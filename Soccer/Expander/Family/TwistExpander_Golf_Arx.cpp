#include "TwistExpander_Golf_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Golf_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC5D1B1E65E89EF65ULL + 0xC0B5BEA9A2C6F57DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDDED9AF5EFFD5BC7ULL + 0xF692F21D2A33D0BBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x83CDC8BF06969551ULL + 0x8F504BCB5ADD9635ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x91A81F1EFC1E8FB9ULL + 0xD5212EF86CC889C2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x96E99C9F7656AF0BULL + 0xBEC8EBC817203F94ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAAABC7BB577603FDULL + 0xC64FB9CC4CBD454CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEB7CCB1A1A4040E9ULL + 0xFED5543753DBB6F6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA358D2C7252B3987ULL + 0xAA45303C19ADFC16ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordF, 11U)) ^ RotL64(aNonceWordH, 53U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3915U)) & S_BLOCK1], 20U) ^ RotL64(mSnow[((aIndex + 3383U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 11U) ^ RotL64(aNonceWordD, 3U)) ^ RotL64(aNonceWordA, 57U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 2706U)) & S_BLOCK1], 48U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 2834U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 22U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 8793908991006073956U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 19U)) + 2932916283348441943U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aIngress, 26U)) + 11069042087940968262U) + RotL64(aNonceWordC, 9U);
            aOrbiterC = (aWandererH + RotL64(aPrevious, 57U)) + 14369628676782894441U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 43U)) + 8602903272780978282U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 3827036107178568820U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 8905245209036772489U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 41U)) + 13331387530760017893U) + RotL64(aNonceWordF, 37U);
            aOrbiterD = (aWandererF + RotL64(aCross, 21U)) + 9880107580289737823U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 48U)) + 10199619040626900278U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 5U)) + 2466307560891374281U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13973403407981259448U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 2851460278409385243U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11226902976321781743U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 10365453393815690776U) + RotL64(aNonceWordE, 14U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 2382382358987358791U) ^ RotL64(aNonceWordG, 41U);
            aOrbiterE = RotL64((aOrbiterE * 481563628980705781U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5058198848163792422U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10500434740387593487U;
            aOrbiterK = RotL64((aOrbiterK * 5946747708776079787U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11289798395177667084U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14327152153231286666U;
            aOrbiterC = RotL64((aOrbiterC * 18155778059595245561U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8065137263811956313U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 3865153574847924816U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9495741102667755161U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 18102279969722473375U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6306428427188742325U;
            aOrbiterD = RotL64((aOrbiterD * 17826782872351406167U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16953348204663693724U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11950791817032898613U;
            aOrbiterF = RotL64((aOrbiterF * 1498946055469611133U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11980823193543752994U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17845490308799454871U;
            aOrbiterG = RotL64((aOrbiterG * 16385153013485463791U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5566398755702887071U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10308378271388889968U;
            aOrbiterH = RotL64((aOrbiterH * 142732084484961281U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 6717846700455219260U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8297225372883997017U;
            aOrbiterA = RotL64((aOrbiterA * 14102812043481327907U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12249337046267666603U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8793908991006073956U;
            aOrbiterI = RotL64((aOrbiterI * 5851229209188473467U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 52U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 10U) + aOrbiterD) + RotL64(aOrbiterJ, 41U)) + aWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 19U) + RotL64(aOrbiterC, 56U)) + aOrbiterA);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterA, 5U)) + RotL64(aNonceWordD, 61U));
            aWandererH = aWandererH + ((RotL64(aCross, 37U) + RotL64(aOrbiterI, 13U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterK, 47U));
            aWandererI = aWandererI + (((RotL64(aScatter, 58U) + aOrbiterI) + RotL64(aOrbiterG, 27U)) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 37U)) + aOrbiterK);
            aWandererF = aWandererF + ((((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 43U)) + RotL64(aNonceWordH, 29U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterB, 58U));
            aWandererD = aWandererD + ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 46U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 37U) ^ RotL64(aNonceWordH, 12U)) ^ RotL64(aNonceWordF, 21U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 8069U)) & S_BLOCK1], 3U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 8307U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 43U) ^ RotL64(aNonceWordB, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8582U)) & S_BLOCK1], 56U) ^ RotL64(mSource[((aIndex + 6792U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 18U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 29U)) + 18144572925667544139U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aCross, 27U)) + 5659758077574059728U) + RotL64(aNonceWordF, 36U);
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 6343330616999166392U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 17754639838410839447U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 50U)) + 9451843819849581729U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 35U)) + 7957854457197462212U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 23U)) + 1461994799722205010U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 37U)) + 18002214276252170177U) + aOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 14689869073147027164U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 58U)) + 3978104368003440293U) + RotL64(aNonceWordC, 57U);
            aOrbiterH = (aWandererE + RotL64(aCross, 21U)) + 8512135845221335386U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1477533446382953439U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 2166717790929947990U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6538884492418324461U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8082437060686606995U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4363687722464700362U;
            aOrbiterG = RotL64((aOrbiterG * 7199165810993478887U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 15782763348014924206U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8572509150015960728U;
            aOrbiterB = RotL64((aOrbiterB * 3340528604891897779U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12248271773316742521U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 9602078627638561949U) ^ RotL64(aNonceWordG, 27U);
            aOrbiterC = RotL64((aOrbiterC * 1860631869877427405U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 17244849374768558859U) + RotL64(aNonceWordD, 31U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 1030743048280579012U) ^ aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10858949914285817051U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17722342363541914280U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15667504059789880034U;
            aOrbiterE = RotL64((aOrbiterE * 15872269872168533709U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12645332941998550794U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9938135244509986497U;
            aOrbiterF = RotL64((aOrbiterF * 16548185968987392957U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4024609904162105979U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6732064218696157303U;
            aOrbiterI = RotL64((aOrbiterI * 3815409766145891393U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14314117137220703583U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 15244765904057473814U;
            aOrbiterK = RotL64((aOrbiterK * 4034571710808047959U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17441241682018169245U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 11958974379114644873U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11315689206845170303U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8310839846793796473U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 18144572925667544139U;
            aOrbiterH = RotL64((aOrbiterH * 11668203295511168011U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 24U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 37U) + RotL64(aOrbiterF, 13U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 35U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aPrevious, 60U) + aOrbiterA) + RotL64(aOrbiterH, 24U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 41U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 53U)) + aOrbiterB);
            aWandererI = aWandererI ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterB, 21U)) + aOrbiterE) + RotL64(aNonceWordB, 19U));
            aWandererG = aWandererG + ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 6U)) + aOrbiterE);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 39U)) + aOrbiterG) + RotL64(aNonceWordE, 13U));
            aWandererA = aWandererA + ((((RotL64(aCross, 52U) + RotL64(aOrbiterB, 37U)) + aOrbiterK) + RotL64(aCarry, 21U)) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 57U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 27U)) + aOrbiterG) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 12U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 6U) ^ RotL64(aNonceWordB, 27U)) ^ RotL64(aNonceWordA, 51U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 14977U)) & S_BLOCK1], 19U) ^ RotL64(mSnow[((aIndex + 11560U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 35U) ^ RotL64(aNonceWordE, 52U)) ^ RotL64(aNonceWordG, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15592U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 15627U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererB + RotL64(aCross, 41U)) + 4848316479321533394U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 6919360256662636195U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 35U)) + 9897013582181108544U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 47U)) + 7319353809896158678U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aIngress, 21U)) + 2848175435514849859U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 14U)) + 6967780718720437934U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 43U)) + 10143884766603388136U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 51U)) + 8675965006150972051U) + RotL64(aNonceWordF, 5U);
            aOrbiterF = (((aWandererG + RotL64(aIngress, 11U)) + 16350117755560994281U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordG, 27U);
            aOrbiterB = (aWandererF + RotL64(aCross, 44U)) + 17976597517118423760U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 57U)) + 1399631141355370237U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3590613762034716792U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 5134624314245932157U;
            aOrbiterG = RotL64((aOrbiterG * 13077589037975283371U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 10082236952942943654U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4015535035905433450U;
            aOrbiterA = RotL64((aOrbiterA * 4961808568701908559U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 611474103801573800U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5786708483794098001U;
            aOrbiterE = RotL64((aOrbiterE * 7694007039340089267U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5201943497363274455U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9282160506938328489U;
            aOrbiterD = RotL64((aOrbiterD * 5368182164239021367U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4932320527498940158U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11576526341731392916U;
            aOrbiterI = RotL64((aOrbiterI * 1712051774729439363U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10790691517638887125U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16280649213607464422U;
            aOrbiterB = RotL64((aOrbiterB * 10756733801499471873U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9553716940667712810U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11827518270964003341U;
            aOrbiterK = RotL64((aOrbiterK * 1322489827908132831U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 16777463701235809321U) + RotL64(aNonceWordH, 24U);
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3375489084588454149U;
            aOrbiterH = RotL64((aOrbiterH * 3335010977457647307U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 8129898095524287632U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14496406641486541929U;
            aOrbiterJ = RotL64((aOrbiterJ * 10077246205532940301U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17968163292907132345U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 2431407778543471402U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 407105842057624537U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 18330313613898211889U) + RotL64(aNonceWordB, 17U);
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4848316479321533394U;
            aOrbiterC = RotL64((aOrbiterC * 3462735144109152811U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 56U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 54U) + aOrbiterK) + RotL64(aOrbiterH, 50U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterB, 5U));
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 53U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 19U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterK, 56U));
            aWandererK = aWandererK + ((RotL64(aIngress, 50U) + aOrbiterI) + RotL64(aOrbiterF, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 37U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 39U)) + RotL64(aNonceWordD, 41U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterC, 29U)) + RotL64(aNonceWordC, 59U)) + aWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterK, 47U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 56U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 39U) ^ RotL64(aNonceWordF, 21U)) ^ RotL64(aNonceWordH, 60U));
            aIngress = aIngress ^ (RotL64(mSnow[((aIndex + 20086U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 17690U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordC, 35U)) ^ RotL64(aNonceWordB, 43U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17107U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16828U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 52U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererE + RotL64(aIngress, 23U)) + 12222235191147985484U) + RotL64(aNonceWordH, 51U);
            aOrbiterE = ((((aWandererG + RotL64(aPrevious, 10U)) + RotL64(aCarry, 53U)) + 16367317014523328414U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordB, 57U);
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 35U)) + 3511378091284703789U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aCross, 39U)) + 15247492830966725949U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 53U)) + 7745995913390407897U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 19U)) + 6463593307540108810U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 5U)) + 1101669311005268630U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 44U)) + 12988052764067518580U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 13U)) + 17717179747434679772U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 39U)) + 11662190906682400416U;
            aOrbiterK = (aWandererI + RotL64(aCross, 57U)) + 6563014073547628748U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 13099094932059419219U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16342730862261868847U;
            aOrbiterJ = RotL64((aOrbiterJ * 10988124108686164829U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16855346813127524624U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6570063128502306944U;
            aOrbiterB = RotL64((aOrbiterB * 4571570049463124831U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11328352033809240501U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11640986648833160901U;
            aOrbiterA = RotL64((aOrbiterA * 2895830492089678919U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 2675226158571501666U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 17700531248266458165U) ^ RotL64(aNonceWordE, 55U);
            aOrbiterC = RotL64((aOrbiterC * 2231403813970188657U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7729597396731910874U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15172374484412053756U;
            aOrbiterH = RotL64((aOrbiterH * 149009041406406517U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9178769489257842683U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9020154972097834926U;
            aOrbiterG = RotL64((aOrbiterG * 8910504667566521429U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1317403761217790562U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17151528554929201571U;
            aOrbiterD = RotL64((aOrbiterD * 3735945655450625203U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11621882033959669977U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 10289504450815075623U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13365982786836243195U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16178772981106335703U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16896130772325866910U;
            aOrbiterI = RotL64((aOrbiterI * 6993524735412868965U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9573223644675562575U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17552463713786507189U;
            aOrbiterE = RotL64((aOrbiterE * 16103431656424881779U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 4801852246698369631U) + RotL64(aNonceWordC, 13U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 12222235191147985484U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2835204872125428065U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 48U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 37U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterC, 40U)) + RotL64(aNonceWordD, 12U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 19U)) + aOrbiterE) + RotL64(aNonceWordF, 25U)) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 27U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 30U) + aOrbiterA) + RotL64(aOrbiterB, 11U));
            aWandererG = aWandererG + ((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 5U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterJ, 44U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 53U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 23U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 51U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aCross, 52U) + aOrbiterC) + RotL64(aOrbiterH, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 4U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 10U) ^ RotL64(aNonceWordD, 21U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 21946U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26998U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 5U) ^ RotL64(aNonceWordF, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26100U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 23551U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 52U)) + (RotL64(aIngress, 3U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererK + RotL64(aCross, 3U)) + 16189787374324972735U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 53U)) + 17563763730956242224U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 47U)) + 10572803498593789385U) + RotL64(aNonceWordD, 19U);
            aOrbiterD = ((aWandererA + RotL64(aIngress, 60U)) + RotL64(aCarry, 53U)) + 7713105232072974166U;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 43U)) + 10760839534772718139U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + RotL64(aNonceWordC, 17U);
            aOrbiterA = (aWandererD + RotL64(aCross, 41U)) + 13397069448391230253U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 4569255679998375682U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 5U)) + 9888769350817876949U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 10U)) + RotL64(aCarry, 57U)) + 11351796060878856300U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 21U)) + 18153775071965707204U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 19U)) + 1282846411145853435U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16457743979262460660U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 173493260775251032U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) ^ RotL64(aNonceWordF, 29U);
            aOrbiterG = RotL64((aOrbiterG * 4935807229040883505U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3927345926316409630U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5158769729850853623U;
            aOrbiterA = RotL64((aOrbiterA * 2446452358663812945U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12331351600010165154U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3940794200348684050U;
            aOrbiterB = RotL64((aOrbiterB * 13248997263062075043U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11248514843822945425U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1391497323278226522U;
            aOrbiterF = RotL64((aOrbiterF * 8376841806072565005U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13265623528678787307U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2802033745265647317U;
            aOrbiterK = RotL64((aOrbiterK * 3437626962562016147U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6938444301018051844U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 1086544666755559028U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16039728388882079889U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 16156443117365816536U) + aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3619942859562697142U;
            aOrbiterC = RotL64((aOrbiterC * 7589346043159112151U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17681848914912743292U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8848238631758130416U;
            aOrbiterE = RotL64((aOrbiterE * 810402256099500607U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6019192027793541890U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16917288363166352778U;
            aOrbiterH = RotL64((aOrbiterH * 17673667086593738207U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 5598218150530046752U) + RotL64(aNonceWordE, 44U);
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17285995539011279010U;
            aOrbiterI = RotL64((aOrbiterI * 15621233176885995065U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12380627610747299268U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 16189787374324972735U) ^ aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2144714828503219209U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterC, 43U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 48U)) + aOrbiterI) + RotL64(aCarry, 41U)) + RotL64(aNonceWordH, 41U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 10U) + aOrbiterF) + RotL64(aOrbiterG, 21U));
            aWandererI = aWandererI + (((((RotL64(aCross, 37U) + RotL64(aOrbiterG, 27U)) + aOrbiterH) + RotL64(aCarry, 47U)) + RotL64(aNonceWordA, 35U)) + aWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 13U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 37U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterD, 51U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterJ, 11U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 3U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterC, 39U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterB, 6U)) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 4U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordC, 11U)) ^ RotL64(aNonceWordD, 30U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 32312U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 29328U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordA, 37U)) ^ RotL64(aNonceWordH, 46U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31585U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31188U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 54U)) ^ (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 3650233661228036955U) + RotL64(aNonceWordG, 55U);
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 50U)) + RotL64(aCarry, 41U)) + 11607036400067735729U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aScatter, 35U)) + 3899614406903883035U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 21U)) + 8159156925629965143U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 41U)) + 7148903913967261270U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 29U)) + 9161665622287517848U) + RotL64(aNonceWordE, 7U);
            aOrbiterK = (aWandererF + RotL64(aScatter, 5U)) + 2981535013474059469U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 3U)) + 15812469008200319549U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 46U)) + 14687469489893270300U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 27U)) + 6025209349511417063U) + aOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aScatter, 43U)) + 12964750392311112676U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6572355895765394340U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3542300121890027981U;
            aOrbiterA = RotL64((aOrbiterA * 11201491178181273935U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 6477175684045398359U) + aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1081388388827929314U;
            aOrbiterC = RotL64((aOrbiterC * 8752188637514143529U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13754328481584620771U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3684673342659575917U;
            aOrbiterI = RotL64((aOrbiterI * 6139923312873039143U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6542045150319909445U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 5352102692424060388U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) ^ RotL64(aNonceWordB, 26U);
            aOrbiterK = RotL64((aOrbiterK * 7385758355501860261U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9110100774657340354U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2813273684436269057U;
            aOrbiterE = RotL64((aOrbiterE * 10468759062594022273U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5860425751137403755U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 1598622981888978548U) ^ RotL64(aNonceWordC, 37U);
            aOrbiterD = RotL64((aOrbiterD * 651816500461718345U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14710305692377606725U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16280545617802383463U;
            aOrbiterG = RotL64((aOrbiterG * 12541767206978802063U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6849565243667718750U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12152381961996750050U;
            aOrbiterJ = RotL64((aOrbiterJ * 11185935780063403807U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 1318947876257794796U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5447559252769140391U;
            aOrbiterB = RotL64((aOrbiterB * 13683733413554766327U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2766869582494246454U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15757729967222729304U;
            aOrbiterH = RotL64((aOrbiterH * 1858683399257513171U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 13063432816787882618U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3650233661228036955U;
            aOrbiterF = RotL64((aOrbiterF * 16230564672533821641U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 43U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 27U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 29U));
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterF, 19U)) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterF, 57U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterB, 35U)) + RotL64(aNonceWordF, 27U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterI, 54U)) + RotL64(aNonceWordD, 9U)) + aWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 40U) + RotL64(aOrbiterE, 51U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 13U)) + aOrbiterE);
            aWandererE = aWandererE + ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterB, 37U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterJ, 42U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 6U) + RotL64(aOrbiterG, 47U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererB, 46U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + RotL64(aWandererI, 34U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_Golf_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF2109B92F7EFE88DULL + 0x903524172325496FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD48D593A9A1F508FULL + 0xCBD85BFA1D56C34BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA9674BD5DE109F6DULL + 0x95B9CEF9BC5B3F66ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8E9841078249D0E3ULL + 0xFB2C69C3D0F6A013ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9CDB92D558770AD7ULL + 0xBB5EEF9E9526AC0AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA0F82C64C660E16DULL + 0xB61688B010EAE608ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD2B1640C211742CFULL + 0xB5FA70A6A155F310ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC11BBB35DEAEE237ULL + 0xAC063B87D4A64073ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 34U) ^ RotL64(aNonceWordG, 23U)) ^ RotL64(aNonceWordB, 53U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7621U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 3800U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordD, 39U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3688U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((aIndex + 7237U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 39U)) + (RotL64(aCarry, 57U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererG + RotL64(aPrevious, 35U)) + 13278949403988203974U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 28U)) + RotL64(aCarry, 37U)) + 9213599924054673756U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 41U)) + 1255746482932381798U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aCross, 5U)) + 11575321997144516122U) + RotL64(aNonceWordG, 7U);
            aOrbiterB = (aWandererK + RotL64(aPrevious, 11U)) + 15881587525529432437U;
            aOrbiterK = ((((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 29U)) + 9846195809864862707U) + aOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordA, 11U);
            aOrbiterE = (aWandererB + RotL64(aIngress, 19U)) + 12319815691858217670U;
            aOrbiterI = (aWandererH + RotL64(aCross, 60U)) + 16322617427294439587U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 51U)) + 16332130810525887437U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 4920951156015336794U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16767126455124552329U;
            aOrbiterA = RotL64((aOrbiterA * 4440352337076842603U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12553595911087945223U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 1437522202135436142U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2001992794165550905U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 12313100454852227143U) + RotL64(aNonceWordH, 57U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 2761983020631055729U) ^ aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3874839760378039509U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 17635303588421554367U) + RotL64(aNonceWordC, 25U);
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 788212489507463763U;
            aOrbiterF = RotL64((aOrbiterF * 17896475584538528059U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5192552894670654434U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6784748488807738811U;
            aOrbiterG = RotL64((aOrbiterG * 8077237651953896479U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16113417046719114943U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1096874945215225916U;
            aOrbiterC = RotL64((aOrbiterC * 17308604412622879833U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7610274704570171595U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10466070212284342550U;
            aOrbiterE = RotL64((aOrbiterE * 6449728258497920613U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6777845928873855221U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5251515022021984126U;
            aOrbiterJ = RotL64((aOrbiterJ * 9018277343404261611U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 13849343158824111498U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7977711210181714021U;
            aOrbiterB = RotL64((aOrbiterB * 4182053966171053577U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterC, 54U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 28U) + RotL64(aOrbiterJ, 34U)) + aOrbiterG) + RotL64(aNonceWordB, 16U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterE, 19U)) + aWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 57U) + RotL64(aOrbiterB, 39U)) + aOrbiterC) + RotL64(aCarry, 51U)) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterF, 23U));
            aWandererH = aWandererH + ((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterB, 57U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 48U) + aOrbiterI) + RotL64(aOrbiterJ, 53U)) + RotL64(aNonceWordE, 43U));
            aWandererG = aWandererG + (((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterJ, 14U));
            aWandererD = aWandererD + ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 27U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 42U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordE, 46U)) ^ RotL64(aNonceWordC, 29U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12073U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 10264U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 27U) ^ RotL64(aNonceWordF, 56U)) ^ RotL64(aNonceWordA, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11399U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10796U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 5U)) + 6916817163240024692U) + aOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (((aWandererH + RotL64(aIngress, 29U)) + 14554930751292077817U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordH, 11U);
            aOrbiterI = ((aWandererG + RotL64(aCross, 47U)) + 1098305064484336101U) + RotL64(aNonceWordE, 53U);
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 56U)) + 12192821172420471527U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 2435134991707318845U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 19U)) + 1896745368738512624U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 13U)) + 1114996424222923873U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 4U)) + 9839135798371512656U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 29U)) + 8037967239603177043U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15185468738487237432U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4912098316394854543U;
            aOrbiterI = RotL64((aOrbiterI * 3072785550384399929U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 13142688607850380888U) + RotL64(aNonceWordD, 27U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 4507379759608945839U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2989332387754215967U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7299006009652289342U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 5390655277207053627U) ^ aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10973744708856143715U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 6744737023577785725U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 15539737698867067285U) ^ RotL64(aNonceWordF, 21U);
            aOrbiterJ = RotL64((aOrbiterJ * 4686092035261336911U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13329866734681377952U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 13284937458969166257U) ^ aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3965985432462699445U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8695002088915702168U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3858059421620839286U;
            aOrbiterK = RotL64((aOrbiterK * 9559783727301092937U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6609163873243179836U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9416165620556710540U;
            aOrbiterF = RotL64((aOrbiterF * 240385043740268229U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1578449067529000433U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14309000104419489303U;
            aOrbiterG = RotL64((aOrbiterG * 7599078306153684729U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15785180680737461320U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10099222679918382021U;
            aOrbiterD = RotL64((aOrbiterD * 2012232597046182581U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 6U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 18U) + RotL64(aOrbiterH, 4U)) + aOrbiterK) + RotL64(aNonceWordB, 55U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 39U)) + aOrbiterD) + RotL64(aCarry, 47U)) + RotL64(aNonceWordG, 44U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 51U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterF, 35U)) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 58U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 29U)) + aOrbiterG) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterG, 23U));
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 43U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 24U) + aOrbiterD) + RotL64(aOrbiterA, 47U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 39U) ^ RotL64(aNonceWordH, 18U)) ^ RotL64(aNonceWordE, 47U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 16459U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 23391U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 40U) ^ RotL64(aNonceWordG, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19342U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22352U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 24U) ^ RotL64(aCross, 37U)) + (RotL64(aCarry, 5U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 47U)) + 12029393034357490020U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 40U)) + 4526754731580694987U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 23U)) + 17060419646421271853U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 47U)) + 4128488893837059683U) + RotL64(aNonceWordH, 11U);
            aOrbiterJ = (aWandererF + RotL64(aScatter, 35U)) + 12706894827547160110U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 6U)) + 12506324593645825056U;
            aOrbiterE = ((((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 12581344490649250025U) + aOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordB, 61U);
            aOrbiterI = (((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 14357032418199130132U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aIngress, 27U)) + 15341977701796331249U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 7086602307544733241U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12398300065276832486U;
            aOrbiterD = RotL64((aOrbiterD * 18157408831225635333U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2499745046076601988U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7249361592814001829U;
            aOrbiterC = RotL64((aOrbiterC * 14597139848072319685U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3254456186337366437U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 3472973415969046680U) ^ RotL64(aNonceWordG, 20U);
            aOrbiterA = RotL64((aOrbiterA * 14583566953969168353U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7905718972111691591U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15941413652144021522U;
            aOrbiterF = RotL64((aOrbiterF * 3473779492962783565U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10583964125960308762U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 13659925272340853715U) ^ aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1]) ^ RotL64(aNonceWordE, 15U);
            aOrbiterJ = RotL64((aOrbiterJ * 16708294803316630743U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9487054537489454887U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 13287757570441887517U) ^ aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17351439045329892107U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15279245465808571942U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12424999114621745879U;
            aOrbiterE = RotL64((aOrbiterE * 2274918760256527137U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 13915392738892970475U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13797668053788805126U;
            aOrbiterI = RotL64((aOrbiterI * 13752161103680525317U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14344766585550401077U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13727554194373146727U;
            aOrbiterB = RotL64((aOrbiterB * 17164450431362670223U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 50U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 60U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterG, 53U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 14U) + aOrbiterA) + RotL64(aOrbiterC, 29U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 5U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 47U)) + aOrbiterF);
            aWandererI = aWandererI + (((((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 11U)) + RotL64(aNonceWordD, 47U)) + aWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterA, 18U)) + aOrbiterG);
            aWandererH = aWandererH + ((((RotL64(aScatter, 28U) + aOrbiterB) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 43U)) + RotL64(aNonceWordC, 43U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 35U)) + aOrbiterF) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 12U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordF, 5U)) ^ RotL64(aNonceWordA, 19U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30702U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31202U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 11U) ^ RotL64(aNonceWordB, 27U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25053U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 28357U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 37U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 3U)) + 4068921616130916949U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 41U)) + 12077715273915151726U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 3U)) + 16047546802670596833U;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 52U)) + RotL64(aCarry, 23U)) + 9690277462716999763U) + RotL64(aNonceWordC, 16U);
            aOrbiterC = (((aWandererC + RotL64(aIngress, 23U)) + 14484814700447992628U) + aOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1]) + RotL64(aNonceWordD, 21U);
            aOrbiterG = (aWandererA + RotL64(aCross, 13U)) + 17089267243053958210U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 41U)) + 9138746214446211147U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 18U)) + 10181001536979097045U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aCross, 57U)) + 6657458969093373191U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7515983477876590988U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3039935555863947600U;
            aOrbiterK = RotL64((aOrbiterK * 12511160550780270119U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16209389224740851136U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 725253312098083182U) ^ RotL64(aNonceWordH, 55U);
            aOrbiterC = RotL64((aOrbiterC * 17535989492095522597U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13307041115748941383U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 7159572004825238263U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4855009895002398449U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 12027236743251643820U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8717826175991286553U;
            aOrbiterH = RotL64((aOrbiterH * 1175614802543098451U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 4769096034227659937U) + aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11201226563992939616U;
            aOrbiterD = RotL64((aOrbiterD * 15595355978388159931U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17295978531215563256U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11850923890626719833U;
            aOrbiterG = RotL64((aOrbiterG * 3854851059897397075U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14139441565288097706U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 988684899382304485U;
            aOrbiterJ = RotL64((aOrbiterJ * 11929090869999700891U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 6159251276942253175U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 4849529993914550651U) ^ RotL64(aNonceWordB, 41U);
            aOrbiterE = RotL64((aOrbiterE * 18240712676783671317U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6679745455842119497U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15838404437552215214U;
            aOrbiterA = RotL64((aOrbiterA * 17357853511591350887U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 14U) + aOrbiterK) + RotL64(aOrbiterA, 58U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 43U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 47U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 13U)) + aOrbiterG) + RotL64(aNonceWordA, 39U));
            aWandererI = aWandererI + (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 35U)) + aOrbiterK) + aWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterG, 26U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterD, 19U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 26U) + aOrbiterA) + RotL64(aOrbiterE, 5U)) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 39U)) + aOrbiterE) + RotL64(aCarry, 37U)) + RotL64(aNonceWordE, 53U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 44U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 35U));
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

