#include "TwistExpander_VolleyBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_VolleyBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8A7688E09D5CB82DULL + 0x8A794C6509D04A4FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9045E4D44B67F213ULL + 0x9DEE5748A67B6BB7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCE3C8CF1300C6C3DULL + 0xAA2E4EC7BAEA1342ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9F3CDAE1A8439BFFULL + 0x9A5E59D627285D44ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x849DC5A24051E2EDULL + 0x893B3E2B17114B82ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8781230A52F53F2FULL + 0xD431FA6E2448EAC1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF47D8A5119C4BC49ULL + 0xC11D34EF1E7F58A3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC25ED0E45FE426B5ULL + 0xE0361FF7C0E649B7ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 4U) ^ RotL64(aNonceWordB, 43U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5057U)) & S_BLOCK1], 29U) ^ RotL64(mSnow[((aIndex + 879U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 23U) ^ RotL64(aNonceWordH, 11U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 2195U)) & S_BLOCK1], 36U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 2397U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 60U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererF + RotL64(aScatter, 30U)) + RotL64(aCarry, 37U)) + 11177787645248006236U;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 13U)) + 3808340254579817169U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordE, 59U);
            aOrbiterA = (aWandererC + RotL64(aCross, 41U)) + 828030667598518279U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 53U)) + 16177835921238398371U;
            aOrbiterD = (aWandererI + RotL64(aCross, 19U)) + 5518747735458708741U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 35U)) + 17346319082399995165U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 6397156921893030937U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 56U)) + 15559381654710713582U) + RotL64(aNonceWordA, 55U);
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 23U)) + 940404446491415088U) + aOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aIngress, 37U)) + 8047166032048732645U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 4688468645859470491U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3710878044770337260U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 116343189456629220U;
            aOrbiterA = RotL64((aOrbiterA * 5637725064169289339U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 883908030159391659U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 18058691521694880482U;
            aOrbiterC = RotL64((aOrbiterC * 3132200449123497619U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17521015077103586117U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3668332225435714918U;
            aOrbiterK = RotL64((aOrbiterK * 12658899101297839881U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12229480388278883300U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16206524049491531816U;
            aOrbiterE = RotL64((aOrbiterE * 11122340196620859805U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 5743265849441077466U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2812293020719282236U;
            aOrbiterF = RotL64((aOrbiterF * 8903956475200417109U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 13718364781538837074U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 861529717259766236U;
            aOrbiterJ = RotL64((aOrbiterJ * 17019744777211266685U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4862687502126693872U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7722024283321020761U;
            aOrbiterG = RotL64((aOrbiterG * 18086944039541060829U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8205803118233399853U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15130160926615050422U;
            aOrbiterI = RotL64((aOrbiterI * 1454552751453996765U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 667469191899263617U) + RotL64(aNonceWordC, 20U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 18048970185163843471U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1800698970568737425U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 508102841337488721U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3803840516662727630U;
            aOrbiterH = RotL64((aOrbiterH * 8477778555284121637U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17055028117762299436U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterC) ^ 11177787645248006236U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) ^ RotL64(aNonceWordF, 61U);
            aOrbiterB = RotL64((aOrbiterB * 12457019014051206805U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 36U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterG, 26U)) + aOrbiterC) + RotL64(aNonceWordH, 3U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 30U) + aOrbiterB) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterK, 51U)) + aWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 47U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 3U));
            aWandererC = aWandererC + ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 29U)) + aOrbiterC);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterG, 37U)) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 39U)) + aOrbiterG) + RotL64(aCarry, 11U)) + RotL64(aNonceWordG, 57U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 13U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 57U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterH, 42U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 52U) ^ RotL64(aNonceWordF, 19U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 7434U)) & S_BLOCK1], 27U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 9788U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 53U) ^ RotL64(aNonceWordH, 40U)) ^ RotL64(aNonceWordG, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8641U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8586U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 10U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 19U)) + 3650233661228036955U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 51U)) + 11607036400067735729U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 27U)) + 3899614406903883035U) + RotL64(aNonceWordD, 6U);
            aOrbiterA = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 11U)) + 8159156925629965143U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 39U)) + 7148903913967261270U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 57U)) + 9161665622287517848U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 14U)) + 2981535013474059469U;
            aOrbiterD = (aWandererI + RotL64(aCross, 3U)) + 15812469008200319549U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 47U)) + 14687469489893270300U) + aOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 43U)) + 6025209349511417063U) + RotL64(aNonceWordH, 15U);
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 20U)) + 12964750392311112676U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6572355895765394340U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 3542300121890027981U) ^ aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11201491178181273935U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6477175684045398359U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1081388388827929314U;
            aOrbiterC = RotL64((aOrbiterC * 8752188637514143529U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 13754328481584620771U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 3684673342659575917U) ^ RotL64(aNonceWordC, 41U);
            aOrbiterK = RotL64((aOrbiterK * 6139923312873039143U), 11U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 6542045150319909445U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordA, 7U);
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5352102692424060388U;
            aOrbiterI = RotL64((aOrbiterI * 7385758355501860261U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9110100774657340354U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 2813273684436269057U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10468759062594022273U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5860425751137403755U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1598622981888978548U;
            aOrbiterJ = RotL64((aOrbiterJ * 651816500461718345U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14710305692377606725U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16280545617802383463U;
            aOrbiterA = RotL64((aOrbiterA * 12541767206978802063U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6849565243667718750U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12152381961996750050U;
            aOrbiterG = RotL64((aOrbiterG * 11185935780063403807U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1318947876257794796U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5447559252769140391U;
            aOrbiterD = RotL64((aOrbiterD * 13683733413554766327U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2766869582494246454U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15757729967222729304U;
            aOrbiterF = RotL64((aOrbiterF * 1858683399257513171U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13063432816787882618U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3650233661228036955U;
            aOrbiterE = RotL64((aOrbiterE * 16230564672533821641U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 10U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 18U)) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterB, 13U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 43U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 39U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF) + RotL64(aNonceWordB, 11U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 50U) + aOrbiterF) + RotL64(aOrbiterG, 23U)) + RotL64(aNonceWordE, 57U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterB, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 3U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 35U)) + aOrbiterA) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 54U) + RotL64(aOrbiterD, 56U)) + aOrbiterH) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 46U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 48U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 21U) ^ RotL64(aNonceWordH, 6U)) ^ RotL64(aNonceWordF, 35U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 15787U)) & S_BLOCK1], 43U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 11654U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 30U) ^ RotL64(aNonceWordA, 5U)) ^ RotL64(aNonceWordG, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12181U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11610U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 43U)) + (RotL64(aCarry, 30U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererK + RotL64(aScatter, 53U)) + 13499155707765393469U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 23U)) + 3740324981823726185U) + RotL64(aNonceWordC, 45U);
            aOrbiterJ = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 5470765363949735652U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 3446436171274452326U;
            aOrbiterB = (aWandererE + RotL64(aCross, 13U)) + 1778929412631211933U;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 34U)) + 14666308799855220954U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordB, 53U);
            aOrbiterE = (aWandererD + RotL64(aPrevious, 29U)) + 4548410236791175055U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 37U)) + 5829739767694190372U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 47U)) + 14319231414903675748U;
            aOrbiterA = (aWandererB + RotL64(aCross, 44U)) + 1513851750246111405U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 1685620217748986019U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 16284162182006054402U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6271539598462003309U;
            aOrbiterJ = RotL64((aOrbiterJ * 13923286694131331137U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12669312437565969473U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 11894755313393001665U) ^ RotL64(aNonceWordA, 24U);
            aOrbiterG = RotL64((aOrbiterG * 12556759675372354075U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6315983824634946566U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17106616474222892782U;
            aOrbiterC = RotL64((aOrbiterC * 167205520766791073U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13350266700180455548U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 4608846311203767162U;
            aOrbiterB = RotL64((aOrbiterB * 2504857468837437365U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 14195866746143604365U) + RotL64(aNonceWordH, 31U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 7917977448256795054U) ^ aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5927771378657284557U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10707336923305131629U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 17122696159336995392U;
            aOrbiterA = RotL64((aOrbiterA * 13953518568670659191U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5182322763573586116U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6503754948502556246U;
            aOrbiterF = RotL64((aOrbiterF * 14749002194140663519U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 14907832047832987341U) + aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6258064448676621346U;
            aOrbiterI = RotL64((aOrbiterI * 4407960312705621487U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1180234574888070795U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 801686887651085881U;
            aOrbiterE = RotL64((aOrbiterE * 433981853631548041U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 11810494591997709554U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 9343740505955858127U;
            aOrbiterH = RotL64((aOrbiterH * 8733378485648720323U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12816829575386720695U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 13499155707765393469U;
            aOrbiterD = RotL64((aOrbiterD * 9937924703928730369U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 28U);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterH, 13U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 43U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 19U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterJ, 22U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 57U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 39U)) + aOrbiterB) + RotL64(aNonceWordE, 25U)) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aIngress, 42U) + aOrbiterJ) + RotL64(aOrbiterB, 46U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordG, 59U)) + aWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 37U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 51U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 28U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 43U) ^ RotL64(aNonceWordG, 13U)) ^ RotL64(aNonceWordE, 3U));
            aIngress = aIngress ^ (RotL64(mSnow[((aIndex + 17899U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21427U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 60U) ^ RotL64(aNonceWordD, 27U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17587U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 17151U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 26U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 11U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererH + RotL64(aCross, 42U)) + 2571116506511057880U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 13112435411509707292U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aPrevious, 47U)) + 10403251762787357256U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 8461951095541400405U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 23U)) + 9890793478557463815U) + RotL64(aNonceWordA, 31U);
            aOrbiterF = (aWandererK + RotL64(aIngress, 53U)) + 3030229465991783707U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 5U)) + 7273848154043719247U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 13U)) + 10681774862516028276U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 35U)) + 7105082755586853104U) + RotL64(aNonceWordD, 15U);
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 6588579345319551129U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 44U)) + 14616333550242386092U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15439666290229654921U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3360304356760164799U;
            aOrbiterK = RotL64((aOrbiterK * 5164191920584106237U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14438730801970761889U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 14515616787452085729U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2041601927968559821U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 4167853822635132419U) + RotL64(aNonceWordE, 8U);
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8950982233003320239U;
            aOrbiterF = RotL64((aOrbiterF * 887144270884244907U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12391327853728029953U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 7100871010552394421U) ^ RotL64(aNonceWordB, 29U);
            aOrbiterG = RotL64((aOrbiterG * 16552349374101955967U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15381697462381887944U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6801677551341079401U;
            aOrbiterC = RotL64((aOrbiterC * 13325954438427340703U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 947011315719204867U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6356920162398333481U;
            aOrbiterB = RotL64((aOrbiterB * 5566721941682667419U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8910262020598577378U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8778455415977526457U;
            aOrbiterH = RotL64((aOrbiterH * 4092470497616637283U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5585696961453127223U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 9670655481681494412U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7863197168965036383U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 10713004007087085729U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 4036355047492922339U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6923922258047667173U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14580156873863533497U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7049502932205025182U;
            aOrbiterE = RotL64((aOrbiterE * 8665428649262370727U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12707521269341941677U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2571116506511057880U;
            aOrbiterI = RotL64((aOrbiterI * 2388236789245943699U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aPrevious, 34U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterG, 23U)) + RotL64(aNonceWordH, 23U)) + aWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 11U) + RotL64(aOrbiterA, 39U)) + aOrbiterD) + RotL64(aNonceWordF, 61U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterF, 54U));
            aWandererA = aWandererA + (((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 57U)) + aOrbiterH) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterD, 35U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 21U)) + aOrbiterC) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterA, 44U));
            aWandererD = aWandererD + ((RotL64(aIngress, 44U) + aOrbiterB) + RotL64(aOrbiterH, 5U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 28U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 5U) ^ RotL64(aNonceWordH, 19U)) ^ RotL64(aNonceWordA, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 26411U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 22828U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordB, 47U)) ^ RotL64(aNonceWordF, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26917U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 22503U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCross, 19U)) + (RotL64(aIngress, 37U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererG + RotL64(aIngress, 57U)) + 12615321415808640429U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 13U)) + 15712784676459931207U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aScatter, 48U)) + 11013335427004930046U;
            aOrbiterH = (aWandererK + RotL64(aCross, 29U)) + 8298733856304768806U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 37U)) + 6207732959150824216U) + RotL64(aNonceWordD, 10U);
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 9769864876127544038U) + RotL64(aNonceWordC, 27U);
            aOrbiterF = ((aWandererI + RotL64(aCross, 18U)) + RotL64(aCarry, 41U)) + 10782181918651152563U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 47U)) + 5790454015845620939U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 39U)) + 15606578025386733803U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 5U)) + 5522352539991175304U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aCross, 41U)) + 5993355818572869649U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 10864534396947622047U) + RotL64(aNonceWordE, 29U);
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12090053126235913528U;
            aOrbiterA = RotL64((aOrbiterA * 7250801471645972261U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14191181677234981396U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 2258570108233924592U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8307541155393855209U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8448114811381534603U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2702389315763499817U;
            aOrbiterD = RotL64((aOrbiterD * 6710443836432274393U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17202184076718780200U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 150549910056015002U;
            aOrbiterI = RotL64((aOrbiterI * 195034681254956335U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4910512055808124967U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4783477997418403079U;
            aOrbiterB = RotL64((aOrbiterB * 861977492146512865U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 13842899106208709771U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7930112618036681468U;
            aOrbiterH = RotL64((aOrbiterH * 8609551859830858419U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8790107242863198659U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6882768826643279144U;
            aOrbiterF = RotL64((aOrbiterF * 13745521454063360763U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12136498871759890015U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 8120456314755584336U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1830725195528043575U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14425711740351183016U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15907406009196323049U;
            aOrbiterE = RotL64((aOrbiterE * 8599371693260686839U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4878521420367891861U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1184672056055028939U;
            aOrbiterK = RotL64((aOrbiterK * 5963961755367831967U), 37U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterE) + 10126736568567000180U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + RotL64(aNonceWordF, 7U);
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12615321415808640429U;
            aOrbiterC = RotL64((aOrbiterC * 11663715449073755137U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 11U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 20U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterK, 18U)) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 54U) + aOrbiterF) + RotL64(aOrbiterC, 11U));
            aWandererI = aWandererI + ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterF, 51U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterH, 47U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 54U)) + aOrbiterB) + RotL64(aCarry, 39U)) + RotL64(aNonceWordH, 55U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterH, 57U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 29U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 41U)) + aOrbiterI) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterB, 27U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterG, 43U)) + RotL64(aNonceWordB, 15U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 27U) + RotL64(aOrbiterI, 5U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 24U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 22U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 13U) ^ RotL64(aNonceWordE, 5U)) ^ RotL64(aNonceWordB, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 28093U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((aIndex + 29091U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 51U) ^ RotL64(aNonceWordC, 19U)) ^ RotL64(aNonceWordA, 28U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28544U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 27898U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 53U)) + (RotL64(aIngress, 39U) + RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererH + RotL64(aScatter, 54U)) + 12980104182836602177U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 41U)) + 3172622203188863995U) + RotL64(aNonceWordB, 59U);
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 43U)) + 1170974132219980203U) + aOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 19U)) + 6035201940965047490U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aPrevious, 10U)) + 18033907118424996722U;
            aOrbiterF = (aWandererA + RotL64(aCross, 51U)) + 14604813424800580304U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 13U)) + 13720232492851066035U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 47U)) + 3902659710585257448U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 8331560652661619868U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 57U)) + 4485014147538689794U) + RotL64(aNonceWordD, 25U);
            aOrbiterG = (aWandererG + RotL64(aScatter, 21U)) + 168202636924512424U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 16227825670092707848U) + RotL64(aNonceWordG, 41U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 4792781933944671365U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15859849676231455283U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12636865372722601282U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 18198291399585556632U;
            aOrbiterE = RotL64((aOrbiterE * 18155803890313399795U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3650053185419807206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5897288963905408776U;
            aOrbiterF = RotL64((aOrbiterF * 3706949366974086151U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 9922308113622901726U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13352279749091561510U;
            aOrbiterI = RotL64((aOrbiterI * 4025213180483632557U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14969461950939646117U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10231661776135056651U;
            aOrbiterD = RotL64((aOrbiterD * 11284575051455238501U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10621934544068320859U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6029116920305246887U;
            aOrbiterC = RotL64((aOrbiterC * 6087523725059376905U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 12887482425168671195U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8351351557123783853U;
            aOrbiterH = RotL64((aOrbiterH * 3839381627914762245U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5405938210926464973U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 385145802287899406U) ^ RotL64(aNonceWordA, 17U);
            aOrbiterG = RotL64((aOrbiterG * 8330751480464271445U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7907749190875916461U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 5138733192253468642U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17028325976353263843U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14382272868178763187U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14354777100157531233U;
            aOrbiterK = RotL64((aOrbiterK * 7095764230272037767U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4390647647193363824U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12980104182836602177U;
            aOrbiterA = RotL64((aOrbiterA * 11124472075872147333U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 21U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 6U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterF, 53U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordH, 44U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 56U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 37U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 21U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterJ, 5U)) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 18U) + aOrbiterI) + RotL64(aOrbiterB, 29U));
            aWandererE = aWandererE + ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterF, 35U)) + aWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 13U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 4U) + RotL64(aOrbiterG, 50U)) + aOrbiterH) + RotL64(aNonceWordE, 43U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 48U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 40U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_VolleyBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFF6D0788ABEDD861ULL + 0xDAF722153C89E882ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x86ECA597D44D790DULL + 0xB966EA2D1EDBA1F3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE737EE580486957DULL + 0xF5AA3B8FD81AAA74ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE923EC47E116F69DULL + 0xBCE39ABCE57F34B6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD653CACDA6C1E4F9ULL + 0x8209A77EE1D6A15FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB55FF31F70C2EAD9ULL + 0xCF9C4F555C1F961BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEAE090CEEFA7FF13ULL + 0xF886CABD64B9D83CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD8796989CD7030FBULL + 0xDCAE9E615D868C99ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 27U) ^ RotL64(aNonceWordE, 3U)) ^ RotL64(aNonceWordH, 51U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6421U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6240U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 36U) ^ RotL64(aNonceWordD, 51U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5287U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 6426U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererE + RotL64(aIngress, 43U)) + 3255291173184001106U) + aOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 35U)) + 15308468160116255528U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 21U)) + 18186972408589866656U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 57U)) + 4439324265978331914U) + RotL64(aNonceWordD, 40U);
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 10U)) + RotL64(aCarry, 13U)) + 13099263173016322486U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 7041561081767500660U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 29U)) + 6196422612687812971U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 19U)) + 7664260932541281413U) + RotL64(aNonceWordC, 27U);
            aOrbiterE = (aWandererF + RotL64(aIngress, 52U)) + 17802347823020441056U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 4253107484061190446U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13799496534030645312U;
            aOrbiterA = RotL64((aOrbiterA * 9167675060053848207U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14252892847595951926U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5663527578664291422U;
            aOrbiterI = RotL64((aOrbiterI * 18314294235895182465U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11148755959699137661U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 17036900929333594592U) ^ RotL64(aNonceWordF, 41U);
            aOrbiterB = RotL64((aOrbiterB * 16041243617369003291U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2403828181385259549U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17813580350434928194U;
            aOrbiterE = RotL64((aOrbiterE * 13666780980793857831U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5623611126885414523U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7293224381174846969U;
            aOrbiterK = RotL64((aOrbiterK * 7032561584670788117U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 10602620906929686163U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 18015916257203385982U;
            aOrbiterF = RotL64((aOrbiterF * 10684090189688871993U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13592915735376305773U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 13995866908043417505U) ^ aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3802175869395887331U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8200465989447697618U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 9866671660800629464U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2138851839905326265U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 11557528777230608777U) + RotL64(aNonceWordA, 47U);
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 131060617338185060U;
            aOrbiterD = RotL64((aOrbiterD * 11068705423012265209U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 58U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterB, 53U)) + RotL64(aNonceWordB, 53U));
            aWandererK = aWandererK + ((RotL64(aScatter, 34U) + aOrbiterC) + RotL64(aOrbiterF, 35U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 29U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 4U)) + aOrbiterF) + RotL64(aCarry, 57U)) + RotL64(aNonceWordG, 35U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 47U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterE, 43U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterE, 39U));
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterB, 13U)) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 18U)) + aOrbiterD) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordD, 51U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 11351U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14478U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 24U) ^ RotL64(aNonceWordB, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12779U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 8702U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCarry, 36U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 27U)) + 8975885703279267062U) + RotL64(aNonceWordF, 59U);
            aOrbiterB = ((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 8664844915562660637U;
            aOrbiterE = (((aWandererK + RotL64(aIngress, 5U)) + 12281774799736296726U) + aOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + RotL64(aNonceWordB, 37U);
            aOrbiterD = (aWandererD + RotL64(aScatter, 27U)) + 15347461352311329726U;
            aOrbiterC = (aWandererI + RotL64(aCross, 20U)) + 12967500561828907834U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 57U)) + 5002833859280402726U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 11U)) + 11908257536954668983U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 17017174811949227162U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 36U)) + 16851323125613931180U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13469326957728686706U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5228638551056105241U;
            aOrbiterE = RotL64((aOrbiterE * 13369947664646167255U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11945166198089308564U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16268645041872996022U;
            aOrbiterC = RotL64((aOrbiterC * 5391448793718370911U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14781204627695095701U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 5365325354838101092U) ^ RotL64(aNonceWordE, 40U);
            aOrbiterG = RotL64((aOrbiterG * 8017284997946310807U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 563147416025715953U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14660867395395625851U;
            aOrbiterI = RotL64((aOrbiterI * 4769458126865307103U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3168989056355712105U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16179131669773665579U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5641461617066671723U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4160220074225527179U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 8597134686962559111U) ^ RotL64(aNonceWordC, 47U);
            aOrbiterJ = RotL64((aOrbiterJ * 639572585431474015U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16811551552456811661U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 5827323970423386301U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9328247349730652021U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15583234353262170227U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2950816254621717748U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1102417597476170143U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4426165025104306337U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11871220132164971152U;
            aOrbiterB = RotL64((aOrbiterB * 2366168050042802207U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 36U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 47U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + RotL64(aNonceWordA, 5U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 38U) + aOrbiterB) + RotL64(aOrbiterC, 14U));
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 43U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aCross, 5U) + RotL64(aOrbiterI, 57U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterG, 34U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 58U) + aOrbiterE) + RotL64(aOrbiterK, 53U)) + RotL64(aNonceWordH, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 21U)) + aOrbiterD) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterD, 5U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 26U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 21U) ^ RotL64(aNonceWordF, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23511U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneA[((aIndex + 18815U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 28U) ^ RotL64(aNonceWordD, 13U)) ^ RotL64(aNonceWordA, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21244U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 21873U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 51U) + RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererB + RotL64(aIngress, 44U)) + 8604208734152026945U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 1374329953253889829U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 57U)) + 5779278910548228339U) + aOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 47U)) + 17670451230882805140U) + RotL64(aNonceWordC, 15U);
            aOrbiterG = (aWandererF + RotL64(aIngress, 21U)) + 8193848740764866860U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 10U)) + 15801168428145650104U;
            aOrbiterC = (aWandererC + RotL64(aCross, 39U)) + 2584718176087499066U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 14950366247822737997U;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 5U)) + 9779293225265670135U) + aOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1]) + RotL64(aNonceWordH, 44U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8688968319288372383U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13665723186950342601U;
            aOrbiterF = RotL64((aOrbiterF * 292035540396910837U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9395428688359973510U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2152719218018108418U;
            aOrbiterI = RotL64((aOrbiterI * 15271961483518392671U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 1350324137411377992U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8729317951386057921U;
            aOrbiterJ = RotL64((aOrbiterJ * 6008790836417785083U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 6317310451893678411U) + RotL64(aNonceWordF, 5U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 10175620379041384281U) ^ RotL64(aNonceWordG, 19U);
            aOrbiterK = RotL64((aOrbiterK * 14079679617394330781U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1203082119358827708U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 523869107818193101U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4629501113595689157U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 4028324959540432983U) + aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15447631947468213912U;
            aOrbiterH = RotL64((aOrbiterH * 6037306615787729185U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14225888694733041031U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11925000696281947629U;
            aOrbiterC = RotL64((aOrbiterC * 4337022940520411253U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15015531024930608745U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16752579225076943550U;
            aOrbiterA = RotL64((aOrbiterA * 15551083683579981439U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2432733494869267901U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 10103430321388601485U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18372919379972432569U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 24U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterF, 52U));
            aWandererK = aWandererK + (((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 26U) + aOrbiterH) + RotL64(aOrbiterA, 21U));
            aWandererB = aWandererB + ((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 29U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterC, 5U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterG, 12U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 58U) + aOrbiterC) + RotL64(aOrbiterG, 47U)) + RotL64(aNonceWordE, 17U)) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 43U)) + RotL64(aNonceWordD, 21U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 35U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 52U) ^ RotL64(aNonceWordB, 23U)) ^ RotL64(aNonceWordH, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25876U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28999U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 44U) ^ RotL64(aNonceWordF, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32507U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 27737U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 40U)) + (RotL64(aIngress, 13U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererF + RotL64(aPrevious, 35U)) + 9107326720193244489U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 58U)) + 10868585484401664145U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 47U)) + 13637736741437846622U;
            aOrbiterA = (aWandererK + RotL64(aCross, 21U)) + 6130725216183918844U;
            aOrbiterD = (((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 2063834478521338187U) + RotL64(aNonceWordC, 7U);
            aOrbiterI = (((aWandererB + RotL64(aScatter, 43U)) + 8564870627911949158U) + aOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1]) + RotL64(aNonceWordD, 49U);
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 39U)) + 6524015751064086390U;
            aOrbiterE = (((aWandererH + RotL64(aCross, 30U)) + RotL64(aCarry, 13U)) + 9874937766875388236U) + aOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aScatter, 5U)) + 14723718409522680894U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13767059954741528279U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6387608251033722169U;
            aOrbiterH = RotL64((aOrbiterH * 6601902195707980693U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5391425980008431000U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11524218415655093779U;
            aOrbiterD = RotL64((aOrbiterD * 12508457981779189389U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 155510463350385905U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 10554591788433641311U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5412084824127934293U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8662160162966241542U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5092555636369853727U;
            aOrbiterG = RotL64((aOrbiterG * 433807340167635499U), 29U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 7163345798448796101U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordG, 41U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 695089002178413267U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17302689458565434475U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 5409173939213468972U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15349690077393827541U;
            aOrbiterI = RotL64((aOrbiterI * 10984681254001609841U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12376011890751302027U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7809614158898158383U) ^ RotL64(aNonceWordA, 10U);
            aOrbiterE = RotL64((aOrbiterE * 13845113198736843629U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13031938699536449576U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3983178190194056516U;
            aOrbiterC = RotL64((aOrbiterC * 1341678482929213405U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5567935037909671790U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17137042627663349797U;
            aOrbiterB = RotL64((aOrbiterB * 13535586899620672373U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 13U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 6U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 60U) + aOrbiterG) + RotL64(aOrbiterC, 27U));
            aWandererB = aWandererB + (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 19U)) + aOrbiterC) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterA, 60U)) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 23U)) + aOrbiterB) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 50U) + aOrbiterE) + RotL64(aOrbiterD, 43U)) + RotL64(aNonceWordF, 57U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 35U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 48U)) + aOrbiterH);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterI, 11U)) + RotL64(aNonceWordE, 39U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 42U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_VolleyBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x840B59AC1B70669DULL + 0xBF63391A36810E1AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8ED237269D075B11ULL + 0x871F1F797A3A4E9EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEA0F42E653DFE183ULL + 0xED77129BD7EB392BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB9463D74CA95C8C1ULL + 0xF593C326D5E23663ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB06A67E457A43DC9ULL + 0x90D0C8983252DF2FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE40B3E4220B78AABULL + 0xB2CBCD2F91C97645ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD76A99515111B76DULL + 0xF1EEA06FF269AC18ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF65CBB27927B9795ULL + 0xA8D256F3EFF8E431ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 24U) ^ RotL64(aNonceWordC, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5774U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 651U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 27U) ^ RotL64(aNonceWordH, 43U)) ^ RotL64(aNonceWordE, 54U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7614U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5537U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 36U)) + 898812731947995389U) + RotL64(aNonceWordF, 5U);
            aOrbiterD = ((aWandererG + RotL64(aCross, 13U)) + 8677347622525527167U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 770321564027567654U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 11020474858081526395U) + RotL64(aNonceWordG, 41U);
            aOrbiterG = (((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 17289793580414993470U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 10111912559295118444U) + RotL64(aNonceWordB, 35U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 8083622125544542011U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3610772128071340341U), 57U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 7149858558922988240U) + aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1]) + RotL64(aNonceWordA, 23U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5919683821379905699U;
            aOrbiterJ = RotL64((aOrbiterJ * 16705119888884231567U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6860902846079238714U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15083517836867542075U;
            aOrbiterC = RotL64((aOrbiterC * 4686657139237578325U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 14852868368708376381U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9860233289028878323U;
            aOrbiterD = RotL64((aOrbiterD * 13418143547952204667U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 772406119079116272U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 7971141501337627589U) ^ aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10168120622976358617U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 28U) + aOrbiterC) + RotL64(aOrbiterD, 3U)) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 39U)) + aOrbiterC) + RotL64(aCarry, 39U)) + RotL64(aNonceWordH, 14U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 51U)) + aOrbiterG) + RotL64(aNonceWordD, 37U)) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterG, 14U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterD, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 37U) ^ RotL64(aNonceWordB, 21U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12503U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8955U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordD, 19U)) ^ RotL64(aNonceWordA, 48U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8399U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12029U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 40U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererF + RotL64(aScatter, 14U)) + 14249093584376402677U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + RotL64(aNonceWordE, 13U);
            aOrbiterG = ((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 5U)) + 8756965951816492264U;
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 43U)) + 11221139480258176330U) + RotL64(aNonceWordG, 45U);
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 17218894445564194851U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aScatter, 47U)) + 8064642692524949490U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5822093203710704646U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 3217799620158102238U) ^ RotL64(aNonceWordH, 29U);
            aOrbiterJ = RotL64((aOrbiterJ * 2806328682494910635U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2613757677892120843U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 13647481499551657237U;
            aOrbiterB = RotL64((aOrbiterB * 5517563514031899891U), 39U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 3545714196663685016U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordF, 3U);
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9735422670576621521U;
            aOrbiterE = RotL64((aOrbiterE * 7276207208162697249U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3911046580637583767U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9315984027042049203U;
            aOrbiterG = RotL64((aOrbiterG * 12568550776487242469U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 8926367674641729058U) + aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11035347490524961446U;
            aOrbiterC = RotL64((aOrbiterC * 10948288997163592463U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 46U);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 4U)) + RotL64(aNonceWordD, 46U)) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 51U)) + aOrbiterB) + aWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterJ, 39U)) + RotL64(aNonceWordB, 17U));
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 52U) ^ RotL64(aNonceWordA, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22029U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19397U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 57U) ^ RotL64(aNonceWordD, 19U)) ^ RotL64(aNonceWordH, 47U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19405U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21678U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 47U) + RotL64(aCarry, 35U)) ^ (RotL64(aCross, 22U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 2786079456995203065U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 7237256119153857253U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 9310834010563647604U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aCross, 27U)) + 17361734905706517877U) + RotL64(aNonceWordB, 39U);
            aOrbiterD = (((aWandererF + RotL64(aScatter, 44U)) + 15837111231884647451U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordG, 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 18065431964418026445U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 3029123922999952652U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16309219658285890145U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5166926595573507837U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 1918425684273807598U) ^ RotL64(aNonceWordD, 23U);
            aOrbiterA = RotL64((aOrbiterA * 16616641579714896719U), 3U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 4724551751012661440U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordH, 3U);
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1818014487579644390U;
            aOrbiterB = RotL64((aOrbiterB * 14904092108647864911U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 6670090372241084216U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8485757110007268693U;
            aOrbiterH = RotL64((aOrbiterH * 11876760095108618363U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 4928130251509514742U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2528788422725346792U;
            aOrbiterD = RotL64((aOrbiterD * 1855982047967756661U), 37U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 3U)) + aOrbiterH) + RotL64(aNonceWordC, 41U)) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterD, 35U)) + RotL64(aNonceWordF, 14U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 30U) + aOrbiterB) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterD, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 48U) ^ RotL64(aNonceWordB, 13U)) ^ RotL64(aNonceWordC, 39U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28761U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 31849U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 41U) ^ RotL64(aNonceWordD, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27555U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneD[((aIndex + 31137U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 4U) + RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 12122689833405846292U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aCross, 10U)) + 9640400270962766788U) + RotL64(aNonceWordA, 27U);
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 9141937998266739071U) + RotL64(aNonceWordD, 37U);
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 12899395770434090537U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 35U)) + 13457918115408031842U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15134784483576000943U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12540961268790055438U;
            aOrbiterJ = RotL64((aOrbiterJ * 3295706140418040089U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 6306886773092764230U) + RotL64(aNonceWordG, 19U);
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13573343491337243121U;
            aOrbiterE = RotL64((aOrbiterE * 15893457012357368707U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8545588657348974413U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10891410570357275120U;
            aOrbiterF = RotL64((aOrbiterF * 5399310978367842841U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 2877137119767060151U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + RotL64(aNonceWordF, 9U);
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9178097682386595144U;
            aOrbiterD = RotL64((aOrbiterD * 3524486002084427513U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 15528007881855616978U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 11368419529245281435U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12433207037378339309U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 18U);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 60U) + RotL64(aOrbiterE, 3U)) + aOrbiterH) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterH, 13U)) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 51U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ) + RotL64(aNonceWordC, 15U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterE, 38U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordE, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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

void TwistExpander_VolleyBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x808982BCFC693D11ULL + 0xCAE56642B1973A5DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE8B0E2012BBBBB49ULL + 0xD6396FD4464C2A32ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE57D653548A9F4FBULL + 0xECBB93ED23ED5038ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8B43862EA741EDE5ULL + 0x9B68B50D0808A8BAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9677772560E65F5FULL + 0xF6F8CFAA4262BF63ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE43748CE3E0B3AADULL + 0xE98177B22215C61AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE320147D31A53A89ULL + 0xB93CF933F66500DCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9EEB88B2BD9D613BULL + 0xAF630CBE532F94C2ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordB, 13U)) ^ RotL64(aNonceWordD, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6041U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 7556U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 42U) ^ RotL64(aNonceWordH, 13U)) ^ RotL64(aNonceWordA, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4917U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5415U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 53U)) + (RotL64(aIngress, 40U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 41U)) + 5160910997561396461U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 35U)) + 14920764751058512062U) + aOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 6080952401749660022U) + RotL64(aNonceWordF, 61U);
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 17667234330526298627U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aIngress, 27U)) + 760630072638686756U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 6U)) + 3504157162816997476U) + RotL64(aNonceWordA, 53U);
            aOrbiterE = (aWandererF + RotL64(aCross, 57U)) + 9489022223422585882U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 1149898536879968964U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10492284328940025310U;
            aOrbiterJ = RotL64((aOrbiterJ * 7893416766300156495U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13213275606286399312U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 10557118912847180413U) ^ RotL64(aNonceWordB, 16U);
            aOrbiterF = RotL64((aOrbiterF * 10077877991284587845U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 15618980209023994776U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 5268600749854045564U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3849660559223919613U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8011552687609649990U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3148133096349525066U;
            aOrbiterE = RotL64((aOrbiterE * 5245156554959620007U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12032847944237867285U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14999005703490824673U;
            aOrbiterD = RotL64((aOrbiterD * 6631584955208646049U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5426735969392906710U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3593177531650386729U;
            aOrbiterA = RotL64((aOrbiterA * 12997284886192717043U), 21U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterA) + 1701444719333347373U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordE, 27U);
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15928731228196894960U;
            aOrbiterG = RotL64((aOrbiterG * 1919318226904213433U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 28U);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterA, 13U)) + RotL64(aNonceWordC, 35U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 60U)) + aOrbiterH) + RotL64(aNonceWordG, 31U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 3U)) + aOrbiterH) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterG, 19U)) + aWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 14U) + aOrbiterE) + RotL64(aOrbiterA, 43U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 12U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 28U) ^ RotL64(aNonceWordB, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14304U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11314U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 41U) ^ RotL64(aNonceWordG, 18U)) ^ RotL64(aNonceWordD, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12996U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 15452U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 48U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 439898681482066326U;
            aOrbiterH = (((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 27U)) + 17362083676671776094U) + RotL64(aNonceWordD, 29U);
            aOrbiterB = (aWandererC + RotL64(aScatter, 47U)) + 6418499837265155024U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 13U)) + 17262244253027454972U) + aOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aCross, 3U)) + 2382066162993139503U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 60U)) + RotL64(aCarry, 57U)) + 14345808395587174135U) + RotL64(aNonceWordH, 27U);
            aOrbiterJ = (aWandererD + RotL64(aScatter, 41U)) + 7534743166385552851U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 16994453324688523966U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7079553728544045092U;
            aOrbiterB = RotL64((aOrbiterB * 10104892188895367489U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3562822704508440641U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 13990892681975857821U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) ^ RotL64(aNonceWordG, 13U);
            aOrbiterI = RotL64((aOrbiterI * 8352929306654078795U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 1796728922368577238U) + RotL64(aNonceWordE, 55U);
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6605161260520067178U;
            aOrbiterA = RotL64((aOrbiterA * 8147537646591674091U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13994083795942328918U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6144523182899107711U;
            aOrbiterH = RotL64((aOrbiterH * 4153879991344611283U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 12247462325297436642U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1065809332002012789U;
            aOrbiterK = RotL64((aOrbiterK * 5496601177032953251U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10147919864511540753U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 17138553441127273354U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5773875596275267871U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2653924016109573974U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6254416952351699582U;
            aOrbiterJ = RotL64((aOrbiterJ * 12756861659704947257U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 51U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 13U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 39U)) + RotL64(aNonceWordF, 23U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterB, 43U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterI, 6U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 37U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aIngress, 60U) + RotL64(aOrbiterA, 21U)) + aOrbiterB) + RotL64(aNonceWordC, 44U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterK, 57U)) + aWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordB, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16989U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((aIndex + 20931U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 13U) ^ RotL64(aNonceWordG, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16820U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 16552U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 5U)) ^ (RotL64(aIngress, 27U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererE + RotL64(aPrevious, 3U)) + 252059974543142812U;
            aOrbiterC = (((aWandererK + RotL64(aScatter, 57U)) + 11690823093681457368U) + aOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1]) + RotL64(aNonceWordF, 55U);
            aOrbiterA = (aWandererC + RotL64(aIngress, 21U)) + 13282189752890971123U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 9507416294305708435U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 29U)) + 14053038174390776539U) + RotL64(aNonceWordC, 5U);
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 46U)) + RotL64(aCarry, 5U)) + 14605253312318725009U;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 18138286582677863671U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 8530091235978489988U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 14381731677571170073U) ^ aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11675896999665768253U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 13316413456378978456U) + RotL64(aNonceWordH, 48U);
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3910529530149320706U;
            aOrbiterC = RotL64((aOrbiterC * 16000139333493588429U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6302070286831566901U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12324134652758551396U;
            aOrbiterH = RotL64((aOrbiterH * 17136438281540250165U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4773478557638475048U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4031153435446078944U;
            aOrbiterJ = RotL64((aOrbiterJ * 3876928995240982769U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 3114794895962903899U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3552936509969106796U;
            aOrbiterB = RotL64((aOrbiterB * 16823186892738820299U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 5828754613946145627U) + RotL64(aNonceWordD, 17U);
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 17985241114076114558U;
            aOrbiterI = RotL64((aOrbiterI * 1986669631395606833U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 11319331046368072261U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6104267020171882160U;
            aOrbiterF = RotL64((aOrbiterF * 12525117969211576177U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 44U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 57U)) + aOrbiterF) + RotL64(aNonceWordA, 27U)) + aWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 21U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterH, 5U));
            aWandererB = aWandererB + ((((RotL64(aCross, 44U) + aOrbiterA) + RotL64(aOrbiterJ, 12U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordE, 51U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterB, 47U));
            aWandererK = aWandererK + ((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 35U)) + aOrbiterI);
            aWandererF = aWandererF ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterC, 27U)) + aOrbiterF) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 6U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 30U) ^ RotL64(aNonceWordF, 5U)) ^ RotL64(aNonceWordG, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26789U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25933U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 29U) ^ RotL64(aNonceWordA, 40U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30411U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25657U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 23U)) + (RotL64(aPrevious, 10U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 5906639480605353429U;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 11U)) + 5293518570213287605U) + RotL64(aNonceWordE, 49U);
            aOrbiterG = (aWandererF + RotL64(aCross, 43U)) + 15383185501428521377U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 27U)) + 15364072512743978902U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aCross, 4U)) + RotL64(aCarry, 23U)) + 4525473357144014271U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 13U)) + 10400911938125603074U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 57U)) + 16417506293824627550U) + RotL64(aNonceWordG, 55U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2419329331753341815U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 14929222427923332069U) ^ RotL64(aNonceWordC, 6U);
            aOrbiterG = RotL64((aOrbiterG * 11596261802662514979U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 16771573504983922586U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 1863466450051787622U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2585626547126027053U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12895350137096692415U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3700979086526298327U) ^ aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10279730254867618193U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 1977099106211282426U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6144698304096915742U;
            aOrbiterK = RotL64((aOrbiterK * 5039822990560519609U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3858895556659724975U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1283646340363435327U;
            aOrbiterD = RotL64((aOrbiterD * 11622421841377018069U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 6240532051889108891U) + aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 757364889381634634U;
            aOrbiterI = RotL64((aOrbiterI * 943852137901972945U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 5272945693977418174U) + RotL64(aNonceWordB, 9U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6850528198786172283U;
            aOrbiterJ = RotL64((aOrbiterJ * 1966383079897679953U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aPrevious, 18U) + RotL64(aOrbiterG, 57U)) + aOrbiterI) + RotL64(aCarry, 57U)) + RotL64(aNonceWordD, 5U)) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterB, 3U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterK, 10U));
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 35U)) + aOrbiterD) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterK, 21U));
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterB, 29U)) + RotL64(aNonceWordF, 35U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 28U));
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_VolleyBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8969124E6CE0C21BULL + 0xAB982A0C6538863FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD216A8A51F55F2B5ULL + 0xFF5B29D4FA3BC644ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEA99A8ECD10CDDDBULL + 0x9BD0F411E8F7B01CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xFBA9FF8326EF81E1ULL + 0xFDB2A454EA077384ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9F0EAF0F08C457D3ULL + 0xF652C5081442AD15ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA017A02C590ADAA5ULL + 0xDD50F79E5209AEBFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x944A821DB4F8BA43ULL + 0xC2E97A605437C92AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA802D8C7877576B5ULL + 0xF7B7D408E7F929E1ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 47U) ^ RotL64(aNonceWordH, 57U)) ^ RotL64(aNonceWordE, 38U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 5738U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1165U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 39U) ^ RotL64(aNonceWordF, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3380U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((aIndex + 7581U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 12U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 15652862298542575895U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 47U)) + 16925323928418184554U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 36U)) + 4413861484961668394U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 2215946422098155969U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 3U)) + 14975185533513111110U) + RotL64(aNonceWordH, 3U);
            aOrbiterK = (((aWandererD + RotL64(aScatter, 27U)) + 9711613814905834552U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordD, 49U);
            aOrbiterB = (aWandererF + RotL64(aPrevious, 43U)) + 13154957291850149471U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5058313016418534840U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 15011423472941211620U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6125316151731105673U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2030053257469580168U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 150530795186791193U;
            aOrbiterA = RotL64((aOrbiterA * 11106050063717096073U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 10878237472104183427U) + RotL64(aNonceWordA, 7U);
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11724672539469573109U;
            aOrbiterK = RotL64((aOrbiterK * 16158741837357985395U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9589700906445846956U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1367381624958248949U;
            aOrbiterB = RotL64((aOrbiterB * 8459515089081211977U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 12003215666757518106U) + RotL64(aNonceWordF, 37U);
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11232479330848006729U;
            aOrbiterH = RotL64((aOrbiterH * 10993290955464593033U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 13013910456628561621U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 6092509838924105265U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 805601154718006061U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11999225836250312801U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 14421271973875748413U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9529010940887430157U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordG, 38U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterD, 30U)) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 60U) + aOrbiterD) + RotL64(aOrbiterB, 57U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterH, 13U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterG, 51U)) + RotL64(aNonceWordC, 13U)) + aWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 3U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 42U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 28U) ^ RotL64(aNonceWordC, 57U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 13616U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8780U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordF, 22U)) ^ RotL64(aNonceWordA, 39U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14053U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 16130U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 26U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererH + RotL64(aCross, 5U)) + 1364174714924216027U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordB, 47U);
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 13561796874229506613U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 41U)) + 11845572344206238305U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 12U)) + 15762708240326773763U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 21U)) + 1157119665207900473U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 6823546624372055260U;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 51U)) + 14465564210523945121U) + RotL64(aNonceWordH, 31U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10667464548080807531U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13445737493224316575U;
            aOrbiterD = RotL64((aOrbiterD * 12137295000900795711U), 57U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 3009837893785957665U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordC, 35U);
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2886920524111083752U;
            aOrbiterK = RotL64((aOrbiterK * 15308180928967762543U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 10886177449328249656U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15067759884678100433U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5724566815989860041U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 18307930462682331536U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8791864377579255801U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9265158882471421767U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 805797468642992351U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5743305867058244964U;
            aOrbiterB = RotL64((aOrbiterB * 16263000753351131717U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17102025528234481273U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 1841579177327486899U) ^ RotL64(aNonceWordD, 10U);
            aOrbiterC = RotL64((aOrbiterC * 3841603385577825265U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2189493507896508972U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 18209567010094914374U;
            aOrbiterI = RotL64((aOrbiterI * 3737080408976852351U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 12U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 27U)) + aOrbiterC) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterI, 58U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordG, 27U)) + aWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 13U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordA, 53U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterD, 3U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 21U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterE, 37U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererI, 56U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 29U) ^ RotL64(aNonceWordA, 10U)) ^ RotL64(aNonceWordG, 53U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 18221U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23816U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 35U) ^ RotL64(aNonceWordC, 18U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19772U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((aIndex + 16939U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 26U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 53U)) + 4179952823252098240U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 3745613452332101749U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aIngress, 35U)) + 2955689793395307176U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 5639060180251322019U) + RotL64(aNonceWordF, 26U);
            aOrbiterF = (aWandererA + RotL64(aIngress, 48U)) + 7901969163853586463U;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 11U)) + 2242166787816318119U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) + RotL64(aNonceWordC, 49U);
            aOrbiterK = (aWandererG + RotL64(aPrevious, 29U)) + 5239936443960750064U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13939136954732185558U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17058884136712717463U;
            aOrbiterB = RotL64((aOrbiterB * 7222348891215482977U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 18148618660054585941U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7022023484530327814U;
            aOrbiterI = RotL64((aOrbiterI * 650100011311048589U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 7722084537340095637U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11764151879690934182U;
            aOrbiterD = RotL64((aOrbiterD * 12264384877711365655U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16412785901758144708U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 9666718667728274824U) ^ aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10865799822751771795U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 4307127540152109364U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2457646804702647606U;
            aOrbiterF = RotL64((aOrbiterF * 6340030928007058595U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 3179394870088602208U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 504977947273774249U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16190282058883481551U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 16182729401018310837U) + RotL64(aNonceWordB, 7U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 7110817020445860609U) ^ RotL64(aNonceWordH, 53U);
            aOrbiterK = RotL64((aOrbiterK * 13371352088428584087U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 4U)) + aOrbiterK) + aWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 38U) + aOrbiterJ) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordE, 25U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterD, 35U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterI, 13U)) + RotL64(aNonceWordD, 61U)) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterJ, 19U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterE, 53U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 52U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 47U) ^ RotL64(aNonceWordC, 24U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 25821U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 27404U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 57U) ^ RotL64(aNonceWordG, 46U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31587U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 26068U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 43U)) ^ (RotL64(aCarry, 29U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererH + RotL64(aPrevious, 35U)) + 18191288703716505885U;
            aOrbiterH = (((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 9824014524910417136U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (((aWandererE + RotL64(aIngress, 47U)) + 11953012029254917548U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordE, 19U);
            aOrbiterB = ((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 11U)) + 6297568011027199089U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 5U)) + 2576999400457367975U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 13176139160575558254U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 28U)) + 9978408174563621810U) + RotL64(aNonceWordA, 31U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 16765834875061607142U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) + RotL64(aNonceWordF, 51U);
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16534507305459121344U;
            aOrbiterF = RotL64((aOrbiterF * 8943988574248229067U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 3114710944346151807U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10240517868726718592U;
            aOrbiterG = RotL64((aOrbiterG * 4645691562915606463U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 10721450637990777883U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 16689590768796583952U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3046344179729901637U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2427422768928450209U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13495584061816457831U;
            aOrbiterA = RotL64((aOrbiterA * 6670984773768885119U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 7058636403765106682U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9897341853944713767U;
            aOrbiterC = RotL64((aOrbiterC * 14286816859999869231U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17749559755733386064U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 12515645083926326659U) ^ RotL64(aNonceWordC, 37U);
            aOrbiterB = RotL64((aOrbiterB * 6582878478865838245U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2625692458813609962U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10596240255026143019U;
            aOrbiterI = RotL64((aOrbiterI * 11605800195771080135U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 4U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterF, 35U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 41U)) + aOrbiterA) + RotL64(aCarry, 39U)) + RotL64(aNonceWordH, 16U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterI, 27U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 21U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 13U)) + aOrbiterH) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + (((((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 56U)) + aOrbiterH) + RotL64(aCarry, 5U)) + RotL64(aNonceWordB, 11U)) + aWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 48U) + aOrbiterB) + RotL64(aOrbiterA, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 52U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_VolleyBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA62A7B25DDF957C5ULL + 0xD4E74400177EC1A6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEB374FCFDBC16BB3ULL + 0xBF106DC30FE28C5CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xAC0249FA4DC0B043ULL + 0x9E30F18805CB7065ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB209C43A309ECBDBULL + 0xAF5D3ABF368D70D2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD9EA4F280282B301ULL + 0xC35460C120116910ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8E679993F75B4099ULL + 0xA84AAA488F6C491AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x87684BD39A59BD83ULL + 0xD9C405EDAB0CB604ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x83A383349029C79DULL + 0xB40A19453F10BCB5ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 6U) ^ RotL64(aNonceWordB, 19U)) ^ RotL64(aNonceWordC, 51U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1755U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 4909U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 13U) ^ RotL64(aNonceWordF, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 889U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((aIndex + 1479U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 37U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 50U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererA + RotL64(aIngress, 5U)) + 7825479804710770560U;
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 53U)) + 5298124167101358123U) + aOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) + RotL64(aNonceWordF, 42U);
            aOrbiterE = (aWandererG + RotL64(aScatter, 39U)) + 17774541024369233726U;
            aOrbiterD = (aWandererB + RotL64(aCross, 44U)) + 7679371833537454082U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 29U)) + 5385914900748772224U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 23U)) + 3879781930908486531U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 659110346638873236U) + RotL64(aNonceWordD, 7U);
            aOrbiterG = (aWandererI + RotL64(aScatter, 41U)) + 10749021728538539749U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 3U)) + 3631252455767429457U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 2271978810960685021U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 20U)) + RotL64(aCarry, 41U)) + 5963558780692551176U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 974909966119198104U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9296998242911152296U;
            aOrbiterE = RotL64((aOrbiterE * 2613629915877957661U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2245318466901521959U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13391076374843288568U;
            aOrbiterF = RotL64((aOrbiterF * 18094558036982107419U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6184487746594236737U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1563385912137291418U;
            aOrbiterJ = RotL64((aOrbiterJ * 4805455299959232321U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1744840092006498629U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 2100927276837188416U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3541788262067077997U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9998911862807246338U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 12239948725635220096U) ^ RotL64(aNonceWordB, 3U);
            aOrbiterH = RotL64((aOrbiterH * 7098620484129489129U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 3307447094994950246U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 12746613971448298932U;
            aOrbiterB = RotL64((aOrbiterB * 9463975886346934681U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 11577488293733790649U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 191108997585598809U;
            aOrbiterC = RotL64((aOrbiterC * 9574978681405356871U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 18096145693841273722U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 10026281133603934071U) ^ RotL64(aNonceWordH, 43U);
            aOrbiterA = RotL64((aOrbiterA * 17261343107314203471U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2346682418062064668U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2996178204018644206U;
            aOrbiterK = RotL64((aOrbiterK * 2552965800703390909U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15085425896818988223U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1589593231782852588U;
            aOrbiterG = RotL64((aOrbiterG * 1535556765195388675U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 17170695588248383518U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7825479804710770560U;
            aOrbiterI = RotL64((aOrbiterI * 7434218282170150533U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 56U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterD, 5U));
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 53U)) + aOrbiterB) + RotL64(aNonceWordE, 35U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 40U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 11U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 3U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aPrevious, 44U) + aOrbiterG) + RotL64(aOrbiterK, 43U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 22U)) + aOrbiterH) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 29U) + RotL64(aOrbiterB, 13U)) + aOrbiterC) + RotL64(aCarry, 37U)) + RotL64(aNonceWordA, 27U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 35U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterD, 19U)) + aOrbiterC) + aWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterJ, 57U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 44U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 6U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 37U) ^ RotL64(aNonceWordH, 52U)) ^ RotL64(aNonceWordG, 21U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8830U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12185U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 35U) ^ RotL64(aNonceWordC, 26U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15215U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 9678U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 39U)) ^ (RotL64(aCarry, 6U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererH + RotL64(aScatter, 4U)) + RotL64(aCarry, 37U)) + 3238389262925516513U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 12381787182611386995U;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 47U)) + 7883885539305181549U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordA, 9U);
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 51U)) + 1185413044597727092U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 29U)) + 15219353497204773135U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 43U)) + 7533774715626734082U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 29U)) + 2599930450937763464U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 27U)) + 16074720663961214284U) + RotL64(aNonceWordD, 45U);
            aOrbiterE = (aWandererB + RotL64(aIngress, 41U)) + 15483613196360051221U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 37U)) + 9396557867081376268U;
            aOrbiterD = (aWandererC + RotL64(aCross, 6U)) + 9668459976852660245U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9037269914643207212U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16936742640861088240U;
            aOrbiterK = RotL64((aOrbiterK * 1040172193161012227U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16481274825758546398U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 481851372837611166U;
            aOrbiterJ = RotL64((aOrbiterJ * 2225030139210599207U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13608921517203544108U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16930740723286214636U;
            aOrbiterB = RotL64((aOrbiterB * 2605108503821980865U), 43U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 902242902582149908U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordG, 39U);
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1510861213079342977U;
            aOrbiterG = RotL64((aOrbiterG * 3309753895727400707U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7116243600304980310U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 6631412278359709602U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11452627691392637463U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9246698682265275165U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8594373032014031450U;
            aOrbiterA = RotL64((aOrbiterA * 2550138341089957033U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15912837963877821048U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11404583513022627609U;
            aOrbiterI = RotL64((aOrbiterI * 17715204726760125357U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17295214920690244319U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 18315664494984189344U;
            aOrbiterF = RotL64((aOrbiterF * 17398893532076312945U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2474825506593695564U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4400473621592150441U;
            aOrbiterC = RotL64((aOrbiterC * 7098832854166953839U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 15270166373215060119U) + RotL64(aNonceWordF, 7U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 4331232225067306139U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2299883590703870703U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2176207815544347316U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 3238389262925516513U) ^ aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13104597690682251231U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 18U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterI, 29U));
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 37U)) + aOrbiterB) + RotL64(aNonceWordB, 13U));
            aWandererH = aWandererH + ((((RotL64(aCross, 29U) + RotL64(aOrbiterH, 13U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterA, 53U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 18U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterF, 47U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 11U)) + aOrbiterI);
            aWandererI = aWandererI ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterD, 39U)) + aOrbiterA) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterD, 24U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 46U) + RotL64(aOrbiterC, 27U)) + aOrbiterK) + RotL64(aNonceWordE, 8U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 51U) ^ RotL64(aNonceWordC, 19U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21183U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18824U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 35U) ^ RotL64(aNonceWordA, 43U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20721U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19523U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 54U)) + (RotL64(aCross, 29U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererB + RotL64(aIngress, 39U)) + 16016931609704150191U;
            aOrbiterC = (aWandererA + RotL64(aCross, 23U)) + 14511433515861302636U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 50U)) + 11691237442613269593U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 47U)) + 16383220587320484649U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 14293015313458219868U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 39U)) + 4407695248205526670U) + RotL64(aNonceWordD, 57U);
            aOrbiterB = (aWandererK + RotL64(aIngress, 27U)) + 1158323195324398372U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 11U)) + 6577683409653864555U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 3U)) + 171080079472863843U) + aOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aIngress, 48U)) + 5766333425872228205U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aScatter, 29U)) + 16173508656917582960U) + RotL64(aNonceWordH, 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11781450063402219202U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13033139686637576694U;
            aOrbiterK = RotL64((aOrbiterK * 4331137994135472025U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 4006310759400926020U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13156817947481574467U;
            aOrbiterE = RotL64((aOrbiterE * 563189239835001483U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 12791290558893516411U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 989729955679243234U;
            aOrbiterC = RotL64((aOrbiterC * 8757228712495095017U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 838379839663022790U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2830743864262313606U;
            aOrbiterH = RotL64((aOrbiterH * 10173947177104802797U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2146646527331684652U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4629168181742174906U;
            aOrbiterD = RotL64((aOrbiterD * 9046124907945045131U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 1150129989168501777U) + RotL64(aNonceWordG, 37U);
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 619659995945229440U;
            aOrbiterG = RotL64((aOrbiterG * 13734821008174603409U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8120315647582116952U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13754584116324996165U;
            aOrbiterJ = RotL64((aOrbiterJ * 12295486140772079747U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 6084566798869999580U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 5731665119233722504U) ^ RotL64(aNonceWordA, 25U);
            aOrbiterA = RotL64((aOrbiterA * 5921510209025133639U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16134513471149338456U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9841695976256666234U;
            aOrbiterB = RotL64((aOrbiterB * 7417023101762286049U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2559042046155066240U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 14065288635273112125U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10464173719695109147U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 18228257734024217020U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16016931609704150191U;
            aOrbiterI = RotL64((aOrbiterI * 2874343578276710555U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 14U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterJ, 41U));
            aWandererI = aWandererI + ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 27U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterC, 53U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterD, 50U)) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 37U)) + aOrbiterH) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterE, 3U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 6U) + aOrbiterA) + RotL64(aOrbiterC, 43U)) + RotL64(aNonceWordE, 50U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ) + RotL64(aNonceWordC, 45U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 14U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterB, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 26U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + RotL64(aWandererD, 56U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordA, 18U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29065U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 27416U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 50U) ^ RotL64(aNonceWordC, 11U)) ^ RotL64(aNonceWordE, 29U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27369U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31157U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 36U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererA + RotL64(aIngress, 21U)) + 15910560457440369082U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aPrevious, 39U)) + 17953072986407436888U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 15446940721193538669U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 6U)) + 3020785262774422009U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 7001288645424994404U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 53U)) + 13385250665458462689U) + RotL64(aNonceWordF, 53U);
            aOrbiterK = (aWandererG + RotL64(aScatter, 13U)) + 4841895644623005949U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 13053476783239482065U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 43U)) + 641996979335975244U) + RotL64(aNonceWordB, 26U);
            aOrbiterA = ((aWandererF + RotL64(aCross, 36U)) + 16211238020928688299U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aPrevious, 57U)) + 12715448751323279480U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17784406727699995290U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16626339815786580778U;
            aOrbiterE = RotL64((aOrbiterE * 13940754474750138041U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 9035070625716345139U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6085848172494001945U;
            aOrbiterI = RotL64((aOrbiterI * 10405728912339646693U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1177103851507561053U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2281901691017816407U;
            aOrbiterH = RotL64((aOrbiterH * 3142197009403602497U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9040984343694325070U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13334258224023902365U;
            aOrbiterK = RotL64((aOrbiterK * 4782523727707164869U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 1079824790138592518U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14024082692012948652U;
            aOrbiterC = RotL64((aOrbiterC * 3219489374333737903U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2966776524421278970U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 5510281854029308547U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9275402927591867297U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 7126632329316720048U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1476827035602733472U;
            aOrbiterA = RotL64((aOrbiterA * 2217671289726794033U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6470212302133184965U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 4172257438373147415U) ^ RotL64(aNonceWordG, 21U);
            aOrbiterB = RotL64((aOrbiterB * 4449314239630366533U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11445212164224402184U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1779825157413363285U;
            aOrbiterG = RotL64((aOrbiterG * 15393425495668107155U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7561888690947559866U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14440989817038856852U;
            aOrbiterD = RotL64((aOrbiterD * 5799807036762859679U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10618807050937260814U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterB) ^ 15910560457440369082U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) ^ RotL64(aNonceWordC, 29U);
            aOrbiterJ = RotL64((aOrbiterJ * 10902491688248464465U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (RotL64(aOrbiterF, 40U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 40U) + aOrbiterG) + RotL64(aOrbiterD, 47U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterF, 34U)) + RotL64(aNonceWordD, 47U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 19U)) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + RotL64(aOrbiterH, 29U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterG, 21U));
            aWandererH = aWandererH + (((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 53U)) + aOrbiterA) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 51U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aCross, 11U) + RotL64(aOrbiterF, 43U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 24U) + aOrbiterA) + RotL64(aOrbiterB, 6U));
            aWandererI = aWandererI + (((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 3U)) + aOrbiterC) + RotL64(aNonceWordH, 19U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterC, 23U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 54U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 28U);
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

void TwistExpander_VolleyBall_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFAB6EAD6B3A7B967ULL + 0xD2AEF174DD0CA172ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8C72C55AA5D00E71ULL + 0x8B78BFCB1E6BCCC9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA303A5BC2B883D35ULL + 0xF1318B538098E6D7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE16977063E2257C9ULL + 0x9E57A3CB01E29A21ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA8C10D30FCBC06DBULL + 0x9951F51DCB47FD37ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD8C24618632FCF7BULL + 0x89BA79B6A145BB3AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBE9BC7C27E9A3837ULL + 0xD048550D21A59CA8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF48B52991762F9CBULL + 0xD14A0559BB72DD04ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 13U) ^ RotL64(aNonceWordG, 27U)) ^ RotL64(aNonceWordA, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 817U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneC[((aIndex + 3298U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 27U) ^ RotL64(aNonceWordB, 11U)) ^ RotL64(aNonceWordH, 19U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4302U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 2736U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 27U)) + (RotL64(aPrevious, 14U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererH + RotL64(aPrevious, 39U)) + 13854738573712660276U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 43U)) + 16835460633412286294U;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 47U)) + 6785859293758091931U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordB, 21U);
            aOrbiterE = (((aWandererF + RotL64(aCross, 34U)) + RotL64(aCarry, 21U)) + 126317283127992659U) + aOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 7568963536291415413U;
            aOrbiterG = (aWandererA + RotL64(aCross, 23U)) + 12294016745653004819U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 18269588932920281147U) + RotL64(aNonceWordA, 40U);
            aOrbiterB = (aWandererB + RotL64(aIngress, 10U)) + 5872406424994751026U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 5U)) + 7764434758831474129U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 4804168969415573371U) + aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 959601763507651280U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) ^ RotL64(aNonceWordD, 27U);
            aOrbiterI = RotL64((aOrbiterI * 4647396592804833217U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9257644462479293048U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14332699366894494579U;
            aOrbiterG = RotL64((aOrbiterG * 8829304078930625541U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 10487012596470786004U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 612729229562321440U;
            aOrbiterB = RotL64((aOrbiterB * 11380387280507726003U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7845523921295625315U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12742115479740024747U;
            aOrbiterF = RotL64((aOrbiterF * 15578543510683986421U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10294667720904610944U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 14369711143154904567U) ^ RotL64(aNonceWordH, 13U);
            aOrbiterA = RotL64((aOrbiterA * 13753005602288309379U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10918344717497681894U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 18136794828308636957U;
            aOrbiterE = RotL64((aOrbiterE * 17899418637978002409U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14378638206724886404U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7077588188450008059U;
            aOrbiterC = RotL64((aOrbiterC * 485375960462924335U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8941870012851971932U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 15242087859620352399U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4963002810455992839U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 10395280254030875387U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6826595516076975980U;
            aOrbiterJ = RotL64((aOrbiterJ * 6198886240333178001U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (RotL64(aOrbiterG, 58U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterH, 56U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 39U)) + aOrbiterA);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 19U)) + RotL64(aNonceWordE, 3U));
            aWandererH = aWandererH + ((RotL64(aIngress, 28U) + aOrbiterB) + RotL64(aOrbiterG, 23U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 13U)) + aOrbiterG) + RotL64(aNonceWordC, 19U)) + aWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 5U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 60U));
            aWandererK = aWandererK + (((RotL64(aScatter, 20U) + RotL64(aOrbiterH, 51U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 44U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordD, 42U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7261U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9244U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 43U) ^ RotL64(aNonceWordF, 29U)) ^ RotL64(aNonceWordE, 53U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10103U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10582U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 10U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 29U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererG + RotL64(aScatter, 39U)) + 4384716820085860551U) + RotL64(aNonceWordG, 20U);
            aOrbiterK = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 9715780315942116888U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 43U)) + 15963520052789178632U) + aOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 26U)) + RotL64(aCarry, 57U)) + 14346700690686392938U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 6005518012489966643U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 19U)) + 2506732930310252119U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 3U)) + 16782163084851775826U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 13U)) + 823673076571076303U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordB, 45U);
            aOrbiterA = (aWandererC + RotL64(aIngress, 50U)) + 1634084509064077736U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1288134975466877686U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 2998220403162908444U) ^ aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4321412662318298283U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 220430672180734911U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 10223923547068528867U) ^ RotL64(aNonceWordC, 53U);
            aOrbiterG = RotL64((aOrbiterG * 12577370238343872139U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11696469696177647608U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6545430420379636963U;
            aOrbiterJ = RotL64((aOrbiterJ * 8387163146257553773U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 79691451831797107U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8971444023498649419U;
            aOrbiterF = RotL64((aOrbiterF * 7148919880477390009U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5624403902454498793U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9468064161002030997U;
            aOrbiterA = RotL64((aOrbiterA * 8243560528100864595U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4619361544913629805U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12682446273369750704U;
            aOrbiterI = RotL64((aOrbiterI * 10879074713156075641U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 8728730962617599223U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 9099675924074253030U) ^ RotL64(aNonceWordA, 51U);
            aOrbiterB = RotL64((aOrbiterB * 5525644236954497523U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3298303921318288541U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 5953276499411658358U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10565471305001292693U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6725769507592688539U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1057277456510215817U;
            aOrbiterK = RotL64((aOrbiterK * 8269412198279297075U), 39U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (RotL64(aOrbiterI, 36U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 47U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterF, 30U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterK, 19U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 3U)) + aOrbiterK) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 35U)) + RotL64(aNonceWordH, 17U));
            aWandererA = aWandererA + ((((RotL64(aCross, 19U) + RotL64(aOrbiterI, 13U)) + aOrbiterG) + RotL64(aCarry, 5U)) + RotL64(aNonceWordD, 25U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterF, 51U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 46U) + RotL64(aOrbiterI, 57U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 42U)) + aOrbiterA) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 54U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 47U) ^ RotL64(aNonceWordG, 36U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13321U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 11262U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 21U) ^ RotL64(aNonceWordA, 43U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12535U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneC[((aIndex + 14555U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCross, 23U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 8604208734152026945U;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 56U)) + RotL64(aCarry, 11U)) + 1374329953253889829U) + RotL64(aNonceWordH, 37U);
            aOrbiterD = (aWandererK + RotL64(aCross, 11U)) + 5779278910548228339U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 37U)) + 17670451230882805140U) + aOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aCross, 29U)) + 8193848740764866860U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 23U)) + 15801168428145650104U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 42U)) + RotL64(aCarry, 21U)) + 2584718176087499066U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 3U)) + 14950366247822737997U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 19U)) + 9779293225265670135U) + RotL64(aNonceWordB, 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 8688968319288372383U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 13665723186950342601U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 292035540396910837U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9395428688359973510U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 2152719218018108418U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15271961483518392671U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1350324137411377992U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8729317951386057921U;
            aOrbiterJ = RotL64((aOrbiterJ * 6008790836417785083U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6317310451893678411U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 10175620379041384281U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14079679617394330781U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1203082119358827708U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 523869107818193101U;
            aOrbiterH = RotL64((aOrbiterH * 4629501113595689157U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4028324959540432983U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15447631947468213912U;
            aOrbiterI = RotL64((aOrbiterI * 6037306615787729185U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14225888694733041031U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 11925000696281947629U) ^ RotL64(aNonceWordG, 20U);
            aOrbiterG = RotL64((aOrbiterG * 4337022940520411253U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 15015531024930608745U) + RotL64(aNonceWordC, 55U);
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16752579225076943550U;
            aOrbiterK = RotL64((aOrbiterK * 15551083683579981439U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2432733494869267901U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10103430321388601485U;
            aOrbiterA = RotL64((aOrbiterA * 18372919379972432569U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 48U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 20U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 53U)) + aOrbiterK) + RotL64(aNonceWordF, 29U)) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 10U) + aOrbiterD) + RotL64(aOrbiterA, 48U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterE, 57U));
            aWandererK = aWandererK + (((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 27U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 18U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 60U) + aOrbiterG) + RotL64(aOrbiterD, 11U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 39U)) + aOrbiterI) + RotL64(aCarry, 11U)) + RotL64(aNonceWordA, 41U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterK, 5U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 43U) ^ RotL64(aNonceWordH, 57U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19959U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 17417U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 18U) ^ RotL64(aNonceWordE, 53U)) ^ RotL64(aNonceWordG, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20849U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((aIndex + 17270U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 60U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 3238389262925516513U) + RotL64(aNonceWordB, 40U);
            aOrbiterG = (aWandererE + RotL64(aCross, 12U)) + 12381787182611386995U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 3U)) + 7883885539305181549U) + RotL64(aNonceWordF, 35U);
            aOrbiterJ = (aWandererC + RotL64(aScatter, 53U)) + 1185413044597727092U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 15219353497204773135U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 7533774715626734082U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 41U)) + 2599930450937763464U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 19U)) + 16074720663961214284U) + aOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aIngress, 58U)) + 15483613196360051221U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9396557867081376268U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9668459976852660245U;
            aOrbiterK = RotL64((aOrbiterK * 11748505665890567063U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 9037269914643207212U) + RotL64(aNonceWordD, 5U);
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16936742640861088240U;
            aOrbiterH = RotL64((aOrbiterH * 1040172193161012227U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 16481274825758546398U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 481851372837611166U;
            aOrbiterD = RotL64((aOrbiterD * 2225030139210599207U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13608921517203544108U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16930740723286214636U;
            aOrbiterC = RotL64((aOrbiterC * 2605108503821980865U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 902242902582149908U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 1510861213079342977U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3309753895727400707U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 7116243600304980310U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6631412278359709602U;
            aOrbiterF = RotL64((aOrbiterF * 11452627691392637463U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9246698682265275165U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8594373032014031450U;
            aOrbiterE = RotL64((aOrbiterE * 2550138341089957033U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 15912837963877821048U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 11404583513022627609U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17715204726760125357U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 17295214920690244319U) + RotL64(aNonceWordA, 39U);
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 18315664494984189344U;
            aOrbiterG = RotL64((aOrbiterG * 17398893532076312945U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 22U);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((((RotL64(aCross, 12U) + aOrbiterG) + RotL64(aOrbiterJ, 18U)) + RotL64(aCarry, 29U)) + RotL64(aNonceWordE, 53U)) + aWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterE, 11U));
            aWandererF = aWandererF + (((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterD, 27U)) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 57U)) + aOrbiterC) + RotL64(aNonceWordC, 61U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterC, 48U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 52U) + RotL64(aOrbiterH, 5U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 37U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 26U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 35U) ^ RotL64(aNonceWordD, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26269U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24810U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordH, 39U)) ^ RotL64(aNonceWordF, 22U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24615U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 23027U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 22U)) ^ (RotL64(aCross, 51U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 11U)) + 12583180859826261500U) + RotL64(aNonceWordD, 9U);
            aOrbiterE = (aWandererG + RotL64(aIngress, 51U)) + 9067093488553721468U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 37U)) + 12173106198862881754U;
            aOrbiterD = (aWandererE + RotL64(aCross, 60U)) + 11333491014394592654U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 51U)) + 3511883526940919554U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 7416810692106273044U;
            aOrbiterB = (((aWandererI + RotL64(aIngress, 47U)) + 8341174972619784110U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordB, 57U);
            aOrbiterF = ((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 13U)) + 2220852854836962979U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 18U)) + 8090781422229383825U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2338801236599102223U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12484514711848308104U;
            aOrbiterJ = RotL64((aOrbiterJ * 10364216764253366067U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 13684861340589131816U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 12796636819991873058U) ^ RotL64(aNonceWordA, 38U);
            aOrbiterG = RotL64((aOrbiterG * 5533508014234835669U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7634198650894837690U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10240326122201201762U;
            aOrbiterF = RotL64((aOrbiterF * 8758703497719125901U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4162814763739453934U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2766504649149048469U;
            aOrbiterH = RotL64((aOrbiterH * 16731843453895178671U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 11051393030148769655U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17687055068651386665U;
            aOrbiterK = RotL64((aOrbiterK * 1042927176246229537U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 3353615315436983420U) + aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 5971640796220306310U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1]) ^ RotL64(aNonceWordE, 23U);
            aOrbiterD = RotL64((aOrbiterD * 15804313508835034807U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12299773092762384765U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7435804907797063411U;
            aOrbiterB = RotL64((aOrbiterB * 9848139805288165965U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8735783937125735699U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11903126115475835615U;
            aOrbiterE = RotL64((aOrbiterE * 16942088822124940265U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4427166023462475475U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6011733469446008137U;
            aOrbiterC = RotL64((aOrbiterC * 17298067225913923517U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 27U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 56U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterD, 47U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterD, 26U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 35U)) + aOrbiterF) + RotL64(aNonceWordC, 59U)) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 11U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 56U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aCross, 54U) + aOrbiterK) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG) + aWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterB, 39U)) + RotL64(aNonceWordH, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 22U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordB, 39U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31966U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31938U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 46U) ^ RotL64(aNonceWordG, 29U)) ^ RotL64(aNonceWordD, 21U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29472U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 29416U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 39U)) + (RotL64(aCross, 57U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 23U)) + 13350544654542863236U) + RotL64(aNonceWordE, 17U);
            aOrbiterD = ((aWandererK + RotL64(aIngress, 29U)) + 12364346790125404372U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 3U)) + 9738750172849512764U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 56U)) + RotL64(aCarry, 27U)) + 3781373837635491421U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 47U)) + 16635020317512702337U;
            aOrbiterG = (aWandererI + RotL64(aCross, 13U)) + 5383653921676231276U;
            aOrbiterF = ((((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 10181959815492056493U) + aOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1]) + RotL64(aNonceWordC, 45U);
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 60U)) + RotL64(aCarry, 43U)) + 10005510924273927017U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 39U)) + 9524687662265740565U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4259138552009771014U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8973051213213726023U;
            aOrbiterJ = RotL64((aOrbiterJ * 12625091476068190979U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 17602611840127337490U) + RotL64(aNonceWordD, 12U);
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8218984546932905269U;
            aOrbiterE = RotL64((aOrbiterE * 17504305273683304231U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 18102186122213487888U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2629927500298092976U;
            aOrbiterF = RotL64((aOrbiterF * 6983280164448292723U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 2491581597835795234U) + RotL64(aNonceWordH, 51U);
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9506602492971620955U;
            aOrbiterH = RotL64((aOrbiterH * 9559829640915637163U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 13422942713680612924U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 15037354693234876601U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12692376075738621447U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12896066842192894694U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2202952306291905855U;
            aOrbiterC = RotL64((aOrbiterC * 6779368532763429997U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 12160313482450599313U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 10812986281270407756U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7786608700746771809U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12474638293190144525U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5882870951276225224U;
            aOrbiterG = RotL64((aOrbiterG * 15532427302173572457U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3782896138051179209U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10965680631059882311U;
            aOrbiterD = RotL64((aOrbiterD * 14060923998307082385U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 40U);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 58U) + RotL64(aOrbiterF, 19U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterA, 14U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 47U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 57U)) + aOrbiterG) + RotL64(aNonceWordB, 23U));
            aWandererI = aWandererI + (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterF, 29U)) + RotL64(aNonceWordG, 3U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 24U) + aOrbiterJ) + RotL64(aOrbiterE, 23U));
            aWandererB = aWandererB + ((((RotL64(aCross, 43U) + RotL64(aOrbiterE, 43U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterC, 3U)) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterE, 38U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_VolleyBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF0ADD8FDA4A53DB9ULL + 0xC51B1367F3C53D54ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFB9C57B78C16CC81ULL + 0xB2E044DF1E3C436FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC98E2ADE3822C879ULL + 0xA0D1853865E7BD0EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCD8477BABC19FB59ULL + 0xBDC020A2C42BA520ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xBA207E7B2B1589BFULL + 0x831ED5049D4F6486ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA1D099CFDD6F588FULL + 0x83DB42D409D671CAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC370D4166379DCB9ULL + 0xE8661F80A9CACBDBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB6BF35D51E9EC599ULL + 0x85F6C070D0C8AEF8ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 47U) ^ RotL64(aNonceWordB, 11U)) ^ RotL64(aNonceWordF, 38U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1255U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 3127U)) & W_KEY1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordE, 53U)) ^ RotL64(aNonceWordA, 13U));
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 1076U)) & W_KEY1], 26U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3403U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 19U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCross, 36U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = ((aWandererK + RotL64(aIngress, 44U)) + RotL64(aCarry, 57U)) + 12809562813316740345U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 19U)) + 17084212535326321199U) + RotL64(aNonceWordB, 53U);
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 11U)) + 16074921689983846769U) + RotL64(aNonceWordG, 61U);
            aOrbiterF = ((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 14027986153007120145U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 35U)) + 7633455951809250227U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 29U)) + 340989348513370174U) + aPhaseAOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 19U)) + 5307820377645020116U) + aPhaseAOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 5605285015771527274U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5293500434746182790U;
            aOrbiterJ = RotL64((aOrbiterJ * 17674669610895537063U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 7263156475892261811U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10672879570907433005U;
            aOrbiterK = RotL64((aOrbiterK * 2506338667179450741U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 16659226780900986107U) + RotL64(aNonceWordD, 10U);
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9774892622769850665U;
            aOrbiterD = RotL64((aOrbiterD * 7487477727543183211U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10728057184108279042U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5032485856947407217U;
            aOrbiterB = RotL64((aOrbiterB * 16651577903809154285U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14642241075374862345U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 8386481273395203518U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11649977733867003445U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2874153265304098104U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 11519900149177261000U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) ^ RotL64(aNonceWordE, 43U);
            aOrbiterF = RotL64((aOrbiterF * 2010158758971864505U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 8885690878540115768U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4482143389870987714U;
            aOrbiterA = RotL64((aOrbiterA * 7105332459437434281U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 39U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 43U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 20U) + RotL64(aOrbiterF, 18U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterK, 29U));
            aWandererD = aWandererD + (((((RotL64(aCross, 43U) + RotL64(aOrbiterI, 11U)) + aOrbiterK) + RotL64(aCarry, 3U)) + RotL64(aNonceWordA, 41U)) + aPhaseAWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 57U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 5U)) + RotL64(aNonceWordC, 27U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 36U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 27U) ^ RotL64(aNonceWordD, 39U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5702U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((aIndex + 5907U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 21U) ^ RotL64(aNonceWordB, 5U)) ^ RotL64(aNonceWordF, 46U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 9991U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 10751U)) & W_KEY1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCarry, 12U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = (((aWandererI + RotL64(aScatter, 47U)) + 12426357877879529292U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordA, 25U);
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 12604900366173639176U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 35U)) + 13511119007338929401U) + RotL64(aNonceWordE, 47U);
            aOrbiterF = (aWandererC + RotL64(aIngress, 60U)) + 9878720081166788060U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 15463195409806395076U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 27U)) + 6407922778852833423U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 5U)) + 7690427254160734016U) + aPhaseAOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 18030974031722143619U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 17983938038322737041U) ^ RotL64(aNonceWordG, 13U);
            aOrbiterG = RotL64((aOrbiterG * 12479365337221685413U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 16605512170117753884U) + RotL64(aNonceWordB, 53U);
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 681802273302348322U;
            aOrbiterE = RotL64((aOrbiterE * 14608920184802647123U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 15550312921312083819U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17824154101711884508U;
            aOrbiterF = RotL64((aOrbiterF * 7358612830654795357U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1939207786756735430U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3132864634777826569U;
            aOrbiterD = RotL64((aOrbiterD * 13606281919426730325U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 12822929773923954849U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16576106045887115660U;
            aOrbiterJ = RotL64((aOrbiterJ * 16370914370769903051U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 2398825881649235260U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 13700821892926092479U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10830623703416956043U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2439833784883391606U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15870638514107637833U;
            aOrbiterC = RotL64((aOrbiterC * 3797380922767479287U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 46U) + RotL64(aOrbiterE, 5U)) + aOrbiterF) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterC, 53U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 27U)) + aOrbiterC) + RotL64(aNonceWordC, 30U));
            aWandererE = aWandererE + (((((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 19U)) + RotL64(aNonceWordH, 43U)) + aPhaseAWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterC, 19U));
            aWandererC = aWandererC + (((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 13U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordF, 57U)) ^ RotL64(aNonceWordD, 38U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13039U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 11148U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 35U) ^ RotL64(aNonceWordC, 26U)) ^ RotL64(aNonceWordH, 3U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 11887U)) & W_KEY1], 11U) ^ RotL64(aKeyRowReadB[((aIndex + 11156U)) & W_KEY1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 9630214189402543339U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 4072576573737526819U) + RotL64(aNonceWordC, 39U);
            aOrbiterB = ((aWandererF + RotL64(aCross, 21U)) + 15994787452709618869U) + RotL64(aNonceWordH, 46U);
            aOrbiterK = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 6403240137132259482U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 4U)) + 10229266900170507720U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 43U)) + 5025294577989748989U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aCross, 57U)) + 16696461238217956883U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 9878318855341719119U) + RotL64(aNonceWordB, 19U);
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16086635438116177346U;
            aOrbiterB = RotL64((aOrbiterB * 5585682357395705671U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12295437783084203730U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7681150419912842402U;
            aOrbiterC = RotL64((aOrbiterC * 7289497379725191451U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 2639104034287637448U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12298170009332243573U;
            aOrbiterJ = RotL64((aOrbiterJ * 9397919591171238575U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3485932317267669626U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16569551670038752475U;
            aOrbiterK = RotL64((aOrbiterK * 8139802826402217631U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 4448490103784103954U) + RotL64(aNonceWordE, 17U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 14510534073046885941U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7777192047386438305U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4286195398675733451U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15790355933840266463U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13342257823027075501U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6362891510370156055U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 15121822034579983174U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7268045994574844937U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterC, 44U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 29U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 58U) + aOrbiterF) + RotL64(aOrbiterI, 10U)) + RotL64(aNonceWordF, 25U)) + aPhaseAWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 57U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 47U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 39U)) + aOrbiterI);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterF, 3U)) + aPhaseAWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 23U)) + aOrbiterC) + RotL64(aCarry, 53U)) + RotL64(aNonceWordG, 53U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 29U) ^ RotL64(aNonceWordE, 3U)) ^ RotL64(aNonceWordC, 46U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18356U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 21319U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordB, 24U)) ^ RotL64(aNonceWordH, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17074U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 18669U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 29U)) + (RotL64(aIngress, 43U) + RotL64(aCarry, 12U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = (((aWandererG + RotL64(aCross, 3U)) + 5131645209694953015U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + RotL64(aNonceWordF, 51U);
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 12070391048835379854U) + aPhaseAOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aPrevious, 29U)) + 2604295836242338724U;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 14042039029284001596U) + RotL64(aNonceWordE, 45U);
            aOrbiterB = (aWandererB + RotL64(aIngress, 35U)) + 8914654543854559327U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 51U)) + 2185619407969359869U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 14U)) + RotL64(aCarry, 27U)) + 5187406295103352574U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8022832481290871217U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8783061916740573472U;
            aOrbiterC = RotL64((aOrbiterC * 3309891377744201773U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10711028365596196301U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 13387065038269133571U) ^ RotL64(aNonceWordD, 57U);
            aOrbiterA = RotL64((aOrbiterA * 12444578026365205255U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11187001318931801582U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14191473173276034019U;
            aOrbiterE = RotL64((aOrbiterE * 2491253922434756431U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 16207761776716426435U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9677408414452078760U;
            aOrbiterB = RotL64((aOrbiterB * 5487303383095129949U), 29U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterI) + 17812460332794370649U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1]) + RotL64(aNonceWordG, 25U);
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7736423148554132028U;
            aOrbiterG = RotL64((aOrbiterG * 15588733747232852555U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17293203944059014763U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13487243633338010243U;
            aOrbiterJ = RotL64((aOrbiterJ * 9468688858740539095U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 15979293016815060755U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 17645215484691359547U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1449450767288733995U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 51U)) + aOrbiterG) + RotL64(aNonceWordH, 47U));
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterI, 58U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 13U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aCross, 4U) + RotL64(aOrbiterB, 43U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aPhaseAWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterA, 35U));
            aWandererF = aWandererF + ((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 23U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterA, 29U)) + RotL64(aNonceWordA, 60U)) + aPhaseAWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 12U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 37U) ^ RotL64(aNonceWordB, 6U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26570U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 24738U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 53U) ^ RotL64(aNonceWordE, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23143U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23390U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 35U)) + (RotL64(aPrevious, 50U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = (((aWandererC + RotL64(aCross, 27U)) + 15383045568644941552U) + aPhaseAOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1]) + RotL64(aNonceWordF, 19U);
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 51U)) + 17452811657750910067U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 15660117718455155603U;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 20U)) + RotL64(aCarry, 35U)) + 10396441207743665753U) + RotL64(aNonceWordH, 42U);
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 3708971058200841442U;
            aOrbiterD = (aWandererB + RotL64(aCross, 11U)) + 7000673057768598750U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 57U)) + 9886354469011131596U;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 16018065329058043467U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + RotL64(aNonceWordB, 17U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5024756166109352320U;
            aOrbiterJ = RotL64((aOrbiterJ * 11660932185479046483U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6587818720728886652U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3652672354944162319U;
            aOrbiterK = RotL64((aOrbiterK * 10807121230791716109U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 6307315649915348048U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 16405347331742979258U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7183142442906743699U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5427299664054601957U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 4983381733483185898U;
            aOrbiterG = RotL64((aOrbiterG * 14646556236306407673U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10182995521328377487U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8694282877540593550U;
            aOrbiterA = RotL64((aOrbiterA * 14614602561910403893U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4085927978153269932U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterH) ^ 6176195962815240877U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1]) ^ RotL64(aNonceWordG, 25U);
            aOrbiterD = RotL64((aOrbiterD * 16792916528959579875U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6966742100601433005U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9920952446921247521U;
            aOrbiterH = RotL64((aOrbiterH * 1879821050131820933U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 35U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 48U) + RotL64(aOrbiterJ, 51U)) + aOrbiterH) + RotL64(aCarry, 53U)) + RotL64(aNonceWordD, 35U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 58U)) + aOrbiterG) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 5U)) + aPhaseAWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 19U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 27U)) + aOrbiterH) + RotL64(aNonceWordA, 53U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterK, 41U));
            aWandererH = aWandererH + ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 5U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 38U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 14U) ^ RotL64(aNonceWordF, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27371U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 32561U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 23U) ^ RotL64(aNonceWordE, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32047U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((aIndex + 28609U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 3U)) + (RotL64(aIngress, 24U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 19U)) + 1042610313571524121U) + aPhaseAOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordB, 39U);
            aOrbiterE = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 3505725321008825582U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 11U)) + 12584654563843782991U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 37U)) + 6645399144515770935U) + RotL64(aNonceWordH, 53U);
            aOrbiterB = ((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 3608978423753715584U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 53U)) + 8089198857670370983U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 46U)) + RotL64(aCarry, 23U)) + 15207251813516399879U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 9579268660105824516U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16055044469473802812U;
            aOrbiterK = RotL64((aOrbiterK * 2269649280637188723U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 583811872609805949U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 7027491967970873942U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) ^ RotL64(aNonceWordC, 15U);
            aOrbiterB = RotL64((aOrbiterB * 12686754713465826139U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 18256061823189677508U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12708429127816136937U;
            aOrbiterF = RotL64((aOrbiterF * 12593886633108075321U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 12169216645156306078U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 12694325407567795065U) ^ RotL64(aNonceWordD, 48U);
            aOrbiterH = RotL64((aOrbiterH * 3711789483877261899U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16109994660203297503U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4234704064165718913U;
            aOrbiterJ = RotL64((aOrbiterJ * 730085881474787681U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14119541943554602878U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8777769004811352951U;
            aOrbiterG = RotL64((aOrbiterG * 2556957257736134223U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15642663488392549609U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11594468530833278624U;
            aOrbiterE = RotL64((aOrbiterE * 6639306656361601143U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 29U)) + aOrbiterG) + RotL64(aCarry, 21U)) + RotL64(aNonceWordE, 5U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterJ, 60U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 51U)) + RotL64(aNonceWordA, 31U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 43U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterK, 3U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterE, 37U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_VolleyBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC32886461594D599ULL + 0xCD49740A052AF1B5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xAE0F13E006B29469ULL + 0xBCF6AD6264002D14ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA624FD7BFC68200BULL + 0xAD200DB0F84DE49EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF91E886703BAD071ULL + 0x8ADDFDB21376A015ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE19091C1BB4E295FULL + 0xC1720F9B3C0E6191ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCADBF330257A6B97ULL + 0xBAE6FC8D9B08FE66ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9DDD6241E1662619ULL + 0xD3BECCAB521FFD2AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB68B22BA3EB30DCDULL + 0xF440456403ADCDF1ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 58U) ^ RotL64(aNonceWordE, 19U)) ^ RotL64(aNonceWordH, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1950U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5097U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 19U) ^ RotL64(aNonceWordA, 46U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 211U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4271U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 13U)) + (RotL64(aIngress, 27U) ^ RotL64(aCross, 42U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = ((aWandererF + RotL64(aIngress, 56U)) + RotL64(aCarry, 21U)) + 6771552164800695068U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 19U)) + 12131763371571322040U) + aPhaseBOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 35U)) + 3326182381395522013U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 12288775097697156383U) + RotL64(aNonceWordH, 28U);
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 27U)) + 5195948373449796741U) + RotL64(aNonceWordC, 13U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 14404044002250137144U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordG, 25U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 11142382920035825426U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8134413822789107595U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2967149520256475485U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 1470907369577818097U) ^ RotL64(aNonceWordA, 43U);
            aOrbiterA = RotL64((aOrbiterA * 9398653295177725883U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9231668148004163910U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13078929163913892386U;
            aOrbiterG = RotL64((aOrbiterG * 7509829068700523627U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9485274692075657877U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12216951187543631673U;
            aOrbiterD = RotL64((aOrbiterD * 6571066246507310805U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6933334652581744234U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 17260276102423580920U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7796879893790990605U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 52U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 46U) + RotL64(aOrbiterD, 19U)) + aOrbiterE) + RotL64(aNonceWordD, 7U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 38U)) + aOrbiterE) + RotL64(aNonceWordE, 53U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 47U)) + aOrbiterE) + aPhaseBWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 48U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 35U) ^ RotL64(aNonceWordF, 22U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10417U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5561U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordH, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6703U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9843U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 13U)) + (RotL64(aIngress, 26U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = (aWandererK + RotL64(aIngress, 41U)) + 18180797995100240808U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 6585906608223552885U) + RotL64(aNonceWordC, 59U);
            aOrbiterB = ((((aWandererA + RotL64(aPrevious, 22U)) + RotL64(aCarry, 11U)) + 14088708930575939855U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordG, 35U);
            aOrbiterG = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 468974153311516044U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 51U)) + 12481951025619894110U) + aPhaseBOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 17227987923860711763U) + RotL64(aNonceWordD, 13U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 4373962756657477139U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6069068316234356267U), 51U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 2077576476565420951U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1]) + RotL64(aNonceWordH, 27U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 17435011300234663764U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8910133867294004711U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 4118039398293246896U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13724716599855216683U;
            aOrbiterC = RotL64((aOrbiterC * 17556333902751079677U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12391461204689596339U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9900605191533799627U;
            aOrbiterJ = RotL64((aOrbiterJ * 13553565332531046301U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 972946858824366125U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17247681919694541215U;
            aOrbiterG = RotL64((aOrbiterG * 2974639094630445643U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 26U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 24U) + RotL64(aOrbiterG, 43U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterD, 11U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordF, 55U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 20U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterC, 3U)) + RotL64(aNonceWordA, 40U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 38U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordH, 57U)) ^ RotL64(aNonceWordG, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12790U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11855U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 53U) ^ RotL64(aNonceWordD, 36U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13734U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13006U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 27U)) + (RotL64(aIngress, 56U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (aWandererK + RotL64(aCross, 13U)) + 13499155707765393469U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 4U)) + 3740324981823726185U) + RotL64(aNonceWordH, 5U);
            aOrbiterH = (((aWandererH + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 5470765363949735652U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 27U)) + 3446436171274452326U;
            aOrbiterJ = ((((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 1778929412631211933U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + RotL64(aNonceWordG, 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14666308799855220954U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 4548410236791175055U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6822908616815218501U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5829739767694190372U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 14319231414903675748U) ^ RotL64(aNonceWordC, 49U);
            aOrbiterG = RotL64((aOrbiterG * 4966501102515775601U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1513851750246111405U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 1685620217748986019U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9286548037413609445U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 16284162182006054402U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6271539598462003309U;
            aOrbiterE = RotL64((aOrbiterE * 13923286694131331137U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 12669312437565969473U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 11894755313393001665U) ^ RotL64(aNonceWordE, 39U);
            aOrbiterJ = RotL64((aOrbiterJ * 12556759675372354075U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 26U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 13U)) + aOrbiterG) + RotL64(aCarry, 51U)) + RotL64(aNonceWordF, 61U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 42U) + RotL64(aOrbiterG, 60U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterH, 5U)) + RotL64(aNonceWordA, 34U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 23U)) + aOrbiterE) + aPhaseBWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 47U) ^ RotL64(aNonceWordA, 23U)) ^ RotL64(aNonceWordC, 35U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 19386U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21224U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 27U) ^ RotL64(aNonceWordB, 12U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17071U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 19949U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 10U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 38U)) + RotL64(aCarry, 11U)) + 8866844335448071821U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 23U)) + 15159698739856430085U) + RotL64(aNonceWordC, 60U);
            aOrbiterC = (((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 9582805772989594633U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aCross, 57U)) + 1438538239931588373U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 23U)) + 10862044156620436139U) + RotL64(aNonceWordG, 51U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 13682173320058164615U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordH, 15U);
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8351013291045977592U;
            aOrbiterC = RotL64((aOrbiterC * 5722336275651615473U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 15777857431516633916U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 16178966745333885377U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7545129923202147703U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9031889187993001617U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6308472367425865347U;
            aOrbiterH = RotL64((aOrbiterH * 17118710301967158153U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 642109145903321046U) + RotL64(aNonceWordE, 41U);
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9186268569255318035U;
            aOrbiterK = RotL64((aOrbiterK * 10714674348507516749U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6091345356803675860U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13218507921880873749U;
            aOrbiterD = RotL64((aOrbiterD * 15415157927185637717U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 30U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterI, 13U));
            aWandererB = aWandererB + (((((RotL64(aIngress, 50U) + aOrbiterD) + RotL64(aOrbiterI, 46U)) + RotL64(aCarry, 19U)) + RotL64(aNonceWordF, 53U)) + aPhaseBWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterI, 57U));
            aWandererC = aWandererC + (((((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordD, 13U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterH, 5U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 10U) ^ RotL64(aNonceWordE, 21U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 26948U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 24735U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 23U) ^ RotL64(aNonceWordC, 53U)) ^ RotL64(aNonceWordF, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22150U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25176U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 26U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 11U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = (aWandererG + RotL64(aCross, 29U)) + 7893287783892523139U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 13U)) + 10257331997383491153U;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 11U)) + 14562226733652231753U) + aPhaseBOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1]) + RotL64(aNonceWordA, 27U);
            aOrbiterH = (((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 14320342577110737851U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (((aWandererE + RotL64(aIngress, 38U)) + RotL64(aCarry, 39U)) + 9816717579822880756U) + RotL64(aNonceWordB, 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9558926960095881953U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9230371862654338324U;
            aOrbiterB = RotL64((aOrbiterB * 8842712825810461561U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6414274291252913420U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13868546184398350849U;
            aOrbiterF = RotL64((aOrbiterF * 1547986864837497409U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16940736952569949038U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2866957764814864371U;
            aOrbiterE = RotL64((aOrbiterE * 3554702178644797003U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 7916721976073979724U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 1602444214978842275U) ^ RotL64(aNonceWordG, 23U);
            aOrbiterI = RotL64((aOrbiterI * 11072503711308122385U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9529061385251008037U) + RotL64(aNonceWordD, 35U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 8402775110887376588U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13980225144628227381U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 30U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 28U) + RotL64(aOrbiterF, 57U)) + aOrbiterB) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterE, 37U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 5U)) + RotL64(aNonceWordE, 9U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 41U) + RotL64(aOrbiterF, 10U)) + aOrbiterH) + RotL64(aNonceWordH, 60U)) + aPhaseBWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 21U)) + aOrbiterH) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 24U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 53U) ^ RotL64(aNonceWordF, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29789U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneB[((aIndex + 29989U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 5U) ^ RotL64(aNonceWordB, 34U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30577U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27536U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aIngress, 13U)) ^ (RotL64(aCarry, 43U) + RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((aWandererA + RotL64(aScatter, 11U)) + 5173905450211892891U) + RotL64(aNonceWordC, 61U);
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 42U)) + 3555542451908039957U) + aPhaseBOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 19U)) + 11559884700283861559U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) + RotL64(aNonceWordE, 35U);
            aOrbiterF = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 47U)) + 1352524329968738673U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 35U)) + 8914206450420616349U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 2251523378498463946U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9541575923299247038U;
            aOrbiterB = RotL64((aOrbiterB * 1066487482799638689U), 3U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 1239854507907214595U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) + RotL64(aNonceWordF, 24U);
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17698101462598498934U;
            aOrbiterA = RotL64((aOrbiterA * 2304948713665996433U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12305566971683256060U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 13804545036303215569U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10359543704152744971U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 10239749097704329264U) + RotL64(aNonceWordG, 19U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 4212214906286320308U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3661436621615751071U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12192418916967430783U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4475514289326450361U;
            aOrbiterJ = RotL64((aOrbiterJ * 17497164630368757887U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (RotL64(aOrbiterA, 22U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 38U) + RotL64(aOrbiterB, 13U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aPhaseBWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 52U)) + aOrbiterA) + RotL64(aNonceWordH, 15U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 37U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + RotL64(aNonceWordD, 47U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 21U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 5U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 52U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_VolleyBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE2EDCF47119F3F89ULL + 0xD0BEF325814C343AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAAFB688A622DEF13ULL + 0xEF15596143AF4ABEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xADB4796C91A062B3ULL + 0x834E62DAD7C4BD02ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE3E67B74BE61A885ULL + 0xE8EB9BFA6DD3A3D6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xAF06770EFA5A01F7ULL + 0xF4FA766BA60ED8FDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x94C41BFF210A49E5ULL + 0xF95BD129F268CDDFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBB80F4915270B427ULL + 0x9C59F0319550123BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x91B7D5AA76742C71ULL + 0xC63C337D8DC21747ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 23U) ^ RotL64(aNonceWordH, 13U)) ^ RotL64(aNonceWordD, 51U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3566U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2138U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 37U) ^ RotL64(aNonceWordE, 11U)) ^ RotL64(aNonceWordA, 29U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1880U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneA[((aIndex + 2628U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCross, 19U)) ^ (RotL64(aCarry, 39U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = (((aWandererE + RotL64(aCross, 48U)) + 966899917801652720U) + aPhaseCOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1]) + RotL64(aNonceWordA, 9U);
            aOrbiterD = ((aWandererB + RotL64(aScatter, 53U)) + 10996327672320748649U) + aPhaseCOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aIngress, 5U)) + 4188171566846621107U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 39U)) + 5886209243097387959U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 13U)) + 14940428957136728111U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 58U)) + RotL64(aCarry, 51U)) + 179187285531914832U;
            aOrbiterA = (((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 6685351948936817752U) + RotL64(aNonceWordD, 17U);
            aOrbiterH = (aWandererA + RotL64(aPrevious, 27U)) + 1894506461704029700U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 4182760368636977082U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 12523318028514940790U) + RotL64(aNonceWordC, 44U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 5059306166973366892U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2857409765717296483U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5890872367917643851U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 17747338389865221534U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5306740664798049267U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13906227834259884100U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7152105382899756368U;
            aOrbiterH = RotL64((aOrbiterH * 6772157117358310485U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17868101884759619240U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 11758843266314148347U) ^ RotL64(aNonceWordH, 13U);
            aOrbiterC = RotL64((aOrbiterC * 5919135169337501485U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 13950566197090324859U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17278105609930477854U;
            aOrbiterJ = RotL64((aOrbiterJ * 11431842718945107359U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9556785965646738355U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 841298436857932987U;
            aOrbiterG = RotL64((aOrbiterG * 15077843186688841797U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1951515285492133830U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15775839819330588437U;
            aOrbiterA = RotL64((aOrbiterA * 7902654031401620995U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5585458468816495436U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17258586689032223623U;
            aOrbiterD = RotL64((aOrbiterD * 1652050227399194271U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5254132659445988836U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15440741734777060925U;
            aOrbiterI = RotL64((aOrbiterI * 17445581079035134067U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 28U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 36U)) + aOrbiterI) + RotL64(aCarry, 41U)) + aPhaseCWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterG, 43U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 10U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH) + RotL64(aNonceWordG, 45U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 3U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterH, 56U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 51U)) + aOrbiterE) + RotL64(aNonceWordB, 57U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 27U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 52U) + aOrbiterD) + RotL64(aOrbiterK, 23U));
            aWandererI = aWandererI + ((RotL64(aCross, 21U) + RotL64(aOrbiterA, 19U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererB, 40U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererF, 50U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 29U) ^ RotL64(aNonceWordG, 58U)) ^ RotL64(aNonceWordA, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13977U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((aIndex + 8899U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 29U) ^ RotL64(aNonceWordF, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12594U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12205U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 20U) + RotL64(aCarry, 51U)) ^ (RotL64(aCross, 3U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = (aWandererK + RotL64(aPrevious, 10U)) + 13350544654542863236U;
            aOrbiterB = (aWandererA + RotL64(aCross, 51U)) + 12364346790125404372U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 3U)) + 9738750172849512764U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 23U)) + 3781373837635491421U) + aPhaseCOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 30U)) + RotL64(aCarry, 37U)) + 16635020317512702337U;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 5383653921676231276U) + aPhaseCOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aScatter, 19U)) + 10181959815492056493U;
            aOrbiterH = (((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 10005510924273927017U) + RotL64(aNonceWordH, 31U);
            aOrbiterG = ((aWandererC + RotL64(aIngress, 39U)) + 9524687662265740565U) + RotL64(aNonceWordG, 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4259138552009771014U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8973051213213726023U;
            aOrbiterA = RotL64((aOrbiterA * 12625091476068190979U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17602611840127337490U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8218984546932905269U;
            aOrbiterJ = RotL64((aOrbiterJ * 17504305273683304231U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 18102186122213487888U) + RotL64(aNonceWordB, 13U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 2629927500298092976U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6983280164448292723U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2491581597835795234U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9506602492971620955U;
            aOrbiterH = RotL64((aOrbiterH * 9559829640915637163U), 3U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 13422942713680612924U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordD, 60U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 15037354693234876601U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12692376075738621447U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12896066842192894694U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2202952306291905855U;
            aOrbiterE = RotL64((aOrbiterE * 6779368532763429997U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12160313482450599313U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10812986281270407756U;
            aOrbiterK = RotL64((aOrbiterK * 7786608700746771809U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 12474638293190144525U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5882870951276225224U;
            aOrbiterI = RotL64((aOrbiterI * 15532427302173572457U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3782896138051179209U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10965680631059882311U;
            aOrbiterB = RotL64((aOrbiterB * 14060923998307082385U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (RotL64(aOrbiterD, 10U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterI, 42U)) + aPhaseCWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterD, 11U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 19U)) + aOrbiterD) + RotL64(aNonceWordC, 7U));
            aWandererC = aWandererC + ((((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 29U)) + RotL64(aNonceWordE, 27U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 34U) + aOrbiterK) + RotL64(aOrbiterB, 23U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterG, 46U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB) + aPhaseCWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterE, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 30U) ^ RotL64(aNonceWordD, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20350U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 17027U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordB, 29U)) ^ RotL64(aNonceWordH, 53U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19067U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16442U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 37U)) + (RotL64(aPrevious, 50U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 2786079456995203065U) + aPhaseCOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 24U)) + RotL64(aCarry, 29U)) + 7237256119153857253U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 19U)) + 9310834010563647604U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 17361734905706517877U) + RotL64(aNonceWordG, 11U);
            aOrbiterD = (aWandererA + RotL64(aCross, 47U)) + 15837111231884647451U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 35U)) + 18065431964418026445U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 11U)) + 3029123922999952652U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 41U)) + 5166926595573507837U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 4U)) + 1918425684273807598U) + RotL64(aNonceWordC, 7U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4724551751012661440U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1818014487579644390U;
            aOrbiterI = RotL64((aOrbiterI * 14904092108647864911U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6670090372241084216U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8485757110007268693U;
            aOrbiterA = RotL64((aOrbiterA * 11876760095108618363U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4928130251509514742U) + RotL64(aNonceWordD, 3U);
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2528788422725346792U;
            aOrbiterG = RotL64((aOrbiterG * 1855982047967756661U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 2860387120895147503U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12927802338151379368U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8876144125458603029U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 18029699867733207083U) + RotL64(aNonceWordB, 27U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 13361836994951253312U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5349767426256597073U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11957294454794128079U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3755417922063414648U;
            aOrbiterF = RotL64((aOrbiterF * 13896364063651241401U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 18001157153447913032U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 16214145724690286854U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5874139687703360515U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3860958772090975562U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12395621524459640173U;
            aOrbiterB = RotL64((aOrbiterB * 722817135977510161U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3402035664910754484U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2139099117325745602U;
            aOrbiterE = RotL64((aOrbiterE * 14008983756425796029U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 21U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 40U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 58U) + aOrbiterG) + RotL64(aOrbiterF, 6U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterE, 51U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 57U)) + aOrbiterF) + RotL64(aCarry, 11U)) + RotL64(aNonceWordE, 14U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterI, 35U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 10U) + aOrbiterB) + RotL64(aOrbiterA, 18U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 43U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterJ, 39U)) + RotL64(aNonceWordH, 9U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 23U)) + aOrbiterB) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 26U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 11U) ^ RotL64(aNonceWordB, 58U)) ^ RotL64(aNonceWordH, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31944U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 30657U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordD, 30U)) ^ RotL64(aNonceWordE, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26619U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((aIndex + 31854U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 10U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 35U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterC = ((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 18087125778766689269U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 6U)) + 13710545066503235196U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 53U)) + 1701939704736254645U) + RotL64(aNonceWordB, 53U);
            aOrbiterE = ((((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 29U)) + 8064093611384019909U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordE, 15U);
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 47U)) + 16623332751533885431U;
            aOrbiterK = (aWandererH + RotL64(aCross, 39U)) + 15590129153794910109U;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 7413312683079107383U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aIngress, 28U)) + 4186064478651458810U;
            aOrbiterA = (aWandererI + RotL64(aCross, 13U)) + 5501191643940735954U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 11064645242200570835U) + RotL64(aNonceWordH, 54U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 13825922087298055833U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7529317892716108867U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5944980709887369970U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8181136916070569646U;
            aOrbiterB = RotL64((aOrbiterB * 395183021205661827U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15442336949157292482U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 11580554435240641337U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6654637892858767739U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11240018128174598322U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2027565596050777471U;
            aOrbiterC = RotL64((aOrbiterC * 18048186560314431815U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16425887196883725233U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 16828683527588834095U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17746289103235902485U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9923829146479008804U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6669171007279929454U;
            aOrbiterK = RotL64((aOrbiterK * 681823450939955099U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3902430046523165149U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6739998149289590041U;
            aOrbiterI = RotL64((aOrbiterI * 2675037435528416821U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16014401255534234075U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 14741857638680634564U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8723611021403369393U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5064807861673260054U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 968747317273200299U) ^ RotL64(aNonceWordA, 25U);
            aOrbiterJ = RotL64((aOrbiterJ * 14122304002722582329U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 11U);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 18U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterC, 3U)) + RotL64(aNonceWordG, 43U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 48U)) + aOrbiterJ) + RotL64(aNonceWordD, 41U)) + aPhaseCWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterI, 41U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 14U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 19U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterB, 57U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 58U) + RotL64(aOrbiterE, 52U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 13U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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

void TwistExpander_VolleyBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD3D647B236CD97B7ULL + 0xF3B281C4E93E6E3AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFD8F045543DE3811ULL + 0xEC0F2BA9EDD03665ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD24A3904AD3EFFC7ULL + 0xE79773B18CCD843AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xAE4FD5FC37E8BC4BULL + 0x97A08F825E6FD0EFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBBF0F7F9FA5D3D43ULL + 0xA6756B4F71EFEAB9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x907E834C5628B245ULL + 0x8DA5CA598FB13513ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFD77276C6175A4D7ULL + 0xF73D653E8E36742EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFD8FC045E0259615ULL + 0xBD191EF7F0E8E082ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 29U) ^ RotL64(aNonceWordB, 19U)) ^ RotL64(aNonceWordG, 53U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2005U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneC[((aIndex + 1551U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 35U) ^ RotL64(aNonceWordF, 56U)) ^ RotL64(aNonceWordH, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3285U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4153U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 35U)) ^ (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 50U)) + 12027839670755583592U) + RotL64(aNonceWordB, 43U);
            aOrbiterK = (aWandererE + RotL64(aCross, 13U)) + 15380130703509859843U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 43U)) + 4590907433867798074U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 47U)) + 1754574023602519724U) + aPhaseDOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 9832756659564903767U) + aPhaseDOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aCross, 53U)) + 5035088494491470403U;
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 14199170923323644638U) + RotL64(aNonceWordC, 7U);
            aOrbiterB = ((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 13U)) + 8325619421264440438U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 56U)) + 969534320779067977U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 11U)) + 270575869402913847U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 39U)) + 13344806516599578910U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15143147951139409101U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14425582489214169238U;
            aOrbiterG = RotL64((aOrbiterG * 16893787086337916355U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13951127523239064584U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14177925225918293579U;
            aOrbiterJ = RotL64((aOrbiterJ * 13079514031864998485U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8258920744278218901U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7408161179397242453U;
            aOrbiterE = RotL64((aOrbiterE * 975737128100519169U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8581481606764773468U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 10078416198417433133U) ^ RotL64(aNonceWordA, 51U);
            aOrbiterI = RotL64((aOrbiterI * 1102721083915858247U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 18299772198826189580U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 18304668908084397946U;
            aOrbiterA = RotL64((aOrbiterA * 10589455451200578687U), 27U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 16729632621573817223U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + RotL64(aNonceWordD, 40U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13362300981585573239U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9824473895535518785U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8629682832849915380U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6852852009091469641U;
            aOrbiterC = RotL64((aOrbiterC * 11912646687050011915U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 7433098156961745198U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10931806208899417308U;
            aOrbiterK = RotL64((aOrbiterK * 14699197041038067483U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 629604718211675247U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1487372736719237118U;
            aOrbiterF = RotL64((aOrbiterF * 705192821277928909U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3567439893461603384U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11143068753134694333U;
            aOrbiterB = RotL64((aOrbiterB * 15529326960229305389U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14242098279913980463U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12027839670755583592U;
            aOrbiterH = RotL64((aOrbiterH * 6630014752150544153U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 28U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 54U) + aOrbiterB) + RotL64(aOrbiterF, 47U)) + RotL64(aNonceWordE, 27U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterF, 5U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 56U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 13U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterE, 23U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterH, 21U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 35U)) + aOrbiterD) + RotL64(aCarry, 35U)) + RotL64(aNonceWordF, 49U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterA, 18U)) + aPhaseDWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 51U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 52U) + aOrbiterA) + RotL64(aOrbiterG, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 41U) ^ RotL64(aNonceWordA, 11U)) ^ RotL64(aNonceWordH, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8164U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((aIndex + 7957U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 38U) ^ RotL64(aNonceWordB, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5587U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 9210U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 14U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 57U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = ((aWandererE + RotL64(aIngress, 60U)) + RotL64(aCarry, 47U)) + 11274974230580265396U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 11U)) + 16658438747342741547U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 11U)) + 16612986966106053844U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 43U)) + 9329502236843231290U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 6U)) + 14088261356708344656U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 27U)) + 13692608802007789581U;
            aOrbiterI = (aWandererC + RotL64(aCross, 37U)) + 6824473946645682398U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 43U)) + 2072915876348570040U) + aPhaseDOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aScatter, 35U)) + 7420507753044460759U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 39U)) + 4677557318688502593U) + RotL64(aNonceWordG, 43U);
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 47U)) + 15081678577055628459U) + aPhaseDOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordF, 54U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7026792817486507482U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 14871665922943969918U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 694073180313083145U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 6807734532159292872U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17882797335141303280U;
            aOrbiterK = RotL64((aOrbiterK * 15439872930381050291U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9233542707022629190U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1205501586581350876U;
            aOrbiterH = RotL64((aOrbiterH * 2596053290311090589U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10878718669747466677U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8066049063548639241U;
            aOrbiterI = RotL64((aOrbiterI * 3031382633089381605U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 861295180226875235U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9134969787937288583U;
            aOrbiterJ = RotL64((aOrbiterJ * 7565008208670843555U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6726642007159809594U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8061661744643240470U;
            aOrbiterB = RotL64((aOrbiterB * 6703498926835391813U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13541412083111962884U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8617442758729315637U;
            aOrbiterG = RotL64((aOrbiterG * 15471862889276160953U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 16884403561131293362U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 9490680911678221233U) ^ RotL64(aNonceWordC, 37U);
            aOrbiterD = RotL64((aOrbiterD * 15988763830018001033U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 10486145044311386738U) + RotL64(aNonceWordE, 39U);
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10200001044821063684U;
            aOrbiterF = RotL64((aOrbiterF * 16149790736141571017U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6997073594007878034U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 13585783612009989767U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11425303157774550449U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3847846040256340653U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11274974230580265396U;
            aOrbiterC = RotL64((aOrbiterC * 13970270689108369205U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 46U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 19U)) + aOrbiterE) + RotL64(aNonceWordB, 7U));
            aWandererG = aWandererG + ((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 21U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterJ, 5U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 50U) + RotL64(aOrbiterI, 37U)) + aOrbiterG);
            aWandererI = aWandererI + (((((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 34U)) + aOrbiterH) + RotL64(aCarry, 43U)) + RotL64(aNonceWordD, 49U)) + aPhaseDWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterF, 41U));
            aWandererE = aWandererE + ((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterB, 53U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 51U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterD, 29U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterD, 10U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 48U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordA, 56U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 12878U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 14394U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordE, 27U)) ^ RotL64(aNonceWordH, 60U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11354U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 15366U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 20U) ^ RotL64(aCross, 5U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = (((aWandererE + RotL64(aScatter, 26U)) + 5480870806135400132U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordB, 31U);
            aOrbiterA = (aWandererH + RotL64(aPrevious, 43U)) + 8034874599430768743U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 4006919843736863767U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 29U)) + 2988069748674633718U) + aPhaseDOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 3U)) + 12347295651973135786U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 47U)) + 14152683894431568192U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 53U)) + 15765143815254196598U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 51U)) + 10473067082331244233U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 18U)) + 1089466925383677249U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 13215039929873682230U;
            aOrbiterD = (((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 43U)) + 3957997712247961479U) + RotL64(aNonceWordG, 56U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10023907397941685546U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 14593012591254614353U;
            aOrbiterF = RotL64((aOrbiterF * 17111300092082154687U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13353797968154036726U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9259966668512102858U;
            aOrbiterJ = RotL64((aOrbiterJ * 8326732574268308221U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10757861831070349321U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10530223113483866178U;
            aOrbiterA = RotL64((aOrbiterA * 11269177745265396583U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7554320926405521865U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 6978052067277966996U) ^ RotL64(aNonceWordF, 23U);
            aOrbiterK = RotL64((aOrbiterK * 18020134738536217801U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1053695861967171420U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15980734683539854451U;
            aOrbiterE = RotL64((aOrbiterE * 3208466640010555357U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17041258393808061556U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12846551858751995530U;
            aOrbiterI = RotL64((aOrbiterI * 9303891433380993639U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14617434286683320666U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3999309956180741302U;
            aOrbiterB = RotL64((aOrbiterB * 15037707937050015205U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 13452627760403094126U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 2633241575260427158U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1]) ^ RotL64(aNonceWordD, 39U);
            aOrbiterG = RotL64((aOrbiterG * 2638570213290747581U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 15575035993965639421U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 7829837426112185905U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17059814556114938275U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12565466096663867876U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 4845209979900289818U;
            aOrbiterH = RotL64((aOrbiterH * 14990494169374347835U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13472490162287247012U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5480870806135400132U;
            aOrbiterD = RotL64((aOrbiterD * 9150331893094034245U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 56U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 11U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 38U) + RotL64(aOrbiterC, 56U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterD, 39U));
            aWandererF = aWandererF + ((((RotL64(aCross, 5U) + RotL64(aOrbiterE, 47U)) + aOrbiterK) + RotL64(aCarry, 35U)) + RotL64(aNonceWordC, 59U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 13U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aCross, 43U) + RotL64(aOrbiterA, 19U)) + aOrbiterI) + RotL64(aNonceWordA, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterG, 3U));
            aWandererI = aWandererI + ((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterA, 27U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterC, 29U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterB, 22U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterD, 43U)) + aPhaseDWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 36U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererD, 38U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordE, 20U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 17962U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17270U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 23U) ^ RotL64(aNonceWordD, 44U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19433U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20208U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 19U)) ^ (RotL64(aCross, 6U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = ((aWandererC + RotL64(aIngress, 39U)) + 16451272412693907816U) + RotL64(aNonceWordB, 26U);
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 19U)) + 10099485419723255462U) + aPhaseDOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aScatter, 3U)) + 17668900099534923192U;
            aOrbiterI = (aWandererA + RotL64(aCross, 58U)) + 5497093724143181753U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 10354044773550071706U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 12728258851198019099U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 11U)) + 4144050505314242618U) + aPhaseDOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aPrevious, 47U)) + 14133805325480076530U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 5U)) + 308863673210602899U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 44U)) + RotL64(aCarry, 53U)) + 11741180130160569753U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 21U)) + 12926863156769180448U) + RotL64(aNonceWordD, 61U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 211920854786494259U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13234608842479411078U;
            aOrbiterD = RotL64((aOrbiterD * 2556747209733759467U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9164711974854618892U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6667377062281954219U;
            aOrbiterK = RotL64((aOrbiterK * 2603737166987437649U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4559040002406721850U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1749875480850675109U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15822640067349481089U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 9555365165561936366U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 18289733999504213574U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14156217554673229429U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 8727162691639622461U) + RotL64(aNonceWordH, 41U);
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 291406782452963706U;
            aOrbiterA = RotL64((aOrbiterA * 8413500075082350243U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 8294911802626492257U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15853578397277298548U;
            aOrbiterE = RotL64((aOrbiterE * 13256191781365357747U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11535146194939658681U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2177540476748375661U;
            aOrbiterC = RotL64((aOrbiterC * 15791341922007841029U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2705306323728084136U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17617871830709148043U;
            aOrbiterB = RotL64((aOrbiterB * 3449981219502809255U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3699834746313613206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17952609181629473245U;
            aOrbiterF = RotL64((aOrbiterF * 6103160209028988839U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8016694658897707674U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6971251395823324489U;
            aOrbiterJ = RotL64((aOrbiterJ * 13483776115929040277U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 17467528888050817915U) + RotL64(aNonceWordF, 27U);
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16451272412693907816U;
            aOrbiterI = RotL64((aOrbiterI * 13689734638238895071U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterC, 48U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 53U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 3U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aScatter, 4U) + aOrbiterG) + RotL64(aOrbiterJ, 11U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 37U)) + aOrbiterA) + aPhaseDWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + RotL64(aOrbiterK, 23U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterD, 42U)) + RotL64(aNonceWordA, 43U));
            aWandererC = aWandererC + (((RotL64(aScatter, 42U) + aOrbiterF) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterH, 13U));
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterB, 57U)) + RotL64(aNonceWordC, 3U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 27U)) + aOrbiterI) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 22U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 10U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 23U) ^ RotL64(aNonceWordA, 40U)) ^ RotL64(aNonceWordH, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 26762U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25353U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 47U) ^ RotL64(aNonceWordE, 39U)) ^ RotL64(aNonceWordC, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24949U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 25307U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = (((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 51U)) + 2571116506511057880U) + aPhaseDOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aCross, 19U)) + 13112435411509707292U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 13U)) + 10403251762787357256U) + RotL64(aNonceWordG, 26U);
            aOrbiterI = ((aWandererE + RotL64(aIngress, 40U)) + RotL64(aCarry, 5U)) + 8461951095541400405U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 35U)) + 9890793478557463815U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 3030229465991783707U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 43U)) + 7273848154043719247U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 11U)) + 10681774862516028276U) + aPhaseDOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aScatter, 57U)) + 7105082755586853104U;
            aOrbiterK = (aWandererD + RotL64(aCross, 21U)) + 6588579345319551129U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 28U)) + 14616333550242386092U) + RotL64(aNonceWordB, 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15439666290229654921U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3360304356760164799U;
            aOrbiterG = RotL64((aOrbiterG * 5164191920584106237U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 14438730801970761889U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14515616787452085729U;
            aOrbiterC = RotL64((aOrbiterC * 2041601927968559821U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4167853822635132419U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8950982233003320239U;
            aOrbiterJ = RotL64((aOrbiterJ * 887144270884244907U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 12391327853728029953U) + RotL64(aNonceWordD, 41U);
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7100871010552394421U;
            aOrbiterK = RotL64((aOrbiterK * 16552349374101955967U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 15381697462381887944U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6801677551341079401U;
            aOrbiterD = RotL64((aOrbiterD * 13325954438427340703U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 947011315719204867U) + RotL64(aNonceWordC, 3U);
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6356920162398333481U;
            aOrbiterI = RotL64((aOrbiterI * 5566721941682667419U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8910262020598577378U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8778455415977526457U;
            aOrbiterF = RotL64((aOrbiterF * 4092470497616637283U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 5585696961453127223U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9670655481681494412U;
            aOrbiterA = RotL64((aOrbiterA * 7863197168965036383U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10713004007087085729U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4036355047492922339U;
            aOrbiterE = RotL64((aOrbiterE * 6923922258047667173U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14580156873863533497U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7049502932205025182U;
            aOrbiterB = RotL64((aOrbiterB * 8665428649262370727U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12707521269341941677U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 2571116506511057880U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2388236789245943699U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 44U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 21U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 53U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 57U)) + aOrbiterA) + RotL64(aNonceWordF, 13U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 44U) + RotL64(aOrbiterE, 50U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterG, 39U)) + RotL64(aNonceWordH, 23U)) + aPhaseDWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 19U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 35U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 10U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 54U) + aOrbiterB) + RotL64(aOrbiterD, 47U)) + aPhaseDWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 43U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 27U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordG, 53U)) ^ RotL64(aNonceWordF, 40U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32553U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31121U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 27U) ^ RotL64(aNonceWordH, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27783U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30915U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 19U) + RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = ((aWandererH + RotL64(aIngress, 27U)) + 439898681482066326U) + RotL64(aNonceWordG, 40U);
            aOrbiterH = (aWandererJ + RotL64(aCross, 37U)) + 17362083676671776094U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 47U)) + 6418499837265155024U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 10U)) + 17262244253027454972U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 41U)) + 2382066162993139503U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 13U)) + 14345808395587174135U;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 7534743166385552851U) + RotL64(aNonceWordA, 49U);
            aOrbiterE = ((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 51U)) + 16994453324688523966U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 22U)) + 7079553728544045092U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aScatter, 51U)) + 3562822704508440641U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 13990892681975857821U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1796728922368577238U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 6605161260520067178U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8147537646591674091U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13994083795942328918U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6144523182899107711U;
            aOrbiterI = RotL64((aOrbiterI * 4153879991344611283U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12247462325297436642U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 1065809332002012789U) ^ RotL64(aNonceWordC, 35U);
            aOrbiterA = RotL64((aOrbiterA * 5496601177032953251U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10147919864511540753U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17138553441127273354U;
            aOrbiterC = RotL64((aOrbiterC * 5773875596275267871U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2653924016109573974U) + RotL64(aNonceWordD, 19U);
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6254416952351699582U;
            aOrbiterE = RotL64((aOrbiterE * 12756861659704947257U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 813046408080197079U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9624466135414123483U;
            aOrbiterJ = RotL64((aOrbiterJ * 6960320253124395015U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 972586705850825744U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 155283774901960223U;
            aOrbiterF = RotL64((aOrbiterF * 9928051687724257041U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 18200100644751360406U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1168426822045686004U;
            aOrbiterK = RotL64((aOrbiterK * 5867027156069481313U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2271564377169233643U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1896317305868283986U;
            aOrbiterD = RotL64((aOrbiterD * 8080751157990019287U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 10209708407397294552U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 947585551223387294U;
            aOrbiterH = RotL64((aOrbiterH * 15339472308062247067U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12313594490465462211U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 439898681482066326U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12336632799055203705U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 10U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + RotL64(aOrbiterB, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 27U) + RotL64(aOrbiterE, 43U)) + aOrbiterG) + RotL64(aCarry, 35U)) + RotL64(aNonceWordB, 23U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 11U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 58U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 39U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterE, 37U)) + RotL64(aNonceWordE, 53U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 50U) + RotL64(aOrbiterA, 19U)) + aOrbiterB) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 41U)) + aOrbiterC) + aPhaseDWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 51U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 35U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aCross, 34U) + aOrbiterE) + RotL64(aOrbiterH, 46U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 42U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 14U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_VolleyBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xABA6CAB458DF17E1ULL + 0xE90D0936AE23041DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBDA8D3B53D20D10DULL + 0x9C56DAE1C79B2D22ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x901D3C99DD6FAA19ULL + 0xECB041D8AEA4E9E2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC69460D12889E4EDULL + 0x9D781B4C423DCB18ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD92408BC16583229ULL + 0xF2FDAC3D30954A1FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD28DBBFC4BDA8FE7ULL + 0xF9D46EAF5AC370A0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBBA1AA719B73839FULL + 0x8CBEEEF25977714FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA80961988CFD7D11ULL + 0xA3275A955B36FC75ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 12U) ^ RotL64(aNonceWordF, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3396U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((aIndex + 681U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 23U) ^ RotL64(aNonceWordB, 43U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3603U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 768U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 60U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (aWandererB + RotL64(aIngress, 53U)) + 15910560457440369082U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 39U)) + 17953072986407436888U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 27U)) + 15446940721193538669U) + RotL64(aNonceWordB, 52U);
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 3020785262774422009U;
            aOrbiterH = (((aWandererD + RotL64(aCross, 46U)) + RotL64(aCarry, 19U)) + 7001288645424994404U) + RotL64(aNonceWordC, 53U);
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 19U)) + 13385250665458462689U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aScatter, 29U)) + 4841895644623005949U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 57U)) + 13053476783239482065U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 6U)) + 641996979335975244U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 16211238020928688299U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aCross, 23U)) + 12715448751323279480U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17784406727699995290U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16626339815786580778U;
            aOrbiterA = RotL64((aOrbiterA * 13940754474750138041U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9035070625716345139U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6085848172494001945U;
            aOrbiterG = RotL64((aOrbiterG * 10405728912339646693U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1177103851507561053U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterJ) ^ 2281901691017816407U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) ^ RotL64(aNonceWordE, 15U);
            aOrbiterC = RotL64((aOrbiterC * 3142197009403602497U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9040984343694325070U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13334258224023902365U;
            aOrbiterK = RotL64((aOrbiterK * 4782523727707164869U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1079824790138592518U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14024082692012948652U;
            aOrbiterJ = RotL64((aOrbiterJ * 3219489374333737903U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 2966776524421278970U) + RotL64(aNonceWordG, 47U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 5510281854029308547U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9275402927591867297U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 7126632329316720048U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 1476827035602733472U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2217671289726794033U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 6470212302133184965U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4172257438373147415U;
            aOrbiterI = RotL64((aOrbiterI * 4449314239630366533U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11445212164224402184U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1779825157413363285U;
            aOrbiterH = RotL64((aOrbiterH * 15393425495668107155U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7561888690947559866U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14440989817038856852U;
            aOrbiterB = RotL64((aOrbiterB * 5799807036762859679U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10618807050937260814U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15910560457440369082U;
            aOrbiterF = RotL64((aOrbiterF * 10902491688248464465U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 56U));
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 21U)) + aOrbiterB) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 51U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterI, 53U)) + aOrbiterE) + RotL64(aNonceWordA, 23U));
            aWandererB = aWandererB + ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 60U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterA, 13U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 35U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterJ, 23U));
            aWandererE = aWandererE + (((RotL64(aIngress, 30U) + RotL64(aOrbiterC, 19U)) + aOrbiterE) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 29U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 6U)) + aOrbiterK) + RotL64(aNonceWordH, 3U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 3U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 12U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 10U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordC, 12U)) ^ RotL64(aNonceWordB, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 6043U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9098U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 57U) ^ RotL64(aNonceWordH, 35U)) ^ RotL64(aNonceWordE, 43U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6322U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6553U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 43U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 11U)) + 3236820517816085022U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (((aWandererK + RotL64(aIngress, 36U)) + RotL64(aCarry, 13U)) + 741288875914097926U) + aPhaseEOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 27U)) + 8417246926007729580U) + RotL64(aNonceWordF, 36U);
            aOrbiterI = (aWandererE + RotL64(aCross, 3U)) + 9715717805774537170U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 19U)) + 14360243844821619482U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 39U)) + 10760908100206775334U;
            aOrbiterD = (aWandererI + RotL64(aCross, 41U)) + 3434641779946167811U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 51U)) + 7885568822756234567U) + RotL64(aNonceWordH, 9U);
            aOrbiterB = (aWandererC + RotL64(aPrevious, 29U)) + 3041563437672051294U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 53U)) + 15761355327564963516U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 48U)) + RotL64(aCarry, 51U)) + 1158633562785937421U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9338581575871970653U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9172038894262857354U;
            aOrbiterH = RotL64((aOrbiterH * 3110871165285625807U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14653924713599790081U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3854497592598563309U;
            aOrbiterA = RotL64((aOrbiterA * 11737111068815795303U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16286980180327600557U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5092583772591249756U;
            aOrbiterF = RotL64((aOrbiterF * 13955105624639442903U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4288397994175567333U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15584236478994873104U;
            aOrbiterD = RotL64((aOrbiterD * 1860480595862755379U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5557463939827483792U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 2659814275753280856U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17702430405693184643U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6941807963525063449U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2040598555191211307U;
            aOrbiterC = RotL64((aOrbiterC * 14750544987531722765U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 347572666231116258U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 779304821185302523U;
            aOrbiterI = RotL64((aOrbiterI * 14180254150318109855U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10632524582873079742U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 9761308771280517212U) ^ RotL64(aNonceWordB, 23U);
            aOrbiterK = RotL64((aOrbiterK * 13926235411726048921U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2097439707055737964U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2813977930321463948U;
            aOrbiterJ = RotL64((aOrbiterJ * 14983538728730662603U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 6080592019313796689U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5396623654821376409U;
            aOrbiterE = RotL64((aOrbiterE * 15478858835919398677U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 8460497459575045342U) + RotL64(aNonceWordA, 13U);
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3236820517816085022U;
            aOrbiterG = RotL64((aOrbiterG * 5530411244458067093U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 50U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 46U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 4U) + RotL64(aOrbiterK, 37U)) + aOrbiterB);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterA, 58U)) + RotL64(aNonceWordE, 15U));
            aWandererH = aWandererH + ((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterE, 11U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 13U)) + aOrbiterG) + aPhaseEWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 36U) + RotL64(aOrbiterB, 47U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 43U)) + aOrbiterD) + aPhaseEWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterF, 53U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterI, 23U));
            aWandererA = aWandererA + (((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterC, 56U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 21U)) + aOrbiterI) + RotL64(aNonceWordG, 25U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 58U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + RotL64(aWandererE, 46U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 27U) ^ RotL64(aNonceWordG, 51U)) ^ RotL64(aNonceWordD, 4U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15554U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13384U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 29U) ^ RotL64(aNonceWordB, 13U)) ^ RotL64(aNonceWordA, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13171U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 16111U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 26U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aCross, 3U)) + 7960325128608297381U) + RotL64(aNonceWordD, 15U);
            aOrbiterA = ((aWandererK + RotL64(aScatter, 56U)) + RotL64(aCarry, 37U)) + 12773836012104052042U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 3173972621347773016U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 3708401356314308171U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 53U)) + 950774285720019449U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aCross, 13U)) + 4170092315705438265U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 43U)) + 17000449130864980747U) + RotL64(aNonceWordH, 3U);
            aOrbiterH = (aWandererC + RotL64(aPrevious, 39U)) + 8793910540062893860U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 6U)) + 520277969543516469U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 21U)) + 12762214857389827271U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aCross, 37U)) + 2932451184340207695U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11062179998786293839U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7919119215271524178U;
            aOrbiterE = RotL64((aOrbiterE * 9053677007180081359U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1774988449597115155U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3799792889466518953U;
            aOrbiterK = RotL64((aOrbiterK * 17512791286490623455U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 1815062051307896589U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 15260373951371654483U) ^ RotL64(aNonceWordE, 35U);
            aOrbiterA = RotL64((aOrbiterA * 2208604434669491625U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12867546628945676853U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7772820973895846946U;
            aOrbiterD = RotL64((aOrbiterD * 7581704643538761985U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 14213957831821966834U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 16561105721170419454U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2540533987337175367U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 16556502948339949526U) + RotL64(aNonceWordC, 49U);
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9706742922075498974U;
            aOrbiterG = RotL64((aOrbiterG * 8527361328901355457U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 13455756934917486016U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 9107769876332723454U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1722386100852683783U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15793099079168487016U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7968278803691283365U;
            aOrbiterF = RotL64((aOrbiterF * 11644765391940099387U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15068302421261745111U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11373111908765197862U;
            aOrbiterI = RotL64((aOrbiterI * 17756438368103196771U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 6362100123286229887U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 528778333872160609U;
            aOrbiterJ = RotL64((aOrbiterJ * 17377710146983314215U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6116442644744391285U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7960325128608297381U;
            aOrbiterC = RotL64((aOrbiterC * 17826511435509927061U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (RotL64(aOrbiterG, 24U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 3U)) + aOrbiterI);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterE, 21U)) + RotL64(aNonceWordG, 7U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 23U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterD, 60U));
            aWandererH = aWandererH + (((RotL64(aCross, 23U) + RotL64(aOrbiterK, 5U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterE, 19U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 37U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterB, 54U));
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 39U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 54U) + RotL64(aOrbiterE, 13U)) + aOrbiterB) + RotL64(aNonceWordF, 10U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 26U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordD, 60U)) ^ RotL64(aNonceWordB, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 21672U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19089U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 43U) ^ RotL64(aNonceWordH, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19892U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16907U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 36U) + RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 50U)) + RotL64(aCarry, 23U)) + 4751694786009671052U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 16362725160370844224U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 41U)) + 6360885380915941057U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 13U)) + 5154536007972297036U) + RotL64(aNonceWordF, 45U);
            aOrbiterA = (aWandererI + RotL64(aPrevious, 39U)) + 9362540581874808253U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 35U)) + 13902493871525612934U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 3U)) + 10208452885367546542U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aScatter, 43U)) + 3117030377279160998U) + aPhaseEOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aIngress, 48U)) + 17286247690414027870U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 41U)) + 3930314320040949141U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 21U)) + 7289525252391668404U) + RotL64(aNonceWordH, 36U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3434167955466809185U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17852573095128575663U;
            aOrbiterJ = RotL64((aOrbiterJ * 1485660158767033425U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6137259687928853253U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13992510605237574698U;
            aOrbiterA = RotL64((aOrbiterA * 15346263295995333395U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6470556523400123474U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4333255670390099293U;
            aOrbiterC = RotL64((aOrbiterC * 11089933812030082647U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7700424876430257995U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16920736951239453071U;
            aOrbiterG = RotL64((aOrbiterG * 8920407493132380497U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1635071690430295730U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9966700845966398620U;
            aOrbiterB = RotL64((aOrbiterB * 17210048121896546867U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 9833458070123027075U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1990346556486746432U;
            aOrbiterH = RotL64((aOrbiterH * 8704943923474148699U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 13339523466436517327U) + RotL64(aNonceWordE, 47U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 5018264760406215603U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2769197961801783627U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 123427497520755346U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 4535841104215792886U;
            aOrbiterE = RotL64((aOrbiterE * 1417676310539177131U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3525925567359163763U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3273741481392187986U;
            aOrbiterF = RotL64((aOrbiterF * 16116160744647235811U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 6230742908784102407U) + RotL64(aNonceWordA, 29U);
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7578784912496239362U;
            aOrbiterD = RotL64((aOrbiterD * 2614448818452560369U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 14669810330213234082U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4751694786009671052U;
            aOrbiterI = RotL64((aOrbiterI * 9583151676882991817U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 48U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterF, 10U)) + RotL64(aNonceWordB, 37U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterK, 43U));
            aWandererG = aWandererG + (((RotL64(aIngress, 60U) + aOrbiterE) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 35U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 57U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterC, 19U)) + RotL64(aNonceWordC, 59U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 21U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterI, 23U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 44U) + RotL64(aOrbiterH, 40U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 46U));
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 11U) ^ RotL64(aNonceWordC, 21U)) ^ RotL64(aNonceWordE, 56U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23637U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 24364U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordB, 21U)) ^ RotL64(aNonceWordF, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24144U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26856U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 57U)) + (RotL64(aPrevious, 38U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 35U)) + 2330952702412094686U) + aPhaseEOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aCross, 48U)) + 7820188225935060799U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 37U)) + 9347644591709839145U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 5U)) + 2288624878446846870U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 39U)) + 9358977729492824128U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 11U)) + 1858511275052455039U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 53U)) + 13715478509322292552U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 29U)) + 16413396625604260455U) + RotL64(aNonceWordC, 41U);
            aOrbiterC = ((aWandererA + RotL64(aCross, 58U)) + RotL64(aCarry, 57U)) + 17714322215518432705U;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 16188315436202861122U) + RotL64(aNonceWordG, 21U);
            aOrbiterH = ((aWandererH + RotL64(aScatter, 21U)) + 5564445841368207813U) + aPhaseEOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13717068949900594673U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14143659432287313765U;
            aOrbiterG = RotL64((aOrbiterG * 17281441046722262917U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5729546141908425670U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4297827922736712074U;
            aOrbiterB = RotL64((aOrbiterB * 13631630436759768885U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 829520109395163673U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11547160328525174295U;
            aOrbiterK = RotL64((aOrbiterK * 4759690159673049775U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2907177944512117206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11100346409065275671U;
            aOrbiterF = RotL64((aOrbiterF * 17927994356809011637U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1344592529249949068U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6470438516791143572U;
            aOrbiterJ = RotL64((aOrbiterJ * 13339390828725370475U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5217751823741520847U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterI) ^ 5371275223586938039U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) ^ RotL64(aNonceWordD, 7U);
            aOrbiterE = RotL64((aOrbiterE * 12318403075523724125U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 14218103150268532919U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1367628876596800571U;
            aOrbiterD = RotL64((aOrbiterD * 13777531272321533137U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2372041991018455610U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9870744274890595581U;
            aOrbiterC = RotL64((aOrbiterC * 12093443117747395585U), 51U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 15531376915156611594U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordF, 44U);
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11166549148968363252U;
            aOrbiterH = RotL64((aOrbiterH * 10024372567841218915U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8555942275137258839U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 3304132937209624841U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7965093976633155809U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14825330575158830172U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2330952702412094686U;
            aOrbiterA = RotL64((aOrbiterA * 9146641978165131495U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 36U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 29U)) + aOrbiterB) + RotL64(aNonceWordE, 55U));
            aWandererD = aWandererD + (((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 58U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 44U) + aOrbiterC) + RotL64(aOrbiterF, 39U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterE, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterF, 35U));
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 60U)) + aOrbiterE) + aPhaseEWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterK, 13U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterE, 43U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterB, 27U));
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterC, 37U)) + RotL64(aNonceWordH, 31U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + RotL64(aWandererD, 56U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 14U) ^ RotL64(aNonceWordH, 39U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30622U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 29275U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 34U) ^ RotL64(aNonceWordG, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31794U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27854U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCarry, 23U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 41U)) + 5510690816044082200U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 21U)) + 15967820875033940530U;
            aOrbiterH = (aWandererA + RotL64(aCross, 34U)) + 539348720848176221U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 3U)) + 15779318183635560817U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aCross, 37U)) + 14511058534424187469U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 5811130556873428391U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 41U)) + 1085928476499444025U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 57U)) + 6973335316600768130U) + RotL64(aNonceWordG, 17U);
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 10747243745475009744U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 11U)) + 1072260008981349754U) + RotL64(aNonceWordA, 55U);
            aOrbiterF = ((aWandererH + RotL64(aCross, 26U)) + 2018772405352495753U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1092091597048996547U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15103140149542167197U;
            aOrbiterH = RotL64((aOrbiterH * 621856991658027989U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13194619321108681542U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 16749188603268621850U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9575408950550922039U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 7427959503086895166U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 9895804051379551393U) ^ RotL64(aNonceWordF, 37U);
            aOrbiterE = RotL64((aOrbiterE * 2701997336201570715U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4526020800679774259U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4484850928870048176U;
            aOrbiterG = RotL64((aOrbiterG * 17556987520625677313U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1837404844299040155U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15213208978489570694U;
            aOrbiterC = RotL64((aOrbiterC * 7062740584650274133U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9615231781751396800U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15872192167825648096U;
            aOrbiterA = RotL64((aOrbiterA * 2900526493682580729U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 12530672039655918903U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10617836782870315804U;
            aOrbiterI = RotL64((aOrbiterI * 9716778004909794973U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 550750725406860977U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3498554352021622907U;
            aOrbiterF = RotL64((aOrbiterF * 9846933294851238495U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4059346317776216057U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14161853870874499023U;
            aOrbiterJ = RotL64((aOrbiterJ * 8601560894939097781U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4088411647683253905U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9321241420172776158U) ^ RotL64(aNonceWordB, 27U);
            aOrbiterB = RotL64((aOrbiterB * 4167888281125330225U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8527337525861632945U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5510690816044082200U;
            aOrbiterD = RotL64((aOrbiterD * 12464836001483233379U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 21U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aCross, 18U) + aOrbiterC) + RotL64(aOrbiterB, 11U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 51U)) + aOrbiterH) + aPhaseEWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterC, 19U)) + RotL64(aNonceWordE, 61U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 14U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterK, 47U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordD, 8U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterA, 53U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 57U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 44U) + RotL64(aOrbiterD, 26U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 56U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_VolleyBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD5884E622DC2FE71ULL + 0x8158A88B00E452ABULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8321846F970569F9ULL + 0x89B49EA099AB0136ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFF6B6615D2B7CF9BULL + 0x90EB03DBBC4C30D4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x99CB284F02861B51ULL + 0xFE97BE7FCCF48FEBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xAFE39A4685BA2B8DULL + 0x80724F0527058223ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8BCD8D594781EA91ULL + 0xDAE9DBBBEA2538E4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xFA16DF1B209A009FULL + 0xAD93957E9898390CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB23E7BA5A253188FULL + 0xC0C1B6C25605DAEEULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 29U) ^ RotL64(aNonceWordF, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3951U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneC[((aIndex + 3524U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 39U) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 556U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 340U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 11U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = ((aWandererI + RotL64(aIngress, 3U)) + 7722279280863371124U) + RotL64(aNonceWordB, 55U);
            aOrbiterK = (aWandererC + RotL64(aCross, 47U)) + 11584220561732385598U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 53U)) + 7834679350105534657U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 50U)) + 11347994382444180879U;
            aOrbiterJ = ((((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 9449903188047063431U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordD, 47U);
            aOrbiterE = (aWandererF + RotL64(aPrevious, 41U)) + 6516243976652795170U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 8420815253991184777U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 9081386852515170937U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 14U)) + 14375955191735286867U) + aPhaseFOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aScatter, 11U)) + 880757589768436072U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 57U)) + 3349856625725164229U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7826309957607577207U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8057435761214313635U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4718430712767038607U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 9565237500443303103U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15893066735310588501U;
            aOrbiterE = RotL64((aOrbiterE * 8457633439171452397U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3276844534476430842U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6828644383891274120U;
            aOrbiterC = RotL64((aOrbiterC * 979580351653410157U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2815676923011504251U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 5030251870850928417U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7075653570570819253U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13464083008377887034U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 8994560761846897590U) ^ RotL64(aNonceWordE, 51U);
            aOrbiterF = RotL64((aOrbiterF * 9892839554658865143U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8398813387154468736U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8136429428340910892U;
            aOrbiterD = RotL64((aOrbiterD * 3348811490733577295U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 418587250696862341U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4111667833838312094U;
            aOrbiterI = RotL64((aOrbiterI * 860949442143849147U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6075478294190926371U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2208124955874142264U;
            aOrbiterK = RotL64((aOrbiterK * 15741988616251072075U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4726538724576443010U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6524078248882840425U;
            aOrbiterJ = RotL64((aOrbiterJ * 9784875566721689069U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14521003220464811621U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 16916247868211621303U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1911638054294853877U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 18207293125461843123U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 7722279280863371124U) ^ RotL64(aNonceWordH, 59U);
            aOrbiterG = RotL64((aOrbiterG * 14303108475807941791U), 29U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 11U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 38U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterG, 20U)) + RotL64(aNonceWordG, 23U));
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterE, 27U));
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterH, 47U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 20U) + aOrbiterD) + RotL64(aOrbiterI, 57U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 23U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 3U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 13U)) + aOrbiterK);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 29U)) + aOrbiterF) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 40U) + RotL64(aOrbiterJ, 34U)) + aOrbiterC) + RotL64(aCarry, 57U)) + RotL64(aNonceWordA, 54U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 39U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordC, 47U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9733U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneD[((aIndex + 9285U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 20U) ^ RotL64(aNonceWordH, 3U)) ^ RotL64(aNonceWordG, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9033U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7099U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 6U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererB + RotL64(aScatter, 60U)) + 14499676118633326000U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 3U)) + 17191273593018552288U) + RotL64(aNonceWordB, 45U);
            aOrbiterK = ((aWandererF + RotL64(aCross, 23U)) + 4085176294948097737U) + aPhaseFOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 11112671474158908186U) + aPhaseFOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordF, 7U);
            aOrbiterC = (aWandererH + RotL64(aPrevious, 41U)) + 8745787969012266485U;
            aOrbiterE = (aWandererE + RotL64(aCross, 35U)) + 18074049663777707948U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 5U)) + 2543758649719164688U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 10U)) + 4659584749412700523U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 27U)) + 974639159259871273U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 29U)) + 9211220687971081987U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 8567024626862182714U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 5803002132294840900U) + RotL64(aNonceWordG, 56U);
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11968489432878148467U;
            aOrbiterK = RotL64((aOrbiterK * 4501441062617123165U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9470807228394903442U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1692347973120388469U;
            aOrbiterD = RotL64((aOrbiterD * 17433393164156231575U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 16510815732690193145U) + RotL64(aNonceWordC, 43U);
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 755159406833096510U;
            aOrbiterC = RotL64((aOrbiterC * 14091736464659561165U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1518824876475937620U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 701225390867330446U;
            aOrbiterJ = RotL64((aOrbiterJ * 12264618860580199927U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8425976693733003889U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7182176375442410367U;
            aOrbiterA = RotL64((aOrbiterA * 8860605703761731859U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4546566785167467924U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2593340999038753749U;
            aOrbiterF = RotL64((aOrbiterF * 10152461487764567563U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9756331608356622299U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 5511625814747641978U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4806076157539829529U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8694400787420160733U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12648969491371382682U;
            aOrbiterE = RotL64((aOrbiterE * 5346585704222643759U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15261238546696118531U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14236129054778329471U;
            aOrbiterI = RotL64((aOrbiterI * 11789581469516267749U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 16251500056378064213U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 790320176607605195U;
            aOrbiterH = RotL64((aOrbiterH * 15706130623435648555U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17114773669444878655U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 14499676118633326000U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8095707555083587081U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 60U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterF, 54U)) + RotL64(aNonceWordD, 37U));
            aWandererI = aWandererI + (((RotL64(aIngress, 58U) + aOrbiterK) + RotL64(aOrbiterD, 27U)) + aPhaseFWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterI, 39U));
            aWandererB = aWandererB + ((RotL64(aCross, 13U) + RotL64(aOrbiterI, 29U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterF, 13U));
            aWandererA = aWandererA + (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 43U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 41U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterD, 3U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterI, 5U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 11U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 24U)) + aOrbiterJ) + RotL64(aNonceWordA, 27U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 53U) ^ RotL64(aNonceWordC, 12U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13242U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14531U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 47U) ^ RotL64(aNonceWordH, 3U)) ^ RotL64(aNonceWordD, 39U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16142U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13518U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 3U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererF + RotL64(aCross, 35U)) + 16802219662864902427U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 39U)) + 14332033461409490629U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aIngress, 29U)) + 8781794298640286845U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 12U)) + 8459933908074937264U) + RotL64(aNonceWordE, 29U);
            aOrbiterK = (((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 29U)) + 1883580287986004426U) + RotL64(aNonceWordA, 47U);
            aOrbiterF = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 17500258188004626118U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 7934811305150872870U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 41U)) + 6380363892361098905U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 27U)) + 12623079132626676910U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 50U)) + 10455208121949202703U) + aPhaseFOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aCross, 21U)) + 8805532707916767629U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 9161544391400377699U) + RotL64(aNonceWordG, 50U);
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3501434325829663268U;
            aOrbiterH = RotL64((aOrbiterH * 7933545151293799637U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 651783304096081996U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 441505031509930622U;
            aOrbiterF = RotL64((aOrbiterF * 8045355432310956143U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1771159983581326424U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 15227946417377695989U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1563141188972797601U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4153717524193279095U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4404521756523902829U;
            aOrbiterK = RotL64((aOrbiterK * 1410342912973206203U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6231945075461813285U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3864780227164426690U;
            aOrbiterJ = RotL64((aOrbiterJ * 18031353247480673617U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 1509699687948576558U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17316114302489411191U;
            aOrbiterD = RotL64((aOrbiterD * 15490661284980281585U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2250572827340157410U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 6403966113144372915U) ^ RotL64(aNonceWordD, 61U);
            aOrbiterB = RotL64((aOrbiterB * 726441947009132383U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2329903609147403156U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2486330017319455238U;
            aOrbiterC = RotL64((aOrbiterC * 17427461345935191757U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9333421733051210144U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 14779925626161889533U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9120486933147706541U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 4343688173541745311U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12686722305368397686U;
            aOrbiterG = RotL64((aOrbiterG * 17484250022537912537U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 3745163111502795473U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16802219662864902427U;
            aOrbiterA = RotL64((aOrbiterA * 4343730534036919417U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 20U);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 30U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterF, 39U));
            aWandererE = aWandererE + (((RotL64(aScatter, 14U) + aOrbiterF) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 43U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 35U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 27U)) + aOrbiterC) + RotL64(aNonceWordF, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterC, 23U)) + aPhaseFWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 47U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterH, 19U)) + aPhaseFWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 56U) + aOrbiterE) + RotL64(aOrbiterG, 51U)) + RotL64(aNonceWordC, 39U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 56U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + RotL64(aWandererE, 50U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 35U) ^ RotL64(aNonceWordF, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17991U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18961U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 52U) ^ RotL64(aNonceWordD, 43U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18401U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((aIndex + 19098U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 57U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 36U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererK + RotL64(aPrevious, 35U)) + 2571116506511057880U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 13112435411509707292U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 41U)) + 10403251762787357256U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 37U)) + 8461951095541400405U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 58U)) + 9890793478557463815U) + RotL64(aNonceWordG, 10U);
            aOrbiterA = (aWandererI + RotL64(aIngress, 19U)) + 3030229465991783707U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 51U)) + 7273848154043719247U) + RotL64(aNonceWordE, 27U);
            aOrbiterJ = ((aWandererA + RotL64(aCross, 11U)) + 10681774862516028276U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 7105082755586853104U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aCross, 30U)) + 6588579345319551129U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 13U)) + 14616333550242386092U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15439666290229654921U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3360304356760164799U;
            aOrbiterG = RotL64((aOrbiterG * 5164191920584106237U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14438730801970761889U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 14515616787452085729U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2041601927968559821U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4167853822635132419U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8950982233003320239U;
            aOrbiterA = RotL64((aOrbiterA * 887144270884244907U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12391327853728029953U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7100871010552394421U;
            aOrbiterC = RotL64((aOrbiterC * 16552349374101955967U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 15381697462381887944U) + RotL64(aNonceWordC, 29U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6801677551341079401U;
            aOrbiterJ = RotL64((aOrbiterJ * 13325954438427340703U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 947011315719204867U) + RotL64(aNonceWordH, 55U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6356920162398333481U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5566721941682667419U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 8910262020598577378U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8778455415977526457U;
            aOrbiterE = RotL64((aOrbiterE * 4092470497616637283U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5585696961453127223U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9670655481681494412U;
            aOrbiterI = RotL64((aOrbiterI * 7863197168965036383U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10713004007087085729U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 4036355047492922339U;
            aOrbiterB = RotL64((aOrbiterB * 6923922258047667173U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14580156873863533497U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7049502932205025182U;
            aOrbiterK = RotL64((aOrbiterK * 8665428649262370727U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12707521269341941677U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2571116506511057880U;
            aOrbiterD = RotL64((aOrbiterD * 2388236789245943699U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 5U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 18U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 13U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterA, 23U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 10U) + RotL64(aOrbiterE, 50U)) + aOrbiterI) + aPhaseFWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterK, 41U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 53U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 58U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterB, 27U)) + RotL64(aNonceWordB, 21U));
            aWandererK = aWandererK + ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 39U)) + aOrbiterC);
            aWandererE = aWandererE ^ (((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterG, 19U)) + RotL64(aNonceWordA, 39U));
            aWandererC = aWandererC + (((RotL64(aIngress, 56U) + RotL64(aOrbiterK, 5U)) + aOrbiterB) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 46U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 30U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 6U) ^ RotL64(aNonceWordD, 27U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24306U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23029U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 10U) ^ RotL64(aNonceWordA, 35U)) ^ RotL64(aNonceWordC, 27U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26954U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 25809U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 38U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererC + RotL64(aIngress, 50U)) + 4259993311776766595U;
            aOrbiterA = (aWandererB + RotL64(aCross, 53U)) + 2857813330021126753U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 1345396841329442896U) + aPhaseFOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 57U)) + 320992148982301024U) + RotL64(aNonceWordH, 61U);
            aOrbiterJ = (aWandererI + RotL64(aIngress, 19U)) + 5619109532065293074U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 34U)) + 10380157329426706345U) + aPhaseFOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 12449831150625409695U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 21U)) + 7847096607042268396U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 13U)) + 11707184096803214678U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 47U)) + 9893643746186827088U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 3U)) + 333687403830908774U) + RotL64(aNonceWordA, 59U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13837360705077441580U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4367119682175710689U;
            aOrbiterD = RotL64((aOrbiterD * 10295744669174603401U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 1193493435041306784U) + RotL64(aNonceWordG, 39U);
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15062951612027370606U;
            aOrbiterB = RotL64((aOrbiterB * 2509383510565136549U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16000173839235429105U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 15294482444605409961U) ^ RotL64(aNonceWordF, 38U);
            aOrbiterC = RotL64((aOrbiterC * 1031800997944302665U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5720749055549773527U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17248674962996093668U;
            aOrbiterF = RotL64((aOrbiterF * 15730637462755795591U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 16956840483882091059U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9637715107943515594U;
            aOrbiterH = RotL64((aOrbiterH * 8878362378343603463U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7147495779349862274U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 7508890985889484275U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17728368447504622035U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4407738164617959366U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17027017782352660454U;
            aOrbiterK = RotL64((aOrbiterK * 417183060881259295U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 3174658601748235285U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9779053567370714831U;
            aOrbiterG = RotL64((aOrbiterG * 6383245776181968033U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16256981360027888091U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12778335633397105924U;
            aOrbiterI = RotL64((aOrbiterI * 10821225965811763659U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 13985909343937844583U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14307218309393008729U;
            aOrbiterA = RotL64((aOrbiterA * 12053366452617039877U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15549857305890093491U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4259993311776766595U;
            aOrbiterJ = RotL64((aOrbiterJ * 13703695714360435719U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 4U);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterA, 13U));
            aWandererB = aWandererB + ((RotL64(aCross, 27U) + RotL64(aOrbiterF, 23U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterK, 57U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 22U) + RotL64(aOrbiterJ, 48U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 13U) + RotL64(aOrbiterB, 3U)) + aOrbiterA) + RotL64(aNonceWordB, 3U)) + aPhaseFWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 43U)) + aOrbiterA) + aPhaseFWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterE, 11U));
            aWandererE = aWandererE + (((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterA, 40U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aScatter, 24U) + aOrbiterA) + RotL64(aOrbiterI, 35U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 5U)) + RotL64(aNonceWordE, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 44U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 36U) ^ RotL64(aNonceWordE, 57U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29845U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 32227U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 53U) ^ RotL64(aNonceWordA, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31011U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneB[((aIndex + 28813U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 50U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 3U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 46U)) + 8604208734152026945U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 53U)) + 1374329953253889829U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 41U)) + 5779278910548228339U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 35U)) + 17670451230882805140U) + RotL64(aNonceWordD, 55U);
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 8193848740764866860U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 48U)) + 15801168428145650104U) + RotL64(aNonceWordC, 25U);
            aOrbiterK = (((aWandererK + RotL64(aCross, 39U)) + RotL64(aCarry, 57U)) + 2584718176087499066U) + aPhaseFOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 29U)) + 14950366247822737997U) + aPhaseFOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aCross, 5U)) + 9779293225265670135U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 8688968319288372383U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 57U)) + 13665723186950342601U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9395428688359973510U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 2152719218018108418U) ^ RotL64(aNonceWordG, 45U);
            aOrbiterI = RotL64((aOrbiterI * 15271961483518392671U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1350324137411377992U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8729317951386057921U;
            aOrbiterJ = RotL64((aOrbiterJ * 6008790836417785083U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6317310451893678411U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 10175620379041384281U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14079679617394330781U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1203082119358827708U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 523869107818193101U;
            aOrbiterK = RotL64((aOrbiterK * 4629501113595689157U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4028324959540432983U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 15447631947468213912U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6037306615787729185U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14225888694733041031U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11925000696281947629U;
            aOrbiterC = RotL64((aOrbiterC * 4337022940520411253U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15015531024930608745U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16752579225076943550U;
            aOrbiterB = RotL64((aOrbiterB * 15551083683579981439U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2432733494869267901U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10103430321388601485U;
            aOrbiterH = RotL64((aOrbiterH * 18372919379972432569U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15943360147468638325U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 9782703760233558733U) ^ RotL64(aNonceWordE, 31U);
            aOrbiterF = RotL64((aOrbiterF * 685056980418243879U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 18345087852012669037U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8897505040792027675U;
            aOrbiterE = RotL64((aOrbiterE * 14333687539092412967U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7402581293947129667U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8604208734152026945U;
            aOrbiterG = RotL64((aOrbiterG * 9965525485538037673U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterG, 29U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 43U)) + aOrbiterB) + RotL64(aNonceWordH, 61U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 13U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 12U) + aOrbiterF) + RotL64(aOrbiterK, 58U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 37U)) + aOrbiterA) + RotL64(aCarry, 57U)) + RotL64(aNonceWordF, 22U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterB, 39U)) + aPhaseFWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 24U) + aOrbiterE) + RotL64(aOrbiterJ, 11U));
            aWandererK = aWandererK + ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 46U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterK, 51U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterI, 27U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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

void TwistExpander_VolleyBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xFD71222D0F69D627ULL + 0xB4EC7E28DB285827ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA8D04467740C5F8BULL + 0x91118AB5D675A6A2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEA051D55BBEEF0A5ULL + 0xC0E561B734B42E13ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB6C4E2C14DBE6CF3ULL + 0x81821178393CEE09ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x860039718153DBADULL + 0xC3BC82B1E673EDF8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xDFAB4A443BDA2539ULL + 0x8ED6C523A2E650F0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x91DEAB8631C97BCBULL + 0xC76D2E4F4863611BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xAF7969241F1318DDULL + 0xEE5C20B7B9F210DBULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 13U) ^ RotL64(aNonceWordA, 47U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4282U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 436U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordB, 35U)) ^ RotL64(aNonceWordD, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 962U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneA[((aIndex + 559U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 13U)) ^ (RotL64(aCarry, 41U) + RotL64(aIngress, 26U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererI + RotL64(aScatter, 27U)) + 2915859148137000694U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 29U)) + 210680583721444425U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 27U)) + 6668118118775650387U;
            aOrbiterF = (aWandererA + RotL64(aCross, 50U)) + 15794200818099010989U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 5U)) + 6565076707062828369U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 39U)) + 16323164497808856719U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 7965435318816716560U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 47U)) + 7390281030573369017U) + RotL64(aNonceWordD, 21U);
            aOrbiterB = ((aWandererE + RotL64(aIngress, 21U)) + 2269738866911824875U) + RotL64(aNonceWordA, 3U);
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 24U)) + 9664014216039993873U;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 43U)) + 18284857398028357633U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 367667619795303009U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7935945060956274197U;
            aOrbiterI = RotL64((aOrbiterI * 5481786693511955209U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16683666162337789540U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10655658270998102390U;
            aOrbiterJ = RotL64((aOrbiterJ * 15231596813382239841U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 8307037916581540297U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3247742749860703524U;
            aOrbiterC = RotL64((aOrbiterC * 15052136713218656641U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10446792483683818139U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 16374602929344972364U) ^ RotL64(aNonceWordF, 11U);
            aOrbiterF = RotL64((aOrbiterF * 12599903932725787599U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2411334498322777183U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1093701164116833765U;
            aOrbiterE = RotL64((aOrbiterE * 13129220206835381729U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 17018480952982840635U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17348395690080029814U;
            aOrbiterB = RotL64((aOrbiterB * 6212591395713433257U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 16111252311283623152U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 12776492920397785951U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) ^ RotL64(aNonceWordE, 20U);
            aOrbiterD = RotL64((aOrbiterD * 6136009241593081821U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12214538600808144816U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10043377462096783363U;
            aOrbiterG = RotL64((aOrbiterG * 14639467375095185877U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5101561512438055661U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3683207847147603335U;
            aOrbiterA = RotL64((aOrbiterA * 14355438383379198639U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14446947359104987749U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7596096688268335354U;
            aOrbiterK = RotL64((aOrbiterK * 13522935803383107145U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14015424109468938015U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2915859148137000694U;
            aOrbiterH = RotL64((aOrbiterH * 3653144205211106817U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 50U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 43U) + RotL64(aOrbiterK, 37U)) + aOrbiterA) + aPhaseFWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 43U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterC, 19U)) + RotL64(aNonceWordG, 13U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 29U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterG, 6U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 20U) + RotL64(aOrbiterJ, 23U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 57U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 53U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterI, 41U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 28U) + RotL64(aOrbiterJ, 11U)) + aOrbiterH) + RotL64(aNonceWordH, 27U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterF, 50U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 5U) ^ RotL64(aNonceWordH, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8556U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((aIndex + 9117U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 44U) ^ RotL64(aNonceWordA, 19U)) ^ RotL64(aNonceWordC, 27U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8479U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5894U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 24U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererB + RotL64(aCross, 27U)) + 15813325389431304548U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 3U)) + 2223874171125403602U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 29U)) + 5510483568496824130U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 35U)) + 15474152493495661876U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 50U)) + 16846339705130829195U) + aPhaseFOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 41U)) + 1289670576865739669U) + RotL64(aNonceWordF, 47U);
            aOrbiterJ = (aWandererC + RotL64(aScatter, 43U)) + 18017354919647006944U;
            aOrbiterE = (aWandererA + RotL64(aCross, 11U)) + 8539685539928984921U;
            aOrbiterG = ((((aWandererH + RotL64(aPrevious, 14U)) + RotL64(aCarry, 57U)) + 3333721400836704048U) + aPhaseFOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordG, 12U);
            aOrbiterB = ((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 39U)) + 2261560416623815491U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 4377786131746816567U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 18047393176583722719U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8184724021940434631U;
            aOrbiterA = RotL64((aOrbiterA * 9800116157750921119U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10469895939183324807U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 14543391765109879223U;
            aOrbiterH = RotL64((aOrbiterH * 4817987697437667225U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5757225781746158178U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 3539000495894022869U) ^ RotL64(aNonceWordH, 31U);
            aOrbiterK = RotL64((aOrbiterK * 1032298408884695925U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11288971092707065923U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2761384065186568294U;
            aOrbiterJ = RotL64((aOrbiterJ * 3323838837427471051U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7120580145300417101U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 6977246291769372866U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15170353875184253779U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17625434527765525937U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3299714663631376190U;
            aOrbiterI = RotL64((aOrbiterI * 6532628892760776767U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 10331889953489885250U) + RotL64(aNonceWordD, 27U);
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8550932256881727932U;
            aOrbiterD = RotL64((aOrbiterD * 13085531621192583719U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11151195711186126257U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2552002192824926483U;
            aOrbiterF = RotL64((aOrbiterF * 9754056316698523849U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 8038115194286715268U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 16594489591573505305U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1241387574663818247U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13476964484361081681U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 2136330439951908303U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12728359054660550527U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 231990686776499700U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15813325389431304548U;
            aOrbiterC = RotL64((aOrbiterC * 9155088985405261637U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 21U);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 46U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 50U) + aOrbiterF) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 29U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 48U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterB, 5U)) + aPhaseFWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 57U)) + aOrbiterK);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 24U) + RotL64(aOrbiterA, 3U)) + aOrbiterG) + RotL64(aNonceWordE, 11U));
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterD, 53U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 51U)) + RotL64(aNonceWordA, 25U));
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 39U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterA, 27U));
            aWandererA = aWandererA + ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 44U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 34U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 44U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 60U) ^ RotL64(aNonceWordF, 35U)) ^ RotL64(aNonceWordE, 51U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11483U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 15225U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 47U) ^ RotL64(aNonceWordD, 36U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12131U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15073U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 6U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererG + RotL64(aPrevious, 37U)) + 15188686795415908074U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 17310049041983079779U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 8246925977992441471U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 34U)) + 8644260919918112781U) + aPhaseFOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 41U)) + 13401663736874819483U) + RotL64(aNonceWordD, 39U);
            aOrbiterI = (aWandererB + RotL64(aIngress, 19U)) + 7940358935238314973U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 3U)) + 13278990328548007839U) + aPhaseFOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aScatter, 47U)) + 11346868298353840706U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 37U)) + 2374077904806833579U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 58U)) + 6978903378645019166U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 29U)) + 11951633297870965212U) + RotL64(aNonceWordC, 49U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17398460995357409673U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1215437945597836770U;
            aOrbiterA = RotL64((aOrbiterA * 9322970054123481621U), 11U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 1878751468043972239U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordA, 57U);
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5343002808239712390U;
            aOrbiterI = RotL64((aOrbiterI * 11878640995447558811U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9884918450053276861U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 15894599082080422550U) ^ RotL64(aNonceWordB, 26U);
            aOrbiterD = RotL64((aOrbiterD * 8359936745539546131U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13917339232771145459U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 18101134009493720683U;
            aOrbiterJ = RotL64((aOrbiterJ * 15835859435306756387U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3830086372356903769U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15894394599564584010U;
            aOrbiterE = RotL64((aOrbiterE * 9513921913446609263U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5127590955274245812U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9410946933309720054U;
            aOrbiterH = RotL64((aOrbiterH * 14507476989423060561U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15544384157294987085U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 998801294460434123U;
            aOrbiterG = RotL64((aOrbiterG * 5946968142746472745U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 16442095194965452163U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 14294936349037516932U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14655345374740882581U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16680659892463349201U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10921918150041635666U;
            aOrbiterC = RotL64((aOrbiterC * 2908474941036821745U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15350264522133299871U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 16413848767507968239U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10226942289998651355U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11963105565077056299U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15188686795415908074U;
            aOrbiterF = RotL64((aOrbiterF * 13002484121826831091U), 39U);
            //
            aIngress = RotL64(aOrbiterI, 39U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 30U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterH, 10U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterC, 53U));
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 43U)) + aOrbiterA) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterB, 35U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 47U)) + aPhaseFWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterH, 41U)) + RotL64(aNonceWordF, 21U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterK, 22U));
            aWandererI = aWandererI + (((RotL64(aCross, 24U) + aOrbiterF) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 39U)) + RotL64(aNonceWordG, 5U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 38U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 40U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 57U) ^ RotL64(aNonceWordA, 3U)) ^ RotL64(aNonceWordC, 47U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16593U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 16679U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 11U) ^ RotL64(aNonceWordG, 46U)) ^ RotL64(aNonceWordH, 35U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21037U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17538U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCarry, 37U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 28U)) + RotL64(aCarry, 41U)) + 7651355040951791298U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 43U)) + 13988210277931659312U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 19U)) + 9846849412579537783U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 19U)) + 12746719939495876158U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 47U)) + 11498066185182895284U) + aPhaseFOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 11U)) + 11101058955193080232U;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 5U)) + 15513734459555672046U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + RotL64(aNonceWordG, 43U);
            aOrbiterA = (aWandererA + RotL64(aCross, 60U)) + 15711108675349394643U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 41U)) + 4771231759949468556U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 39U)) + 11449258010811305256U) + RotL64(aNonceWordD, 9U);
            aOrbiterF = (aWandererG + RotL64(aPrevious, 23U)) + 17036938391509986723U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6999245666776654250U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2106819066263369528U;
            aOrbiterI = RotL64((aOrbiterI * 13005885810757743129U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12716183358903477216U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16752724547046059889U;
            aOrbiterC = RotL64((aOrbiterC * 11475905692393034141U), 43U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 17623077680983093163U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordA, 49U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6726003022297274986U;
            aOrbiterJ = RotL64((aOrbiterJ * 14709385877103232653U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2842410225096524740U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 9235178377537910514U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11813751114775673845U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2619888019860844610U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6295481948199619613U;
            aOrbiterA = RotL64((aOrbiterA * 15429161806953951205U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9724921158061115570U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4070976180958458679U;
            aOrbiterB = RotL64((aOrbiterB * 6080566609081811453U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 5864247978960125554U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7771249710071026757U;
            aOrbiterD = RotL64((aOrbiterD * 4787660062590737657U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15006900854988166845U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2755659268987119046U;
            aOrbiterF = RotL64((aOrbiterF * 8043939381186802359U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1922321482806966418U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13910818219761929659U;
            aOrbiterG = RotL64((aOrbiterG * 8895973123729951173U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 7540972911473176026U) + RotL64(aNonceWordB, 19U);
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5419023469522423893U;
            aOrbiterE = RotL64((aOrbiterE * 1380429266266313945U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2349651834739320824U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 7651355040951791298U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3713776056028698433U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 21U);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 38U) + aOrbiterE) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 57U)) + RotL64(aNonceWordF, 45U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 34U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 39U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterC, 19U)) + RotL64(aNonceWordE, 34U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 21U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterD, 5U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 51U)) + aOrbiterA) + aPhaseFWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterH, 43U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterD, 10U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 3U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 29U) ^ RotL64(aNonceWordB, 11U)) ^ RotL64(aNonceWordA, 21U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23880U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((aIndex + 23939U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordE, 27U)) ^ RotL64(aNonceWordD, 58U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23685U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22778U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCross, 5U)) + (RotL64(aIngress, 51U) + RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererG + RotL64(aCross, 23U)) + 252059974543142812U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 11U)) + 11690823093681457368U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 51U)) + 13282189752890971123U) + RotL64(aNonceWordC, 51U);
            aOrbiterK = (aWandererI + RotL64(aPrevious, 18U)) + 9507416294305708435U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 14053038174390776539U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 57U)) + 14605253312318725009U) + RotL64(aNonceWordG, 35U);
            aOrbiterA = ((aWandererE + RotL64(aIngress, 29U)) + 18138286582677863671U) + aPhaseFOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 43U)) + 8530091235978489988U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 51U)) + 14381731677571170073U;
            aOrbiterH = (aWandererA + RotL64(aCross, 20U)) + 13316413456378978456U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 3U)) + 3910529530149320706U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 6302070286831566901U) + RotL64(aNonceWordE, 31U);
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12324134652758551396U;
            aOrbiterB = RotL64((aOrbiterB * 17136438281540250165U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4773478557638475048U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4031153435446078944U;
            aOrbiterC = RotL64((aOrbiterC * 3876928995240982769U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 3114794895962903899U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3552936509969106796U;
            aOrbiterD = RotL64((aOrbiterD * 16823186892738820299U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 5828754613946145627U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17985241114076114558U;
            aOrbiterH = RotL64((aOrbiterH * 1986669631395606833U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11319331046368072261U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 6104267020171882160U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12525117969211576177U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7662668379725735125U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 6583034411403600735U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1]) ^ RotL64(aNonceWordD, 16U);
            aOrbiterK = RotL64((aOrbiterK * 262095656452193889U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5569865728026310280U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4176065898330374039U;
            aOrbiterA = RotL64((aOrbiterA * 11305749530796963967U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13677146592276526676U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2734371113158117596U;
            aOrbiterE = RotL64((aOrbiterE * 13146444882662731975U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14890607377967461739U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3110674898918355049U;
            aOrbiterF = RotL64((aOrbiterF * 9637837600671200315U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15329760212453783067U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 18214263442264013242U;
            aOrbiterJ = RotL64((aOrbiterJ * 9139354822936682953U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6727267537859989206U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 252059974543142812U;
            aOrbiterG = RotL64((aOrbiterG * 9559128226993261041U), 37U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 39U);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 44U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterF, 11U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 41U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterA, 52U)) + RotL64(aNonceWordB, 27U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterI, 37U));
            aWandererI = aWandererI + ((RotL64(aCross, 36U) + aOrbiterG) + RotL64(aOrbiterH, 23U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterE, 3U)) + aPhaseFWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 21U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterD, 13U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 34U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG) + RotL64(aCarry, 5U)) + RotL64(aNonceWordH, 11U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 5U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 58U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 37U) ^ RotL64(aNonceWordF, 11U)) ^ RotL64(aNonceWordH, 46U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32695U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 28200U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordD, 51U)) ^ RotL64(aNonceWordC, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28325U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 27984U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 34U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 10U)) + RotL64(aCarry, 37U)) + 2783898056762489197U;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 7177192902873343053U) + aPhaseFOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aCross, 27U)) + 12254703232691980774U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 57U)) + 15446547245691219559U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aIngress, 39U)) + 888475203006174856U) + RotL64(aNonceWordB, 21U);
            aOrbiterC = (aWandererA + RotL64(aScatter, 48U)) + 3649183529366307877U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 29U)) + 4642631047518805167U;
            aOrbiterF = (aWandererI + RotL64(aCross, 51U)) + 6108329730724782250U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 23U)) + 8334054653023816636U) + RotL64(aNonceWordA, 39U);
            aOrbiterK = (aWandererH + RotL64(aPrevious, 35U)) + 5891895375031474350U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 3176720746238477862U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6111038696865301675U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11914998302228682704U;
            aOrbiterG = RotL64((aOrbiterG * 11738924766359642853U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17005063057791320948U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 18333780598768130670U;
            aOrbiterB = RotL64((aOrbiterB * 5416759844884107303U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2056115016443263153U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 10245512728872962677U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 707106795383284903U), 23U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterB) + 4810366069422162351U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordG, 30U);
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3051442983125942469U;
            aOrbiterE = RotL64((aOrbiterE * 13558537578054436423U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9285068547223654308U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13067251130180968842U;
            aOrbiterF = RotL64((aOrbiterF * 7000687697769766605U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3203670242792002165U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1770881716916463461U;
            aOrbiterD = RotL64((aOrbiterD * 13870229847371882171U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16286823712870537410U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13067191141829694202U;
            aOrbiterK = RotL64((aOrbiterK * 15629974528467350445U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3414576315085336932U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 8979691827341555245U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15971594804040295757U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11370607523115189596U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1346943598249651668U;
            aOrbiterJ = RotL64((aOrbiterJ * 4994794423314630209U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2441719135451272926U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3347272129827184676U;
            aOrbiterI = RotL64((aOrbiterI * 10434510775894776597U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1116857329130532047U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 2783898056762489197U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) ^ RotL64(aNonceWordC, 7U);
            aOrbiterA = RotL64((aOrbiterA * 9504855173533274401U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 38U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 41U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 29U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterD, 56U)) + RotL64(aNonceWordE, 31U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 30U) + aOrbiterF) + RotL64(aOrbiterJ, 37U));
            aWandererH = aWandererH + ((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterK, 51U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 35U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 48U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 23U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 56U) + aOrbiterG) + RotL64(aOrbiterE, 19U));
            aWandererD = aWandererD + ((((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordF, 27U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 44U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_VolleyBall_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5812U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 2171U)) & W_KEY1], 6U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 6352U)) & W_KEY1], 14U) ^ RotL64(mSource[((aIndex + 324U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 26U)) + (RotL64(aIngress, 41U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererG + RotL64(aCross, 5U)) + 17454559218352016650U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 23U)) + 8005709669325164803U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 38U)) + 13393741948412816357U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 43U)) + 3665865624348875553U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 8334142570031883436U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 17226066128706139657U;
            aOrbiterF = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 29U)) + 3319093033121522613U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 54U)) + 6657535603401588798U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aIngress, 29U)) + 5469746182326331147U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17846791786050221418U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15939541003714896288U;
            aOrbiterC = RotL64((aOrbiterC * 1400351482213119809U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12076763190461077406U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3594038213596405284U;
            aOrbiterG = RotL64((aOrbiterG * 10244002692575821495U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 8301291631324464622U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8460406137668390582U;
            aOrbiterJ = RotL64((aOrbiterJ * 9117147929757711595U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 7612394867020871200U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8525076134853103975U;
            aOrbiterK = RotL64((aOrbiterK * 5790440201072204659U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11929899088215090379U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7119509166360685726U;
            aOrbiterD = RotL64((aOrbiterD * 1662341427992528823U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 5081078459225240607U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 17149991983909906705U;
            aOrbiterB = RotL64((aOrbiterB * 950223374568067343U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8817303295675241994U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7962039282652745113U;
            aOrbiterF = RotL64((aOrbiterF * 12773588587795522121U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 13596273086338032370U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8186297702278180956U;
            aOrbiterA = RotL64((aOrbiterA * 6226504769888753861U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1696277861691580263U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17360461831507082959U;
            aOrbiterH = RotL64((aOrbiterH * 1651378456022210983U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 56U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterC, 19U)) + aPhaseCWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterA, 23U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterG, 28U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 37U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 44U) + RotL64(aOrbiterJ, 47U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterD, 57U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterD, 5U));
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 51U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterB, 10U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererB, 6U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 18U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 14393U)) & S_BLOCK1], 42U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 16142U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 9477U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 11985U)) & W_KEY1], 24U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 18U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 47U)) + 6381335981879993247U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 51U)) + 15595429101600023172U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 10U)) + 5449234297249826461U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aPrevious, 19U)) + 11213734849329731168U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 47U)) + 16438473952464514248U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aPrevious, 29U)) + 7357872882115186976U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 394402075160738643U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 37U)) + 11112941985410283532U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 14U)) + RotL64(aCarry, 35U)) + 14955125011182736212U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 14770727009821304070U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11286366598129204910U;
            aOrbiterA = RotL64((aOrbiterA * 15884310771003021989U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7358400908565425780U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15635109923749114761U;
            aOrbiterJ = RotL64((aOrbiterJ * 12415152149408700329U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13826842523738623579U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1072811298828325231U;
            aOrbiterG = RotL64((aOrbiterG * 9662800288646215083U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4017334196009350776U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 8812213572751410831U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12744171921566782795U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6723457786170634403U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9785583533999417673U;
            aOrbiterB = RotL64((aOrbiterB * 7776915427605471097U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10265132640322153964U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8435670887514808087U;
            aOrbiterC = RotL64((aOrbiterC * 2706263045620662131U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4303823386961718326U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4214384238167491037U;
            aOrbiterF = RotL64((aOrbiterF * 8490707334221154005U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8740835037840799136U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 5988815405391206280U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17838555472135715929U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15539461383052981747U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 3743772525784217714U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6352086797545969187U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 19U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 46U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 6U) + RotL64(aOrbiterE, 42U)) + aOrbiterB) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 53U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 13U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aPrevious, 14U) + aOrbiterF) + RotL64(aOrbiterA, 29U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 60U)) + aOrbiterA) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 21U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterE, 37U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 5U)) + aOrbiterC) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 26U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 19814U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((aIndex + 21124U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 17118U)) & W_KEY1], 44U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21925U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 24U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererH + RotL64(aCross, 3U)) + 13924571355038625040U;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 48U)) + RotL64(aCarry, 27U)) + 16328300979357156658U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aScatter, 53U)) + 3947771961206012461U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 39U)) + 15428284250569311285U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 5777369485254032486U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aPrevious, 26U)) + 16813320300717644673U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 35U)) + 16689933050200758251U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 21U)) + 1856422419049390708U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 18214498743831925517U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 18278550878494094923U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 797712062039591797U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7212998747080137625U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15854849439012341347U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 996882939768167773U;
            aOrbiterE = RotL64((aOrbiterE * 14936703950807908575U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3005829974130671692U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 8793495343509953906U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14065479348374612031U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7710453029930631112U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9511995836117707047U;
            aOrbiterC = RotL64((aOrbiterC * 7250766204781428201U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 670902975693341744U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9045820304668279777U;
            aOrbiterD = RotL64((aOrbiterD * 18373074917532639027U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 12417212387607119470U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12816983560669985622U;
            aOrbiterI = RotL64((aOrbiterI * 8406003970221889847U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17245432086377688540U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6806521945548502014U;
            aOrbiterA = RotL64((aOrbiterA * 11335859481858640857U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8947500746292365294U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4468060468522895852U;
            aOrbiterJ = RotL64((aOrbiterJ * 7022481284816599797U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9892975931958803992U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 3042599331526937836U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3308512896171443645U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 50U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterI, 51U));
            aWandererG = aWandererG + ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterC, 6U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 10U) + RotL64(aOrbiterC, 57U)) + aOrbiterE) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterK, 47U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterE, 13U));
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 20U) + RotL64(aOrbiterD, 29U)) + aOrbiterA);
            aWandererF = aWandererF + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 18U)) + aOrbiterJ) + RotL64(aCarry, 41U)) + aPhaseCWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 39U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27082U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((aIndex + 28779U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29858U)) & S_BLOCK1], 26U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25195U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 20U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererF + RotL64(aIngress, 3U)) + 10404808878585437255U;
            aOrbiterI = (((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 29U)) + 10587858736301591439U) + aPhaseCOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aPrevious, 11U)) + 1430530909801644435U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 30U)) + 9090938022430118902U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aCross, 23U)) + 12936604311751121235U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 1000583006020232032U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 35U)) + 12352532088997042232U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 44U)) + 16723410947058502564U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 39U)) + 16614089235313154270U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4245553025593349277U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3353146318549477494U;
            aOrbiterK = RotL64((aOrbiterK * 14246377408238318091U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5935727336135635196U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10312187090293319667U;
            aOrbiterH = RotL64((aOrbiterH * 1395964500396711899U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12192843181244744484U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2542570124502586365U;
            aOrbiterD = RotL64((aOrbiterD * 17222847847573534963U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3315472769469002444U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17512858811783071174U;
            aOrbiterJ = RotL64((aOrbiterJ * 9070400454074283765U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16633218007427888082U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 2502077714838858460U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 970762420815997725U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 14792910273226469214U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15739513291150783151U;
            aOrbiterG = RotL64((aOrbiterG * 11896279674116906915U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2192903544350345992U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 844428341223009295U;
            aOrbiterE = RotL64((aOrbiterE * 4768368713974002539U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2998511458298901402U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 7790789639864783373U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9173097618440495497U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4540735375055164995U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 13700342877362633034U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14730797752841670505U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 18U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterE, 34U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 30U) + aOrbiterA) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 37U)) + aPhaseCWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterG, 39U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterJ, 11U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 30U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + RotL64(aOrbiterI, 53U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterC, 57U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 3U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 18U) + aOrbiterC) + RotL64(aOrbiterI, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 4U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_VolleyBall_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5189U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7246U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4128U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((aIndex + 4434U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 19U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 13350544654542863236U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 12364346790125404372U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 37U)) + 9738750172849512764U) + aPhaseDOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aCross, 3U)) + 3781373837635491421U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 20U)) + 16635020317512702337U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5383653921676231276U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10181959815492056493U;
            aOrbiterF = RotL64((aOrbiterF * 14784636206508715141U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 10005510924273927017U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9524687662265740565U;
            aOrbiterE = RotL64((aOrbiterE * 13687380438646756931U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4259138552009771014U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 8973051213213726023U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12625091476068190979U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17602611840127337490U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 8218984546932905269U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17504305273683304231U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 18102186122213487888U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2629927500298092976U;
            aOrbiterI = RotL64((aOrbiterI * 6983280164448292723U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterF, 52U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 30U) + RotL64(aOrbiterB, 3U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 28U)) + aOrbiterF) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterF, 37U)) + aPhaseDWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 14U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8228U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 15585U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15415U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8510U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 3650233661228036955U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 41U)) + 11607036400067735729U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aCross, 29U)) + 3899614406903883035U;
            aOrbiterF = (((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 8159156925629965143U) + aPhaseDOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aCross, 60U)) + RotL64(aCarry, 53U)) + 7148903913967261270U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 9161665622287517848U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2981535013474059469U;
            aOrbiterC = RotL64((aOrbiterC * 4434815231517266013U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15812469008200319549U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14687469489893270300U;
            aOrbiterJ = RotL64((aOrbiterJ * 14142363399696670451U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6025209349511417063U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 12964750392311112676U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12955480283032701843U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6572355895765394340U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3542300121890027981U;
            aOrbiterB = RotL64((aOrbiterB * 11201491178181273935U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 6477175684045398359U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 1081388388827929314U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8752188637514143529U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 18U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 57U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 48U)) + aOrbiterF);
            aWandererH = aWandererH + ((((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 18U) + RotL64(aOrbiterI, 11U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterC, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20818U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18005U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21727U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneC[((aIndex + 16988U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 50U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererI + RotL64(aCross, 4U)) + RotL64(aCarry, 23U)) + 7896237440058555694U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 35U)) + 11870529476037558635U) + aPhaseDOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 41U)) + 9158983227801569448U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 13U)) + 4710172270996950329U;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 14634482800356647630U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8822207952170610891U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 13755891414028982553U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5173750624716006485U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4555293067488040719U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 2816805148093762081U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16838149138341713943U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2122631477965135190U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4592922416380416071U;
            aOrbiterD = RotL64((aOrbiterD * 11644507904538573165U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7102471666524164715U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17274623547879474204U;
            aOrbiterE = RotL64((aOrbiterE * 5443572270546181789U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 938587316977094680U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 18258015823797023523U;
            aOrbiterC = RotL64((aOrbiterC * 6068819567674605919U), 39U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 54U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 27U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterC, 19U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 35U)) + aOrbiterE) + aPhaseDWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 46U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aCross, 56U) + aOrbiterB) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 46U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26565U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28875U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31968U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25663U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCross, 27U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aCross, 22U)) + RotL64(aCarry, 47U)) + 16424657151168221875U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 57U)) + 17150123681886380361U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aPrevious, 3U)) + 16041993588694572757U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 9871185846434828537U;
            aOrbiterD = (((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 35U)) + 11227236398354430757U) + aPhaseDOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 5399325217402192631U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9248828789282890454U;
            aOrbiterB = RotL64((aOrbiterB * 6733832755349139621U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9041370494203701062U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14944424084524970764U;
            aOrbiterH = RotL64((aOrbiterH * 10283363059424655079U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5481938174456671041U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 14783648629543752715U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7260164783191886395U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12355573914530445723U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9863991559011968318U;
            aOrbiterC = RotL64((aOrbiterC * 8495251211794343179U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16149688605937250965U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 106041828692026825U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12199934305374582599U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 6U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 51U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 11U)) + aOrbiterB) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 3U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 21U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aPhaseDWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterB, 42U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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

void TwistExpander_VolleyBall_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3793U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneC[((aIndex + 3946U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 609U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 3164U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 19U)) ^ (RotL64(aIngress, 34U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererB + RotL64(aCross, 13U)) + 6024062041314952357U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 27U)) + 18340757093658015585U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 11911120493880346751U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 4U)) + 17428074353884654439U) + aPhaseEOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 11U)) + 12790849760814795936U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 51U)) + 12633397052172117800U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 47U)) + 11946150433665237945U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16842157900909419285U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14186235783224155962U;
            aOrbiterK = RotL64((aOrbiterK * 10521157787073684417U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 13284904542579767591U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11609181965078844357U;
            aOrbiterH = RotL64((aOrbiterH * 5455780554452453513U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9628562297095374984U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7850281529011259759U;
            aOrbiterD = RotL64((aOrbiterD * 17611485102925470357U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 257458718073794527U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 10693404545773519306U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14821443722828498323U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3430519236533871460U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6183054506953198055U;
            aOrbiterE = RotL64((aOrbiterE * 6121082743789970911U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2905610989884221654U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4472163910775333862U;
            aOrbiterJ = RotL64((aOrbiterJ * 7770678426310856745U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 16870142883133769663U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1403692060594816451U;
            aOrbiterG = RotL64((aOrbiterG * 9740854430251597879U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 28U));
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterE, 29U)) + aPhaseEWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 54U)) + aOrbiterE);
            aWandererE = aWandererE + ((((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 47U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterH, 23U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 41U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterG, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10595U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneD[((aIndex + 15138U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10674U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneB[((aIndex + 12290U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 41U)) ^ (RotL64(aCross, 11U) + RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 47U)) + 13854738573712660276U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 51U)) + 16835460633412286294U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 5U)) + 6785859293758091931U) + aPhaseEOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aCross, 12U)) + RotL64(aCarry, 35U)) + 126317283127992659U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 23U)) + 7568963536291415413U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 27U)) + 12294016745653004819U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 35U)) + 18269588932920281147U) + aPhaseEOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5872406424994751026U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 7764434758831474129U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3772146788188420071U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 4804168969415573371U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 959601763507651280U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4647396592804833217U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9257644462479293048U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14332699366894494579U;
            aOrbiterG = RotL64((aOrbiterG * 8829304078930625541U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10487012596470786004U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 612729229562321440U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11380387280507726003U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7845523921295625315U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12742115479740024747U;
            aOrbiterB = RotL64((aOrbiterB * 15578543510683986421U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10294667720904610944U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14369711143154904567U;
            aOrbiterC = RotL64((aOrbiterC * 13753005602288309379U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10918344717497681894U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 18136794828308636957U;
            aOrbiterF = RotL64((aOrbiterF * 17899418637978002409U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 19U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterF, 29U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterG, 51U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 43U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterG, 37U));
            aWandererH = aWandererH + ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 19U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterB, 4U)) + aOrbiterF) + aPhaseEWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 36U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16549U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18624U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19092U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneC[((aIndex + 23128U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 38U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererC + RotL64(aIngress, 11U)) + 9435962834163239322U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 10524704356081318973U;
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 13U)) + 7403401305665208680U) + aPhaseEOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aCross, 41U)) + 7525414805023556493U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aPrevious, 5U)) + 1116686470029070951U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 20U)) + 13257612299137802420U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 9181543003986598283U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9739384852307501107U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11308402900229016057U;
            aOrbiterH = RotL64((aOrbiterH * 12690186771773188967U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 14935167593705272337U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7171824007631943535U;
            aOrbiterE = RotL64((aOrbiterE * 4839974427616194289U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8068411284829563567U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 12350207458513447578U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 813973258659041895U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17039236343991574134U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 18291683592714999632U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7771718817924840713U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6239616841884430968U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10604527977569876774U;
            aOrbiterG = RotL64((aOrbiterG * 6972820410084939637U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 1707724300671717658U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3802268808625297647U;
            aOrbiterD = RotL64((aOrbiterD * 11296811630387191563U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9423064323799920219U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 242153923313096551U;
            aOrbiterI = RotL64((aOrbiterI * 12117679073775630197U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 35U);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 14U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterD, 29U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterJ, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 23U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 10U) + aOrbiterA) + RotL64(aOrbiterE, 35U));
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterG, 50U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32037U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28711U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28085U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneD[((aIndex + 28123U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 50U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 35U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererA + RotL64(aPrevious, 19U)) + 1866656689936219099U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 2312314528139448289U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 35U)) + 3554037526469185237U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aScatter, 41U)) + 405707755060974111U;
            aOrbiterD = (((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 1862976326004007697U) + aPhaseEOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 60U)) + 12992483065443288263U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 3793854946371595197U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4244007978867369382U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 10280867500312580308U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13729899124177931289U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 472563452959164242U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12041770406895816553U;
            aOrbiterJ = RotL64((aOrbiterJ * 17811798500132002631U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6118634015704900486U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13637107920449233307U;
            aOrbiterA = RotL64((aOrbiterA * 17712028184714868053U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16673735670669318830U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 8602681273646630496U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6995213887710749241U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7683264695930369476U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9146674871199188218U;
            aOrbiterC = RotL64((aOrbiterC * 7403427067419261981U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 3012935612827493084U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1259789268731661945U;
            aOrbiterG = RotL64((aOrbiterG * 2372843620327050137U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5623690455471160780U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 18355567776031865462U;
            aOrbiterE = RotL64((aOrbiterE * 9553862670107886679U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 58U) + aOrbiterJ) + RotL64(aOrbiterD, 5U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 51U)) + aOrbiterD) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 19U)) + aOrbiterE) + aPhaseEWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 43U) + RotL64(aOrbiterE, 11U)) + aOrbiterA) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 44U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterG, 35U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 57U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
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

void TwistExpander_VolleyBall_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6404U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 161U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2445U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 900U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 6U)) ^ (RotL64(aCarry, 19U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 1866656689936219099U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 47U)) + 2312314528139448289U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 39U)) + 3554037526469185237U;
            aOrbiterA = (((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 405707755060974111U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (((aWandererE + RotL64(aIngress, 28U)) + RotL64(aCarry, 13U)) + 1862976326004007697U) + aPhaseFOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12992483065443288263U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3793854946371595197U;
            aOrbiterI = RotL64((aOrbiterI * 1819119223110966487U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4244007978867369382U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 10280867500312580308U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13729899124177931289U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 472563452959164242U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12041770406895816553U;
            aOrbiterA = RotL64((aOrbiterA * 17811798500132002631U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 6118634015704900486U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13637107920449233307U;
            aOrbiterD = RotL64((aOrbiterD * 17712028184714868053U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16673735670669318830U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 8602681273646630496U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6995213887710749241U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterE, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterD, 5U));
            aWandererI = aWandererI + (((RotL64(aIngress, 56U) + aOrbiterC) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 37U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterC, 47U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9099U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 10719U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11633U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((aIndex + 12211U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 50U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererJ + RotL64(aCross, 19U)) + 12222235191147985484U;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 16367317014523328414U) + aPhaseFOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 52U)) + RotL64(aCarry, 27U)) + 3511378091284703789U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 11U)) + 15247492830966725949U;
            aOrbiterD = (((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 39U)) + 7745995913390407897U) + aPhaseFOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 6463593307540108810U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1101669311005268630U;
            aOrbiterB = RotL64((aOrbiterB * 10550146460887359369U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12988052764067518580U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 17717179747434679772U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10820310705487638793U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 11662190906682400416U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6563014073547628748U;
            aOrbiterH = RotL64((aOrbiterH * 16967910471722117761U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 13099094932059419219U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16342730862261868847U;
            aOrbiterC = RotL64((aOrbiterC * 10988124108686164829U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16855346813127524624U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6570063128502306944U;
            aOrbiterF = RotL64((aOrbiterF * 4571570049463124831U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 41U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterC, 52U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterF, 13U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterB, 21U)) + aPhaseFWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 24U) + RotL64(aOrbiterH, 43U)) + aOrbiterF) + aPhaseFWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 3U)) + aOrbiterF) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 30U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19766U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 20764U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19614U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18850U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCarry, 19U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 23U)) + 10915618884692072446U) + aPhaseFOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aCross, 3U)) + 12634922308499254909U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 5U)) + 6533934734564499389U;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 6744203303756105181U) + aPhaseFOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aCross, 24U)) + 13086782386652045658U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 5693840533331397822U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1803663542535024611U;
            aOrbiterG = RotL64((aOrbiterG * 8511046986156781857U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 3597219300593287708U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 1429753448204448904U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10927459251773273143U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17229017825587322715U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1137574712801062932U;
            aOrbiterB = RotL64((aOrbiterB * 3645832160939819415U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2401991077004083378U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1332473247826139292U;
            aOrbiterD = RotL64((aOrbiterD * 15029831858261506447U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 11730946340796899885U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15319163439700390962U;
            aOrbiterJ = RotL64((aOrbiterJ * 1349242001887975499U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 48U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 57U)) + aOrbiterD) + aPhaseFWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterG, 37U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27861U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26191U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30454U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31981U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCarry, 56U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererD + RotL64(aIngress, 43U)) + 12380376990224645149U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 41U)) + 18296928500297384014U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 3550626816361145100U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 19U)) + 2667792936946706027U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (((aWandererB + RotL64(aIngress, 58U)) + RotL64(aCarry, 21U)) + 12020969779370926953U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 737340727886903447U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1681797651799760502U;
            aOrbiterJ = RotL64((aOrbiterJ * 11923920414802777451U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 2956186342689489064U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1876852870402977177U;
            aOrbiterG = RotL64((aOrbiterG * 8875540081346621757U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6433205819353555071U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 9065076854974222998U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5459675878087242021U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3254410578766789992U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2005081975473815576U;
            aOrbiterD = RotL64((aOrbiterD * 9947701153722014085U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 15992999234834560419U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 3458344156815120948U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1668460113964608051U), 37U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 40U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 11U)) + aOrbiterG) + aPhaseFWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 42U) + RotL64(aOrbiterA, 53U)) + aOrbiterG) + aPhaseFWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterD, 39U));
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterB, 22U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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

