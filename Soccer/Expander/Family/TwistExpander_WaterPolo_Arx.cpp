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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCE695AA0E20C3347ULL + 0x9F679417ACEFCAF8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE57DFB35F247A92BULL + 0xB342183C5DC28057ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFA9E53BA54CF9D57ULL + 0x9A1494E5C97D6173ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEB13CCA648329F15ULL + 0xEB027610D852679BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD1AF222C0DC7EEC1ULL + 0xEB6CA8B863EA08ABULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC6342EF7953A3F37ULL + 0xC1AA3390EDD4A27EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB591CE28D0437A33ULL + 0xC221D5C57F3880A8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA845D32D4A6609F1ULL + 0xB26C59DB76B05F58ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD960EDEA14D7F10BULL + 0xA51F2D9BB80F1FD6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDB8109A5BAB5F475ULL + 0xD4CF5603DF4A5D14ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8D658C0973069FB3ULL + 0x93E8A68E6CD37B18ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE0D3D1089543868DULL + 0xBBAD1C988D63D80CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE7379956D8CFC7D7ULL + 0xA2824A649A998776ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE60513AC95F55DBFULL + 0x8757162C59C80B24ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF5FC8AD4DB32B9BBULL + 0xFEDA1A4483464D74ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE8093E7BD6C8B7DBULL + 0xA85133E2BD316903ULL);
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
            aIngress = RotL64(mSource[((aIndex + 4614U)) & S_BLOCK1], 43U) ^ RotL64(pSnow[((aIndex + 382U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 4432U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 677U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 52U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = (aWandererE + RotL64(aPrevious, 50U)) + 8793908991006073956U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 21U)) + 2932916283348441943U;
            aOrbiterC = (aWandererF + RotL64(aCross, 13U)) + 11069042087940968262U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 47U)) + 14369628676782894441U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 29U)) + 8602903272780978282U) + aNonceWordH;
            aOrbiterF = (aWandererJ + RotL64(aCross, 20U)) + 3827036107178568820U;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 53U)) + 8905245209036772489U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (aWandererG + RotL64(aScatter, 43U)) + 13331387530760017893U;
            aOrbiterE = (((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 9880107580289737823U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aIngress, 5U)) + 10199619040626900278U;
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 11U)) + 2466307560891374281U) + aNonceWordF;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13973403407981259448U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2851460278409385243U;
            aOrbiterC = RotL64((aOrbiterC * 11226902976321781743U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10365453393815690776U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2382382358987358791U;
            aOrbiterA = RotL64((aOrbiterA * 481563628980705781U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5058198848163792422U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 10500434740387593487U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 5946747708776079787U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 11289798395177667084U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14327152153231286666U;
            aOrbiterE = RotL64((aOrbiterE * 18155778059595245561U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8065137263811956313U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3865153574847924816U;
            aOrbiterH = RotL64((aOrbiterH * 9495741102667755161U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 18102279969722473375U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 6306428427188742325U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 17826782872351406167U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16953348204663693724U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11950791817032898613U;
            aOrbiterJ = RotL64((aOrbiterJ * 1498946055469611133U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 11980823193543752994U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 17845490308799454871U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16385153013485463791U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 5566398755702887071U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10308378271388889968U;
            aOrbiterB = RotL64((aOrbiterB * 142732084484961281U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6717846700455219260U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 8297225372883997017U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 14102812043481327907U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12249337046267666603U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 8793908991006073956U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 5851229209188473467U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 50U));
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterI, 48U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterF, 21U));
            aWandererC = aWandererC + ((RotL64(aScatter, 40U) + aOrbiterE) + RotL64(aOrbiterI, 3U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 53U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterG, 51U)) + aOrbiterC) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 27U)) + aNonceWordL);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 58U)) + aOrbiterG) + aNonceWordD);
            aWandererD = aWandererD + (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 37U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 10U) + aOrbiterE) + RotL64(aOrbiterA, 11U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterJ, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 58U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 40U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 10002U)) & S_BLOCK1], 27U) ^ RotL64(pSnow[((aIndex + 5792U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7726U)) & S_BLOCK1], 52U) ^ RotL64(mSource[((aIndex + 6064U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 23U)) + (RotL64(aIngress, 41U) ^ RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = (aWandererG + RotL64(aIngress, 29U)) + 5573188770530340913U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 43U)) + 1431772230889897111U;
            aOrbiterK = (aWandererC + RotL64(aCross, 57U)) + 4809192776429682319U;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 22U)) + 5576603692574369341U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (aWandererD + RotL64(aIngress, 5U)) + 2720143226007220386U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 19U)) + 17220328778565331629U;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 9629485808442089423U) + aNonceWordP;
            aOrbiterE = ((aWandererE + RotL64(aCross, 41U)) + 1136998437010390983U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (((aWandererH + RotL64(aScatter, 24U)) + RotL64(aCarry, 51U)) + 11893390497814523841U) + aNonceWordK;
            aOrbiterC = (aWandererK + RotL64(aIngress, 13U)) + 1764986431917532370U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 21U)) + 1741014798007010376U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12221368453236547044U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7694538641172350430U;
            aOrbiterK = RotL64((aOrbiterK * 8439120733670016501U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17472344518811560603U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 3308740700728172984U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15290400462887712083U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9535358833412446771U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11192312491731312451U;
            aOrbiterF = RotL64((aOrbiterF * 17405609148475445743U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14850451970047190039U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11932493299452443256U;
            aOrbiterA = RotL64((aOrbiterA * 7964808728820467795U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5972619895614731870U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17174497535809891690U;
            aOrbiterC = RotL64((aOrbiterC * 15471084511364572533U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17412894714378898351U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14675615208706549810U;
            aOrbiterG = RotL64((aOrbiterG * 7864845089606499769U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16116792108013658523U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 9702262005960966336U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 970452849653781703U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17337264966818542841U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 7004462033775827275U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 11943575980344402681U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17499850384482055438U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 1839357713256560566U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12943750650487416281U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 8144238113917577524U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 888195876227325908U;
            aOrbiterI = RotL64((aOrbiterI * 7941506708630993709U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5081763359501717653U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 5573188770530340913U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 9699901099898698965U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 58U);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterC, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterG, 29U));
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterB, 21U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 50U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aIngress, 12U) + aOrbiterI) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterE, 43U)) + aNonceWordJ);
            aWandererG = aWandererG + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 19U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterE, 23U)) + aWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterI, 41U)) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 56U) + aOrbiterH) + RotL64(aOrbiterJ, 60U)) + aNonceWordM);
            aWandererH = aWandererH + ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterB, 47U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 14688U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 12340U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11960U)) & S_BLOCK1], 41U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 11710U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = ((aWandererC + RotL64(aScatter, 42U)) + 5295352595333316211U) + aOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aIngress, 47U)) + 2341795367042042605U) + aNonceWordO;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 53U)) + 10122175780504033663U;
            aOrbiterE = (aWandererE + RotL64(aCross, 11U)) + 10084612804696198554U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 3U)) + 16470424309851045971U;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 58U)) + RotL64(aCarry, 47U)) + 656016130975227994U) + aNonceWordH;
            aOrbiterF = ((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 15313268829659834317U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 29U)) + 3795220914993923394U;
            aOrbiterC = (aWandererK + RotL64(aCross, 35U)) + 14044442220988813825U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 27U)) + 3804224626734584802U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 21U)) + 7980006306010255693U) + aOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 13746830564584711549U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11852212099729274845U;
            aOrbiterA = RotL64((aOrbiterA * 2164880979318247855U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9083223471018084847U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 13706723820703853346U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 11361854103656219887U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 1713819986642275223U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 1382000168233902914U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3894160765130198157U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4540474625764565485U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1756168174375757220U;
            aOrbiterC = RotL64((aOrbiterC * 12739160208010092017U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1409297070183609309U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6082750101445444357U;
            aOrbiterK = RotL64((aOrbiterK * 17438740230251860935U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1113239890859479202U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10932192439503964363U;
            aOrbiterD = RotL64((aOrbiterD * 5915660289913324281U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3732595033748508428U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5117760372351117286U;
            aOrbiterG = RotL64((aOrbiterG * 2671510075176315761U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 7399968659654088641U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14835608167871904147U;
            aOrbiterE = RotL64((aOrbiterE * 8312521710415756159U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7851355416751467648U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 262169565276199916U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11801419425408657509U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1771847554312299305U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15588805765521695222U;
            aOrbiterJ = RotL64((aOrbiterJ * 8541206691371972017U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6162696602553964144U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5295352595333316211U;
            aOrbiterI = RotL64((aOrbiterI * 8368226841948931873U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 39U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 54U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 35U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 39U)) + aOrbiterA) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 6U) + aOrbiterI) + RotL64(aOrbiterH, 48U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterE, 53U));
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterG, 41U)) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterG, 3U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterJ, 51U)) + aNonceWordN);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterK, 26U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterF, 29U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterF, 43U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 41U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 48U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 34U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17757U)) & S_BLOCK1], 57U) ^ RotL64(pSnow[((aIndex + 16818U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 20989U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(mSource[((S_BLOCK1 - aIndex + 19682U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneB[((aIndex + 19429U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 38U)) ^ (RotL64(aCross, 5U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = ((aWandererF + RotL64(aScatter, 43U)) + 18191288703716505885U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 29U)) + 9824014524910417136U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 57U)) + 11953012029254917548U) + aNonceWordP;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 22U)) + RotL64(aCarry, 23U)) + 6297568011027199089U) + aNonceWordA;
            aOrbiterG = (aWandererG + RotL64(aCross, 11U)) + 2576999400457367975U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 3U)) + 13176139160575558254U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 29U)) + 9978408174563621810U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 14U)) + 16765834875061607142U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aIngress, 35U)) + 16534507305459121344U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 51U)) + 3114710944346151807U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 39U)) + 10240517868726718592U) + aNonceWordE;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10721450637990777883U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 16689590768796583952U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3046344179729901637U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2427422768928450209U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 13495584061816457831U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6670984773768885119U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7058636403765106682U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9897341853944713767U;
            aOrbiterK = RotL64((aOrbiterK * 14286816859999869231U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 17749559755733386064U) + aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12515645083926326659U;
            aOrbiterE = RotL64((aOrbiterE * 6582878478865838245U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2625692458813609962U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10596240255026143019U;
            aOrbiterD = RotL64((aOrbiterD * 11605800195771080135U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12374290338067865540U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1507386663796330249U;
            aOrbiterI = RotL64((aOrbiterI * 1210241080424446087U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9288099549484146726U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 15159312464747000702U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 500055502081347757U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14998608679505446229U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 17625038109437732009U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 14785862243019841689U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10543192232885637211U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 10330547522729618042U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 7635903835474874057U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 5753298214283941201U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15943436872588208065U;
            aOrbiterF = RotL64((aOrbiterF * 17704547766822075741U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5757218926946874970U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 18191288703716505885U;
            aOrbiterJ = RotL64((aOrbiterJ * 2644970408001409575U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 56U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterC, 35U));
            aWandererD = aWandererD + (((RotL64(aCross, 58U) + aOrbiterK) + RotL64(aOrbiterH, 22U)) + aWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterJ, 41U));
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 39U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterI, 51U)) + aNonceWordJ);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 34U) + RotL64(aOrbiterK, 37U)) + aOrbiterA) + aNonceWordF);
            aWandererE = aWandererE + ((((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 51U)) + aNonceWordL);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 5U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 46U)) + aOrbiterF) + aWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterH, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 24U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26898U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((aIndex + 22209U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(pSnow[((aIndex + 26411U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneA[((aIndex + 23256U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21914U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 22442U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aPrevious, 29U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = (((aWandererF + RotL64(aScatter, 56U)) + 13583136155674166402U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (aWandererE + RotL64(aCross, 29U)) + 12830472187484919497U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 53U)) + 18081197909484522509U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 47U)) + 8680634051297891550U;
            aOrbiterF = (((aWandererD + RotL64(aIngress, 24U)) + RotL64(aCarry, 19U)) + 13939998767458656823U) + aNonceWordI;
            aOrbiterE = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 29U)) + 1795730579103692594U;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 27U)) + 17369751719734069999U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 39U)) + 224769585901248068U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 51U)) + 4133547085925268180U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 13U)) + 7022512056309567391U) + aNonceWordL;
            aOrbiterB = (aWandererA + RotL64(aScatter, 41U)) + 10319484359046945495U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 10483878349412282069U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6481381149199985736U;
            aOrbiterG = RotL64((aOrbiterG * 9701719367082506253U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13721077228796934509U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 9704818014314175007U) ^ aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 760445624027740287U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6253040047758584339U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16890211690273641226U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 5622534399866057841U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6216227831265032436U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 2023609047004658739U) ^ aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 3252332895698310147U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 9201669637050388263U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5106927540934338576U;
            aOrbiterA = RotL64((aOrbiterA * 6368134569042291431U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10080368957861445998U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10784789383436485808U;
            aOrbiterC = RotL64((aOrbiterC * 3794918350254445939U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15426339824951793026U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17637144549368340331U;
            aOrbiterH = RotL64((aOrbiterH * 10971293914614704441U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9941300382181962134U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8118046374121322097U;
            aOrbiterK = RotL64((aOrbiterK * 8481945819050983127U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5138086185042567633U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7279942739248982986U;
            aOrbiterJ = RotL64((aOrbiterJ * 12911998308338410917U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12135610639038562853U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12945353426409788798U;
            aOrbiterE = RotL64((aOrbiterE * 7434977715954413699U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7534876598022096222U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 13583136155674166402U;
            aOrbiterB = RotL64((aOrbiterB * 8194058098043157015U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 46U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 11U)) + aOrbiterE) + aNonceWordN);
            aWandererC = aWandererC + ((RotL64(aCross, 39U) + RotL64(aOrbiterA, 39U)) + aOrbiterC);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 34U)) + aOrbiterK) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 21U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterG, 51U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 27U)) + aOrbiterC) + aNonceWordF);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE) + aNonceWordM);
            aWandererI = aWandererI + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 43U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterB, 58U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererH, 22U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29748U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 30276U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 28846U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30111U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 32636U)) & S_BLOCK1], 54U));
            aCross ^= (RotL64(pSnow[((S_BLOCK1 - aIndex + 28495U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28673U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 39U)) + (RotL64(aIngress, 60U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = ((aWandererJ + RotL64(aCross, 60U)) + RotL64(aCarry, 11U)) + 7270044678408187242U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 10192278965379756766U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 19U)) + 17568666746676060748U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 14312927531124963037U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 37U)) + 9825825726152087706U;
            aOrbiterB = (aWandererA + RotL64(aCross, 28U)) + 9696778570255265896U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 57U)) + 17657841352013417228U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aScatter, 21U)) + 16207815085909628439U) + aNonceWordE;
            aOrbiterD = ((aWandererK + RotL64(aCross, 5U)) + 1752979206374514227U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aScatter, 3U)) + 10456310689643905854U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 47U)) + 16127830548663742550U) + aNonceWordK;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2940917376003930842U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7353596864777649953U;
            aOrbiterI = RotL64((aOrbiterI * 7499468723171042005U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12725092740446150705U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5791296650856037010U;
            aOrbiterC = RotL64((aOrbiterC * 760379251950502133U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1200130368046206150U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16689604428598558547U;
            aOrbiterJ = RotL64((aOrbiterJ * 13815324235939996623U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 14359561591103730856U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3975025843599045263U;
            aOrbiterB = RotL64((aOrbiterB * 5025047888533298617U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 14017901732955607601U) + aNonceWordA;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 10431526786489555196U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10181915874476132407U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 7320527073559849223U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15333411223710709907U;
            aOrbiterG = RotL64((aOrbiterG * 3488684905528068775U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14302474063321663801U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 2104154521019935187U;
            aOrbiterD = RotL64((aOrbiterD * 12944382959742278055U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5167600586916325228U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4566823109447208716U;
            aOrbiterA = RotL64((aOrbiterA * 9997799807454267443U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12475580453805083495U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 15461491763911887974U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 13548865386159287481U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11000532703581114393U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7815822789941347770U;
            aOrbiterK = RotL64((aOrbiterK * 1476638214324946775U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 2166336159928211562U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7270044678408187242U;
            aOrbiterE = RotL64((aOrbiterE * 10648564933168714815U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 26U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 50U) + aOrbiterE) + RotL64(aOrbiterA, 37U)) + aNonceWordC);
            aWandererC = aWandererC + ((((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterJ, 52U)) + aNonceWordP) + aWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 39U)) + aOrbiterI) + aNonceWordF);
            aWandererG = aWandererG + ((RotL64(aCross, 39U) + RotL64(aOrbiterK, 19U)) + aOrbiterI);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 34U) + aOrbiterK) + RotL64(aOrbiterG, 11U)) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 54U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterD, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 41U)) + aOrbiterI) + aNonceWordD);
            aWandererH = aWandererH + (((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterH, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 20U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 10U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEEACFD76FAB1D199ULL + 0xA0157048EA589383ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCC99EF9AE1CD543FULL + 0x9678719745E39E8DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC0FF86E787780327ULL + 0xD6884275C67C8617ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF7338D6EF0EBEB23ULL + 0xC61CD22E4482DC71ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB6FB31C1C23BD1FBULL + 0xDA2956121744BEB5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFB8187FB20AE60D9ULL + 0x8296A7D6AF7F4A85ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8BC7CA606F950C15ULL + 0xCCE52A44B709C0A5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x956D2DBAFB62388BULL + 0xE8846E48811AD724ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBB084F969AFDF641ULL + 0xBDB9854954038BADULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8C3635B11C6257ABULL + 0xB7D186D374B796F3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8D084BEB8B0E864BULL + 0xDFDEC186166A2BC3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9CAF6F31A4D51039ULL + 0xD08E4BD6304492A2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xFC2892F548CAC185ULL + 0xCF5D1802A4F51813ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB66DDEA85FC6E521ULL + 0x906FD497C0A1531EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x94F16AC451FCF7FDULL + 0x9C2AC2066BD84842ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB4464D75DC25ECCBULL + 0x9CC2889AD2AB4B31ULL);
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
            aIngress = RotL64(aExpandLaneA[((aIndex + 4277U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 444U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3698U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3838U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 21U)) + (RotL64(aIngress, 34U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterG = (((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 21U)) + 5131645209694953015U) + aNonceWordM;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 24U)) + 12070391048835379854U) + aNonceWordI;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 2604295836242338724U) + aNonceWordP;
            aOrbiterB = (aWandererH + RotL64(aScatter, 19U)) + 14042039029284001596U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 39U)) + 8914654543854559327U;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 2185619407969359869U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aScatter, 57U)) + 5187406295103352574U;
            aOrbiterF = (((aWandererA + RotL64(aCross, 48U)) + 8022832481290871217U) + aOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 35U)) + 8783061916740573472U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10711028365596196301U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 13387065038269133571U;
            aOrbiterK = RotL64((aOrbiterK * 12444578026365205255U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11187001318931801582U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14191473173276034019U;
            aOrbiterE = RotL64((aOrbiterE * 2491253922434756431U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16207761776716426435U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9677408414452078760U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5487303383095129949U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 17812460332794370649U) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7736423148554132028U;
            aOrbiterC = RotL64((aOrbiterC * 15588733747232852555U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 17293203944059014763U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13487243633338010243U;
            aOrbiterD = RotL64((aOrbiterD * 9468688858740539095U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15979293016815060755U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17645215484691359547U;
            aOrbiterJ = RotL64((aOrbiterJ * 1449450767288733995U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11635961468586927692U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10530136578329059784U;
            aOrbiterF = RotL64((aOrbiterF * 8785021493374398437U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4900370530116992731U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 15952900504821599445U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 5413316082800365261U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9938000151832814778U) + aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 14170277411106520726U) ^ aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5058343552974910737U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 54U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterC, 13U)) + aNonceWordA);
            aWandererK = aWandererK + ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterE, 29U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterC, 53U));
            aWandererH = aWandererH + (((RotL64(aCross, 30U) + aOrbiterJ) + RotL64(aOrbiterD, 20U)) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterF, 43U)) + aNonceWordG) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 5U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 37U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aNonceWordH);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterK, 24U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererF, 20U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 5724U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 6146U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8723U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7624U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8800U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 41U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = (aWandererI + RotL64(aPrevious, 43U)) + 8020711767807230555U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 39U)) + 15368693777246341570U) + aNonceWordN;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 47U)) + 5117523734225562401U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 58U)) + 13155269151097507808U) + aOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 9879303753623578272U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 19U)) + 1165799257173794826U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 11U)) + 930641942062732091U) + aOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aIngress, 52U)) + RotL64(aCarry, 13U)) + 11330571332221123153U;
            aOrbiterI = (((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 2862963158282518899U) + aNonceWordM;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6019186399361476659U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 1924419843785161958U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 9485557122500346869U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12618629043591380461U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9334176504266512405U;
            aOrbiterB = RotL64((aOrbiterB * 18239109235362925739U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16829692481030013551U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5604784396927022709U;
            aOrbiterG = RotL64((aOrbiterG * 2833893610883508353U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 16124030106598549644U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16571659812830230677U;
            aOrbiterH = RotL64((aOrbiterH * 4668250364992383549U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15171089673591843703U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 2826755560293849328U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9397017963457655287U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9976785768283589291U) + aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11845100564714691809U;
            aOrbiterA = RotL64((aOrbiterA * 4935139932585319251U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 7318560453127859950U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3039196878830506712U;
            aOrbiterD = RotL64((aOrbiterD * 3140508261330698717U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8850992055588337843U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4219373528176869146U;
            aOrbiterK = RotL64((aOrbiterK * 1310964742529956743U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1341474458715938799U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 15937557372891732898U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 11437307017920192915U), 39U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 51U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 54U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 19U) + RotL64(aOrbiterD, 3U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 58U) + aOrbiterG) + RotL64(aOrbiterI, 60U));
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 19U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 47U)) + aOrbiterC) + aNonceWordK);
            aWandererG = aWandererG + ((((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 53U)) + aNonceWordP);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterI, 13U)) + aNonceWordI);
            aWandererK = aWandererK + ((RotL64(aIngress, 34U) + RotL64(aOrbiterA, 51U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 42U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterJ, 27U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 10U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 12319U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 15013U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 12830U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12520U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15329U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 12U) + RotL64(aCross, 39U)) ^ (RotL64(aIngress, 27U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 60U)) + RotL64(aCarry, 19U)) + 16189787374324972735U) + aNonceWordK;
            aOrbiterI = (aWandererK + RotL64(aIngress, 27U)) + 17563763730956242224U;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 10572803498593789385U) + aNonceWordN;
            aOrbiterG = (aWandererD + RotL64(aCross, 23U)) + 7713105232072974166U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 51U)) + 10760839534772718139U) + aNonceWordJ;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 47U)) + 13397069448391230253U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aPrevious, 3U)) + 4569255679998375682U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 11U)) + 9888769350817876949U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (((aWandererF + RotL64(aIngress, 36U)) + RotL64(aCarry, 11U)) + 11351796060878856300U) + aNonceWordB;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 18153775071965707204U) + aNonceWordP;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 1282846411145853435U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 12294455920906257823U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 16457743979262460660U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 173493260775251032U;
            aOrbiterB = RotL64((aOrbiterB * 4935807229040883505U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3927345926316409630U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5158769729850853623U;
            aOrbiterI = RotL64((aOrbiterI * 2446452358663812945U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12331351600010165154U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3940794200348684050U;
            aOrbiterJ = RotL64((aOrbiterJ * 13248997263062075043U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11248514843822945425U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 1391497323278226522U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8376841806072565005U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 13265623528678787307U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 2802033745265647317U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3437626962562016147U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6938444301018051844U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 1086544666755559028U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 16039728388882079889U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16156443117365816536U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3619942859562697142U;
            aOrbiterG = RotL64((aOrbiterG * 7589346043159112151U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17681848914912743292U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8848238631758130416U;
            aOrbiterA = RotL64((aOrbiterA * 810402256099500607U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 51U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 18U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 51U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterB, 6U)) + aNonceWordM) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 47U)) + aOrbiterA) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterG, 39U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 28U) + RotL64(aOrbiterE, 29U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterA, 22U)) + RotL64(aCarry, 19U)) + aNonceWordF);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 24U) + aOrbiterJ) + RotL64(aOrbiterK, 57U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 54U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18075U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 19831U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 20015U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19912U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneD[((aIndex + 19771U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aPrevious, 36U)) ^ (RotL64(aCross, 21U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = (((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 3339283916456813609U) + aOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 12U)) + 11339086426180649584U;
            aOrbiterH = (((aWandererC + RotL64(aCross, 21U)) + 16819191669329316585U) + aOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (aWandererG + RotL64(aScatter, 5U)) + 8361916937762630725U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 35U)) + 18031328374429899857U) + aNonceWordF;
            aOrbiterG = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 18261756894092897276U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 42U)) + RotL64(aCarry, 3U)) + 4250319792907645666U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 53U)) + 1492411503643460886U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 57U)) + 17369549067879344180U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7301713524358676722U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2985193736033012535U;
            aOrbiterH = RotL64((aOrbiterH * 7473297294949338265U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14086975808140927408U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 10390516547834639800U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 11441293212275890819U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 18205555540941493267U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 16967799565443938873U;
            aOrbiterF = RotL64((aOrbiterF * 3009081009044782443U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9209505304067579944U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3522631966146762306U;
            aOrbiterJ = RotL64((aOrbiterJ * 3441982898533162599U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 8811497120829041188U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 14707301680850257294U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 11383709499376464085U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10080595991787801029U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6822892187784299166U;
            aOrbiterA = RotL64((aOrbiterA * 7417016898027778287U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1981637172055758689U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16463077485583119324U;
            aOrbiterC = RotL64((aOrbiterC * 2876782050665869121U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 8383837717361569465U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2788511294985017326U;
            aOrbiterI = RotL64((aOrbiterI * 2809163242875130677U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 3529607472855930041U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8850940802020173766U;
            aOrbiterB = RotL64((aOrbiterB * 7821450253655655943U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 6U));
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterA, 13U)) + aNonceWordL) + aWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 54U) + aOrbiterA) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterF, 30U));
            aWandererC = aWandererC + ((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterC, 41U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterD, 51U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterI, 19U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 23U)) + aOrbiterI) + aNonceWordC);
            aWandererG = aWandererG + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 47U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterG, 34U)) + aOrbiterA) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 20U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aOperationLaneB[((aIndex + 24921U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25102U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24788U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23254U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 6U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 23U)) + 1393781663398437180U) + aOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aCross, 60U)) + 17414594746688585273U) + aNonceWordJ;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 2823888497053071250U) + aNonceWordD;
            aOrbiterC = (aWandererC + RotL64(aIngress, 3U)) + 17032631958617884859U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 37U)) + 15222697630461125019U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 56U)) + 15737414920751551780U) + aNonceWordC;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 1357196111055783001U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 43U)) + 5315122321649251691U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aScatter, 27U)) + 7893744655508595974U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 16721939414324611738U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3444375866323610848U;
            aOrbiterH = RotL64((aOrbiterH * 10874157227815775661U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1825716513674511632U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 15582066843912467318U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12765146555943757373U), 57U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 15673590949193923915U) + aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 13887365046280406413U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 3169061375011420121U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12730414371734709356U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4819112390640821927U;
            aOrbiterC = RotL64((aOrbiterC * 8782547948627685451U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3089925954422937464U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7180179304678622530U;
            aOrbiterB = RotL64((aOrbiterB * 16118051565147747413U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17030269962085008657U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 6675917351883004046U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14134335325316949687U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12572022803491077491U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2801421744689267375U;
            aOrbiterA = RotL64((aOrbiterA * 315045745990934023U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4335148696780313055U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 12526298573395110141U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 11276803410698178607U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6984239833558496091U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 12195433952105336808U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8642600547427664495U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 37U);
            aIngress = aIngress + (RotL64(aOrbiterF, 18U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 6U) + aOrbiterF) + RotL64(aOrbiterG, 23U)) + aNonceWordI);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterE, 34U)) + RotL64(aCarry, 3U)) + aNonceWordH);
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterG, 19U));
            aWandererC = aWandererC + (((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 5U)) + aOrbiterB) + aNonceWordM);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 34U) + aOrbiterB) + RotL64(aOrbiterG, 47U)) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 11U)) + aOrbiterE) + aNonceWordL) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 43U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterE, 30U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 38U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aOperationLaneC[((aIndex + 27500U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 30468U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31354U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27835U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 52U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterE = ((aWandererE + RotL64(aCross, 13U)) + 4622023259121087483U) + aNonceWordN;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 23U)) + 10253505250223501352U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 35U)) + 17133877904420462669U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 19U)) + 6162827793741796700U) + aNonceWordI;
            aOrbiterA = ((((aWandererG + RotL64(aPrevious, 6U)) + RotL64(aCarry, 21U)) + 9610986424765907615U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = (aWandererA + RotL64(aIngress, 39U)) + 11210747154264753754U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 57U)) + 16554205219580654546U;
            aOrbiterB = (((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 10352576357413766388U) + aOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (((aWandererK + RotL64(aIngress, 30U)) + RotL64(aCarry, 41U)) + 3651845783283479752U) + aNonceWordK;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 18145542190463500476U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5415609566767162857U;
            aOrbiterJ = RotL64((aOrbiterJ * 6474184559323816389U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2033734872464201570U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3507213117125813345U;
            aOrbiterF = RotL64((aOrbiterF * 5453058336688881113U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8716253393049851856U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 695984869565941856U;
            aOrbiterK = RotL64((aOrbiterK * 8377921610764044735U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 7661578828878284931U) + aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 906654265099155956U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8117625377607536949U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6050049984731254612U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 17882717590338190821U;
            aOrbiterI = RotL64((aOrbiterI * 10807367411402733215U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4996521991532815957U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 4246460672800604436U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12047466401960824903U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 8700148116452518842U) + aNonceWordB;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 10039050281847466206U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11884791271239660157U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 4513844680425845372U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3037563127442815153U;
            aOrbiterC = RotL64((aOrbiterC * 18363509277992292407U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 1005237931570968724U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1373258132025712065U;
            aOrbiterA = RotL64((aOrbiterA * 10458020799382532395U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 23U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 46U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterA, 41U)) + aNonceWordL) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 44U) + RotL64(aOrbiterG, 57U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterA, 53U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterK, 46U)) + RotL64(aCarry, 35U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 21U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 27U)) + aOrbiterJ) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterG, 5U)) + aOrbiterF) + aNonceWordP);
            aWandererF = aWandererF + ((RotL64(aScatter, 48U) + RotL64(aOrbiterA, 37U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 14U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB181BB62D6ABB21BULL + 0xDDAB8FE1D9B7130DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xAE76CB864BA8F041ULL + 0xDC5461D477B35A66ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x97DAA70855FB1B39ULL + 0xBA495C9158B499D0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF407AFB7E1897BCBULL + 0xDB74AF888194B190ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA029005543FF585DULL + 0xD1C18F652EDB8A71ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xAC14C1DF46DC5B17ULL + 0xDCAF61BBDC01D91BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCFE837689C8E5685ULL + 0xFCF1A71BFD56E7BFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCA81884580F5D019ULL + 0xA137A7217C8C97AEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x852D0B63AEA27DC1ULL + 0xC345F2C52CE06169ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB1258E349CCF66DBULL + 0xC5952D2CB8E6D8DDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x83A96BC529B7F8C7ULL + 0xEFB514C59E758628ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD356BD23BE7B27A5ULL + 0x8B9D2DFBEEE6E8C7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x81030FDE6CFC573DULL + 0xFD15F22A720806A8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD43927897D6423B3ULL + 0xBA79891CF105B932ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xCEAD84E690326BFBULL + 0xC02E2367CCD7D612ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBA84FBFF98BCA163ULL + 0x80D45C72FE7605B2ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3822U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneB[((aIndex + 4745U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4396U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7780U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7182U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 6865U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 4U) + RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = (((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 10404808878585437255U) + aNonceWordB;
            aOrbiterB = ((((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 10587858736301591439U) + aOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 58U)) + 1430530909801644435U) + aOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 29U)) + 9090938022430118902U) + aNonceWordM;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 12936604311751121235U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 1000583006020232032U) + aNonceWordF;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 12352532088997042232U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 494418029883239087U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16723410947058502564U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16614089235313154270U;
            aOrbiterI = RotL64((aOrbiterI * 11530998303573027827U), 27U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterI) + 4245553025593349277U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 3353146318549477494U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14246377408238318091U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5935727336135635196U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 10312187090293319667U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1395964500396711899U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 12192843181244744484U) + aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2542570124502586365U;
            aOrbiterA = RotL64((aOrbiterA * 17222847847573534963U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 37U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 5U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 40U)) + aOrbiterI) + aNonceWordL);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 18U) + RotL64(aOrbiterI, 57U)) + aOrbiterB) + aNonceWordH) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11057U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 15242U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 16107U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9177U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9104U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15707U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 11745U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 11U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = (((aWandererB + RotL64(aCross, 21U)) + 9107326720193244489U) + aOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 10868585484401664145U;
            aOrbiterF = ((((aWandererJ + RotL64(aPrevious, 58U)) + RotL64(aCarry, 19U)) + 13637736741437846622U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 37U)) + 6130725216183918844U) + aNonceWordN;
            aOrbiterD = ((aWandererG + RotL64(aCross, 5U)) + 2063834478521338187U) + aNonceWordI;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 8564870627911949158U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6524015751064086390U;
            aOrbiterF = RotL64((aOrbiterF * 12055267995727104463U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9874937766875388236U) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14723718409522680894U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17379140128833323431U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 13767059954741528279U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 6387608251033722169U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 6601902195707980693U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 5391425980008431000U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 11524218415655093779U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 12508457981779189389U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 155510463350385905U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10554591788433641311U;
            aOrbiterI = RotL64((aOrbiterI * 5412084824127934293U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 11U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + aNonceWordC);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 40U) + aOrbiterD) + RotL64(aOrbiterI, 60U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterI, 37U)) + aNonceWordH) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 23U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18650U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 20088U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 18315U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 23945U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23279U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17125U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 20053U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 20U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = ((aWandererA + RotL64(aIngress, 23U)) + 8975885703279267062U) + aNonceWordF;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 37U)) + 8664844915562660637U;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 5U)) + 12281774799736296726U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (((aWandererF + RotL64(aCross, 48U)) + RotL64(aCarry, 3U)) + 15347461352311329726U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 23U)) + 12967500561828907834U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5002833859280402726U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 11908257536954668983U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4384790916151202785U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17017174811949227162U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 16851323125613931180U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 12446990992858763577U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13469326957728686706U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 5228638551056105241U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13369947664646167255U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 11945166198089308564U) + aNonceWordI;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 16268645041872996022U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5391448793718370911U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 14781204627695095701U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5365325354838101092U;
            aOrbiterK = RotL64((aOrbiterK * 8017284997946310807U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 4U) + aOrbiterK) + RotL64(aOrbiterA, 53U)) + aNonceWordP) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterA, 39U));
            aWandererA = aWandererA + (((((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 14U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aNonceWordC) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 5U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 24729U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((aIndex + 30431U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 27377U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26821U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32215U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26351U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 32160U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCross, 23U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 30U)) + RotL64(aCarry, 47U)) + 14499676118633326000U) + aNonceWordN;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 13U)) + 17191273593018552288U) + aNonceWordC;
            aOrbiterD = ((aWandererE + RotL64(aCross, 11U)) + 4085176294948097737U) + aOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 11112671474158908186U) + aNonceWordE;
            aOrbiterB = ((aWandererH + RotL64(aCross, 19U)) + 8745787969012266485U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 18074049663777707948U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 2543758649719164688U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7153845562786344373U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4659584749412700523U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 974639159259871273U;
            aOrbiterB = RotL64((aOrbiterB * 17918719351847605523U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 9211220687971081987U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 8567024626862182714U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 7755874089832496393U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5803002132294840900U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11968489432878148467U;
            aOrbiterG = RotL64((aOrbiterG * 4501441062617123165U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9470807228394903442U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 1692347973120388469U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 17433393164156231575U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 56U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 3U)) + aOrbiterE) + aNonceWordD) + aWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterD, 40U)) + aNonceWordO);
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 10U) + aOrbiterD) + RotL64(aOrbiterE, 21U)) + aNonceWordK);
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 37U)) + aNonceWordM) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 14U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x81553E7922B5A141ULL + 0xCAB0E4A07CEF6893ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC116A2D1855F6B4DULL + 0xD1F5F1A004FE89DDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xDD902435B2AEEA61ULL + 0x90E6840B22CE0380ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xAE5A9CFD48F0D823ULL + 0xD49B527772AA0F78ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8821F3044C5FA90FULL + 0xE031EA6DF61FF33BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF6651A0DE419EC85ULL + 0xE47AFABB6BC655F2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBABF311003894427ULL + 0xC7963779FCD2B424ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xEA2A60DC9F986519ULL + 0xD97C2D4C2CE2D5D0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCA970891B08AD0CFULL + 0xA84BE030F5E7D204ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA06F4DEF39CA0213ULL + 0xC935382A25BB595DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x860AF721AD8B3DFFULL + 0xC7316A18E42BB63AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF37CD5FE5ECCBD1DULL + 0xC38ABA4AC7B04A0DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x876E7A3BBF28D70BULL + 0x801478EFCA876892ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB7032BC115E665AFULL + 0xB2BD311ED775F8CBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD50CDF0D4635A067ULL + 0xA10E96F97DC71B40ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xAC343E477613B62DULL + 0xE99CB6DF932E1903ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2917U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((aIndex + 7137U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1495U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3242U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6626U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 7161U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 35U)) ^ (RotL64(aIngress, 22U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 39U)) + 10726035965553989335U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 24U)) + RotL64(aCarry, 21U)) + 967354339530195662U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 57U)) + 10834593005478605624U;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 51U)) + 1012888282838656933U) + aOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = ((((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 15283530351725183253U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = (aWandererK + RotL64(aCross, 37U)) + 11724495956731703750U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 43U)) + 4288330117317505776U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 10894778070022873473U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 15563886747621617467U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17884709931569040065U), 41U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 11182488628562891937U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 10420140066310588580U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 13898299782819948719U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 11775138062167543111U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16545391898578161683U;
            aOrbiterB = RotL64((aOrbiterB * 14588306527161321535U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1550144656312299266U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14903504853138279883U;
            aOrbiterG = RotL64((aOrbiterG * 8003033561266164387U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 309935535526750396U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13991265868040011411U;
            aOrbiterK = RotL64((aOrbiterK * 2887531132228588441U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1755976294857114222U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 2259275858478396846U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7416165760067878161U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4838175912944552936U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 12307900457200936013U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 14719363144850838805U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterK, 19U)) + aNonceWordO) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 41U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterJ, 27U)) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterA, 57U)) + aNonceWordE);
            aWandererG = aWandererG ^ (((RotL64(aCross, 4U) + aOrbiterC) + RotL64(aOrbiterB, 35U)) + aNonceWordN);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 4U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterG, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 18U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12668U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneC[((aIndex + 10069U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 15496U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneC[((aIndex + 9854U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15606U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9030U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 10585U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 11U)) + (RotL64(aIngress, 37U) ^ RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = (aWandererH + RotL64(aScatter, 29U)) + 6469584119078165548U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 11U)) + 14329756366517987910U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 53U)) + 12890831797059772123U;
            aOrbiterG = (((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 41U)) + 3164503807500018990U) + aNonceWordD;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 60U)) + 177531431387646836U) + aNonceWordJ;
            aOrbiterJ = ((((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 23U)) + 3167421392893561015U) + aOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = ((((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 2813174781844753460U) + aOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10953270419153249857U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 16911518309710356951U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13162785997686570445U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6616750447844893150U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10276741398025985982U;
            aOrbiterD = RotL64((aOrbiterD * 6824712685896987133U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 6206043608461213208U) + aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12021552904553405793U;
            aOrbiterH = RotL64((aOrbiterH * 10023362889960174909U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15283586234744144846U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 5923238786775948571U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8200882393521882651U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11044014510971660078U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9351141024085076044U;
            aOrbiterG = RotL64((aOrbiterG * 13316079344614432317U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 17703395981862992420U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10154548848376027087U;
            aOrbiterB = RotL64((aOrbiterB * 12324478347590509035U), 19U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 8836420852291617425U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10193385413543886344U;
            aOrbiterJ = RotL64((aOrbiterJ * 824935982418585449U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 12U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterG, 13U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 35U)) + aNonceWordG);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 5U)) + aOrbiterC) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 27U)) + aOrbiterK) + RotL64(aCarry, 13U)) + aNonceWordI);
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 47U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aScatter, 60U) + RotL64(aOrbiterH, 41U)) + aOrbiterB);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterB, 34U)) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18230U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 22778U)) & S_BLOCK1], 20U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 22872U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 19409U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18090U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17533U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23260U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 53U)) + (RotL64(aIngress, 3U) ^ RotL64(aCross, 36U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = (((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 9446153639709651566U) + aNonceWordJ;
            aOrbiterK = (aWandererB + RotL64(aIngress, 27U)) + 10550762260670758167U;
            aOrbiterB = (((aWandererJ + RotL64(aCross, 54U)) + RotL64(aCarry, 35U)) + 7062634922142578383U) + aNonceWordB;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 3U)) + 9178499097812764515U) + aNonceWordE;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 19U)) + 6887103379773525538U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 41U)) + 6239750312052010257U) + aNonceWordA;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 17645022614523287959U) + aOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 3639618183259408272U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3131737117548745095U;
            aOrbiterB = RotL64((aOrbiterB * 6585057380704940395U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7253994382396406554U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 15217993711938379561U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17853313384747259923U), 3U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 12594152227603630033U) + aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11250170200489647869U;
            aOrbiterE = RotL64((aOrbiterE * 546800378327864723U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 12936942656624279424U) + aNonceWordC;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 10990736056052106149U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7123916809953459187U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12787293075893090465U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17154990205620778151U;
            aOrbiterJ = RotL64((aOrbiterJ * 10031369940028159521U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 1270827262969060301U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17337623431665013136U;
            aOrbiterK = RotL64((aOrbiterK * 1517262088236356107U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 830330490987911853U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6828309232554560547U;
            aOrbiterG = RotL64((aOrbiterG * 9742464176986145819U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 38U)) + aOrbiterB) + aNonceWordH) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 41U) + RotL64(aOrbiterC, 29U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterH, 23U)) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 34U) + aOrbiterC) + RotL64(aOrbiterG, 3U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterE, 53U)) + aOrbiterK) + aNonceWordO);
            aWandererK = aWandererK + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aNonceWordG);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 13U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererA, 44U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29873U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 26996U)) & S_BLOCK1], 14U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 25054U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 25877U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29629U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28080U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24965U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 40U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 43U)) + 15904465836916519864U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 51U)) + 17725629806317789307U) + aNonceWordF;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 21U)) + 13794170125914914828U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 2149055907476874332U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 5342047776745074649U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 34U)) + 8268148484060546838U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 10821151364028563719U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 4294213820894407378U) + aNonceWordO;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 10884726101307943090U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1116128870387229159U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16432210042202444824U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15196602644336228055U;
            aOrbiterA = RotL64((aOrbiterA * 12680438355124070237U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 14117787670220328165U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 219833877949480215U;
            aOrbiterF = RotL64((aOrbiterF * 10736293047771972173U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3326396981881473962U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 14918513066311426279U) ^ aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14269763278564574663U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 11795234681370163206U) + aNonceWordG;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 3068267285352664813U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15746255933920904619U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 245233356957999496U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 709926406353796673U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 13627039596842073595U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 5378105439430271038U) + aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10114555061122044430U;
            aOrbiterE = RotL64((aOrbiterE * 5351295043424885549U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 28U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 29U) + RotL64(aOrbiterC, 29U)) + aOrbiterG) + aNonceWordK) + aWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterA, 43U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 4U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aNonceWordE);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterE, 51U)) + aNonceWordD);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 13U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((((RotL64(aCross, 60U) + RotL64(aOrbiterB, 19U)) + aOrbiterE) + aNonceWordN) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 37U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB4D6F8AACE3841B5ULL + 0xAE9D3115D1CD369AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEFCAEFC20F5598ABULL + 0xC7A44B205C83E5B2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF74E87E95EAD35DBULL + 0xC2D2790B16CE725CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC594710406FA3491ULL + 0xE506FC4B4ED95794ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA1FACECD2441FB5DULL + 0xE2536EFBBE692B9CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xAA95C3C58216FC03ULL + 0x98A6A655814F84B9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9FDEDB1EF5BD4E53ULL + 0x97F2CF96BCC808A7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xAB75D5489BF1D279ULL + 0x92861F24987AB331ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD8B9DF6112AC80AFULL + 0x86984D8A8D25EB70ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDA9B0E87790C880FULL + 0xEF7255EEEDAE25EBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE3F2A3E445A0E8C1ULL + 0xD286CBDF87773523ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9108A9DE626AADBBULL + 0xD2542B20B89DA882ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8A80BD8E70D05BEFULL + 0xCAB8FB26F0353492ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE4ABFC42F8D83AC7ULL + 0x88973134993CE8B3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x80A5C6115A2E5E8DULL + 0xBCFB65924CAADD4DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9E9D7E2A5459F4BDULL + 0xB5AE65EA8B3DC418ULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 3228U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 2695U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5089U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 173U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 946U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 44U) ^ RotL64(aIngress, 29U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterC = (((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 10881271196314989997U) + aNonceWordP;
            aOrbiterH = (((aWandererB + RotL64(aIngress, 19U)) + 6406461249988567558U) + aOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 27U)) + 17255067918280095959U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aCross, 5U)) + 16690850682497718411U) + aNonceWordK;
            aOrbiterG = (aWandererF + RotL64(aScatter, 29U)) + 5576201059361086866U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 54U)) + RotL64(aCarry, 41U)) + 11991259685693687554U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 11U)) + 14652535244217836909U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 1701789037170782122U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 953429054903473833U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13482379459700651427U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 12064513610469714211U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7993881398822002424U;
            aOrbiterG = RotL64((aOrbiterG * 11572884842788918377U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14421313768013320050U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 11112386845630998889U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 11771526352030371669U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 17069630896535699015U) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3308240081138623373U;
            aOrbiterE = RotL64((aOrbiterE * 10449509484417835159U), 27U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 17615529807112933619U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11782807146851563541U;
            aOrbiterF = RotL64((aOrbiterF * 12992075832343669221U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14401645829607611983U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6736397344219993532U;
            aOrbiterK = RotL64((aOrbiterK * 1667287547938175641U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6446974060524700550U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 7840991992443308254U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 6891023544882740107U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 50U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterI, 57U));
            aWandererE = aWandererE + ((((RotL64(aCross, 34U) + RotL64(aOrbiterF, 36U)) + aOrbiterE) + RotL64(aCarry, 35U)) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterC, 27U)) + aNonceWordE);
            aWandererF = aWandererF + (((((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 53U)) + aNonceWordC) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 47U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + RotL64(aOrbiterH, 5U)) + aOrbiterE) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 13U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 20U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 6229U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((aIndex + 9489U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10498U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6623U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7424U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8961U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 37U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = (aWandererI + RotL64(aScatter, 27U)) + 12426357877879529292U;
            aOrbiterH = (((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 12604900366173639176U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 13511119007338929401U) + aNonceWordK;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 11U)) + 9878720081166788060U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 4U)) + RotL64(aCarry, 3U)) + 15463195409806395076U) + aNonceWordE;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 19U)) + 6407922778852833423U) + aNonceWordN;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 51U)) + 7690427254160734016U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 18030974031722143619U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17983938038322737041U;
            aOrbiterC = RotL64((aOrbiterC * 12479365337221685413U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16605512170117753884U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 681802273302348322U;
            aOrbiterH = RotL64((aOrbiterH * 14608920184802647123U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 15550312921312083819U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17824154101711884508U;
            aOrbiterD = RotL64((aOrbiterD * 7358612830654795357U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 1939207786756735430U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3132864634777826569U;
            aOrbiterK = RotL64((aOrbiterK * 13606281919426730325U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12822929773923954849U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 16576106045887115660U) ^ aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 16370914370769903051U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 2398825881649235260U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 13700821892926092479U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 10830623703416956043U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 2439833784883391606U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15870638514107637833U;
            aOrbiterJ = RotL64((aOrbiterJ * 3797380922767479287U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 39U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 58U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 14U)) + aOrbiterH) + aNonceWordD);
            aWandererI = aWandererI + ((((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterI, 3U)) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 58U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 37U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 21U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 51U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 34U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 14465U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 15601U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14865U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13304U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneA[((aIndex + 12663U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 44U) ^ RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 10915618884692072446U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 47U)) + 12634922308499254909U) + aNonceWordI;
            aOrbiterK = ((((aWandererF + RotL64(aIngress, 54U)) + RotL64(aCarry, 19U)) + 6533934734564499389U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 6744203303756105181U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aPrevious, 27U)) + 13086782386652045658U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 5U)) + 5693840533331397822U;
            aOrbiterC = (aWandererI + RotL64(aCross, 21U)) + 1803663542535024611U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3597219300593287708U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1429753448204448904U;
            aOrbiterK = RotL64((aOrbiterK * 10927459251773273143U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17229017825587322715U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 1137574712801062932U) ^ aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 3645832160939819415U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 2401991077004083378U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1332473247826139292U;
            aOrbiterF = RotL64((aOrbiterF * 15029831858261506447U), 19U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 11730946340796899885U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15319163439700390962U;
            aOrbiterJ = RotL64((aOrbiterJ * 1349242001887975499U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4744141870145159917U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6067132201862688684U;
            aOrbiterC = RotL64((aOrbiterC * 6046100687757836027U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 14991509179286371800U) + aNonceWordH;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 4342608825699398682U) ^ aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10240526103933275875U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3727521409410742075U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 3302027219498304367U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 12153634588200479559U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 13U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterF, 10U)) + RotL64(aCarry, 41U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB) + aNonceWordP) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterK, 29U)) + aNonceWordL);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 21U)) + aOrbiterC) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 34U) + aOrbiterK) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20999U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 20084U)) & S_BLOCK1], 42U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16680U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18947U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((aIndex + 20833U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 35U)) + 13442819395490639310U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 8187292523194120936U;
            aOrbiterF = ((((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 27U)) + 11469697159823131388U) + aOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 13414083692375929653U) + aNonceWordJ;
            aOrbiterD = (aWandererJ + RotL64(aCross, 19U)) + 11404010733687907517U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 29U)) + 6783212827186218247U) + aNonceWordD;
            aOrbiterA = (aWandererG + RotL64(aIngress, 51U)) + 8561131439340372614U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 6252609642004429113U) + aNonceWordM;
            aOrbiterF = (((aOrbiterF ^ aOrbiterK) ^ 12804867444200448952U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 3114688959081972615U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2739648749603690781U) + aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14808861217017399752U;
            aOrbiterJ = RotL64((aOrbiterJ * 373911885694012101U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17588866502571268888U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5882260142735642980U;
            aOrbiterA = RotL64((aOrbiterA * 7688252946143263869U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 15493099088132862949U) + aNonceWordG;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 5175647411532429582U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15226544495598541883U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14279707376173642767U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6826363572161275158U;
            aOrbiterK = RotL64((aOrbiterK * 5263708315440161809U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13267185753040999992U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 9980987858092888720U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13210290848800728635U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3582972937645514549U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10140409019562890804U;
            aOrbiterB = RotL64((aOrbiterB * 6944490201647678479U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 30U);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterA, 29U)) + aNonceWordK) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterC, 5U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 18U) + aOrbiterD) + RotL64(aOrbiterK, 57U)) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 50U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 21U)) + aOrbiterF);
            aWandererK = aWandererK + ((((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 53U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 43U)) + aOrbiterD) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 28U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneB[((aIndex + 26747U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneB[((aIndex + 26492U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22844U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((aIndex + 24601U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 21U)) + (RotL64(aCarry, 42U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 10812151398716051703U) + aNonceWordH;
            aOrbiterD = ((aWandererF + RotL64(aCross, 41U)) + 18202551453336003710U) + aNonceWordO;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 28U)) + 9434410809101973752U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 12955829998028534045U) + aNonceWordJ;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 19U)) + 12271740641929640181U) + aOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aScatter, 51U)) + 14009351527014534752U;
            aOrbiterF = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 4316296955679133450U) + aOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 16473324966997442872U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15735123324965019802U;
            aOrbiterG = RotL64((aOrbiterG * 5624078184997601019U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17656375090484080236U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16066325053456055298U;
            aOrbiterK = RotL64((aOrbiterK * 17912970706985130327U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 12908968778503516903U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 12761433987676836197U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 1023329467480907925U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 12737513138040664509U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14535795767570998392U;
            aOrbiterD = RotL64((aOrbiterD * 15560519667062222269U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14370908061811284364U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7001358781208669795U;
            aOrbiterJ = RotL64((aOrbiterJ * 11641248025734015835U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 7298578161120090849U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 10498302152357484629U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13144110412179037175U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 11447343228638006767U) + aNonceWordK;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 18284143620422655675U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 572862190073605651U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 41U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 4U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterF, 3U)) + aWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterJ, 34U)) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 11U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 51U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 41U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aNonceWordN);
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 57U)) + aOrbiterF) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 44U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31278U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28021U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32168U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30465U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aIngress, 41U)) + (RotL64(aPrevious, 12U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 3U)) + 9914837590440975587U) + aNonceWordK;
            aOrbiterB = (aWandererK + RotL64(aScatter, 21U)) + 6706125076401958051U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 51U)) + 16570817772679258409U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 6843705658115186948U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 37U)) + 16099930446791572351U;
            aOrbiterA = ((((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 5420550009556030459U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 14U)) + RotL64(aCarry, 23U)) + 5729549069420177477U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 15590601126188675834U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13044027390998620029U;
            aOrbiterK = RotL64((aOrbiterK * 16845199115313444123U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11068338135659636772U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6584988841809544332U;
            aOrbiterG = RotL64((aOrbiterG * 1683336180438945439U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 8516813219883915404U) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10647314042912492785U;
            aOrbiterC = RotL64((aOrbiterC * 15559481057047148785U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 201691689889605304U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15512161798401184003U;
            aOrbiterF = RotL64((aOrbiterF * 11473219183982564709U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 3883760518944464145U) + aNonceWordD;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 13861805129175491145U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17194438894492581181U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 12019138626550801486U) + aNonceWordB;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 13030350224959652248U) ^ aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11724200983306280107U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 2643807255422544248U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4127143302485631794U;
            aOrbiterB = RotL64((aOrbiterB * 5441038881111578487U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 11U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterA, 35U));
            aWandererA = aWandererA + (((RotL64(aCross, 41U) + RotL64(aOrbiterK, 57U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 13U)) + aOrbiterG) + aNonceWordN) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 60U) + RotL64(aOrbiterB, 21U)) + aOrbiterF) + aNonceWordL);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 3U)) + aOrbiterC) + aNonceWordA);
            aWandererB = aWandererB + ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 50U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 28U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF31C13BD5F6E53F3ULL + 0xFDE0A44BF0043874ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x84ADF6A0ACE82431ULL + 0xA4A364569F4BDFEFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD3BC31C5B8ECB5A9ULL + 0x8BA0E9BECF6CC3D0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD3A108FDCCBE621BULL + 0x8BEA127F03AA8474ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE772102BC57B0CBBULL + 0x995EAF41029AD807ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF82A52B405E496C7ULL + 0x9FFB3648D2FE1420ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8A34E77C16734717ULL + 0xCDCC73E83A238BD4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB30343ACF561619BULL + 0xFCC0BE2599918733ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA21AE53FCFCD3799ULL + 0xB190A37D221A989FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xFCCBDAD881A11A57ULL + 0xCBC1DF46712F25A9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB9F603619D4DFF79ULL + 0xB0E26E83E30644AFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE5CE4018A7A2B623ULL + 0xBAAB29D932F2BB55ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA2C04197DF612C91ULL + 0xD7E49B0A4120BF69ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x936D7796E0889CBDULL + 0xBC7CF77234C52151ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBA29C7AAE166CCFFULL + 0xF0B3A7C35DB37C28ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x8E984A3E2856C0F1ULL + 0xC0C7C310304BE0DAULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5351U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 2647U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 7611U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 709U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7263U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 5771U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 24U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = ((aWandererE + RotL64(aScatter, 39U)) + 8020711767807230555U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 13U)) + 15368693777246341570U) + aNonceWordC;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 43U)) + 5117523734225562401U;
            aOrbiterI = (aWandererH + RotL64(aCross, 54U)) + 13155269151097507808U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 21U)) + 9879303753623578272U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 19U)) + 1165799257173794826U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aPrevious, 3U)) + 930641942062732091U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 60U)) + RotL64(aCarry, 5U)) + 11330571332221123153U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 2862963158282518899U) + aNonceWordM;
            aOrbiterD = ((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 19U)) + 6019186399361476659U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 5U)) + 1924419843785161958U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12618629043591380461U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9334176504266512405U;
            aOrbiterJ = RotL64((aOrbiterJ * 18239109235362925739U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16829692481030013551U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5604784396927022709U;
            aOrbiterG = RotL64((aOrbiterG * 2833893610883508353U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 16124030106598549644U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16571659812830230677U;
            aOrbiterK = RotL64((aOrbiterK * 4668250364992383549U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15171089673591843703U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 2826755560293849328U) ^ aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9397017963457655287U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9976785768283589291U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 11845100564714691809U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 4935139932585319251U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7318560453127859950U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3039196878830506712U;
            aOrbiterE = RotL64((aOrbiterE * 3140508261330698717U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8850992055588337843U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4219373528176869146U;
            aOrbiterA = RotL64((aOrbiterA * 1310964742529956743U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 1341474458715938799U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15937557372891732898U;
            aOrbiterF = RotL64((aOrbiterF * 11437307017920192915U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 7512741986101399499U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 4304636545688233645U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 1948671766238131953U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11460886069492094055U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2019818350627642126U;
            aOrbiterC = RotL64((aOrbiterC * 9802784763505584769U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3190374588085859096U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8020711767807230555U;
            aOrbiterB = RotL64((aOrbiterB * 12055760672321414929U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 39U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 38U) + aOrbiterD) + RotL64(aOrbiterH, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 47U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 44U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH) + aNonceWordH);
            aWandererI = aWandererI + ((((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterK, 11U)) + aNonceWordL);
            aWandererK = aWandererK + ((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 53U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 26U)) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 3U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 29U)) + aOrbiterF) + aNonceWordK);
            aWandererE = aWandererE + (((RotL64(aCross, 34U) + aOrbiterA) + RotL64(aOrbiterD, 51U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererD, 10U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16247U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 14878U)) & S_BLOCK1], 52U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 10863U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneC[((aIndex + 11590U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15789U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8800U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 11901U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 39U) + RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = (aWandererC + RotL64(aIngress, 21U)) + 1557680213571812384U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 19U)) + 7387349725778021121U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aScatter, 53U)) + 15379264067601586976U) + aNonceWordE;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 3730195724576043708U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aScatter, 56U)) + 9637070085323827066U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 13U)) + 1170865717363676184U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 2750833653175252030U;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 3U)) + 15118992811225568305U) + aNonceWordK;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 24U)) + 4974092922102988451U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 47U)) + 10625719096296719514U) + aNonceWordH;
            aOrbiterJ = (aWandererI + RotL64(aCross, 51U)) + 855167122475471865U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 11322911068958340262U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4334591909425429835U;
            aOrbiterE = RotL64((aOrbiterE * 10059025861172038183U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14263701737208936392U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 678723206735649084U;
            aOrbiterB = RotL64((aOrbiterB * 10823239851733632227U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 15652053114252065230U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1705225940224061401U;
            aOrbiterA = RotL64((aOrbiterA * 3626023093533713579U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6826394665732900206U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11902946775066981141U;
            aOrbiterH = RotL64((aOrbiterH * 18300629262162694137U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 9802212958998591310U) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 14001358545610206524U) ^ aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13172645840788327099U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4299184726135884309U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7288757011999872416U;
            aOrbiterF = RotL64((aOrbiterF * 16806027820468277393U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 233801262480580205U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14208660347238680268U;
            aOrbiterD = RotL64((aOrbiterD * 6299693448313154603U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9217797359740446104U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 18165073197136050838U;
            aOrbiterG = RotL64((aOrbiterG * 11677479094709512887U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9101905235436427482U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2884224555227870272U;
            aOrbiterK = RotL64((aOrbiterK * 12085235281782370391U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 13118509728421714433U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1385390888603164704U;
            aOrbiterI = RotL64((aOrbiterI * 6927424835779289199U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9621084561183039538U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 1557680213571812384U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 3202327770291862207U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 52U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ) + aWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 51U)) + aOrbiterH) + aNonceWordL);
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 53U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 14U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aIngress, 44U) + RotL64(aOrbiterK, 43U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 37U)) + aOrbiterH) + aNonceWordN) + aWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 11U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 35U));
            aWandererH = aWandererH + ((((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterB, 60U)) + RotL64(aCarry, 53U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 22U) + RotL64(aOrbiterC, 3U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 36U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22528U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 22319U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 23140U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16882U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21942U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23924U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17320U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCross, 48U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = (aWandererF + RotL64(aScatter, 37U)) + 17019646486641172469U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 3U)) + 12276141179299971572U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 10U)) + 3617241694029841555U;
            aOrbiterC = (aWandererH + RotL64(aCross, 13U)) + 6967963401259371737U;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 43U)) + 6340709284279891017U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aIngress, 47U)) + 456065368903896482U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aCross, 43U)) + 17686765719908116203U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 53U)) + 1322045955429785736U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 19U)) + 5163772703302372887U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 57U)) + 13268431135020363252U) + aNonceWordN;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 6U)) + RotL64(aCarry, 37U)) + 6538789950366849332U) + aNonceWordJ;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10390344544314544893U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5087084271300584267U;
            aOrbiterG = RotL64((aOrbiterG * 15149302947570776165U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13423071121590981727U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 18324443012024134729U;
            aOrbiterI = RotL64((aOrbiterI * 15814349432207734533U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4129091815978464507U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17024797553831962245U;
            aOrbiterK = RotL64((aOrbiterK * 3137753479364378175U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 6501545108779991661U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11930037791867597447U;
            aOrbiterB = RotL64((aOrbiterB * 4904739567549702851U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4667298703308315851U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6315980380900062127U;
            aOrbiterF = RotL64((aOrbiterF * 12080555704907924637U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 12732382340390769888U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7792095326183864547U;
            aOrbiterD = RotL64((aOrbiterD * 12645556660611824631U), 35U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 17428384983571405782U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3193205313177048443U;
            aOrbiterA = RotL64((aOrbiterA * 14488006565106259731U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2813743367131107264U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2742138679703780981U;
            aOrbiterC = RotL64((aOrbiterC * 18356569025783532225U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6270291142961043031U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 3490174937775044998U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13879285210885619613U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13182535825771438942U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 13047228760732694484U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 10365428317468779549U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 17926326514553542739U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 17019646486641172469U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 13978838314848228053U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 60U);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 58U) + aOrbiterG) + RotL64(aOrbiterJ, 35U)) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 27U)) + aNonceWordL);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterC, 21U));
            aWandererF = aWandererF + ((RotL64(aCross, 41U) + RotL64(aOrbiterI, 3U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 56U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 23U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterH, 13U)) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 44U) + RotL64(aOrbiterJ, 27U)) + aOrbiterE) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterD, 44U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 42U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + RotL64(aWandererH, 34U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28457U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 30603U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 26734U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25632U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26231U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30600U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25277U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 37U)) ^ (RotL64(aCross, 11U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = (aWandererI + RotL64(aScatter, 53U)) + 5041131702736607991U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 13U)) + 9295010428212681446U) + aOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aIngress, 11U)) + 6235875895358766017U;
            aOrbiterG = (aWandererK + RotL64(aCross, 58U)) + 2622227802531866918U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 19U)) + 3888894734834524972U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 5U)) + 241682012014701753U;
            aOrbiterF = (((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 15758000422451568079U) + aNonceWordE;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 50U)) + RotL64(aCarry, 29U)) + 2061944548396976912U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 8177144990755754531U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 47U)) + 554978075608818497U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 29U)) + 250408260560714933U) + aNonceWordH;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8700027645880997552U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 10026130047465480902U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 12417270861933696623U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9785843014096326696U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 9998582683258411251U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 7197956237569462269U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 13817734599383455151U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6647207154174092691U;
            aOrbiterG = RotL64((aOrbiterG * 1578528131687283531U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 4957715980509035719U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 4994885315786213197U;
            aOrbiterF = RotL64((aOrbiterF * 5676683798126497011U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5072908311783966503U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5535039946192891515U;
            aOrbiterJ = RotL64((aOrbiterJ * 2989412783482309753U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6594577050344146271U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8750154123258714856U;
            aOrbiterB = RotL64((aOrbiterB * 6942158167127532003U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 3514769314840874873U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8626045200273524281U;
            aOrbiterK = RotL64((aOrbiterK * 4315441782689789689U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8524870284841706517U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1841819423572964209U;
            aOrbiterA = RotL64((aOrbiterA * 9802481758007234681U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12668382464510772517U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6330331402801670515U;
            aOrbiterC = RotL64((aOrbiterC * 9096920618612750935U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 10346986196055766087U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10932918162471200996U;
            aOrbiterH = RotL64((aOrbiterH * 6863632877625141567U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 6264557195446069146U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5041131702736607991U;
            aOrbiterE = RotL64((aOrbiterE * 4978591546106895045U), 39U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 40U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterB, 27U)) + aNonceWordL);
            aWandererC = aWandererC + ((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterI, 3U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 57U)) + aOrbiterH) + aNonceWordA);
            aWandererE = aWandererE + ((((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterD, 38U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 11U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 53U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterK, 42U)) + aOrbiterG) + aNonceWordB);
            aWandererI = aWandererI + ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterK, 51U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 35U)) + aOrbiterD) + aNonceWordK) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 20U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDD6BB049FC94CF47ULL + 0x8A67D3AB71DDC4DCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC52B85FEB27D0F13ULL + 0xEB3E2109CF9636D8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA274A403A08B70D3ULL + 0xFF2BC0A166A3A04FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x979E20199DB6203FULL + 0x8ACECEA7723EDDD2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEB4774F7E1C9DD69ULL + 0xBAA90C975A589029ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFD2BE81230AC4A37ULL + 0xE1A069F39C707C2DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC214EE029669FCA7ULL + 0xECF537E5C0AD9218ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCA41BB69E35B7231ULL + 0xFD40F1EA50C19A7BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF7078C9F6579C5B9ULL + 0xD9A80D3C1CA05630ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCBADAE015DD3AC0FULL + 0xD0C67BB6C1395623ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8C0C3308F40BEEDBULL + 0xAEE3B37E72A763A0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBA005F119B55FF55ULL + 0x81229111D3753015ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB7821F7B199B9041ULL + 0xBA6F0A3FE2266706ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x85F13872F8A4A7C5ULL + 0xE25FBB03864F823BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xEDF47BCFCFEF4345ULL + 0xD88313C8DAA2703EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF3DA49A188AE328DULL + 0xB8B5BE6CA9DB80F5ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2723U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 5860U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4635U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4345U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7119U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2686U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 56U)) + (RotL64(aPrevious, 23U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = (((aWandererE + RotL64(aScatter, 46U)) + RotL64(aCarry, 13U)) + 16124889768301047791U) + aNonceWordC;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 27U)) + 11912338587186717280U;
            aOrbiterB = (((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 8594012868813114354U) + aNonceWordJ;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 41U)) + 18281043566156682815U) + aNonceWordP;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 16853106130200942302U) + aNonceWordO;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 37U)) + 2611212958619673086U) + aOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aIngress, 53U)) + 18039472325066855180U;
            aOrbiterC = (aWandererK + RotL64(aCross, 3U)) + 14495785571345122046U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 60U)) + 4556063793412832418U) + aOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14896419970271244358U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 880028529183500036U;
            aOrbiterB = RotL64((aOrbiterB * 14228281807461251361U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2379557167489415783U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11854373946064529806U;
            aOrbiterD = RotL64((aOrbiterD * 150755294320438887U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 1487252775956449964U) + aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12777924204511625545U;
            aOrbiterG = RotL64((aOrbiterG * 1366019527386994789U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15998631485222477969U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8864212892296191613U;
            aOrbiterI = RotL64((aOrbiterI * 579242788050369815U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17069347835763226743U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7443008171694679791U;
            aOrbiterF = RotL64((aOrbiterF * 748894368884566607U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17334256152350782002U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 8986626119086556393U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 2258172145924120235U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8528180968228358674U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 12702290928064582589U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 15673603224146737631U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 7742438100860023610U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3729687240959702198U;
            aOrbiterC = RotL64((aOrbiterC * 3756794766163746783U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 426129097367382096U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 16782175452274911213U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1041477289638333659U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 23U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 44U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 23U)) + aOrbiterB) + aNonceWordG);
            aWandererI = aWandererI + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 19U)) + aOrbiterD) + RotL64(aCarry, 47U)) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterA, 14U)) + aOrbiterC);
            aWandererH = aWandererH + (((((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 43U)) + aOrbiterB) + RotL64(aCarry, 21U)) + aNonceWordK) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 39U)) + aOrbiterA) + aNonceWordB);
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterI, 27U)) + aNonceWordI);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 58U) + aOrbiterD) + RotL64(aOrbiterC, 10U));
            aWandererB = aWandererB + ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterD, 51U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterG, 35U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 14U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11443U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneC[((aIndex + 8693U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 12114U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneC[((aIndex + 15173U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8794U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16330U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 15528U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 3U)) + (RotL64(aCarry, 34U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = ((aWandererK + RotL64(aIngress, 35U)) + 5088525177670191619U) + aNonceWordN;
            aOrbiterK = (aWandererI + RotL64(aCross, 24U)) + 9966456257813932112U;
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 7707646574027146307U) + aOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 75480203757681173U) + aNonceWordB;
            aOrbiterG = (aWandererB + RotL64(aCross, 19U)) + 384659134071835163U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 39U)) + 3158769775373307778U) + aNonceWordL;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 28U)) + 17360830943513941272U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 5317278822721604586U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 43U)) + 1371427105215954781U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 3162710551223553423U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5332921933853550756U;
            aOrbiterE = RotL64((aOrbiterE * 11709546145149357887U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 10572462410297815854U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 10234389605554817892U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2130374833440291193U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13421365517991380605U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10186643614984034083U;
            aOrbiterI = RotL64((aOrbiterI * 8554471709467808453U), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 4742438973260817120U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6081590345899008846U;
            aOrbiterC = RotL64((aOrbiterC * 7069396301823124931U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15360092808493795340U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 12186413069553132646U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 3815981440611914267U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16756221656224451552U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12232880965861373143U;
            aOrbiterJ = RotL64((aOrbiterJ * 14196910735715726471U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 10090954323470840557U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15615770271463853537U;
            aOrbiterA = RotL64((aOrbiterA * 13544181592829027283U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 556029032505658411U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 13311879111583579039U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 3924744868168749003U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8646360871497847336U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2064833941982069154U;
            aOrbiterK = RotL64((aOrbiterK * 10016546852137913163U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 28U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 5U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aIngress, 24U) + aOrbiterD) + RotL64(aOrbiterA, 53U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 23U)) + aOrbiterC) + aNonceWordP);
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ) + aNonceWordC);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterI, 38U));
            aWandererB = aWandererB + ((((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 20U) + aOrbiterG) + RotL64(aOrbiterA, 47U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 51U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterC, 60U)) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 24U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21628U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 19280U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 23737U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24241U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24053U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24508U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 24499U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 5U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterH = (((aWandererD + RotL64(aScatter, 56U)) + RotL64(aCarry, 57U)) + 9888431329297626900U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 35U)) + 2937735167534624403U) + aNonceWordN;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 5U)) + 17626022970343789617U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 51U)) + 5665660859333693743U) + aNonceWordF;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 19U)) + 1060537034632076669U) + aNonceWordL;
            aOrbiterG = (aWandererE + RotL64(aScatter, 41U)) + 743777763907175800U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 5744905970181808845U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 39U)) + 3545351394494002180U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 30U)) + 4877547088414106007U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11669378338379598445U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 2961072441706158212U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2677988507090705371U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 13984945589234919765U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 1433097875470903205U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 451996840039906781U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 716415411025451152U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8542286150858297810U;
            aOrbiterC = RotL64((aOrbiterC * 9139015340823332449U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 12932391786479661299U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14005503313299177013U;
            aOrbiterG = RotL64((aOrbiterG * 802663466907819743U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9382792812676318046U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5138554251079724724U;
            aOrbiterH = RotL64((aOrbiterH * 6386016499265056247U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8522380066269546172U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11825536408101906458U;
            aOrbiterJ = RotL64((aOrbiterJ * 17042837108792016849U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 15504062350899452495U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 1219010998820336744U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 10650635772711590803U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 6442717843380349632U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1047843426279085117U;
            aOrbiterI = RotL64((aOrbiterI * 4074561571072878005U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10611039527108679173U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5092816736177358221U;
            aOrbiterA = RotL64((aOrbiterA * 14342779343820140833U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 54U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 60U) + aOrbiterI) + RotL64(aOrbiterD, 18U));
            aWandererB = aWandererB + (((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 23U)) + aOrbiterC) + aNonceWordM);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 5U)) + aOrbiterD) + aNonceWordB);
            aWandererK = aWandererK + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 57U)) + aOrbiterH) + RotL64(aCarry, 47U)) + aNonceWordE);
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 48U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 13U)) + aOrbiterK) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 28U) + aOrbiterH) + RotL64(aOrbiterA, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32251U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 30393U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 32269U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((aIndex + 29843U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31195U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26932U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 31686U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 34U) + RotL64(aCarry, 3U)) + (RotL64(aCross, 51U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (aWandererG + RotL64(aScatter, 53U)) + 14179205183062705133U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 34U)) + 210032324058740920U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 7387115089142500152U) + aNonceWordL;
            aOrbiterG = ((aWandererK + RotL64(aCross, 29U)) + 17583362781238061430U) + aOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 57U)) + 4991442849150005943U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 46U)) + 2891376254689854555U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 57U)) + 10523274382407446239U) + aNonceWordG;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 11U)) + 3861893764676218667U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 37U)) + 3366674459852093746U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 5898492634386601145U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7047353571244768721U;
            aOrbiterB = RotL64((aOrbiterB * 2257518291062508467U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14374108805453186316U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 8763667021501226510U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 7694695426430267863U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 18261523829316379575U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 650477532238860965U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 8291758490821819851U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2162326554604894042U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 5776546692501825278U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14911545784585246537U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3501863793638415049U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14853789267425352958U;
            aOrbiterH = RotL64((aOrbiterH * 10590325397179928739U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15399673014671329743U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12253428583438990426U;
            aOrbiterG = RotL64((aOrbiterG * 12052855472196447849U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 13202953937621953839U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 7547616636832698398U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 9533399972562428073U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 15709801946594868318U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 12458677982746610971U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6662570874316418993U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6957370791367530127U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10511379961344950861U;
            aOrbiterC = RotL64((aOrbiterC * 15551333099264031337U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 34U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 3U)) + aOrbiterD);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterK, 53U)) + aNonceWordF);
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterF, 34U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterD, 21U));
            aWandererK = aWandererK + (((RotL64(aScatter, 34U) + RotL64(aOrbiterK, 57U)) + aOrbiterH) + aWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterC, 13U)) + aNonceWordB);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterF, 46U));
            aWandererF = aWandererF + (((RotL64(aCross, 46U) + aOrbiterJ) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF3BF432472D45593ULL + 0xD01B7B0FAFC65376ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF15B9B7B62F041F3ULL + 0xF16BA116D39B61DFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC674CE9F1BFA2107ULL + 0xFC1923438C49632BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE2D86AE5714E3C35ULL + 0xC24B10D1A5377CB6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE0C376CB2132A47FULL + 0xD2BF16276486B67EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA772DFD8B4BCC123ULL + 0x86E8F2D3151BAFC5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE1583226EB5A6DBBULL + 0x9A37E1B14314A462ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9840AFFFBC772BCFULL + 0xFA89418332F5363DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA6739ED36CCDDA83ULL + 0xCEBFD07D9D8D9D4DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xEE029580863953B7ULL + 0xABD213D6332D4204ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x96FBE6C25D259343ULL + 0xA3EDEFAEE9C526B7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDFEAC03FC4CA0673ULL + 0xB5BD901FFC96DD1BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9E2E5D69C7D973E9ULL + 0xCAEA7D29DC8D87D8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD04AFB2C86259A07ULL + 0xFA3ABB6DBB6FD408ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xBF03DA962538B9B7ULL + 0xA79EA2DD05F0C6C7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFB167205777E6339ULL + 0xB14B3F04F5F6DF33ULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 3383U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 1971U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 6415U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 861U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4894U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7088U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCross, 60U)) ^ (RotL64(aIngress, 43U) + RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 9914837590440975587U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 3U)) + 6706125076401958051U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 11U)) + 16570817772679258409U) + aNonceWordN;
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 6843705658115186948U) + aOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 27U)) + 16099930446791572351U) + aNonceWordD;
            aOrbiterI = ((aWandererB + RotL64(aCross, 30U)) + 5420550009556030459U) + aNonceWordF;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 23U)) + 5729549069420177477U) + aOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15590601126188675834U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 13044027390998620029U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16845199115313444123U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 11068338135659636772U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6584988841809544332U;
            aOrbiterA = RotL64((aOrbiterA * 1683336180438945439U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 8516813219883915404U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 10647314042912492785U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 15559481057047148785U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 201691689889605304U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 15512161798401184003U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11473219183982564709U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3883760518944464145U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13861805129175491145U;
            aOrbiterG = RotL64((aOrbiterG * 17194438894492581181U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 12019138626550801486U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13030350224959652248U;
            aOrbiterB = RotL64((aOrbiterB * 11724200983306280107U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2643807255422544248U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4127143302485631794U;
            aOrbiterH = RotL64((aOrbiterH * 5441038881111578487U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 51U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 30U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 13U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aNonceWordH);
            aWandererB = aWandererB ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 37U)) + aOrbiterG) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 11U)) + aNonceWordB);
            aWandererK = aWandererK ^ (((RotL64(aCross, 28U) + aOrbiterA) + RotL64(aOrbiterB, 57U)) + aNonceWordJ);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterH, 43U)) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 58U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 14446U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 10360U)) & S_BLOCK1], 44U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 15508U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneC[((aIndex + 10554U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14621U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13243U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10175U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 47U)) + (RotL64(aPrevious, 20U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = (aWandererK + RotL64(aPrevious, 27U)) + 12380376990224645149U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 21U)) + 18296928500297384014U) + aNonceWordL;
            aOrbiterF = ((aWandererA + RotL64(aCross, 13U)) + 3550626816361145100U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 51U)) + 2667792936946706027U;
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 36U)) + RotL64(aCarry, 19U)) + 12020969779370926953U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 5U)) + 737340727886903447U) + aNonceWordE;
            aOrbiterA = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 1681797651799760502U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2956186342689489064U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 1876852870402977177U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 8875540081346621757U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 6433205819353555071U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9065076854974222998U;
            aOrbiterK = RotL64((aOrbiterK * 5459675878087242021U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3254410578766789992U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2005081975473815576U;
            aOrbiterH = RotL64((aOrbiterH * 9947701153722014085U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15992999234834560419U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 3458344156815120948U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 1668460113964608051U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 17069783053664877727U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 1260234710193913099U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 4561226779897414381U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 3825186451876061335U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 2905344294992827535U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 2469896090698580795U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 18141402347899180617U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 8760129857609925066U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2507999156108123047U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterI, 3U)) + aWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 10U)) + aOrbiterJ);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 58U) + aOrbiterJ) + RotL64(aOrbiterF, 41U)) + aNonceWordB);
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 57U)) + aOrbiterK);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 47U)) + aOrbiterG) + aWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 5U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 52U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21880U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 21982U)) & S_BLOCK1], 18U));
            aIngress ^= (RotL64(aWorkLaneB[((aIndex + 18651U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 20324U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18191U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 18019U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 20864U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 16189787374324972735U;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 41U)) + 17563763730956242224U) + aOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aCross, 37U)) + 10572803498593789385U) + aNonceWordF;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 30U)) + RotL64(aCarry, 3U)) + 7713105232072974166U) + aNonceWordE;
            aOrbiterK = ((aWandererD + RotL64(aCross, 3U)) + 10760839534772718139U) + aOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aScatter, 57U)) + 13397069448391230253U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 21U)) + 4569255679998375682U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9888769350817876949U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 11351796060878856300U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 13356749147334008399U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 18153775071965707204U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 1282846411145853435U) ^ aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12294455920906257823U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 16457743979262460660U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 173493260775251032U;
            aOrbiterD = RotL64((aOrbiterD * 4935807229040883505U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3927345926316409630U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5158769729850853623U;
            aOrbiterC = RotL64((aOrbiterC * 2446452358663812945U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 12331351600010165154U) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 3940794200348684050U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13248997263062075043U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11248514843822945425U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1391497323278226522U;
            aOrbiterH = RotL64((aOrbiterH * 8376841806072565005U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13265623528678787307U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2802033745265647317U;
            aOrbiterJ = RotL64((aOrbiterJ * 3437626962562016147U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 43U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 48U) + aOrbiterF) + RotL64(aOrbiterH, 11U)) + aNonceWordN);
            aWandererH = aWandererH + (((((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterK, 26U)) + RotL64(aCarry, 13U)) + aNonceWordG) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 5U)) + aOrbiterG);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 43U)) + aNonceWordA) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 51U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 19U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 26134U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneA[((aIndex + 30803U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 25718U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 32575U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30673U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29741U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 25183U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 6U)) + (RotL64(aCarry, 41U) + RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = (aWandererB + RotL64(aIngress, 58U)) + 16922357079016918108U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 41U)) + 11771749797137599131U;
            aOrbiterF = (((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 4635668433708036077U) + aNonceWordA;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 3U)) + 15827952719230577008U) + aNonceWordB;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 21U)) + 1495675306110023086U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 7294835466949728365U) + aNonceWordE;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 179122461212041978U) + aOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 545981421632236251U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15338259639814630535U;
            aOrbiterF = RotL64((aOrbiterF * 14895421566334357871U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12924313840290895215U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17846785921286020610U;
            aOrbiterE = RotL64((aOrbiterE * 18309347016029917133U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 5721472794107057875U) + aNonceWordG;
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 16359630793856870319U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 14186771515526698907U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10614102110239037308U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16421992251278236531U;
            aOrbiterG = RotL64((aOrbiterG * 2561232904676068089U), 19U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 8668149834861244963U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12699331834360948734U;
            aOrbiterH = RotL64((aOrbiterH * 2249360824172616357U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4470693178142950471U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 526000656022724741U;
            aOrbiterJ = RotL64((aOrbiterJ * 16688501462334673493U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 6880246132270094141U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7126466778855297013U;
            aOrbiterI = RotL64((aOrbiterI * 5692237926830293205U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 43U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterE, 29U)) + aOrbiterH) + aNonceWordH);
            aWandererE = aWandererE + ((((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 29U)) + aNonceWordJ);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 11U));
            aWandererC = aWandererC + (((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 22U)) + aOrbiterJ) + aWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 51U)) + aOrbiterJ) + aNonceWordP);
            aWandererD = aWandererD + (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterI, 37U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
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
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA6E303460197F6C7ULL + 0xE5B2D89D694A8DABULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE0EC73C480933883ULL + 0xA22AC50DF72D85CDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8D8F9A705AE2E04BULL + 0xE3A3EC0367DCC85AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD8B08EFFA9D7DC59ULL + 0xD615B91F8F13E955ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD4CF40DA442F12D1ULL + 0x82DEB120A1AF80A1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBF0EAF3A1A3FF1A1ULL + 0x8F95A722EF0F758BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8235FE4D02C5EA7DULL + 0xB3E82B02C5C42CC8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x81D71C2A49471569ULL + 0xA0E4F3AD53A90248ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xBA51B296CA864DA1ULL + 0x81F5B9DE6D384871ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB07571E7E5486193ULL + 0x8B78EBB5F1ED3F46ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xBF4ECB7126FE27A3ULL + 0xC5363F9B89B83678ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB8B9883106FB8CDFULL + 0xC98439440FF46F0BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8EE122E0C0DE0379ULL + 0xFDC5F9795699D2B9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x904616F842FC731BULL + 0xE8DA893277423E6AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xAA19DD7F5C228F39ULL + 0xC3A0F945117C0CE8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA515734BEF132CF3ULL + 0xD5372383FD4B6C7DULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1549U)) & W_KEY1], 21U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 2281U)) & W_KEY1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2539U)) & W_KEY1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 829U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 19U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 38U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = (aWandererE + RotL64(aScatter, 3U)) + 13333509828310369865U;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 7645352517103840797U) + aNonceWordD;
            aOrbiterC = ((((aWandererG + RotL64(aPrevious, 22U)) + RotL64(aCarry, 5U)) + 5310766306660062655U) + aPhaseEOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (((aWandererB + RotL64(aCross, 35U)) + 5165635069832352932U) + aPhaseEOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 15684141764734281849U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 13U)) + 3327963374225061738U) + aNonceWordG;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 43U)) + 8625811794878848871U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7598657468430485291U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2881171216276746485U;
            aOrbiterC = RotL64((aOrbiterC * 3331350584102843605U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10237691227222918101U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 6419254255884834497U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3816625473642865305U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4238455444646479956U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 14936613353493061492U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3544216916806292273U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15324699725208372627U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9506640480601832011U;
            aOrbiterA = RotL64((aOrbiterA * 12819564111348390227U), 37U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 3709149613660215641U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 1724290199312754307U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 12597580418257897965U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13191172833570139194U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 3686087945377837886U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10883609557429936283U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10418330386245397022U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5383531313632347245U;
            aOrbiterH = RotL64((aOrbiterH * 2987755379396160073U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 35U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 51U) + RotL64(aOrbiterD, 35U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterK, 29U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 11U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aNonceWordN);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 57U)) + aOrbiterK) + aNonceWordO);
            aWandererC = aWandererC + (((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterK, 41U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 42U) + aOrbiterD) + RotL64(aOrbiterK, 19U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 50U)) + aOrbiterA) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 4163U)) & S_BLOCK1], 50U) ^ RotL64(aKeyRowReadA[((aIndex + 2797U)) & W_KEY1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3212U)) & W_KEY1], 44U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4494U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 22U) ^ RotL64(aCross, 39U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = ((aWandererC + RotL64(aIngress, 29U)) + 4634399531433127141U) + aPhaseEOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 16961792729406903200U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 12U)) + 4105280732301137738U) + aNonceWordJ;
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 15692013501147331191U) + aNonceWordC;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 23U)) + 1252216715968780587U) + aNonceWordE;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 37U)) + 7958289043012473752U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 19U)) + 6611577301818896615U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8506226754305949140U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 3648813120449403353U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9521367946879238849U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5195245426245535735U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 542948051600803051U;
            aOrbiterK = RotL64((aOrbiterK * 4631106308856448475U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 11974253551208964789U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10596463592332655367U;
            aOrbiterF = RotL64((aOrbiterF * 10941161258815714641U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12015129484061440159U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8254944355710109060U;
            aOrbiterD = RotL64((aOrbiterD * 3233697992479357615U), 51U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 2754858806943915419U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 5007802002906662779U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 15613733948331639723U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6262190752136523216U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 10528977986487821428U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 1184258264034585525U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 8511097226098211854U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12091864735686692582U;
            aOrbiterH = RotL64((aOrbiterH * 6128140528141411237U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 47U)) + aNonceWordO) + aPhaseEWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterH, 35U)) + aNonceWordB);
            aWandererI = aWandererI + (((RotL64(aCross, 37U) + RotL64(aOrbiterF, 60U)) + aOrbiterD) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 12U) + aOrbiterH) + RotL64(aOrbiterJ, 51U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterI, 29U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 5U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 13U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 6143U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 8160U)) & W_KEY1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7737U)) & W_KEY1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5750U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6011U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 50U)) + (RotL64(aIngress, 35U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = (aWandererI + RotL64(aIngress, 53U)) + 14823268998003220191U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 14U)) + 15295237288788213847U) + aNonceWordJ;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 16434853402001133899U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 47U)) + 7555911304407871631U) + aNonceWordM;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 39U)) + 14977248264994834620U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 3U)) + 9707764144919392380U) + aPhaseEOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 21U)) + 1277304385464681529U) + aNonceWordN;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3089786220465849395U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3700503853358695085U;
            aOrbiterJ = RotL64((aOrbiterJ * 2079089949442685421U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 3240054112993517371U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16897532076915366859U;
            aOrbiterK = RotL64((aOrbiterK * 4120874717534309035U), 35U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 18167359289798364307U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8870819278575769863U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 9334066154398059075U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15363069206212330251U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14858164441499725158U;
            aOrbiterE = RotL64((aOrbiterE * 14931933411393847915U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5357144808788707522U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 2910681277417754860U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13170868582159347059U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 9824408699018165151U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 368370224788793300U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 14358982366258729959U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 7095398304588825115U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11418879758164313554U;
            aOrbiterA = RotL64((aOrbiterA * 5983520332639771791U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 10U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterJ, 13U));
            aWandererG = aWandererG + ((RotL64(aScatter, 12U) + aOrbiterG) + RotL64(aOrbiterK, 29U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterK, 39U)) + aNonceWordC);
            aWandererB = aWandererB + (((((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 13U)) + aNonceWordP) + aPhaseEWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 21U)) + aOrbiterD) + aNonceWordL);
            aWandererK = aWandererK + ((((RotL64(aCross, 35U) + RotL64(aOrbiterF, 47U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aNonceWordG);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterA, 58U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 10732U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 10608U)) & W_KEY1], 58U));
            aIngress ^= (RotL64(mSource[((aIndex + 9931U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneA[((aIndex + 8274U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9335U)) & W_KEY1], 60U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 10068U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = (((aWandererH + RotL64(aScatter, 44U)) + RotL64(aCarry, 3U)) + 5697928251815176134U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aIngress, 29U)) + 337587740689259575U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aCross, 37U)) + 4927686903263973950U) + aNonceWordM;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 3742409032569801033U) + aNonceWordK;
            aOrbiterG = (aWandererA + RotL64(aCross, 51U)) + 1608092659172197650U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 53U)) + 15848744267145717509U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 13U)) + 15300174177963339253U) + aNonceWordG;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14162868453323648628U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 12020167069983729869U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 2071080217680099017U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 16259538291658723956U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8516686212464112245U;
            aOrbiterK = RotL64((aOrbiterK * 4731296903548893627U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3722184575520553132U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5663609293306386784U;
            aOrbiterB = RotL64((aOrbiterB * 14364218128780764749U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15265344442454471986U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3050323350098829515U;
            aOrbiterG = RotL64((aOrbiterG * 5890624677162388135U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1093356813820599238U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15167726103772238440U;
            aOrbiterI = RotL64((aOrbiterI * 5719466863561311069U), 51U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 15170797965325981472U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (((aOrbiterA ^ aOrbiterB) ^ 17826286701992981628U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 11186808881726573677U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14710892030473425181U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 397194787697553904U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14368930300818752833U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 58U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aIngress, 58U) + aOrbiterI) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 21U)) + aNonceWordH) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 27U)) + aOrbiterB) + aNonceWordD);
            aWandererI = aWandererI + ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterB, 51U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 3U)) + aOrbiterI) + aNonceWordO);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 41U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 57U)) + aOrbiterK) + aNonceWordP) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 34U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 12246U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 12348U)) & W_KEY1], 35U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13108U)) & W_KEY1], 3U) ^ RotL64(mSource[((aIndex + 13393U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 12712U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12136U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12972U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 29U)) ^ (RotL64(aIngress, 11U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterI = (((aWandererE + RotL64(aIngress, 3U)) + 10915618884692072446U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 12634922308499254909U) + aNonceWordK;
            aOrbiterG = (aWandererH + RotL64(aScatter, 13U)) + 6533934734564499389U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 44U)) + 6744203303756105181U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 13086782386652045658U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 5693840533331397822U) + aPhaseFOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aCross, 37U)) + 1803663542535024611U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3597219300593287708U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 1429753448204448904U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 10927459251773273143U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17229017825587322715U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 1137574712801062932U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 3645832160939819415U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2401991077004083378U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1332473247826139292U;
            aOrbiterA = RotL64((aOrbiterA * 15029831858261506447U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 11730946340796899885U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15319163439700390962U;
            aOrbiterI = RotL64((aOrbiterI * 1349242001887975499U), 3U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 4744141870145159917U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 6067132201862688684U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6046100687757836027U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14991509179286371800U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4342608825699398682U;
            aOrbiterF = RotL64((aOrbiterF * 10240526103933275875U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 3727521409410742075U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 3302027219498304367U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12153634588200479559U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 58U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 41U)) + aNonceWordM);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterA, 57U));
            aWandererG = aWandererG + (((((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 27U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aNonceWordN) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 56U) + RotL64(aOrbiterF, 3U)) + aOrbiterI) + aPhaseFWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterH, 44U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterG, 19U)) + aNonceWordO);
            aWandererB = aWandererB + ((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterB, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 14677U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14413U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14899U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14464U)) & W_KEY1], 21U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14566U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 14202U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14395U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 42U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = ((aWandererF + RotL64(aCross, 58U)) + RotL64(aCarry, 35U)) + 4384716820085860551U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 5U)) + 9715780315942116888U;
            aOrbiterK = ((((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 15963520052789178632U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 14346700690686392938U) + aPhaseFOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aScatter, 43U)) + 6005518012489966643U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 51U)) + 2506732930310252119U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 37U)) + 16782163084851775826U) + aNonceWordL;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 823673076571076303U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1634084509064077736U;
            aOrbiterK = RotL64((aOrbiterK * 1128407326773234517U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1288134975466877686U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2998220403162908444U;
            aOrbiterB = RotL64((aOrbiterB * 4321412662318298283U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 220430672180734911U) + aNonceWordF;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 10223923547068528867U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12577370238343872139U), 11U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 11696469696177647608U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6545430420379636963U;
            aOrbiterF = RotL64((aOrbiterF * 8387163146257553773U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 79691451831797107U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8971444023498649419U;
            aOrbiterJ = RotL64((aOrbiterJ * 7148919880477390009U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5624403902454498793U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 9468064161002030997U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8243560528100864595U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4619361544913629805U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12682446273369750704U;
            aOrbiterD = RotL64((aOrbiterD * 10879074713156075641U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 50U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 42U) + RotL64(aOrbiterC, 11U)) + aOrbiterD) + RotL64(aCarry, 13U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 60U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aCross, 3U) + RotL64(aOrbiterF, 41U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK) + aNonceWordP) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 53U)) + aOrbiterK);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 5U)) + aPhaseFWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 50U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16619U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[((aIndex + 18034U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(mSource[((aIndex + 16727U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17476U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17243U)) & W_KEY1], 56U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17952U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 17041U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 54U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = ((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 47U)) + 8767379393098711499U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 53U)) + 7168159491580816433U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 47U)) + 9879279829061883406U;
            aOrbiterF = (aWandererD + RotL64(aCross, 21U)) + 10537167136053399303U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 3U)) + 2839070018069188936U) + aNonceWordG;
            aOrbiterG = ((((aWandererK + RotL64(aScatter, 14U)) + RotL64(aCarry, 27U)) + 13844278063968429732U) + aPhaseGOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 11278946626186474646U) + aPhaseGOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11798425216660557799U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7618446090703335192U;
            aOrbiterJ = RotL64((aOrbiterJ * 7168757300685156779U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 695423597006983660U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14344728202803488813U;
            aOrbiterH = RotL64((aOrbiterH * 5168825904902285909U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 11656100506575697086U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10384358779985773937U;
            aOrbiterG = RotL64((aOrbiterG * 247494692039140973U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17585001605131977341U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9964478171465522911U;
            aOrbiterE = RotL64((aOrbiterE * 13484044854790175315U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 2710943171829692624U) + aNonceWordC;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 17809072853457153057U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16341884203303271365U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 12814092033910687774U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1743186323268668740U;
            aOrbiterF = RotL64((aOrbiterF * 11150822630624332557U), 43U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 10750472346626754704U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15925901217078035356U;
            aOrbiterD = RotL64((aOrbiterD * 9276504171291801637U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 35U);
            aIngress = aIngress + (RotL64(aOrbiterC, 6U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 35U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 19U)) + aOrbiterD) + aNonceWordD);
            aWandererA = aWandererA + ((((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterE, 56U)) + RotL64(aCarry, 51U)) + aNonceWordB);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterH, 27U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterF, 43U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterE, 5U)) + aOrbiterH);
            aWandererD = aWandererD + ((((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 20U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 21363U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((aIndex + 20230U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 19385U)) & S_BLOCK1], 4U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 19478U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20866U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19526U)) & W_KEY1], 57U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20136U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((aIndex + 19422U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 26U) + RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = (aWandererE + RotL64(aScatter, 26U)) + 11480359716598965890U;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 15431182525482873419U) + aNonceWordC;
            aOrbiterD = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 43U)) + 11360504974812776707U;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 51U)) + 9292576416573382769U) + aPhaseGOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 19U)) + 1549257414531028975U) + aPhaseGOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 5347769463033129317U) + aNonceWordJ;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 43U)) + 17019199177478377234U) + aNonceWordM;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16558106007323125094U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3976182233825939422U;
            aOrbiterD = RotL64((aOrbiterD * 4392162052317572289U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 2889047161195954395U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2241831345026962605U;
            aOrbiterE = RotL64((aOrbiterE * 5757458560979927857U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 12850802412140579294U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13541744735436450160U;
            aOrbiterG = RotL64((aOrbiterG * 906089290000537439U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2085863085516538212U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 2969034221711544086U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7768528124408400403U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6482666944512391472U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16969153556875844613U;
            aOrbiterB = RotL64((aOrbiterB * 9483462388353216219U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 5161314086757363678U) + aNonceWordE;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 7150282484670673211U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 8522427002337918663U), 21U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 5465304381272305847U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2344610773390354017U;
            aOrbiterC = RotL64((aOrbiterC * 17010258514288089191U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 36U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB) + aPhaseGWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterH, 23U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 22U) + aOrbiterJ) + RotL64(aOrbiterD, 5U)) + aNonceWordH) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 5U) + RotL64(aOrbiterG, 46U)) + aOrbiterB) + RotL64(aCarry, 39U)) + aNonceWordI);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterD, 13U));
            aWandererE = aWandererE + (((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 46U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 23987U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 21914U)) & W_KEY1], 41U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23402U)) & W_KEY1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22572U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22176U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23103U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22227U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 22531U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 10U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = (((aWandererF + RotL64(aCross, 58U)) + RotL64(aCarry, 21U)) + 8506388683755208267U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aPrevious, 5U)) + 2179323259055019735U;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 3345902531140983016U) + aNonceWordD;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 35U)) + 17456139311481306584U) + aNonceWordM;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 11U)) + 14587864088462311164U) + aPhaseGOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 13178947246650647057U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 43U)) + 12866578138946916962U) + aNonceWordH;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13098524333655118173U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15451329483787541982U;
            aOrbiterE = RotL64((aOrbiterE * 13580376920467431451U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9494299579678389385U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15581954810375490643U;
            aOrbiterG = RotL64((aOrbiterG * 13670002280188424825U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4487042505730624892U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2774455928791636186U;
            aOrbiterD = RotL64((aOrbiterD * 15847933919136777451U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 12435319582397755819U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10077180055177766823U;
            aOrbiterC = RotL64((aOrbiterC * 3924363471701748703U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10391963896910956455U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 6149237416725301794U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 10115917698918612823U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 15673402771629639978U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 14729117178956592426U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9070464269215820531U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 14492001279368870240U) + aNonceWordO;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 6278248084483259952U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16731228350971263873U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 12U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterE, 41U)) + aNonceWordJ);
            aWandererC = aWandererC + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 54U)) + aOrbiterD) + RotL64(aCarry, 47U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterG, 47U)) + aNonceWordI);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 10U) + RotL64(aOrbiterK, 35U)) + aOrbiterE) + aNonceWordF) + aPhaseGWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 19U)) + aOrbiterG) + aNonceWordE);
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterI, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26987U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 26981U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 24626U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26187U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 27126U)) & W_KEY1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26256U)) & S_BLOCK1], 41U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25138U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 24581U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 12U) + RotL64(aIngress, 27U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = (((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 9888431329297626900U) + aNonceWordH;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 47U)) + 2937735167534624403U) + aPhaseHOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 17626022970343789617U) + aNonceWordC;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 11U)) + 5665660859333693743U) + aNonceWordE;
            aOrbiterI = (aWandererD + RotL64(aCross, 60U)) + 1060537034632076669U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 23U)) + 743777763907175800U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 5744905970181808845U) + aNonceWordK;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterE) + 3545351394494002180U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 4877547088414106007U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 5416792889338547109U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 11669378338379598445U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2961072441706158212U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2677988507090705371U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13984945589234919765U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1433097875470903205U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 451996840039906781U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 716415411025451152U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8542286150858297810U;
            aOrbiterF = RotL64((aOrbiterF * 9139015340823332449U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12932391786479661299U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 14005503313299177013U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 802663466907819743U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 9382792812676318046U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5138554251079724724U;
            aOrbiterE = RotL64((aOrbiterE * 6386016499265056247U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8522380066269546172U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 11825536408101906458U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 17042837108792016849U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 43U);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 18U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 27U)) + aOrbiterA) + aNonceWordD);
            aWandererG = aWandererG ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterE, 5U)) + aOrbiterC) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 51U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 44U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 18U) + aOrbiterF) + RotL64(aOrbiterE, 11U)) + aNonceWordP) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 18U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28414U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 29594U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27353U)) & W_KEY1], 4U) ^ RotL64(aWorkLaneC[((aIndex + 29147U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29851U)) & W_KEY1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29324U)) & S_BLOCK1], 58U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29864U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29293U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 13U)) + (RotL64(aPrevious, 26U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = (aWandererK + RotL64(aCross, 23U)) + 1952750591494698524U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 43U)) + 4488270851303332830U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 2738763375328927635U;
            aOrbiterK = ((((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 6728843649480454340U) + aPhaseHOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = (aWandererD + RotL64(aIngress, 51U)) + 10490717875258865358U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 3U)) + 1429288737812910205U) + aNonceWordJ;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 34U)) + 2761375016998907636U) + aPhaseHOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 1088988605204499835U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6829840407300289709U;
            aOrbiterJ = RotL64((aOrbiterJ * 13101432880030791787U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9267240337867690471U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 8120113021183975703U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 14296504593187173107U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1340980511302566784U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11874452169979878835U;
            aOrbiterC = RotL64((aOrbiterC * 8638486178860092537U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1872314794140971426U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6013952618696225751U;
            aOrbiterK = RotL64((aOrbiterK * 7994863587373565715U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3644011378086236002U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8501867691997891731U;
            aOrbiterI = RotL64((aOrbiterI * 7115282675461711509U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 2493546555198066143U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5179240189571799179U;
            aOrbiterH = RotL64((aOrbiterH * 1267579130962756135U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 11273348247858394197U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 4577476419423118925U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 8427261005061162673U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 11U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterH, 51U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 12U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aNonceWordL);
            aWandererA = aWandererA ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 57U)) + aOrbiterI) + aNonceWordO);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 3U)) + aOrbiterC) + aNonceWordM) + aPhaseHWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 23U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31108U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 32449U)) & W_KEY1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 31681U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30187U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30491U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadB[((aIndex + 31835U)) & W_KEY1], 3U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 54U)) + (RotL64(aCross, 21U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 4179952823252098240U) + aNonceWordO;
            aOrbiterH = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 37U)) + 3745613452332101749U) + aNonceWordK;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 28U)) + 2955689793395307176U) + aPhaseHOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 5639060180251322019U;
            aOrbiterB = (aWandererC + RotL64(aCross, 19U)) + 7901969163853586463U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 35U)) + 2242166787816318119U) + aPhaseHOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aIngress, 43U)) + 5239936443960750064U) + aNonceWordA;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 13939136954732185558U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17058884136712717463U;
            aOrbiterI = RotL64((aOrbiterI * 7222348891215482977U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 18148618660054585941U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7022023484530327814U;
            aOrbiterB = RotL64((aOrbiterB * 650100011311048589U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7722084537340095637U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11764151879690934182U;
            aOrbiterG = RotL64((aOrbiterG * 12264384877711365655U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 16412785901758144708U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9666718667728274824U;
            aOrbiterE = RotL64((aOrbiterE * 10865799822751771795U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 4307127540152109364U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2457646804702647606U;
            aOrbiterH = RotL64((aOrbiterH * 6340030928007058595U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 3179394870088602208U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 504977947273774249U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16190282058883481551U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 16182729401018310837U) + aNonceWordM;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 7110817020445860609U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13371352088428584087U), 41U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 56U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 27U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 13U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 52U) + aOrbiterH) + RotL64(aOrbiterB, 41U));
            aWandererH = aWandererH + (((RotL64(aCross, 23U) + RotL64(aOrbiterI, 57U)) + aOrbiterB) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 47U)) + aOrbiterB) + aNonceWordE) + aPhaseHWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + RotL64(aOrbiterG, 34U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 5U)) + aOrbiterH) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 12U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDF3F3C4A34D884FBULL + 0x8B122EDD507C2A01ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEA0EBBFB2A38AC25ULL + 0x8B2035E27576B4F5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9FE0BDE3B40F2AF1ULL + 0xE01E1AD9558D5917ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x86E136DC4A0E7B03ULL + 0xD3915C2241BE713EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA851408900D5779FULL + 0xB02789EDA8AAE8DAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD8EB7352AFC24AE7ULL + 0xEB1569E52CDC4BF3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xFE6C613889F32ABBULL + 0x88020FA9E000D089ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD8C183DC55AE2D47ULL + 0xF9D53BC6374F33EBULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBBEB51D98B1A10D5ULL + 0x94C19821AF240888ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC5C1A5B8BE3B06BDULL + 0xE1C559DBBCF3AB64ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xFAE7C2CB2435EB05ULL + 0xA95E722F70A8E4CEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE6A8DD75D5F0A125ULL + 0x971A64AE3D29E07DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFB0954D6E0683DEFULL + 0xC6C3351B082EF8CBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD2579A578E3DB7A5ULL + 0xD76FD8D4DD918E15ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB92D93A7CA1E674BULL + 0xCAA0BCEBE5FAF5D1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD20A49CD656D7985ULL + 0xBB164AA62D1DF7FEULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 328U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 3567U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3777U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4503U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3232U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3493U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterD = (((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 7948891781097675369U) + aNonceWordJ;
            aOrbiterE = (aWandererB + RotL64(aIngress, 30U)) + 13928362874228230226U;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 10776180542602258926U) + aNonceWordG;
            aOrbiterI = ((((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 5735115172149470447U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (((aWandererC + RotL64(aCross, 13U)) + 5353591822981766987U) + aPhaseAOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 562301708107268570U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10467810247578364868U;
            aOrbiterH = RotL64((aOrbiterH * 10449089554007059823U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14541630141152308564U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2350076897065139429U;
            aOrbiterE = RotL64((aOrbiterE * 12222554362482034393U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 17519109078651162228U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 6061035173339902910U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 10021905773432907835U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15654836633731000065U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterE) ^ 13723521735153718904U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 14459516479283070563U), 27U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 2849680038315532197U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17336102435576647923U;
            aOrbiterI = RotL64((aOrbiterI * 10984689101753586739U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterB, 53U)) + aNonceWordA) + aPhaseAWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 5U) + RotL64(aOrbiterH, 5U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterB, 23U)) + aOrbiterD) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 37U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterE, 14U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 6588U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 6744U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 6965U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9391U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9462U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8170U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 8495U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 27U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = (((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 439898681482066326U) + aNonceWordD;
            aOrbiterA = ((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 39U)) + 17362083676671776094U;
            aOrbiterE = (((aWandererF + RotL64(aScatter, 13U)) + 6418499837265155024U) + aPhaseAOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 53U)) + 17262244253027454972U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 58U)) + 2382066162993139503U) + aPhaseAOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14345808395587174135U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 7534743166385552851U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 9475127126941982125U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 16994453324688523966U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 7079553728544045092U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10104892188895367489U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 3562822704508440641U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13990892681975857821U;
            aOrbiterA = RotL64((aOrbiterA * 8352929306654078795U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1796728922368577238U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6605161260520067178U;
            aOrbiterC = RotL64((aOrbiterC * 8147537646591674091U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13994083795942328918U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 6144523182899107711U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 4153879991344611283U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + RotL64(aOrbiterI, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterE, 3U));
            aWandererF = aWandererF + (((((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 3U)) + aNonceWordA) + aPhaseAWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterA, 24U));
            aWandererI = aWandererI + (((((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aNonceWordO) + aPhaseAWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 15890U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 11811U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12654U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15168U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14549U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 58U) + RotL64(aCross, 29U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = (((aWandererE + RotL64(aIngress, 39U)) + 15316464782468770057U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 6642872057476351588U;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 660732654689529192U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 7235418086884000655U) + aNonceWordA;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 56U)) + 14784518476694580493U) + aNonceWordH;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12222433977933449375U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 8573001207708329927U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 17771120145431297541U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 16035256260815013172U) + aNonceWordD;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 15767726974121910203U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 719060452537759331U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 17712217935322939971U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 13488963456923357159U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 16785285630840310405U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10222949131965611079U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 1495561412321657209U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9706305581868526265U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 16156530750584361434U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7773792489045606309U;
            aOrbiterC = RotL64((aOrbiterC * 10730624207715601393U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 21U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 28U) + RotL64(aOrbiterB, 51U)) + aOrbiterC) + aNonceWordN);
            aWandererC = aWandererC + ((((RotL64(aCross, 51U) + RotL64(aOrbiterA, 3U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aNonceWordL);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 42U)) + aOrbiterF) + aPhaseAWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 21U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aNonceWordI);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterA, 11U)) + aPhaseAWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20202U)) & S_BLOCK1], 44U) ^ RotL64(aInvestLaneA[((aIndex + 21478U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20931U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 19299U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 17044U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = (((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 10881271196314989997U) + aNonceWordE;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 3U)) + 6406461249988567558U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 44U)) + 17255067918280095959U) + aNonceWordG;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 16690850682497718411U) + aNonceWordL;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 5576201059361086866U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 11991259685693687554U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14652535244217836909U;
            aOrbiterG = RotL64((aOrbiterG * 18283959577075524171U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1701789037170782122U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 953429054903473833U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 13482379459700651427U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 12064513610469714211U) + aNonceWordJ;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 7993881398822002424U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11572884842788918377U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14421313768013320050U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 11112386845630998889U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 11771526352030371669U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17069630896535699015U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3308240081138623373U;
            aOrbiterI = RotL64((aOrbiterI * 10449509484417835159U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 5U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 30U) + RotL64(aOrbiterG, 58U)) + aOrbiterB) + aNonceWordH);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 29U)) + aOrbiterK) + aNonceWordF) + aPhaseAWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 41U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aNonceWordD) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterC, 19U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 3U)) + aOrbiterI) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22887U)) & S_BLOCK1], 6U) ^ RotL64(aInvestLaneB[((aIndex + 25602U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25327U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25590U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneA[((aIndex + 25575U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 24U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = ((((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 23U)) + 6068543441070417854U) + aPhaseAOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = ((((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 2995980468193441856U) + aPhaseAOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 4U)) + RotL64(aCarry, 51U)) + 18020277482171594003U) + aNonceWordE;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 27U)) + 4293807434721230702U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 19U)) + 7980599111583893156U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8593141111851052016U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5903487523900084325U;
            aOrbiterD = RotL64((aOrbiterD * 2508618861111356699U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15112035513447930209U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 9854037263057006439U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 396276470208637283U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 16759760289688823193U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12622628933030601390U;
            aOrbiterA = RotL64((aOrbiterA * 2151912984825538321U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 1264668857268123425U) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 16302812053619101593U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18291400055836111547U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 16087995784896123610U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 7970269262800468363U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14924752223305807461U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterA, 19U)) + aPhaseAWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 56U)) + aOrbiterG) + aNonceWordH) + aPhaseAWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterD, 35U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 11U)) + aOrbiterD) + aNonceWordI);
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 27U)) + aOrbiterA) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 56U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29249U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 32142U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 32306U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29914U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28108U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 41U)) ^ (RotL64(aCross, 11U) + RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = (((aWandererF + RotL64(aIngress, 12U)) + 4773124477323378268U) + aPhaseAOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 13U)) + 16848723289435796005U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 13846642134917107058U;
            aOrbiterB = ((((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 6472057872482789939U) + aPhaseAOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (aWandererC + RotL64(aIngress, 3U)) + 2747019500690707226U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 9003965289739733880U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 3013390651936257377U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 11081353600889943167U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3331004709895625067U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15355010435553517129U;
            aOrbiterA = RotL64((aOrbiterA * 8322759117004876831U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 7709870658004280052U) + aNonceWordP;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 13568728443963926564U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6736090830113688981U), 27U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 12409548853419307131U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 969183352023661537U;
            aOrbiterI = RotL64((aOrbiterI * 5549220554838837145U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15370309834426476775U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 3896803894396631184U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11018830202891911603U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 40U);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 3U)) + aOrbiterB) + aNonceWordO);
            aWandererE = aWandererE + (((((RotL64(aCross, 4U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aNonceWordL) + aPhaseAWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 47U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aNonceWordJ);
            aWandererC = aWandererC ^ (((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterA, 30U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererH, 56U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAD4EC39BF5AD3013ULL + 0xBD60C8BC7BE06814ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8423A51D87A1E123ULL + 0xD615F011AAA24A92ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFE37B3E272EDD639ULL + 0xF193CC0806D44176ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA4665FFD24524737ULL + 0xEE5955062B9BE4DAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA985B9EA5E8092E5ULL + 0xFDB22CB1C1DFD2FDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x86C470BA4D1DCA65ULL + 0xDF59C6B9CC881287ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE30DC39A850333C1ULL + 0xBE88AD43D3058312ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEFDB3B46058FBD01ULL + 0xC087ED808DCCCC54ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB2AF869E54DFF80DULL + 0xDBB8D06783054E99ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9F5EED825B48D5B1ULL + 0xE391D8D1899E5D8DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x85A0331F125C523FULL + 0x9CEDF68C52C1C15FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD2F84388EF73A7D5ULL + 0xBE4971BFC2DBDB20ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE4F158F1E2E8AB01ULL + 0xC97821889D8CE6EFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE42AA4538726A10FULL + 0xB62A9BDB95D632EDULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC13A152FE4B773F3ULL + 0x9618D791B77514FEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9821FA8028000333ULL + 0xBB0C0625EA452291ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5830U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((aIndex + 597U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4564U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3205U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6786U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 421U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 36U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = (((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 43U)) + 9107326720193244489U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aScatter, 57U)) + 10868585484401664145U;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 27U)) + 13637736741437846622U) + aNonceWordK;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 19U)) + 6130725216183918844U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 30U)) + 2063834478521338187U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 37U)) + 8564870627911949158U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 47U)) + 6524015751064086390U) + aNonceWordO;
            aOrbiterF = (aWandererD + RotL64(aIngress, 3U)) + 9874937766875388236U;
            aOrbiterD = (((aWandererE + RotL64(aScatter, 24U)) + RotL64(aCarry, 51U)) + 14723718409522680894U) + aNonceWordH;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13767059954741528279U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 6387608251033722169U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6601902195707980693U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5391425980008431000U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11524218415655093779U;
            aOrbiterA = RotL64((aOrbiterA * 12508457981779189389U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 155510463350385905U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10554591788433641311U;
            aOrbiterE = RotL64((aOrbiterE * 5412084824127934293U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 8662160162966241542U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 5092555636369853727U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 433807340167635499U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7163345798448796101U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 695089002178413267U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17302689458565434475U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5409173939213468972U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 15349690077393827541U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 10984681254001609841U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12376011890751302027U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7809614158898158383U;
            aOrbiterB = RotL64((aOrbiterB * 13845113198736843629U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13031938699536449576U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 3983178190194056516U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 1341678482929213405U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5567935037909671790U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17137042627663349797U;
            aOrbiterD = RotL64((aOrbiterD * 13535586899620672373U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 40U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 19U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aIngress, 58U) + aOrbiterE) + RotL64(aOrbiterI, 13U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 30U)) + aOrbiterF) + aPhaseBWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + RotL64(aOrbiterE, 5U)) + aOrbiterD) + aPhaseBWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 47U)) + aOrbiterF);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 35U)) + aNonceWordC);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 39U)) + aOrbiterA) + aNonceWordN);
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 35U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 48U) + aOrbiterE) + RotL64(aOrbiterB, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 50U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15311U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 12166U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 14547U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 9092U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15033U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12958U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 9243U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 4U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = (aWandererC + RotL64(aScatter, 11U)) + 2571116506511057880U;
            aOrbiterH = (aWandererF + RotL64(aCross, 18U)) + 13112435411509707292U;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 10403251762787357256U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 41U)) + 8461951095541400405U) + aNonceWordJ;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 47U)) + 9890793478557463815U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 39U)) + 3030229465991783707U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 53U)) + 7273848154043719247U) + aNonceWordD;
            aOrbiterI = (((aWandererH + RotL64(aIngress, 28U)) + RotL64(aCarry, 19U)) + 10681774862516028276U) + aPhaseBOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aCross, 3U)) + 7105082755586853104U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6588579345319551129U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14616333550242386092U;
            aOrbiterA = RotL64((aOrbiterA * 2934574715879306337U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15439666290229654921U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3360304356760164799U;
            aOrbiterE = RotL64((aOrbiterE * 5164191920584106237U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 14438730801970761889U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 14515616787452085729U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 2041601927968559821U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 4167853822635132419U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8950982233003320239U;
            aOrbiterJ = RotL64((aOrbiterJ * 887144270884244907U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12391327853728029953U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 7100871010552394421U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16552349374101955967U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15381697462381887944U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6801677551341079401U;
            aOrbiterH = RotL64((aOrbiterH * 13325954438427340703U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 947011315719204867U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6356920162398333481U;
            aOrbiterK = RotL64((aOrbiterK * 5566721941682667419U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 8910262020598577378U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8778455415977526457U;
            aOrbiterI = RotL64((aOrbiterI * 4092470497616637283U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5585696961453127223U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 9670655481681494412U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 7863197168965036383U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 54U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 10U)) + aOrbiterH) + RotL64(aCarry, 47U)) + aNonceWordK);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 37U)) + aOrbiterB) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 30U) + RotL64(aOrbiterI, 29U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterK, 51U)) + aNonceWordA);
            aWandererB = aWandererB + ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterA, 42U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterH, 19U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterG, 23U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 52U) + RotL64(aOrbiterG, 3U)) + aOrbiterK) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 57U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21771U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 19359U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 22591U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((aIndex + 20043U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20987U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24108U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 17842U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 24U)) + (RotL64(aCarry, 37U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = ((aWandererC + RotL64(aScatter, 13U)) + 2672739400294801233U) + aNonceWordF;
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 24U)) + RotL64(aCarry, 5U)) + 8475624545015101850U) + aPhaseBOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 21U)) + 1252755112289831257U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 35U)) + 7938039507649183387U) + aNonceWordI;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 43U)) + 8167413146948861022U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aIngress, 48U)) + 17712313989694374353U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 51U)) + 7637042279892596975U) + aNonceWordJ;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 57U)) + 15770412950033467341U;
            aOrbiterG = (aWandererG + RotL64(aCross, 29U)) + 3951812021898608685U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8656983621098246507U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17943342344730687317U;
            aOrbiterC = RotL64((aOrbiterC * 16495519451034883813U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3087677463651608668U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 16493240011924342788U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16898479041530771871U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 7750923317452683057U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 2185924841611106546U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 708072658250726381U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14676868738946722416U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 6849098251696302393U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2599806275837778069U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17817755047153606419U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9900465270314068757U;
            aOrbiterG = RotL64((aOrbiterG * 9267925873983176685U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11380000891112113701U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15930503831156546113U;
            aOrbiterK = RotL64((aOrbiterK * 14450535035065393845U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5439183530402949780U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 3731802052051181843U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 7739775058947333169U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14432344583247783600U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16192098795467501636U;
            aOrbiterA = RotL64((aOrbiterA * 6285466374319549047U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 1523272672673940290U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 7462092373525113574U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 15067751170235540679U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 34U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 18U) + RotL64(aOrbiterC, 37U)) + aOrbiterG) + RotL64(aCarry, 27U)) + aPhaseBWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 5U)) + aOrbiterD) + aPhaseBWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 53U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 27U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aIngress, 6U) + RotL64(aOrbiterG, 60U)) + aOrbiterE) + aNonceWordC);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 13U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 23U)) + aOrbiterC);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterA, 41U)) + aNonceWordK);
            aWandererG = aWandererG + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 18U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 56U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererF, 10U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27547U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((aIndex + 26793U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 26897U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31656U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31518U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28822U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 29585U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 56U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 19U)) + 5697928251815176134U) + aNonceWordO;
            aOrbiterG = ((aWandererF + RotL64(aCross, 18U)) + 337587740689259575U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aScatter, 43U)) + 4927686903263973950U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 47U)) + 3742409032569801033U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 35U)) + 1608092659172197650U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 11U)) + 15848744267145717509U) + aNonceWordG;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 58U)) + RotL64(aCarry, 57U)) + 15300174177963339253U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 27U)) + 14162868453323648628U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aPrevious, 53U)) + 12020167069983729869U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 16259538291658723956U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8516686212464112245U;
            aOrbiterB = RotL64((aOrbiterB * 4731296903548893627U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 3722184575520553132U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 5663609293306386784U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14364218128780764749U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 15265344442454471986U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 3050323350098829515U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 5890624677162388135U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1093356813820599238U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15167726103772238440U;
            aOrbiterD = RotL64((aOrbiterD * 5719466863561311069U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15170797965325981472U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17826286701992981628U;
            aOrbiterF = RotL64((aOrbiterF * 11186808881726573677U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14710892030473425181U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 397194787697553904U;
            aOrbiterC = RotL64((aOrbiterC * 14368930300818752833U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1273724124862533034U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13018397560392545616U;
            aOrbiterG = RotL64((aOrbiterG * 4644812473262395329U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9638716186445643730U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7255587739807843785U;
            aOrbiterE = RotL64((aOrbiterE * 6055682981584011189U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9272350563697399628U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1040729335295009339U;
            aOrbiterK = RotL64((aOrbiterK * 17825687660830291443U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 34U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterK, 58U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 41U)) + aOrbiterF) + aNonceWordD);
            aWandererA = aWandererA + (((((RotL64(aScatter, 36U) + aOrbiterJ) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 29U)) + aNonceWordI) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterB, 53U));
            aWandererC = aWandererC + (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 27U)) + aPhaseBWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 21U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterF, 11U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 6U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aPrevious, 40U) + RotL64(aOrbiterH, 47U)) + aOrbiterD) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 6U));
            aCarry = aCarry + RotL64(aWandererJ, 41U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC44EA74417B764BBULL + 0xF8E720093A8B9A92ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEEB33D0CB69B0E01ULL + 0xDE794F1F1D3236BCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFBE891FB1F496D45ULL + 0xFD49594802458E50ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBCB22FEB0E0C4B4DULL + 0x97F23BBD72D8FADEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xFBA2F06EB16667C7ULL + 0xFA7D39411BB55CE7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8B6EBEEBAF129EA1ULL + 0xD4DDBF13532434BEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBDE4D3AA7B62276FULL + 0x88F388D033FAE34DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB07488EBB8ABE3AFULL + 0xCDC6CAD991A8C250ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x87EA43E4C6B41159ULL + 0xAF3DBBBB68BF7DF0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC75FAFD470F9851DULL + 0xA99D5D763E98BDA9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x86497692ED43F005ULL + 0xEAB00F462DEE5084ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x99D4F3B700041175ULL + 0xC10FEBA74819E807ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xAC8A91F60AADD2F9ULL + 0xAC8D3842AE25D609ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA93C26AEDB065EF9ULL + 0xF6FAF60E84D6D02CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD6D2F5FDD10AB941ULL + 0xE296F0CB3FCC5B3EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8B887DF7EFF982A5ULL + 0xB44E2BB0E9C2B351ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5369U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 4619U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3987U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4446U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4339U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1247U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 51U)) ^ (RotL64(aCarry, 4U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = ((aWandererA + RotL64(aCross, 51U)) + 9654059367478508868U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aScatter, 60U)) + RotL64(aCarry, 41U)) + 6473006635864677427U;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 6944184481315853243U) + aNonceWordF;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 43U)) + 4061496421939102306U) + aNonceWordH;
            aOrbiterD = (aWandererF + RotL64(aScatter, 21U)) + 15791809275719085463U;
            aOrbiterI = (((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 14050798802646323055U) + aNonceWordG;
            aOrbiterC = (((aWandererD + RotL64(aIngress, 27U)) + 12072905924741758266U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 17639076509231343896U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12195388285571234715U;
            aOrbiterB = RotL64((aOrbiterB * 4317060502521195769U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4325404419499496529U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 5910567888204238382U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11503787177122206937U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13092940059929942699U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13381962590820308761U;
            aOrbiterJ = RotL64((aOrbiterJ * 6345904465930943295U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15622862439323440527U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 14027151901132249793U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2273573821630510087U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 4584410023907605157U) + aNonceWordA;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 15763755180625487157U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 6755736130607297639U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17023059745666559199U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5298529579288492971U;
            aOrbiterI = RotL64((aOrbiterI * 2483562793328357721U), 51U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 2870152867331654736U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12017191100173748848U;
            aOrbiterH = RotL64((aOrbiterH * 9958191466506480519U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 19U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterD, 4U));
            aWandererF = aWandererF + (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 41U)) + aOrbiterC) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterI, 57U)) + aNonceWordL);
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterC, 11U)) + aNonceWordJ);
            aWandererG = aWandererG + (((((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 27U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aNonceWordI) + aPhaseDWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 50U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7978U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 10065U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 8262U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 6726U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9004U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10135U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 7850U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 9471546960258473684U) + aPhaseDOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aIngress, 28U)) + 18050235435948942244U) + aNonceWordH;
            aOrbiterH = (aWandererF + RotL64(aScatter, 57U)) + 3005107102671544641U;
            aOrbiterI = (aWandererG + RotL64(aCross, 11U)) + 17898396434573801850U;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 37U)) + 15071602525497771648U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 51U)) + 5780119462702672108U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 39U)) + 13301326224151025687U) + aNonceWordL;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 18129323022260575961U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 1199228670638790709U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1780426336211781025U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 1839199978088021020U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4999517042246790165U;
            aOrbiterC = RotL64((aOrbiterC * 4585813675677234577U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 8788607633376516299U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15143903839930468749U;
            aOrbiterI = RotL64((aOrbiterI * 12735914889325422675U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16674732686428431869U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15908873150953195581U;
            aOrbiterD = RotL64((aOrbiterD * 18049755517524334107U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11204775359756474667U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2525984309543939465U;
            aOrbiterK = RotL64((aOrbiterK * 3988529812023791571U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 4566345170476825512U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14876612901557406267U;
            aOrbiterB = RotL64((aOrbiterB * 9047956948845135339U), 47U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 14926290877038883931U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12710203178186614846U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 14841163494801662515U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 12U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 57U)) + aNonceWordO);
            aWandererE = aWandererE + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 29U)) + aOrbiterK) + RotL64(aCarry, 21U)) + aNonceWordK);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 19U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterI, 3U)) + aPhaseDWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 54U) + aOrbiterH) + RotL64(aOrbiterB, 50U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterC, 13U)) + aNonceWordG) + aPhaseDWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 28U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 11726U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 14650U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12946U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12684U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneC[((aIndex + 13285U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 23U)) + (RotL64(aIngress, 35U) ^ RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterB = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 6163290588946759209U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 50U)) + 7342672468560105447U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 21U)) + 11574563167017282321U) + aNonceWordC;
            aOrbiterE = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 2254820206194758964U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 41U)) + 1469783447473099498U) + aNonceWordH;
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 14174828900676165088U) + aNonceWordP;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 57U)) + 16277954291890598132U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14845750668693136766U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 150099699692047766U;
            aOrbiterF = RotL64((aOrbiterF * 7644895634421086357U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 1200784917165131703U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9469982764806754302U;
            aOrbiterG = RotL64((aOrbiterG * 17851969334511301943U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 10956702761701710182U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7915506894975487807U;
            aOrbiterK = RotL64((aOrbiterK * 8874108311712727983U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17335794183733623213U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 557028996286989506U;
            aOrbiterB = RotL64((aOrbiterB * 3993359298602424281U), 51U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 1597385667771002414U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 4376417959915162639U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4626236858205178149U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 549770198518993876U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 756554555648070919U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 16272320259614325355U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7298557532533152193U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3336802611342112013U;
            aOrbiterJ = RotL64((aOrbiterJ * 14679103452120080499U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 41U)) + aOrbiterF) + aPhaseDWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 3U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterB, 51U));
            aWandererH = aWandererH + ((((RotL64(aCross, 42U) + RotL64(aOrbiterK, 21U)) + aOrbiterJ) + aNonceWordL) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterJ, 29U)) + aNonceWordO);
            aWandererA = aWandererA + ((((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterG, 10U)) + RotL64(aCarry, 47U)) + aNonceWordN);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterE, 35U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 17116U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 18041U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 17410U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21133U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 20652U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 35U)) ^ (RotL64(aCross, 6U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 11U)) + 18087125778766689269U) + aNonceWordL;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 5U)) + 13710545066503235196U) + aNonceWordP;
            aOrbiterB = ((aWandererE + RotL64(aCross, 43U)) + 1701939704736254645U) + aNonceWordB;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 60U)) + RotL64(aCarry, 5U)) + 8064093611384019909U;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 39U)) + 16623332751533885431U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 15590129153794910109U) + aNonceWordE;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 37U)) + 7413312683079107383U) + aPhaseDOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4186064478651458810U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5501191643940735954U;
            aOrbiterB = RotL64((aOrbiterB * 14254804649177125269U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 11064645242200570835U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13825922087298055833U;
            aOrbiterG = RotL64((aOrbiterG * 7529317892716108867U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5944980709887369970U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8181136916070569646U;
            aOrbiterC = RotL64((aOrbiterC * 395183021205661827U), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 15442336949157292482U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11580554435240641337U;
            aOrbiterH = RotL64((aOrbiterH * 6654637892858767739U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 11240018128174598322U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2027565596050777471U;
            aOrbiterK = RotL64((aOrbiterK * 18048186560314431815U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16425887196883725233U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 16828683527588834095U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17746289103235902485U), 57U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 9923829146479008804U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6669171007279929454U;
            aOrbiterD = RotL64((aOrbiterD * 681823450939955099U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 27U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 11U)) + aOrbiterD) + aNonceWordK);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 36U) + aOrbiterD) + RotL64(aOrbiterH, 47U));
            aWandererA = aWandererA + ((((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 51U)) + aNonceWordM);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 3U)) + aOrbiterF) + aNonceWordH);
            aWandererB = aWandererB + (((((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterH, 58U)) + RotL64(aCarry, 29U)) + aNonceWordJ) + aPhaseDWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 19U)) + aOrbiterD) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 28U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 23429U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((aIndex + 27089U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 25922U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25836U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 24242U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 11U) ^ RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 4U)) + 77518479758428414U) + aNonceWordD;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 29U)) + 4832061802166300011U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 11695291171006574112U;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 19U)) + 7467412817843260094U) + aNonceWordN;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 35U)) + 17801484124471154757U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 5555455638503958639U;
            aOrbiterD = (aWandererH + RotL64(aCross, 41U)) + 5669470540733721606U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 3042388456327784163U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2236734925228156691U;
            aOrbiterK = RotL64((aOrbiterK * 10076582424701705531U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14459720401528685450U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4814967631216658856U;
            aOrbiterH = RotL64((aOrbiterH * 18288097536171386643U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 16950679344449075945U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6262238639302011050U;
            aOrbiterA = RotL64((aOrbiterA * 9942659897425088183U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3522256359074996724U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12524717897707074242U;
            aOrbiterC = RotL64((aOrbiterC * 6787771338063891989U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13891759914865623828U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 11910250571469028666U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 12311343917878428995U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 2240189915640314069U) + aNonceWordE;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 5365912986308810837U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15133972552032469957U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9323732721344489753U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 13087326560957916553U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14659491687401151733U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 12U) + RotL64(aOrbiterH, 53U)) + aOrbiterK) + aNonceWordI);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 37U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aNonceWordJ);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterF, 11U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 29U)) + aOrbiterK) + aNonceWordP) + aPhaseDWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 23U)) + aOrbiterC) + aNonceWordO);
            aWandererE = aWandererE + ((((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterA, 60U)) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterA, 43U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 4U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 28477U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneA[((aIndex + 28831U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 29786U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 30188U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30250U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aCross, 20U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = (aWandererK + RotL64(aIngress, 13U)) + 7893287783892523139U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 51U)) + 10257331997383491153U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 35U)) + 14562226733652231753U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 53U)) + 14320342577110737851U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 29U)) + 9816717579822880756U) + aNonceWordO;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 35U)) + 9558926960095881953U) + aNonceWordK;
            aOrbiterC = (((aWandererF + RotL64(aScatter, 6U)) + RotL64(aCarry, 21U)) + 9230371862654338324U) + aPhaseDOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 6414274291252913420U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13868546184398350849U;
            aOrbiterK = RotL64((aOrbiterK * 1547986864837497409U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 16940736952569949038U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 2866957764814864371U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 3554702178644797003U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 7916721976073979724U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1602444214978842275U;
            aOrbiterC = RotL64((aOrbiterC * 11072503711308122385U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9529061385251008037U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8402775110887376588U;
            aOrbiterH = RotL64((aOrbiterH * 13980225144628227381U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15003592180290390713U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14195681406520825751U;
            aOrbiterA = RotL64((aOrbiterA * 11455000833788877217U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3263577002367714202U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 12019422062655581928U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5002313835338447799U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 8508638054582582917U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6536618106353552880U;
            aOrbiterJ = RotL64((aOrbiterJ * 6233964121117511885U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 46U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 13U)) + aPhaseDWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 35U)) + aOrbiterE) + aNonceWordJ) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterF, 3U));
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 48U)) + aOrbiterC) + aNonceWordG);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterH, 21U)) + aNonceWordL);
            aWandererH = aWandererH + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 57U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 57U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC05958A2944523EDULL + 0xE27ABD170DF71468ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xABA2C760BDAD4A9BULL + 0x91FD05964EF9BCDBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x97B9C61ED0CC0B29ULL + 0xDE0A6AE19E16C748ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB9DF21967B2DE569ULL + 0x9A698916BECB39E0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9B7E3C46554362B5ULL + 0xD0CC23E0E0E3AB3BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB5717606E6707A93ULL + 0x821CAE531AF3D1E6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8C97B779DED951EBULL + 0xDACB442EC85A7ADEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA887A1A68646F72BULL + 0xA181BB39E5990749ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8C1862799CB1D299ULL + 0xBBD5E3BE4F76E90BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCCEDA2E0F9396D6BULL + 0x824E2331E34F448EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xAC584EA27DA79F6DULL + 0xC8B3A0B1D98563F9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD27F9728EA1D8D5BULL + 0x89AD53F3170B1F0FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC4644F8BC5BDE8E1ULL + 0xB9E324FE94B312B5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA030BD4C261CE5A3ULL + 0xA6B878780F46884FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xEE29BE7B3DA04F9BULL + 0x9E2694F0A4BBAD2DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xBE8583E10054645FULL + 0x8D0E54348D738BDBULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 1199U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneB[((aIndex + 3821U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1707U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 1365U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 2394U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4940U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 21U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 39U)) + 5173905450211892891U;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 54U)) + RotL64(aCarry, 57U)) + 3555542451908039957U) + aNonceWordF;
            aOrbiterD = (aWandererC + RotL64(aIngress, 47U)) + 11559884700283861559U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 1352524329968738673U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 29U)) + 8914206450420616349U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 23U)) + 2251523378498463946U) + aNonceWordC;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 11U)) + 9541575923299247038U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 41U)) + 1239854507907214595U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 3U)) + 17698101462598498934U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aIngress, 52U)) + 12305566971683256060U) + aNonceWordN;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 43U)) + 13804545036303215569U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 10239749097704329264U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4212214906286320308U;
            aOrbiterD = RotL64((aOrbiterD * 3661436621615751071U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12192418916967430783U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 4475514289326450361U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 17497164630368757887U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17376102613298827459U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 18129393209955439341U;
            aOrbiterJ = RotL64((aOrbiterJ * 6404089025014118979U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4014763724300253568U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 17325007199676828814U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 1420888274815627083U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 15480474849292388685U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 14357924730184375449U;
            aOrbiterF = RotL64((aOrbiterF * 16723492259068034209U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4335731868597970070U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8296023680394303015U;
            aOrbiterA = RotL64((aOrbiterA * 14027415401430120543U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2807312426993262800U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15510369660839648501U;
            aOrbiterH = RotL64((aOrbiterH * 18207954408298333959U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 12597844696606519907U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7231012798553551535U;
            aOrbiterG = RotL64((aOrbiterG * 2841306785994479299U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 849663631945232360U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 4002310581470781194U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 2148877014350721479U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16067735571435654555U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4607980694199923842U;
            aOrbiterI = RotL64((aOrbiterI * 10401780756830017477U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 5346879191913449715U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5173905450211892891U;
            aOrbiterK = RotL64((aOrbiterK * 15360571827429301833U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (RotL64(aOrbiterC, 20U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 58U) + RotL64(aOrbiterF, 21U)) + aOrbiterE) + aNonceWordE) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterI, 53U)) + aPhaseEWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 18U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 39U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aCross, 51U) + RotL64(aOrbiterG, 11U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aNonceWordG);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 22U) + RotL64(aOrbiterB, 3U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterK, 57U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 46U)) + aOrbiterK) + aNonceWordK);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 13U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 51U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6269U)) & S_BLOCK1], 60U) ^ RotL64(aInvestLaneC[((aIndex + 8265U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 6661U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 6423U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 6106U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 6840U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8193U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 36U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = (((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 4384716820085860551U) + aPhaseEOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (((aWandererA + RotL64(aCross, 58U)) + RotL64(aCarry, 39U)) + 9715780315942116888U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aPrevious, 43U)) + 15963520052789178632U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 39U)) + 14346700690686392938U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 27U)) + 6005518012489966643U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 21U)) + 2506732930310252119U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 3U)) + 16782163084851775826U) + aNonceWordL;
            aOrbiterB = (aWandererI + RotL64(aCross, 11U)) + 823673076571076303U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 13U)) + 1634084509064077736U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 56U)) + RotL64(aCarry, 3U)) + 1288134975466877686U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 37U)) + 2998220403162908444U) + aNonceWordE;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 220430672180734911U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10223923547068528867U;
            aOrbiterK = RotL64((aOrbiterK * 12577370238343872139U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11696469696177647608U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6545430420379636963U;
            aOrbiterG = RotL64((aOrbiterG * 8387163146257553773U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 79691451831797107U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8971444023498649419U;
            aOrbiterH = RotL64((aOrbiterH * 7148919880477390009U), 47U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 5624403902454498793U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9468064161002030997U;
            aOrbiterC = RotL64((aOrbiterC * 8243560528100864595U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4619361544913629805U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12682446273369750704U;
            aOrbiterB = RotL64((aOrbiterB * 10879074713156075641U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8728730962617599223U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9099675924074253030U;
            aOrbiterI = RotL64((aOrbiterI * 5525644236954497523U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3298303921318288541U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 5953276499411658358U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 10565471305001292693U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6725769507592688539U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 1057277456510215817U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8269412198279297075U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11317925732206917722U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 17814749417006079067U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4369209051015735925U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9258362135343403308U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4873837345446960113U;
            aOrbiterF = RotL64((aOrbiterF * 14223381466269503273U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7863380865835889675U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4384716820085860551U;
            aOrbiterA = RotL64((aOrbiterA * 2003891033298374621U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 10U);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 34U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterB, 3U)) + aNonceWordI);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterJ, 5U)) + aNonceWordO) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 60U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterE, 57U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 46U) + RotL64(aOrbiterC, 35U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 19U)) + aOrbiterD) + aNonceWordC) + aPhaseEWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 54U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterE, 39U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterA, 41U)) + aNonceWordP);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 28U) + RotL64(aOrbiterD, 47U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 27U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 40U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 14067U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneA[((aIndex + 13611U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 11339U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 16086U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 14771U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 41U)) ^ (RotL64(aCross, 11U) ^ RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (aWandererF + RotL64(aScatter, 5U)) + 16922357079016918108U;
            aOrbiterC = ((((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 11771749797137599131U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 4635668433708036077U) + aNonceWordI;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 39U)) + 15827952719230577008U;
            aOrbiterI = (aWandererA + RotL64(aCross, 24U)) + 1495675306110023086U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 27U)) + 7294835466949728365U;
            aOrbiterG = (((aWandererG + RotL64(aScatter, 53U)) + 179122461212041978U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 13U)) + 545981421632236251U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 35U)) + 15338259639814630535U) + aNonceWordF;
            aOrbiterE = (aWandererK + RotL64(aCross, 10U)) + 12924313840290895215U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 17846785921286020610U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5721472794107057875U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16359630793856870319U;
            aOrbiterH = RotL64((aOrbiterH * 14186771515526698907U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10614102110239037308U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 16421992251278236531U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2561232904676068089U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 8668149834861244963U) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12699331834360948734U;
            aOrbiterG = RotL64((aOrbiterG * 2249360824172616357U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4470693178142950471U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 526000656022724741U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16688501462334673493U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6880246132270094141U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7126466778855297013U;
            aOrbiterK = RotL64((aOrbiterK * 5692237926830293205U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6436404501390442054U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1213633065612242699U;
            aOrbiterF = RotL64((aOrbiterF * 17604454985534439259U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8186529105901185854U) + aNonceWordN;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 10607460957358250935U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17172191011625677861U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9743278964993305169U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14007577681873418075U;
            aOrbiterA = RotL64((aOrbiterA * 4231122580398039133U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11636165671710638530U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9334375905020670988U;
            aOrbiterC = RotL64((aOrbiterC * 8801600439900803907U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4261340110915336428U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12336921031446129288U;
            aOrbiterE = RotL64((aOrbiterE * 2306768964600968743U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2029125959974424325U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 16922357079016918108U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8718484611517064455U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 42U);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 20U) + RotL64(aOrbiterD, 5U)) + aOrbiterB) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterJ, 41U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterE, 21U)) + aNonceWordH);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterK, 43U));
            aWandererE = aWandererE + ((((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 35U)) + aNonceWordO);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterD, 52U)) + aNonceWordL);
            aWandererF = aWandererF + ((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 23U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 47U)) + aOrbiterC) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + aNonceWordG);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 57U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 58U) + aOrbiterB) + RotL64(aOrbiterE, 34U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 10U));
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17344U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneA[((aIndex + 17333U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 18977U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 20192U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneD[((aIndex + 18223U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 60U) ^ RotL64(aCross, 39U)) ^ (RotL64(aCarry, 27U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = ((aWandererE + RotL64(aIngress, 27U)) + 4622023259121087483U) + aPhaseEOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 57U)) + 10253505250223501352U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 17133877904420462669U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 21U)) + 6162827793741796700U) + aNonceWordM;
            aOrbiterB = (aWandererA + RotL64(aScatter, 18U)) + 9610986424765907615U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 11210747154264753754U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 16554205219580654546U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 11U)) + 10352576357413766388U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 13U)) + 3651845783283479752U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 44U)) + 18145542190463500476U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 23U)) + 5415609566767162857U) + aNonceWordI;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2033734872464201570U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 3507213117125813345U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5453058336688881113U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8716253393049851856U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 695984869565941856U;
            aOrbiterG = RotL64((aOrbiterG * 8377921610764044735U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7661578828878284931U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 906654265099155956U;
            aOrbiterB = RotL64((aOrbiterB * 8117625377607536949U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 6050049984731254612U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17882717590338190821U;
            aOrbiterE = RotL64((aOrbiterE * 10807367411402733215U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 4996521991532815957U) + aNonceWordO;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 4246460672800604436U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 12047466401960824903U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8700148116452518842U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10039050281847466206U;
            aOrbiterI = RotL64((aOrbiterI * 11884791271239660157U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4513844680425845372U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3037563127442815153U;
            aOrbiterD = RotL64((aOrbiterD * 18363509277992292407U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 1005237931570968724U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 1373258132025712065U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 10458020799382532395U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 12759144329395682277U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5139371668116336931U;
            aOrbiterK = RotL64((aOrbiterK * 10761543179345026943U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3211005174890625715U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 18045286961878287418U;
            aOrbiterC = RotL64((aOrbiterC * 4536094526540761611U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4454078771279674978U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4622023259121087483U;
            aOrbiterA = RotL64((aOrbiterA * 8991756794989027019U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 56U);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 18U) + RotL64(aOrbiterF, 24U)) + aOrbiterJ);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterF, 47U)) + aNonceWordD);
            aWandererH = aWandererH + ((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterG, 27U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterC, 43U));
            aWandererC = aWandererC + ((RotL64(aScatter, 56U) + aOrbiterH) + RotL64(aOrbiterD, 18U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 5U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 21U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 11U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterF, 37U)) + aNonceWordN) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 35U) + RotL64(aOrbiterH, 53U)) + aOrbiterA) + aNonceWordC) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (RotL64(aWandererK, 42U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 40U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22100U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneB[((aIndex + 22762U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 26362U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22052U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 23076U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 50U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = (aWandererK + RotL64(aCross, 13U)) + 2783898056762489197U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 44U)) + 7177192902873343053U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 3U)) + 12254703232691980774U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 15446547245691219559U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 29U)) + 888475203006174856U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aIngress, 46U)) + 3649183529366307877U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 19U)) + 4642631047518805167U;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 37U)) + 6108329730724782250U) + aPhaseEOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 37U)) + 8334054653023816636U) + aNonceWordK;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 27U)) + 5891895375031474350U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 39U)) + 3176720746238477862U) + aNonceWordA;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6111038696865301675U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11914998302228682704U;
            aOrbiterG = RotL64((aOrbiterG * 11738924766359642853U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 17005063057791320948U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 18333780598768130670U;
            aOrbiterB = RotL64((aOrbiterB * 5416759844884107303U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 2056115016443263153U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10245512728872962677U;
            aOrbiterI = RotL64((aOrbiterI * 707106795383284903U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4810366069422162351U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3051442983125942469U;
            aOrbiterJ = RotL64((aOrbiterJ * 13558537578054436423U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9285068547223654308U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13067251130180968842U;
            aOrbiterA = RotL64((aOrbiterA * 7000687697769766605U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 3203670242792002165U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1770881716916463461U;
            aOrbiterK = RotL64((aOrbiterK * 13870229847371882171U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16286823712870537410U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13067191141829694202U;
            aOrbiterD = RotL64((aOrbiterD * 15629974528467350445U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 3414576315085336932U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8979691827341555245U;
            aOrbiterF = RotL64((aOrbiterF * 15971594804040295757U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11370607523115189596U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1346943598249651668U;
            aOrbiterC = RotL64((aOrbiterC * 4994794423314630209U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 2441719135451272926U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3347272129827184676U;
            aOrbiterE = RotL64((aOrbiterE * 10434510775894776597U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 1116857329130532047U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2783898056762489197U;
            aOrbiterH = RotL64((aOrbiterH * 9504855173533274401U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (RotL64(aOrbiterC, 48U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterF, 11U)) + aNonceWordG);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterA, 27U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterD, 3U)) + aNonceWordC);
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterH, 23U));
            aWandererK = aWandererK + ((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 43U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 56U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 37U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterI, 29U)) + aNonceWordE) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterA, 20U)) + aOrbiterG) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 34U) + aOrbiterB) + RotL64(aOrbiterE, 53U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 38U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27808U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneA[((aIndex + 28653U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 27609U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27437U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneB[((aIndex + 28846U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 48U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 3U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = ((aWandererJ + RotL64(aCross, 43U)) + 15652862298542575895U) + aPhaseEOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 6U)) + RotL64(aCarry, 47U)) + 16925323928418184554U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 41U)) + 4413861484961668394U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 19U)) + 2215946422098155969U;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 47U)) + 14975185533513111110U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (aWandererF + RotL64(aCross, 3U)) + 9711613814905834552U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 41U)) + 13154957291850149471U) + aNonceWordH;
            aOrbiterI = (aWandererC + RotL64(aScatter, 10U)) + 5058313016418534840U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 23U)) + 15011423472941211620U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 39U)) + 2030053257469580168U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 150530795186791193U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 10878237472104183427U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 11724672539469573109U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16158741837357985395U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 9589700906445846956U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1367381624958248949U;
            aOrbiterF = RotL64((aOrbiterF * 8459515089081211977U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12003215666757518106U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11232479330848006729U;
            aOrbiterI = RotL64((aOrbiterI * 10993290955464593033U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 13013910456628561621U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6092509838924105265U;
            aOrbiterH = RotL64((aOrbiterH * 805601154718006061U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11999225836250312801U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14421271973875748413U;
            aOrbiterC = RotL64((aOrbiterC * 9529010940887430157U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15536288285741825272U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2071793889925436679U;
            aOrbiterD = RotL64((aOrbiterD * 1526376970151714589U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5622386476463436967U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16147972771639168516U;
            aOrbiterE = RotL64((aOrbiterE * 11826916832825159095U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4519892856053952290U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12059500374938843538U;
            aOrbiterA = RotL64((aOrbiterA * 14987533625537956299U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4547335128847992282U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 15378473334472216418U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 13907560285280544037U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 14644123269581735633U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6434315615480805381U;
            aOrbiterB = RotL64((aOrbiterB * 4335857173941645355U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14241680137158382296U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 15652862298542575895U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 4190840063924551519U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 57U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterJ, 12U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 47U)) + aOrbiterG) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 27U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 30U) + aOrbiterA) + RotL64(aOrbiterE, 53U)) + aNonceWordL);
            aWandererK = aWandererK + ((((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 41U)) + aNonceWordD);
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 23U)) + aNonceWordA);
            aWandererD = aWandererD + ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 35U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterF, 3U));
            aWandererA = aWandererA + ((RotL64(aIngress, 24U) + aOrbiterA) + RotL64(aOrbiterD, 37U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 39U)) + aOrbiterJ) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC3001E31D1F2A6C3ULL + 0x9AEC7087C0A722C5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9686AB0AE0D954C1ULL + 0xA4BC3030444662D3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xDC99070C4C18ACDFULL + 0x956C8B2883D306D0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCEAE1CA6237230E7ULL + 0xBEAEC55B0B76F460ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9F0532053D923BD3ULL + 0x9A769418B936F561ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x967921209C2A03CDULL + 0xB472D11726EECD9FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8E7075120B2933F1ULL + 0x9BA478ECF2E19AFAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF9E849CD44A5B4EBULL + 0xD73CC9DC0A2BCEB9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8A32AB123542E8E9ULL + 0xDAE9B396C3B3CFF5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA76E30BD97E6B0FDULL + 0xC6D1139E42F82471ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA773F8C70EF78731ULL + 0xC65BB8EE8B48F4C1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xEA004E090713C143ULL + 0xFB8396CF72492E1CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xAEBA6E4198FE369DULL + 0xD527D58A31295497ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDE1B7D4B95CA9DE5ULL + 0x9C821C1FCF81FAB3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xDDAFA93CD62F27DDULL + 0xA06F351CA51B2CBCULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC8AD8FF441B61AC9ULL + 0x999188CF764B4B45ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1337U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 3742U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1116U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4353U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3949U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1827U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 20U)) + 17668251151213543491U;
            aOrbiterD = (aWandererK + RotL64(aCross, 5U)) + 16101602509895104517U;
            aOrbiterC = ((((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 9083915270773304935U) + aPhaseFOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aWandererE + RotL64(aIngress, 13U)) + 12810720730318214811U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 19U)) + 18113428002071925621U;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 47U)) + 1582208899354109878U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 36U)) + 4180688104819188154U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 43U)) + 8954598189262820611U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 15360094153175355879U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8383954114668216260U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 15626783326234049197U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 15058420415480073793U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10609978564404958066U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 17656516608997517984U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4590620354119899777U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 760077259110786536U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 3597338735888033063U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 6548831472863517621U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 4431777844935985157U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 10710423172154671296U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16267496318491473315U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 10240882795242085185U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7826053487019825891U;
            aOrbiterG = RotL64((aOrbiterG * 15053729937684375907U), 39U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 9418883403715727353U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11507423614799075545U;
            aOrbiterE = RotL64((aOrbiterE * 16189463984557044693U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11545217316421066655U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 617921402135485341U;
            aOrbiterB = RotL64((aOrbiterB * 8182920764965471653U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14456933220749921009U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7990243583564535387U;
            aOrbiterF = RotL64((aOrbiterF * 5994900368027985469U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14023633125757654751U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11319146808574958827U;
            aOrbiterA = RotL64((aOrbiterA * 13676159969338309307U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 20U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterF, 23U)) + aNonceWordE) + aPhaseFWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 58U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 3U)) + aNonceWordC);
            aWandererE = aWandererE ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterD, 28U)) + aOrbiterH) + aPhaseFWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 35U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 51U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aCross, 52U) + aOrbiterK) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 43U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterC, 19U)) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterH, 12U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6182U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneC[((aIndex + 7395U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9932U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 6936U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9502U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8053U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8137U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aPrevious, 53U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = ((aWandererE + RotL64(aScatter, 43U)) + 2177539223979303669U) + aNonceWordO;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 29U)) + 3962004686551521471U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 13U)) + 8457602312617147662U) + aNonceWordE;
            aOrbiterH = (aWandererD + RotL64(aCross, 52U)) + 18011802451816510632U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 9046101759168876832U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 11135620637431969597U) + aNonceWordJ;
            aOrbiterK = ((aWandererA + RotL64(aCross, 39U)) + 15913029940697999701U) + aPhaseFOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aIngress, 48U)) + 16304193109948135982U) + aPhaseFOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aScatter, 57U)) + 13208892298820080981U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4182377898949419225U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 13970137023071326151U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9075061559681739865U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8402396284835248583U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8859190834060657829U;
            aOrbiterC = RotL64((aOrbiterC * 13552418608113716117U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9760005337757990392U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14108277760135744897U;
            aOrbiterI = RotL64((aOrbiterI * 4474681104256093885U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12226316121949012350U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3456392186754113960U;
            aOrbiterD = RotL64((aOrbiterD * 8704729827929941215U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5004087958637038973U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7176881295123125567U;
            aOrbiterA = RotL64((aOrbiterA * 15272157962928021009U), 47U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 10889800478505074438U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 13728832441482547824U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17588477761978646139U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17345665880706866772U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 301139993853297566U;
            aOrbiterE = RotL64((aOrbiterE * 5812445396758354505U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2061389844760610160U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 13631862266139238355U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 143613352104722701U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10767186080827509622U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4893486019456886013U;
            aOrbiterH = RotL64((aOrbiterH * 5194746459545610901U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (RotL64(aOrbiterC, 26U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterF, 11U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 54U) + RotL64(aOrbiterI, 47U)) + aOrbiterK) + RotL64(aCarry, 39U)) + aNonceWordP);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 23U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 43U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterE, 30U));
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 39U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterC, 57U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterF, 35U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterI, 52U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15111U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((aIndex + 15117U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 13415U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 13646U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 11348U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 27U)) + (RotL64(aCarry, 13U) ^ RotL64(aIngress, 42U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = (aWandererH + RotL64(aCross, 14U)) + 16651241552253078315U;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 4558144676982478003U) + aPhaseFOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aScatter, 47U)) + 8814884320080367550U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 41U)) + 16011579668555672117U) + aNonceWordJ;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 57U)) + 4738918668759862438U) + aPhaseFOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = ((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 12526083125540985108U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 39U)) + 8048723561746000552U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 19U)) + 1082218464034639039U) + aNonceWordB;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 6U)) + 8432043246965946816U) + aNonceWordC;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9982080524048636852U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6720069955755215919U;
            aOrbiterC = RotL64((aOrbiterC * 1025046364205332059U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1019035028070247757U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7360619079463870467U;
            aOrbiterG = RotL64((aOrbiterG * 6623074813047915863U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10893918488381348474U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1390297670907738019U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 11909657437658597735U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12512200589031203480U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 14741471280748399540U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3012135242889901095U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 8543897248359826770U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8545972622733791272U;
            aOrbiterD = RotL64((aOrbiterD * 11793879362775346821U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7049384618581928664U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14730773807906925408U;
            aOrbiterA = RotL64((aOrbiterA * 10711566871536755073U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11480717275652449986U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 1135397594974536859U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6347492892938856497U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6897207625849516702U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10920630712550287148U;
            aOrbiterJ = RotL64((aOrbiterJ * 4140705091806993359U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 1094056478999931332U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 6784487144549717207U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 6295177724167067891U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 14U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 47U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterD, 37U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 56U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 54U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 23U)) + aOrbiterJ);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterG, 41U)) + aNonceWordH);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterG, 3U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterH, 28U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19703U)) & S_BLOCK1], 54U) ^ RotL64(aSnowLaneA[((aIndex + 20692U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 18393U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 21775U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((aIndex + 20160U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 10U) + RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = ((((aWandererG + RotL64(aCross, 46U)) + RotL64(aCarry, 13U)) + 3970829908171131502U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 13U)) + 7040283759419531991U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 29U)) + 11856292169397052901U) + aNonceWordM;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 3U)) + 819598588791819022U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 50U)) + RotL64(aCarry, 5U)) + 2176451710970866848U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 37U)) + 6454704928613390494U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 19U)) + 11792122387218053841U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 21U)) + 9254780213489752211U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 57U)) + 16591812589999846482U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1471246223935074832U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1424843083106386453U;
            aOrbiterE = RotL64((aOrbiterE * 15020536982657410783U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 1856469958050891629U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 6331743690452052712U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 15327924647897459645U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10351075711345476487U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9518585245330480185U;
            aOrbiterB = RotL64((aOrbiterB * 3792179827396760391U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17787514620244712033U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 14182328067398162557U;
            aOrbiterF = RotL64((aOrbiterF * 18107337388659070197U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12798088948801072444U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9563215159275202323U;
            aOrbiterJ = RotL64((aOrbiterJ * 7058145016617349141U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9904919772580498232U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 16579777394992143043U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 10516761340320196661U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6344049286854588503U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3531503618941046788U;
            aOrbiterA = RotL64((aOrbiterA * 10855385899703024105U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 11334308840132700377U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 11093833870078787770U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16105889714648555755U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3831491136025364271U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12505259454860591372U;
            aOrbiterH = RotL64((aOrbiterH * 6135450888433504093U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 34U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 53U)) + aOrbiterE) + aNonceWordG) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 4U) + aOrbiterD) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterC, 23U)) + aNonceWordB);
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterD, 36U)) + aNonceWordE);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterF, 13U)) + aNonceWordC) + aPhaseFWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 43U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aCross, 24U) + RotL64(aOrbiterG, 27U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 58U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 24U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24591U)) & S_BLOCK1], 12U) ^ RotL64(aSnowLaneB[((aIndex + 27024U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 22034U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23446U)) & S_BLOCK1], 50U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 25899U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 5U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = ((aWandererE + RotL64(aScatter, 47U)) + 15549114274303128055U) + aPhaseFOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 23U)) + 16466750056388063241U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 4U)) + RotL64(aCarry, 43U)) + 12209449840836787142U;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 27U)) + 14551496099734294336U) + aPhaseFOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 6266576428679808622U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 19U)) + 16892841575635668152U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 43U)) + 7375966221423362125U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 60U)) + 11926105302821753530U) + aNonceWordH;
            aOrbiterH = (aWandererH + RotL64(aScatter, 35U)) + 16219253791550461124U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 7299056065319248160U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15234001484933728439U;
            aOrbiterA = RotL64((aOrbiterA * 8182244796017018911U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 6615802589932632120U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 5481176858895819247U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 3604590158551984877U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 17220507586542139380U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14137921473739415340U;
            aOrbiterI = RotL64((aOrbiterI * 10634645686035907603U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 16981960446540932787U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10897565927079518588U;
            aOrbiterD = RotL64((aOrbiterD * 418843936329303571U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2746889569299593263U) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4894117146736361379U;
            aOrbiterH = RotL64((aOrbiterH * 2656750612042673191U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 18294823016957137777U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 86828501068883383U;
            aOrbiterF = RotL64((aOrbiterF * 11432686669235402365U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6322053762209547826U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 6754524552483363820U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1746163087826694641U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7306452650619361017U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12717201204443785828U;
            aOrbiterE = RotL64((aOrbiterE * 6121251603905574991U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 10422327053543898585U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14786413282036348183U;
            aOrbiterJ = RotL64((aOrbiterJ * 8713024293107068275U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 40U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 53U)) + aOrbiterA) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 48U) + aOrbiterD) + RotL64(aOrbiterI, 3U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterF, 30U)) + RotL64(aCarry, 21U)) + aNonceWordD);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterF, 47U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterH, 13U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterC, 35U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aPrevious, 36U) + aOrbiterE) + RotL64(aOrbiterC, 22U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 26U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27585U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 27332U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 29861U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32625U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 29430U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aPrevious, 11U)) + (RotL64(aIngress, 58U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (aWandererD + RotL64(aIngress, 19U)) + 15920462086654025436U;
            aOrbiterH = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 51U)) + 487844076858004017U) + aNonceWordJ;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 47U)) + 14502883786442630566U) + aPhaseFOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 39U)) + 3787107318658233674U) + aPhaseFOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aScatter, 34U)) + RotL64(aCarry, 39U)) + 12548777544693755491U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 5U)) + 4907309444075181683U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 18342396700266492072U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 43U)) + 13503051997624242670U) + aNonceWordF;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 26U)) + 17845742460521374571U) + aNonceWordO;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8640887211877858169U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5273913123709097537U;
            aOrbiterI = RotL64((aOrbiterI * 1661149444148461791U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17756844173695563883U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 6713055830729302951U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2832836748513174311U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5106468334224035972U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10228769728713526172U;
            aOrbiterJ = RotL64((aOrbiterJ * 9760310686414358435U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 7687649520668883142U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7757480627354711605U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7222553727737349209U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10876291698508634557U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 8149278085586014186U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 8577133863470695381U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15592893988925610485U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8639028256640537165U;
            aOrbiterE = RotL64((aOrbiterE * 1880655276432963955U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 475660347892196219U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 1903736092401853832U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8486318978769094799U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12463250192809450953U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 7253918448601703982U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 3821034106528009129U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5171661020093804486U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11627344933828324146U;
            aOrbiterA = RotL64((aOrbiterA * 5388047063152043277U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 12U) + RotL64(aOrbiterI, 53U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aNonceWordB);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterC, 18U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 23U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 43U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aScatter, 34U) + aOrbiterF) + RotL64(aOrbiterA, 39U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI) + aNonceWordD) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterE, 29U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 12U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 50U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xAA87B5B662B07FF1ULL + 0xA088FC2929CF5B0CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC20785ABF148BE7BULL + 0xBACB9F16FCA86A3EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF1F326DD83C0D033ULL + 0xF257C9A1E3E9E65CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD09CA390CD27602BULL + 0x8C69C6E088C83478ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x81A74BD6BF339EA7ULL + 0xAE5105EF8C1995C8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF0F9CE5B9C06CC15ULL + 0xE786216CE0978493ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA448CD193D1025BDULL + 0x98D7EAD5152C3D1EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD34A538FB08A2945ULL + 0xB0DA1B61CE22936CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA474D16BF31A4D51ULL + 0x94A183CAAF961D70ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8F6D06B6984E9D39ULL + 0x8D341DE3D1DEE9A1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9B3D228A3AB9F6D5ULL + 0x9B201DF88633EB98ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA1E101510182FD17ULL + 0xDB549B76AC4CBF2AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC08E773B6EB25859ULL + 0x940AC69B1DF47E24ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x95ACC0B92DB71B19ULL + 0x93D904D525E6EDDAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xFFB10CDC565CE4EBULL + 0xBEDDF1FC74CB62AFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x80F34820F74E1857ULL + 0xC46E531F390D6077ULL);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 3730U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneB[((aIndex + 1031U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3493U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 5319U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 4445U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3756U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 52U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = ((aWandererG + RotL64(aScatter, 5U)) + 12380376990224645149U) + aNonceWordH;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 41U)) + 18296928500297384014U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 35U)) + 3550626816361145100U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 2667792936946706027U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 51U)) + 12020969779370926953U) + aNonceWordL;
            aOrbiterC = ((((aWandererJ + RotL64(aIngress, 58U)) + RotL64(aCarry, 11U)) + 737340727886903447U) + aPhaseHOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 29U)) + 1681797651799760502U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 2956186342689489064U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 1876852870402977177U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 8875540081346621757U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 6433205819353555071U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9065076854974222998U;
            aOrbiterD = RotL64((aOrbiterD * 5459675878087242021U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 3254410578766789992U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2005081975473815576U;
            aOrbiterH = RotL64((aOrbiterH * 9947701153722014085U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15992999234834560419U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3458344156815120948U;
            aOrbiterB = RotL64((aOrbiterB * 1668460113964608051U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17069783053664877727U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1260234710193913099U;
            aOrbiterC = RotL64((aOrbiterC * 4561226779897414381U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3825186451876061335U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2905344294992827535U;
            aOrbiterK = RotL64((aOrbiterK * 2469896090698580795U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 18141402347899180617U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 8760129857609925066U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 2507999156108123047U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 29U);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 60U) + RotL64(aOrbiterD, 27U)) + aOrbiterC) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterK, 51U));
            aWandererD = aWandererD + (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterI, 3U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterK, 60U));
            aWandererI = aWandererI + (((((RotL64(aCross, 23U) + RotL64(aOrbiterA, 35U)) + aOrbiterB) + RotL64(aCarry, 53U)) + aNonceWordM) + aPhaseHWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 41U)) + aOrbiterH);
            aWandererF = aWandererF + (((((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 29U)) + aNonceWordD) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5714U)) & S_BLOCK1], 58U) ^ RotL64(aSnowLaneC[((aIndex + 7902U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 10046U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneC[((aIndex + 6273U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 6631U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 9451U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 8070U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aPrevious, 43U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 14U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = (aWandererD + RotL64(aIngress, 37U)) + 18302975933754610273U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 3U)) + 16736972646771456082U) + aNonceWordB;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 29U)) + 17389406266488137442U) + aNonceWordM;
            aOrbiterE = ((aWandererK + RotL64(aCross, 57U)) + 5252511566486165539U) + aPhaseHOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 53U)) + 5730715427422747640U) + aNonceWordH;
            aOrbiterI = (((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 29U)) + 6412695646456045825U) + aNonceWordK;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 10U)) + RotL64(aCarry, 5U)) + 9539701605708994494U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 18355107116412945722U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 11735742491750132942U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18129835093627763685U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12363819388562658842U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5861430292304371543U;
            aOrbiterA = RotL64((aOrbiterA * 12989055611235382695U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 15027487084595017708U) + aNonceWordI;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 7012850020745791926U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15952928839355613939U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11904871669287886120U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11199760114477343208U;
            aOrbiterD = RotL64((aOrbiterD * 7156374911847525867U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3856004502263742700U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 3705931243173921893U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10334871178498711485U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12305785390539209389U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 18057980996551978823U;
            aOrbiterB = RotL64((aOrbiterB * 4850564181113470859U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 3229431819292153014U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 2994716629242460094U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 1029427328395257917U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 37U);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 44U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterI, 44U)) + aNonceWordA) + aPhaseHWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 46U) + aOrbiterK) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 29U)) + aOrbiterB) + aNonceWordD);
            aWandererC = aWandererC + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 37U)) + aOrbiterI) + aPhaseHWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 5U)) + aOrbiterE) + aNonceWordO);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 29U)) + aNonceWordF);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 11U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 48U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 14453U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneA[((aIndex + 13574U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 15530U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14122U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 14693U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 6U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (aWandererC + RotL64(aScatter, 11U)) + 12027839670755583592U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 5U)) + 15380130703509859843U) + aNonceWordC;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 4590907433867798074U;
            aOrbiterH = (((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 1754574023602519724U) + aNonceWordE;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 26U)) + 9832756659564903767U) + aPhaseHOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 5035088494491470403U) + aNonceWordB;
            aOrbiterF = ((aWandererK + RotL64(aCross, 19U)) + 14199170923323644638U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8325619421264440438U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterD) ^ 969534320779067977U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 17767548306355264705U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 270575869402913847U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 13344806516599578910U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 10193544126281901579U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15143147951139409101U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 14425582489214169238U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16893787086337916355U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 13951127523239064584U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14177925225918293579U;
            aOrbiterE = RotL64((aOrbiterE * 13079514031864998485U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8258920744278218901U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7408161179397242453U;
            aOrbiterH = RotL64((aOrbiterH * 975737128100519169U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8581481606764773468U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10078416198417433133U;
            aOrbiterF = RotL64((aOrbiterF * 1102721083915858247U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 18299772198826189580U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 18304668908084397946U;
            aOrbiterI = RotL64((aOrbiterI * 10589455451200578687U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 4U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 5U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aNonceWordG) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterG, 11U));
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterH, 35U));
            aWandererD = aWandererD + (((RotL64(aIngress, 20U) + RotL64(aOrbiterJ, 41U)) + aOrbiterH) + aNonceWordH);
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterE, 47U)) + aPhaseHWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterF, 29U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + RotL64(aWandererK, 58U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21738U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 17582U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 19489U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16637U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 17872U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCross, 34U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 51U)) + 17912271996338180948U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 35U)) + 13259276608841847058U) + aNonceWordM;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 4U)) + RotL64(aCarry, 11U)) + 16225936008657276089U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 41U)) + 2243058962151834071U;
            aOrbiterD = ((((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 10637439274127347861U) + aPhaseHOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 15312219216405992627U) + aNonceWordL;
            aOrbiterI = (aWandererI + RotL64(aScatter, 23U)) + 2393933972129878613U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4327069337247976513U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 8307656353434167837U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 11386588389133096705U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17299145556933889336U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14458100581172798164U;
            aOrbiterG = RotL64((aOrbiterG * 16543734663677070509U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 6410095654927998067U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6168964796264687686U;
            aOrbiterI = RotL64((aOrbiterI * 16218071040190475953U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 3667999465041020730U) + aNonceWordH;
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 16021552859323602007U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 6427266472526362663U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12941668202330045095U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 4222032891850449934U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 17292856787431308097U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1346342592002730785U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16860611785008118820U;
            aOrbiterA = RotL64((aOrbiterA * 384963420804756607U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3193572711804730241U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 5866881282680588589U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9226331800853634597U), 21U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 5U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 21U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterH, 12U));
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + RotL64(aOrbiterG, 51U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 27U)) + aOrbiterA) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aScatter, 14U) + RotL64(aOrbiterH, 37U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aNonceWordJ) + aPhaseHWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23148U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 26571U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23211U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22586U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21894U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 24U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 7960325128608297381U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 36U)) + 12773836012104052042U) + aNonceWordG;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 3U)) + 3173972621347773016U) + aPhaseHOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 51U)) + 3708401356314308171U) + aPhaseHOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 950774285720019449U;
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 3U)) + 4170092315705438265U) + aNonceWordI;
            aOrbiterH = (aWandererD + RotL64(aScatter, 19U)) + 17000449130864980747U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 8793910540062893860U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 520277969543516469U;
            aOrbiterC = RotL64((aOrbiterC * 4150613128885828229U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12762214857389827271U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 2932451184340207695U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 7513337346940091655U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11062179998786293839U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7919119215271524178U;
            aOrbiterH = RotL64((aOrbiterH * 9053677007180081359U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 1774988449597115155U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 3799792889466518953U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 17512791286490623455U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 1815062051307896589U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 15260373951371654483U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2208604434669491625U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12867546628945676853U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 7772820973895846946U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 7581704643538761985U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14213957831821966834U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16561105721170419454U;
            aOrbiterK = RotL64((aOrbiterK * 2540533987337175367U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 60U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + aNonceWordL);
            aWandererD = aWandererD + ((((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterF, 60U)) + aNonceWordM) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 5U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aScatter, 54U) + RotL64(aOrbiterH, 53U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 21U)) + aOrbiterE);
            aWandererH = aWandererH + (((((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 47U)) + aNonceWordC) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterC, 27U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 52U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28531U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 27523U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 29806U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29601U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneB[((aIndex + 30127U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 22U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 43U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 13333509828310369865U) + aNonceWordC;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 51U)) + 7645352517103840797U) + aNonceWordA;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 57U)) + 5310766306660062655U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 5165635069832352932U) + aNonceWordO;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 4U)) + 15684141764734281849U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aIngress, 43U)) + 3327963374225061738U;
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 51U)) + 8625811794878848871U) + aPhaseHOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7598657468430485291U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 2881171216276746485U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3331350584102843605U), 43U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 10237691227222918101U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6419254255884834497U;
            aOrbiterG = RotL64((aOrbiterG * 3816625473642865305U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 4238455444646479956U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14936613353493061492U;
            aOrbiterJ = RotL64((aOrbiterJ * 3544216916806292273U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15324699725208372627U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 9506640480601832011U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12819564111348390227U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3709149613660215641U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1724290199312754307U;
            aOrbiterI = RotL64((aOrbiterI * 12597580418257897965U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 13191172833570139194U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3686087945377837886U;
            aOrbiterD = RotL64((aOrbiterD * 10883609557429936283U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10418330386245397022U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5383531313632347245U;
            aOrbiterH = RotL64((aOrbiterH * 2987755379396160073U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((((RotL64(aCross, 54U) + aOrbiterI) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 47U)) + aNonceWordN) + aPhaseHWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterB, 21U));
            aWandererG = aWandererG + ((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterD, 13U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 6U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterK, 41U)) + aNonceWordE) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 6U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint8_t *aKeyRowReadA = &(pWorkSpace->mKeyBoxA[H_KEY - 1][0]);
    [[maybe_unused]] std::uint8_t *aKeyRowReadB = &(pWorkSpace->mKeyBoxB[H_KEY - 1][0]);
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
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
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 491U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 2687U)) & W_KEY1], 56U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 138U)) & W_KEY1], 28U) ^ RotL64(mSource[((aIndex + 1921U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 24U) + RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 37U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererB + RotL64(aIngress, 47U)) + 1952750591494698524U) + aPhaseAOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aCross, 12U)) + RotL64(aCarry, 57U)) + 4488270851303332830U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 43U)) + 2738763375328927635U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 51U)) + 6728843649480454340U;
            aOrbiterA = (aWandererE + RotL64(aCross, 29U)) + 10490717875258865358U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 23U)) + 1429288737812910205U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 3U)) + 2761375016998907636U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 1088988605204499835U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 18U)) + 6829840407300289709U) + aPhaseAOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9267240337867690471U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8120113021183975703U;
            aOrbiterC = RotL64((aOrbiterC * 14296504593187173107U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1340980511302566784U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11874452169979878835U;
            aOrbiterK = RotL64((aOrbiterK * 8638486178860092537U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 1872314794140971426U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6013952618696225751U;
            aOrbiterA = RotL64((aOrbiterA * 7994863587373565715U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3644011378086236002U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8501867691997891731U;
            aOrbiterI = RotL64((aOrbiterI * 7115282675461711509U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2493546555198066143U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5179240189571799179U;
            aOrbiterB = RotL64((aOrbiterB * 1267579130962756135U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 11273348247858394197U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 4577476419423118925U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8427261005061162673U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6201955123046621919U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 3930651302557530185U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1563512534463027965U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7571426325227856019U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11098508505512361002U;
            aOrbiterE = RotL64((aOrbiterE * 9229352429618815089U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6154830144380484305U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 4282054616147137364U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14984813139796280171U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 30U));
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterF, 60U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterE, 3U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterF, 29U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterH, 52U)) + aPhaseAWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 28U) + RotL64(aOrbiterB, 13U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 35U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 21U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 40U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 4969U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 4659U)) & W_KEY1], 40U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 5296U)) & W_KEY1], 60U) ^ RotL64(mSource[((aIndex + 5055U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCarry, 60U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 15910560457440369082U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 53U)) + 17953072986407436888U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 34U)) + RotL64(aCarry, 29U)) + 15446940721193538669U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 23U)) + 3020785262774422009U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 7001288645424994404U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 19U)) + 13385250665458462689U) + aPhaseAOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aCross, 47U)) + 4841895644623005949U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 41U)) + 13053476783239482065U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 14U)) + 641996979335975244U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 16211238020928688299U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12715448751323279480U;
            aOrbiterI = RotL64((aOrbiterI * 2116880429675303291U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17784406727699995290U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16626339815786580778U;
            aOrbiterC = RotL64((aOrbiterC * 13940754474750138041U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9035070625716345139U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6085848172494001945U;
            aOrbiterB = RotL64((aOrbiterB * 10405728912339646693U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 1177103851507561053U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2281901691017816407U;
            aOrbiterH = RotL64((aOrbiterH * 3142197009403602497U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9040984343694325070U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 13334258224023902365U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4782523727707164869U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1079824790138592518U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14024082692012948652U;
            aOrbiterG = RotL64((aOrbiterG * 3219489374333737903U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2966776524421278970U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5510281854029308547U;
            aOrbiterD = RotL64((aOrbiterD * 9275402927591867297U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 7126632329316720048U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1476827035602733472U;
            aOrbiterF = RotL64((aOrbiterF * 2217671289726794033U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6470212302133184965U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4172257438373147415U;
            aOrbiterK = RotL64((aOrbiterK * 4449314239630366533U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 21U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterG, 23U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 44U) + RotL64(aOrbiterK, 41U)) + aOrbiterI) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 27U)) + aOrbiterH) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 13U) + RotL64(aOrbiterH, 12U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 35U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 47U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterD, 3U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterH, 54U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 19U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 54U));
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 6302U)) & S_BLOCK1], 50U) ^ RotL64(aKeyRowReadB[((aIndex + 7976U)) & W_KEY1], 35U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 5919U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6894U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7342U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 24U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 41U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererI + RotL64(aCross, 28U)) + 13278949403988203974U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 19U)) + 9213599924054673756U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 51U)) + 1255746482932381798U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 11575321997144516122U) + aPhaseAOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aCross, 13U)) + 15881587525529432437U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 9846195809864862707U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 3U)) + 12319815691858217670U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 16322617427294439587U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 60U)) + 16332130810525887437U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 4920951156015336794U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 16767126455124552329U;
            aOrbiterC = RotL64((aOrbiterC * 4440352337076842603U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12553595911087945223U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 1437522202135436142U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2001992794165550905U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12313100454852227143U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2761983020631055729U;
            aOrbiterG = RotL64((aOrbiterG * 3874839760378039509U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17635303588421554367U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 788212489507463763U;
            aOrbiterB = RotL64((aOrbiterB * 17896475584538528059U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5192552894670654434U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6784748488807738811U;
            aOrbiterJ = RotL64((aOrbiterJ * 8077237651953896479U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16113417046719114943U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1096874945215225916U;
            aOrbiterF = RotL64((aOrbiterF * 17308604412622879833U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7610274704570171595U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10466070212284342550U;
            aOrbiterH = RotL64((aOrbiterH * 6449728258497920613U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6777845928873855221U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 5251515022021984126U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9018277343404261611U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13849343158824111498U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 7977711210181714021U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4182053966171053577U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 11U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 30U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterC, 60U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 37U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterE, 51U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 3U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterC, 41U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterG, 14U)) + aPhaseAWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterJ, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 50U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 9329U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadB[((aIndex + 8698U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(mSource[((aIndex + 8555U)) & S_BLOCK1], 26U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 9798U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9269U)) & W_KEY1], 48U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 10732U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 10U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 6469584119078165548U) + aPhaseBOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 14329756366517987910U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 11U)) + 12890831797059772123U;
            aOrbiterI = (aWandererC + RotL64(aCross, 6U)) + 3164503807500018990U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 35U)) + 177531431387646836U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 3167421392893561015U;
            aOrbiterB = (aWandererA + RotL64(aCross, 41U)) + 2813174781844753460U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 57U)) + 10953270419153249857U) + aPhaseBOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aScatter, 28U)) + 16911518309710356951U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6616750447844893150U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10276741398025985982U;
            aOrbiterG = RotL64((aOrbiterG * 6824712685896987133U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6206043608461213208U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12021552904553405793U;
            aOrbiterJ = RotL64((aOrbiterJ * 10023362889960174909U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 15283586234744144846U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5923238786775948571U;
            aOrbiterF = RotL64((aOrbiterF * 8200882393521882651U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11044014510971660078U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 9351141024085076044U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13316079344614432317U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 17703395981862992420U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10154548848376027087U;
            aOrbiterA = RotL64((aOrbiterA * 12324478347590509035U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8836420852291617425U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10193385413543886344U;
            aOrbiterD = RotL64((aOrbiterD * 824935982418585449U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 8248580084535685190U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3910083671888152974U;
            aOrbiterI = RotL64((aOrbiterI * 17825311776715895927U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12350341628569930642U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2565977481575002842U;
            aOrbiterE = RotL64((aOrbiterE * 18233446879833776677U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9271041067874027417U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 14289254596554201861U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7985522692852251413U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 18U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterJ, 18U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterI, 57U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 23U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterB, 5U));
            aWandererD = aWandererD + (((RotL64(aCross, 38U) + RotL64(aOrbiterF, 11U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterD, 43U));
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterB, 48U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 53U)) + aOrbiterK) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 58U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 13489U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 11371U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11865U)) & W_KEY1], 34U) ^ RotL64(mSource[((aIndex + 12339U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 12444U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12844U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12903U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 23U) + RotL64(aCarry, 58U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererH + RotL64(aScatter, 5U)) + 4634399531433127141U) + aPhaseBOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aIngress, 13U)) + 16961792729406903200U;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 4105280732301137738U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aCross, 43U)) + 15692013501147331191U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 60U)) + RotL64(aCarry, 57U)) + 1252216715968780587U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 47U)) + 7958289043012473752U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 6611577301818896615U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 35U)) + 8506226754305949140U;
            aOrbiterB = (aWandererE + RotL64(aCross, 24U)) + 3648813120449403353U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5195245426245535735U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 542948051600803051U;
            aOrbiterI = RotL64((aOrbiterI * 4631106308856448475U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 11974253551208964789U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10596463592332655367U;
            aOrbiterC = RotL64((aOrbiterC * 10941161258815714641U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12015129484061440159U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8254944355710109060U;
            aOrbiterD = RotL64((aOrbiterD * 3233697992479357615U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2754858806943915419U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 5007802002906662779U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15613733948331639723U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6262190752136523216U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10528977986487821428U;
            aOrbiterB = RotL64((aOrbiterB * 1184258264034585525U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8511097226098211854U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12091864735686692582U;
            aOrbiterF = RotL64((aOrbiterF * 6128140528141411237U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4970966265236842566U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10728884018459718341U;
            aOrbiterE = RotL64((aOrbiterE * 18205183219769602827U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13760057185629905360U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6590269178744829056U;
            aOrbiterK = RotL64((aOrbiterK * 14482684769712170123U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 765826377665103262U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9364759196106579706U;
            aOrbiterH = RotL64((aOrbiterH * 10315111163659289329U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 51U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterF, 34U));
            aWandererI = aWandererI + (((RotL64(aScatter, 52U) + aOrbiterE) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterI, 5U)) + aPhaseBWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 37U) + RotL64(aOrbiterG, 47U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 51U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aPrevious, 28U) + RotL64(aOrbiterB, 27U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterF, 57U));
            aWandererG = aWandererG + ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterB, 12U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 19U)) + aOrbiterD) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 13814U)) & S_BLOCK1], 58U) ^ RotL64(aFireLaneC[((aIndex + 15644U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14375U)) & W_KEY1], 28U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15100U)) & W_KEY1], 19U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14868U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 15455U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15037U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 10U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 16183871922837164759U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 7002058258090219055U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 29U)) + 5650868611888303705U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 36U)) + RotL64(aCarry, 39U)) + 11899839660943876690U) + aPhaseBOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aCross, 41U)) + 15349649504488111111U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 23U)) + 14060149569086744970U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 19U)) + 12920917574225030112U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 57U)) + 2831994965175330135U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 48U)) + 18312543585028439192U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11657562205118394239U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 10850792819281246052U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10663100544207879337U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 17810371216216125323U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7963413941144223128U;
            aOrbiterF = RotL64((aOrbiterF * 534217972450595401U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5498715358793875584U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9256727548911651373U;
            aOrbiterG = RotL64((aOrbiterG * 10498848323914000989U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17246360111302191699U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 18309978718113983369U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18267472694666221077U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3100998994319502921U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8129301860291235970U;
            aOrbiterB = RotL64((aOrbiterB * 17847033539279176187U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1889641029473279114U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16538494307002917945U;
            aOrbiterK = RotL64((aOrbiterK * 8081488217920885783U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5432230549146849322U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2634437941396090817U;
            aOrbiterC = RotL64((aOrbiterC * 7612999214758935211U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16940172599174185058U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13151669140593952203U;
            aOrbiterI = RotL64((aOrbiterI * 16225319638131723487U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3995064294869931681U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 913081077665768816U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9299514648768060453U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 27U);
            aIngress = aIngress + (RotL64(aOrbiterC, 50U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 14U) + RotL64(aOrbiterG, 43U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 39U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 57U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 37U)) + aPhaseBWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterF, 48U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterK, 29U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 19U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 35U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterI, 6U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17378U)) & S_BLOCK1], 6U) ^ RotL64(aKeyRowReadA[((aIndex + 16447U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(mSource[((aIndex + 16730U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneA[((aIndex + 17263U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18612U)) & W_KEY1], 5U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 18779U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 18839U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 47U)) + 8101351470141807662U) + aPhaseCOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aScatter, 60U)) + RotL64(aCarry, 19U)) + 6965474099521076705U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 35U)) + 6803828268885684784U;
            aOrbiterC = (aWandererA + RotL64(aCross, 23U)) + 13454235922950972488U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 35U)) + 11678091885751244777U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 54U)) + 5307134544628507141U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 3U)) + 4873703518950429353U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 11U)) + 8542156221858586039U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 13U)) + 3993726182905296513U) + aPhaseCOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12113047622035464386U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 1944244448665721151U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7010050836758762003U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12914188029425467576U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2486762763475327024U;
            aOrbiterF = RotL64((aOrbiterF * 12319769994433811617U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 14580191602982245481U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12093414832400135066U;
            aOrbiterE = RotL64((aOrbiterE * 12720286833215690663U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13623906997320021065U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9977356009806428696U;
            aOrbiterB = RotL64((aOrbiterB * 2005536391712733499U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3694954095397810851U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 11453812627797091638U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13730420725113907161U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 542311345544726351U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3024285045990499484U;
            aOrbiterC = RotL64((aOrbiterC * 5153745952148205645U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15397664082460849530U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10716856680110815056U;
            aOrbiterD = RotL64((aOrbiterD * 13947203772929252823U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 833342121331428547U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1111339940097269219U;
            aOrbiterK = RotL64((aOrbiterK * 17991642769781175473U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9312963978841402871U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8225496710723213204U;
            aOrbiterH = RotL64((aOrbiterH * 894499195498817065U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterK, 50U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterH, 58U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterF, 5U));
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF) + aPhaseCWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 30U) + RotL64(aOrbiterF, 35U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 47U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterH, 29U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 47U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 26U) + aOrbiterE) + RotL64(aOrbiterK, 23U));
            aWandererF = aWandererF + ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 18U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 50U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 20781U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((aIndex + 21594U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 19481U)) & S_BLOCK1], 40U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 20006U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20822U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21713U)) & W_KEY1], 47U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21762U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((aIndex + 19484U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 24U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 47U)) + 3238389262925516513U) + aPhaseCOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 41U)) + 12381787182611386995U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 7883885539305181549U;
            aOrbiterG = (aWandererA + RotL64(aCross, 35U)) + 1185413044597727092U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 12U)) + RotL64(aCarry, 53U)) + 15219353497204773135U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 21U)) + 7533774715626734082U) + aPhaseCOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 5U)) + 2599930450937763464U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 53U)) + 16074720663961214284U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 58U)) + RotL64(aCarry, 43U)) + 15483613196360051221U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 9396557867081376268U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 9668459976852660245U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11748505665890567063U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9037269914643207212U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 16936742640861088240U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1040172193161012227U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16481274825758546398U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 481851372837611166U;
            aOrbiterF = RotL64((aOrbiterF * 2225030139210599207U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13608921517203544108U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16930740723286214636U;
            aOrbiterH = RotL64((aOrbiterH * 2605108503821980865U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 902242902582149908U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1510861213079342977U;
            aOrbiterE = RotL64((aOrbiterE * 3309753895727400707U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7116243600304980310U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6631412278359709602U;
            aOrbiterG = RotL64((aOrbiterG * 11452627691392637463U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9246698682265275165U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8594373032014031450U;
            aOrbiterJ = RotL64((aOrbiterJ * 2550138341089957033U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15912837963877821048U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11404583513022627609U;
            aOrbiterI = RotL64((aOrbiterI * 17715204726760125357U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17295214920690244319U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 18315664494984189344U;
            aOrbiterC = RotL64((aOrbiterC * 17398893532076312945U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 30U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterK, 51U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 10U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterC, 37U));
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 58U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterH, 41U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterH, 27U));
            aWandererB = aWandererB + ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 6U)) + aOrbiterJ);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 47U)) + aOrbiterB) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 23684U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 22920U)) & W_KEY1], 51U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24221U)) & W_KEY1], 60U) ^ RotL64(aWorkLaneC[((aIndex + 22070U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22037U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23090U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24410U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 23212U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 6U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererI + RotL64(aPrevious, 19U)) + 5576732410244514238U;
            aOrbiterK = (aWandererK + RotL64(aCross, 5U)) + 2833808925935929629U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 52U)) + 3670188682914544792U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 15759072378887814995U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 23U)) + 13934007231137439994U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 41U)) + 11022225696007690512U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 46U)) + RotL64(aCarry, 27U)) + 16989177104453635790U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 19U)) + 9256930045263527091U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 37U)) + 17788596104417068290U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17044369456673337625U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1310908395523250343U;
            aOrbiterE = RotL64((aOrbiterE * 16305084373037705921U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12067065689034065422U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15130844248737512262U;
            aOrbiterA = RotL64((aOrbiterA * 9409499577465934107U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14532689204495587494U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8198147292120244178U;
            aOrbiterJ = RotL64((aOrbiterJ * 1418356389507740991U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 5485494458627163347U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10830008207150307611U;
            aOrbiterD = RotL64((aOrbiterD * 6526039534042499457U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17770065502486618029U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6397859353395335459U;
            aOrbiterB = RotL64((aOrbiterB * 14286997752368893825U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5128700697381508319U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7103394110057060499U;
            aOrbiterK = RotL64((aOrbiterK * 5053680689949149633U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16024401282261796979U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12818445221897253410U;
            aOrbiterH = RotL64((aOrbiterH * 11450004517784155405U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 13386978409145916350U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16740821954556699503U;
            aOrbiterI = RotL64((aOrbiterI * 5376430209628515105U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 313978038530994953U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1355733685461795345U;
            aOrbiterC = RotL64((aOrbiterC * 15955927322082619735U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 11U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 54U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 26U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 57U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 51U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterD, 37U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterH, 3U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterB, 41U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterI, 46U)) + RotL64(aCarry, 41U)) + aPhaseCWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterC, 11U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aScatter, 34U) + RotL64(aOrbiterE, 21U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 40U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26416U)) & S_BLOCK1], 26U) ^ RotL64(aKeyRowReadA[((aIndex + 27108U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 26795U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 27012U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25120U)) & W_KEY1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26930U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26607U)) & S_BLOCK1], 22U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25854U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 26U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 29U)) + 3650233661228036955U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 5U)) + 11607036400067735729U;
            aOrbiterD = (aWandererH + RotL64(aCross, 51U)) + 3899614406903883035U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 39U)) + 8159156925629965143U;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 10U)) + RotL64(aCarry, 13U)) + 7148903913967261270U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aPrevious, 23U)) + 9161665622287517848U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 2981535013474059469U;
            aOrbiterB = (aWandererI + RotL64(aCross, 57U)) + 15812469008200319549U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 34U)) + 14687469489893270300U) + aPhaseDOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6025209349511417063U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12964750392311112676U;
            aOrbiterD = RotL64((aOrbiterD * 12955480283032701843U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6572355895765394340U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3542300121890027981U;
            aOrbiterG = RotL64((aOrbiterG * 11201491178181273935U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6477175684045398359U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1081388388827929314U;
            aOrbiterE = RotL64((aOrbiterE * 8752188637514143529U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 13754328481584620771U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3684673342659575917U;
            aOrbiterH = RotL64((aOrbiterH * 6139923312873039143U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6542045150319909445U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 5352102692424060388U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7385758355501860261U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9110100774657340354U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2813273684436269057U;
            aOrbiterJ = RotL64((aOrbiterJ * 10468759062594022273U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5860425751137403755U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1598622981888978548U;
            aOrbiterI = RotL64((aOrbiterI * 651816500461718345U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14710305692377606725U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 16280545617802383463U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12541767206978802063U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6849565243667718750U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 12152381961996750050U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11185935780063403807U), 39U);
            //
            aIngress = RotL64(aOrbiterI, 30U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterA, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 57U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 36U) + RotL64(aOrbiterE, 28U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 5U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterI, 43U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 47U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterG, 35U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 21U)) + aOrbiterB);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 24U) + aOrbiterJ) + RotL64(aOrbiterA, 10U)) + RotL64(aCarry, 29U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 22U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 60U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28581U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((aIndex + 28087U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29161U)) & W_KEY1], 40U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29139U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28731U)) & W_KEY1], 38U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28404U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28190U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29620U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 38U)) + (RotL64(aCross, 51U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererB + RotL64(aIngress, 53U)) + 11039986441331892533U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 34U)) + 6256024955965426119U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aScatter, 27U)) + 9857443189988995666U) + aPhaseDOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aCross, 47U)) + 11900944813380998208U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 8422577734978875541U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 23U)) + 3100835100713928724U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 11871553509810206993U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 4U)) + RotL64(aCarry, 19U)) + 17614749493763417027U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 43U)) + 3638372131856199916U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6582275259281025770U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17016882418498941958U;
            aOrbiterG = RotL64((aOrbiterG * 4269869255230867823U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1747214688658984715U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9356088987044015278U;
            aOrbiterH = RotL64((aOrbiterH * 16221733545319753695U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 4056238112133473456U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16013150119949532998U;
            aOrbiterD = RotL64((aOrbiterD * 12913648646318115315U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 16076621211111834889U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9940824359571581765U;
            aOrbiterJ = RotL64((aOrbiterJ * 11624767861336495331U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15624084004784515753U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7630989544834680335U;
            aOrbiterA = RotL64((aOrbiterA * 12261063237156822067U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 18003586430673313786U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1654118743290334161U;
            aOrbiterC = RotL64((aOrbiterC * 1153250137357176071U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3254189676528343910U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 15629083361573065165U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17024833368570949107U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10056859810555674806U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15976683222786846254U;
            aOrbiterB = RotL64((aOrbiterB * 2801754232182942635U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11872378594829637933U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7633773773528713489U;
            aOrbiterE = RotL64((aOrbiterE * 8218288492011593353U), 23U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 40U);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterA, 57U));
            aWandererE = aWandererE + (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 11U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 53U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 30U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 22U) + aOrbiterH) + RotL64(aOrbiterB, 35U));
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 5U)) + aOrbiterF) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 39U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 23U)) + aOrbiterF) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterD, 44U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 22U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31780U)) & S_BLOCK1], 58U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32366U)) & W_KEY1], 11U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30339U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30496U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31332U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 32172U)) & W_KEY1], 18U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 39U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 3U)) + 380024772508948442U;
            aOrbiterE = (aWandererI + RotL64(aCross, 39U)) + 7649029098162567210U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 43U)) + 5329304598870421851U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 51U)) + 12306118665045151326U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 35U)) + 960751560457324256U;
            aOrbiterF = (aWandererH + RotL64(aCross, 19U)) + 3244070254386191876U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 6U)) + 15733408571609521746U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 17623448932647018544U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 43U)) + 8787759896149035829U) + aPhaseDOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 14741681792348288162U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8801731213568307302U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12127126999570616489U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 9872248187499779222U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15407371518644528235U;
            aOrbiterC = RotL64((aOrbiterC * 1245102406469471673U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4242060317152943062U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 9942784962409917541U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 888649755587764533U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 7296348796484458631U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15061417216070157797U;
            aOrbiterE = RotL64((aOrbiterE * 10349554676953256231U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3233185810644297433U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9241229457641024287U;
            aOrbiterF = RotL64((aOrbiterF * 2728237515724597517U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8464051359381554575U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3307872165699029375U;
            aOrbiterJ = RotL64((aOrbiterJ * 4859663401033023433U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5482617843966711997U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4442149210462943872U;
            aOrbiterI = RotL64((aOrbiterI * 8979352218576515647U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 10591636597580147381U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14925122230279312217U;
            aOrbiterA = RotL64((aOrbiterA * 15038171961638724013U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9772367878232735350U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15800661165607190092U;
            aOrbiterB = RotL64((aOrbiterB * 10493976952980533589U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 26U);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 18U) + aOrbiterG) + RotL64(aOrbiterF, 57U)) + aPhaseDWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 6U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 51U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterJ, 23U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 35U)) + aOrbiterB) + aPhaseDWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 24U) + RotL64(aOrbiterB, 47U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterB, 12U));
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 39U)) + aOrbiterH) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 26U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 993U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 7956U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4056U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4312U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 103U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2118U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 4U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererK + RotL64(aCross, 58U)) + RotL64(aCarry, 47U)) + 13481227414590594621U) + aPhaseEOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 11U)) + 17425964381118918026U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 4792004356135956581U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 29U)) + 11926849936000639098U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 35U)) + 990697329347742142U;
            aOrbiterH = (aWandererB + RotL64(aCross, 29U)) + 9307721505373076588U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 43U)) + 17605732738841908719U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 13110764518634187439U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17970109897810645911U;
            aOrbiterD = RotL64((aOrbiterD * 10395095143998920213U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10273133817644703654U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11239046688920468137U;
            aOrbiterB = RotL64((aOrbiterB * 5197802934333553327U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8355821483275763145U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15522151127786049345U;
            aOrbiterH = RotL64((aOrbiterH * 4844278537850520413U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5381663179722418112U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 9551368011768104906U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14202470972121732997U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16264476585232221270U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7721417776432288282U;
            aOrbiterF = RotL64((aOrbiterF * 10267770327791051869U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 339418090653475277U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 3247926250495935511U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16824669543765729097U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3390560045236418590U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3894024951542543635U;
            aOrbiterG = RotL64((aOrbiterG * 10599637790900418767U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterB, 19U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterH, 4U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 18U) + RotL64(aOrbiterA, 35U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterG, 27U));
            aWandererC = aWandererC + ((RotL64(aCross, 5U) + RotL64(aOrbiterD, 53U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 13U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8927U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 13258U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 14767U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((aIndex + 16352U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15816U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11451U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 11235U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 40U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 23U)) + 3621877681473089725U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 4451752751536414717U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aScatter, 26U)) + 11371625415377772117U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 11U)) + 6046792758881150619U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 57U)) + 8213166120394461682U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 3U)) + 4343156661140422645U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 11105271483234947905U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 348904609985341372U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12924652822526858767U;
            aOrbiterK = RotL64((aOrbiterK * 2801892489296408735U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7461211697358520287U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 16551553555297890558U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16432952324635746293U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11908056404140782995U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9147367258259948715U;
            aOrbiterC = RotL64((aOrbiterC * 10777628928376261667U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8876461054692728610U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10546855952702525404U;
            aOrbiterH = RotL64((aOrbiterH * 10071104785895309677U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4748636139110443794U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 783046909529525098U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8969157702460927215U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16683965945838696665U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 12385412690177109575U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10795062772707143187U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8210546822184469023U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13146493623236979963U;
            aOrbiterF = RotL64((aOrbiterF * 13199947810161148155U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterC, 21U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterC, 47U)) + aOrbiterH) + aPhaseEWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterC, 13U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterD, 39U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterF, 28U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 3U)) + aOrbiterF) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 34U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 19629U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 17608U)) & S_BLOCK1], 28U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 21005U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 21474U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23506U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23388U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 19081U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 48U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 3U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererF + RotL64(aScatter, 11U)) + 8101351470141807662U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aIngress, 51U)) + 6965474099521076705U;
            aOrbiterC = (aWandererI + RotL64(aCross, 34U)) + 6803828268885684784U;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 13454235922950972488U) + aPhaseEOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 11678091885751244777U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 5307134544628507141U;
            aOrbiterA = (aWandererH + RotL64(aCross, 57U)) + 4873703518950429353U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8542156221858586039U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3993726182905296513U;
            aOrbiterC = RotL64((aOrbiterC * 11331376012938127609U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12113047622035464386U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 1944244448665721151U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7010050836758762003U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 12914188029425467576U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2486762763475327024U;
            aOrbiterD = RotL64((aOrbiterD * 12319769994433811617U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14580191602982245481U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 12093414832400135066U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12720286833215690663U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13623906997320021065U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9977356009806428696U;
            aOrbiterE = RotL64((aOrbiterE * 2005536391712733499U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3694954095397810851U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11453812627797091638U;
            aOrbiterF = RotL64((aOrbiterF * 13730420725113907161U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 542311345544726351U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3024285045990499484U;
            aOrbiterG = RotL64((aOrbiterG * 5153745952148205645U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 4U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterG, 27U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterI, 47U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterE, 13U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterG, 60U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 41U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterD, 21U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 53U)) + aOrbiterD) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 22U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29978U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 25995U)) & S_BLOCK1], 60U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 25571U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((aIndex + 28379U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27616U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25321U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 27149U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 53U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 57U)) + 1866656689936219099U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 2312314528139448289U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 21U)) + 3554037526469185237U) + aPhaseEOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 405707755060974111U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 41U)) + 1862976326004007697U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 10U)) + RotL64(aCarry, 39U)) + 12992483065443288263U;
            aOrbiterK = (aWandererI + RotL64(aCross, 27U)) + 3793854946371595197U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 4244007978867369382U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10280867500312580308U;
            aOrbiterC = RotL64((aOrbiterC * 13729899124177931289U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 472563452959164242U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 12041770406895816553U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17811798500132002631U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 6118634015704900486U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13637107920449233307U;
            aOrbiterJ = RotL64((aOrbiterJ * 17712028184714868053U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16673735670669318830U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8602681273646630496U;
            aOrbiterD = RotL64((aOrbiterD * 6995213887710749241U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7683264695930369476U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9146674871199188218U;
            aOrbiterI = RotL64((aOrbiterI * 7403427067419261981U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3012935612827493084U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1259789268731661945U;
            aOrbiterK = RotL64((aOrbiterK * 2372843620327050137U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5623690455471160780U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 18355567776031865462U;
            aOrbiterE = RotL64((aOrbiterE * 9553862670107886679U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 60U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterH, 47U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterC, 39U)) + aPhaseEWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 58U) + aOrbiterD) + RotL64(aOrbiterJ, 27U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 20U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterJ, 3U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 57U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4324U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 5183U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5901U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5588U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6286U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 6135U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 56U)) + (RotL64(aCross, 43U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererH + RotL64(aScatter, 23U)) + 2571116506511057880U) + aPhaseFOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aCross, 19U)) + 13112435411509707292U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 47U)) + 10403251762787357256U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 30U)) + 8461951095541400405U) + aPhaseFOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aCross, 3U)) + 9890793478557463815U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 37U)) + 3030229465991783707U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 7273848154043719247U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 21U)) + 10681774862516028276U;
            aOrbiterA = (aWandererK + RotL64(aCross, 53U)) + 7105082755586853104U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 6588579345319551129U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 44U)) + RotL64(aCarry, 47U)) + 14616333550242386092U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15439666290229654921U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3360304356760164799U;
            aOrbiterC = RotL64((aOrbiterC * 5164191920584106237U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14438730801970761889U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14515616787452085729U;
            aOrbiterG = RotL64((aOrbiterG * 2041601927968559821U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4167853822635132419U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 8950982233003320239U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 887144270884244907U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12391327853728029953U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7100871010552394421U;
            aOrbiterK = RotL64((aOrbiterK * 16552349374101955967U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 15381697462381887944U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6801677551341079401U;
            aOrbiterA = RotL64((aOrbiterA * 13325954438427340703U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 947011315719204867U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6356920162398333481U;
            aOrbiterH = RotL64((aOrbiterH * 5566721941682667419U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8910262020598577378U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8778455415977526457U;
            aOrbiterI = RotL64((aOrbiterI * 4092470497616637283U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5585696961453127223U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9670655481681494412U;
            aOrbiterB = RotL64((aOrbiterB * 7863197168965036383U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10713004007087085729U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4036355047492922339U;
            aOrbiterD = RotL64((aOrbiterD * 6923922258047667173U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 14580156873863533497U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7049502932205025182U;
            aOrbiterE = RotL64((aOrbiterE * 8665428649262370727U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12707521269341941677U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 2571116506511057880U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2388236789245943699U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 48U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 6U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterH, 60U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 13U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterD, 53U));
            aWandererE = aWandererE + ((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 11U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterD, 41U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterH, 39U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 18U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 5U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 48U) + aOrbiterH) + RotL64(aOrbiterE, 29U)) + aPhaseFWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterH, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 24U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12932U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 10313U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 16292U)) & S_BLOCK1], 46U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8241U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12878U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 13991U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 13107U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 19U)) ^ (RotL64(aIngress, 37U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererJ + RotL64(aCross, 3U)) + 17081642665820489793U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 20U)) + 14468854040067229623U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 43U)) + 2249450222593057429U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 41U)) + 14964389079511378664U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 17003491054252360650U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 51U)) + 12710882240582032588U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 60U)) + 9887078182156755359U;
            aOrbiterA = (aWandererG + RotL64(aCross, 47U)) + 7665284531810584704U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 13U)) + 7304284015511876717U;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 5517927023543751734U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aCross, 37U)) + 17704756310857362759U) + aPhaseFOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11347400363019508578U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11696395232760991243U;
            aOrbiterC = RotL64((aOrbiterC * 9725231749679442003U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10875780291242873583U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7808740614343437672U;
            aOrbiterH = RotL64((aOrbiterH * 8889516201913716283U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3145390996141902032U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 16080636485642732615U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7445756373012217305U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3929263288176983844U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 18210228766683996806U;
            aOrbiterI = RotL64((aOrbiterI * 13178080076505449091U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13948962323541421431U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3037683309790156893U;
            aOrbiterD = RotL64((aOrbiterD * 13406672352222636739U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17827265198532699474U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7270895262023504864U;
            aOrbiterG = RotL64((aOrbiterG * 13467417362477308167U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 6431243064980879185U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6680205390976259885U;
            aOrbiterF = RotL64((aOrbiterF * 10421386694108590789U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 15910655919164357152U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8046213498216027383U;
            aOrbiterK = RotL64((aOrbiterK * 18061867495824063553U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 2521111689480478597U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13892876610454681741U;
            aOrbiterE = RotL64((aOrbiterE * 17776392934374483875U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16009217514890880809U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1221573458193626679U;
            aOrbiterA = RotL64((aOrbiterA * 73477765605619369U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9275704218554025797U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17081642665820489793U;
            aOrbiterJ = RotL64((aOrbiterJ * 5613316790159527375U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 23U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 27U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 54U) + RotL64(aOrbiterI, 29U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterE, 13U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterI, 51U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 43U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aPrevious, 10U) + RotL64(aOrbiterC, 20U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterK, 11U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 3U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterB, 22U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 52U));
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18851U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 19730U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 16884U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16768U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24359U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19635U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19567U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 41U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererI + RotL64(aCross, 56U)) + 12535417189990029950U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 27U)) + 6204401443676390273U) + aPhaseFOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aIngress, 35U)) + 869613505613154672U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 15053590879563855802U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 13338989605204591428U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 19U)) + 18306470022403825392U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 60U)) + 1150696349434090218U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 53U)) + 13549541786420596437U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 11U)) + 14302878430259588461U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 39U)) + 4660437084477165225U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 1653628537860912069U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5594199757006711631U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11008472193138708891U;
            aOrbiterG = RotL64((aOrbiterG * 13645764762027798301U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 3668516817279364310U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 128159531749679984U;
            aOrbiterD = RotL64((aOrbiterD * 4523246859249826987U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6378674346113979108U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11438762460659123362U;
            aOrbiterK = RotL64((aOrbiterK * 2733309638158283953U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10624263004446482910U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 12546839706919241411U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11468326687628079347U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8466639576503293921U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5828694979857951504U;
            aOrbiterI = RotL64((aOrbiterI * 7835487310289634515U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16496305151014092976U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 589464613876410567U;
            aOrbiterH = RotL64((aOrbiterH * 13190816610718051897U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4168532743415647825U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15944887793736489375U;
            aOrbiterE = RotL64((aOrbiterE * 17273403561158196717U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 11642456814106259483U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1609897693632334867U;
            aOrbiterJ = RotL64((aOrbiterJ * 12912773555616819941U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14950238412766325479U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11862438528287402255U;
            aOrbiterC = RotL64((aOrbiterC * 7635864312080265695U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 5900629306795222263U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3221591991392500536U;
            aOrbiterA = RotL64((aOrbiterA * 7188525011266868855U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16938699391746264010U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12535417189990029950U;
            aOrbiterF = RotL64((aOrbiterF * 18212319484142613215U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 46U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 29U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterB, 60U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 5U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aIngress, 10U) + RotL64(aOrbiterB, 57U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 19U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 11U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 23U)) + aOrbiterC) + aPhaseFWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterJ, 27U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 22U) + RotL64(aOrbiterD, 40U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterK, 21U)) + aPhaseFWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 37U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 50U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32413U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 31298U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 31356U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 32221U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29310U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29619U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 28990U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererD + RotL64(aCross, 52U)) + 7075016829833562104U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 41U)) + 8783765886115517036U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 5U)) + 2996723892384565829U) + aPhaseFOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aIngress, 35U)) + 9494134707342189476U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 14U)) + RotL64(aCarry, 37U)) + 5052642981395679904U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 11U)) + 8766787055127962238U;
            aOrbiterA = (aWandererE + RotL64(aCross, 29U)) + 4467211954388738079U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 19U)) + 8030255604633658608U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 23U)) + 16962408063455702251U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 21U)) + 3768222186567699076U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 14930990410207899871U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14179761938395502502U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1879084742719898108U;
            aOrbiterB = RotL64((aOrbiterB * 16783034788172670121U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5535012408925981515U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12792553516710295939U;
            aOrbiterJ = RotL64((aOrbiterJ * 8577530993755159329U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8979253163346099252U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5559189896063990740U;
            aOrbiterK = RotL64((aOrbiterK * 8832485423727331621U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13937564337299044079U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 2393376759689394948U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2352815657830413941U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12647519563697356479U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10946871249960389549U;
            aOrbiterE = RotL64((aOrbiterE * 6272580371881237173U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13376798695582123147U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 10958115913599631271U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18233981473003345217U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4283914227806672773U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 910842005516235816U;
            aOrbiterD = RotL64((aOrbiterD * 6722229871617873429U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1509644316619370324U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 165987596716078174U;
            aOrbiterA = RotL64((aOrbiterA * 13600064054240185123U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 12491315345199091186U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 5982431705686495125U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2547243804779022665U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 231183123382412440U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2872632389683254396U;
            aOrbiterC = RotL64((aOrbiterC * 1972278820468847241U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15259314110008210315U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7075016829833562104U;
            aOrbiterG = RotL64((aOrbiterG * 8350093877370898869U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 40U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 37U) + RotL64(aOrbiterB, 3U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 5U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aIngress, 24U) + aOrbiterC) + RotL64(aOrbiterJ, 29U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 53U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aCross, 19U) + RotL64(aOrbiterC, 26U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 35U)) + aOrbiterG) + aPhaseFWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 39U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 19U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 47U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aPrevious, 10U) + RotL64(aOrbiterK, 50U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererF, 24U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 48U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
        // ingress from: aWorkLaneA, aWorkLaneB, aWorkLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aWorkLaneB, aWorkLaneC, aWorkLaneD
        // cross directions: aWorkLaneB backward forced, aWorkLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2164U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 8052U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 5124U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 619U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 665U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 8191U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 20U) + RotL64(aCarry, 47U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererH + RotL64(aIngress, 13U)) + 1042610313571524121U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 34U)) + RotL64(aCarry, 47U)) + 3505725321008825582U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 12584654563843782991U;
            aOrbiterE = (((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 27U)) + 6645399144515770935U) + aPhaseGOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aScatter, 51U)) + 3608978423753715584U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8089198857670370983U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15207251813516399879U;
            aOrbiterG = RotL64((aOrbiterG * 7596841660069752069U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9579268660105824516U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 16055044469473802812U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2269649280637188723U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 583811872609805949U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 7027491967970873942U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12686754713465826139U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 18256061823189677508U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 12708429127816136937U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12593886633108075321U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 12169216645156306078U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12694325407567795065U;
            aOrbiterC = RotL64((aOrbiterC * 3711789483877261899U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 43U);
            aIngress = aIngress + (RotL64(aOrbiterG, 54U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 5U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterE, 37U));
            aWandererH = aWandererH + ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 60U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 48U) + RotL64(aOrbiterG, 13U)) + aOrbiterE) + aPhaseGWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 14586U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((aIndex + 10348U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10282U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8918U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9292U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11849U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 18U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 11480359716598965890U) + aPhaseGOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aIngress, 47U)) + 15431182525482873419U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 13U)) + 11360504974812776707U;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 20U)) + RotL64(aCarry, 53U)) + 9292576416573382769U) + aPhaseGOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aCross, 57U)) + 1549257414531028975U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5347769463033129317U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17019199177478377234U;
            aOrbiterB = RotL64((aOrbiterB * 4336112198640602307U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16558106007323125094U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 3976182233825939422U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4392162052317572289U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2889047161195954395U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2241831345026962605U;
            aOrbiterG = RotL64((aOrbiterG * 5757458560979927857U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 12850802412140579294U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 13541744735436450160U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 906089290000537439U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2085863085516538212U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2969034221711544086U;
            aOrbiterI = RotL64((aOrbiterI * 7768528124408400403U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 26U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 43U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 34U) + RotL64(aOrbiterJ, 53U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 5U)) + aOrbiterI) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterJ, 26U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18587U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 20246U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 20645U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22803U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23633U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 18153U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 27U)) + (RotL64(aIngress, 40U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 29U)) + 10805654776556844351U) + aPhaseGOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 51U)) + 582794182442795335U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 51U)) + 2858343650974681068U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 40U)) + RotL64(aCarry, 11U)) + 8189584049022064284U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 21U)) + 1565100751996962893U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8062028016947611891U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8280504280578451745U;
            aOrbiterD = RotL64((aOrbiterD * 5212851648135050483U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 11326869194491655350U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1671695656567777163U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7511554500524257921U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2349843105293943452U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 13015545152052004254U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1316662811685429983U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16703354404749291869U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 8713231044374305801U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9242480982197688625U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11118401674497783533U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14857556493734710364U;
            aOrbiterC = RotL64((aOrbiterC * 3452566050389715195U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 40U) + RotL64(aOrbiterJ, 53U)) + aOrbiterD) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 27U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterE, 5U));
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterE, 42U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30603U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 29285U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31804U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29875U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31378U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 26629U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 11U)) + (RotL64(aCross, 37U) ^ RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (((aWandererF + RotL64(aIngress, 56U)) + RotL64(aCarry, 53U)) + 17711946802293254150U) + aPhaseGOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 16652362590489569378U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 11U)) + 6972810344198183097U;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 35U)) + 13117100889782940546U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aScatter, 35U)) + 13199305696782626591U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 992156184392760945U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13791265442074543880U;
            aOrbiterH = RotL64((aOrbiterH * 1263919538622722673U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17057087245252294859U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13444195995883541046U;
            aOrbiterG = RotL64((aOrbiterG * 13067044288608808777U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6723678233676059420U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7913379431208430475U;
            aOrbiterE = RotL64((aOrbiterE * 2295062944289127123U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4481887195529300665U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11892724101424384078U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3468639499716604111U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 7700902083270424194U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 1888001433557140271U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8975562955027025349U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 39U)) + aOrbiterE) + aPhaseGWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 5U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 57U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 48U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererG, 34U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

    std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0;
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
        // ingress from: aExpandLaneA, aExpandLaneB, aExpandLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aExpandLaneB, aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneB backward forced, aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3029U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 273U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 488U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7814U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7927U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2372U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 3621877681473089725U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 29U)) + 4451752751536414717U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 21U)) + 11371625415377772117U;
            aOrbiterG = (((aWandererG + RotL64(aCross, 40U)) + RotL64(aCarry, 37U)) + 6046792758881150619U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aIngress, 57U)) + 8213166120394461682U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4343156661140422645U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 11105271483234947905U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 853531080115819287U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 348904609985341372U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12924652822526858767U;
            aOrbiterF = RotL64((aOrbiterF * 2801892489296408735U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7461211697358520287U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 16551553555297890558U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16432952324635746293U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11908056404140782995U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9147367258259948715U;
            aOrbiterJ = RotL64((aOrbiterJ * 10777628928376261667U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8876461054692728610U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 10546855952702525404U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10071104785895309677U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 52U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aCross, 28U) + aOrbiterH) + RotL64(aOrbiterF, 48U)) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterE, 57U));
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 39U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 16366U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 11925U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11737U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9257U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13283U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 14754U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 11U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 42U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 13U)) + 2672739400294801233U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 3U)) + 8475624545015101850U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 24U)) + RotL64(aCarry, 27U)) + 1252755112289831257U) + aPhaseHOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 7938039507649183387U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 51U)) + 8167413146948861022U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 17712313989694374353U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 7637042279892596975U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13056020836704050293U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15770412950033467341U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3951812021898608685U;
            aOrbiterG = RotL64((aOrbiterG * 6623127125223204737U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8656983621098246507U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17943342344730687317U;
            aOrbiterF = RotL64((aOrbiterF * 16495519451034883813U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3087677463651608668U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 16493240011924342788U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16898479041530771871U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7750923317452683057U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 2185924841611106546U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 708072658250726381U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 13U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 35U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 48U) + RotL64(aOrbiterK, 23U)) + aOrbiterI) + aPhaseHWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterI, 60U)) + aPhaseHWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16506U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 24010U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22460U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19134U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19406U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 20382U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 52U) + RotL64(aIngress, 39U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererH + RotL64(aCross, 56U)) + 10805654776556844351U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 39U)) + 582794182442795335U;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 21U)) + 2858343650974681068U) + aPhaseHOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aIngress, 13U)) + 8189584049022064284U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 1565100751996962893U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8062028016947611891U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8280504280578451745U;
            aOrbiterE = RotL64((aOrbiterE * 5212851648135050483U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11326869194491655350U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 1671695656567777163U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7511554500524257921U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 2349843105293943452U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13015545152052004254U;
            aOrbiterF = RotL64((aOrbiterF * 1316662811685429983U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16703354404749291869U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8713231044374305801U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9242480982197688625U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11118401674497783533U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14857556493734710364U;
            aOrbiterC = RotL64((aOrbiterC * 3452566050389715195U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 41U);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterD, 43U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 54U) + RotL64(aOrbiterF, 35U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 23U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterF, 52U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28784U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneB[((aIndex + 24609U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 28618U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28729U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28434U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28414U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererA + RotL64(aCross, 6U)) + 14249093584376402677U;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 19U)) + 8756965951816492264U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aScatter, 19U)) + 11221139480258176330U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 37U)) + 17218894445564194851U;
            aOrbiterH = (((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 8064642692524949490U) + aPhaseHOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5822093203710704646U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3217799620158102238U;
            aOrbiterG = RotL64((aOrbiterG * 2806328682494910635U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2613757677892120843U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13647481499551657237U;
            aOrbiterJ = RotL64((aOrbiterJ * 5517563514031899891U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 3545714196663685016U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 9735422670576621521U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7276207208162697249U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 3911046580637583767U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 9315984027042049203U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12568550776487242469U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8926367674641729058U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11035347490524961446U;
            aOrbiterE = RotL64((aOrbiterE * 10948288997163592463U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterE, 60U));
            aWandererH = aWandererH + (((RotL64(aCross, 27U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 42U) + RotL64(aOrbiterG, 39U)) + aOrbiterC) + aPhaseHWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 11U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterH, 51U)) + aPhaseHWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 44U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 53U);
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