void TwistExpander_Golf_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCDA62D1A93484DA9ULL + 0x922E74F01438589BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBB5BA467F1551AD9ULL + 0xB61F801E051A7EF8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD998AE9D5B151A8FULL + 0xDC1BAE9E1785F5A3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB54FE599CC6A81BFULL + 0xA7F45505B8985579ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB20DC4954BCD56BFULL + 0xF0E84E20E99D6184ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x85351E8482471849ULL + 0xC9FCF3BBE3A9AB88ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC6BE951B2E4EEADFULL + 0x91DE7E70D9EBD1B6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC5A9E3883EF5DC73ULL + 0xEA71E1444FF9E9FDULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordG, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 243U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7218U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1527U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6788U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 18U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererE + RotL64(aIngress, 57U)) + 1457104756581596530U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 6127240317844622874U;
            aOrbiterF = ((((aWandererC + RotL64(aCross, 22U)) + RotL64(aCarry, 35U)) + 16492290056044189421U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordA, 17U);
            aOrbiterA = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 10963676850938416468U;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 11U)) + 4872917367399752405U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordB, 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15218882377875616148U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 5934166612122118251U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10365045124180379919U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14215280930872003003U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 11428034799044600979U) ^ aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12162528943733976177U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 5453003654321728726U) + RotL64(aNonceWordE, 55U);
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14273775120265649389U;
            aOrbiterA = RotL64((aOrbiterA * 5139018128323795309U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 328723770018440271U) + RotL64(aNonceWordC, 8U);
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13032190719588211088U;
            aOrbiterI = RotL64((aOrbiterI * 13363368478932798315U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2386881543033598494U) + aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 1649501123340887116U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11148976582360499033U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 30U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 12U) + aOrbiterI) + RotL64(aOrbiterA, 54U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterD, 11U)) + RotL64(aNonceWordD, 7U)) + aWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 35U)) + aOrbiterA) + RotL64(aCarry, 41U)) + RotL64(aNonceWordH, 31U)) + aWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 27U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 43U)) + aOrbiterI) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 40U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 24U) ^ RotL64(aNonceWordG, 35U)) ^ RotL64(aNonceWordF, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8192U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((aIndex + 12846U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordC, 38U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16240U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14500U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 18U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 35U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererF + RotL64(aIngress, 30U)) + RotL64(aCarry, 57U)) + 16462052553719977502U) + RotL64(aNonceWordE, 41U);
            aOrbiterF = (aWandererJ + RotL64(aScatter, 57U)) + 12337064059566619581U;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 15801005007094515447U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 11U)) + 8228706742665081656U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aIngress, 13U)) + 11006723027845190869U) + RotL64(aNonceWordA, 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 18173765337829177450U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterH) ^ 530215083653542558U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) ^ RotL64(aNonceWordG, 13U);
            aOrbiterD = RotL64((aOrbiterD * 8938680024265564887U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6608611827035564511U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 2246051826221626809U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1]) ^ RotL64(aNonceWordF, 16U);
            aOrbiterE = RotL64((aOrbiterE * 6333352641495253539U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 5228575308895381421U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10999213210689606857U;
            aOrbiterH = RotL64((aOrbiterH * 5467601259546342925U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3773371037240485696U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 8887985779436152504U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 698713082830739677U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11150566414723818350U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8336366151003049546U;
            aOrbiterI = RotL64((aOrbiterI * 9033771197242493699U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 19U)) + aOrbiterE) + RotL64(aNonceWordB, 55U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 56U) + RotL64(aOrbiterF, 47U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 56U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 29U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterE, 3U)) + RotL64(aNonceWordH, 7U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordD, 35U)) ^ RotL64(aNonceWordG, 24U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18534U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21839U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordB, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18661U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22037U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aIngress, 48U)) + 11210042748013785976U) + RotL64(aNonceWordB, 8U);
            aOrbiterK = (((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 4584747303233477454U) + RotL64(aNonceWordE, 7U);
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 39U)) + 8878765929792969517U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 2172232330280041122U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 3U)) + 8378937026022264016U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8683007464695824208U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 9564352997357118134U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17869948990449143305U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 11713878436769887528U) + RotL64(aNonceWordG, 43U);
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8052917623074021077U;
            aOrbiterK = RotL64((aOrbiterK * 7450115139081623477U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 7720597162792145185U) + RotL64(aNonceWordC, 5U);
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2602847785328475621U;
            aOrbiterB = RotL64((aOrbiterB * 14065077077207224525U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17813669222300509724U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8724263063156573013U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3632927017737834359U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 6882429835961613492U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 13213313479525717359U) ^ aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2411431247725974895U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 14U));
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterB, 30U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 30U) + aOrbiterH) + RotL64(aOrbiterG, 13U)) + aWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 5U)) + aOrbiterH) + RotL64(aCarry, 37U)) + RotL64(aNonceWordD, 25U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 39U)) + aOrbiterH) + RotL64(aNonceWordH, 37U)) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 4U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordH, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32196U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32040U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 48U) ^ RotL64(aNonceWordC, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31536U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26904U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 35U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererC + RotL64(aCross, 41U)) + 13499155707765393469U;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 3U)) + 3740324981823726185U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1]) + RotL64(aNonceWordE, 15U);
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 43U)) + 5470765363949735652U) + RotL64(aNonceWordB, 5U);
            aOrbiterA = (((aWandererE + RotL64(aScatter, 56U)) + RotL64(aCarry, 57U)) + 3446436171274452326U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 29U)) + 1778929412631211933U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 14666308799855220954U) + RotL64(aNonceWordD, 22U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 4548410236791175055U) ^ aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6822908616815218501U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5829739767694190372U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 14319231414903675748U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4966501102515775601U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1513851750246111405U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1685620217748986019U;
            aOrbiterA = RotL64((aOrbiterA * 9286548037413609445U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 16284162182006054402U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6271539598462003309U;
            aOrbiterD = RotL64((aOrbiterD * 13923286694131331137U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12669312437565969473U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 11894755313393001665U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) ^ RotL64(aNonceWordG, 53U);
            aOrbiterF = RotL64((aOrbiterF * 12556759675372354075U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 38U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterH, 24U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 47U)) + aOrbiterB) + RotL64(aCarry, 5U)) + RotL64(aNonceWordH, 55U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterF, 5U));
            aWandererH = aWandererH + ((((RotL64(aCross, 56U) + aOrbiterA) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 13U)) + aOrbiterA) + RotL64(aNonceWordA, 27U)) + aWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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