void TwistExpander_VolleyBall_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 658U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 594U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1832U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6109U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 37U)) + (RotL64(aCross, 4U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererF + RotL64(aScatter, 19U)) + 12311607308490066301U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 13100864684740679846U) + aPhaseGOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aIngress, 47U)) + 13697304189274329704U;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 28U)) + RotL64(aCarry, 51U)) + 9047976902871216732U) + aPhaseGOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 2147897579538537888U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2072444829390996142U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2129307836981020908U;
            aOrbiterE = RotL64((aOrbiterE * 8065769537670939667U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 10663145333751112064U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15019844390503785459U;
            aOrbiterC = RotL64((aOrbiterC * 7442321463110790449U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 5460865577557928142U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 15806522559993224197U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8722932687972240099U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6361113778657833389U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8306013884615042570U;
            aOrbiterD = RotL64((aOrbiterD * 8234258702656728667U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4038420580499706912U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 11908091484457158973U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3964111175645156719U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 54U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterF, 13U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 4U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + aPhaseGWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterI, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12325U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11818U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12930U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12480U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 4U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 13U)) + 14157904117287696136U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aPrevious, 47U)) + 7369512677371640676U;
            aOrbiterJ = (((aWandererF + RotL64(aCross, 37U)) + RotL64(aCarry, 13U)) + 8411250745902073798U) + aPhaseGOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 29U)) + 5002041814539710275U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 60U)) + RotL64(aCarry, 41U)) + 9538041410816283124U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5210700103927513061U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7600709399101287982U;
            aOrbiterJ = RotL64((aOrbiterJ * 6777896926889560889U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2366369466696580499U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5544575244203019109U;
            aOrbiterC = RotL64((aOrbiterC * 16231219246786333057U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 8710073749110329779U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 15998211310115361630U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15275657696897688955U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 15354357553877376422U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 10657523549259276169U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13695239532898311073U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10405750198355464768U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3465819693133515142U;
            aOrbiterI = RotL64((aOrbiterI * 14678343718277562799U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterI, 41U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 5U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 54U) + aOrbiterI) + RotL64(aOrbiterE, 23U));
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterG, 54U)) + aPhaseGWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererJ, 4U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 18119U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneD[((aIndex + 19978U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21912U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((aIndex + 17356U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 21U)) + (RotL64(aIngress, 54U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 19U)) + 4848316479321533394U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 35U)) + 6919360256662636195U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 27U)) + 9897013582181108544U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 7319353809896158678U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 4U)) + RotL64(aCarry, 5U)) + 2848175435514849859U) + aPhaseGOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6967780718720437934U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 10143884766603388136U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17346772745745835895U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 8675965006150972051U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16350117755560994281U;
            aOrbiterI = RotL64((aOrbiterI * 15072308930382994425U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17976597517118423760U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1399631141355370237U;
            aOrbiterB = RotL64((aOrbiterB * 16537788276543236833U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 3590613762034716792U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5134624314245932157U;
            aOrbiterD = RotL64((aOrbiterD * 13077589037975283371U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 10082236952942943654U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4015535035905433450U;
            aOrbiterK = RotL64((aOrbiterK * 4961808568701908559U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterF, 39U)) + aOrbiterD) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 18U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 4U) + aOrbiterI) + RotL64(aOrbiterF, 47U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterD, 57U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 30761U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25772U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31221U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 28496U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 29U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 42U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 5160910997561396461U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 11U)) + 14920764751058512062U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 20U)) + 6080952401749660022U) + aPhaseGOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 17667234330526298627U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 760630072638686756U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3504157162816997476U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 9489022223422585882U;
            aOrbiterK = RotL64((aOrbiterK * 2398110457196177747U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1149898536879968964U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 10492284328940025310U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7893416766300156495U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13213275606286399312U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 10557118912847180413U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10077877991284587845U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15618980209023994776U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5268600749854045564U;
            aOrbiterA = RotL64((aOrbiterA * 3849660559223919613U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 8011552687609649990U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 3148133096349525066U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5245156554959620007U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterD, 13U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 37U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterA, 3U)) + aPhaseGWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterA, 24U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 4U));
            aCarry = aCarry + RotL64(aWandererF, 21U);
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