void TwistExpander_Golf_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB8C0102571E78327ULL + 0xD730151DDF6A6D80ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD8B141721B925B13ULL + 0x8E65A77E5F078CB0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x891EF0B7112BA39BULL + 0xDD849E9833D6419EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xADC8E17E0E623633ULL + 0x930C216D5B1C0E70ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF5714ACCEDC2DE99ULL + 0xB323AC95F2F7CBAAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB9D961EAF0A22951ULL + 0xAF236596235181FAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAC344BDCD604C5F7ULL + 0xC1CF12DF9278C61CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x84D8B745F76F69B1ULL + 0xBC085A19A1876F61ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordH, 12U)) ^ RotL64(aNonceWordG, 47U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3900U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4347U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordF, 37U)) ^ RotL64(aNonceWordD, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5681U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2500U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 41U)) + (RotL64(aPrevious, 22U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 58U)) + 9041099828460168106U;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 37U)) + 12883711604096848454U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 17420968786226443079U;
            aOrbiterA = (((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 5U)) + 3448213891716125104U) + RotL64(aNonceWordE, 17U);
            aOrbiterI = (aWandererI + RotL64(aIngress, 51U)) + 11866455977445336560U;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 3U)) + 4119356835384495905U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1]) + RotL64(aNonceWordF, 9U);
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 29U)) + 2186212599698637068U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 6506144898969301620U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 12556800923644051626U) ^ RotL64(aNonceWordG, 8U);
            aOrbiterC = RotL64((aOrbiterC * 15961043406612913121U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 4075551535185182945U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 17877694808492008749U;
            aOrbiterI = RotL64((aOrbiterI * 901315308379887473U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5553428900598223316U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 14362304852277160675U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11415103199856419303U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9174200302876075831U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16110739511917638547U;
            aOrbiterG = RotL64((aOrbiterG * 7004356839428657949U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10189881974519849402U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 2128076632642616677U) ^ RotL64(aNonceWordA, 39U);
            aOrbiterJ = RotL64((aOrbiterJ * 8860453653433114929U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 18133523799074400083U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9916472958834153766U;
            aOrbiterA = RotL64((aOrbiterA * 3454601168808001733U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10274457562795569227U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14134814273275356425U;
            aOrbiterB = RotL64((aOrbiterB * 15912501063665343159U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 21U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 44U));
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 27U)) + aOrbiterB) + RotL64(aNonceWordB, 55U));
            aWandererH = aWandererH + (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 19U)) + aOrbiterC) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterF, 52U)) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterB, 37U));
            aWandererD = aWandererD + (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 3U)) + RotL64(aNonceWordC, 53U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 60U) + aOrbiterJ) + RotL64(aOrbiterG, 43U)) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 14U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 19U) ^ RotL64(aNonceWordA, 27U)) ^ RotL64(aNonceWordE, 58U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13862U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 12940U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 47U) ^ RotL64(aNonceWordC, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12065U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 10671U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 47U) ^ RotL64(aCross, 23U)) + (RotL64(aPrevious, 35U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 5U)) + 9751314027302668907U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordD, 11U);
            aOrbiterC = (aWandererF + RotL64(aCross, 36U)) + 12175450995523107056U;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 5U)) + 17519694958730119552U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aIngress, 27U)) + 9093525527925682263U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 19U)) + 3713831321786810138U) + RotL64(aNonceWordG, 17U);
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 37U)) + 10108355209191835040U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 12956307447311314768U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1904298513945877359U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4658049993308574460U;
            aOrbiterD = RotL64((aOrbiterD * 10482422152074338611U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9826333658248851902U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 12058666914724365134U) ^ RotL64(aNonceWordC, 29U);
            aOrbiterJ = RotL64((aOrbiterJ * 964233873188373939U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2516574707110528099U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 13335308331049750235U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5880227828760598587U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 8230749255538495304U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16536559486797811486U;
            aOrbiterC = RotL64((aOrbiterC * 7097036838156464969U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12387639130570188998U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8459259798142872020U;
            aOrbiterF = RotL64((aOrbiterF * 8001346480955847013U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16083784052002800300U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 1957284290736468379U) ^ RotL64(aNonceWordF, 9U);
            aOrbiterB = RotL64((aOrbiterB * 5046501301740813065U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 7349538179311335863U) + aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 16395170077006105258U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4230485452156662763U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 6U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterB, 12U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordA, 41U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 23U)) + aOrbiterF);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 43U)) + RotL64(aNonceWordH, 44U)) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterE, 5U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 13U) + RotL64(aOrbiterD, 53U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordC, 23U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18708U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23948U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 26U) ^ RotL64(aNonceWordD, 57U)) ^ RotL64(aNonceWordG, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17334U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16940U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 52U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererK + RotL64(aIngress, 19U)) + 1087148170018530502U) + RotL64(aNonceWordA, 48U);
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 38U)) + 15530846874509311414U) + RotL64(aNonceWordD, 13U);
            aOrbiterF = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 16987358651515511212U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 53U)) + 12504143181007924259U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 57U)) + 393322117322732418U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 29U)) + 14325937299241887166U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 9395262907017475742U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13658510441418344769U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6410754322737005336U;
            aOrbiterF = RotL64((aOrbiterF * 6932217611373076391U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9257290738538818434U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 7489828960857692286U) ^ RotL64(aNonceWordE, 3U);
            aOrbiterK = RotL64((aOrbiterK * 16519674788777989043U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4118778591214588387U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 16619215231168796563U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14876884956536265157U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11326283811003573430U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1865401866017614604U;
            aOrbiterB = RotL64((aOrbiterB * 8378326058282460073U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 670150121105733604U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 1499331510641068749U) ^ RotL64(aNonceWordH, 43U);
            aOrbiterH = RotL64((aOrbiterH * 16623742535540383107U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 1116410848560838532U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2696841341036281779U;
            aOrbiterI = RotL64((aOrbiterI * 9598953298074904869U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 5487352391229549881U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12008243050943342979U;
            aOrbiterE = RotL64((aOrbiterE * 9087261224804582459U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 20U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 13U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 28U) + RotL64(aOrbiterI, 29U)) + aOrbiterB) + aWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterF, 43U));
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 5U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 58U)) + aOrbiterF);
            aWandererF = aWandererF + (((((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordF, 61U)) + aWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 51U)) + aOrbiterG) + RotL64(aNonceWordB, 31U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 12U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 38U) ^ RotL64(aNonceWordF, 51U)) ^ RotL64(aNonceWordA, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32158U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28980U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 18U) ^ RotL64(aNonceWordE, 47U)) ^ RotL64(aNonceWordD, 37U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28676U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 28581U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 18U) ^ RotL64(aCarry, 5U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererH + RotL64(aScatter, 22U)) + RotL64(aCarry, 11U)) + 9914837590440975587U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 29U)) + 6706125076401958051U) + RotL64(aNonceWordG, 55U);
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 41U)) + 16570817772679258409U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aIngress, 57U)) + 6843705658115186948U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 51U)) + 16099930446791572351U) + RotL64(aNonceWordE, 45U);
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 11U)) + 5420550009556030459U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 5729549069420177477U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15590601126188675834U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 13044027390998620029U;
            aOrbiterB = RotL64((aOrbiterB * 16845199115313444123U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11068338135659636772U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 6584988841809544332U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1683336180438945439U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8516813219883915404U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10647314042912492785U;
            aOrbiterD = RotL64((aOrbiterD * 15559481057047148785U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 201691689889605304U) + RotL64(aNonceWordB, 34U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15512161798401184003U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11473219183982564709U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3883760518944464145U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 13861805129175491145U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17194438894492581181U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 12019138626550801486U) + RotL64(aNonceWordC, 15U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 13030350224959652248U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11724200983306280107U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2643807255422544248U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4127143302485631794U;
            aOrbiterH = RotL64((aOrbiterH * 5441038881111578487U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterD, 41U)) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 5U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 51U)) + aOrbiterE) + RotL64(aNonceWordH, 3U));
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 6U) + aOrbiterC) + RotL64(aOrbiterH, 34U)) + aWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 39U) + RotL64(aOrbiterA, 21U)) + aOrbiterB) + RotL64(aNonceWordD, 41U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 27U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Golf_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x84FAD78094A6469FULL + 0xC2A797CC35F197C4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xED8CE018A110522BULL + 0xD22B71CB42B1AE5FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFFF2A602B326888FULL + 0xA3FE955BCBA3E154ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBACCDA156B4C6325ULL + 0x9625F7305E55CBCEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8A36D35F5E95A9A7ULL + 0x90A1192E1A528C16ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x97C8D01FBD771017ULL + 0xF6286705B7F7F8D5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB55B45154F9AE7A3ULL + 0xCE6472727AF4F0A7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x98D6D2247E20CDADULL + 0x994B051DC055A1FCULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 21U) ^ RotL64(aNonceWordC, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 7323U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5844U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 46U) ^ RotL64(aNonceWordD, 3U)) ^ RotL64(aNonceWordF, 57U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2350U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 4269U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 54U)) + (RotL64(aIngress, 5U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 9774364261626083532U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 41U)) + 18059001521926116420U) + aOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aCross, 19U)) + 10615626210406381148U;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 3U)) + 10536484278007898620U) + RotL64(aNonceWordG, 37U);
            aOrbiterC = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 41U)) + 13320663045139972700U) + RotL64(aNonceWordE, 17U);
            aOrbiterB = (aWandererG + RotL64(aIngress, 34U)) + 17127001787268166583U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 57U)) + 16742574590844166551U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8347719720758228053U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 13502468705946051986U) ^ aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13822952083584784695U), 51U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 3512687886188904904U) + aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1]) + RotL64(aNonceWordF, 34U);
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 495660316165795934U;
            aOrbiterC = RotL64((aOrbiterC * 6724596801190194913U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5092722552034477356U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15641128019608284015U;
            aOrbiterB = RotL64((aOrbiterB * 3621036395703527059U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15421873776811085458U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17978775513204574125U;
            aOrbiterG = RotL64((aOrbiterG * 18359600395119440183U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16617179197537669849U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 1931805387534012528U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3400139345857733775U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 9544923119559308431U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 12930999400470173353U) ^ RotL64(aNonceWordB, 21U);
            aOrbiterI = RotL64((aOrbiterI * 16791006919271490005U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13673733276226249890U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2032263473309124738U;
            aOrbiterE = RotL64((aOrbiterE * 3088728329261360607U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 21U);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterK, 37U)) + RotL64(aNonceWordA, 19U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 60U) + aOrbiterG) + RotL64(aOrbiterC, 5U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 57U)) + aOrbiterF) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + RotL64(aOrbiterB, 20U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterE, 43U)) + RotL64(aNonceWordH, 3U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 51U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 11U)) + aOrbiterG) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 4U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 27U) ^ RotL64(aNonceWordC, 51U)) ^ RotL64(aNonceWordG, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 14286U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneD[((aIndex + 16311U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordD, 37U)) ^ RotL64(aNonceWordF, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13929U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 11555U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 54U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 28U)) + 5697928251815176134U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 43U)) + 337587740689259575U) + RotL64(aNonceWordE, 36U);
            aOrbiterD = ((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 4927686903263973950U;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 51U)) + 3742409032569801033U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordA, 29U);
            aOrbiterI = (((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 1608092659172197650U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aPrevious, 37U)) + 15848744267145717509U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 23U)) + 15300174177963339253U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14162868453323648628U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 12020167069983729869U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2071080217680099017U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16259538291658723956U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 8516686212464112245U) ^ RotL64(aNonceWordF, 35U);
            aOrbiterJ = RotL64((aOrbiterJ * 4731296903548893627U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3722184575520553132U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 5663609293306386784U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14364218128780764749U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15265344442454471986U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3050323350098829515U;
            aOrbiterF = RotL64((aOrbiterF * 5890624677162388135U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1093356813820599238U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15167726103772238440U;
            aOrbiterI = RotL64((aOrbiterI * 5719466863561311069U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15170797965325981472U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 17826286701992981628U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11186808881726573677U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 14710892030473425181U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 397194787697553904U) ^ RotL64(aNonceWordC, 57U);
            aOrbiterK = RotL64((aOrbiterK * 14368930300818752833U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 27U)) + aOrbiterJ) + RotL64(aNonceWordD, 43U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 47U)) + RotL64(aNonceWordH, 31U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 43U)) + aOrbiterI) + aWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 19U)) + aOrbiterF) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 14U) + aOrbiterB) + RotL64(aOrbiterI, 3U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 54U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererG, 18U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordH, 58U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 20110U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19219U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 39U) ^ RotL64(aNonceWordG, 27U)) ^ RotL64(aNonceWordC, 50U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19475U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 18858U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 26U) + RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererE + RotL64(aCross, 37U)) + 2786079456995203065U) + aOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aScatter, 43U)) + 7237256119153857253U;
            aOrbiterG = (((aWandererH + RotL64(aIngress, 28U)) + RotL64(aCarry, 47U)) + 9310834010563647604U) + RotL64(aNonceWordF, 13U);
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 17361734905706517877U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 15837111231884647451U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 19U)) + 18065431964418026445U) + aOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aScatter, 11U)) + 3029123922999952652U) + RotL64(aNonceWordB, 17U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5166926595573507837U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1918425684273807598U;
            aOrbiterG = RotL64((aOrbiterG * 16616641579714896719U), 21U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterK) + 4724551751012661440U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1]) + RotL64(aNonceWordA, 19U);
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1818014487579644390U;
            aOrbiterD = RotL64((aOrbiterD * 14904092108647864911U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 6670090372241084216U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8485757110007268693U;
            aOrbiterK = RotL64((aOrbiterK * 11876760095108618363U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4928130251509514742U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 2528788422725346792U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1855982047967756661U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2860387120895147503U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 12927802338151379368U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8876144125458603029U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 18029699867733207083U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13361836994951253312U;
            aOrbiterH = RotL64((aOrbiterH * 5349767426256597073U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11957294454794128079U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 3755417922063414648U) ^ RotL64(aNonceWordD, 20U);
            aOrbiterC = RotL64((aOrbiterC * 13896364063651241401U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 43U)) + aOrbiterI) + RotL64(aNonceWordC, 35U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterC, 12U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + RotL64(aOrbiterH, 57U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 29U)) + aOrbiterC) + aWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 23U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aCross, 10U) + RotL64(aOrbiterG, 5U)) + aOrbiterD) + RotL64(aNonceWordE, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 27U) ^ RotL64(aNonceWordD, 3U)) ^ RotL64(aNonceWordC, 19U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31538U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27189U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 5U) ^ RotL64(aNonceWordH, 29U)) ^ RotL64(aNonceWordA, 39U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26118U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 27520U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 56U)) + (RotL64(aIngress, 35U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererI + RotL64(aCross, 52U)) + 16200278595895089008U) + RotL64(aNonceWordE, 17U);
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 1029614154810465897U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aIngress, 41U)) + 7129562468705441295U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 14388903902433951274U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 35U)) + 1013568949315967455U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 3U)) + 3128823373497815651U) + aOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 14525694606889470589U) + RotL64(aNonceWordG, 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14443983602196782887U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 12244220415328641190U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15052949098014803181U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10477159225338766614U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 2842870123078131566U) ^ RotL64(aNonceWordF, 25U);
            aOrbiterB = RotL64((aOrbiterB * 11522265477555954071U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8621138818955849917U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5038396344400303181U;
            aOrbiterJ = RotL64((aOrbiterJ * 14636756322207385447U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2768613802894372496U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2027754864051410015U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2461322540050569287U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2848088309172056399U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15017458513904884651U;
            aOrbiterF = RotL64((aOrbiterF * 9926904679902843055U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9079797279596336139U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 15424866642305110811U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12912331089970158845U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 13751764050290602740U) + RotL64(aNonceWordB, 53U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7694557131324740282U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14980807690491467023U), 39U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 41U)) + aOrbiterE) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 34U) + RotL64(aOrbiterD, 10U)) + aOrbiterF) + RotL64(aNonceWordH, 54U)) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterE, 3U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 23U)) + aOrbiterA) + RotL64(aNonceWordD, 5U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 29U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterB, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Golf_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEF5F6BB96E0EB4EFULL + 0xB7FD5B9FD3C1E5E3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF8E60A5759157D33ULL + 0x928634C86B71B56FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xCCDDAEEE5B92C25FULL + 0xB1A6D110C5426E7CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB79ED6EE3DE51595ULL + 0xE6F896117852C680ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF245DBDDBD38B955ULL + 0x8466F9D22EC4C2F9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x80F1D6D91C3F3399ULL + 0xF7C9B3B748CB26CEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB5A2AB7404F43E4DULL + 0xCB085C39E1B96B62ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9D97247D1B227613ULL + 0xDEA3E234C5166D63ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 37U) ^ RotL64(aNonceWordG, 54U)) ^ RotL64(aNonceWordE, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6661U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 1264U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 38U) ^ RotL64(aNonceWordC, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7453U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 170U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCross, 3U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 2672739400294801233U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aScatter, 6U)) + 8475624545015101850U;
            aOrbiterH = (aWandererE + RotL64(aCross, 43U)) + 1252755112289831257U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 19U)) + 7938039507649183387U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 8167413146948861022U;
            aOrbiterF = (aWandererI + RotL64(aCross, 37U)) + 17712313989694374353U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 10U)) + RotL64(aCarry, 19U)) + 7637042279892596975U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 27U)) + 15770412950033467341U) + RotL64(aNonceWordH, 13U);
            aOrbiterA = (aWandererA + RotL64(aCross, 53U)) + 3951812021898608685U;
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 41U)) + 8656983621098246507U) + aOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1]) + RotL64(aNonceWordE, 41U);
            aOrbiterG = (aWandererB + RotL64(aScatter, 23U)) + 17943342344730687317U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3087677463651608668U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16493240011924342788U;
            aOrbiterH = RotL64((aOrbiterH * 16898479041530771871U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7750923317452683057U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2185924841611106546U;
            aOrbiterF = RotL64((aOrbiterF * 708072658250726381U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14676868738946722416U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6849098251696302393U;
            aOrbiterE = RotL64((aOrbiterE * 2599806275837778069U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17817755047153606419U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 9900465270314068757U) ^ RotL64(aNonceWordB, 56U);
            aOrbiterI = RotL64((aOrbiterI * 9267925873983176685U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11380000891112113701U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 15930503831156546113U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14450535035065393845U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 5439183530402949780U) + aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 3731802052051181843U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7739775058947333169U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14432344583247783600U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16192098795467501636U;
            aOrbiterG = RotL64((aOrbiterG * 6285466374319549047U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1523272672673940290U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7462092373525113574U;
            aOrbiterD = RotL64((aOrbiterD * 15067751170235540679U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4612539457663050732U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7959404391235752875U;
            aOrbiterB = RotL64((aOrbiterB * 137834571274065007U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11853468935131763944U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 3575434598998149168U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16971321675425065041U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 6135993440654291404U) + RotL64(aNonceWordC, 9U);
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2672739400294801233U;
            aOrbiterK = RotL64((aOrbiterK * 12891757276825641567U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 42U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 40U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 41U)) + aOrbiterG) + RotL64(aNonceWordA, 45U)) + aWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 21U) + RotL64(aOrbiterD, 43U)) + aOrbiterK) + RotL64(aCarry, 47U)) + RotL64(aNonceWordF, 11U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterB, 24U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterF, 51U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 13U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aCross, 54U) + RotL64(aOrbiterI, 3U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 21U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 34U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterC, 47U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 40U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordB, 34U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14959U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((aIndex + 16127U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 58U) ^ RotL64(aNonceWordE, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16261U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10692U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 35U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererI + RotL64(aIngress, 6U)) + 9630214189402543339U;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 43U)) + 4072576573737526819U) + RotL64(aNonceWordB, 61U);
            aOrbiterD = ((aWandererC + RotL64(aScatter, 23U)) + 15994787452709618869U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aPrevious, 39U)) + 6403240137132259482U;
            aOrbiterF = (aWandererD + RotL64(aCross, 58U)) + 10229266900170507720U;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 5025294577989748989U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aScatter, 19U)) + 16696461238217956883U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 47U)) + 9878318855341719119U;
            aOrbiterC = (aWandererF + RotL64(aCross, 3U)) + 16086635438116177346U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 43U)) + 12295437783084203730U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 27U)) + 7681150419912842402U) + RotL64(aNonceWordD, 9U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2639104034287637448U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 12298170009332243573U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9397919591171238575U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3485932317267669626U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16569551670038752475U;
            aOrbiterJ = RotL64((aOrbiterJ * 8139802826402217631U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4448490103784103954U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14510534073046885941U;
            aOrbiterF = RotL64((aOrbiterF * 7777192047386438305U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4286195398675733451U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 15790355933840266463U) ^ RotL64(aNonceWordA, 47U);
            aOrbiterB = RotL64((aOrbiterB * 13342257823027075501U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 6362891510370156055U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15121822034579983174U;
            aOrbiterC = RotL64((aOrbiterC * 7268045994574844937U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13817341015719915628U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14113474087906143783U;
            aOrbiterE = RotL64((aOrbiterE * 12838910141533126059U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9988301252236121106U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11287477288382171758U;
            aOrbiterK = RotL64((aOrbiterK * 4979297247881426383U), 35U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterH) + 9491727010910328644U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordG, 34U);
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7961202721830514030U;
            aOrbiterA = RotL64((aOrbiterA * 16300364540313620767U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10058066852293995222U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 541563830282750968U;
            aOrbiterH = RotL64((aOrbiterH * 1516823517052019845U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7791201128863372861U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 8334318157449352359U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2924838607279239375U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6861081455774799715U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9630214189402543339U;
            aOrbiterG = RotL64((aOrbiterG * 10837610668580336781U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 39U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 54U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 50U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 13U)) + aOrbiterB);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 13U)) + RotL64(aNonceWordC, 23U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 47U)) + RotL64(aNonceWordH, 59U));
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 35U)) + aOrbiterG) + aWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 46U) + RotL64(aOrbiterB, 21U)) + aOrbiterK) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterH, 44U));
            aWandererC = aWandererC + ((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterI, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterD, 57U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aPrevious, 60U) + aOrbiterA) + RotL64(aOrbiterC, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 42U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 13U) ^ RotL64(aNonceWordD, 47U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21838U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneA[((aIndex + 17677U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 39U) ^ RotL64(aNonceWordF, 23U)) ^ RotL64(aNonceWordC, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22076U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 20262U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 48U) + RotL64(aCarry, 19U)) ^ (RotL64(aCross, 35U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 8866844335448071821U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 15159698739856430085U) + RotL64(aNonceWordF, 37U);
            aOrbiterI = ((aWandererD + RotL64(aIngress, 18U)) + 9582805772989594633U) + RotL64(aNonceWordB, 61U);
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 39U)) + 1438538239931588373U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aScatter, 29U)) + 10862044156620436139U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 35U)) + 13682173320058164615U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 23U)) + 8351013291045977592U;
            aOrbiterK = (aWandererB + RotL64(aCross, 43U)) + 15777857431516633916U;
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 16178966745333885377U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aIngress, 26U)) + 9031889187993001617U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 41U)) + 6308472367425865347U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 642109145903321046U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 9186268569255318035U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) ^ RotL64(aNonceWordG, 25U);
            aOrbiterI = RotL64((aOrbiterI * 10714674348507516749U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6091345356803675860U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13218507921880873749U;
            aOrbiterF = RotL64((aOrbiterF * 15415157927185637717U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4266652275234474616U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 4391422098164506195U) ^ aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17634679403195085867U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 5160682323243635577U) + aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10351728852161347404U;
            aOrbiterJ = RotL64((aOrbiterJ * 11105410036471745951U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3950932176454814023U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9536466386833427441U;
            aOrbiterK = RotL64((aOrbiterK * 18064984243491293435U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 9927425919978776529U) + RotL64(aNonceWordE, 53U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 6819384090527481081U) ^ aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18032965969184368561U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1646274931424218507U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16166524473976135097U;
            aOrbiterA = RotL64((aOrbiterA * 11672192658072663849U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11252501968059485262U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16847854447987609067U;
            aOrbiterE = RotL64((aOrbiterE * 6326299154627028295U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16723218285355036446U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13870211254243048975U;
            aOrbiterC = RotL64((aOrbiterC * 10203222183774624097U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11401147367366049493U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4266628469244269926U;
            aOrbiterH = RotL64((aOrbiterH * 2409934496621365221U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11578385782347296942U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8866844335448071821U;
            aOrbiterD = RotL64((aOrbiterD * 6456956795450036515U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 22U);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterG, 58U));
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterG, 13U));
            aWandererE = aWandererE + ((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 5U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 26U) + aOrbiterE) + RotL64(aOrbiterD, 37U));
            aWandererG = aWandererG + (((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 21U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterD, 39U)) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterH, 41U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 43U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 34U) + aOrbiterK) + RotL64(aOrbiterE, 24U)) + RotL64(aNonceWordC, 26U)) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 51U)) + aOrbiterI) + RotL64(aNonceWordA, 3U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 19U) ^ RotL64(aNonceWordF, 47U)) ^ RotL64(aNonceWordE, 11U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27852U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31389U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 5U) ^ RotL64(aNonceWordH, 29U)) ^ RotL64(aNonceWordC, 38U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30189U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 26097U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCross, 27U)) + (RotL64(aPrevious, 60U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererB + RotL64(aIngress, 10U)) + 966899917801652720U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 21U)) + 10996327672320748649U;
            aOrbiterE = (aWandererC + RotL64(aCross, 29U)) + 4188171566846621107U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 5886209243097387959U) + RotL64(aNonceWordF, 31U);
            aOrbiterJ = ((aWandererI + RotL64(aCross, 48U)) + RotL64(aCarry, 11U)) + 14940428957136728111U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 27U)) + 179187285531914832U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 3U)) + 6685351948936817752U;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 21U)) + 1894506461704029700U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aCross, 35U)) + 4182760368636977082U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 5U)) + 12523318028514940790U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aScatter, 41U)) + 5059306166973366892U) + RotL64(aNonceWordA, 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5890872367917643851U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 17747338389865221534U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5306740664798049267U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13906227834259884100U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7152105382899756368U;
            aOrbiterJ = RotL64((aOrbiterJ * 6772157117358310485U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 17868101884759619240U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11758843266314148347U;
            aOrbiterI = RotL64((aOrbiterI * 5919135169337501485U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13950566197090324859U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 17278105609930477854U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11431842718945107359U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9556785965646738355U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 841298436857932987U;
            aOrbiterK = RotL64((aOrbiterK * 15077843186688841797U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1951515285492133830U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15775839819330588437U;
            aOrbiterD = RotL64((aOrbiterD * 7902654031401620995U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 5585458468816495436U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 17258586689032223623U) ^ RotL64(aNonceWordH, 3U);
            aOrbiterH = RotL64((aOrbiterH * 1652050227399194271U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5254132659445988836U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15440741734777060925U;
            aOrbiterB = RotL64((aOrbiterB * 17445581079035134067U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16770361602586485631U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14902616717976301965U;
            aOrbiterC = RotL64((aOrbiterC * 7757713071544143453U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9521517757370835715U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 18241677917767801049U;
            aOrbiterG = RotL64((aOrbiterG * 16977396965907931057U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 14307634663160859644U) + RotL64(aNonceWordC, 45U);
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 966899917801652720U;
            aOrbiterF = RotL64((aOrbiterF * 17012361848398765251U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 39U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterE, 11U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 24U)) + aOrbiterE);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 27U)) + RotL64(aNonceWordD, 19U));
            aWandererH = aWandererH + (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 47U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 43U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aCross, 28U) + RotL64(aOrbiterI, 37U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 5U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterD, 57U)) + RotL64(aNonceWordB, 38U)) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterC, 22U)) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterF, 13U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 36U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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

void TwistExpander_Golf_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB9C759BAD94FA85BULL + 0xD2708CB46097C655ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC03FC867B2B3DCE1ULL + 0xDA770627F6257284ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8F2449F8C8F20899ULL + 0x8EB2025EC4295F7EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xAA9FCBB6AA13A3B9ULL + 0xF825100A4DE1FA80ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFEC95E15C9B1ADD1ULL + 0xAB5717721C5F77F8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE26B6D0C803B441BULL + 0x8C64EF11337294DCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC03676F7193D420BULL + 0xE8C8D0BACDB069B6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9679545D699BC171ULL + 0xCFCF3D00DD1F1591ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordE, 11U)) ^ RotL64(aNonceWordH, 50U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 469U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2769U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 27U) ^ RotL64(aNonceWordA, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2207U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 291U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 40U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 46U)) + 7651355040951791298U) + RotL64(aNonceWordB, 61U);
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 41U)) + 13988210277931659312U) + RotL64(aNonceWordD, 29U);
            aOrbiterF = (aWandererK + RotL64(aIngress, 53U)) + 9846849412579537783U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 12746719939495876158U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 36U)) + 11498066185182895284U;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 11101058955193080232U) + aOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aCross, 11U)) + 15513734459555672046U) + aOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 15711108675349394643U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 3U)) + 4771231759949468556U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 11449258010811305256U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17036938391509986723U;
            aOrbiterF = RotL64((aOrbiterF * 7411466953205347639U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 6999245666776654250U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2106819066263369528U;
            aOrbiterB = RotL64((aOrbiterB * 13005885810757743129U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12716183358903477216U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16752724547046059889U;
            aOrbiterK = RotL64((aOrbiterK * 11475905692393034141U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17623077680983093163U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6726003022297274986U;
            aOrbiterE = RotL64((aOrbiterE * 14709385877103232653U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 2842410225096524740U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9235178377537910514U;
            aOrbiterD = RotL64((aOrbiterD * 11813751114775673845U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2619888019860844610U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6295481948199619613U;
            aOrbiterI = RotL64((aOrbiterI * 15429161806953951205U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9724921158061115570U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4070976180958458679U;
            aOrbiterH = RotL64((aOrbiterH * 6080566609081811453U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5864247978960125554U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7771249710071026757U;
            aOrbiterG = RotL64((aOrbiterG * 4787660062590737657U), 3U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 15006900854988166845U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) + RotL64(aNonceWordC, 3U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 2755659268987119046U) ^ RotL64(aNonceWordE, 19U);
            aOrbiterA = RotL64((aOrbiterA * 8043939381186802359U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (RotL64(aOrbiterE, 58U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterH, 18U)) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterI, 51U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterB, 27U));
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterA, 39U));
            aWandererB = aWandererB + ((RotL64(aCross, 56U) + RotL64(aOrbiterG, 13U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterG, 22U)) + RotL64(aNonceWordG, 42U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 5U)) + aOrbiterK) + RotL64(aNonceWordA, 23U)) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 39U) ^ RotL64(aNonceWordA, 5U)) ^ RotL64(aNonceWordG, 60U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6070U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8185U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordH, 52U)) ^ RotL64(aNonceWordB, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8315U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 10845U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 37U)) ^ (RotL64(aCarry, 54U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererI + RotL64(aScatter, 58U)) + RotL64(aCarry, 57U)) + 1042610313571524121U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 43U)) + 3505725321008825582U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 3U)) + 12584654563843782991U) + aOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 27U)) + 6645399144515770935U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + RotL64(aNonceWordA, 11U);
            aOrbiterF = (aWandererC + RotL64(aScatter, 47U)) + 3608978423753715584U;
            aOrbiterD = (aWandererD + RotL64(aCross, 23U)) + 8089198857670370983U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 27U)) + 15207251813516399879U;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 14U)) + RotL64(aCarry, 3U)) + 9579268660105824516U) + RotL64(aNonceWordC, 57U);
            aOrbiterA = (aWandererG + RotL64(aPrevious, 51U)) + 16055044469473802812U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 583811872609805949U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 7027491967970873942U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12686754713465826139U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 18256061823189677508U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12708429127816136937U;
            aOrbiterF = RotL64((aOrbiterF * 12593886633108075321U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 12169216645156306078U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 12694325407567795065U) ^ aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3711789483877261899U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16109994660203297503U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 4234704064165718913U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 730085881474787681U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14119541943554602878U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8777769004811352951U;
            aOrbiterA = RotL64((aOrbiterA * 2556957257736134223U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 15642663488392549609U) + RotL64(aNonceWordE, 9U);
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11594468530833278624U;
            aOrbiterB = RotL64((aOrbiterB * 6639306656361601143U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7365350535791499871U) + RotL64(aNonceWordG, 12U);
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5965170981970155956U;
            aOrbiterE = RotL64((aOrbiterE * 1898702752753066851U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9115232101451815522U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9433983580038990072U;
            aOrbiterD = RotL64((aOrbiterD * 1951249217843992179U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8810565477444156140U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12081286530401844859U;
            aOrbiterJ = RotL64((aOrbiterJ * 1991383259486140229U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 20U));
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterI, 5U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterG, 36U)) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 57U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterB, 13U));
            aWandererI = aWandererI + ((((RotL64(aCross, 34U) + aOrbiterE) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 30U)) + aOrbiterA);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 47U)) + aOrbiterI) + RotL64(aCarry, 21U)) + RotL64(aNonceWordF, 17U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterI, 43U)) + RotL64(aNonceWordD, 23U));
            aWandererH = aWandererH + ((RotL64(aCross, 60U) + RotL64(aOrbiterF, 51U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 19U) ^ RotL64(aNonceWordG, 51U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13001U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12648U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 43U) ^ RotL64(aNonceWordA, 18U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15772U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14069U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 35U)) + (RotL64(aPrevious, 48U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 6342299552323486695U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 29U)) + 12692748514781367538U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 6U)) + 8202639945493229155U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aIngress, 51U)) + 4439975701793231639U;
            aOrbiterK = (((aWandererC + RotL64(aCross, 11U)) + 16774235182859553759U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + RotL64(aNonceWordH, 17U);
            aOrbiterF = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 8764155413335405667U;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 24U)) + RotL64(aCarry, 57U)) + 7167848811974967685U) + RotL64(aNonceWordG, 57U);
            aOrbiterJ = (aWandererK + RotL64(aScatter, 19U)) + 16768278912125334220U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 35U)) + 9090838954826296201U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 7644075729758006298U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17326182797908071215U;
            aOrbiterB = RotL64((aOrbiterB * 2408330168749256075U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16158809721888137555U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8029938783858263694U;
            aOrbiterH = RotL64((aOrbiterH * 12628072435324195483U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8716553521415553404U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7012599977009208840U;
            aOrbiterC = RotL64((aOrbiterC * 8775355876188948851U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 13250558696578541499U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13705957059101025396U;
            aOrbiterA = RotL64((aOrbiterA * 16889495686487056367U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2796775206291902461U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13741676263512390669U;
            aOrbiterK = RotL64((aOrbiterK * 10455782033465595947U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 1691908360612389252U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 4114939415206031540U) ^ aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2797401802892718297U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 2374911514440738727U) + RotL64(aNonceWordA, 3U);
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12377616933668803091U;
            aOrbiterI = RotL64((aOrbiterI * 2505164835116651215U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 681094033415259645U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 13841322124900463362U) ^ RotL64(aNonceWordE, 51U);
            aOrbiterJ = RotL64((aOrbiterJ * 4210414203856902329U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 18082983557580381338U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15731122225678626778U;
            aOrbiterG = RotL64((aOrbiterG * 7785999919955613789U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 39U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (RotL64(aOrbiterK, 6U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 12U) + RotL64(aOrbiterK, 19U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterC, 47U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 39U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 28U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterH, 43U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 57U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ) + RotL64(aNonceWordD, 9U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 53U)) + aOrbiterA) + RotL64(aNonceWordB, 54U));
            aWandererD = aWandererD + ((((RotL64(aCross, 48U) + RotL64(aOrbiterB, 10U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 24U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 51U) ^ RotL64(aNonceWordA, 37U)) ^ RotL64(aNonceWordC, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20139U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20953U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 56U) ^ RotL64(aNonceWordH, 19U)) ^ RotL64(aNonceWordB, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20634U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19980U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 26U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 18U)) + RotL64(aCarry, 43U)) + 5295352595333316211U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 41U)) + 2341795367042042605U) + RotL64(aNonceWordE, 9U);
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 47U)) + 10122175780504033663U) + aOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1]) + RotL64(aNonceWordG, 12U);
            aOrbiterF = (((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 10084612804696198554U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aPrevious, 11U)) + 16470424309851045971U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 6U)) + RotL64(aCarry, 23U)) + 656016130975227994U;
            aOrbiterB = (aWandererI + RotL64(aCross, 53U)) + 15313268829659834317U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 35U)) + 3795220914993923394U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 23U)) + 14044442220988813825U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3804224626734584802U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7980006306010255693U;
            aOrbiterK = RotL64((aOrbiterK * 13958505239726088561U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13746830564584711549U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 11852212099729274845U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2164880979318247855U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9083223471018084847U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13706723820703853346U;
            aOrbiterB = RotL64((aOrbiterB * 11361854103656219887U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1713819986642275223U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1382000168233902914U;
            aOrbiterJ = RotL64((aOrbiterJ * 3894160765130198157U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4540474625764565485U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 1756168174375757220U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) ^ RotL64(aNonceWordH, 35U);
            aOrbiterF = RotL64((aOrbiterF * 12739160208010092017U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1409297070183609309U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6082750101445444357U;
            aOrbiterC = RotL64((aOrbiterC * 17438740230251860935U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1113239890859479202U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 10932192439503964363U) ^ aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5915660289913324281U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3732595033748508428U) + aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5117760372351117286U;
            aOrbiterH = RotL64((aOrbiterH * 2671510075176315761U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 7399968659654088641U) + RotL64(aNonceWordC, 13U);
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14835608167871904147U;
            aOrbiterE = RotL64((aOrbiterE * 8312521710415756159U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 14U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 54U) + aOrbiterB) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterB, 11U));
            aWandererG = aWandererG + ((RotL64(aCross, 43U) + RotL64(aOrbiterA, 35U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 46U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterD, 53U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB) + RotL64(aNonceWordF, 11U)) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 14U) + aOrbiterH) + RotL64(aOrbiterD, 27U)) + RotL64(aNonceWordD, 57U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 40U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 6U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 11U) ^ RotL64(aNonceWordD, 56U)) ^ RotL64(aNonceWordC, 47U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25675U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 25958U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 39U) ^ RotL64(aNonceWordF, 27U)) ^ RotL64(aNonceWordA, 56U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23995U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24169U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCross, 29U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 52U)) + RotL64(aCarry, 37U)) + 4752759164691497960U;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 21U)) + 12088872623537639782U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aIngress, 57U)) + 3734943577379734227U) + RotL64(aNonceWordG, 45U);
            aOrbiterA = (aWandererA + RotL64(aPrevious, 43U)) + 8854778183012444234U;
            aOrbiterB = (aWandererC + RotL64(aCross, 13U)) + 16948373492893967275U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 7962415690046184385U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 27U)) + 1872682375669714454U;
            aOrbiterE = (((aWandererK + RotL64(aScatter, 48U)) + 7776801806943853566U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1]) + RotL64(aNonceWordA, 31U);
            aOrbiterK = (aWandererF + RotL64(aPrevious, 19U)) + 16665439117257230732U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 11088186766134265676U) + RotL64(aNonceWordE, 38U);
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10850237991780969350U;
            aOrbiterH = RotL64((aOrbiterH * 7547414856143095121U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6464817712131305812U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 244557182884209844U;
            aOrbiterC = RotL64((aOrbiterC * 2394270354887582889U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13261563971157415841U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2323811103717827362U;
            aOrbiterE = RotL64((aOrbiterE * 11483723582415081925U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 12338803568475493422U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2811342930111104982U;
            aOrbiterK = RotL64((aOrbiterK * 5020981755203607757U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 5554497011738996057U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 12712169745460598698U) ^ RotL64(aNonceWordD, 35U);
            aOrbiterJ = RotL64((aOrbiterJ * 1985586486150377769U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17415058661427002973U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9430421222715343818U;
            aOrbiterA = RotL64((aOrbiterA * 10321140659099470811U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3926618548181233180U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6172453297026957838U;
            aOrbiterD = RotL64((aOrbiterD * 1161551082037835233U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8633288765997226004U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 17270881130844274342U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8888559940161770791U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12232950994807835262U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 15352600312956742750U) ^ aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6140396356904933003U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 52U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterH, 60U)) + aOrbiterA) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordF, 17U)) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterE, 11U));
            aWandererK = aWandererK + ((RotL64(aCross, 51U) + RotL64(aOrbiterA, 23U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 35U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 18U) + aOrbiterD) + RotL64(aOrbiterC, 39U));
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterF, 29U)) + RotL64(aNonceWordC, 15U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterK, 18U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordG, 43U)) ^ RotL64(aNonceWordB, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28581U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29696U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 41U) ^ RotL64(aNonceWordD, 30U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27541U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 32280U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererA + RotL64(aIngress, 29U)) + 1364174714924216027U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 60U)) + RotL64(aCarry, 3U)) + 13561796874229506613U;
            aOrbiterG = (aWandererF + RotL64(aCross, 19U)) + 11845572344206238305U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 39U)) + 15762708240326773763U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 35U)) + 1157119665207900473U;
            aOrbiterK = ((((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 6823546624372055260U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordH, 36U);
            aOrbiterE = (aWandererE + RotL64(aScatter, 47U)) + 14465564210523945121U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 56U)) + 10667464548080807531U) + aOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + RotL64(aNonceWordA, 53U);
            aOrbiterJ = (aWandererC + RotL64(aScatter, 43U)) + 13445737493224316575U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 3009837893785957665U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2886920524111083752U;
            aOrbiterG = RotL64((aOrbiterG * 15308180928967762543U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 10886177449328249656U) + RotL64(aNonceWordG, 21U);
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15067759884678100433U;
            aOrbiterC = RotL64((aOrbiterC * 5724566815989860041U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 18307930462682331536U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8791864377579255801U;
            aOrbiterE = RotL64((aOrbiterE * 9265158882471421767U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 805797468642992351U) + RotL64(aNonceWordD, 3U);
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5743305867058244964U;
            aOrbiterI = RotL64((aOrbiterI * 16263000753351131717U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17102025528234481273U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1841579177327486899U;
            aOrbiterJ = RotL64((aOrbiterJ * 3841603385577825265U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 2189493507896508972U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 18209567010094914374U;
            aOrbiterB = RotL64((aOrbiterB * 3737080408976852351U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6697069234216868330U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 927471474577415372U) ^ aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10680760991009199309U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13155854301197725408U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1014625081915435892U;
            aOrbiterK = RotL64((aOrbiterK * 11592754232949990435U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 12697209921410914931U) + aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11555096613655648647U;
            aOrbiterD = RotL64((aOrbiterD * 4598821388864997089U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 56U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 53U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterK, 46U)) + RotL64(aCarry, 47U)) + RotL64(aNonceWordB, 29U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 5U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 23U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterB, 13U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 57U)) + aOrbiterA) + RotL64(aNonceWordE, 35U));
            aWandererE = aWandererE + (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterI, 34U)) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 4U) + aOrbiterB) + RotL64(aOrbiterC, 19U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 54U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Golf_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8E69C25F28F63D1DULL + 0x80E8A7442CF44B83ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x88A91FAB1A3DB407ULL + 0xC95844C287C772F3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB850D5FDB08EC07BULL + 0xD4ADF9C7E9657923ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD087A90A5E29EA87ULL + 0xA5E2320B2543BCF4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC853E260E02EBA8DULL + 0x985BB091C2FA3A1CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC51F764396FD496FULL + 0xFAE331A249AD69F4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDB94A311EC1AC49FULL + 0xAA31FBE9E156B65BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFEF5617BC9B37513ULL + 0x9E57138E0D2C896AULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 23U) ^ RotL64(aNonceWordG, 57U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4026U)) & S_BLOCK1], 34U) ^ RotL64(aKeyRowReadA[((aIndex + 3122U)) & W_KEY1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 22U) ^ RotL64(aNonceWordD, 5U)) ^ RotL64(aNonceWordE, 51U));
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 1433U)) & W_KEY1], 37U) ^ RotL64(mSource[((aIndex + 2828U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 21U)) + (RotL64(aCarry, 52U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = ((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 898812731947995389U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 27U)) + 8677347622525527167U) + RotL64(aNonceWordD, 29U);
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 11U)) + 770321564027567654U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + RotL64(aNonceWordA, 3U);
            aOrbiterH = ((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 11020474858081526395U;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 17289793580414993470U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aCross, 47U)) + 10111912559295118444U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 18U)) + 8083622125544542011U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7149858558922988240U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 5919683821379905699U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16705119888884231567U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6860902846079238714U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15083517836867542075U;
            aOrbiterD = RotL64((aOrbiterD * 4686657139237578325U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14852868368708376381U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9860233289028878323U;
            aOrbiterK = RotL64((aOrbiterK * 13418143547952204667U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 772406119079116272U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7971141501337627589U;
            aOrbiterG = RotL64((aOrbiterG * 10168120622976358617U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8478568022896691911U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4027604850785607101U;
            aOrbiterA = RotL64((aOrbiterA * 4826627523578901467U), 37U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 17199331557841535430U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordE, 5U);
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7515957656979776361U;
            aOrbiterH = RotL64((aOrbiterH * 5468950152869656599U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 17138249294921502391U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 16236812863923234668U) ^ RotL64(aNonceWordC, 17U);
            aOrbiterJ = RotL64((aOrbiterJ * 2925542836624164807U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 5U)) + aOrbiterD) + RotL64(aNonceWordH, 24U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 39U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterK, 29U));
            aWandererC = aWandererC + (((RotL64(aCross, 11U) + RotL64(aOrbiterA, 20U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 46U) + RotL64(aOrbiterE, 47U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 11U)) + aOrbiterG) + RotL64(aNonceWordB, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 28U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 14U) ^ RotL64(aNonceWordH, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6214U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6649U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 21U) ^ RotL64(aNonceWordB, 58U)) ^ RotL64(aNonceWordF, 11U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7925U)) & W_KEY1], 29U) ^ RotL64(aKeyRowReadB[((aIndex + 9842U)) & W_KEY1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aPrevious, 18U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((aWandererK + RotL64(aIngress, 51U)) + 3255291173184001106U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aPrevious, 60U)) + 15308468160116255528U;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 18186972408589866656U) + aPhaseAOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aCross, 41U)) + 4439324265978331914U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 27U)) + 13099263173016322486U;
            aOrbiterD = (((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 7041561081767500660U) + RotL64(aNonceWordG, 6U);
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 11U)) + 6196422612687812971U) + RotL64(aNonceWordC, 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7664260932541281413U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17802347823020441056U;
            aOrbiterK = RotL64((aOrbiterK * 2220679459017369255U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4253107484061190446U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 13799496534030645312U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9167675060053848207U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14252892847595951926U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5663527578664291422U;
            aOrbiterG = RotL64((aOrbiterG * 18314294235895182465U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 11148755959699137661U) + RotL64(aNonceWordE, 37U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 17036900929333594592U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16041243617369003291U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2403828181385259549U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 17813580350434928194U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13666780980793857831U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 5623611126885414523U) + RotL64(aNonceWordA, 11U);
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7293224381174846969U;
            aOrbiterD = RotL64((aOrbiterD * 7032561584670788117U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10602620906929686163U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 18015916257203385982U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10684090189688871993U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 43U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 19U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 30U) + aOrbiterF) + RotL64(aOrbiterA, 57U));
            aWandererH = aWandererH + (((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterG, 48U)) + aPhaseAWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 29U)) + aPhaseAWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterF, 27U)) + RotL64(aNonceWordD, 49U));
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterK, 41U)) + RotL64(aNonceWordB, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 44U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 14U) ^ RotL64(aNonceWordH, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12908U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15204U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 47U) ^ RotL64(aNonceWordD, 39U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14900U)) & W_KEY1], 14U) ^ RotL64(aKeyRowReadB[((aIndex + 15032U)) & W_KEY1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 39U)) + (RotL64(aCross, 5U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 11U)) + 701291026547470433U;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 17283292650462111643U) + RotL64(aNonceWordB, 19U);
            aOrbiterK = (aWandererJ + RotL64(aCross, 20U)) + 9969124091931303406U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 11U)) + 889176772718046988U) + RotL64(aNonceWordG, 51U);
            aOrbiterE = (((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 6054541844643748084U) + aPhaseAOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 57U)) + 14703226235143028132U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 3U)) + 7977975878522921062U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16894322614172266274U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 12160451749345900570U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18055355572903901749U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10870847008043897470U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8159920947172520247U;
            aOrbiterI = RotL64((aOrbiterI * 4833194641611011805U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2440099120969517932U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2428396147731468007U;
            aOrbiterB = RotL64((aOrbiterB * 9363073341539598441U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2213226274394673479U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7079731443427765333U;
            aOrbiterJ = RotL64((aOrbiterJ * 16918930776877030559U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 958896789550478970U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 10788682955708075458U) ^ RotL64(aNonceWordE, 7U);
            aOrbiterE = RotL64((aOrbiterE * 913321215613559729U), 41U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 2003386579317564870U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + RotL64(aNonceWordA, 9U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 8419686358774204999U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6547052526438697621U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6989167615157578904U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17636634003643824148U;
            aOrbiterA = RotL64((aOrbiterA * 11038576417283732937U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 37U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 44U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 41U)) + aOrbiterK) + RotL64(aNonceWordF, 26U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 35U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterB, 47U)) + aPhaseAWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 58U) + RotL64(aOrbiterK, 53U)) + aOrbiterA) + RotL64(aNonceWordC, 53U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterE, 4U));
            aWandererD = aWandererD + (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 13U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterJ, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 30U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 19U) ^ RotL64(aNonceWordH, 37U)) ^ RotL64(aNonceWordD, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17882U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 20087U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 41U) ^ RotL64(aNonceWordF, 29U)) ^ RotL64(aNonceWordA, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21639U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 18760U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 37U)) ^ (RotL64(aIngress, 3U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = (aWandererJ + RotL64(aCross, 23U)) + 2571116506511057880U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 13112435411509707292U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 29U)) + 10403251762787357256U) + aPhaseAOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aIngress, 11U)) + 8461951095541400405U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) + RotL64(aNonceWordD, 22U);
            aOrbiterH = (aWandererH + RotL64(aScatter, 41U)) + 9890793478557463815U;
            aOrbiterK = (((aWandererC + RotL64(aCross, 54U)) + RotL64(aCarry, 41U)) + 3030229465991783707U) + RotL64(aNonceWordB, 45U);
            aOrbiterF = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 53U)) + 7273848154043719247U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10681774862516028276U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 7105082755586853104U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12217705329504230357U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6588579345319551129U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 14616333550242386092U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) ^ RotL64(aNonceWordE, 35U);
            aOrbiterK = RotL64((aOrbiterK * 2934574715879306337U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15439666290229654921U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3360304356760164799U;
            aOrbiterJ = RotL64((aOrbiterJ * 5164191920584106237U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 14438730801970761889U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14515616787452085729U;
            aOrbiterH = RotL64((aOrbiterH * 2041601927968559821U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4167853822635132419U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8950982233003320239U;
            aOrbiterI = RotL64((aOrbiterI * 887144270884244907U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12391327853728029953U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7100871010552394421U;
            aOrbiterG = RotL64((aOrbiterG * 16552349374101955967U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15381697462381887944U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 6801677551341079401U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) ^ RotL64(aNonceWordH, 15U);
            aOrbiterF = RotL64((aOrbiterF * 13325954438427340703U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 58U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterJ, 11U));
            aWandererF = aWandererF + ((((RotL64(aCross, 30U) + aOrbiterK) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 37U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 43U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 37U)) + aOrbiterH) + RotL64(aNonceWordA, 11U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterI, 21U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordF, 61U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterK, 60U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 43U) ^ RotL64(aNonceWordF, 23U)) ^ RotL64(aNonceWordC, 54U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25517U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 22849U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 58U) ^ RotL64(aNonceWordH, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25384U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 25045U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 53U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 28U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 3238389262925516513U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 41U)) + 12381787182611386995U;
            aOrbiterJ = ((((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 7883885539305181549U) + aPhaseAOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordD, 18U);
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 57U)) + 1185413044597727092U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + RotL64(aNonceWordH, 11U);
            aOrbiterK = (aWandererD + RotL64(aIngress, 19U)) + 15219353497204773135U;
            aOrbiterA = (aWandererA + RotL64(aCross, 51U)) + 7533774715626734082U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 30U)) + RotL64(aCarry, 51U)) + 2599930450937763464U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16074720663961214284U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15483613196360051221U;
            aOrbiterJ = RotL64((aOrbiterJ * 11717479088020532861U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9396557867081376268U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 9668459976852660245U) ^ RotL64(aNonceWordE, 15U);
            aOrbiterH = RotL64((aOrbiterH * 11748505665890567063U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 9037269914643207212U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16936742640861088240U;
            aOrbiterE = RotL64((aOrbiterE * 1040172193161012227U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16481274825758546398U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 481851372837611166U;
            aOrbiterG = RotL64((aOrbiterG * 2225030139210599207U), 51U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 13608921517203544108U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordG, 37U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 16930740723286214636U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2605108503821980865U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 902242902582149908U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1510861213079342977U;
            aOrbiterA = RotL64((aOrbiterA * 3309753895727400707U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7116243600304980310U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 6631412278359709602U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11452627691392637463U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 41U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterA, 21U)) + aPhaseAWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 60U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + RotL64(aNonceWordB, 27U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 41U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 11U)) + aOrbiterG);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 12U) + aOrbiterH) + RotL64(aOrbiterG, 5U)) + RotL64(aNonceWordC, 13U));
            aWandererA = aWandererA + ((((RotL64(aCross, 27U) + RotL64(aOrbiterK, 35U)) + aOrbiterE) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 47U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererD, 34U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 39U) ^ RotL64(aNonceWordG, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29902U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29696U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordD, 28U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29790U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32482U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 5U)) + (RotL64(aIngress, 56U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = (aWandererB + RotL64(aScatter, 19U)) + 4179952823252098240U;
            aOrbiterG = (((aWandererD + RotL64(aCross, 48U)) + RotL64(aCarry, 41U)) + 3745613452332101749U) + RotL64(aNonceWordE, 47U);
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 29U)) + 2955689793395307176U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 5639060180251322019U;
            aOrbiterD = (((aWandererG + RotL64(aCross, 57U)) + 7901969163853586463U) + aPhaseAOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordH, 31U);
            aOrbiterH = (aWandererF + RotL64(aScatter, 41U)) + 2242166787816318119U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 35U)) + 5239936443960750064U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13939136954732185558U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 17058884136712717463U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7222348891215482977U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 18148618660054585941U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7022023484530327814U;
            aOrbiterD = RotL64((aOrbiterD * 650100011311048589U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7722084537340095637U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11764151879690934182U;
            aOrbiterH = RotL64((aOrbiterH * 12264384877711365655U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 16412785901758144708U) + RotL64(aNonceWordC, 12U);
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9666718667728274824U;
            aOrbiterA = RotL64((aOrbiterA * 10865799822751771795U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4307127540152109364U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 2457646804702647606U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6340030928007058595U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 3179394870088602208U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 504977947273774249U;
            aOrbiterF = RotL64((aOrbiterF * 16190282058883481551U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16182729401018310837U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 7110817020445860609U) ^ RotL64(aNonceWordA, 49U);
            aOrbiterG = RotL64((aOrbiterG * 13371352088428584087U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 51U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 12U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterJ, 21U)) + aPhaseAWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterH, 37U)) + RotL64(aNonceWordD, 35U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 43U)) + aOrbiterD) + RotL64(aNonceWordB, 5U)) + aPhaseAWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 51U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 14U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Golf_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC4DC349EA1AE21F1ULL + 0xEF9DA86A70896645ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xBD0D5A628C690A6BULL + 0x8ED0886B16AAB5B7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD3C46F0F57A7EC71ULL + 0x971EB1FA27389A73ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF2AFE294DCCF559FULL + 0xDB4685C66E99E4DFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBB7EC48035BD784BULL + 0xFB7A3E599E3580DEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA2A356A66F6EA2A3ULL + 0x8F43294508FECB35ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD7D74A13E77734D9ULL + 0x8532F504C83DB160ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCBA890BE1A42DAABULL + 0xD7B83F45EE4916A1ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 24U) ^ RotL64(aNonceWordF, 3U)) ^ RotL64(aNonceWordG, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1448U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 3435U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 11U) ^ RotL64(aNonceWordE, 41U)) ^ RotL64(aNonceWordD, 51U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5217U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 5356U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 54U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 41U)) + 4179952823252098240U) + RotL64(aNonceWordB, 39U);
            aOrbiterH = (aWandererC + RotL64(aIngress, 27U)) + 3745613452332101749U;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 2955689793395307176U) + aPhaseBOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 36U)) + RotL64(aCarry, 57U)) + 5639060180251322019U;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 11U)) + 7901969163853586463U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + RotL64(aNonceWordE, 47U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 2242166787816318119U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1]) + RotL64(aNonceWordD, 37U);
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5239936443960750064U;
            aOrbiterF = RotL64((aOrbiterF * 2752853245379816327U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 13939136954732185558U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17058884136712717463U;
            aOrbiterE = RotL64((aOrbiterE * 7222348891215482977U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 18148618660054585941U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 7022023484530327814U) ^ RotL64(aNonceWordA, 61U);
            aOrbiterD = RotL64((aOrbiterD * 650100011311048589U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 7722084537340095637U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11764151879690934182U;
            aOrbiterH = RotL64((aOrbiterH * 12264384877711365655U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16412785901758144708U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 9666718667728274824U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10865799822751771795U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 19U)) + RotL64(aNonceWordF, 23U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterE, 57U));
            aWandererF = aWandererF + (((RotL64(aCross, 53U) + RotL64(aOrbiterG, 11U)) + aOrbiterH) + RotL64(aNonceWordG, 24U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterF, 24U)) + aPhaseBWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterD, 47U)) + aOrbiterG) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 53U) ^ RotL64(aNonceWordD, 43U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8352U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10771U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 41U) ^ RotL64(aNonceWordH, 19U)) ^ RotL64(aNonceWordB, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7978U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7014U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 40U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = (((aWandererH + RotL64(aIngress, 14U)) + RotL64(aCarry, 19U)) + 16189787374324972735U) + RotL64(aNonceWordE, 45U);
            aOrbiterK = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 39U)) + 17563763730956242224U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 47U)) + 10572803498593789385U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 7713105232072974166U) + RotL64(aNonceWordD, 5U);
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 3U)) + 10760839534772718139U) + aPhaseBOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 13397069448391230253U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4569255679998375682U;
            aOrbiterH = RotL64((aOrbiterH * 15163488708398248639U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9888769350817876949U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 11351796060878856300U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13356749147334008399U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 18153775071965707204U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 1282846411145853435U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12294455920906257823U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16457743979262460660U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 173493260775251032U) ^ RotL64(aNonceWordA, 56U);
            aOrbiterK = RotL64((aOrbiterK * 4935807229040883505U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3927345926316409630U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 5158769729850853623U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) ^ RotL64(aNonceWordF, 3U);
            aOrbiterD = RotL64((aOrbiterD * 2446452358663812945U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 5U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 58U)) + aOrbiterA);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterA, 21U)) + RotL64(aNonceWordB, 51U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordG, 47U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 40U) + aOrbiterD) + RotL64(aOrbiterA, 11U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 41U)) + aPhaseBWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 44U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 21U) ^ RotL64(aNonceWordH, 44U)) ^ RotL64(aNonceWordE, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 10957U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 15301U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 35U) ^ RotL64(aNonceWordF, 24U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15812U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15011U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 13U)) + (RotL64(aPrevious, 42U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 7960325128608297381U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordB, 29U);
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 12773836012104052042U) + RotL64(aNonceWordG, 55U);
            aOrbiterH = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 3173972621347773016U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 12U)) + 3708401356314308171U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aIngress, 51U)) + 950774285720019449U;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 4170092315705438265U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + RotL64(aNonceWordC, 61U);
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17000449130864980747U;
            aOrbiterH = RotL64((aOrbiterH * 7710635557693533263U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8793910540062893860U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 520277969543516469U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4150613128885828229U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12762214857389827271U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2932451184340207695U;
            aOrbiterD = RotL64((aOrbiterD * 7513337346940091655U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 11062179998786293839U) + RotL64(aNonceWordA, 11U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 7919119215271524178U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9053677007180081359U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1774988449597115155U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 3799792889466518953U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17512791286490623455U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 40U);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterF, 47U)) + aOrbiterD) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 23U)) + aOrbiterH) + RotL64(aCarry, 41U)) + RotL64(aNonceWordH, 38U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 14U)) + aOrbiterG) + aPhaseBWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 37U)) + aOrbiterH) + RotL64(aCarry, 5U)) + RotL64(aNonceWordD, 41U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 57U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererA, 52U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 10U) ^ RotL64(aNonceWordD, 57U)) ^ RotL64(aNonceWordC, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 17894U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 18718U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 39U) ^ RotL64(aNonceWordH, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21602U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 21055U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 53U)) + (RotL64(aPrevious, 18U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 2168513956284366370U;
            aOrbiterD = ((((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 13U)) + 10290361969974613111U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + RotL64(aNonceWordD, 31U);
            aOrbiterH = ((aWandererG + RotL64(aScatter, 47U)) + 15673836275828498050U) + RotL64(aNonceWordG, 17U);
            aOrbiterE = (aWandererA + RotL64(aCross, 58U)) + 16600540024145812236U;
            aOrbiterF = (((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 37U)) + 9428052101528111892U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12763657928312763377U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 10751286982008662485U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6169084301655877217U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 1708230173038057979U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 4011389705422783816U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11692237130784795961U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 11704428328093077714U) + RotL64(aNonceWordF, 44U);
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2055336619674699284U;
            aOrbiterE = RotL64((aOrbiterE * 6374289210096410907U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1870865272102705804U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 3574214263751923179U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13132083406834413563U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 984611970726966186U) + RotL64(aNonceWordB, 5U);
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15207945449947643672U;
            aOrbiterF = RotL64((aOrbiterF * 9539470161576639981U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 57U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterH, 5U)) + RotL64(aNonceWordC, 45U)) + aPhaseBWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterG, 29U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 4U) + aOrbiterH) + RotL64(aOrbiterD, 38U)) + RotL64(aNonceWordE, 47U)) + aPhaseBWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 37U) ^ RotL64(aNonceWordC, 48U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 25297U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24513U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 5U) ^ RotL64(aNonceWordG, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26549U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneA[((aIndex + 24595U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCross, 60U)) ^ (RotL64(aCarry, 47U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 43U)) + 14214886793361825363U) + aPhaseBOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordG, 59U);
            aOrbiterF = (((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 17267959031078766320U) + RotL64(aNonceWordF, 7U);
            aOrbiterI = (aWandererG + RotL64(aCross, 21U)) + 16436067429484887644U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 9885951769332633820U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 48U)) + 12971711341813893304U) + aPhaseBOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 199970353398450154U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 1237341696444162094U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2850125642665515751U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 7991128854417613360U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 14809029847149045833U) ^ RotL64(aNonceWordA, 61U);
            aOrbiterC = RotL64((aOrbiterC * 5940857360838299105U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2559509556915775947U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 14336829730147834160U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15103242520064900873U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 8853631886733610440U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13346159398673246914U;
            aOrbiterF = RotL64((aOrbiterF * 13660497151446983393U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 12121095718571872976U) + RotL64(aNonceWordE, 53U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 16239781125815589804U;
            aOrbiterJ = RotL64((aOrbiterJ * 5157009090454962231U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 14U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterF, 43U)) + RotL64(aNonceWordH, 42U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 46U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + aPhaseBWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + (((((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 54U)) + aOrbiterF) + RotL64(aCarry, 43U)) + RotL64(aNonceWordB, 31U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterI, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 44U) ^ RotL64(aNonceWordH, 29U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31041U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 31194U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 36U) ^ RotL64(aNonceWordF, 23U)) ^ RotL64(aNonceWordA, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29788U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30915U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = ((aWandererA + RotL64(aIngress, 11U)) + 11450949896247900941U) + RotL64(aNonceWordC, 31U);
            aOrbiterH = (((aWandererB + RotL64(aScatter, 57U)) + 3905542253538116335U) + aPhaseBOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1]) + RotL64(aNonceWordF, 43U);
            aOrbiterD = (((aWandererK + RotL64(aCross, 48U)) + RotL64(aCarry, 51U)) + 9529740545977785305U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 1856876631533143492U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 84253466320181686U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12577480918745432444U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 5625703170397704029U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13583960724598036659U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 694608607323629282U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3993981243536262204U;
            aOrbiterH = RotL64((aOrbiterH * 2502835860198146381U), 43U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 4119215953484892051U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1]) + RotL64(aNonceWordB, 9U);
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8785040118556157146U;
            aOrbiterA = RotL64((aOrbiterA * 17113521266125471625U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16234403619456882890U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 10398727475672860610U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5086871400049644715U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 18327987141759096769U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2645964788056875452U) ^ RotL64(aNonceWordE, 53U);
            aOrbiterE = RotL64((aOrbiterE * 8778681366114628045U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 39U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 28U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 47U) + RotL64(aOrbiterE, 5U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 14U) + RotL64(aOrbiterA, 57U)) + aOrbiterE) + RotL64(aNonceWordG, 6U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 13U)) + aOrbiterI) + RotL64(aNonceWordD, 61U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 28U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 43U)) + aOrbiterA) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 30U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Golf_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE4FD4C195EFCA439ULL + 0xFC68546A8527689DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFE8973B0C90B7A53ULL + 0xADF666887F13FB4AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBB95678452438215ULL + 0xB7ADD7C40EED0755ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB728708761E15D17ULL + 0xA2D154CC1D34C003ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA1EBFF58C471513DULL + 0xEA860D68C1FFD627ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD3990A7EE52CE40FULL + 0xCE0427B4478C04EBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE6378319302202E9ULL + 0xC0A8D41EE45F1943ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE14B0AE30D2CC99DULL + 0xAFD4AA52475968CAULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 11U) ^ RotL64(aNonceWordH, 60U)) ^ RotL64(aNonceWordC, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3396U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 807U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordF, 37U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1551U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3329U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 42U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterC = ((aWandererE + RotL64(aIngress, 58U)) + RotL64(aCarry, 43U)) + 12632404972795375757U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 21U)) + 5351879979055988456U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 19U)) + 3597737727467443413U) + aPhaseCOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 47U)) + 2830846754917852318U;
            aOrbiterE = (aWandererI + RotL64(aCross, 5U)) + 17311925960294518018U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 52U)) + RotL64(aCarry, 51U)) + 2083584640523695383U;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 35U)) + 15049343611387010158U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) + RotL64(aNonceWordA, 17U);
            aOrbiterJ = (aWandererC + RotL64(aIngress, 11U)) + 6443050378205811147U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 29U)) + 6021965178697344070U) + RotL64(aNonceWordE, 55U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 5080289878758029976U) + RotL64(aNonceWordD, 12U);
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 576927745306972983U;
            aOrbiterF = RotL64((aOrbiterF * 16008958833683246115U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4728489691382690859U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6184355840165758855U;
            aOrbiterA = RotL64((aOrbiterA * 1515043910404156423U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11220539885798595450U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 11091438724966718214U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8225347114759391961U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 17184210490020062419U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 2150997767099116408U) ^ RotL64(aNonceWordC, 37U);
            aOrbiterD = RotL64((aOrbiterD * 8058553821648892499U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 7021953562676903717U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17159676348343312834U;
            aOrbiterC = RotL64((aOrbiterC * 13877284519668483549U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 10367891770525239784U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11922478487264201233U;
            aOrbiterB = RotL64((aOrbiterB * 9195137452661956029U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17815162358981720634U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9582631251085100284U;
            aOrbiterK = RotL64((aOrbiterK * 11838992994130850483U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 872593750259572264U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17832330100262167302U;
            aOrbiterI = RotL64((aOrbiterI * 1114416841510028467U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16601139856969287418U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14931287111691324985U;
            aOrbiterE = RotL64((aOrbiterE * 16757174577841001179U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 40U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterK, 13U)) + RotL64(aNonceWordB, 31U)) + aPhaseCWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 52U) + aOrbiterE) + RotL64(aOrbiterJ, 39U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterA, 48U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 43U)) + aOrbiterD) + RotL64(aNonceWordG, 15U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 29U)) + aOrbiterJ);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterD, 53U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 35U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 56U) + aOrbiterC) + RotL64(aOrbiterF, 57U));
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 18U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 46U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 21U) ^ RotL64(aNonceWordG, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15493U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14703U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 5U) ^ RotL64(aNonceWordE, 47U)) ^ RotL64(aNonceWordF, 24U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11336U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10576U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 29U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterK = (((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 57U)) + 7270044678408187242U) + RotL64(aNonceWordD, 59U);
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 51U)) + 10192278965379756766U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 13U)) + 17568666746676060748U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 46U)) + RotL64(aCarry, 3U)) + 14312927531124963037U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 21U)) + 9825825726152087706U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 5U)) + 9696778570255265896U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aPrevious, 27U)) + 17657841352013417228U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 16207815085909628439U;
            aOrbiterF = (((aWandererG + RotL64(aCross, 58U)) + 1752979206374514227U) + aPhaseCOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordF, 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 10456310689643905854U) + RotL64(aNonceWordG, 41U);
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16127830548663742550U;
            aOrbiterH = RotL64((aOrbiterH * 4355938404839045417U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 2940917376003930842U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 7353596864777649953U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7499468723171042005U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12725092740446150705U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 5791296650856037010U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 760379251950502133U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1200130368046206150U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16689604428598558547U;
            aOrbiterG = RotL64((aOrbiterG * 13815324235939996623U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14359561591103730856U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3975025843599045263U;
            aOrbiterF = RotL64((aOrbiterF * 5025047888533298617U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14017901732955607601U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10431526786489555196U) ^ RotL64(aNonceWordB, 10U);
            aOrbiterK = RotL64((aOrbiterK * 10181915874476132407U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7320527073559849223U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15333411223710709907U;
            aOrbiterC = RotL64((aOrbiterC * 3488684905528068775U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 14302474063321663801U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2104154521019935187U;
            aOrbiterE = RotL64((aOrbiterE * 12944382959742278055U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5167600586916325228U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4566823109447208716U;
            aOrbiterJ = RotL64((aOrbiterJ * 9997799807454267443U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 30U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 10U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 20U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aCross, 12U) + RotL64(aOrbiterK, 39U)) + aOrbiterA) + aPhaseCWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 43U));
            aWandererE = aWandererE + (((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 13U)) + aOrbiterF) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 20U) + aOrbiterK) + RotL64(aOrbiterE, 35U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterG, 4U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordH, 53U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterA, 29U)) + RotL64(aNonceWordA, 27U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 50U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordG, 53U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23266U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 21553U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordB, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 23793U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneC[((aIndex + 19667U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 51U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterF = (aWandererH + RotL64(aScatter, 57U)) + 5088525177670191619U;
            aOrbiterG = (aWandererE + RotL64(aCross, 34U)) + 9966456257813932112U;
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 7707646574027146307U) + aPhaseCOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aIngress, 47U)) + 75480203757681173U;
            aOrbiterD = (aWandererF + RotL64(aCross, 29U)) + 384659134071835163U;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 52U)) + RotL64(aCarry, 21U)) + 3158769775373307778U) + RotL64(aNonceWordD, 43U);
            aOrbiterE = ((aWandererG + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 17360830943513941272U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 43U)) + 5317278822721604586U;
            aOrbiterB = (((aWandererD + RotL64(aIngress, 19U)) + 1371427105215954781U) + aPhaseCOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1]) + RotL64(aNonceWordA, 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3162710551223553423U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5332921933853550756U;
            aOrbiterK = RotL64((aOrbiterK * 11709546145149357887U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10572462410297815854U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10234389605554817892U;
            aOrbiterF = RotL64((aOrbiterF * 2130374833440291193U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13421365517991380605U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10186643614984034083U;
            aOrbiterH = RotL64((aOrbiterH * 8554471709467808453U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4742438973260817120U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6081590345899008846U;
            aOrbiterG = RotL64((aOrbiterG * 7069396301823124931U), 39U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 15360092808493795340U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1]) + RotL64(aNonceWordC, 24U);
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12186413069553132646U;
            aOrbiterD = RotL64((aOrbiterD * 3815981440611914267U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16756221656224451552U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 12232880965861373143U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14196910735715726471U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10090954323470840557U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15615770271463853537U;
            aOrbiterE = RotL64((aOrbiterE * 13544181592829027283U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 556029032505658411U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 13311879111583579039U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3924744868168749003U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 8646360871497847336U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 2064833941982069154U) ^ RotL64(aNonceWordH, 47U);
            aOrbiterB = RotL64((aOrbiterB * 10016546852137913163U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 20U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterK, 19U)) + RotL64(aNonceWordE, 55U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + RotL64(aNonceWordF, 5U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterI, 4U));
            aWandererD = aWandererD + ((RotL64(aIngress, 6U) + RotL64(aOrbiterH, 51U)) + aOrbiterD);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterK, 35U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 11U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterK, 46U));
            aWandererF = aWandererF + (((RotL64(aIngress, 30U) + aOrbiterB) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 36U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordH, 20U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29275U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26039U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 39U) ^ RotL64(aNonceWordC, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27343U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31268U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 60U) + RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 27U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterC = (aWandererG + RotL64(aPrevious, 58U)) + 13687218104610230596U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 23U)) + 6841550124960692709U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 29U)) + 17418968668458764131U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 39U)) + 8303537912696948204U;
            aOrbiterI = (((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 12376614417285936537U) + RotL64(aNonceWordE, 15U);
            aOrbiterE = ((aWandererH + RotL64(aScatter, 10U)) + 14215749063579232654U) + aPhaseCOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 3U)) + 4111736931433665347U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 11250375934571631522U) + RotL64(aNonceWordH, 19U);
            aOrbiterH = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 5367367837773331275U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15514089192382674434U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 1475991716685034960U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17720681295551650891U), 37U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterA) + 5531622777788629748U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordG, 11U);
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8363822215908303335U;
            aOrbiterI = RotL64((aOrbiterI * 17850203366840994883U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 3741256932685720414U) + RotL64(aNonceWordF, 39U);
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11634667238062155772U;
            aOrbiterD = RotL64((aOrbiterD * 15925089729784547403U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 18180546911210417155U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5123234656838556335U;
            aOrbiterC = RotL64((aOrbiterC * 15362857462853398025U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11215734271189250284U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16863747802158398092U;
            aOrbiterJ = RotL64((aOrbiterJ * 1828035970246160023U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9859050606636646323U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9331300036643654675U;
            aOrbiterE = RotL64((aOrbiterE * 2502263410556166281U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15028845665427209759U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8916444839488901676U;
            aOrbiterB = RotL64((aOrbiterB * 6646561894156038791U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8024631140949068570U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1116378858490660031U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4247798531910227367U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 5066486214537899212U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9346312092322423057U;
            aOrbiterF = RotL64((aOrbiterF * 13443190089768875191U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterH, 13U));
            aWandererI = aWandererI + ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterD, 58U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterA, 39U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 19U)) + aOrbiterH);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterE, 23U)) + RotL64(aNonceWordB, 54U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 57U)) + aPhaseCWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 4U) + RotL64(aOrbiterJ, 29U)) + aOrbiterI) + aPhaseCWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 35U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 4U)) + aOrbiterB) + RotL64(aNonceWordD, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 36U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Golf_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF51484E0C3EA6DF3ULL + 0xB0F19A89EB144067ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD0A134D17B60C511ULL + 0xDB96F418F6BCB078ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8003F6F3818B2855ULL + 0xDE9CB8ADD3802C59ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8FB43C1093F63CF1ULL + 0xDAEC874650E45E77ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xBA6EFB808F49F649ULL + 0xF623B83CAD107B7CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA60AB34181764867ULL + 0xA08D7BF42DB5FBFAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFADEC6FE7B0FA085ULL + 0xDB25AB8818C3649AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8FA9A8ADE8AA7E3DULL + 0xEB1A0AA10A0E2860ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 38U) ^ RotL64(aNonceWordD, 13U)) ^ RotL64(aNonceWordE, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5250U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1166U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 38U) ^ RotL64(aNonceWordG, 5U)) ^ RotL64(aNonceWordA, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3754U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 546U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = (aWandererH + RotL64(aPrevious, 19U)) + 15813325389431304548U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 21U)) + 2223874171125403602U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 5510483568496824130U) + RotL64(aNonceWordG, 35U);
            aOrbiterE = (((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 13U)) + 15474152493495661876U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aCross, 6U)) + 16846339705130829195U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 37U)) + 1289670576865739669U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 51U)) + 18017354919647006944U) + aPhaseDOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aIngress, 53U)) + 8539685539928984921U;
            aOrbiterF = (aWandererA + RotL64(aCross, 10U)) + 3333721400836704048U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 2261560416623815491U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 23U)) + 4377786131746816567U) + RotL64(aNonceWordH, 22U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 18047393176583722719U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 8184724021940434631U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9800116157750921119U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 10469895939183324807U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14543391765109879223U;
            aOrbiterI = RotL64((aOrbiterI * 4817987697437667225U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5757225781746158178U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3539000495894022869U) ^ RotL64(aNonceWordE, 59U);
            aOrbiterG = RotL64((aOrbiterG * 1032298408884695925U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11288971092707065923U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2761384065186568294U;
            aOrbiterE = RotL64((aOrbiterE * 3323838837427471051U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7120580145300417101U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6977246291769372866U;
            aOrbiterA = RotL64((aOrbiterA * 15170353875184253779U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17625434527765525937U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3299714663631376190U;
            aOrbiterF = RotL64((aOrbiterF * 6532628892760776767U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10331889953489885250U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8550932256881727932U;
            aOrbiterC = RotL64((aOrbiterC * 13085531621192583719U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11151195711186126257U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 2552002192824926483U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9754056316698523849U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 8038115194286715268U) + RotL64(aNonceWordF, 5U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16594489591573505305U;
            aOrbiterJ = RotL64((aOrbiterJ * 1241387574663818247U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13476964484361081681U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2136330439951908303U;
            aOrbiterH = RotL64((aOrbiterH * 12728359054660550527U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 231990686776499700U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 15813325389431304548U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9155088985405261637U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 34U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterA, 30U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterK, 27U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 41U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 30U) + RotL64(aOrbiterC, 51U)) + aOrbiterE) + RotL64(aNonceWordB, 19U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterC, 5U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterB, 36U)) + RotL64(aNonceWordC, 7U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aScatter, 14U) + aOrbiterK) + RotL64(aOrbiterJ, 11U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 19U)) + aOrbiterA) + aPhaseDWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 20U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 47U) ^ RotL64(aNonceWordD, 10U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6990U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9307U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordF, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6925U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5739U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 14U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = (aWandererK + RotL64(aPrevious, 53U)) + 6521330037475130256U;
            aOrbiterH = (aWandererB + RotL64(aCross, 42U)) + 12611880456055428940U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 39U)) + 12061611078130934708U) + aPhaseDOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 11U)) + 1558112410801116984U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 37U)) + 10509115227850160786U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 5U)) + 4045915960688792066U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 44U)) + RotL64(aCarry, 37U)) + 1196541286513243082U) + RotL64(aNonceWordG, 42U);
            aOrbiterA = (((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 15564991032722373702U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aIngress, 57U)) + 4897765238703641798U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 51U)) + 12327429514907752733U) + RotL64(aNonceWordC, 37U);
            aOrbiterG = (aWandererJ + RotL64(aScatter, 21U)) + 6189189797708711636U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6374267075282018852U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1888758503831341439U;
            aOrbiterI = RotL64((aOrbiterI * 74387714918264257U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14956857689299491800U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14879361107223331957U;
            aOrbiterH = RotL64((aOrbiterH * 9166712966729591953U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 16086885494838105042U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 8069724185844303923U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8878470736758734353U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 10854345917959911439U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7078313614360332089U;
            aOrbiterJ = RotL64((aOrbiterJ * 9864025732292844871U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15083669236062255011U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 594879695916679116U;
            aOrbiterE = RotL64((aOrbiterE * 9852515479152735283U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6721466068234534523U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 475816724162626782U;
            aOrbiterD = RotL64((aOrbiterD * 4799725182757588407U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4341655358154605899U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15477254302340298586U;
            aOrbiterC = RotL64((aOrbiterC * 13961520225881974201U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 10179091913200895775U) + RotL64(aNonceWordA, 55U);
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6310490897546909571U;
            aOrbiterF = RotL64((aOrbiterF * 15080621088825477613U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 13462682513035460711U) + RotL64(aNonceWordH, 21U);
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16739138858084100385U;
            aOrbiterA = RotL64((aOrbiterA * 16386371811268298031U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13608837667062268989U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12902415667552110103U;
            aOrbiterB = RotL64((aOrbiterB * 16398790854093048017U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16596211634603915761U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 6521330037475130256U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 631958426544321145U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 39U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 36U));
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterG, 53U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterF, 56U)) + aOrbiterB) + aPhaseDWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterA, 21U)) + aPhaseDWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterB, 51U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 23U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 37U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 27U)) + RotL64(aNonceWordD, 47U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterA, 39U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterJ, 42U)) + RotL64(aNonceWordF, 9U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 48U) + RotL64(aOrbiterE, 13U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordB, 27U)) ^ RotL64(aNonceWordG, 53U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 15238U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 12173U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 12U) ^ RotL64(aNonceWordF, 3U)) ^ RotL64(aNonceWordA, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11089U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13256U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 36U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (aWandererA + RotL64(aCross, 51U)) + 13442819395490639310U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 29U)) + 8187292523194120936U;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 26U)) + 11469697159823131388U) + aPhaseDOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordH, 19U);
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 53U)) + 13414083692375929653U) + RotL64(aNonceWordC, 11U);
            aOrbiterA = (aWandererE + RotL64(aCross, 39U)) + 11404010733687907517U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 6783212827186218247U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 8561131439340372614U;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 6252609642004429113U) + aPhaseDOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aCross, 41U)) + 12804867444200448952U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 13U)) + 2739648749603690781U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 22U)) + 14808861217017399752U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 17588866502571268888U) + RotL64(aNonceWordB, 57U);
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5882260142735642980U;
            aOrbiterE = RotL64((aOrbiterE * 7688252946143263869U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 15493099088132862949U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5175647411532429582U;
            aOrbiterD = RotL64((aOrbiterD * 15226544495598541883U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14279707376173642767U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6826363572161275158U;
            aOrbiterK = RotL64((aOrbiterK * 5263708315440161809U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 13267185753040999992U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9980987858092888720U;
            aOrbiterA = RotL64((aOrbiterA * 13210290848800728635U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 3582972937645514549U) + RotL64(aNonceWordG, 49U);
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10140409019562890804U;
            aOrbiterB = RotL64((aOrbiterB * 6944490201647678479U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6160444117287330557U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16344602960561293113U;
            aOrbiterJ = RotL64((aOrbiterJ * 2319964919335633293U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 3497141036108337171U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 91269118352540308U;
            aOrbiterC = RotL64((aOrbiterC * 5160060720189045505U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12739932748793144857U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12820180915064791197U;
            aOrbiterH = RotL64((aOrbiterH * 5843849637411948699U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17572075652083359962U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10684041099654982701U;
            aOrbiterF = RotL64((aOrbiterF * 7121293375756263771U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10739534650885677354U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9731206787727954809U;
            aOrbiterG = RotL64((aOrbiterG * 3730875775588585547U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9655432616347117764U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13442819395490639310U;
            aOrbiterI = RotL64((aOrbiterI * 3650859301708619119U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 58U));
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 50U) + aOrbiterK) + RotL64(aOrbiterD, 39U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 10U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 53U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 41U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aScatter, 54U) + aOrbiterA) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterA, 21U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 30U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterK, 5U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 37U)) + aOrbiterA) + RotL64(aNonceWordD, 60U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterH, 19U)) + RotL64(aNonceWordF, 23U)) + aPhaseDWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 18U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 44U) ^ RotL64(aNonceWordC, 21U)) ^ RotL64(aNonceWordG, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 20810U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 18323U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordF, 56U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19928U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20609U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 11U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 36U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterJ = (aWandererC + RotL64(aCross, 5U)) + 11698283336767769359U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 11U)) + 13297826354831483872U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 39U)) + 15254999058287530795U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aIngress, 30U)) + 17474166585085346567U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 3U)) + 15684783498452840289U;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 41U)) + 5061229733465216486U) + RotL64(aNonceWordE, 7U);
            aOrbiterH = (((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 15370981279168377944U) + RotL64(aNonceWordB, 5U);
            aOrbiterE = ((aWandererI + RotL64(aIngress, 14U)) + RotL64(aCarry, 11U)) + 17966672773619554092U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 37U)) + 14685092893994491068U) + aPhaseDOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aPrevious, 43U)) + 12798804186209406389U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 47U)) + 2848444181474221574U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8551142075919636146U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8833198159158950723U;
            aOrbiterK = RotL64((aOrbiterK * 7650289040764974737U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7351473160893666232U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14204899612487622222U;
            aOrbiterF = RotL64((aOrbiterF * 6317485031956448029U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7008985178526543258U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13576796403863120356U;
            aOrbiterC = RotL64((aOrbiterC * 13745839827679114077U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5769784656937900699U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14075925808204936705U;
            aOrbiterH = RotL64((aOrbiterH * 5844894088757604713U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 17818667502858010896U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 16016922065572683130U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1]) ^ RotL64(aNonceWordA, 25U);
            aOrbiterE = RotL64((aOrbiterE * 7525645833898085373U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1582458237855075977U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10830440354527138227U;
            aOrbiterB = RotL64((aOrbiterB * 10499386926982228251U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 10653964151654643772U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 11218475491129483859U) ^ RotL64(aNonceWordF, 41U);
            aOrbiterD = RotL64((aOrbiterD * 3338108067044357141U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9863649760189649255U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13790281439048354358U;
            aOrbiterG = RotL64((aOrbiterG * 4682098083538482849U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14846954923718136337U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 522207783972623813U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14299798934454852811U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 426829715716262697U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7482977730216354509U;
            aOrbiterA = RotL64((aOrbiterA * 6317437989422015173U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10736099808538972990U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11698283336767769359U;
            aOrbiterI = RotL64((aOrbiterI * 17230175904095995929U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 56U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterE, 14U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterA, 48U));
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 13U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterJ, 39U));
            aWandererE = aWandererE + ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 27U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterG, 57U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 54U) + RotL64(aOrbiterI, 30U)) + aOrbiterK) + RotL64(aNonceWordC, 13U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterF, 35U));
            aWandererA = aWandererA + ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterD, 43U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterH, 11U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 18U) + RotL64(aOrbiterF, 5U)) + aOrbiterE) + RotL64(aNonceWordH, 14U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 38U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererE, 12U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 19U) ^ RotL64(aNonceWordE, 11U)) ^ RotL64(aNonceWordF, 56U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24728U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25132U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordB, 28U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23986U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 22399U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 44U) + RotL64(aIngress, 11U)) + (RotL64(aCross, 27U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = (aWandererC + RotL64(aCross, 26U)) + 5568146815535263910U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 37U)) + 7736084960873834666U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 1336413621817562093U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 29U)) + 5218462026934984692U) + aPhaseDOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aCross, 39U)) + 7048890985969555935U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 41U)) + 13415955213864702118U) + RotL64(aNonceWordE, 58U);
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 5657023257021528548U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 53U)) + 14338310943137497116U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 39U)) + 12305161641833950473U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 11U)) + 14514226578370459131U;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 4U)) + 12692904083266024340U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + RotL64(aNonceWordD, 31U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 11012959130001327964U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7106471380403489078U;
            aOrbiterA = RotL64((aOrbiterA * 515626559384817223U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3718101961355280891U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13364192077222322664U;
            aOrbiterC = RotL64((aOrbiterC * 1411328915372590283U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6720867800318913440U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 14497243926965866546U) ^ RotL64(aNonceWordC, 29U);
            aOrbiterF = RotL64((aOrbiterF * 13595058589060114653U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5789056168233262435U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14438482587495779937U;
            aOrbiterB = RotL64((aOrbiterB * 10593535547917767263U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 313917798940179945U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 15241845511889502917U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16483477103771326107U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3591957424821693032U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1559050939014453558U;
            aOrbiterH = RotL64((aOrbiterH * 17933346117866604725U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15340590914441451383U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 5538037287390050110U) ^ RotL64(aNonceWordG, 5U);
            aOrbiterE = RotL64((aOrbiterE * 4082576643144951473U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4151270491894969214U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 263593701314144898U;
            aOrbiterK = RotL64((aOrbiterK * 10372046955804512457U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9025145270653080646U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6867950904094870056U;
            aOrbiterD = RotL64((aOrbiterD * 9975247022340627751U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3183454301841252109U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 3054904157641290615U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4092317552439599475U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1768555574434776135U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5568146815535263910U;
            aOrbiterI = RotL64((aOrbiterI * 12466957001078663927U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 23U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 10U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterA, 39U));
            aWandererH = aWandererH + ((((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordA, 27U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 5U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterA, 13U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 60U) + aOrbiterC) + RotL64(aOrbiterE, 11U));
            aWandererB = aWandererB + ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 44U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((((RotL64(aCross, 11U) + RotL64(aOrbiterH, 51U)) + aOrbiterE) + RotL64(aNonceWordB, 21U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 21U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterE, 29U));
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 6U) + RotL64(aOrbiterB, 23U)) + aOrbiterK) + aPhaseDWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 46U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 24U) ^ RotL64(aNonceWordH, 35U)) ^ RotL64(aNonceWordB, 51U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27740U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 30621U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordC, 35U)) ^ RotL64(aNonceWordA, 24U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31655U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28560U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 37U)) + 6024062041314952357U) + RotL64(aNonceWordD, 16U);
            aOrbiterK = (((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 18340757093658015585U) + aPhaseDOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 11911120493880346751U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 11U)) + 17428074353884654439U) + RotL64(aNonceWordH, 45U);
            aOrbiterJ = (aWandererH + RotL64(aScatter, 35U)) + 12790849760814795936U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 60U)) + 12633397052172117800U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aPrevious, 21U)) + 11946150433665237945U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 3U)) + 16842157900909419285U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 5U)) + 14186235783224155962U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 51U)) + 13284904542579767591U;
            aOrbiterB = (aWandererD + RotL64(aCross, 18U)) + 11609181965078844357U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9628562297095374984U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7850281529011259759U;
            aOrbiterE = RotL64((aOrbiterE * 17611485102925470357U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 257458718073794527U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 10693404545773519306U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14821443722828498323U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3430519236533871460U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6183054506953198055U;
            aOrbiterD = RotL64((aOrbiterD * 6121082743789970911U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2905610989884221654U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 4472163910775333862U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7770678426310856745U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16870142883133769663U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1403692060594816451U;
            aOrbiterF = RotL64((aOrbiterF * 9740854430251597879U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16904169913507057108U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4773518591580333357U;
            aOrbiterA = RotL64((aOrbiterA * 5306070307776061267U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6528141733853494275U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 11254806909313951442U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6316669786405548827U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 6857506858448143407U) + RotL64(aNonceWordC, 55U);
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2855763534355983644U;
            aOrbiterB = RotL64((aOrbiterB * 16881334940165182415U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12328391751024624740U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16475072086109949522U;
            aOrbiterC = RotL64((aOrbiterC * 15218626930666825883U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15505670341076785424U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6972128419331939330U;
            aOrbiterK = RotL64((aOrbiterK * 12206069109180246067U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7151546362283646210U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 6024062041314952357U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1]) ^ RotL64(aNonceWordE, 53U);
            aOrbiterG = RotL64((aOrbiterG * 10243806128059850493U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 26U));
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ);
            aWandererA = aWandererA + ((((RotL64(aScatter, 14U) + aOrbiterA) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 39U)) + RotL64(aNonceWordF, 61U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 3U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 37U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 50U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 19U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterF, 21U)) + aOrbiterE) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterG, 53U)) + RotL64(aNonceWordB, 11U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 56U) + RotL64(aOrbiterK, 43U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterD, 28U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 24U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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

void TwistExpander_Golf_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE9A795F6C58D42AFULL + 0xC1982AB061B042F2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xAA2B8807935B2ED3ULL + 0x899E3DC4D66AB15CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA88318CEA9410B1DULL + 0xCB1FF321747BB393ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9EC020ADCD953C2BULL + 0xAEA9524530B09C35ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x93A89185F090D531ULL + 0xB96E53264E1ABDFDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xEED2B3CD6E59B477ULL + 0xFB7DA0D9A9BD199DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBC98A150A8614BEDULL + 0x9A7B99B0F6A2D0B1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x908B3DD5CA76E4EDULL + 0xAA67CA4C58C94CEFULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 5U) ^ RotL64(aNonceWordD, 19U)) ^ RotL64(aNonceWordH, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3255U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneC[((aIndex + 2692U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 29U) ^ RotL64(aNonceWordF, 12U)) ^ RotL64(aNonceWordG, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 691U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 216U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 10U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = ((aWandererE + RotL64(aCross, 23U)) + 3970829908171131502U) + RotL64(aNonceWordF, 27U);
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 57U)) + 7040283759419531991U) + aPhaseEOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aIngress, 5U)) + 11856292169397052901U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 23U)) + 819598588791819022U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 10U)) + 2176451710970866848U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 35U)) + 6454704928613390494U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 29U)) + 11792122387218053841U) + aPhaseEOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aCross, 51U)) + 9254780213489752211U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 16591812589999846482U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 46U)) + 1471246223935074832U) + RotL64(aNonceWordD, 59U);
            aOrbiterB = (aWandererD + RotL64(aPrevious, 19U)) + 1424843083106386453U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1856469958050891629U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6331743690452052712U;
            aOrbiterJ = RotL64((aOrbiterJ * 15327924647897459645U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10351075711345476487U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 9518585245330480185U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3792179827396760391U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17787514620244712033U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14182328067398162557U;
            aOrbiterH = RotL64((aOrbiterH * 18107337388659070197U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12798088948801072444U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9563215159275202323U;
            aOrbiterK = RotL64((aOrbiterK * 7058145016617349141U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9904919772580498232U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16579777394992143043U;
            aOrbiterF = RotL64((aOrbiterF * 10516761340320196661U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 6344049286854588503U) + RotL64(aNonceWordG, 41U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 3531503618941046788U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10855385899703024105U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11334308840132700377U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11093833870078787770U;
            aOrbiterB = RotL64((aOrbiterB * 16105889714648555755U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 3831491136025364271U) + RotL64(aNonceWordA, 20U);
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12505259454860591372U;
            aOrbiterG = RotL64((aOrbiterG * 6135450888433504093U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2210290810330253363U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10786160915224323113U;
            aOrbiterD = RotL64((aOrbiterD * 799075068398619501U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 7791474921127653867U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1046454625851499863U;
            aOrbiterC = RotL64((aOrbiterC * 18040454167287729591U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 14636813124839719351U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3970829908171131502U;
            aOrbiterI = RotL64((aOrbiterI * 2737568880005765517U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 53U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 14U));
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 60U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterA, 53U)) + RotL64(aNonceWordB, 31U));
            aWandererE = aWandererE + ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterB, 39U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterF, 35U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterK, 13U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterI, 37U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 28U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 56U) + RotL64(aOrbiterE, 43U)) + aOrbiterD) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 3U)) + RotL64(aNonceWordE, 29U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterG, 21U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 50U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 52U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 37U) ^ RotL64(aNonceWordF, 53U)) ^ RotL64(aNonceWordD, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8153U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneD[((aIndex + 9996U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 38U) ^ RotL64(aNonceWordG, 53U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9080U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8697U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = (aWandererE + RotL64(aIngress, 29U)) + 2330952702412094686U;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 7820188225935060799U) + RotL64(aNonceWordB, 53U);
            aOrbiterB = (aWandererF + RotL64(aCross, 22U)) + 9347644591709839145U;
            aOrbiterA = ((((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 37U)) + 2288624878446846870U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) + RotL64(aNonceWordG, 57U);
            aOrbiterK = (aWandererD + RotL64(aScatter, 19U)) + 9358977729492824128U;
            aOrbiterF = (aWandererI + RotL64(aCross, 37U)) + 1858511275052455039U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 5U)) + 13715478509322292552U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aIngress, 14U)) + 16413396625604260455U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 35U)) + 17714322215518432705U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 19U)) + 16188315436202861122U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 27U)) + 5564445841368207813U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 13717068949900594673U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14143659432287313765U;
            aOrbiterB = RotL64((aOrbiterB * 17281441046722262917U), 43U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterK) + 5729546141908425670U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1]) + RotL64(aNonceWordC, 7U);
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4297827922736712074U;
            aOrbiterH = RotL64((aOrbiterH * 13631630436759768885U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 829520109395163673U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11547160328525174295U;
            aOrbiterK = RotL64((aOrbiterK * 4759690159673049775U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2907177944512117206U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11100346409065275671U;
            aOrbiterJ = RotL64((aOrbiterJ * 17927994356809011637U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 1344592529249949068U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6470438516791143572U;
            aOrbiterC = RotL64((aOrbiterC * 13339390828725370475U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5217751823741520847U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 5371275223586938039U) ^ RotL64(aNonceWordF, 11U);
            aOrbiterE = RotL64((aOrbiterE * 12318403075523724125U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14218103150268532919U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1367628876596800571U;
            aOrbiterA = RotL64((aOrbiterA * 13777531272321533137U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2372041991018455610U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 9870744274890595581U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12093443117747395585U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15531376915156611594U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 11166549148968363252U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10024372567841218915U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8555942275137258839U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3304132937209624841U;
            aOrbiterG = RotL64((aOrbiterG * 7965093976633155809U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14825330575158830172U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2330952702412094686U;
            aOrbiterI = RotL64((aOrbiterI * 9146641978165131495U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 39U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 36U) + RotL64(aOrbiterC, 29U)) + aOrbiterJ) + RotL64(aCarry, 41U)) + RotL64(aNonceWordE, 8U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterH, 60U));
            aWandererE = aWandererE + ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 35U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterK, 51U));
            aWandererA = aWandererA + ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 37U)) + aOrbiterA);
            aWandererI = aWandererI ^ (((RotL64(aCross, 34U) + aOrbiterH) + RotL64(aOrbiterC, 21U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 56U)) + aOrbiterH) + aPhaseEWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterJ, 5U));
            aWandererB = aWandererB + ((((RotL64(aCross, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterD) + RotL64(aCarry, 53U)) + RotL64(aNonceWordA, 51U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterK, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 35U) ^ RotL64(aNonceWordF, 51U)) ^ RotL64(aNonceWordE, 27U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15758U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13681U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 43U) ^ RotL64(aNonceWordA, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12319U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13917U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 4U) ^ RotL64(aCross, 29U)) ^ (RotL64(aCarry, 41U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = (aWandererD + RotL64(aIngress, 39U)) + 5568146815535263910U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 7736084960873834666U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 35U)) + 1336413621817562093U) + RotL64(aNonceWordB, 3U);
            aOrbiterI = (aWandererI + RotL64(aCross, 41U)) + 5218462026934984692U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 14U)) + 7048890985969555935U;
            aOrbiterA = (aWandererH + RotL64(aCross, 37U)) + 13415955213864702118U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 3U)) + 5657023257021528548U) + aPhaseEOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordC, 9U);
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 5U)) + 14338310943137497116U) + aPhaseEOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aPrevious, 11U)) + 12305161641833950473U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 26U)) + RotL64(aCarry, 47U)) + 14514226578370459131U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 29U)) + 12692904083266024340U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11012959130001327964U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7106471380403489078U;
            aOrbiterK = RotL64((aOrbiterK * 515626559384817223U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 3718101961355280891U) + RotL64(aNonceWordF, 30U);
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13364192077222322664U;
            aOrbiterA = RotL64((aOrbiterA * 1411328915372590283U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 6720867800318913440U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14497243926965866546U;
            aOrbiterE = RotL64((aOrbiterE * 13595058589060114653U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5789056168233262435U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14438482587495779937U;
            aOrbiterB = RotL64((aOrbiterB * 10593535547917767263U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 313917798940179945U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15241845511889502917U;
            aOrbiterC = RotL64((aOrbiterC * 16483477103771326107U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3591957424821693032U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1559050939014453558U;
            aOrbiterG = RotL64((aOrbiterG * 17933346117866604725U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 15340590914441451383U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5538037287390050110U;
            aOrbiterJ = RotL64((aOrbiterJ * 4082576643144951473U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4151270491894969214U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 263593701314144898U;
            aOrbiterI = RotL64((aOrbiterI * 10372046955804512457U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9025145270653080646U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 6867950904094870056U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9975247022340627751U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3183454301841252109U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 3054904157641290615U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4092317552439599475U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1768555574434776135U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 5568146815535263910U) ^ RotL64(aNonceWordD, 17U);
            aOrbiterH = RotL64((aOrbiterH * 12466957001078663927U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 48U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + RotL64(aOrbiterA, 60U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 42U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 11U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 13U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 39U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterC, 57U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 50U) + RotL64(aOrbiterE, 26U)) + aOrbiterH) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterD, 37U)) + aOrbiterF) + RotL64(aNonceWordH, 11U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 5U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterI, 3U));
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterE, 21U)) + RotL64(aNonceWordG, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 41U) ^ RotL64(aNonceWordC, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 21420U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 21807U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 13U) ^ RotL64(aNonceWordA, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16951U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((aIndex + 20734U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 52U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 3U)) + 439898681482066326U) + RotL64(aNonceWordD, 28U);
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 47U)) + 17362083676671776094U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 5U)) + 6418499837265155024U;
            aOrbiterE = (((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 17262244253027454972U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aScatter, 60U)) + 2382066162993139503U;
            aOrbiterA = (aWandererK + RotL64(aCross, 21U)) + 14345808395587174135U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 19U)) + 7534743166385552851U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 21U)) + 16994453324688523966U) + RotL64(aNonceWordE, 29U);
            aOrbiterB = (aWandererF + RotL64(aCross, 57U)) + 7079553728544045092U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 39U)) + 3562822704508440641U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 44U)) + RotL64(aCarry, 27U)) + 13990892681975857821U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1796728922368577238U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6605161260520067178U;
            aOrbiterF = RotL64((aOrbiterF * 8147537646591674091U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 13994083795942328918U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6144523182899107711U;
            aOrbiterK = RotL64((aOrbiterK * 4153879991344611283U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 12247462325297436642U) + RotL64(aNonceWordF, 25U);
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1065809332002012789U;
            aOrbiterA = RotL64((aOrbiterA * 5496601177032953251U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10147919864511540753U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 17138553441127273354U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5773875596275267871U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2653924016109573974U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6254416952351699582U;
            aOrbiterI = RotL64((aOrbiterI * 12756861659704947257U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 813046408080197079U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9624466135414123483U;
            aOrbiterB = RotL64((aOrbiterB * 6960320253124395015U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 972586705850825744U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 155283774901960223U;
            aOrbiterH = RotL64((aOrbiterH * 9928051687724257041U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 18200100644751360406U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1168426822045686004U;
            aOrbiterD = RotL64((aOrbiterD * 5867027156069481313U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 2271564377169233643U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 1896317305868283986U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) ^ RotL64(aNonceWordH, 15U);
            aOrbiterC = RotL64((aOrbiterC * 8080751157990019287U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10209708407397294552U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 947585551223387294U;
            aOrbiterJ = RotL64((aOrbiterJ * 15339472308062247067U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12313594490465462211U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 439898681482066326U;
            aOrbiterE = RotL64((aOrbiterE * 12336632799055203705U), 39U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 18U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterG, 11U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterA, 3U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterA, 21U)) + RotL64(aNonceWordB, 37U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterK, 19U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 41U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterD, 44U)) + aOrbiterJ);
            aWandererB = aWandererB + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 53U)) + aOrbiterD) + RotL64(aCarry, 35U)) + RotL64(aNonceWordA, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterH, 35U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 47U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 18U) + aOrbiterD) + RotL64(aOrbiterG, 37U)) + aPhaseEWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 58U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererH, 60U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 46U) ^ RotL64(aNonceWordF, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 25250U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21905U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 23U) ^ RotL64(aNonceWordH, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26998U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25884U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 21U)) + (RotL64(aPrevious, 37U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = ((aWandererE + RotL64(aCross, 51U)) + 8685374557928800912U) + aPhaseEOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aScatter, 11U)) + 3482312691892161229U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 60U)) + 6948130297389161165U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 57U)) + 5506385663788942690U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 39U)) + 17859982009307397161U;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 9178488809207094043U) + RotL64(aNonceWordC, 5U);
            aOrbiterG = (aWandererC + RotL64(aCross, 27U)) + 1835479501226057169U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 34U)) + 5368101733632614939U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 19U)) + 9050459666576835422U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 9042186993119635078U) + RotL64(aNonceWordE, 55U);
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 17528342580198295025U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6495418332558436882U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8834495762667327342U;
            aOrbiterK = RotL64((aOrbiterK * 10783141541937645995U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 4364314196965690905U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6357485231062120459U;
            aOrbiterE = RotL64((aOrbiterE * 289429584586504995U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3321488322626415347U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10817330671781848737U;
            aOrbiterA = RotL64((aOrbiterA * 15875919466358823335U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17974092279281611763U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2871472057292789157U;
            aOrbiterD = RotL64((aOrbiterD * 16104199340711015181U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 15187929795092006849U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13482063681546475923U;
            aOrbiterB = RotL64((aOrbiterB * 14466266308157364963U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6232152545071397380U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 17488906002621373262U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) ^ RotL64(aNonceWordH, 27U);
            aOrbiterH = RotL64((aOrbiterH * 4719340606442742577U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12444819880507588549U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13808941689757772497U;
            aOrbiterG = RotL64((aOrbiterG * 6541360905282412317U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8049361354387692374U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7137831335606542401U;
            aOrbiterI = RotL64((aOrbiterI * 11022231291507235007U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7230759462019420058U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 3923744511976096944U) ^ RotL64(aNonceWordG, 50U);
            aOrbiterF = RotL64((aOrbiterF * 9953869624243563101U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15967667946023263856U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8677583624693910669U;
            aOrbiterJ = RotL64((aOrbiterJ * 10737731876339973717U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 1604347321263511013U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8685374557928800912U;
            aOrbiterC = RotL64((aOrbiterC * 14103365695918844461U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 22U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 36U) + aOrbiterB) + RotL64(aOrbiterE, 27U));
            aWandererH = aWandererH + ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterA, 19U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 13U)) + aPhaseEWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterB, 24U)) + RotL64(aNonceWordA, 13U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 47U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aCross, 23U) + RotL64(aOrbiterF, 37U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterC, 41U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 43U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 6U)) + aOrbiterG);
            aWandererG = aWandererG + (((((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB) + RotL64(aCarry, 23U)) + RotL64(aNonceWordD, 3U)) + aPhaseEWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 36U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererH, 4U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 43U) ^ RotL64(aNonceWordB, 28U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29560U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 29894U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordD, 51U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32083U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28355U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 51U)) + (RotL64(aCross, 18U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = (aWandererI + RotL64(aIngress, 53U)) + 8866844335448071821U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 3U)) + 15159698739856430085U;
            aOrbiterK = (aWandererF + RotL64(aCross, 41U)) + 9582805772989594633U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 27U)) + 1438538239931588373U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 60U)) + RotL64(aCarry, 13U)) + 10862044156620436139U;
            aOrbiterC = (aWandererC + RotL64(aCross, 37U)) + 13682173320058164615U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 29U)) + 8351013291045977592U) + RotL64(aNonceWordA, 22U);
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 15777857431516633916U) + RotL64(aNonceWordG, 53U);
            aOrbiterF = ((aWandererE + RotL64(aCross, 24U)) + RotL64(aCarry, 21U)) + 16178966745333885377U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 5U)) + 9031889187993001617U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aScatter, 47U)) + 6308472367425865347U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 642109145903321046U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9186268569255318035U;
            aOrbiterK = RotL64((aOrbiterK * 10714674348507516749U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 6091345356803675860U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13218507921880873749U;
            aOrbiterI = RotL64((aOrbiterI * 15415157927185637717U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4266652275234474616U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 4391422098164506195U;
            aOrbiterC = RotL64((aOrbiterC * 17634679403195085867U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5160682323243635577U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10351728852161347404U;
            aOrbiterB = RotL64((aOrbiterB * 11105410036471745951U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3950932176454814023U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 9536466386833427441U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18064984243491293435U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9927425919978776529U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6819384090527481081U;
            aOrbiterF = RotL64((aOrbiterF * 18032965969184368561U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1646274931424218507U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16166524473976135097U;
            aOrbiterJ = RotL64((aOrbiterJ * 11672192658072663849U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 11252501968059485262U) + RotL64(aNonceWordD, 59U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 16847854447987609067U) ^ RotL64(aNonceWordB, 57U);
            aOrbiterA = RotL64((aOrbiterA * 6326299154627028295U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16723218285355036446U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13870211254243048975U;
            aOrbiterG = RotL64((aOrbiterG * 10203222183774624097U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 11401147367366049493U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4266628469244269926U;
            aOrbiterE = RotL64((aOrbiterE * 2409934496621365221U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11578385782347296942U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 8866844335448071821U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6456956795450036515U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (RotL64(aOrbiterK, 34U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterC, 34U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 51U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterJ, 11U)) + RotL64(aNonceWordF, 37U)) + aPhaseEWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterC, 53U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 19U)) + aOrbiterD);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterA, 5U)) + aOrbiterG) + RotL64(aNonceWordE, 51U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterD, 13U));
            aWandererB = aWandererB + ((RotL64(aCross, 43U) + RotL64(aOrbiterD, 40U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Golf_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC1B2D0D973D6A5B7ULL + 0xAB056D1DEB1B0D7BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC3F893317F2FB60BULL + 0xCD9A8EB0416E5F9EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9ABE15C724B01CABULL + 0x8816D1037A79DAACULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xEBECC71179C802DDULL + 0xC6D70A3A6411E35EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x93025E462B27DCABULL + 0xA516D3845D53B517ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x874A27EB9AAA47FBULL + 0xD6BA44523F59CD8EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD16C64456132806FULL + 0x91B72EED6AFC2F4AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xEDB469F96CD10249ULL + 0xAE59174A9F696266ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 37U) ^ RotL64(aNonceWordC, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1037U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneC[((aIndex + 4564U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordE, 46U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4051U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 689U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 20U) + RotL64(aPrevious, 5U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererE + RotL64(aIngress, 5U)) + 8604208734152026945U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 29U)) + 1374329953253889829U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 5779278910548228339U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 53U)) + 17670451230882805140U;
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 50U)) + 8193848740764866860U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordA, 53U);
            aOrbiterE = (aWandererB + RotL64(aCross, 19U)) + 15801168428145650104U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 3U)) + 2584718176087499066U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 14950366247822737997U) + RotL64(aNonceWordH, 43U);
            aOrbiterH = (aWandererC + RotL64(aIngress, 37U)) + 9779293225265670135U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 24U)) + 8688968319288372383U;
            aOrbiterB = (((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 13665723186950342601U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9395428688359973510U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2152719218018108418U;
            aOrbiterF = RotL64((aOrbiterF * 15271961483518392671U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1350324137411377992U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 8729317951386057921U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6008790836417785083U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6317310451893678411U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10175620379041384281U;
            aOrbiterD = RotL64((aOrbiterD * 14079679617394330781U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 1203082119358827708U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 523869107818193101U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4629501113595689157U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 4028324959540432983U) + RotL64(aNonceWordE, 35U);
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15447631947468213912U;
            aOrbiterI = RotL64((aOrbiterI * 6037306615787729185U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14225888694733041031U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 11925000696281947629U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4337022940520411253U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15015531024930608745U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 16752579225076943550U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15551083683579981439U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2432733494869267901U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10103430321388601485U;
            aOrbiterA = RotL64((aOrbiterA * 18372919379972432569U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15943360147468638325U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9782703760233558733U;
            aOrbiterJ = RotL64((aOrbiterJ * 685056980418243879U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 18345087852012669037U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8897505040792027675U) ^ RotL64(aNonceWordG, 31U);
            aOrbiterG = RotL64((aOrbiterG * 14333687539092412967U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7402581293947129667U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8604208734152026945U;
            aOrbiterC = RotL64((aOrbiterC * 9965525485538037673U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 41U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 48U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 57U) + RotL64(aOrbiterF, 34U)) + aOrbiterK);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 18U) + aOrbiterI) + RotL64(aOrbiterG, 21U)) + aPhaseFWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 5U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterJ, 57U)) + RotL64(aNonceWordF, 26U));
            aWandererF = aWandererF + ((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterG, 13U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 29U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterA, 38U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 53U)) + aOrbiterD) + RotL64(aNonceWordD, 3U));
            aWandererA = aWandererA + ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 23U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 47U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 36U) + aOrbiterB) + RotL64(aOrbiterJ, 19U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 42U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 12U) ^ RotL64(aNonceWordA, 37U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5930U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10867U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 28U) ^ RotL64(aNonceWordE, 57U)) ^ RotL64(aNonceWordC, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7771U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((aIndex + 5736U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 47U) + RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererH + RotL64(aIngress, 24U)) + 1393781663398437180U;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 37U)) + 17414594746688585273U) + aPhaseFOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aCross, 5U)) + 2823888497053071250U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 11U)) + 17032631958617884859U) + RotL64(aNonceWordA, 40U);
            aOrbiterE = (aWandererB + RotL64(aPrevious, 35U)) + 15222697630461125019U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 21U)) + 15737414920751551780U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 27U)) + 1357196111055783001U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 21U)) + 5315122321649251691U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 54U)) + 7893744655508595974U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 3U)) + 16721939414324611738U) + RotL64(aNonceWordB, 57U);
            aOrbiterH = ((aWandererK + RotL64(aScatter, 13U)) + 3444375866323610848U) + aPhaseFOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1825716513674511632U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15582066843912467318U;
            aOrbiterD = RotL64((aOrbiterD * 12765146555943757373U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15673590949193923915U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13887365046280406413U;
            aOrbiterK = RotL64((aOrbiterK * 3169061375011420121U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12730414371734709356U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 4819112390640821927U) ^ RotL64(aNonceWordF, 27U);
            aOrbiterE = RotL64((aOrbiterE * 8782547948627685451U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3089925954422937464U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7180179304678622530U;
            aOrbiterG = RotL64((aOrbiterG * 16118051565147747413U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17030269962085008657U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6675917351883004046U;
            aOrbiterI = RotL64((aOrbiterI * 14134335325316949687U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 12572022803491077491U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2801421744689267375U;
            aOrbiterF = RotL64((aOrbiterF * 315045745990934023U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4335148696780313055U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12526298573395110141U;
            aOrbiterA = RotL64((aOrbiterA * 11276803410698178607U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6984239833558496091U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 12195433952105336808U) ^ RotL64(aNonceWordC, 3U);
            aOrbiterJ = RotL64((aOrbiterJ * 8642600547427664495U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6392683095502982341U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 18047201953488013325U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16151795290455603489U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15433458942878109208U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 1700365768743794306U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16151638348775286903U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10951473638533187729U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1393781663398437180U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2661447713922232789U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 27U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 56U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 44U) + aOrbiterC) + RotL64(aOrbiterA, 35U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordH, 61U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 53U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterI, 5U)) + RotL64(aNonceWordD, 11U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterF, 27U));
            aWandererG = aWandererG + ((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 30U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 11U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 20U) + aOrbiterE) + RotL64(aOrbiterC, 57U));
            aWandererK = aWandererK + ((((RotL64(aCross, 37U) + RotL64(aOrbiterG, 47U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 24U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 18U) ^ RotL64(aNonceWordG, 41U)) ^ RotL64(aNonceWordH, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13135U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 13779U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordE, 28U)) ^ RotL64(aNonceWordB, 53U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12785U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 11335U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 54U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererB + RotL64(aIngress, 27U)) + 8101351470141807662U;
            aOrbiterI = (((aWandererF + RotL64(aScatter, 4U)) + 6965474099521076705U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordF, 5U);
            aOrbiterG = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 6803828268885684784U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 57U)) + 13454235922950972488U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 21U)) + 11678091885751244777U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 56U)) + 5307134544628507141U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 37U)) + 4873703518950429353U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 39U)) + 8542156221858586039U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 35U)) + 3993726182905296513U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 51U)) + 12113047622035464386U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 23U)) + 1944244448665721151U) + RotL64(aNonceWordD, 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 12914188029425467576U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2486762763475327024U;
            aOrbiterG = RotL64((aOrbiterG * 12319769994433811617U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14580191602982245481U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12093414832400135066U;
            aOrbiterC = RotL64((aOrbiterC * 12720286833215690663U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13623906997320021065U) + RotL64(aNonceWordA, 10U);
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9977356009806428696U;
            aOrbiterI = RotL64((aOrbiterI * 2005536391712733499U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 3694954095397810851U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11453812627797091638U;
            aOrbiterF = RotL64((aOrbiterF * 13730420725113907161U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 542311345544726351U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 3024285045990499484U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5153745952148205645U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15397664082460849530U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10716856680110815056U;
            aOrbiterJ = RotL64((aOrbiterJ * 13947203772929252823U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 833342121331428547U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1111339940097269219U;
            aOrbiterE = RotL64((aOrbiterE * 17991642769781175473U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9312963978841402871U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8225496710723213204U;
            aOrbiterK = RotL64((aOrbiterK * 894499195498817065U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 7947419530949269753U) + RotL64(aNonceWordH, 25U);
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5028446114139808517U;
            aOrbiterD = RotL64((aOrbiterD * 5593084899736787263U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9818957208200746975U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17549192719666647522U;
            aOrbiterH = RotL64((aOrbiterH * 4705007748877441833U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16389708540378477737U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8101351470141807662U;
            aOrbiterA = RotL64((aOrbiterA * 9858235486537441981U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 24U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterC, 53U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 6U) + aOrbiterJ) + RotL64(aOrbiterB, 51U)) + aPhaseFWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterH, 26U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 35U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterD, 5U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 30U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aCross, 50U) + aOrbiterB) + RotL64(aOrbiterF, 39U)) + RotL64(aNonceWordB, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterF, 21U)) + RotL64(aNonceWordC, 7U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 48U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + RotL64(aWandererC, 34U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 19U) ^ RotL64(aNonceWordA, 11U)) ^ RotL64(aNonceWordB, 58U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20872U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18520U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 51U) ^ RotL64(aNonceWordG, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17631U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneD[((aIndex + 18880U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 36U) + RotL64(aIngress, 57U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = ((aWandererK + RotL64(aScatter, 35U)) + 4384716820085860551U) + aPhaseFOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aPrevious, 27U)) + 9715780315942116888U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 53U)) + 15963520052789178632U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 44U)) + 14346700690686392938U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 11U)) + 6005518012489966643U) + RotL64(aNonceWordC, 61U);
            aOrbiterI = (aWandererC + RotL64(aIngress, 39U)) + 2506732930310252119U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 27U)) + 16782163084851775826U) + RotL64(aNonceWordF, 13U);
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 50U)) + 823673076571076303U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 29U)) + 1634084509064077736U) + aPhaseFOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aScatter, 41U)) + 1288134975466877686U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 2998220403162908444U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 220430672180734911U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10223923547068528867U;
            aOrbiterJ = RotL64((aOrbiterJ * 12577370238343872139U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11696469696177647608U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6545430420379636963U;
            aOrbiterG = RotL64((aOrbiterG * 8387163146257553773U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 79691451831797107U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8971444023498649419U;
            aOrbiterI = RotL64((aOrbiterI * 7148919880477390009U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 5624403902454498793U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9468064161002030997U;
            aOrbiterD = RotL64((aOrbiterD * 8243560528100864595U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4619361544913629805U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12682446273369750704U;
            aOrbiterF = RotL64((aOrbiterF * 10879074713156075641U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8728730962617599223U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 9099675924074253030U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5525644236954497523U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 3298303921318288541U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5953276499411658358U;
            aOrbiterB = RotL64((aOrbiterB * 10565471305001292693U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 6725769507592688539U) + RotL64(aNonceWordE, 35U);
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1057277456510215817U;
            aOrbiterH = RotL64((aOrbiterH * 8269412198279297075U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 11317925732206917722U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17814749417006079067U;
            aOrbiterA = RotL64((aOrbiterA * 4369209051015735925U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9258362135343403308U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 4873837345446960113U;
            aOrbiterE = RotL64((aOrbiterE * 14223381466269503273U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7863380865835889675U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 4384716820085860551U) ^ RotL64(aNonceWordA, 43U);
            aOrbiterK = RotL64((aOrbiterK * 2003891033298374621U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 34U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordH, 21U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 4U)) + RotL64(aNonceWordG, 10U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 40U) + aOrbiterD) + RotL64(aOrbiterH, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterE, 19U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 53U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterK, 21U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterE, 23U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aIngress, 6U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 6U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererA, 28U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 12U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 26U) ^ RotL64(aNonceWordG, 53U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25447U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 25596U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 5U) ^ RotL64(aNonceWordA, 27U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21948U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23800U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 41U)) + (RotL64(aCross, 19U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 35U)) + 16183871922837164759U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aCross, 26U)) + RotL64(aCarry, 57U)) + 7002058258090219055U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 5650868611888303705U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 21U)) + 11899839660943876690U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 53U)) + 15349649504488111111U) + RotL64(aNonceWordB, 43U);
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 39U)) + 14060149569086744970U) + RotL64(aNonceWordE, 51U);
            aOrbiterA = (aWandererJ + RotL64(aScatter, 37U)) + 12920917574225030112U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 28U)) + 2831994965175330135U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 18312543585028439192U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 57U)) + 11657562205118394239U) + aPhaseFOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aPrevious, 41U)) + 10850792819281246052U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 17810371216216125323U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7963413941144223128U;
            aOrbiterF = RotL64((aOrbiterF * 534217972450595401U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 5498715358793875584U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9256727548911651373U;
            aOrbiterK = RotL64((aOrbiterK * 10498848323914000989U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17246360111302191699U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 18309978718113983369U;
            aOrbiterG = RotL64((aOrbiterG * 18267472694666221077U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3100998994319502921U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8129301860291235970U;
            aOrbiterE = RotL64((aOrbiterE * 17847033539279176187U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1889641029473279114U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16538494307002917945U;
            aOrbiterJ = RotL64((aOrbiterJ * 8081488217920885783U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5432230549146849322U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 2634437941396090817U) ^ RotL64(aNonceWordH, 57U);
            aOrbiterH = RotL64((aOrbiterH * 7612999214758935211U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16940172599174185058U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13151669140593952203U;
            aOrbiterA = RotL64((aOrbiterA * 16225319638131723487U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3995064294869931681U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 913081077665768816U;
            aOrbiterD = RotL64((aOrbiterD * 9299514648768060453U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2469001696075411481U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 2167390955194185443U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11805065572289005223U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1574066406534010796U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 8736976961589874013U) ^ RotL64(aNonceWordC, 23U);
            aOrbiterB = RotL64((aOrbiterB * 5980070607180321955U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 4233621443153132083U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16183871922837164759U;
            aOrbiterC = RotL64((aOrbiterC * 4030569514959370895U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 60U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterC, 27U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 14U) + aOrbiterE) + RotL64(aOrbiterJ, 42U));
            aWandererE = aWandererE + ((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterA, 11U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 57U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 35U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterE, 13U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterB, 5U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterC, 53U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterK, 18U)) + RotL64(aCarry, 53U)) + RotL64(aNonceWordF, 61U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 3U)) + aOrbiterK) + RotL64(aNonceWordA, 26U)) + aPhaseFWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 19U) ^ RotL64(aNonceWordH, 3U)) ^ RotL64(aNonceWordC, 39U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29497U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30178U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordA, 37U)) ^ RotL64(aNonceWordF, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32662U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30516U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 14U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 29U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererJ + RotL64(aIngress, 41U)) + 17936518874386450467U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 21U)) + 13722737841589910344U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 11774969167948715796U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 56U)) + 3640101505680493777U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 1369495382725650822U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 3U)) + 11827310354654653345U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 21U)) + 186037671377175394U) + RotL64(aNonceWordG, 35U);
            aOrbiterD = (aWandererH + RotL64(aPrevious, 27U)) + 11428829344234627340U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 29U)) + 2275016369870029068U) + RotL64(aNonceWordF, 44U);
            aOrbiterF = ((aWandererI + RotL64(aScatter, 10U)) + 15471646673734798328U) + aPhaseFOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 13U)) + 12172082573115640145U) + aPhaseFOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6626736341348283154U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12220614992483863623U;
            aOrbiterG = RotL64((aOrbiterG * 8137086205714097487U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13157102324253760215U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 4143587482368093601U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5060677690991506895U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11007575246013796426U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 11721585930088637162U) ^ RotL64(aNonceWordC, 59U);
            aOrbiterJ = RotL64((aOrbiterJ * 15009627907125738519U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5720789204450196217U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 3094696226821431648U) ^ RotL64(aNonceWordE, 29U);
            aOrbiterA = RotL64((aOrbiterA * 4412033981712165541U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14675830108100986773U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9444071495289719645U;
            aOrbiterD = RotL64((aOrbiterD * 10983136361953366557U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5106753847015199956U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 7585421898593510010U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 140996914192351011U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11746948407655524690U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16336323220286344483U;
            aOrbiterF = RotL64((aOrbiterF * 6590417628835864497U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8030445186765781136U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 276034088015165891U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7626025612710225099U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8116955322602209153U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5704503350608834450U;
            aOrbiterH = RotL64((aOrbiterH * 7049558959583832449U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8063875087087055875U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 1111816778196345760U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13820440198677609571U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7702895879089714461U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17936518874386450467U;
            aOrbiterC = RotL64((aOrbiterC * 12767279443267850009U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 56U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aIngress, 36U) + aOrbiterF) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 39U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterD, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 37U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 53U)) + aOrbiterA);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterH, 41U)) + RotL64(aNonceWordB, 49U));
            aWandererI = aWandererI + ((((RotL64(aCross, 39U) + RotL64(aOrbiterE, 51U)) + aOrbiterG) + RotL64(aNonceWordA, 31U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 27U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterJ, 24U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Golf_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC56DAAC23CAAD05BULL + 0xF7DE3E36395DD25BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB6B2C5EF699E24D9ULL + 0xA5ED101B87901621ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xED3E5C24645A64B5ULL + 0xBCBA636379F154FEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE445B5E2CF2F377BULL + 0xC4ABD511EAAE23A6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF5EB3B8194EE776FULL + 0xE2551815FC441BA4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF1B9B18B7CC6F7ADULL + 0x951A682264FD5B3CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE6A44B03E8C7CB1FULL + 0xDABC529E89ED5261ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA3CF01FC42DAD849ULL + 0x94640C8CC9B34F9FULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 11U) ^ RotL64(aNonceWordH, 29U)) ^ RotL64(aNonceWordF, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4739U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3103U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordA, 42U)) ^ RotL64(aNonceWordG, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 2234U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aPrevious, 57U)) + (RotL64(aCarry, 44U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererH + RotL64(aIngress, 13U)) + 8988572360732005217U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 17889613225105985335U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 37U)) + 15563478320513948626U;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 10U)) + RotL64(aCarry, 37U)) + 3441351228410524816U) + RotL64(aNonceWordG, 13U);
            aOrbiterH = (aWandererJ + RotL64(aCross, 21U)) + 4425592689451435346U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 47U)) + 12733160231627305928U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 57U)) + 3574152157304607854U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 53U)) + 15167631896729808783U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 43U)) + 15822667973915417055U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aScatter, 24U)) + 17181685481076577637U) + aPhaseFOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aCross, 41U)) + 9979204751408873468U) + RotL64(aNonceWordF, 8U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1334240485667164762U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9190066751460137016U;
            aOrbiterD = RotL64((aOrbiterD * 14585141844653660363U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15465215829109246336U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 2305208282453624419U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10257861974108363283U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16951510027310993926U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11117938943423526901U;
            aOrbiterI = RotL64((aOrbiterI * 7805486716716924787U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 12461379120662979432U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11719697049048823897U;
            aOrbiterA = RotL64((aOrbiterA * 14880996802304818757U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6843357278142933570U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 12727898578324702374U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9786435451654365097U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 18127999660067652233U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11754709060558683082U;
            aOrbiterK = RotL64((aOrbiterK * 12798744012150745847U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 16940151146420516184U) + RotL64(aNonceWordH, 57U);
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12924950783056761895U;
            aOrbiterC = RotL64((aOrbiterC * 8898170377271926745U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14829713915929878471U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 840466047621042565U;
            aOrbiterE = RotL64((aOrbiterE * 10748511630509529489U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 11469637840333471085U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5561780312837795893U;
            aOrbiterH = RotL64((aOrbiterH * 11935079844970978957U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1059834104159730610U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 10122108814456766430U) ^ RotL64(aNonceWordA, 17U);
            aOrbiterJ = RotL64((aOrbiterJ * 2184693583782179921U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14857099570072635006U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8988572360732005217U;
            aOrbiterG = RotL64((aOrbiterG * 14409836741925393077U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 41U);
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 14U) + aOrbiterA) + RotL64(aOrbiterK, 27U));
            aWandererE = aWandererE + ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterA, 43U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 21U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 46U)) + aOrbiterI);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterG, 35U)) + RotL64(aNonceWordD, 35U));
            aWandererD = aWandererD + ((((RotL64(aCross, 53U) + RotL64(aOrbiterH, 37U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 39U)) + aOrbiterF) + RotL64(aNonceWordC, 49U));
            aWandererH = aWandererH + ((RotL64(aIngress, 6U) + RotL64(aOrbiterD, 41U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterF, 50U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 23U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 5U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 11U) ^ RotL64(aNonceWordG, 41U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10491U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8928U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 13U) ^ RotL64(aNonceWordA, 3U)) ^ RotL64(aNonceWordB, 46U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7302U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 6568U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 39U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererD + RotL64(aCross, 42U)) + 3917730204724097072U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 27U)) + 1874642340716212824U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aPrevious, 51U)) + 6900165757434854160U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 12750946097023807161U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 11U)) + 6563216048479513594U;
            aOrbiterI = (aWandererC + RotL64(aCross, 13U)) + 14960240191349450795U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 16306180275951788289U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 19U)) + 6502066618271045547U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 23U)) + 6219852857850888738U;
            aOrbiterH = ((((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 2272931312452845850U) + aPhaseFOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1]) + RotL64(aNonceWordG, 57U);
            aOrbiterK = ((aWandererG + RotL64(aScatter, 60U)) + 3028929882263199463U) + RotL64(aNonceWordH, 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 6067393030073568112U) + RotL64(aNonceWordD, 17U);
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10094809900437037258U;
            aOrbiterF = RotL64((aOrbiterF * 18095564940730322769U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5962414178157074575U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15755563045799129417U;
            aOrbiterG = RotL64((aOrbiterG * 3692603590609922031U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 6321455513889880590U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1197435601998121700U;
            aOrbiterE = RotL64((aOrbiterE * 17693996266260557625U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12496949381666299968U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6357070235648527030U;
            aOrbiterA = RotL64((aOrbiterA * 2931486644220862433U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 8423760160877540210U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 8090246492554850768U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2949407491181921633U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11436635942985063755U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17086363141014359856U;
            aOrbiterB = RotL64((aOrbiterB * 10504127577318206801U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10734017887545474935U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 375515325165740779U;
            aOrbiterC = RotL64((aOrbiterC * 9980486695448151709U), 35U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 5217148491945389821U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordB, 13U);
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14696058217023530058U;
            aOrbiterI = RotL64((aOrbiterI * 11026674782236654799U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11869055287836412650U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16951500118659983436U;
            aOrbiterD = RotL64((aOrbiterD * 4304372681583055077U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7866300390953569803U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 18017335943787362993U;
            aOrbiterH = RotL64((aOrbiterH * 15683049583437004889U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2477944286851267725U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3917730204724097072U;
            aOrbiterK = RotL64((aOrbiterK * 6617615984203047419U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 41U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 54U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 51U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aCross, 60U) + aOrbiterF) + RotL64(aOrbiterC, 3U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterK, 5U)) + RotL64(aNonceWordE, 39U));
            aWandererH = aWandererH + ((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterH, 24U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterK, 47U));
            aWandererI = aWandererI + (((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 21U)) + aOrbiterI) + aPhaseFWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 27U)) + aOrbiterK);
            aWandererD = aWandererD + (((((RotL64(aCross, 13U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ) + RotL64(aCarry, 41U)) + RotL64(aNonceWordC, 42U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 13U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aPrevious, 18U) + aOrbiterC) + RotL64(aOrbiterK, 56U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterA, 19U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 43U) ^ RotL64(aNonceWordE, 14U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 13839U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11613U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 57U) ^ RotL64(aNonceWordH, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14885U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneC[((aIndex + 15039U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aPrevious, 37U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererG + RotL64(aIngress, 5U)) + 8101351470141807662U) + aPhaseFOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 19U)) + 6965474099521076705U) + RotL64(aNonceWordF, 25U);
            aOrbiterA = ((aWandererI + RotL64(aScatter, 46U)) + RotL64(aCarry, 35U)) + 6803828268885684784U;
            aOrbiterD = (aWandererB + RotL64(aCross, 51U)) + 13454235922950972488U;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 11678091885751244777U) + aPhaseFOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aScatter, 13U)) + 5307134544628507141U) + RotL64(aNonceWordE, 61U);
            aOrbiterB = (aWandererA + RotL64(aIngress, 60U)) + 4873703518950429353U;
            aOrbiterK = (aWandererH + RotL64(aCross, 23U)) + 8542156221858586039U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 41U)) + 3993726182905296513U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 3U)) + 12113047622035464386U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 21U)) + 1944244448665721151U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12914188029425467576U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2486762763475327024U;
            aOrbiterA = RotL64((aOrbiterA * 12319769994433811617U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14580191602982245481U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12093414832400135066U) ^ RotL64(aNonceWordC, 50U);
            aOrbiterF = RotL64((aOrbiterF * 12720286833215690663U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13623906997320021065U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 9977356009806428696U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2005536391712733499U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3694954095397810851U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11453812627797091638U;
            aOrbiterC = RotL64((aOrbiterC * 13730420725113907161U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 542311345544726351U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 3024285045990499484U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5153745952148205645U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15397664082460849530U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10716856680110815056U;
            aOrbiterH = RotL64((aOrbiterH * 13947203772929252823U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 833342121331428547U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1111339940097269219U;
            aOrbiterE = RotL64((aOrbiterE * 17991642769781175473U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9312963978841402871U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8225496710723213204U;
            aOrbiterD = RotL64((aOrbiterD * 894499195498817065U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 7947419530949269753U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 5028446114139808517U) ^ RotL64(aNonceWordG, 57U);
            aOrbiterB = RotL64((aOrbiterB * 5593084899736787263U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9818957208200746975U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17549192719666647522U;
            aOrbiterG = RotL64((aOrbiterG * 4705007748877441833U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16389708540378477737U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8101351470141807662U;
            aOrbiterI = RotL64((aOrbiterI * 9858235486537441981U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 37U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 50U) + aOrbiterD) + RotL64(aOrbiterF, 19U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterI, 13U));
            aWandererC = aWandererC + ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 52U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 39U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aIngress, 52U) + RotL64(aOrbiterE, 5U)) + aOrbiterH) + aPhaseFWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 11U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 29U)) + aOrbiterC) + RotL64(aCarry, 47U)) + RotL64(aNonceWordB, 9U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterJ, 47U)) + RotL64(aNonceWordA, 35U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterI, 41U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterK, 24U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererC, 18U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 5U) ^ RotL64(aNonceWordG, 26U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19572U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19616U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 56U) ^ RotL64(aNonceWordE, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20841U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((aIndex + 21064U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 19U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 48U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 18U)) + RotL64(aCarry, 13U)) + 3238389262925516513U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 41U)) + 12381787182611386995U) + aPhaseFOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1]) + RotL64(aNonceWordH, 47U);
            aOrbiterA = ((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 39U)) + 7883885539305181549U;
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 1185413044597727092U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aScatter, 43U)) + 15219353497204773135U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 53U)) + 7533774715626734082U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 39U)) + 2599930450937763464U;
            aOrbiterH = (aWandererK + RotL64(aCross, 13U)) + 16074720663961214284U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 35U)) + 15483613196360051221U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 23U)) + 9396557867081376268U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 48U)) + 9668459976852660245U) + RotL64(aNonceWordC, 18U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9037269914643207212U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16936742640861088240U;
            aOrbiterA = RotL64((aOrbiterA * 1040172193161012227U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16481274825758546398U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 481851372837611166U;
            aOrbiterF = RotL64((aOrbiterF * 2225030139210599207U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 13608921517203544108U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 16930740723286214636U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2605108503821980865U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 902242902582149908U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 1510861213079342977U) ^ RotL64(aNonceWordB, 19U);
            aOrbiterK = RotL64((aOrbiterK * 3309753895727400707U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7116243600304980310U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6631412278359709602U;
            aOrbiterH = RotL64((aOrbiterH * 11452627691392637463U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9246698682265275165U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 8594373032014031450U) ^ RotL64(aNonceWordE, 27U);
            aOrbiterG = RotL64((aOrbiterG * 2550138341089957033U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 15912837963877821048U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11404583513022627609U;
            aOrbiterB = RotL64((aOrbiterB * 17715204726760125357U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17295214920690244319U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 18315664494984189344U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17398893532076312945U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2474825506593695564U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4400473621592150441U;
            aOrbiterC = RotL64((aOrbiterC * 7098832854166953839U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15270166373215060119U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 4331232225067306139U;
            aOrbiterE = RotL64((aOrbiterE * 2299883590703870703U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2176207815544347316U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3238389262925516513U;
            aOrbiterJ = RotL64((aOrbiterJ * 13104597690682251231U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 24U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 35U)) + aOrbiterG) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 53U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aCross, 14U) + aOrbiterJ) + RotL64(aOrbiterB, 13U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterD, 57U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterJ, 48U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 43U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 39U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 23U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterD, 50U)) + RotL64(aNonceWordA, 55U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 10U) + RotL64(aOrbiterC, 27U)) + aOrbiterG) + RotL64(aNonceWordF, 3U)) + aPhaseFWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 38U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 50U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 37U) ^ RotL64(aNonceWordD, 6U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22771U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22069U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 58U) ^ RotL64(aNonceWordB, 27U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22622U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25158U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 35U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 18U)) + 2330952702412094686U) + aPhaseFOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aIngress, 53U)) + 7820188225935060799U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 19U)) + 9347644591709839145U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 51U)) + 2288624878446846870U) + RotL64(aNonceWordD, 35U);
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 41U)) + 9358977729492824128U) + RotL64(aNonceWordC, 17U);
            aOrbiterI = ((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 1858511275052455039U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 37U)) + 13715478509322292552U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aIngress, 57U)) + 16413396625604260455U;
            aOrbiterB = (aWandererC + RotL64(aCross, 47U)) + 17714322215518432705U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 41U)) + 16188315436202861122U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 30U)) + 5564445841368207813U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13717068949900594673U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14143659432287313765U;
            aOrbiterC = RotL64((aOrbiterC * 17281441046722262917U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5729546141908425670U) + RotL64(aNonceWordG, 59U);
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4297827922736712074U;
            aOrbiterI = RotL64((aOrbiterI * 13631630436759768885U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 829520109395163673U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 11547160328525174295U) ^ RotL64(aNonceWordH, 31U);
            aOrbiterF = RotL64((aOrbiterF * 4759690159673049775U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 2907177944512117206U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11100346409065275671U;
            aOrbiterA = RotL64((aOrbiterA * 17927994356809011637U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1344592529249949068U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6470438516791143572U;
            aOrbiterK = RotL64((aOrbiterK * 13339390828725370475U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 5217751823741520847U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5371275223586938039U;
            aOrbiterD = RotL64((aOrbiterD * 12318403075523724125U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 14218103150268532919U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1367628876596800571U;
            aOrbiterE = RotL64((aOrbiterE * 13777531272321533137U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2372041991018455610U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9870744274890595581U;
            aOrbiterB = RotL64((aOrbiterB * 12093443117747395585U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 15531376915156611594U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11166549148968363252U;
            aOrbiterG = RotL64((aOrbiterG * 10024372567841218915U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8555942275137258839U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3304132937209624841U;
            aOrbiterH = RotL64((aOrbiterH * 7965093976633155809U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14825330575158830172U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2330952702412094686U;
            aOrbiterJ = RotL64((aOrbiterJ * 9146641978165131495U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 29U);
            aIngress = aIngress + (RotL64(aOrbiterH, 48U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 18U) + aOrbiterG) + RotL64(aOrbiterF, 23U));
            aWandererD = aWandererD + (((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 3U)) + aOrbiterD) + RotL64(aNonceWordA, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterI, 43U)) + RotL64(aNonceWordE, 58U));
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 21U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 40U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterK, 11U)) + aPhaseFWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 53U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 29U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterI, 56U));
            aWandererI = aWandererI + ((RotL64(aCross, 44U) + aOrbiterC) + RotL64(aOrbiterG, 35U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterF, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 10U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 43U) ^ RotL64(aNonceWordH, 53U)) ^ RotL64(aNonceWordA, 27U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30690U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 32232U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 39U) ^ RotL64(aNonceWordG, 4U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28988U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 28699U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 51U)) ^ (RotL64(aIngress, 6U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererI + RotL64(aCross, 3U)) + 9774364261626083532U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 57U)) + 18059001521926116420U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 29U)) + 10615626210406381148U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 13U)) + 10536484278007898620U;
            aOrbiterK = (aWandererE + RotL64(aCross, 52U)) + 13320663045139972700U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 5U)) + 17127001787268166583U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 23U)) + 16742574590844166551U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 13U)) + 8347719720758228053U;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 35U)) + 13502468705946051986U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordA, 41U);
            aOrbiterD = ((aWandererA + RotL64(aIngress, 26U)) + 3512687886188904904U) + RotL64(aNonceWordC, 56U);
            aOrbiterG = (((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 5U)) + 495660316165795934U) + aPhaseFOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5092722552034477356U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 15641128019608284015U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3621036395703527059U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 15421873776811085458U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 17978775513204574125U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18359600395119440183U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16617179197537669849U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1931805387534012528U;
            aOrbiterC = RotL64((aOrbiterC * 3400139345857733775U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9544923119559308431U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12930999400470173353U;
            aOrbiterA = RotL64((aOrbiterA * 16791006919271490005U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13673733276226249890U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2032263473309124738U;
            aOrbiterJ = RotL64((aOrbiterJ * 3088728329261360607U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 14868502349358414206U) + RotL64(aNonceWordE, 7U);
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10116495537187552321U;
            aOrbiterB = RotL64((aOrbiterB * 1380512121796709469U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5341113995358179244U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8415417980279705731U;
            aOrbiterD = RotL64((aOrbiterD * 8521501372683793821U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2462819265072352463U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7657062767608441931U;
            aOrbiterG = RotL64((aOrbiterG * 15554638801273540163U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8153420530633265789U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10990681417675210534U;
            aOrbiterF = RotL64((aOrbiterF * 1928509513380702895U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17035995983178569271U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 2806563871848226777U) ^ RotL64(aNonceWordG, 15U);
            aOrbiterE = RotL64((aOrbiterE * 4137935663733587867U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 6570698907081812011U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9774364261626083532U;
            aOrbiterH = RotL64((aOrbiterH * 1766375419340392741U), 37U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 60U);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 26U) + aOrbiterB) + RotL64(aOrbiterH, 5U)) + RotL64(aNonceWordD, 51U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 47U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 11U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 28U) + RotL64(aOrbiterB, 52U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterG, 39U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 43U)) + aOrbiterB) + RotL64(aNonceWordB, 39U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterI, 27U)) + aPhaseFWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 3U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 30U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 26U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 30U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Golf_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 6551U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 6895U)) & W_KEY1], 10U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 4452U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 282U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCarry, 29U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 8020711767807230555U;
            aOrbiterH = (((aWandererE + RotL64(aCross, 28U)) + RotL64(aCarry, 35U)) + 15368693777246341570U) + aPhaseCOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aScatter, 47U)) + 5117523734225562401U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 41U)) + 13155269151097507808U;
            aOrbiterI = (aWandererF + RotL64(aCross, 19U)) + 9879303753623578272U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 57U)) + 1165799257173794826U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 23U)) + 930641942062732091U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 3U)) + 11330571332221123153U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aCross, 36U)) + 2862963158282518899U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6019186399361476659U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 1924419843785161958U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9485557122500346869U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12618629043591380461U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 9334176504266512405U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18239109235362925739U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16829692481030013551U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5604784396927022709U;
            aOrbiterF = RotL64((aOrbiterF * 2833893610883508353U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16124030106598549644U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16571659812830230677U;
            aOrbiterE = RotL64((aOrbiterE * 4668250364992383549U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 15171089673591843703U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2826755560293849328U;
            aOrbiterA = RotL64((aOrbiterA * 9397017963457655287U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9976785768283589291U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11845100564714691809U;
            aOrbiterD = RotL64((aOrbiterD * 4935139932585319251U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 7318560453127859950U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3039196878830506712U;
            aOrbiterG = RotL64((aOrbiterG * 3140508261330698717U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8850992055588337843U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4219373528176869146U;
            aOrbiterH = RotL64((aOrbiterH * 1310964742529956743U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1341474458715938799U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15937557372891732898U;
            aOrbiterI = RotL64((aOrbiterI * 11437307017920192915U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 6U);
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 40U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterB, 58U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterA, 39U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 20U) + RotL64(aOrbiterE, 23U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 19U)) + aOrbiterC) + aPhaseCWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 3U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterD, 47U));
            aWandererK = aWandererK + ((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterE, 34U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterA, 53U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 50U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 12882U)) & S_BLOCK1], 58U) ^ RotL64(mSource[((aIndex + 12684U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 9374U)) & W_KEY1], 51U) ^ RotL64(aKeyRowReadB[((aIndex + 9180U)) & W_KEY1], 30U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 6U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererF + RotL64(aIngress, 10U)) + 6771552164800695068U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 12131763371571322040U) + aPhaseCOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 23U)) + 3326182381395522013U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 3U)) + 12288775097697156383U;
            aOrbiterG = (aWandererG + RotL64(aCross, 19U)) + 5195948373449796741U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 47U)) + 14404044002250137144U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 11142382920035825426U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 52U)) + 2967149520256475485U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 47U)) + 1470907369577818097U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9231668148004163910U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13078929163913892386U;
            aOrbiterJ = RotL64((aOrbiterJ * 7509829068700523627U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9485274692075657877U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12216951187543631673U;
            aOrbiterG = RotL64((aOrbiterG * 6571066246507310805U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6933334652581744234U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17260276102423580920U;
            aOrbiterC = RotL64((aOrbiterC * 7796879893790990605U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 387767848169714392U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 8597538259308082638U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4888054690557707241U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7996708724489146033U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 15357384191688149939U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9827691726832491373U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17739222908739454637U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 1614322333281471170U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7063116837752240891U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 4531604274893197209U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3453280714992341288U;
            aOrbiterH = RotL64((aOrbiterH * 8390029711127907805U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 116623650872661533U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6565636510115095988U;
            aOrbiterF = RotL64((aOrbiterF * 9691897067492501177U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10303258439817808058U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10917642773040237611U;
            aOrbiterK = RotL64((aOrbiterK * 10232856828372963363U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 51U);
            aIngress = aIngress + (RotL64(aOrbiterC, 30U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterH, 27U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterJ, 43U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterC, 47U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 58U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aCross, 58U) + aOrbiterG) + RotL64(aOrbiterB, 19U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 19U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 5U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 35U)) + aPhaseCWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterE, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 42U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22368U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneA[((aIndex + 18393U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21093U)) & W_KEY1], 38U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 22820U)) & W_KEY1], 29U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 40U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererJ + RotL64(aIngress, 26U)) + 6361545377408870615U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 2967245486744774933U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 19U)) + 3836634268482850139U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 57U)) + 7691642115360086297U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aScatter, 5U)) + 16479280384178279281U;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 57U)) + 2901468732552539249U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aPrevious, 48U)) + 2600353867755647475U;
            aOrbiterI = (aWandererA + RotL64(aCross, 35U)) + 5666596904781510956U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 16108791609267427553U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8389926875737312112U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1689501721163024426U;
            aOrbiterK = RotL64((aOrbiterK * 6517194895779049139U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 11721701506949917719U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3963842745030140473U;
            aOrbiterB = RotL64((aOrbiterB * 6692473494944919373U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8510538243472109368U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 18281865214102080387U;
            aOrbiterE = RotL64((aOrbiterE * 1351546966368884609U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 2259725140963665123U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11652011949557979650U;
            aOrbiterF = RotL64((aOrbiterF * 11260100762113295037U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1116085424226174473U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4725260319270802912U;
            aOrbiterH = RotL64((aOrbiterH * 4697109059565450269U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7348945429843437036U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1249234309180653260U;
            aOrbiterC = RotL64((aOrbiterC * 3136745255820405881U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12463505532573389603U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 2304125977906510386U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9960816714791454421U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2178037443783425551U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11712110130079307683U;
            aOrbiterI = RotL64((aOrbiterI * 9797864956200779505U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10703510612147312252U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 18155460326242413483U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6903953708987478723U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterF, 13U));
            aWandererE = aWandererE + (((RotL64(aScatter, 28U) + RotL64(aOrbiterJ, 18U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 27U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterC, 53U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 58U)) + aOrbiterH) + aPhaseCWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterC, 35U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterI, 3U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterH, 41U)) + aPhaseCWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererF, 50U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31053U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27233U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31486U)) & S_BLOCK1], 48U) ^ RotL64(mSource[((aIndex + 32162U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 26U)) + (RotL64(aIngress, 41U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 52U)) + RotL64(aCarry, 51U)) + 10881271196314989997U;
            aOrbiterA = (aWandererF + RotL64(aCross, 43U)) + 6406461249988567558U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 21U)) + 17255067918280095959U) + aPhaseCOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 16690850682497718411U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 60U)) + RotL64(aCarry, 41U)) + 5576201059361086866U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 47U)) + 11991259685693687554U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 27U)) + 14652535244217836909U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 13U)) + 1701789037170782122U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 37U)) + 953429054903473833U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12064513610469714211U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 7993881398822002424U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11572884842788918377U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14421313768013320050U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11112386845630998889U;
            aOrbiterK = RotL64((aOrbiterK * 11771526352030371669U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17069630896535699015U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3308240081138623373U;
            aOrbiterH = RotL64((aOrbiterH * 10449509484417835159U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17615529807112933619U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11782807146851563541U;
            aOrbiterI = RotL64((aOrbiterI * 12992075832343669221U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14401645829607611983U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6736397344219993532U;
            aOrbiterG = RotL64((aOrbiterG * 1667287547938175641U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6446974060524700550U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 7840991992443308254U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6891023544882740107U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10362169906019794305U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4503700997923168911U;
            aOrbiterB = RotL64((aOrbiterB * 15066164494038852559U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13492041134973259041U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 14337899277551397976U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5966740718899290915U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 13693100781608180748U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16177545026405910052U;
            aOrbiterA = RotL64((aOrbiterA * 6019231448444020563U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 14U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 44U) + aOrbiterJ) + RotL64(aOrbiterG, 46U)) + aPhaseCWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterK, 5U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 57U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aPhaseCWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 29U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 10U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterH, 53U));
            aWandererI = aWandererI + ((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterK, 37U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterA, 23U));
            aWandererC = aWandererC + (((RotL64(aIngress, 58U) + aOrbiterA) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 54U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Golf_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3524U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 6986U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6821U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 5576U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 21U)) ^ (RotL64(aCross, 37U) + RotL64(aIngress, 52U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererF + RotL64(aCross, 47U)) + 6771552164800695068U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 24U)) + RotL64(aCarry, 23U)) + 12131763371571322040U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 37U)) + 3326182381395522013U;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 12288775097697156383U) + aPhaseDOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 5195948373449796741U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14404044002250137144U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11142382920035825426U;
            aOrbiterE = RotL64((aOrbiterE * 8134413822789107595U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 2967149520256475485U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 1470907369577818097U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9398653295177725883U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9231668148004163910U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 13078929163913892386U;
            aOrbiterK = RotL64((aOrbiterK * 7509829068700523627U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9485274692075657877U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12216951187543631673U;
            aOrbiterG = RotL64((aOrbiterG * 6571066246507310805U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6933334652581744234U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 17260276102423580920U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7796879893790990605U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 43U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterA, 29U));
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 5U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 14U) + RotL64(aOrbiterI, 37U)) + aOrbiterA) + aPhaseDWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 52U)) + aOrbiterG) + aPhaseDWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 28U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 11770U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 12062U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8773U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14269U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 38U) ^ RotL64(aCross, 19U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 2101601659597850213U;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 2759794072560720121U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aIngress, 19U)) + 9443562552411269339U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 10801360546699857975U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 40U)) + 8020716394829332019U) + aPhaseDOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1021894212367773801U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 13346855534622490176U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12668950387932320985U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16359309548462953836U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12642446944680783519U;
            aOrbiterF = RotL64((aOrbiterF * 12197935153255283321U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8197424982767553380U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 14346334610901859094U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16982899923227935679U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14171304260534233539U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 334531601308283605U;
            aOrbiterI = RotL64((aOrbiterI * 5012968232749075075U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 10707856298471572695U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 18364775750091914766U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15735143943129143265U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 58U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterI, 36U)) + aPhaseDWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 11U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterI, 51U));
            aWandererE = aWandererE + (((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 52U) + aOrbiterI) + RotL64(aOrbiterF, 19U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22467U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 18367U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20686U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19803U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 27U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererH + RotL64(aPrevious, 53U)) + 13204735390996728477U;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 851171359595647173U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 11U)) + 16745304202825290723U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 11U)) + 562392736584913979U;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 20U)) + RotL64(aCarry, 57U)) + 3244267012529053918U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17282536111067869133U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14851130066471729068U;
            aOrbiterA = RotL64((aOrbiterA * 6308165353504550619U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5256130407952363129U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2904742485828362001U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12941135856735075457U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 3723346325449225387U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5344621093694027341U;
            aOrbiterH = RotL64((aOrbiterH * 9044881458629673499U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12919263300833603026U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17989801264160996071U;
            aOrbiterJ = RotL64((aOrbiterJ * 15468293047311883751U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 5022175042377172157U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 16684822380107847758U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2834049270263837537U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 41U);
            aIngress = aIngress + (RotL64(aOrbiterH, 28U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 29U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 48U)) + aOrbiterH);
            aWandererH = aWandererH + ((((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 57U)) + aOrbiterH) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterK, 3U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 56U) + RotL64(aOrbiterA, 21U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 22U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32010U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30882U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25516U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 27498U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 52U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererK + RotL64(aScatter, 11U)) + 2330952702412094686U;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 7820188225935060799U) + aPhaseDOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aCross, 28U)) + RotL64(aCarry, 5U)) + 9347644591709839145U;
            aOrbiterH = (((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 2288624878446846870U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aScatter, 19U)) + 9358977729492824128U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 1858511275052455039U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13715478509322292552U;
            aOrbiterD = RotL64((aOrbiterD * 15552121744869003235U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16413396625604260455U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17714322215518432705U;
            aOrbiterF = RotL64((aOrbiterF * 1904184102419934333U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 16188315436202861122U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5564445841368207813U;
            aOrbiterH = RotL64((aOrbiterH * 14125834616162835983U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13717068949900594673U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 14143659432287313765U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17281441046722262917U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 5729546141908425670U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4297827922736712074U;
            aOrbiterA = RotL64((aOrbiterA * 13631630436759768885U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 26U);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterF, 27U));
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 19U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterD, 54U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 30U) + aOrbiterF) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterH, 11U)) + aOrbiterA) + aPhaseDWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_Golf_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7045U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2967U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7205U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5206U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 3U)) + (RotL64(aCross, 19U) + RotL64(aIngress, 38U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 1142447269198373880U;
            aOrbiterB = (aWandererG + RotL64(aCross, 51U)) + 10581460640040336191U;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 14703062773878202900U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aIngress, 12U)) + 15737525756286914746U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 37U)) + 16178774478273186999U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 2514897053906809160U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 21U)) + 13702496607592508464U) + aPhaseEOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 18030885275418337965U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5241783876161655984U;
            aOrbiterC = RotL64((aOrbiterC * 10970981186787227937U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 2807052676283587925U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 8022804576763271327U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11727096043219370577U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 15597099852232205860U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1538435607932096400U;
            aOrbiterF = RotL64((aOrbiterF * 7900752511710516981U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11147868774413615365U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9325213746830411568U;
            aOrbiterK = RotL64((aOrbiterK * 561819005818948769U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 13792300423550555634U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3134856508983945719U;
            aOrbiterD = RotL64((aOrbiterD * 4271845067763664863U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8654966018053784882U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8937113935476779267U;
            aOrbiterA = RotL64((aOrbiterA * 7386875687217705855U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4135676350355234788U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11407912615743682678U;
            aOrbiterB = RotL64((aOrbiterB * 2773506587480714695U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 50U) + aOrbiterK) + RotL64(aOrbiterB, 34U));
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 51U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 21U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 13U)) + aOrbiterK) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 43U));
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + RotL64(aOrbiterA, 27U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 3U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 44U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15203U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11871U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11432U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8225U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 4U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererC + RotL64(aPrevious, 3U)) + 3236820517816085022U;
            aOrbiterB = (aWandererB + RotL64(aCross, 57U)) + 741288875914097926U;
            aOrbiterG = (((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 8417246926007729580U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aScatter, 30U)) + RotL64(aCarry, 23U)) + 9715717805774537170U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 11U)) + 14360243844821619482U) + aPhaseEOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 35U)) + 10760908100206775334U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 37U)) + 3434641779946167811U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7885568822756234567U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3041563437672051294U;
            aOrbiterG = RotL64((aOrbiterG * 11440300917533482297U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 15761355327564963516U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1158633562785937421U;
            aOrbiterI = RotL64((aOrbiterI * 15511324886867188235U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9338581575871970653U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9172038894262857354U;
            aOrbiterF = RotL64((aOrbiterF * 3110871165285625807U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14653924713599790081U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 3854497592598563309U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11737111068815795303U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16286980180327600557U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5092583772591249756U;
            aOrbiterH = RotL64((aOrbiterH * 13955105624639442903U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4288397994175567333U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 15584236478994873104U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1860480595862755379U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5557463939827483792U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2659814275753280856U;
            aOrbiterC = RotL64((aOrbiterC * 17702430405693184643U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 58U) + aOrbiterC) + RotL64(aOrbiterG, 43U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterI, 11U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 56U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterG, 29U));
            aWandererF = aWandererF + ((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterF, 35U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterB, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19060U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((aIndex + 19885U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24189U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((aIndex + 21166U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 3U)) + (RotL64(aCross, 20U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 8988572360732005217U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 28U)) + RotL64(aCarry, 51U)) + 17889613225105985335U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 37U)) + 15563478320513948626U) + aPhaseEOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 39U)) + 3441351228410524816U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 3U)) + 4425592689451435346U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 43U)) + 12733160231627305928U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 53U)) + 3574152157304607854U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15167631896729808783U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15822667973915417055U;
            aOrbiterK = RotL64((aOrbiterK * 5155661648455308057U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 17181685481076577637U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 9979204751408873468U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8244434774754786565U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 1334240485667164762U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9190066751460137016U;
            aOrbiterJ = RotL64((aOrbiterJ * 14585141844653660363U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15465215829109246336U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2305208282453624419U;
            aOrbiterG = RotL64((aOrbiterG * 10257861974108363283U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16951510027310993926U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11117938943423526901U;
            aOrbiterE = RotL64((aOrbiterE * 7805486716716924787U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12461379120662979432U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 11719697049048823897U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14880996802304818757U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6843357278142933570U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12727898578324702374U;
            aOrbiterF = RotL64((aOrbiterF * 9786435451654365097U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 36U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 11U)) + aPhaseEWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 51U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 58U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterF, 41U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 3U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 18U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29422U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31132U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24842U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneD[((aIndex + 27954U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererK + RotL64(aIngress, 5U)) + 1087148170018530502U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 27U)) + 15530846874509311414U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 51U)) + 16987358651515511212U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 11U)) + 12504143181007924259U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 12U)) + RotL64(aCarry, 51U)) + 393322117322732418U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 29U)) + 14325937299241887166U) + aPhaseEOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aCross, 57U)) + 9395262907017475742U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13658510441418344769U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6410754322737005336U;
            aOrbiterJ = RotL64((aOrbiterJ * 6932217611373076391U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9257290738538818434U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7489828960857692286U;
            aOrbiterB = RotL64((aOrbiterB * 16519674788777989043U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4118778591214588387U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 16619215231168796563U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14876884956536265157U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11326283811003573430U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1865401866017614604U;
            aOrbiterK = RotL64((aOrbiterK * 8378326058282460073U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 670150121105733604U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 1499331510641068749U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16623742535540383107U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 1116410848560838532U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2696841341036281779U;
            aOrbiterH = RotL64((aOrbiterH * 9598953298074904869U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 5487352391229549881U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12008243050943342979U;
            aOrbiterF = RotL64((aOrbiterF * 9087261224804582459U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterF, 5U)) + aPhaseEWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterH, 43U));
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterK, 29U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterF, 11U)) + aOrbiterB) + aPhaseEWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 60U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 56U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_Golf_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5442U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7147U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7166U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((aIndex + 6594U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aCross, 22U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 47U)) + 13296600294247799698U) + aPhaseFOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 11U)) + 5818503518080877515U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 6735784238734173597U;
            aOrbiterC = (aWandererK + RotL64(aCross, 28U)) + 7368398209488856201U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 53U)) + 961734029066455638U) + aPhaseFOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 797011946660892011U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12841876018396622350U;
            aOrbiterH = RotL64((aOrbiterH * 14056540056414153277U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 16213253970483895623U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 15186950557113470375U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4647470430467908107U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 5117930310827477341U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12265429373166094162U;
            aOrbiterC = RotL64((aOrbiterC * 1522823535151532249U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13920531346698601568U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14695405206998211456U;
            aOrbiterD = RotL64((aOrbiterD * 13950964363414164279U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 7851960904825938443U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9501511171732550190U;
            aOrbiterE = RotL64((aOrbiterE * 5614164120361489613U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 14U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 18U) + aOrbiterC) + RotL64(aOrbiterD, 19U));
            aWandererK = aWandererK + (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 44U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 35U)) + aOrbiterE) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 27U)) + aOrbiterE) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 56U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8944U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9639U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16095U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 9132U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 43U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererA + RotL64(aIngress, 35U)) + 2786079456995203065U) + aPhaseFOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aScatter, 23U)) + 7237256119153857253U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 9310834010563647604U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 14U)) + RotL64(aCarry, 51U)) + 17361734905706517877U;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 15837111231884647451U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 18065431964418026445U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 3029123922999952652U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16309219658285890145U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5166926595573507837U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1918425684273807598U;
            aOrbiterG = RotL64((aOrbiterG * 16616641579714896719U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4724551751012661440U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 1818014487579644390U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14904092108647864911U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6670090372241084216U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 8485757110007268693U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11876760095108618363U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 4928130251509514742U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2528788422725346792U;
            aOrbiterI = RotL64((aOrbiterI * 1855982047967756661U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (RotL64(aOrbiterA, 34U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 11U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 27U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterI, 36U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterI, 19U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 36U) + aOrbiterI) + RotL64(aOrbiterG, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20467U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((aIndex + 21758U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24445U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24474U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 47U)) ^ (RotL64(aCross, 4U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererG + RotL64(aPrevious, 51U)) + 2571116506511057880U;
            aOrbiterD = (((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 13112435411509707292U) + aPhaseFOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 10403251762787357256U;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 6U)) + RotL64(aCarry, 53U)) + 8461951095541400405U) + aPhaseFOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aPrevious, 19U)) + 9890793478557463815U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3030229465991783707U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7273848154043719247U;
            aOrbiterF = RotL64((aOrbiterF * 17562254601517935669U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10681774862516028276U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7105082755586853104U;
            aOrbiterD = RotL64((aOrbiterD * 12217705329504230357U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 6588579345319551129U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 14616333550242386092U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2934574715879306337U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15439666290229654921U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3360304356760164799U;
            aOrbiterB = RotL64((aOrbiterB * 5164191920584106237U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 14438730801970761889U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 14515616787452085729U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2041601927968559821U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 23U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 6U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterA, 53U)) + aPhaseFWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterF, 11U));
            aWandererI = aWandererI + (((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 36U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 10U) + aOrbiterF) + RotL64(aOrbiterA, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30063U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26006U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32456U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 29360U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 52U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererK + RotL64(aCross, 27U)) + 1888427424966603593U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 14U)) + RotL64(aCarry, 23U)) + 5436761445660415091U;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 17322876217962143270U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 37U)) + 9728299982740564979U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 37U)) + 301720335271716921U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 8069685428854814396U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 1973715500949100991U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7940531594430629427U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 87666408799854155U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12195436904339035245U;
            aOrbiterC = RotL64((aOrbiterC * 15427739165893738105U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 4578742069143400295U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7828776048774876484U;
            aOrbiterE = RotL64((aOrbiterE * 4047964518501081039U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17203146364542781833U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16913369550858890466U;
            aOrbiterJ = RotL64((aOrbiterJ * 13534417587921978507U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9632761514552265402U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 9106637671877341286U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9073709119482640391U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterG, 11U)) + aPhaseFWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + RotL64(aOrbiterH, 22U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 4U) + aOrbiterC) + RotL64(aOrbiterE, 39U)) + aPhaseFWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Golf_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 4541U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 3645U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 299U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8192U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 13U) ^ RotL64(aIngress, 40U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererD + RotL64(aCross, 38U)) + 2101601659597850213U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 29U)) + 2759794072560720121U) + aPhaseGOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 9443562552411269339U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 10801360546699857975U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 41U)) + 8020716394829332019U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1021894212367773801U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13346855534622490176U;
            aOrbiterA = RotL64((aOrbiterA * 12668950387932320985U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 16359309548462953836U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12642446944680783519U;
            aOrbiterJ = RotL64((aOrbiterJ * 12197935153255283321U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8197424982767553380U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 14346334610901859094U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16982899923227935679U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 14171304260534233539U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 334531601308283605U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5012968232749075075U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10707856298471572695U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 18364775750091914766U;
            aOrbiterG = RotL64((aOrbiterG * 15735143943129143265U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 39U)) + aOrbiterG) + aPhaseGWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 56U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 10671U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((aIndex + 15481U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14164U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14976U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 7960325128608297381U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aScatter, 24U)) + RotL64(aCarry, 27U)) + 12773836012104052042U;
            aOrbiterD = (((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 3173972621347773016U) + aPhaseGOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aPrevious, 51U)) + 3708401356314308171U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 3U)) + 950774285720019449U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 4170092315705438265U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17000449130864980747U;
            aOrbiterD = RotL64((aOrbiterD * 7710635557693533263U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 8793910540062893860U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 520277969543516469U;
            aOrbiterE = RotL64((aOrbiterE * 4150613128885828229U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 12762214857389827271U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2932451184340207695U;
            aOrbiterF = RotL64((aOrbiterF * 7513337346940091655U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11062179998786293839U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 7919119215271524178U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9053677007180081359U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1774988449597115155U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3799792889466518953U;
            aOrbiterI = RotL64((aOrbiterI * 17512791286490623455U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 40U) + RotL64(aOrbiterI, 3U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterI, 53U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 11U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 44U)) + aOrbiterI) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterE, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 16755U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((aIndex + 19133U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21533U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((aIndex + 22430U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCarry, 21U) + RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 17470880031634374199U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 24U)) + 757565846006937746U) + aPhaseGOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 9419282475801345674U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 2014248014107898196U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 13U)) + 15113928519446490441U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 7346126964886259935U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 5594123113093162359U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18043634828891483403U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 5659237263369402005U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11565709683423969703U;
            aOrbiterK = RotL64((aOrbiterK * 16731289017588574671U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16782863743534856287U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13499100900072115907U;
            aOrbiterC = RotL64((aOrbiterC * 5567729598873214433U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11414447651044205242U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7545993795121430538U;
            aOrbiterH = RotL64((aOrbiterH * 10758488381206257261U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 11778229237616454988U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 2544793391976514665U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4021060413798523299U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (RotL64(aOrbiterA, 54U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 44U) + RotL64(aOrbiterG, 43U)) + aOrbiterA);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 27U)) + aOrbiterC) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 51U)) + aOrbiterC) + aPhaseGWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 24U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 32336U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneA[((aIndex + 28373U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25259U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27599U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 12U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 39U)) + 17912271996338180948U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 5U)) + 13259276608841847058U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 19U)) + 16225936008657276089U;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 2243058962151834071U) + aPhaseGOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 52U)) + RotL64(aCarry, 5U)) + 10637439274127347861U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 15312219216405992627U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2393933972129878613U;
            aOrbiterK = RotL64((aOrbiterK * 13147717214387593761U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4327069337247976513U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8307656353434167837U;
            aOrbiterA = RotL64((aOrbiterA * 11386588389133096705U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17299145556933889336U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 14458100581172798164U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16543734663677070509U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 6410095654927998067U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6168964796264687686U;
            aOrbiterI = RotL64((aOrbiterI * 16218071040190475953U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 3667999465041020730U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16021552859323602007U;
            aOrbiterH = RotL64((aOrbiterH * 6427266472526362663U), 39U);
            //
            aIngress = RotL64(aOrbiterI, 51U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 24U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 29U) + RotL64(aOrbiterK, 13U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 60U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 48U) + RotL64(aOrbiterH, 21U)) + aOrbiterC);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterC, 5U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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

void TwistExpander_Golf_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 5838U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5193U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2432U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((aIndex + 4698U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCarry, 54U)) + (RotL64(aCross, 13U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererH + RotL64(aIngress, 39U)) + 2101601659597850213U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 21U)) + 2759794072560720121U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 9443562552411269339U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 10801360546699857975U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 5U)) + 8020716394829332019U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 1021894212367773801U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 13346855534622490176U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12668950387932320985U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 16359309548462953836U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12642446944680783519U;
            aOrbiterB = RotL64((aOrbiterB * 12197935153255283321U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8197424982767553380U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14346334610901859094U;
            aOrbiterE = RotL64((aOrbiterE * 16982899923227935679U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14171304260534233539U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 334531601308283605U;
            aOrbiterD = RotL64((aOrbiterD * 5012968232749075075U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10707856298471572695U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 18364775750091914766U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15735143943129143265U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterB, 27U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 41U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + aPhaseHWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 5U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterF, 14U)) + aPhaseHWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 12317U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9096U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13610U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13005U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 5U)) + (RotL64(aCross, 21U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererB + RotL64(aCross, 19U)) + 13924571355038625040U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 48U)) + RotL64(aCarry, 27U)) + 16328300979357156658U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 37U)) + 3947771961206012461U;
            aOrbiterK = (((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 15428284250569311285U) + aPhaseHOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 5777369485254032486U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 16813320300717644673U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16689933050200758251U;
            aOrbiterE = RotL64((aOrbiterE * 4832495563863469353U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1856422419049390708U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 18214498743831925517U;
            aOrbiterH = RotL64((aOrbiterH * 10744120577560529379U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 18278550878494094923U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 797712062039591797U;
            aOrbiterB = RotL64((aOrbiterB * 7212998747080137625U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 15854849439012341347U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 996882939768167773U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14936703950807908575U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 3005829974130671692U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8793495343509953906U;
            aOrbiterK = RotL64((aOrbiterK * 14065479348374612031U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 29U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 38U) + aOrbiterB) + RotL64(aOrbiterK, 53U)) + aPhaseHWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 42U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 13U)) + aOrbiterH) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 38U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 20994U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19084U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20417U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneB[((aIndex + 22795U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererE + RotL64(aPrevious, 3U)) + 15813325389431304548U;
            aOrbiterJ = (((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 37U)) + 2223874171125403602U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 5510483568496824130U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 24U)) + 15474152493495661876U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 51U)) + 16846339705130829195U) + aPhaseHOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1289670576865739669U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 18017354919647006944U;
            aOrbiterG = RotL64((aOrbiterG * 13103155460891498469U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 8539685539928984921U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 3333721400836704048U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3745286323481400085U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2261560416623815491U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4377786131746816567U;
            aOrbiterI = RotL64((aOrbiterI * 9164777834392621157U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 18047393176583722719U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8184724021940434631U;
            aOrbiterB = RotL64((aOrbiterB * 9800116157750921119U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 10469895939183324807U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14543391765109879223U;
            aOrbiterK = RotL64((aOrbiterK * 4817987697437667225U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 53U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 39U)) + aOrbiterJ);
            aWandererE = aWandererE + ((((RotL64(aIngress, 34U) + RotL64(aOrbiterK, 13U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 5U)) + aOrbiterI) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterG, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 25695U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 30104U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28711U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((aIndex + 32513U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 10U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 252059974543142812U) + aPhaseHOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aIngress, 47U)) + 11690823093681457368U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 10U)) + RotL64(aCarry, 41U)) + 13282189752890971123U;
            aOrbiterC = (((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 27U)) + 9507416294305708435U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aPrevious, 21U)) + 14053038174390776539U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 14605253312318725009U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 18138286582677863671U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10595905899691011321U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8530091235978489988U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 14381731677571170073U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11675896999665768253U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13316413456378978456U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3910529530149320706U;
            aOrbiterC = RotL64((aOrbiterC * 16000139333493588429U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 6302070286831566901U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12324134652758551396U;
            aOrbiterI = RotL64((aOrbiterI * 17136438281540250165U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4773478557638475048U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4031153435446078944U;
            aOrbiterA = RotL64((aOrbiterA * 3876928995240982769U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 29U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterD, 35U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterE, 21U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 56U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 3U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aCross, 37U) + RotL64(aOrbiterD, 13U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 58U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