void TwistExpander_VolleyBall_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 4827U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1547U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4838U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3430U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 11U) + RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 28U)) + RotL64(aCarry, 27U)) + 16922357079016918108U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 11771749797137599131U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 57U)) + 4635668433708036077U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 51U)) + 15827952719230577008U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 39U)) + 1495675306110023086U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 7294835466949728365U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 179122461212041978U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14467072888722097971U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 545981421632236251U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15338259639814630535U;
            aOrbiterC = RotL64((aOrbiterC * 14895421566334357871U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12924313840290895215U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17846785921286020610U;
            aOrbiterF = RotL64((aOrbiterF * 18309347016029917133U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 5721472794107057875U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16359630793856870319U;
            aOrbiterB = RotL64((aOrbiterB * 14186771515526698907U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10614102110239037308U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 16421992251278236531U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2561232904676068089U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 27U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 38U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 36U) + aOrbiterA) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterF, 37U)) + aPhaseHWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 23U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 58U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterF, 13U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15073U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((aIndex + 16163U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14129U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8281U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 11U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 13924571355038625040U;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 16328300979357156658U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 39U)) + 3947771961206012461U;
            aOrbiterG = (((aWandererH + RotL64(aIngress, 6U)) + RotL64(aCarry, 53U)) + 15428284250569311285U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aCross, 27U)) + 5777369485254032486U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16813320300717644673U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 16689933050200758251U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4832495563863469353U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 1856422419049390708U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 18214498743831925517U;
            aOrbiterH = RotL64((aOrbiterH * 10744120577560529379U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 18278550878494094923U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 797712062039591797U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7212998747080137625U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15854849439012341347U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 996882939768167773U;
            aOrbiterJ = RotL64((aOrbiterJ * 14936703950807908575U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3005829974130671692U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8793495343509953906U;
            aOrbiterG = RotL64((aOrbiterG * 14065479348374612031U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 35U)) + aOrbiterI) + aPhaseHWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 43U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 13U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 23U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 52U) + RotL64(aOrbiterC, 58U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 52U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 22388U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22506U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17950U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneB[((aIndex + 19155U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCross, 5U)) + (RotL64(aIngress, 26U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (((aWandererA + RotL64(aIngress, 56U)) + RotL64(aCarry, 39U)) + 17711946802293254150U) + aPhaseHOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 16652362590489569378U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 5U)) + 6972810344198183097U;
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 13U)) + 13117100889782940546U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aCross, 39U)) + 13199305696782626591U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 992156184392760945U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 13791265442074543880U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1263919538622722673U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17057087245252294859U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13444195995883541046U;
            aOrbiterA = RotL64((aOrbiterA * 13067044288608808777U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 6723678233676059420U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7913379431208430475U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2295062944289127123U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 4481887195529300665U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11892724101424384078U;
            aOrbiterD = RotL64((aOrbiterD * 3468639499716604111U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7700902083270424194U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1888001433557140271U;
            aOrbiterE = RotL64((aOrbiterE * 8975562955027025349U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterF, 56U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 23U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterI, 3U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 13U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 54U) + RotL64(aOrbiterI, 35U)) + aOrbiterD) + aPhaseHWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 32047U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32676U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27102U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((aIndex + 25857U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 50U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 9471546960258473684U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 51U)) + 18050235435948942244U;
            aOrbiterF = (((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 3005107102671544641U) + aPhaseHOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aIngress, 14U)) + RotL64(aCarry, 51U)) + 17898396434573801850U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 23U)) + 15071602525497771648U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5780119462702672108U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13301326224151025687U;
            aOrbiterF = RotL64((aOrbiterF * 2868878978993219351U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 18129323022260575961U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1199228670638790709U;
            aOrbiterJ = RotL64((aOrbiterJ * 1780426336211781025U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 1839199978088021020U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 4999517042246790165U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4585813675677234577U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8788607633376516299U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15143903839930468749U;
            aOrbiterA = RotL64((aOrbiterA * 12735914889325422675U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16674732686428431869U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15908873150953195581U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18049755517524334107U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 58U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 37U) + RotL64(aOrbiterF, 23U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterJ, 50U));
            aWandererF = aWandererF + (((RotL64(aScatter, 58U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterF, 41U));
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
