#include "TwistExpander_Karate_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Karate_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF071CFC1F9333405ULL + 0xB7D5527AA66ADFC0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8C1C5AA15B24D9EFULL + 0xB180C2AF2578E91FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9B7686E26F3E1ACBULL + 0xACE7FCEA073DAFE9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xFFDCA2F6ACD480B9ULL + 0xC6F93C4291C82B51ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD262FCF4FC30FEFBULL + 0xC359FFDE00AC4DB3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9D5392820CE156E5ULL + 0xB5E440FE95A372CBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD87F396F0944E08FULL + 0xF9856AC37C95E4F2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE76D9D36CF6F8523ULL + 0xFB6717231D4F4D56ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xE8E4D9506D694D75ULL + 0xCE46F99588E28A0BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA52D810C54175F6FULL + 0xA834A394E9374E75ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x810268E74D8B9641ULL + 0x9D5DB08B95044A34ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD74FC2EB6048C7E9ULL + 0xCE014A0D6227A217ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE12F704BD1957A11ULL + 0xC4E1B82AAC3AA687ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCEE9FD0669E2591FULL + 0xF67CC55389F79C44ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB775F8F513EA3E9FULL + 0xFF3975715D170412ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF6FFEB47FB58652DULL + 0x873BC7586C9DDA1DULL);
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
        // read from: mSource, pSnow, aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_a_loop_a loop 1
        // read from: mSource, pSnow
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5086U)) & S_BLOCK1], 11U) ^ RotL64(pSnow[((aIndex + 3951U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 1744U)) & S_BLOCK1], 53U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 97U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 24U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererH + RotL64(aScatter, 26U)) + 18302975933754610273U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 47U)) + 16736972646771456082U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 21U)) + 17389406266488137442U) + aOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 39U)) + 5252511566486165539U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aIngress, 23U)) + 5730715427422747640U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 13U)) + 6412695646456045825U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 13U)) + 9539701605708994494U;
            aOrbiterG = (aWandererA + RotL64(aCross, 57U)) + 18355107116412945722U;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 37U)) + 11735742491750132942U) + aNonceWordL;
            aOrbiterK = (aWandererE + RotL64(aScatter, 41U)) + 12363819388562658842U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 34U)) + RotL64(aCarry, 47U)) + 5861430292304371543U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15027487084595017708U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7012850020745791926U;
            aOrbiterJ = RotL64((aOrbiterJ * 15952928839355613939U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 11904871669287886120U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11199760114477343208U;
            aOrbiterF = RotL64((aOrbiterF * 7156374911847525867U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3856004502263742700U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3705931243173921893U;
            aOrbiterC = RotL64((aOrbiterC * 10334871178498711485U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 12305785390539209389U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 18057980996551978823U;
            aOrbiterB = RotL64((aOrbiterB * 4850564181113470859U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3229431819292153014U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 2994716629242460094U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1029427328395257917U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9796307843453735512U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2957260393651252432U;
            aOrbiterD = RotL64((aOrbiterD * 7261055869794739609U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4060469664218866340U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterI) ^ 17462081697889685330U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 7712009170974461225U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13638660073917821172U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15202349592659062565U;
            aOrbiterH = RotL64((aOrbiterH * 4514326257446024301U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12071949111168967041U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11930843273199806728U;
            aOrbiterI = RotL64((aOrbiterI * 16229663295689525137U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 11294220104731500296U) + aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 440743185210586759U;
            aOrbiterG = RotL64((aOrbiterG * 14810195235168807229U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8514240764798061804U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 18302975933754610273U;
            aOrbiterK = RotL64((aOrbiterK * 1972439346780950873U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 12U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 10U) + aOrbiterH) + RotL64(aOrbiterF, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ) + aWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterA, 41U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 47U)) + aOrbiterK) + aNonceWordF);
            aWandererA = aWandererA + ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterA, 21U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 19U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aScatter, 28U) + RotL64(aOrbiterD, 6U)) + aOrbiterA) + aNonceWordC) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterH, 51U));
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + aNonceWordA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 12U)) + aOrbiterA) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 40U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 12U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordO;
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 2
        // read from: aWorkLaneA, mSource, pSnow
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8096U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((aIndex + 6350U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 6365U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8594U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 4U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererH + RotL64(aCross, 30U)) + RotL64(aCarry, 19U)) + 9041099828460168106U;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 23U)) + 12883711604096848454U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (aWandererB + RotL64(aIngress, 51U)) + 17420968786226443079U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 13U)) + 3448213891716125104U) + aNonceWordM;
            aOrbiterC = (aWandererC + RotL64(aCross, 19U)) + 11866455977445336560U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 21U)) + 4119356835384495905U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 5U)) + 2186212599698637068U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 29U)) + 6506144898969301620U) + aNonceWordG;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 12556800923644051626U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 56U)) + 4075551535185182945U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 47U)) + 17877694808492008749U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5553428900598223316U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14362304852277160675U;
            aOrbiterD = RotL64((aOrbiterD * 11415103199856419303U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9174200302876075831U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16110739511917638547U;
            aOrbiterI = RotL64((aOrbiterI * 7004356839428657949U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10189881974519849402U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 2128076632642616677U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8860453653433114929U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 18133523799074400083U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9916472958834153766U;
            aOrbiterF = RotL64((aOrbiterF * 3454601168808001733U), 21U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 10274457562795569227U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14134814273275356425U;
            aOrbiterG = RotL64((aOrbiterG * 15912501063665343159U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6394306369514735480U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4825761192736485643U;
            aOrbiterJ = RotL64((aOrbiterJ * 12534544147331805643U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5672807934779206275U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 3881953574159390421U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7448770570912161095U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12012232712634303203U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14176392925893052596U;
            aOrbiterA = RotL64((aOrbiterA * 11288668529893084583U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 307148402076391033U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 15380446373458263079U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 15228462337097647933U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4654312690816676129U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 10818029316701301859U) ^ aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16245734506125913215U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7340370713289840635U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9041099828460168106U;
            aOrbiterK = RotL64((aOrbiterK * 1807356802142268373U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterB, 5U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterH, 13U)) + aOrbiterF) + aNonceWordI);
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 60U)) + aOrbiterH) + aWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 26U) + aOrbiterJ) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterK, 57U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterD, 37U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterA, 35U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 40U) + aOrbiterD) + RotL64(aOrbiterC, 53U)) + aNonceWordA);
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterI, 24U));
            aWandererH = aWandererH + ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterE, 19U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 6U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordP);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 3
        // read from: aWorkLaneB, aWorkLaneA, mSource, pSnow
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14446U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15268U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 16242U)) & S_BLOCK1], 19U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 13717U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 60U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererG + RotL64(aIngress, 37U)) + 2168513956284366370U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 10290361969974613111U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 4U)) + RotL64(aCarry, 29U)) + 15673836275828498050U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 39U)) + 16600540024145812236U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 53U)) + 9428052101528111892U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 51U)) + 12763657928312763377U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aCross, 23U)) + 10751286982008662485U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 11U)) + 1708230173038057979U) + aNonceWordN;
            aOrbiterC = (aWandererB + RotL64(aCross, 29U)) + 4011389705422783816U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 44U)) + 11704428328093077714U;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 2055336619674699284U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 1870865272102705804U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3574214263751923179U;
            aOrbiterI = RotL64((aOrbiterI * 13132083406834413563U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 984611970726966186U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15207945449947643672U;
            aOrbiterE = RotL64((aOrbiterE * 9539470161576639981U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4181398506373973169U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15222345431506025949U;
            aOrbiterH = RotL64((aOrbiterH * 6925143692628659467U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15023513452326240962U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14965669361708810699U;
            aOrbiterJ = RotL64((aOrbiterJ * 587008860996713147U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7985755518735406360U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 225592097619240187U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 2313509354133400439U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 3659537916566939383U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17043668033610689611U;
            aOrbiterK = RotL64((aOrbiterK * 10797634709118100773U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10217321522161675848U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 8013663869536146842U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2293233079384777175U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13762445330867496042U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2692400019659269106U;
            aOrbiterG = RotL64((aOrbiterG * 167704184292219399U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 18232551682424867647U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 14785847596876239854U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4569180925037758487U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5910282247522389536U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16556038638738871204U;
            aOrbiterC = RotL64((aOrbiterC * 18356922295088260901U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 141620663839815754U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2168513956284366370U;
            aOrbiterD = RotL64((aOrbiterD * 8605382725635471683U), 39U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 54U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 44U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterE, 11U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterD, 21U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterI, 37U)) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 58U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterI, 43U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterF, 35U));
            aWandererC = aWandererC + (((((RotL64(aIngress, 18U) + aOrbiterJ) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 35U)) + aNonceWordH) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterK, 41U)) + aNonceWordO);
            aWandererB = aWandererB + ((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterI, 50U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 20U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 56U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordO);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 4
        // read from: aExpandLaneA, aWorkLaneB, aWorkLaneA, mSource
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19176U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 21108U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17161U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 16878U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 47U)) + (RotL64(aCross, 13U) + RotL64(aPrevious, 60U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 23U)) + 5573188770530340913U) + aNonceWordJ;
            aOrbiterI = ((aWandererC + RotL64(aCross, 48U)) + RotL64(aCarry, 29U)) + 1431772230889897111U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 19U)) + 4809192776429682319U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 11U)) + 5576603692574369341U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 13U)) + 2720143226007220386U) + aNonceWordC;
            aOrbiterB = (aWandererD + RotL64(aIngress, 27U)) + 17220328778565331629U;
            aOrbiterG = (aWandererI + RotL64(aCross, 37U)) + 9629485808442089423U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 41U)) + 1136998437010390983U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 4U)) + 11893390497814523841U;
            aOrbiterC = (((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 37U)) + 1764986431917532370U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 1741014798007010376U) + aOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 12221368453236547044U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 7694538641172350430U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8439120733670016501U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17472344518811560603U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3308740700728172984U;
            aOrbiterF = RotL64((aOrbiterF * 15290400462887712083U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9535358833412446771U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11192312491731312451U;
            aOrbiterB = RotL64((aOrbiterB * 17405609148475445743U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14850451970047190039U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11932493299452443256U;
            aOrbiterG = RotL64((aOrbiterG * 7964808728820467795U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5972619895614731870U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17174497535809891690U;
            aOrbiterA = RotL64((aOrbiterA * 15471084511364572533U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17412894714378898351U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14675615208706549810U;
            aOrbiterD = RotL64((aOrbiterD * 7864845089606499769U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 16116792108013658523U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9702262005960966336U;
            aOrbiterC = RotL64((aOrbiterC * 970452849653781703U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17337264966818542841U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7004462033775827275U;
            aOrbiterE = RotL64((aOrbiterE * 11943575980344402681U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 17499850384482055438U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 1839357713256560566U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 12943750650487416281U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8144238113917577524U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 888195876227325908U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7941506708630993709U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5081763359501717653U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5573188770530340913U;
            aOrbiterK = RotL64((aOrbiterK * 9699901099898698965U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 18U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterK, 4U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterC, 43U));
            aWandererH = aWandererH + ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 21U)) + aOrbiterF);
            aWandererC = aWandererC ^ (((RotL64(aCross, 50U) + aOrbiterK) + RotL64(aOrbiterE, 53U)) + aNonceWordE);
            aWandererI = aWandererI + ((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterB, 48U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 39U)) + aOrbiterI) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 35U)) + aOrbiterA);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 26U) + aOrbiterF) + RotL64(aOrbiterI, 41U)) + aNonceWordI);
            aWandererB = aWandererB + ((((RotL64(aCross, 29U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ) + RotL64(aCarry, 39U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 27U)) + aOrbiterD) + aWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 51U)) + aOrbiterF) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = aCarry ^ aNonceWordO;
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 5
        // read from: aExpandLaneB, aExpandLaneA, aWorkLaneB, aWorkLaneA
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26026U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25919U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23762U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 26706U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 36U) ^ RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 14179205183062705133U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 48U)) + 210032324058740920U) + aNonceWordC;
            aOrbiterG = (aWandererD + RotL64(aScatter, 41U)) + 7387115089142500152U;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 17583362781238061430U) + aNonceWordB;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 4991442849150005943U) + aNonceWordP;
            aOrbiterI = ((aWandererF + RotL64(aCross, 3U)) + 2891376254689854555U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aScatter, 34U)) + 10523274382407446239U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 51U)) + 3861893764676218667U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 29U)) + 3366674459852093746U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 5U)) + 5898492634386601145U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 53U)) + 7047353571244768721U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14374108805453186316U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8763667021501226510U;
            aOrbiterG = RotL64((aOrbiterG * 7694695426430267863U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 18261523829316379575U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 650477532238860965U;
            aOrbiterI = RotL64((aOrbiterI * 8291758490821819851U), 11U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 2162326554604894042U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5776546692501825278U;
            aOrbiterA = RotL64((aOrbiterA * 14911545784585246537U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3501863793638415049U) + aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14853789267425352958U;
            aOrbiterC = RotL64((aOrbiterC * 10590325397179928739U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15399673014671329743U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 12253428583438990426U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12052855472196447849U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13202953937621953839U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 7547616636832698398U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 9533399972562428073U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15709801946594868318U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12458677982746610971U;
            aOrbiterF = RotL64((aOrbiterF * 6662570874316418993U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6957370791367530127U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10511379961344950861U;
            aOrbiterD = RotL64((aOrbiterD * 15551333099264031337U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16489828646914719181U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6827290294344770680U;
            aOrbiterK = RotL64((aOrbiterK * 6408864925398536651U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3308531598034561099U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10336568208337990458U;
            aOrbiterE = RotL64((aOrbiterE * 5606941634846696657U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14116471880098183908U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 14179205183062705133U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 8824119255416045191U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (RotL64(aOrbiterK, 46U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 51U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 27U)) + aOrbiterJ);
            aWandererK = aWandererK ^ (((RotL64(aCross, 6U) + RotL64(aOrbiterI, 14U)) + aOrbiterG) + aWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 5U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterI, 37U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 57U)) + aOrbiterG) + RotL64(aCarry, 21U)) + aNonceWordL);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 53U)) + aOrbiterB) + aNonceWordN) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 39U)) + aOrbiterE);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 21U)) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 12U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 40U) + aOrbiterK) + RotL64(aOrbiterG, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 34U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordN;
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 6
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneB
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32114U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 27356U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32004U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30422U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCarry, 12U) ^ RotL64(aIngress, 29U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 12690502671561165478U) + aOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aScatter, 39U)) + 17519943923428102801U;
            aOrbiterH = (aWandererH + RotL64(aCross, 28U)) + 10705515807975331385U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 23U)) + 16586447272278538179U) + aNonceWordJ;
            aOrbiterD = (aWandererB + RotL64(aCross, 57U)) + 8006560996840971798U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 21U)) + 12928600185788857701U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 19U)) + 14240723153798267172U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 13U)) + 8636219177994872072U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 42U)) + RotL64(aCarry, 57U)) + 7586790235186467512U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 19U)) + 1103807034179512424U) + aNonceWordH;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 3U)) + 7547526530239498693U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8380239679344786397U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 5690809173787433519U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5354724308093372953U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8390902801141804609U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3507306189192059486U;
            aOrbiterD = RotL64((aOrbiterD * 18336280496510253103U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 6190745292098482871U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8065418693975056902U;
            aOrbiterF = RotL64((aOrbiterF * 6414621418430102589U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12111755051718111803U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7605877769709909297U;
            aOrbiterE = RotL64((aOrbiterE * 17525248694315944599U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5969794501112646237U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5127559299360591476U;
            aOrbiterC = RotL64((aOrbiterC * 4521563633438853069U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10593847754747739786U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4401750688524310121U;
            aOrbiterJ = RotL64((aOrbiterJ * 14265829318976633707U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6927893132508779499U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4874009978647014479U;
            aOrbiterG = RotL64((aOrbiterG * 13340466017023540755U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 13146693487138744677U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 3298472134223595298U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 2145005258008477281U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8729305340729268734U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 18347161842033439538U;
            aOrbiterK = RotL64((aOrbiterK * 7952715248988302017U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 166831495912855225U) + aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 4943633045563697271U) ^ aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1809857625425000137U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2460623715340753589U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12690502671561165478U;
            aOrbiterA = RotL64((aOrbiterA * 16421139715633515623U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 6U) + aOrbiterD) + RotL64(aOrbiterC, 27U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 41U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterH, 13U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 37U)) + aOrbiterE) + aNonceWordB);
            aWandererE = aWandererE + (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 48U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 51U)) + aOrbiterK) + aNonceWordD);
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 50U) + RotL64(aOrbiterJ, 53U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterD, 34U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterF, 19U)) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 18U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordG;
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Karate_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9D6F49CAAE8B9F13ULL + 0xD8EAF29AD6581472ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC2BDF2473155575FULL + 0x8C1D69D3B17A3083ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD33A97E2B74AFC43ULL + 0xD5C1E931FACDF0D9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA3602CF028F1AB85ULL + 0xC4DE0040BBD08612ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDB5CCB4B1CEC0E15ULL + 0xA17C5F3202B84EF5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xED22E700DE0001D5ULL + 0xE4F6AF954B20C32BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9D4A39A0511278A1ULL + 0xCD864D8D87BFFBC2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE5792F28F95C1FF5ULL + 0xB7EBDA4C6C009BC9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF75D90FB202E6F03ULL + 0xB2EB5798181F6D2BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9E2E1A8FBD6EB1D1ULL + 0xEB8AE4F801C46F9EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA78CA7754BBDB6D1ULL + 0xF9B8BDAE1488CB6CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF36795DFEC35FA5BULL + 0xA0C4CD2E26CA34AAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8C2EB790AB1EAF85ULL + 0x94D8AE3A9BDDF68AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC07BD3934335A6C3ULL + 0xB83069DBD86EE1FCULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD6B6A6A887A9F17DULL + 0x9784F15C12ED2DADULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE327E999A851E67BULL + 0xEF0AE0C222768DA0ULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5016U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((aIndex + 1574U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4191U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3684U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 35U)) + (RotL64(aCross, 60U) ^ RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aIngress, 14U)) + 4848316479321533394U) + aOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 6919360256662636195U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 23U)) + 9897013582181108544U;
            aOrbiterI = (((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 43U)) + 7319353809896158678U) + aNonceWordH;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 57U)) + 2848175435514849859U) + aNonceWordI;
            aOrbiterG = (aWandererH + RotL64(aIngress, 43U)) + 6967780718720437934U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 23U)) + 10143884766603388136U) + aOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aScatter, 34U)) + 8675965006150972051U;
            aOrbiterE = (aWandererK + RotL64(aCross, 29U)) + 16350117755560994281U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17976597517118423760U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1399631141355370237U;
            aOrbiterD = RotL64((aOrbiterD * 16537788276543236833U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3590613762034716792U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5134624314245932157U;
            aOrbiterG = RotL64((aOrbiterG * 13077589037975283371U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10082236952942943654U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 4015535035905433450U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 4961808568701908559U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 611474103801573800U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5786708483794098001U;
            aOrbiterE = RotL64((aOrbiterE * 7694007039340089267U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 5201943497363274455U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 9282160506938328489U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5368182164239021367U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 4932320527498940158U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11576526341731392916U;
            aOrbiterI = RotL64((aOrbiterI * 1712051774729439363U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10790691517638887125U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16280649213607464422U;
            aOrbiterH = RotL64((aOrbiterH * 10756733801499471873U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9553716940667712810U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 11827518270964003341U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1322489827908132831U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16777463701235809321U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3375489084588454149U;
            aOrbiterC = RotL64((aOrbiterC * 3335010977457647307U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 60U);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 6U) + aOrbiterG) + RotL64(aOrbiterA, 53U));
            aWandererB = aWandererB + ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 43U)) + aOrbiterH);
            aWandererC = aWandererC ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 10U)) + aOrbiterA) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 57U)) + aOrbiterI) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 27U)) + aOrbiterC);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 39U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aNonceWordA);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 34U) + aOrbiterG) + RotL64(aOrbiterH, 19U));
            aWandererF = aWandererF + (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 47U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 4U)) + aOrbiterH) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 26U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13067U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8454U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8349U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12146U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 40U) ^ RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererI + RotL64(aCross, 35U)) + 7270044678408187242U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 14U)) + RotL64(aCarry, 51U)) + 10192278965379756766U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 53U)) + 17568666746676060748U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 11U)) + 14312927531124963037U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 57U)) + 9825825726152087706U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aIngress, 30U)) + 9696778570255265896U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 21U)) + 17657841352013417228U;
            aOrbiterF = (((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 3U)) + 16207815085909628439U) + aOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 5U)) + 1752979206374514227U) + aNonceWordO;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10456310689643905854U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 16127830548663742550U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4355938404839045417U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2940917376003930842U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 7353596864777649953U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7499468723171042005U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12725092740446150705U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 5791296650856037010U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 760379251950502133U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1200130368046206150U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16689604428598558547U;
            aOrbiterF = RotL64((aOrbiterF * 13815324235939996623U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14359561591103730856U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3975025843599045263U;
            aOrbiterC = RotL64((aOrbiterC * 5025047888533298617U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14017901732955607601U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10431526786489555196U;
            aOrbiterI = RotL64((aOrbiterI * 10181915874476132407U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7320527073559849223U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15333411223710709907U;
            aOrbiterA = RotL64((aOrbiterA * 3488684905528068775U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14302474063321663801U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2104154521019935187U;
            aOrbiterG = RotL64((aOrbiterG * 12944382959742278055U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5167600586916325228U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 4566823109447208716U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9997799807454267443U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 28U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 56U) + aOrbiterC) + RotL64(aOrbiterG, 10U)) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterE, 39U));
            aWandererI = aWandererI + (((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterD, 47U)) + aNonceWordI);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterJ, 19U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterC, 34U)) + RotL64(aCarry, 53U)) + aNonceWordK);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 27U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aCross, 18U) + aOrbiterF) + RotL64(aOrbiterB, 51U)) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 5U));
            aWandererH = aWandererH + (((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordK);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 17042U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18171U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21076U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 21770U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 53U)) + (RotL64(aCarry, 11U) ^ RotL64(aIngress, 38U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 7896237440058555694U;
            aOrbiterK = (aWandererG + RotL64(aCross, 56U)) + 11870529476037558635U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 47U)) + 9158983227801569448U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 29U)) + 4710172270996950329U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 5U)) + 14634482800356647630U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aIngress, 43U)) + 8822207952170610891U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 38U)) + RotL64(aCarry, 51U)) + 13755891414028982553U;
            aOrbiterH = ((((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 4555293067488040719U) + aOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 13U)) + 2816805148093762081U) + aNonceWordP;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 2122631477965135190U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 4592922416380416071U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11644507904538573165U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7102471666524164715U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 17274623547879474204U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 5443572270546181789U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 938587316977094680U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 18258015823797023523U;
            aOrbiterF = RotL64((aOrbiterF * 6068819567674605919U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5809987756043471595U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5083075160112581620U;
            aOrbiterK = RotL64((aOrbiterK * 3313957222154937503U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5960021727750946496U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5967477320950630150U;
            aOrbiterG = RotL64((aOrbiterG * 330964768256424655U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6578428711689296132U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5601728218197771276U;
            aOrbiterA = RotL64((aOrbiterA * 9552559022315971847U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7923809409017855241U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 16479366540906497019U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7118578387798460919U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17000467091738009736U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6801634573655508028U;
            aOrbiterH = RotL64((aOrbiterH * 10584635770060137089U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 123668445682719574U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 14462802805503986316U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 12398236364304875941U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 26U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 51U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 10U) + aOrbiterG) + RotL64(aOrbiterK, 39U)) + aNonceWordH);
            aWandererI = aWandererI + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 14U)) + aOrbiterB) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 35U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 29U)) + aOrbiterH) + aNonceWordF);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 47U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aCross, 58U) + RotL64(aOrbiterA, 43U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aNonceWordC);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 60U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 5U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererG, 40U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28594U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneB[((aIndex + 30436U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31485U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 28767U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 37U)) ^ (RotL64(aCross, 51U) ^ RotL64(aIngress, 24U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 5576732410244514238U;
            aOrbiterB = (aWandererA + RotL64(aCross, 41U)) + 2833808925935929629U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 3670188682914544792U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 12U)) + 15759072378887814995U) + aNonceWordH;
            aOrbiterK = (aWandererI + RotL64(aCross, 29U)) + 13934007231137439994U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 3U)) + 11022225696007690512U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 35U)) + 16989177104453635790U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 60U)) + RotL64(aCarry, 43U)) + 9256930045263527091U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 51U)) + 17788596104417068290U) + aNonceWordB;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 17044369456673337625U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1310908395523250343U;
            aOrbiterE = RotL64((aOrbiterE * 16305084373037705921U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12067065689034065422U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15130844248737512262U;
            aOrbiterK = RotL64((aOrbiterK * 9409499577465934107U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14532689204495587494U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8198147292120244178U;
            aOrbiterC = RotL64((aOrbiterC * 1418356389507740991U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 5485494458627163347U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10830008207150307611U;
            aOrbiterI = RotL64((aOrbiterI * 6526039534042499457U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17770065502486618029U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6397859353395335459U;
            aOrbiterA = RotL64((aOrbiterA * 14286997752368893825U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5128700697381508319U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 7103394110057060499U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 5053680689949149633U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16024401282261796979U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12818445221897253410U;
            aOrbiterD = RotL64((aOrbiterD * 11450004517784155405U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 13386978409145916350U) + aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16740821954556699503U;
            aOrbiterJ = RotL64((aOrbiterJ * 5376430209628515105U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 313978038530994953U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1355733685461795345U;
            aOrbiterB = RotL64((aOrbiterB * 15955927322082619735U), 39U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 11U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 58U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 10U) + RotL64(aOrbiterI, 21U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterB, 27U));
            aWandererG = aWandererG + ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterE, 43U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterF, 60U));
            aWandererI = aWandererI + ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterK, 13U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 39U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 35U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 56U)) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 14U) + aOrbiterC) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 53U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordC);
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

void TwistExpander_Karate_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC89400A4A81BDAEDULL + 0xA375DAD4B59D6069ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA07683FAC849D155ULL + 0x867A2D463E4DBF73ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA2F536352FEC26FFULL + 0xBC31A3CAF071F004ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9DEBB05AEA283A25ULL + 0x845C82DCA45A43ADULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA8094F7A7BEB8207ULL + 0xFD8EED8C985E12ACULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB52DD1ADD1626007ULL + 0xB2A75FC4C96281C9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAD4E2ADCAC1E8BEBULL + 0xB4221B0B87E793CBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x85F2FF913968B80DULL + 0xB071B6886721C081ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB5C842D5D3C19F21ULL + 0xE2B891B24AF0ED82ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xED55AFD60C086FEBULL + 0xE7AB1CC6736F91A0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBCA812A38230E485ULL + 0x845C635EC13C43BAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB3C58FF4ACFA9641ULL + 0x8A59FE8D43E42CA7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA1ACF3E49C006649ULL + 0xD3C702E35D0E2F6FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xAD0ED8DD708F85E9ULL + 0x8A02765B94FCEEB3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9D3B6851B8BD477FULL + 0x85B11EA2B23A9383ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x965F5C37516F6FBFULL + 0x93DB0EC74568C590ULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4121U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 3586U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7143U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2824U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 6U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 7960325128608297381U) + aNonceWordB;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 35U)) + 12773836012104052042U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 3173972621347773016U) + aNonceWordA;
            aOrbiterA = (aWandererD + RotL64(aCross, 18U)) + 3708401356314308171U;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 950774285720019449U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4170092315705438265U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17000449130864980747U;
            aOrbiterB = RotL64((aOrbiterB * 7710635557693533263U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8793910540062893860U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 520277969543516469U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 4150613128885828229U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 12762214857389827271U) + aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 2932451184340207695U) ^ aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7513337346940091655U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11062179998786293839U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7919119215271524178U;
            aOrbiterK = RotL64((aOrbiterK * 9053677007180081359U), 21U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 1774988449597115155U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3799792889466518953U;
            aOrbiterE = RotL64((aOrbiterE * 17512791286490623455U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 4U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 35U)) + aOrbiterE) + aNonceWordO) + aWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 56U) + aOrbiterI) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 5U)) + aNonceWordE);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 57U)) + aOrbiterE) + aNonceWordH) + aWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterE, 46U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererC, 38U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15100U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14815U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14492U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14728U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 4U) + RotL64(aCross, 47U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererK + RotL64(aIngress, 12U)) + RotL64(aCarry, 53U)) + 6342299552323486695U) + aNonceWordC;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 29U)) + 12692748514781367538U) + aNonceWordJ;
            aOrbiterK = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 8202639945493229155U;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 4439975701793231639U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (((aWandererJ + RotL64(aCross, 21U)) + 16774235182859553759U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 8764155413335405667U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7167848811974967685U;
            aOrbiterK = RotL64((aOrbiterK * 1052856924757654735U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16768278912125334220U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 9090838954826296201U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5459329624017272077U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 7644075729758006298U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 17326182797908071215U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2408330168749256075U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16158809721888137555U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8029938783858263694U;
            aOrbiterC = RotL64((aOrbiterC * 12628072435324195483U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8716553521415553404U) + aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7012599977009208840U;
            aOrbiterF = RotL64((aOrbiterF * 8775355876188948851U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 18U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterF, 42U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterE, 53U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 27U)) + aOrbiterF) + aWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 3U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24495U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21226U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17227U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18662U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 37U)) ^ (RotL64(aIngress, 6U) + RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 1142447269198373880U) + aNonceWordD;
            aOrbiterB = (((aWandererC + RotL64(aCross, 14U)) + 10581460640040336191U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 14703062773878202900U) + aNonceWordI;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 43U)) + 15737525756286914746U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aCross, 37U)) + 16178774478273186999U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 2514897053906809160U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 13702496607592508464U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 16540143680974064057U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 18030885275418337965U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 5241783876161655984U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10970981186787227937U), 21U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 2807052676283587925U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8022804576763271327U;
            aOrbiterH = RotL64((aOrbiterH * 11727096043219370577U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15597099852232205860U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1538435607932096400U;
            aOrbiterA = RotL64((aOrbiterA * 7900752511710516981U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11147868774413615365U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9325213746830411568U;
            aOrbiterI = RotL64((aOrbiterI * 561819005818948769U), 39U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterI, 5U)) + aNonceWordG);
            aWandererC = aWandererC + ((((RotL64(aCross, 12U) + RotL64(aOrbiterJ, 41U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterH, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26973U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27857U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25309U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 25807U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 37U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 4U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 8685374557928800912U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 6U)) + 3482312691892161229U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 6948130297389161165U) + aNonceWordE;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 27U)) + 5506385663788942690U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 19U)) + 17859982009307397161U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 9178488809207094043U) + aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1835479501226057169U;
            aOrbiterD = RotL64((aOrbiterD * 5671861318767342087U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5368101733632614939U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9050459666576835422U;
            aOrbiterB = RotL64((aOrbiterB * 10351719549990259551U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 9042186993119635078U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17528342580198295025U;
            aOrbiterA = RotL64((aOrbiterA * 14316671546614386775U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6495418332558436882U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8834495762667327342U;
            aOrbiterK = RotL64((aOrbiterK * 10783141541937645995U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 4364314196965690905U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 6357485231062120459U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 289429584586504995U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 6U);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 47U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 3U)) + aOrbiterD) + aNonceWordK);
            aWandererI = aWandererI + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterB, 39U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterK, 58U));
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterI, 11U)) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 56U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordM;
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

void TwistExpander_Karate_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBC04D6E06B66B36DULL + 0x8EAB830FF2B375A2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA9A4A98E4FD6D159ULL + 0x88BA395B2AB69D8EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9F918B0B7A8A7B4BULL + 0xC3D213BDA14CD4E7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD5770C681B99329DULL + 0xA2FDB20A5496E1E4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9260E7163D5F45F1ULL + 0x977D8F87AE0CBFF5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xDE6668389EF3E125ULL + 0xC97506FD9CA306C5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x847CF194F26D6DCDULL + 0xD199B958DDCBFE48ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB90ED000C697F289ULL + 0xC714443101CBF347ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xEB01D2042E13BD55ULL + 0xF79A7CE024999838ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD6365D26C75915F5ULL + 0xD6B918DD92621C93ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x91E679286FD48767ULL + 0xB9FA32F1D5AAFB43ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x815E1BF8B63B7B3BULL + 0xB94D89E9F2B7FA96ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE1C68CED9DACB697ULL + 0xF2DC150C879288BBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBE4682E5A4119491ULL + 0xC41FF06A2CD4E001ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA81D36A80181CEBFULL + 0xC2CF97CF3E41D7A3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x825FC2F171F18149ULL + 0xCBE0F1536F9D8246ULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5552U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 7720U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 569U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((aIndex + 1899U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 47U) ^ RotL64(aCarry, 60U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 47U)) + 12046647397183218524U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 3U)) + 2760779375026461991U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 13735454443176855650U;
            aOrbiterH = (((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 19U)) + 4370377000586647724U) + aNonceWordB;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 29U)) + 14566322384189969094U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 43U)) + 5056565959818422786U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 18U)) + 8795403810686579209U) + aNonceWordG;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 9625947666256011567U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1703669290934254701U;
            aOrbiterA = RotL64((aOrbiterA * 5763881345676123583U), 35U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 6664070663184147951U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2104148316797553431U;
            aOrbiterD = RotL64((aOrbiterD * 12887842067180975983U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1197910004222596145U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 9922977170060903197U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13047828062605568603U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 2048376210852567829U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12568990647075931409U;
            aOrbiterJ = RotL64((aOrbiterJ * 9860242601194210927U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15026894775772902751U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3439447160137900629U;
            aOrbiterC = RotL64((aOrbiterC * 1813754963043785165U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6532671388552829796U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17261098369835997661U;
            aOrbiterH = RotL64((aOrbiterH * 568292591215203521U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3171300991007459947U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5935563269327662024U;
            aOrbiterB = RotL64((aOrbiterB * 11271790283157765003U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 53U)) + aOrbiterA) + aNonceWordH) + aWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 39U)) + aOrbiterH);
            aWandererF = aWandererF + ((((RotL64(aCross, 22U) + aOrbiterB) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 60U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 29U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterJ, 3U)) + aNonceWordI);
            aWandererB = aWandererB + (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 18U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12928U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((aIndex + 15688U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9193U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 15311U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 56U) ^ RotL64(aIngress, 27U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 11U)) + 7651355040951791298U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 21U)) + 13988210277931659312U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 29U)) + 9846849412579537783U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 12746719939495876158U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 47U)) + 11498066185182895284U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 54U)) + 11101058955193080232U) + aNonceWordE;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 15513734459555672046U) + aNonceWordA;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 15711108675349394643U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4771231759949468556U;
            aOrbiterA = RotL64((aOrbiterA * 9806191054594333615U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 11449258010811305256U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17036938391509986723U;
            aOrbiterJ = RotL64((aOrbiterJ * 7411466953205347639U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6999245666776654250U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2106819066263369528U;
            aOrbiterK = RotL64((aOrbiterK * 13005885810757743129U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12716183358903477216U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 16752724547046059889U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 11475905692393034141U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17623077680983093163U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6726003022297274986U;
            aOrbiterC = RotL64((aOrbiterC * 14709385877103232653U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2842410225096524740U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9235178377537910514U;
            aOrbiterB = RotL64((aOrbiterB * 11813751114775673845U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 2619888019860844610U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 6295481948199619613U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15429161806953951205U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + RotL64(aOrbiterD, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 22U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 20U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterB, 29U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 35U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aNonceWordK);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterC, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 47U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 18U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordM);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19687U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 21712U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18371U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneC[((aIndex + 20869U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 42U)) ^ (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererK + RotL64(aCross, 35U)) + 3448371607470865612U;
            aOrbiterD = (((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 3743742913651580573U) + aOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 41U)) + 13069491287948807280U) + aNonceWordO;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 41U)) + 16872779275586545632U) + aNonceWordI;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 19U)) + 17945792656755062795U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 6U)) + 18199747196793731853U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 15953311878379809513U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 941268763494588338U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 10090221530365796809U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 14035236086292997613U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 8335698093307607001U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6147498804734306100U;
            aOrbiterD = RotL64((aOrbiterD * 6904444049941211327U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5980246079567570090U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4152167624425912978U;
            aOrbiterK = RotL64((aOrbiterK * 10019421651535123573U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14990418790239735916U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3418668387496597219U;
            aOrbiterI = RotL64((aOrbiterI * 12814077238529863119U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 4206650904177199425U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 3905470780938996069U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 16030122739273137005U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 9968672788233080924U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 602258075661864866U;
            aOrbiterG = RotL64((aOrbiterG * 2615726693066300065U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 17751667243048041383U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2414054413585296027U;
            aOrbiterF = RotL64((aOrbiterF * 1049512574773201893U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 51U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 22U)) + aOrbiterF) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 57U)) + aOrbiterI);
            aWandererK = aWandererK + ((((RotL64(aCross, 57U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aNonceWordD);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterH, 51U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterG, 35U)) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterH, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 18U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29310U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 31030U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29648U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25443U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 38U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 27U)) + 11521331427196538632U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 37U)) + 16653824187682957632U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 3U)) + 11654676587350088289U) + aNonceWordA;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 29U)) + 8010313317412193584U) + aNonceWordF;
            aOrbiterI = (aWandererK + RotL64(aScatter, 43U)) + 1108775560502907471U;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 11U)) + 243952321439823521U) + aOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 50U)) + RotL64(aCarry, 41U)) + 2324945800401240403U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9257554497543369657U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 16701314607244592540U) ^ aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8790054741039817107U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 3900445848034341782U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7652316487347103658U;
            aOrbiterG = RotL64((aOrbiterG * 11480123491361589799U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14980368605272070578U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 2001165460948764796U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8110980921827107649U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1911044015666991050U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11366207111147818339U;
            aOrbiterI = RotL64((aOrbiterI * 17234439040652553865U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 16469329744002456607U) + aNonceWordN;
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 8062793687044950815U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 5856142259851144369U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15364721421972807872U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8979915611483540231U;
            aOrbiterA = RotL64((aOrbiterA * 10899377466171153383U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7654234623563110457U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1526832460342135008U;
            aOrbiterE = RotL64((aOrbiterE * 12766083052650723051U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterG, 53U)) + aNonceWordK) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterI, 41U)) + aNonceWordH);
            aWandererC = aWandererC + ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterI, 4U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 56U) + aOrbiterB) + RotL64(aOrbiterH, 13U));
            aWandererK = aWandererK + ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 47U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 20U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordH;
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

void TwistExpander_Karate_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD42ECE30D4146E07ULL + 0xD9F504BEFAE83C10ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFE0B20269E30AB4DULL + 0xDBE7D28DC63F721EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC413E6B302707EF3ULL + 0xD216F092AF71C241ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC0DDB8A0FECFC527ULL + 0xC96F249EE1E9E6FEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x956B8ABDE4A0BE6BULL + 0xFFE1B935DA166CA8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x92E8A493A8323A4DULL + 0xB770668441ABC383ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC55456A933032173ULL + 0x8BCAD87FA244E21FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE4834AA91C175C3BULL + 0xD0303C377612BCEAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA4C421567478D239ULL + 0xB000C315FEF9B426ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA70124D72D450A25ULL + 0xFBEC708282CE5492ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC5D8B383B0993033ULL + 0xF669EBC561289201ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9EA56A3CE90D0077ULL + 0xE3EEDEEBA80A0B47ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9678B5DBA8D5E819ULL + 0x996B5721280C6F4CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDDC591441F3AFF81ULL + 0x92A5D53C252825A6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x97CD12D704275119ULL + 0x8AB6BCFCB413B8B9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xBF2E2AA63BBD00BBULL + 0x89E3A8247C7D6607ULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3439U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneC[((aIndex + 7443U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8002U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 4521U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 40U) + RotL64(aCarry, 27U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 13U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 16124889768301047791U) + aNonceWordA;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 19U)) + 11912338587186717280U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 47U)) + 8594012868813114354U;
            aOrbiterE = (aWandererG + RotL64(aCross, 41U)) + 18281043566156682815U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 16853106130200942302U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 60U)) + RotL64(aCarry, 39U)) + 2611212958619673086U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 29U)) + 18039472325066855180U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 14495785571345122046U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 4556063793412832418U;
            aOrbiterJ = RotL64((aOrbiterJ * 13166927543135467627U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14896419970271244358U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 880028529183500036U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 14228281807461251361U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2379557167489415783U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 11854373946064529806U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 150755294320438887U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 1487252775956449964U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12777924204511625545U;
            aOrbiterA = RotL64((aOrbiterA * 1366019527386994789U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15998631485222477969U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8864212892296191613U;
            aOrbiterG = RotL64((aOrbiterG * 579242788050369815U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17069347835763226743U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7443008171694679791U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 748894368884566607U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17334256152350782002U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8986626119086556393U;
            aOrbiterK = RotL64((aOrbiterK * 2258172145924120235U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 11U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 27U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 20U) + aOrbiterG) + RotL64(aOrbiterJ, 19U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterC, 11U)) + aNonceWordK);
            aWandererE = aWandererE ^ (((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterH, 35U)) + aWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 56U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterE, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 42U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8597U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((aIndex + 9580U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12992U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneB[((aIndex + 10795U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 39U)) + (RotL64(aIngress, 20U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aIngress, 47U)) + 1297415699043177788U) + aNonceWordK;
            aOrbiterI = ((aWandererA + RotL64(aCross, 57U)) + 17583786534509260153U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 12U)) + 643197858925708798U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 39U)) + 5062653766915694874U;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 7034273638367180511U) + aNonceWordI;
            aOrbiterF = (aWandererF + RotL64(aCross, 29U)) + 2026909726972916996U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 27U)) + 2785690475553211646U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2910341716302991892U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2834181605200829791U;
            aOrbiterD = RotL64((aOrbiterD * 1510617068750957651U), 47U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 13323052600571281928U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10434901530315760460U;
            aOrbiterG = RotL64((aOrbiterG * 2042210188346767033U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 247903955625194782U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5196515747387257163U;
            aOrbiterB = RotL64((aOrbiterB * 1799024689023272275U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 7196305682377987476U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 14777739876892587484U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 95220583948241581U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10609060796540136671U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 8386027207212484155U) ^ aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4855610536246556893U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 729659744301903424U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2350564261412606157U;
            aOrbiterF = RotL64((aOrbiterF * 16713856782349084977U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16611987556673864177U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1525195188708550503U;
            aOrbiterC = RotL64((aOrbiterC * 10045858602151004553U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 34U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 58U) + aOrbiterD) + RotL64(aOrbiterB, 21U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 6U)) + aOrbiterK);
            aWandererC = aWandererC + ((((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterB, 27U)) + aNonceWordM);
            aWandererK = aWandererK + (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterF, 13U)) + aNonceWordG);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 57U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 24U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordA;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 19510U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22578U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23679U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 18792U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 19U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 40U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 5960680319644404115U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aScatter, 19U)) + 16050752633567034185U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 13U)) + 8447503223226854741U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 4U)) + RotL64(aCarry, 27U)) + 14176813813397917591U;
            aOrbiterE = (aWandererB + RotL64(aCross, 13U)) + 10534915376130006644U;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 51U)) + 6866224454375302514U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 29U)) + 16506374165041008396U) + aNonceWordG;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7167814023968794098U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13870852197416596664U;
            aOrbiterJ = RotL64((aOrbiterJ * 17015971222069856463U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 18064038854848993105U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9869630811507771691U;
            aOrbiterK = RotL64((aOrbiterK * 13723164383800461387U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 863613100452759380U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16597969741225436529U;
            aOrbiterH = RotL64((aOrbiterH * 2680793528887208903U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6575347108051310653U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17062262265485019063U;
            aOrbiterA = RotL64((aOrbiterA * 7601045488473620019U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 7193399224636409133U) + aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 14146747818810433849U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 5273185769989530041U), 11U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 9441449106442431427U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4303295336545399503U;
            aOrbiterD = RotL64((aOrbiterD * 8829695296836242587U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 12604760768543193458U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15779327512379787715U;
            aOrbiterG = RotL64((aOrbiterG * 14000905201441272597U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + RotL64(aOrbiterG, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 35U)) + aOrbiterA) + aNonceWordK) + aWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 54U) + RotL64(aOrbiterG, 48U)) + aOrbiterD) + RotL64(aCarry, 29U)) + aWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 41U)) + aOrbiterA) + aNonceWordJ);
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 27U)) + aOrbiterJ) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterA, 5U));
            aWandererB = aWandererB + ((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterD, 11U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 42U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31348U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30875U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26267U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneD[((aIndex + 24645U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 27U) + RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 4773124477323378268U;
            aOrbiterI = (aWandererD + RotL64(aCross, 51U)) + 16848723289435796005U;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 13846642134917107058U) + aNonceWordL;
            aOrbiterD = (aWandererB + RotL64(aIngress, 27U)) + 6472057872482789939U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 19U)) + 2747019500690707226U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 9003965289739733880U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aPrevious, 12U)) + 3013390651936257377U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3331004709895625067U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15355010435553517129U;
            aOrbiterA = RotL64((aOrbiterA * 8322759117004876831U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7709870658004280052U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 13568728443963926564U) ^ aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6736090830113688981U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 12409548853419307131U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 969183352023661537U;
            aOrbiterI = RotL64((aOrbiterI * 5549220554838837145U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15370309834426476775U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 3896803894396631184U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11018830202891911603U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 10848873633291935766U) + aNonceWordG;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 12885336509190543440U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 1487357252619221365U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8252290890093788010U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9201553615601641350U;
            aOrbiterD = RotL64((aOrbiterD * 420321130559162915U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 14014209645503188472U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4015071464301844550U;
            aOrbiterG = RotL64((aOrbiterG * 17444195018239904971U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 51U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterA, 29U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 14U) + RotL64(aOrbiterH, 39U)) + aOrbiterD) + aWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterK, 4U)) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterI, 11U)) + aNonceWordO);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 21U)) + aOrbiterH) + aNonceWordN) + aWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterK, 51U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordF);
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

void TwistExpander_Karate_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE0331D296D4A9F13ULL + 0xB7D5D5E5FB072E46ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAF6CE172F360F869ULL + 0xA0EDCDAAD05738A5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF3A2525E531E24B5ULL + 0xCC6403462D42131FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD957F2C444655C3DULL + 0xFAD77B94FF6FD88DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE24A6537D7BD1DBFULL + 0x9608E1F35F38FB50ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x83F34EC395E54C15ULL + 0xEB5E30EC1F469679ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF51A4E024DE5DCC1ULL + 0xD3B1159AEE813F12ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC16A9D381D8A2BF9ULL + 0xDA90A7D5423158D6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD418D28CCBA72479ULL + 0x998B489C44401E19ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xBFB45A68A4FA0EB9ULL + 0xF803265382FA26C0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE721A180CB60C35FULL + 0xF1D70BF526BBEDD7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x80C1244399374F73ULL + 0x97EED33A30F4F688ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF2839C5E3B245C21ULL + 0x9A6D4BCAAA88236DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE80D92896D518E95ULL + 0xE9A38A3A60D93A59ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE400B28592D2E411ULL + 0x9E597AC54EF61D65ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xDE34EF4084665FAFULL + 0xF0666071B44F4F3EULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1380U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4353U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 536U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 4843U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aCarry, 28U) + RotL64(aPrevious, 43U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererI + RotL64(aCross, 47U)) + 11700815697312060726U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 43U)) + 11808423452327465441U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 14U)) + 8670503858631730886U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 57U)) + 2400061067991988544U) + aOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aScatter, 35U)) + 16163118178366229686U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 3280178595904941068U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 19U)) + 3298683600817047727U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 16321624053445183574U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 60U)) + 6730229877611375225U) + aNonceWordG;
            aOrbiterJ = (aWandererC + RotL64(aCross, 27U)) + 10162830636713641322U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 23U)) + 15646771327759599256U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14841751262270544102U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9545541117228834895U;
            aOrbiterD = RotL64((aOrbiterD * 11529769874752969377U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14676615635857599982U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 1231768638470558855U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2716808508509014677U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1945905595345404833U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1406171421638586846U;
            aOrbiterK = RotL64((aOrbiterK * 4577864352425476233U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1970292335806697198U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12309719390375013297U;
            aOrbiterE = RotL64((aOrbiterE * 16540660957923687327U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5352135521358954576U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 15465675376193501658U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 16385761112921041387U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2842123638916600369U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 3544764287036748668U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3360772950777850115U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6038297172906492282U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10249342332287140970U;
            aOrbiterH = RotL64((aOrbiterH * 16701083081566042277U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 1662076777040529446U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1949705569959740274U;
            aOrbiterC = RotL64((aOrbiterC * 11340691546658994529U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13934194245417822360U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5720408806425535958U;
            aOrbiterA = RotL64((aOrbiterA * 15237561081637415383U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2209251362417210658U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4917447930929521699U;
            aOrbiterF = RotL64((aOrbiterF * 17489570156694692569U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14817115766683623486U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11700815697312060726U;
            aOrbiterJ = RotL64((aOrbiterJ * 16982411053956669181U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 53U);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 34U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterH, 5U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 3U)) + aOrbiterC);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 47U)) + aOrbiterH) + aNonceWordH);
            aWandererC = aWandererC + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 41U)) + aOrbiterG) + aNonceWordN) + aWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterI, 35U));
            aWandererB = aWandererB + ((((RotL64(aCross, 50U) + aOrbiterJ) + RotL64(aOrbiterA, 22U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 43U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 53U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 27U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterD, 18U)) + aNonceWordJ);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterJ, 39U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 34U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 22U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10753U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((aIndex + 10183U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15918U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 12562U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 21U)) + (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererK + RotL64(aCross, 19U)) + 13687218104610230596U) + aNonceWordP;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 6841550124960692709U) + aNonceWordM;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 27U)) + 17418968668458764131U;
            aOrbiterH = (((aWandererG + RotL64(aScatter, 54U)) + 8303537912696948204U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aWandererH + RotL64(aIngress, 27U)) + 12376614417285936537U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 35U)) + 14215749063579232654U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 43U)) + 4111736931433665347U) + aOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aPrevious, 10U)) + 11250375934571631522U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 41U)) + 5367367837773331275U;
            aOrbiterC = (aWandererB + RotL64(aCross, 29U)) + 15514089192382674434U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 1475991716685034960U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5531622777788629748U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8363822215908303335U;
            aOrbiterK = RotL64((aOrbiterK * 17850203366840994883U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 3741256932685720414U) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11634667238062155772U;
            aOrbiterJ = RotL64((aOrbiterJ * 15925089729784547403U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 18180546911210417155U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5123234656838556335U;
            aOrbiterA = RotL64((aOrbiterA * 15362857462853398025U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 11215734271189250284U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16863747802158398092U;
            aOrbiterD = RotL64((aOrbiterD * 1828035970246160023U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9859050606636646323U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9331300036643654675U;
            aOrbiterI = RotL64((aOrbiterI * 2502263410556166281U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15028845665427209759U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8916444839488901676U;
            aOrbiterG = RotL64((aOrbiterG * 6646561894156038791U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 8024631140949068570U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1116378858490660031U;
            aOrbiterH = RotL64((aOrbiterH * 4247798531910227367U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5066486214537899212U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9346312092322423057U;
            aOrbiterF = RotL64((aOrbiterF * 13443190089768875191U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11651011617027950122U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 11308862427412671711U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12167147966934334703U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3850136281462840708U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13461307727665667424U;
            aOrbiterC = RotL64((aOrbiterC * 10788040812090673421U), 35U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 17824744996404571928U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13687218104610230596U;
            aOrbiterE = RotL64((aOrbiterE * 325803029547254631U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterE, 44U)) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterD, 19U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 41U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 29U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 12U) + RotL64(aOrbiterC, 23U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterE, 35U)) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 57U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterE, 38U)) + aNonceWordL);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 3U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aIngress, 40U) + aOrbiterG) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23296U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 19075U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21886U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19715U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 24U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererD + RotL64(aCross, 47U)) + 13714409587461539863U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aScatter, 3U)) + 14101156723903265839U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 54U)) + 7063754562895369001U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 23U)) + 12320578575245519386U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 19U)) + 11744826789631008424U;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 8744816505096675597U) + aOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 10405435520084528645U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 42U)) + RotL64(aCarry, 11U)) + 1463157688070683543U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 57U)) + 12379603577919617703U) + aNonceWordB;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 35U)) + 1343439118031348146U) + aNonceWordH;
            aOrbiterH = (aWandererC + RotL64(aIngress, 11U)) + 16118850268070235540U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14116264435819277136U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 5251698273012432109U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1495818611622063967U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14806408656041403829U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 11569345414052398227U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9913158908301414861U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17063874769147888574U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9927420478679581917U;
            aOrbiterJ = RotL64((aOrbiterJ * 9042782809534196563U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2550285599827162167U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17801534123304996448U;
            aOrbiterD = RotL64((aOrbiterD * 2160836889363614721U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6456685241021762041U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 17064208177372969289U) ^ aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13726627607233302493U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 18279938244131982650U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8211002229712129419U;
            aOrbiterE = RotL64((aOrbiterE * 12931373380977640645U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12795832560781931767U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 286378504074349650U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 85453101173293509U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5835304250436889513U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12704972686724379659U;
            aOrbiterI = RotL64((aOrbiterI * 1198789639656336053U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12555700587254295099U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6740149669657971715U;
            aOrbiterA = RotL64((aOrbiterA * 9376048577305482691U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1541392147096889431U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16891341703173286949U;
            aOrbiterF = RotL64((aOrbiterF * 697452963711223355U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 8811637585092392653U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13714409587461539863U;
            aOrbiterH = RotL64((aOrbiterH * 2578939920876994763U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 54U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 46U) + aOrbiterD) + RotL64(aOrbiterG, 13U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 19U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 37U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterC, 57U)) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterI, 60U));
            aWandererB = aWandererB + (((RotL64(aCross, 52U) + aOrbiterJ) + RotL64(aOrbiterK, 23U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterA, 21U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterI, 47U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 39U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 44U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterB, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 22U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32467U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 27680U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30568U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 28094U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 18U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererC + RotL64(aCross, 35U)) + 4970414922752555648U;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 28U)) + 9462756592787669327U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 41U)) + 3948790686662213095U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 14542857212241578311U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 3387479009827029547U) + aNonceWordI;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 11U)) + 1411421370057797877U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aCross, 50U)) + 16894451466895681236U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 13U)) + 12727136462290223542U;
            aOrbiterB = (aWandererA + RotL64(aCross, 3U)) + 4625389198191960525U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 3471881403786164913U) + aNonceWordJ;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 57U)) + 6433115856048534831U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9825592965466157982U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1553125767261293088U;
            aOrbiterA = RotL64((aOrbiterA * 411535191177308781U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9951616357109647617U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11231080382787286889U;
            aOrbiterH = RotL64((aOrbiterH * 14024961994986659187U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 13419663264017317947U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4835055642466215566U;
            aOrbiterD = RotL64((aOrbiterD * 17898065852351759171U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 14558747666410946768U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13120938960926874504U;
            aOrbiterF = RotL64((aOrbiterF * 5681766019285559739U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 11910501376797343986U) + aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15074100100781785300U;
            aOrbiterG = RotL64((aOrbiterG * 228976960937473851U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12415377930578091821U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14882039078390681802U;
            aOrbiterB = RotL64((aOrbiterB * 13855446647753150713U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8094338361713756895U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 5478280604704108822U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 18062931724700600993U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6977017654546871841U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 4131602217285988962U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 11865422227883712419U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9619228479582032318U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13506679497441415586U;
            aOrbiterC = RotL64((aOrbiterC * 5789932662418992799U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10180259475831448124U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4721628773773094283U;
            aOrbiterE = RotL64((aOrbiterE * 10834196399754443771U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 7898137727558813688U) + aNonceWordP;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 4970414922752555648U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6651835668618579479U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (RotL64(aOrbiterE, 42U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterH, 23U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 21U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterB, 21U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterI, 47U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 54U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterH, 43U)) + aNonceWordF);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 29U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ) + aWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 20U) + RotL64(aOrbiterE, 35U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 3U)) + aOrbiterA) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 10U)) + aNonceWordG) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 14U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 44U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordA);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Karate_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCE86CC2628B08D95ULL + 0xD8560D8CD8823AFBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA7771F25798D1CAFULL + 0x919511B5C1A6552CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x88B4520B03A812B9ULL + 0xD6291D58B2414B91ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA698918A51D10515ULL + 0xEB176DC3B06642F7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9DB1307252548F17ULL + 0xB1E698DB2B965602ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x917B263F4558CDFFULL + 0xDC7AF19DA2D810FEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE5F7AE64BA64E0CBULL + 0xDB6FBF946F161465ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF9A2192FD54F14C7ULL + 0xD906121E844BE55CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD6D317D28394773FULL + 0xDDD35D32DF87E598ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x85101B9743DE9031ULL + 0x974BB57547F71E1EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDF2F8294E30FF2F7ULL + 0xF60D0C0711EAE250ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xCB02C7DAF9CFD125ULL + 0xA2C3B22B80DCE782ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDBE40AC5A2FE9F07ULL + 0xDFE5772DB91CA903ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xEAD85F3B950B3F43ULL + 0xBCB7F169F57E0A25ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCB678D81C8D673C5ULL + 0xAB9066397EB7CA84ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xDA272997B35A0F6FULL + 0xE69B159C06E40F1DULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3238U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4475U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2898U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1894U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 29U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCross, 56U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 13U)) + 6318740973868639425U) + aNonceWordI;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 39U)) + 5487840061430920881U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aIngress, 3U)) + 10258706763248072672U;
            aOrbiterC = (aWandererF + RotL64(aCross, 22U)) + 18356875269730338208U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 57U)) + 12883160282903147010U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 29U)) + 1010140474942697730U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 41U)) + 17733939421700898293U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 53U)) + 13693055887924981201U) + aNonceWordM;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 18U)) + RotL64(aCarry, 13U)) + 14574732452793385269U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10832873941223609012U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 8212600587135328040U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 5334613996794796145U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5312744319781971178U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6173741211706546923U;
            aOrbiterD = RotL64((aOrbiterD * 12854414066390848249U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3693249147883790810U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 18365859989736602556U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 3348463719324104997U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 10645056678337549771U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1175668356822251045U;
            aOrbiterF = RotL64((aOrbiterF * 6579675292775345579U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 13556844570541823717U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4790355739411849736U;
            aOrbiterI = RotL64((aOrbiterI * 4083544011788850307U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 14905575502272644116U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 17047244574558476634U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 2356386971503880047U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 10161614295718414869U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13413914082651612468U;
            aOrbiterJ = RotL64((aOrbiterJ * 16224039093981079491U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 6072693130156927774U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4333656233793103787U;
            aOrbiterK = RotL64((aOrbiterK * 9374745547133955709U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17209776289202130250U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11752001118070361543U;
            aOrbiterE = RotL64((aOrbiterE * 4416523594812872339U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 23U);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 36U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterF, 6U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 53U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aCross, 10U) + aOrbiterC) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 29U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterI, 57U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterD, 10U)) + aNonceWordE) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 24U) + aOrbiterB) + RotL64(aOrbiterC, 23U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterE, 19U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 35U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 6U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5905U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7950U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9423U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 7255U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 11U) ^ RotL64(aCross, 24U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 22U)) + 1087148170018530502U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 51U)) + 15530846874509311414U) + aOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 16987358651515511212U) + aNonceWordM;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 12504143181007924259U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 27U)) + 393322117322732418U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 39U)) + 14325937299241887166U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 47U)) + 9395262907017475742U;
            aOrbiterB = (aWandererF + RotL64(aCross, 18U)) + 13658510441418344769U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 6410754322737005336U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9257290738538818434U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7489828960857692286U;
            aOrbiterH = RotL64((aOrbiterH * 16519674788777989043U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 4118778591214588387U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 16619215231168796563U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 14876884956536265157U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 11326283811003573430U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1865401866017614604U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8378326058282460073U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 670150121105733604U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1499331510641068749U;
            aOrbiterB = RotL64((aOrbiterB * 16623742535540383107U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1116410848560838532U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2696841341036281779U;
            aOrbiterK = RotL64((aOrbiterK * 9598953298074904869U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5487352391229549881U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12008243050943342979U;
            aOrbiterE = RotL64((aOrbiterE * 9087261224804582459U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 552859665927882960U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8426942688524814473U;
            aOrbiterC = RotL64((aOrbiterC * 10916963622695549105U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 1613287981244830815U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15592897923468694288U;
            aOrbiterA = RotL64((aOrbiterA * 6600750586743893303U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7629853970631002676U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13778028957247561272U;
            aOrbiterJ = RotL64((aOrbiterJ * 4063798788229605659U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 6U));
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterE, 43U)) + aNonceWordE) + aWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 47U)) + aOrbiterF) + aNonceWordK);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterC, 60U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 39U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterA, 35U)) + aNonceWordP);
            aWandererA = aWandererA + ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 11U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterB, 5U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 51U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 48U) + aOrbiterE) + RotL64(aOrbiterF, 30U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 54U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14684U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15964U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15038U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneC[((aIndex + 14698U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 21U)) + (RotL64(aIngress, 52U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererJ + RotL64(aCross, 30U)) + RotL64(aCarry, 29U)) + 12669015908335980355U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 3U)) + 5438715179868613192U;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 13172104448184536460U) + aNonceWordN;
            aOrbiterI = (aWandererI + RotL64(aIngress, 35U)) + 13421421503244744803U;
            aOrbiterB = (((aWandererH + RotL64(aCross, 18U)) + 13327113302994856582U) + aOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 57U)) + 4671768205922454413U) + aNonceWordE;
            aOrbiterC = (aWandererB + RotL64(aIngress, 43U)) + 5355759962838579929U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 6691720614265406851U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 23U)) + 7063906424700911378U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17328616394166672263U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 1542940602574207068U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8981679306319627975U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7203866278803132454U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 993485696233139264U;
            aOrbiterK = RotL64((aOrbiterK * 11609009908810366447U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 15659679028507488331U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 18321361454094675842U;
            aOrbiterI = RotL64((aOrbiterI * 3966860765622641843U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9633319822696783352U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3496559332232402963U;
            aOrbiterA = RotL64((aOrbiterA * 7772060229838162977U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 1918349708324205526U) + aNonceWordC;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 7701088402761359134U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9649485438465644795U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6006824348814439686U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 18088375375347012557U;
            aOrbiterE = RotL64((aOrbiterE * 12801082943086128385U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12816533373478543584U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17951880253818836433U;
            aOrbiterC = RotL64((aOrbiterC * 8935839101517220201U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 11311632024372748238U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9891349164779752351U;
            aOrbiterH = RotL64((aOrbiterH * 11405973752233193209U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 711130292000437038U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17818800917771709681U;
            aOrbiterJ = RotL64((aOrbiterJ * 10567029732245868263U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 51U);
            aIngress = aIngress + (RotL64(aOrbiterD, 10U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 43U)) + aOrbiterB) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 22U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aPrevious, 12U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterJ, 47U)) + aNonceWordL);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 29U)) + aOrbiterH) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + RotL64(aOrbiterK, 3U)) + aOrbiterD) + aNonceWordA);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 18U) + aOrbiterB) + RotL64(aOrbiterK, 18U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererI, 20U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18155U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 20053U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16554U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((aIndex + 19859U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 24U)) + (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 4739486756133131180U) + aNonceWordD;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 54U)) + RotL64(aCarry, 5U)) + 16089707555501328184U) + aOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 19U)) + 15310047330238536453U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 47U)) + 7901411596386834955U) + aNonceWordA;
            aOrbiterK = (aWandererI + RotL64(aCross, 5U)) + 4357555491060982163U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 41U)) + 15667085602825720102U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 8520635334382269253U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 37U)) + 1772509779231068315U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aCross, 58U)) + 15336170957886025677U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8628770833489469980U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15469234024247246228U;
            aOrbiterJ = RotL64((aOrbiterJ * 8905266995119987947U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10796430900884288328U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10660110397012853289U;
            aOrbiterK = RotL64((aOrbiterK * 9140007610912037461U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11202284258711214794U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17509491802893182994U;
            aOrbiterC = RotL64((aOrbiterC * 9329107599972703671U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 16212572740740103554U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 2190030203761579226U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 3101886685668871045U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12014337082293041909U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 3733531010807001506U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 5797362244066062299U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 7100994963061975529U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 17837541162838600258U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8745987361678166553U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3311518938023146951U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7709505172646831553U;
            aOrbiterE = RotL64((aOrbiterE * 7121143171245765213U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 4979968094554018443U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 16822214821463034107U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8618262120451291765U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8376124175020587079U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11084586282092424876U;
            aOrbiterB = RotL64((aOrbiterB * 5835632742522563537U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 50U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 20U) + RotL64(aOrbiterA, 41U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterB, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterI, 51U)) + aNonceWordK);
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterI, 23U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterE, 30U)) + aOrbiterA);
            aWandererH = aWandererH + ((((RotL64(aCross, 11U) + RotL64(aOrbiterH, 57U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 37U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 47U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 6U)) + aOrbiterC) + aNonceWordI) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26116U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26201U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24059U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24940U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 18U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 41U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererH + RotL64(aScatter, 12U)) + RotL64(aCarry, 21U)) + 13924571355038625040U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 29U)) + 16328300979357156658U) + aNonceWordC;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 3U)) + 3947771961206012461U;
            aOrbiterH = (((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 15428284250569311285U) + aNonceWordF;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 41U)) + 5777369485254032486U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aCross, 53U)) + 16813320300717644673U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 37U)) + 16689933050200758251U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 60U)) + RotL64(aCarry, 29U)) + 1856422419049390708U;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 47U)) + 18214498743831925517U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 18278550878494094923U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 797712062039591797U;
            aOrbiterE = RotL64((aOrbiterE * 7212998747080137625U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15854849439012341347U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 996882939768167773U;
            aOrbiterF = RotL64((aOrbiterF * 14936703950807908575U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3005829974130671692U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8793495343509953906U;
            aOrbiterI = RotL64((aOrbiterI * 14065479348374612031U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7710453029930631112U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9511995836117707047U;
            aOrbiterB = RotL64((aOrbiterB * 7250766204781428201U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 670902975693341744U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 9045820304668279777U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 18373074917532639027U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12417212387607119470U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12816983560669985622U;
            aOrbiterH = RotL64((aOrbiterH * 8406003970221889847U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 17245432086377688540U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 6806521945548502014U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 11335859481858640857U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 8947500746292365294U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4468060468522895852U;
            aOrbiterJ = RotL64((aOrbiterJ * 7022481284816599797U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9892975931958803992U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 3042599331526937836U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 3308512896171443645U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 42U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterF, 3U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 47U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 51U) + aOrbiterI) + RotL64(aOrbiterH, 27U)) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 19U)) + aOrbiterG) + aWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 30U) + RotL64(aOrbiterF, 57U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 52U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterC, 37U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30999U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32674U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30757U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32644U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 10U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 13U)) + 3970829908171131502U) + aNonceWordN;
            aOrbiterE = (aWandererD + RotL64(aCross, 37U)) + 7040283759419531991U;
            aOrbiterF = (((aWandererA + RotL64(aIngress, 52U)) + RotL64(aCarry, 13U)) + 11856292169397052901U) + aNonceWordH;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 43U)) + 819598588791819022U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 19U)) + 2176451710970866848U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 5U)) + 6454704928613390494U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 27U)) + 11792122387218053841U) + aOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aScatter, 57U)) + 9254780213489752211U) + aNonceWordC;
            aOrbiterH = (((aWandererC + RotL64(aCross, 46U)) + RotL64(aCarry, 23U)) + 16591812589999846482U) + aOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1471246223935074832U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1424843083106386453U;
            aOrbiterF = RotL64((aOrbiterF * 15020536982657410783U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1856469958050891629U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6331743690452052712U;
            aOrbiterI = RotL64((aOrbiterI * 15327924647897459645U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 10351075711345476487U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9518585245330480185U;
            aOrbiterG = RotL64((aOrbiterG * 3792179827396760391U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17787514620244712033U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14182328067398162557U;
            aOrbiterC = RotL64((aOrbiterC * 18107337388659070197U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 12798088948801072444U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9563215159275202323U;
            aOrbiterH = RotL64((aOrbiterH * 7058145016617349141U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 9904919772580498232U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16579777394992143043U;
            aOrbiterB = RotL64((aOrbiterB * 10516761340320196661U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 6344049286854588503U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3531503618941046788U;
            aOrbiterA = RotL64((aOrbiterA * 10855385899703024105U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11334308840132700377U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11093833870078787770U;
            aOrbiterK = RotL64((aOrbiterK * 16105889714648555755U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 3831491136025364271U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12505259454860591372U;
            aOrbiterE = RotL64((aOrbiterE * 6135450888433504093U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 60U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 14U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 23U)) + aOrbiterH);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterA, 29U)) + aNonceWordG);
            aWandererF = aWandererF + ((RotL64(aPrevious, 18U) + aOrbiterK) + RotL64(aOrbiterE, 3U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 19U)) + aOrbiterB) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 58U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 43U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aIngress, 22U) + RotL64(aOrbiterK, 39U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterK, 53U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 14U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordF);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Karate_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF7BB9507B7A6676DULL + 0xDC8A2646D30E479AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB4F63C95200B0D63ULL + 0x9A552942C7984934ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD61796F92F5A4541ULL + 0xFB9139EDF437308DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCA5DE4C16B5DE75BULL + 0x948AD954DA485FF8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEFEE18BCE5BD3D97ULL + 0xBB24FB8A4486F545ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA992312B27C2AF35ULL + 0xE29E461B20514BA9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBAFF6FF715AF1BBFULL + 0xCA0CFCE75BB1D339ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB60C382807FFAFFFULL + 0x9D4F0E98B3AD8E73ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDABACF1C6A410141ULL + 0x831FF677913ADB4FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA0A0B563801BC6C9ULL + 0x9C3D0215268C937FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA55704717E6E871FULL + 0xC8A298199D3361F7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x902E6800A515623DULL + 0xA1AF6C1A57F8F676ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE846FC95DA0C27B1ULL + 0x81F4488E0617276AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x92D86A256E779B67ULL + 0xDA3685185ACEF9A7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB3037D016EC1B93BULL + 0x88FFAA4099D46836ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE9C17111D13E309FULL + 0xB1CEA7A23E98F1C7ULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3236U)) & S_BLOCK1], 4U) ^ RotL64(aKeyRowReadA[((aIndex + 2317U)) & W_KEY1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 112U)) & W_KEY1], 5U) ^ RotL64(mSource[((aIndex + 2942U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 54U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 53U)) + 11177787645248006236U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 13U)) + 3808340254579817169U) + aNonceWordD;
            aOrbiterD = (aWandererK + RotL64(aCross, 27U)) + 828030667598518279U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 44U)) + 16177835921238398371U) + aPhaseAOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 5518747735458708741U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 17346319082399995165U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 41U)) + 6397156921893030937U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15559381654710713582U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 940404446491415088U;
            aOrbiterD = RotL64((aOrbiterD * 16401260971303026881U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8047166032048732645U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4688468645859470491U;
            aOrbiterC = RotL64((aOrbiterC * 14383536431614496369U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3710878044770337260U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 116343189456629220U;
            aOrbiterG = RotL64((aOrbiterG * 5637725064169289339U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 883908030159391659U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 18058691521694880482U;
            aOrbiterJ = RotL64((aOrbiterJ * 3132200449123497619U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 17521015077103586117U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3668332225435714918U;
            aOrbiterK = RotL64((aOrbiterK * 12658899101297839881U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 12229480388278883300U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 16206524049491531816U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11122340196620859805U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 5743265849441077466U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2812293020719282236U;
            aOrbiterB = RotL64((aOrbiterB * 8903956475200417109U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 60U);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 19U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterI, 53U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 13U)) + aNonceWordA);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 50U) + RotL64(aOrbiterD, 27U)) + aOrbiterK) + aNonceWordF) + aPhaseAWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterK, 41U)) + aPhaseAWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterG, 5U));
            aWandererK = aWandererK + ((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 35U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5612U)) & S_BLOCK1], 26U) ^ RotL64(mSource[((aIndex + 5599U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 9436U)) & W_KEY1], 52U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7557U)) & W_KEY1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCross, 11U)) ^ (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = ((aWandererK + RotL64(aScatter, 18U)) + RotL64(aCarry, 11U)) + 2330952702412094686U;
            aOrbiterK = (aWandererA + RotL64(aCross, 5U)) + 7820188225935060799U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 27U)) + 9347644591709839145U) + aPhaseAOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 57U)) + 2288624878446846870U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 57U)) + 9358977729492824128U;
            aOrbiterG = ((((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 43U)) + 1858511275052455039U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 43U)) + 13715478509322292552U) + aNonceWordF;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 16413396625604260455U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 17714322215518432705U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1904184102419934333U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16188315436202861122U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 5564445841368207813U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 14125834616162835983U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 13717068949900594673U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14143659432287313765U;
            aOrbiterF = RotL64((aOrbiterF * 17281441046722262917U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5729546141908425670U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 4297827922736712074U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 13631630436759768885U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 829520109395163673U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11547160328525174295U;
            aOrbiterE = RotL64((aOrbiterE * 4759690159673049775U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2907177944512117206U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11100346409065275671U;
            aOrbiterG = RotL64((aOrbiterG * 17927994356809011637U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1344592529249949068U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 6470438516791143572U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 13339390828725370475U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 28U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterD, 13U)) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 35U)) + aOrbiterB) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 4U) + aOrbiterF) + RotL64(aOrbiterK, 3U));
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 29U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 43U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 58U)) + aOrbiterB) + RotL64(aCarry, 29U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterF, 23U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererC, 42U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12935U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12887U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 12973U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 14781U)) & W_KEY1], 48U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 5U)) + (RotL64(aPrevious, 40U) ^ RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aIngress, 51U)) + 16519040829220310189U) + aPhaseAOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aCross, 3U)) + 6888002778416941825U) + aNonceWordN;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 60U)) + 1310832187746534025U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aPrevious, 27U)) + 5890888009051281674U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 5143864838362464857U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 5U)) + 15591534069452660003U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 1466867671765325096U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13931443680107902488U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15400747367673245552U;
            aOrbiterJ = RotL64((aOrbiterJ * 7011651369456453127U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2836975369734495759U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2370720358274970117U;
            aOrbiterH = RotL64((aOrbiterH * 4615571902817575375U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3470677184188006133U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7175584278499266723U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 10067096593682482345U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 6095078817776863055U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2176637999243513070U;
            aOrbiterA = RotL64((aOrbiterA * 12215701810843975501U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5580391239754903129U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 15196125567953871184U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12686361960729564519U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 12787014151503209931U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 1523153207064063495U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3113907543551927561U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12973289026485937829U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9087439766232078173U;
            aOrbiterI = RotL64((aOrbiterI * 5817029335999350327U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 37U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 14U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterK, 51U)) + aNonceWordK);
            aWandererC = aWandererC + (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 28U) + aOrbiterC) + RotL64(aOrbiterK, 3U));
            aWandererK = aWandererK + (((RotL64(aCross, 51U) + RotL64(aOrbiterH, 35U)) + aOrbiterA) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 23U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterI, 41U)) + aNonceWordP) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 42U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20833U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 21533U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21174U)) & S_BLOCK1], 4U) ^ RotL64(mSource[((aIndex + 21131U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 60U) ^ RotL64(aPrevious, 47U)) + (RotL64(aIngress, 27U) + RotL64(aCarry, 13U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 17454559218352016650U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 43U)) + 8005709669325164803U) + aPhaseAOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aScatter, 11U)) + 13393741948412816357U) + aNonceWordH;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 3665865624348875553U;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 51U)) + 8334142570031883436U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (aWandererH + RotL64(aCross, 58U)) + 17226066128706139657U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 21U)) + 3319093033121522613U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6657535603401588798U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5469746182326331147U;
            aOrbiterC = RotL64((aOrbiterC * 11315450342347794329U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17846791786050221418U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15939541003714896288U;
            aOrbiterJ = RotL64((aOrbiterJ * 1400351482213119809U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12076763190461077406U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3594038213596405284U;
            aOrbiterE = RotL64((aOrbiterE * 10244002692575821495U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 8301291631324464622U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 8460406137668390582U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 9117147929757711595U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 7612394867020871200U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8525076134853103975U;
            aOrbiterD = RotL64((aOrbiterD * 5790440201072204659U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11929899088215090379U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7119509166360685726U;
            aOrbiterK = RotL64((aOrbiterK * 1662341427992528823U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 5081078459225240607U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 17149991983909906705U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 950223374568067343U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 53U);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 21U)) + aOrbiterK) + aNonceWordN);
            aWandererB = aWandererB + (((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterK, 29U)) + aPhaseAWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterD, 60U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 11U)) + aOrbiterC) + aNonceWordK);
            aWandererD = aWandererD + (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 41U)) + aOrbiterE) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 12U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22543U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26932U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26998U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 24289U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 13U) + RotL64(aCarry, 26U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = ((((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 11480359716598965890U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 47U)) + 15431182525482873419U;
            aOrbiterF = (aWandererD + RotL64(aCross, 23U)) + 11360504974812776707U;
            aOrbiterH = (((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 9292576416573382769U) + aPhaseAOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 23U)) + 1549257414531028975U) + aNonceWordC;
            aOrbiterC = (aWandererH + RotL64(aCross, 58U)) + 5347769463033129317U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 11U)) + 17019199177478377234U) + aNonceWordF;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16558106007323125094U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3976182233825939422U;
            aOrbiterF = RotL64((aOrbiterF * 4392162052317572289U), 35U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterD) + 2889047161195954395U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2241831345026962605U;
            aOrbiterG = RotL64((aOrbiterG * 5757458560979927857U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12850802412140579294U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13541744735436450160U;
            aOrbiterH = RotL64((aOrbiterH * 906089290000537439U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2085863085516538212U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 2969034221711544086U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7768528124408400403U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6482666944512391472U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16969153556875844613U;
            aOrbiterD = RotL64((aOrbiterD * 9483462388353216219U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5161314086757363678U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 7150282484670673211U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 8522427002337918663U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5465304381272305847U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2344610773390354017U;
            aOrbiterE = RotL64((aOrbiterE * 17010258514288089191U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 43U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterF, 29U));
            aWandererC = aWandererC + (((RotL64(aCross, 23U) + RotL64(aOrbiterD, 13U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterG, 19U));
            aWandererB = aWandererB + (((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 51U)) + aOrbiterC) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + aNonceWordH);
            aWandererD = aWandererD + ((((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 21U)) + aPhaseAWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordH;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27340U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 30635U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31448U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 30141U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 43U)) ^ (RotL64(aIngress, 24U) + RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 3248574644570178787U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 53U)) + 4506961512959200024U;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 8423739774540738590U) + aPhaseAOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 6593975869641735337U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 3U)) + 16441716090557369103U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 60U)) + 7936601450453207914U;
            aOrbiterI = (aWandererI + RotL64(aCross, 39U)) + 13333752583560167065U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8013703284795432973U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 2349852779887439236U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2422888500648100783U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5318539364763284138U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11450957608502944376U;
            aOrbiterJ = RotL64((aOrbiterJ * 1957880366707810635U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9058992558327552687U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 632095686920230926U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 12460364388358520799U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 14734218428913777098U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 16344357661370784442U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 15049472842002138369U), 21U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 2981145363531184308U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14176472085175714494U;
            aOrbiterE = RotL64((aOrbiterE * 2584623327412130939U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 11198457590069700889U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 952584436750426828U;
            aOrbiterF = RotL64((aOrbiterF * 1165713888651280355U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4311591763498985972U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16194341833989936369U;
            aOrbiterH = RotL64((aOrbiterH * 9997934560195932575U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 20U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 43U)) + aOrbiterK) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 23U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterH, 30U)) + RotL64(aCarry, 21U)) + aNonceWordP);
            aWandererI = aWandererI ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterJ, 5U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 11U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterK, 51U)) + aNonceWordO) + aPhaseAWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 37U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + RotL64(aWandererG, 4U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordA;
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

void TwistExpander_Karate_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8F3E46F08F39C3A7ULL + 0xFF8C8B5B78C5BD71ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFA3816DEFD5A208BULL + 0xD3A34797489E7FA9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xEB71E1AC5ADE9E97ULL + 0xEA53759054E8D1DAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8DB54B3C6591481FULL + 0xA8CA6AB6679DF0BBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xFD72CBB9F69A8159ULL + 0xB60AD03E1BB6752AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x82FACD1AF38512A7ULL + 0x92B6BEB659242B3AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA54031E42A06381DULL + 0x8EB1659BA08C9330ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB87542AA16D6D207ULL + 0xED1AA8A59999C1F4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x97D133D5384C1929ULL + 0xFC9D7074B70A06F0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF661FA573F0E127DULL + 0xEA4A350654B27CE0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF5F87192EA37DE07ULL + 0x871D10ACE9ACDF8EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xCC5AE1D64405128DULL + 0xDE9E5FF84CDF170CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8CB8ED2A290D327BULL + 0xFFE4D7CC2004097CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA61B61F3300D980DULL + 0xC4813A83A4965005ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA23FE17B07275A3DULL + 0xD6AFBFF0E521FB48ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xAFA66D3EAEF4A6F3ULL + 0xCB4642265F30FB0AULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3900U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1600U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2837U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 919U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 48U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 19U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 12U)) + RotL64(aCarry, 37U)) + 4179952823252098240U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 29U)) + 3745613452332101749U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 43U)) + 2955689793395307176U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 21U)) + 5639060180251322019U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 7901969163853586463U) + aNonceWordE;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2242166787816318119U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5239936443960750064U;
            aOrbiterD = RotL64((aOrbiterD * 2752853245379816327U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 13939136954732185558U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 17058884136712717463U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 7222348891215482977U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 18148618660054585941U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7022023484530327814U;
            aOrbiterG = RotL64((aOrbiterG * 650100011311048589U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7722084537340095637U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 11764151879690934182U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12264384877711365655U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 16412785901758144708U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9666718667728274824U;
            aOrbiterK = RotL64((aOrbiterK * 10865799822751771795U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 54U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((((RotL64(aScatter, 18U) + RotL64(aOrbiterK, 19U)) + aOrbiterD) + RotL64(aCarry, 21U)) + aNonceWordP) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 43U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterG, 57U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterF, 27U)) + aOrbiterK);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 4U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aNonceWordF) + aPhaseBWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9069U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 6225U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6081U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8914U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 6U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (((aWandererD + RotL64(aCross, 56U)) + RotL64(aCarry, 35U)) + 3650233661228036955U) + aNonceWordA;
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 11607036400067735729U) + aPhaseBOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = ((((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 47U)) + 3899614406903883035U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = (aWandererE + RotL64(aIngress, 47U)) + 8159156925629965143U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 27U)) + 7148903913967261270U) + aNonceWordF;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 9161665622287517848U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2981535013474059469U;
            aOrbiterA = RotL64((aOrbiterA * 4434815231517266013U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 15812469008200319549U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14687469489893270300U;
            aOrbiterJ = RotL64((aOrbiterJ * 14142363399696670451U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6025209349511417063U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12964750392311112676U;
            aOrbiterI = RotL64((aOrbiterI * 12955480283032701843U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 6572355895765394340U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 3542300121890027981U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 11201491178181273935U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 6477175684045398359U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 1081388388827929314U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 8752188637514143529U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (RotL64(aOrbiterI, 40U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 39U)) + aPhaseBWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 58U) + aOrbiterK) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 35U)) + aNonceWordO);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 22U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 21U)) + aNonceWordG);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 11U) + RotL64(aOrbiterC, 5U)) + aOrbiterI) + aNonceWordM) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererE, 56U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordF;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13805U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11056U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13857U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 13116U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 58U)) + (RotL64(aIngress, 11U) ^ RotL64(aCross, 29U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = (((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 11998579547770778580U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aCross, 48U)) + 8409465187298704610U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 13U)) + 3470222286110333500U) + aNonceWordF;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 5704486785203069994U) + aNonceWordO;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 11U)) + 10334944660253279633U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 7626852700722567477U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 14631310754943209743U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1958866541508493967U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 807160297237854120U) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 5624154783624196107U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2404066593958052159U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4971444394698940423U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6340057638461027062U;
            aOrbiterD = RotL64((aOrbiterD * 12027586111086798629U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9003019862787819481U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 13632057463595873033U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 12575202147280216765U), 13U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 12766104026871797746U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4062118445824915939U;
            aOrbiterB = RotL64((aOrbiterB * 13130770039048080701U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 14U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 27U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 30U) + aOrbiterB) + RotL64(aOrbiterC, 19U)) + aNonceWordC);
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterE, 41U)) + aPhaseBWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 5U)) + aOrbiterE) + aPhaseBWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterD, 54U)) + RotL64(aCarry, 51U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16989U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((aIndex + 20825U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18646U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20325U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 56U)) + (RotL64(aIngress, 39U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 57U)) + 16802219662864902427U) + aPhaseBOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 14332033461409490629U) + aNonceWordK;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 29U)) + 8781794298640286845U;
            aOrbiterI = (((aWandererB + RotL64(aCross, 46U)) + RotL64(aCarry, 5U)) + 8459933908074937264U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aPrevious, 5U)) + 1883580287986004426U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17500258188004626118U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 7934811305150872870U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10039004285642030761U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 6380363892361098905U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 12623079132626676910U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 12406671746344127399U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 10455208121949202703U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8805532707916767629U;
            aOrbiterI = RotL64((aOrbiterI * 666082374369701881U), 39U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 9161544391400377699U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3501434325829663268U;
            aOrbiterB = RotL64((aOrbiterB * 7933545151293799637U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 651783304096081996U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 441505031509930622U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 8045355432310956143U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 40U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 29U)) + aPhaseBWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 60U));
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 21U)) + aOrbiterI) + aNonceWordJ);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 50U) + aOrbiterI) + RotL64(aOrbiterJ, 51U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererI, 56U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordN);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 26216U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 23444U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23287U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 26726U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 13U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCarry, 26U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = (aWandererJ + RotL64(aIngress, 43U)) + 10805654776556844351U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 582794182442795335U) + aNonceWordH;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 53U)) + 2858343650974681068U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 8189584049022064284U) + aNonceWordO;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 12U)) + RotL64(aCarry, 53U)) + 1565100751996962893U) + aPhaseBOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 8062028016947611891U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 8280504280578451745U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5212851648135050483U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11326869194491655350U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1671695656567777163U;
            aOrbiterB = RotL64((aOrbiterB * 7511554500524257921U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2349843105293943452U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 13015545152052004254U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 1316662811685429983U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16703354404749291869U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8713231044374305801U;
            aOrbiterF = RotL64((aOrbiterF * 9242480982197688625U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 11118401674497783533U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14857556493734710364U;
            aOrbiterC = RotL64((aOrbiterC * 3452566050389715195U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterF, 24U)) + aNonceWordG);
            aWandererD = aWandererD + ((((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 11U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 53U)) + aOrbiterB) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 5U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 58U) + aOrbiterB) + RotL64(aOrbiterJ, 13U)) + aNonceWordA) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31449U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30753U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30370U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((aIndex + 30993U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 36U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = ((((aWandererA + RotL64(aScatter, 4U)) + RotL64(aCarry, 29U)) + 5480870806135400132U) + aPhaseBOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 39U)) + 8034874599430768743U) + aPhaseBOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aCross, 13U)) + 4006919843736863767U) + aNonceWordH;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 2988069748674633718U;
            aOrbiterC = (((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 43U)) + 12347295651973135786U) + aNonceWordJ;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 14152683894431568192U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 15765143815254196598U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8948877544291035189U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10473067082331244233U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1089466925383677249U;
            aOrbiterB = RotL64((aOrbiterB * 17334888609179149753U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13215039929873682230U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3957997712247961479U;
            aOrbiterH = RotL64((aOrbiterH * 7631186240013784703U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10023907397941685546U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14593012591254614353U;
            aOrbiterA = RotL64((aOrbiterA * 17111300092082154687U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 13353797968154036726U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 9259966668512102858U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 8326732574268308221U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 6U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterC, 5U)) + aPhaseBWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterA, 19U)) + aOrbiterB) + aNonceWordE);
            aWandererK = aWandererK + ((((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 35U)) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 4U) + aOrbiterH) + RotL64(aOrbiterK, 39U));
            aWandererA = aWandererA + (((((RotL64(aCross, 13U) + RotL64(aOrbiterA, 52U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aNonceWordF) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 38U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordK);
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

void TwistExpander_Karate_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCA77F8DDCE7C0E53ULL + 0x83B5ED897C5A6724ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC6EABD664D6316B5ULL + 0xF503F500FD040C12ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8680F7BFDF02A26DULL + 0x96DE03449672E16BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD2BED760339E68C9ULL + 0xEEC71AABA838B569ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x91DB583A24026D8DULL + 0xA9EEDB7DDBFB8AE8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFE742EC26CD0D1EBULL + 0xEB4BA3BE4D5EAA29ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9A5637DA2E8EA4E7ULL + 0xBFF39188D1BA6563ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE0CE35D163F63381ULL + 0xD5474018D632953BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xE28662C7539ABCCBULL + 0xF64A103F415267BAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB108EACE1A345D1DULL + 0xB2CC05F9ED28D47CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x855D824E6752B063ULL + 0xFFEC763A52D05006ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9D31306BAF15A161ULL + 0xE363DF94123999B8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x89308B66B00FE395ULL + 0x9B4778DB0EB5388DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB674716951149FA7ULL + 0xB4E5728038C1E0C3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC04735BEC1E50FF9ULL + 0xAA3C995676A5A2B7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x889C8B27E21ECB7DULL + 0x97821C9F4A3C8320ULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4235U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 4128U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7211U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((aIndex + 587U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 24U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 37U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterB = (aWandererE + RotL64(aScatter, 5U)) + 13499155707765393469U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 53U)) + 3740324981823726185U;
            aOrbiterA = (aWandererK + RotL64(aCross, 35U)) + 5470765363949735652U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 47U)) + 3446436171274452326U) + aNonceWordL;
            aOrbiterC = ((aWandererD + RotL64(aCross, 28U)) + 1778929412631211933U) + aPhaseCOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 14666308799855220954U) + aPhaseCOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 4548410236791175055U) + aNonceWordF;
            aOrbiterG = (aWandererF + RotL64(aScatter, 21U)) + 5829739767694190372U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 12U)) + RotL64(aCarry, 37U)) + 14319231414903675748U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1513851750246111405U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1685620217748986019U;
            aOrbiterA = RotL64((aOrbiterA * 9286548037413609445U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16284162182006054402U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6271539598462003309U;
            aOrbiterF = RotL64((aOrbiterF * 13923286694131331137U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12669312437565969473U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11894755313393001665U;
            aOrbiterG = RotL64((aOrbiterG * 12556759675372354075U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6315983824634946566U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17106616474222892782U;
            aOrbiterH = RotL64((aOrbiterH * 167205520766791073U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 13350266700180455548U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 4608846311203767162U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2504857468837437365U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14195866746143604365U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7917977448256795054U;
            aOrbiterK = RotL64((aOrbiterK * 5927771378657284557U), 35U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 10707336923305131629U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17122696159336995392U;
            aOrbiterJ = RotL64((aOrbiterJ * 13953518568670659191U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5182322763573586116U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6503754948502556246U;
            aOrbiterE = RotL64((aOrbiterE * 14749002194140663519U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 14907832047832987341U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6258064448676621346U;
            aOrbiterC = RotL64((aOrbiterC * 4407960312705621487U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 30U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 24U) + aOrbiterG) + RotL64(aOrbiterJ, 27U)) + aNonceWordI) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 60U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterE, 37U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 53U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterA, 43U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 13U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterC, 47U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 4U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 54U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11243U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15023U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15609U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneB[((aIndex + 11504U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 4U) ^ RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = (aWandererB + RotL64(aCross, 27U)) + 12222235191147985484U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 6U)) + 16367317014523328414U) + aPhaseCOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 11U)) + 3511378091284703789U) + aNonceWordP;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 21U)) + 15247492830966725949U;
            aOrbiterD = (aWandererH + RotL64(aCross, 37U)) + 7745995913390407897U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 51U)) + 6463593307540108810U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 47U)) + 1101669311005268630U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 52U)) + RotL64(aCarry, 43U)) + 12988052764067518580U;
            aOrbiterE = (aWandererD + RotL64(aCross, 57U)) + 17717179747434679772U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11662190906682400416U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 6563014073547628748U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16967910471722117761U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13099094932059419219U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16342730862261868847U;
            aOrbiterD = RotL64((aOrbiterD * 10988124108686164829U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16855346813127524624U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6570063128502306944U;
            aOrbiterK = RotL64((aOrbiterK * 4571570049463124831U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11328352033809240501U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11640986648833160901U;
            aOrbiterA = RotL64((aOrbiterA * 2895830492089678919U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 2675226158571501666U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17700531248266458165U;
            aOrbiterE = RotL64((aOrbiterE * 2231403813970188657U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 7729597396731910874U) + aNonceWordO;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 15172374484412053756U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 149009041406406517U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 9178769489257842683U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9020154972097834926U;
            aOrbiterG = RotL64((aOrbiterG * 8910504667566521429U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 1317403761217790562U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 17151528554929201571U;
            aOrbiterH = RotL64((aOrbiterH * 3735945655450625203U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11621882033959669977U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10289504450815075623U;
            aOrbiterI = RotL64((aOrbiterI * 13365982786836243195U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 39U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 36U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 58U) + aOrbiterE) + RotL64(aOrbiterK, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 6U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 39U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterG, 11U)) + aOrbiterK) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterA, 47U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterG, 35U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 22U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterH, 53U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 43U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 14U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordG);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21271U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22783U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19155U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 21618U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 36U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterB = (aWandererG + RotL64(aIngress, 13U)) + 3973833383430652211U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 39U)) + 5760227042747169187U) + aPhaseCOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 41U)) + 4923009065139227286U) + aNonceWordA;
            aOrbiterG = ((aWandererA + RotL64(aCross, 60U)) + 1477807307009107590U) + aNonceWordO;
            aOrbiterD = (aWandererK + RotL64(aScatter, 27U)) + 5707194514329007301U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 5U)) + 5340439728375269724U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 17080457898946572387U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 35U)) + 281559150259472813U) + aPhaseCOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 50U)) + RotL64(aCarry, 27U)) + 16160633048230910560U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9003989610509592121U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10579322462808454333U;
            aOrbiterI = RotL64((aOrbiterI * 100832431598087235U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15059383289528723069U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 10417647757852880956U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1457919230286043137U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14484665027393813330U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12344463053485837974U;
            aOrbiterG = RotL64((aOrbiterG * 5762654194001525041U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 5826453246659297805U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12547902286376986223U;
            aOrbiterC = RotL64((aOrbiterC * 2982850000322672789U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9637855144278126174U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 2132744427444501938U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5911587798564836199U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9248933938130311231U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 13274297928717090383U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2901398809555237563U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3690262236918560930U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3626005326410800344U;
            aOrbiterE = RotL64((aOrbiterE * 13030443356669355355U), 27U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 10801089744186148218U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5446653082176311031U;
            aOrbiterJ = RotL64((aOrbiterJ * 4594267575901248321U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3205541585889107366U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 4532327942368884436U;
            aOrbiterF = RotL64((aOrbiterF * 16287094987689326229U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 12U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 38U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 47U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 23U) + RotL64(aOrbiterF, 41U)) + aOrbiterE) + aNonceWordH) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterB, 52U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 46U) + aOrbiterA) + RotL64(aOrbiterE, 57U)) + aNonceWordJ);
            aWandererK = aWandererK + ((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterD, 19U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterI, 27U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 23U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 35U)) + aOrbiterC) + aNonceWordF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterA, 4U)) + aOrbiterD) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32700U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 26356U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25269U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneD[((aIndex + 32578U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 47U)) + (RotL64(aIngress, 20U) ^ RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 19U)) + 16462052553719977502U) + aNonceWordH;
            aOrbiterC = (aWandererF + RotL64(aScatter, 47U)) + 12337064059566619581U;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 36U)) + 15801005007094515447U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (aWandererA + RotL64(aCross, 57U)) + 8228706742665081656U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 37U)) + 11006723027845190869U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 18173765337829177450U) + aNonceWordL;
            aOrbiterK = (aWandererE + RotL64(aCross, 53U)) + 530215083653542558U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 12U)) + RotL64(aCarry, 47U)) + 6608611827035564511U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 41U)) + 2246051826221626809U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5228575308895381421U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10999213210689606857U;
            aOrbiterI = RotL64((aOrbiterI * 5467601259546342925U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 3773371037240485696U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8887985779436152504U;
            aOrbiterB = RotL64((aOrbiterB * 698713082830739677U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11150566414723818350U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8336366151003049546U;
            aOrbiterK = RotL64((aOrbiterK * 9033771197242493699U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 13233968794237090787U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8172558473508478819U;
            aOrbiterJ = RotL64((aOrbiterJ * 17837070423649268435U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 133564480283347997U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 15104810248883567064U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 706802420642303533U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9138629520201127075U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 13993086066341664080U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4875046427147105077U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6547273508580516932U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9838727018769865759U;
            aOrbiterF = RotL64((aOrbiterF * 11395273371936839815U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11685694999526122626U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 8945983172566303116U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17791527981004597623U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17606249889617356327U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9296903152000480008U;
            aOrbiterC = RotL64((aOrbiterC * 18066622289408024413U), 39U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 50U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 60U) + RotL64(aOrbiterC, 29U)) + aOrbiterG) + aPhaseCWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterK, 43U));
            aWandererC = aWandererC + (((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 11U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 3U)) + aPhaseCWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterH, 60U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 37U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 47U)) + aOrbiterB) + aNonceWordD);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 12U) + aOrbiterB) + RotL64(aOrbiterG, 51U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterD, 20U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ aNonceWordD;
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Karate_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF108B9457BB3BA53ULL + 0x8439788964ED65F2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC78292742B3D3FCFULL + 0xAF008ADA95CA7411ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF2A6C30FB9657F2DULL + 0x94C6E899B326934CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDB9CB8554C193DE9ULL + 0xB84E02757B60F6BEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEE8A92B77D1D6E47ULL + 0xD3751A527FC60F88ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA4F544A41C1B5777ULL + 0x86313B6EBD5A9A3FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA74678730BF17F1FULL + 0xC5B9D1C64A50E30CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x876FD7A50B65EF7DULL + 0x98A57FFCA101EB8DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD69AE444D5D0066DULL + 0xE6C3D5CDDD8BD05FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF4D1C08973BF0325ULL + 0xF1CC7C72F6C9EFCBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB7C3D58CE54DC375ULL + 0xF64294E9BBE9AEA4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xEB40A76E39F55C41ULL + 0xBFC7DD9A485E6368ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x80FF9B901C4B8F27ULL + 0x8E84D7A822A0F195ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA69A4D7B5D06B033ULL + 0x94009E461922FBB8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8456A78A1430D111ULL + 0x863D2A4226A8A34EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xDE457F6903A2ECBFULL + 0xF7C6DB367864A71CULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1324U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((aIndex + 1447U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2774U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1805U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 24U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 52U)) + RotL64(aCarry, 37U)) + 2915859148137000694U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 21U)) + 210680583721444425U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 6668118118775650387U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 43U)) + 15794200818099010989U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 41U)) + 6565076707062828369U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 13U)) + 16323164497808856719U) + aNonceWordP;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 35U)) + 7965435318816716560U) + aNonceWordH;
            aOrbiterD = (aWandererB + RotL64(aCross, 29U)) + 7390281030573369017U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 37U)) + 2269738866911824875U) + aPhaseDOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aCross, 50U)) + RotL64(aCarry, 19U)) + 9664014216039993873U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 11U)) + 18284857398028357633U) + aPhaseDOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 367667619795303009U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 7935945060956274197U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 5481786693511955209U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16683666162337789540U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10655658270998102390U;
            aOrbiterI = RotL64((aOrbiterI * 15231596813382239841U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8307037916581540297U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 3247742749860703524U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15052136713218656641U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10446792483683818139U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16374602929344972364U;
            aOrbiterH = RotL64((aOrbiterH * 12599903932725787599U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 2411334498322777183U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1093701164116833765U;
            aOrbiterE = RotL64((aOrbiterE * 13129220206835381729U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17018480952982840635U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 17348395690080029814U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6212591395713433257U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 16111252311283623152U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12776492920397785951U;
            aOrbiterK = RotL64((aOrbiterK * 6136009241593081821U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12214538600808144816U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10043377462096783363U;
            aOrbiterJ = RotL64((aOrbiterJ * 14639467375095185877U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5101561512438055661U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3683207847147603335U;
            aOrbiterA = RotL64((aOrbiterA * 14355438383379198639U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14446947359104987749U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 7596096688268335354U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 13522935803383107145U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14015424109468938015U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2915859148137000694U;
            aOrbiterC = RotL64((aOrbiterC * 3653144205211106817U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 44U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 35U)) + aNonceWordK);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterC, 5U));
            aWandererF = aWandererF + ((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 53U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 19U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterF, 26U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 60U) + aOrbiterA) + RotL64(aOrbiterK, 11U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 3U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterF, 21U)) + aOrbiterB) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterB, 37U)) + aPhaseDWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterD, 39U)) + aNonceWordI);
            aWandererC = aWandererC + (((RotL64(aCross, 56U) + RotL64(aOrbiterE, 58U)) + aOrbiterB) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6376U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((aIndex + 6629U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7493U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 5690U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 39U)) + (RotL64(aCarry, 57U) + RotL64(aIngress, 6U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 10805654776556844351U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 21U)) + 582794182442795335U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 2858343650974681068U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 27U)) + 8189584049022064284U) + aNonceWordK;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 47U)) + 1565100751996962893U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 30U)) + RotL64(aCarry, 5U)) + 8062028016947611891U) + aNonceWordC;
            aOrbiterF = (aWandererI + RotL64(aCross, 39U)) + 8280504280578451745U;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 43U)) + 11326869194491655350U) + aPhaseDOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 53U)) + 1671695656567777163U;
            aOrbiterC = (aWandererD + RotL64(aCross, 11U)) + 2349843105293943452U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 58U)) + 13015545152052004254U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16703354404749291869U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8713231044374305801U;
            aOrbiterA = RotL64((aOrbiterA * 9242480982197688625U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11118401674497783533U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14857556493734710364U;
            aOrbiterB = RotL64((aOrbiterB * 3452566050389715195U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12953419670951660965U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 12666121730825089017U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14049925256934142519U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11075249639473053423U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9374217688244187867U;
            aOrbiterF = RotL64((aOrbiterF * 5261156325627117877U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17608340953291367867U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13159437499327086340U;
            aOrbiterD = RotL64((aOrbiterD * 4882100944453534805U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4304700511322366815U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10172544755256706767U;
            aOrbiterH = RotL64((aOrbiterH * 4013006212154771797U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17340067939877432472U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14130447570008179105U;
            aOrbiterJ = RotL64((aOrbiterJ * 8178075071208718915U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2652532710498072378U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10384945384238518296U;
            aOrbiterI = RotL64((aOrbiterI * 17137694272394304045U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 15292159041119433363U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 12103644911645285108U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4565615406415614103U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16307525158627275744U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 3786908390177579447U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 6592585847755318801U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13595883419843505634U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10805654776556844351U;
            aOrbiterK = RotL64((aOrbiterK * 10956465099104915639U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 39U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterA, 44U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 35U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK) + aNonceWordJ);
            aWandererB = aWandererB + ((RotL64(aScatter, 30U) + aOrbiterG) + RotL64(aOrbiterJ, 3U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterI, 53U)) + aPhaseDWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 18U)) + aOrbiterB);
            aWandererF = aWandererF ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterH, 41U)) + aOrbiterE) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 23U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterF, 13U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterF, 51U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 10U)) + aOrbiterA) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 20U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14943U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16296U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14671U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 14782U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 41U)) + 7825479804710770560U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 47U)) + 5298124167101358123U;
            aOrbiterA = ((((aWandererH + RotL64(aCross, 36U)) + RotL64(aCarry, 23U)) + 17774541024369233726U) + aPhaseDOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 53U)) + 7679371833537454082U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 19U)) + 5385914900748772224U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 3879781930908486531U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 14U)) + 659110346638873236U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 39U)) + 10749021728538539749U;
            aOrbiterB = (aWandererI + RotL64(aCross, 41U)) + 3631252455767429457U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 21U)) + 2271978810960685021U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 51U)) + 5963558780692551176U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 974909966119198104U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9296998242911152296U;
            aOrbiterA = RotL64((aOrbiterA * 2613629915877957661U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2245318466901521959U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13391076374843288568U;
            aOrbiterI = RotL64((aOrbiterI * 18094558036982107419U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6184487746594236737U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1563385912137291418U;
            aOrbiterF = RotL64((aOrbiterF * 4805455299959232321U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1744840092006498629U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 2100927276837188416U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3541788262067077997U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9998911862807246338U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 12239948725635220096U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7098620484129489129U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3307447094994950246U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12746613971448298932U;
            aOrbiterH = RotL64((aOrbiterH * 9463975886346934681U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 11577488293733790649U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 191108997585598809U;
            aOrbiterJ = RotL64((aOrbiterJ * 9574978681405356871U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 18096145693841273722U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10026281133603934071U;
            aOrbiterD = RotL64((aOrbiterD * 17261343107314203471U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 2346682418062064668U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2996178204018644206U;
            aOrbiterG = RotL64((aOrbiterG * 2552965800703390909U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15085425896818988223U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 1589593231782852588U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 1535556765195388675U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17170695588248383518U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7825479804710770560U;
            aOrbiterK = RotL64((aOrbiterK * 7434218282170150533U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 26U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterA, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterB, 21U));
            aWandererH = aWandererH + (((((RotL64(aCross, 4U) + aOrbiterF) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 53U)) + aNonceWordE) + aPhaseDWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 56U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterK, 27U));
            aWandererF = aWandererF + (((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterI, 41U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 46U) + aOrbiterH) + RotL64(aOrbiterA, 3U)) + aNonceWordC) + aPhaseDWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterI, 35U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 10U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordN);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 20029U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21630U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16926U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneD[((aIndex + 20976U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 22U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 43U)) + 2101601659597850213U) + aNonceWordG;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 39U)) + 2759794072560720121U) + aNonceWordH;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 48U)) + 9443562552411269339U;
            aOrbiterJ = ((((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 10801360546699857975U) + aPhaseDOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 8020716394829332019U;
            aOrbiterB = (aWandererC + RotL64(aCross, 41U)) + 1021894212367773801U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 37U)) + 13346855534622490176U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 13U)) + 16359309548462953836U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 19U)) + 12642446944680783519U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 60U)) + 8197424982767553380U) + aPhaseDOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aCross, 35U)) + 14346334610901859094U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14171304260534233539U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 334531601308283605U;
            aOrbiterD = RotL64((aOrbiterD * 5012968232749075075U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10707856298471572695U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 18364775750091914766U;
            aOrbiterK = RotL64((aOrbiterK * 15735143943129143265U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8531394793118363836U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15352876929406908882U;
            aOrbiterB = RotL64((aOrbiterB * 475199047053777179U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 567682016232278157U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2068146551757663119U;
            aOrbiterC = RotL64((aOrbiterC * 1557877740957797555U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7776122587613256525U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 16430938890724272256U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4540270493783593257U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11912000645055436094U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16800749242578741498U;
            aOrbiterE = RotL64((aOrbiterE * 17804584625034241737U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5909199180260499150U) + aNonceWordO;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 5751089915336865588U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15376689503142397927U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3478216857728853008U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 18007567146937338241U;
            aOrbiterF = RotL64((aOrbiterF * 6620498877303917855U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17454259424163653490U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6276120962018305311U;
            aOrbiterH = RotL64((aOrbiterH * 7560618224285018801U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3839336239901666431U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6230149015045237670U;
            aOrbiterA = RotL64((aOrbiterA * 1838983748994340883U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17552095486612766544U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 2101601659597850213U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2915330118061857271U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 60U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterD, 21U)) + aPhaseDWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 40U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 56U) + RotL64(aOrbiterB, 35U)) + aOrbiterC) + aNonceWordC);
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 53U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterF, 43U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterG, 56U));
            aWandererG = aWandererG + (((RotL64(aIngress, 6U) + aOrbiterD) + RotL64(aOrbiterG, 11U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 29U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + RotL64(aOrbiterA, 51U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterI, 37U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 6U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 34U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordG;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24891U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26679U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22756U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23013U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 4U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 47U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = (aWandererJ + RotL64(aIngress, 39U)) + 1142447269198373880U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 18U)) + 10581460640040336191U;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 21U)) + 14703062773878202900U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aCross, 27U)) + 15737525756286914746U) + aNonceWordB;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 16178774478273186999U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aPrevious, 13U)) + 2514897053906809160U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 29U)) + 13702496607592508464U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 46U)) + 18030885275418337965U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 35U)) + 5241783876161655984U) + aNonceWordN;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 21U)) + 2807052676283587925U) + aNonceWordH;
            aOrbiterB = (aWandererG + RotL64(aIngress, 29U)) + 8022804576763271327U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15597099852232205860U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 1538435607932096400U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 7900752511710516981U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11147868774413615365U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9325213746830411568U;
            aOrbiterG = RotL64((aOrbiterG * 561819005818948769U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 13792300423550555634U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3134856508983945719U;
            aOrbiterF = RotL64((aOrbiterF * 4271845067763664863U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 8654966018053784882U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8937113935476779267U;
            aOrbiterC = RotL64((aOrbiterC * 7386875687217705855U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4135676350355234788U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11407912615743682678U;
            aOrbiterA = RotL64((aOrbiterA * 2773506587480714695U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10966950663872392059U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6686634993700944582U;
            aOrbiterE = RotL64((aOrbiterE * 2509459942163678241U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14154407529749257990U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 18054640398549782388U;
            aOrbiterD = RotL64((aOrbiterD * 7830759861389060149U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14623473030642960240U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1857945571104460086U;
            aOrbiterH = RotL64((aOrbiterH * 18039903315045620079U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 17650774450811065797U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 9458168381246672881U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3452665113988737563U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16604923466236483242U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12447748535184711684U;
            aOrbiterJ = RotL64((aOrbiterJ * 5982708155382249061U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9589720286549780720U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1142447269198373880U;
            aOrbiterI = RotL64((aOrbiterI * 8176719948031280789U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 38U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterG, 42U));
            aWandererI = aWandererI + (((RotL64(aScatter, 28U) + aOrbiterG) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterJ, 21U));
            aWandererG = aWandererG + ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 19U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterC, 39U));
            aWandererD = aWandererD + (((RotL64(aCross, 60U) + aOrbiterA) + RotL64(aOrbiterB, 27U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterF, 29U));
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterG, 56U)) + RotL64(aCarry, 57U)) + aNonceWordD) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 47U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ) + aNonceWordK);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 3U)) + aOrbiterB) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 12U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 6U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29436U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31603U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32148U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28054U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aPrevious, 11U)) + (RotL64(aIngress, 41U) ^ RotL64(aCross, 29U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = (((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 2225397913940961213U) + aNonceWordM;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 21U)) + 8342544893601343643U) + aPhaseDOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aIngress, 47U)) + 162922186381417187U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 11660218373710972210U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 24U)) + 14909034764605802354U;
            aOrbiterF = (aWandererC + RotL64(aCross, 11U)) + 16776955237009701511U;
            aOrbiterH = ((((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 5834487809188925253U) + aPhaseDOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 27U)) + 1498492772767040320U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 51U)) + 4161765458781579617U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 19U)) + 10511923076962447765U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 54U)) + 8575954471692620021U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6536325446331340573U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 1790628986900286346U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5262997114200816715U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2623814807619278590U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 11676970995834706612U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10057461115132434901U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13836786354224256591U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 6293096163612129260U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8977954126326217153U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 4271144764978661248U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 15938494256992560202U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 10004841288382726739U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11038155227307702976U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12408749795071243930U;
            aOrbiterB = RotL64((aOrbiterB * 5527720475032868855U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1673665849053496882U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12866353361497103629U;
            aOrbiterC = RotL64((aOrbiterC * 6041125499398924871U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10673935802381580966U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8946776538955520352U;
            aOrbiterK = RotL64((aOrbiterK * 12293084177712710021U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16294935203370452805U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4697759331563852212U;
            aOrbiterD = RotL64((aOrbiterD * 14407806317275373043U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17633118874112283386U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 89602424202721105U;
            aOrbiterE = RotL64((aOrbiterE * 1010654844008668685U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4019154066191316616U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15029609435149173243U;
            aOrbiterJ = RotL64((aOrbiterJ * 3522168783248806167U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11765990698273078458U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2225397913940961213U;
            aOrbiterA = RotL64((aOrbiterA * 8471538922288466221U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 36U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterK, 51U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterI, 21U));
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 58U)) + aNonceWordL);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 39U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aCross, 40U) + aOrbiterE) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterI, 43U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 41U)) + aOrbiterB);
            aWandererF = aWandererF ^ (((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterC, 27U)) + aNonceWordJ);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 58U) + aOrbiterH) + RotL64(aOrbiterE, 60U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 23U)) + aOrbiterH) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ aNonceWordG;
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

void TwistExpander_Karate_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB1D57C9FCB440EB5ULL + 0x9A59AC742F195D92ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDE4B39A4E65D156BULL + 0xAD567AD1B3111C2EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF671CE31D9C2992DULL + 0x8E2FB8F5CC52E22AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC4886E75650714F1ULL + 0xAB6A4D4893EABC5EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xAD375F5D4BE93EB3ULL + 0xEC66C514CD1A7765ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD1573FB40F4BD7D9ULL + 0xA1AD54143E79E2FEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD072512D067EBC35ULL + 0x9C2DB5FA26B39B25ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC027D9ABB160DCF3ULL + 0xA1DEF793FEE9ACDDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x9B56B097774D1203ULL + 0xB278A55589531DC3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xCE00439FCC5CBFE5ULL + 0xCAE2087EC171B5B3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xEDF85662D3BA5CA3ULL + 0x8995CA38F7FC33ABULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xCDC58C48505B0659ULL + 0x857A9971039FE393ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8C09B3D5BC3840DFULL + 0xEAF6F61380CBED9FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB639C3F63F24A4F7ULL + 0xFF2D9FE58E2D6E10ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB34AFEB1F64D489FULL + 0xE70BF506893762B3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCA3137D1CA3DE343ULL + 0x99D5F405D247492EULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 286U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 3846U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5458U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((aIndex + 1739U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aIngress, 56U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = (aWandererF + RotL64(aIngress, 10U)) + 12690502671561165478U;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 29U)) + 17519943923428102801U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 10705515807975331385U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 47U)) + 16586447272278538179U;
            aOrbiterK = (aWandererH + RotL64(aCross, 57U)) + 8006560996840971798U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 53U)) + 12928600185788857701U) + aNonceWordM;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 14240723153798267172U) + aNonceWordH;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 37U)) + 8636219177994872072U) + aPhaseEOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aScatter, 37U)) + 7586790235186467512U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 26U)) + 1103807034179512424U;
            aOrbiterC = (aWandererG + RotL64(aCross, 41U)) + 7547526530239498693U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 8380239679344786397U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5690809173787433519U;
            aOrbiterB = RotL64((aOrbiterB * 5354724308093372953U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8390902801141804609U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3507306189192059486U;
            aOrbiterJ = RotL64((aOrbiterJ * 18336280496510253103U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6190745292098482871U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8065418693975056902U;
            aOrbiterD = RotL64((aOrbiterD * 6414621418430102589U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12111755051718111803U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7605877769709909297U;
            aOrbiterF = RotL64((aOrbiterF * 17525248694315944599U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5969794501112646237U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 5127559299360591476U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4521563633438853069U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10593847754747739786U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 4401750688524310121U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14265829318976633707U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6927893132508779499U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4874009978647014479U;
            aOrbiterC = RotL64((aOrbiterC * 13340466017023540755U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13146693487138744677U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3298472134223595298U;
            aOrbiterH = RotL64((aOrbiterH * 2145005258008477281U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8729305340729268734U) + aNonceWordP;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 18347161842033439538U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 7952715248988302017U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 166831495912855225U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4943633045563697271U;
            aOrbiterG = RotL64((aOrbiterG * 1809857625425000137U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 2460623715340753589U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12690502671561165478U;
            aOrbiterI = RotL64((aOrbiterI * 16421139715633515623U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 24U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 14U) + aOrbiterK) + RotL64(aOrbiterI, 23U));
            aWandererA = aWandererA + (((((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 58U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aNonceWordL) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterJ, 51U));
            aWandererE = aWandererE + (((RotL64(aCross, 41U) + RotL64(aOrbiterG, 27U)) + aOrbiterH) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 58U) + aOrbiterA) + RotL64(aOrbiterE, 13U)) + aNonceWordD);
            aWandererB = aWandererB + ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 53U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 39U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + RotL64(aOrbiterC, 47U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterH, 6U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 3U)) + aOrbiterB);
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterH, 41U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 30U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 40U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 5689U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((aIndex + 5746U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7823U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 6835U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 24U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 35U)) + 5088525177670191619U) + aPhaseEOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aIngress, 6U)) + 9966456257813932112U;
            aOrbiterA = (aWandererB + RotL64(aCross, 21U)) + 7707646574027146307U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 37U)) + 75480203757681173U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 51U)) + 384659134071835163U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 3158769775373307778U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 21U)) + 17360830943513941272U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 47U)) + 5317278822721604586U) + aNonceWordB;
            aOrbiterB = (aWandererH + RotL64(aScatter, 13U)) + 1371427105215954781U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 52U)) + 3162710551223553423U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 29U)) + 5332921933853550756U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 10572462410297815854U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10234389605554817892U;
            aOrbiterA = RotL64((aOrbiterA * 2130374833440291193U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 13421365517991380605U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10186643614984034083U;
            aOrbiterE = RotL64((aOrbiterE * 8554471709467808453U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4742438973260817120U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6081590345899008846U;
            aOrbiterD = RotL64((aOrbiterD * 7069396301823124931U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 15360092808493795340U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12186413069553132646U;
            aOrbiterI = RotL64((aOrbiterI * 3815981440611914267U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16756221656224451552U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12232880965861373143U;
            aOrbiterB = RotL64((aOrbiterB * 14196910735715726471U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10090954323470840557U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15615770271463853537U;
            aOrbiterJ = RotL64((aOrbiterJ * 13544181592829027283U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 556029032505658411U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13311879111583579039U;
            aOrbiterF = RotL64((aOrbiterF * 3924744868168749003U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8646360871497847336U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2064833941982069154U;
            aOrbiterH = RotL64((aOrbiterH * 10016546852137913163U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1701847261278886621U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9654208200019718374U;
            aOrbiterC = RotL64((aOrbiterC * 4398089490129603677U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14276143262844412074U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 10738184916176200661U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 8940267914440361883U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 2966052720680305600U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5088525177670191619U;
            aOrbiterK = RotL64((aOrbiterK * 11621585388684456139U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 58U);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterI, 5U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ) + aNonceWordG);
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 29U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterF, 27U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterG, 21U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterJ, 13U)) + aPhaseEWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterH, 24U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 38U) + RotL64(aOrbiterE, 51U)) + aOrbiterD) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterB, 35U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterF, 39U)) + aNonceWordA);
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterH, 18U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 54U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 4U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 14689U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11625U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15070U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15180U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 22U) ^ RotL64(aCross, 37U)) + (RotL64(aCarry, 57U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 56U)) + RotL64(aCarry, 39U)) + 9774364261626083532U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 21U)) + 18059001521926116420U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 10615626210406381148U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 3U)) + 10536484278007898620U) + aNonceWordI;
            aOrbiterH = (((aWandererH + RotL64(aCross, 51U)) + 13320663045139972700U) + aPhaseEOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 5U)) + 17127001787268166583U) + aNonceWordO;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 16742574590844166551U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 47U)) + 8347719720758228053U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aCross, 43U)) + 13502468705946051986U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 35U)) + 3512687886188904904U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 14U)) + 495660316165795934U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5092722552034477356U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15641128019608284015U;
            aOrbiterA = RotL64((aOrbiterA * 3621036395703527059U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15421873776811085458U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 17978775513204574125U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 18359600395119440183U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 16617179197537669849U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1931805387534012528U;
            aOrbiterE = RotL64((aOrbiterE * 3400139345857733775U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9544923119559308431U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12930999400470173353U;
            aOrbiterH = RotL64((aOrbiterH * 16791006919271490005U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13673733276226249890U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2032263473309124738U;
            aOrbiterD = RotL64((aOrbiterD * 3088728329261360607U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14868502349358414206U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10116495537187552321U;
            aOrbiterC = RotL64((aOrbiterC * 1380512121796709469U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5341113995358179244U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8415417980279705731U;
            aOrbiterJ = RotL64((aOrbiterJ * 8521501372683793821U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 2462819265072352463U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7657062767608441931U;
            aOrbiterI = RotL64((aOrbiterI * 15554638801273540163U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8153420530633265789U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10990681417675210534U;
            aOrbiterB = RotL64((aOrbiterB * 1928509513380702895U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17035995983178569271U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2806563871848226777U;
            aOrbiterG = RotL64((aOrbiterG * 4137935663733587867U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 6570698907081812011U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9774364261626083532U;
            aOrbiterK = RotL64((aOrbiterK * 1766375419340392741U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 12U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterF, 27U));
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 23U)) + aOrbiterA) + aNonceWordN);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterK, 60U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 51U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aCross, 44U) + RotL64(aOrbiterB, 43U)) + aOrbiterD) + aNonceWordB) + aPhaseEWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 19U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 41U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterA, 5U));
            aWandererC = aWandererC + (((RotL64(aCross, 12U) + aOrbiterC) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + RotL64(aWandererF, 6U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 19049U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((aIndex + 21400U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17075U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20602U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 10U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = (aWandererA + RotL64(aScatter, 5U)) + 3236820517816085022U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 47U)) + 741288875914097926U) + aPhaseEOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aPrevious, 21U)) + 8417246926007729580U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 27U)) + 9715717805774537170U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 14360243844821619482U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 53U)) + 10760908100206775334U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 60U)) + RotL64(aCarry, 11U)) + 3434641779946167811U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 35U)) + 7885568822756234567U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 23U)) + 3041563437672051294U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 43U)) + 15761355327564963516U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 38U)) + 1158633562785937421U) + aNonceWordI;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9338581575871970653U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9172038894262857354U;
            aOrbiterC = RotL64((aOrbiterC * 3110871165285625807U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14653924713599790081U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3854497592598563309U;
            aOrbiterD = RotL64((aOrbiterD * 11737111068815795303U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16286980180327600557U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 5092583772591249756U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 13955105624639442903U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4288397994175567333U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15584236478994873104U;
            aOrbiterB = RotL64((aOrbiterB * 1860480595862755379U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 5557463939827483792U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2659814275753280856U;
            aOrbiterA = RotL64((aOrbiterA * 17702430405693184643U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6941807963525063449U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2040598555191211307U;
            aOrbiterF = RotL64((aOrbiterF * 14750544987531722765U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 347572666231116258U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 779304821185302523U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14180254150318109855U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10632524582873079742U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9761308771280517212U;
            aOrbiterI = RotL64((aOrbiterI * 13926235411726048921U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 2097439707055737964U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 2813977930321463948U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14983538728730662603U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6080592019313796689U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5396623654821376409U;
            aOrbiterH = RotL64((aOrbiterH * 15478858835919398677U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8460497459575045342U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3236820517816085022U;
            aOrbiterJ = RotL64((aOrbiterJ * 5530411244458067093U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 14U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterI, 23U)) + aNonceWordH);
            aWandererI = aWandererI + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 14U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 51U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aCross, 37U) + RotL64(aOrbiterA, 37U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 3U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aPrevious, 34U) + aOrbiterK) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 19U)) + aOrbiterE) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 5U) + RotL64(aOrbiterG, 5U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 41U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterD, 27U)) + aPhaseEWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 40U) + RotL64(aOrbiterE, 54U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 27108U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24465U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22141U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 26548U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 13U) + RotL64(aCross, 58U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 13U)) + 15813325389431304548U) + aPhaseEOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aIngress, 47U)) + 2223874171125403602U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 5510483568496824130U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 30U)) + RotL64(aCarry, 57U)) + 15474152493495661876U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 21U)) + 16846339705130829195U) + aNonceWordB;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 43U)) + 1289670576865739669U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 39U)) + 18017354919647006944U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aIngress, 41U)) + 8539685539928984921U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 37U)) + 3333721400836704048U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 29U)) + 2261560416623815491U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 60U)) + 4377786131746816567U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 18047393176583722719U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8184724021940434631U;
            aOrbiterC = RotL64((aOrbiterC * 9800116157750921119U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10469895939183324807U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14543391765109879223U;
            aOrbiterI = RotL64((aOrbiterI * 4817987697437667225U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5757225781746158178U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3539000495894022869U;
            aOrbiterF = RotL64((aOrbiterF * 1032298408884695925U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11288971092707065923U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 2761384065186568294U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3323838837427471051U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7120580145300417101U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6977246291769372866U;
            aOrbiterH = RotL64((aOrbiterH * 15170353875184253779U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17625434527765525937U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 3299714663631376190U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 6532628892760776767U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10331889953489885250U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 8550932256881727932U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13085531621192583719U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11151195711186126257U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2552002192824926483U;
            aOrbiterJ = RotL64((aOrbiterJ * 9754056316698523849U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 8038115194286715268U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16594489591573505305U;
            aOrbiterG = RotL64((aOrbiterG * 1241387574663818247U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 13476964484361081681U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2136330439951908303U;
            aOrbiterK = RotL64((aOrbiterK * 12728359054660550527U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 231990686776499700U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15813325389431304548U;
            aOrbiterE = RotL64((aOrbiterE * 9155088985405261637U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 50U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 11U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterJ, 19U)) + aNonceWordD);
            aWandererE = aWandererE + (((RotL64(aPrevious, 52U) + RotL64(aOrbiterF, 53U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 28U)) + aPhaseEWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 47U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterA, 51U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 5U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 50U) + aOrbiterI) + RotL64(aOrbiterH, 43U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterC, 56U)) + aNonceWordL);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 13U)) + aOrbiterG) + aPhaseEWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordD;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27795U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((aIndex + 28799U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31241U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27805U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 23U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 54U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = (aWandererB + RotL64(aCross, 58U)) + 14179205183062705133U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 3U)) + 210032324058740920U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 27U)) + 7387115089142500152U;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 39U)) + 17583362781238061430U) + aNonceWordJ;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 5U)) + 4991442849150005943U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aScatter, 51U)) + 2891376254689854555U;
            aOrbiterF = (aWandererD + RotL64(aCross, 11U)) + 10523274382407446239U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 39U)) + 3861893764676218667U;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 27U)) + 3366674459852093746U) + aPhaseEOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 29U)) + 5898492634386601145U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 46U)) + RotL64(aCarry, 21U)) + 7047353571244768721U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 14374108805453186316U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8763667021501226510U;
            aOrbiterH = RotL64((aOrbiterH * 7694695426430267863U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 18261523829316379575U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 650477532238860965U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8291758490821819851U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2162326554604894042U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5776546692501825278U;
            aOrbiterG = RotL64((aOrbiterG * 14911545784585246537U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3501863793638415049U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 14853789267425352958U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10590325397179928739U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15399673014671329743U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 12253428583438990426U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12052855472196447849U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13202953937621953839U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7547616636832698398U;
            aOrbiterD = RotL64((aOrbiterD * 9533399972562428073U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15709801946594868318U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12458677982746610971U;
            aOrbiterA = RotL64((aOrbiterA * 6662570874316418993U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 6957370791367530127U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 10511379961344950861U;
            aOrbiterE = RotL64((aOrbiterE * 15551333099264031337U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16489828646914719181U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6827290294344770680U;
            aOrbiterI = RotL64((aOrbiterI * 6408864925398536651U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3308531598034561099U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10336568208337990458U;
            aOrbiterJ = RotL64((aOrbiterJ * 5606941634846696657U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14116471880098183908U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14179205183062705133U;
            aOrbiterC = RotL64((aOrbiterC * 8824119255416045191U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 5U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (RotL64(aOrbiterI, 50U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterK, 37U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterH, 24U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 19U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterE, 29U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 60U) + aOrbiterC) + RotL64(aOrbiterJ, 27U)) + aNonceWordO) + aPhaseEWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterB, 5U)) + aNonceWordG);
            aWandererC = aWandererC + ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterD, 14U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterG, 21U));
            aWandererG = aWandererG + (((RotL64(aScatter, 26U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 40U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordA);
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

void TwistExpander_Karate_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDE3B1B1493902055ULL + 0xF3AD3AC8753F4F62ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA84D9D2DA0255C19ULL + 0xC87B7C511ACFE9ECULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCA250FC967CDB1BFULL + 0xE5FEC23C24B3E244ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x89A636551A4191B3ULL + 0xCF2ECA464DED2C4CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8200B4855789FE77ULL + 0x9D3C3ECB87533FADULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA817175D35DBCD11ULL + 0xE6A87807DBF9027AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x98458404C0603CC7ULL + 0xF8E8AE4855954973ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x82F905E8822987B7ULL + 0xF1B039F6D9F0A26FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE97BA410DB472DCDULL + 0xF684D5ECDA0402CBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xCF0EE7D2A795FAA9ULL + 0xE1659A9E494E3BEFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC6C1009FBF4B2031ULL + 0x9A17442AB80425A1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBDAF5BB83E7AA9BBULL + 0xC246EAA50D5BAD6AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE8C6A240092AC49BULL + 0xFA4EB403BB2753E6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xBDACB64C97923FABULL + 0xE7D47DF72AF95CD6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xAA71A0F03901608FULL + 0xA805C64AFACCBE8FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFFDFEBE1CE619ACDULL + 0xADCF3FFA3F323D65ULL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4636U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3516U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1309U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3232U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 53U)) ^ (RotL64(aCarry, 21U) + RotL64(aIngress, 34U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererG + RotL64(aScatter, 46U)) + 17225673071833726819U) + aNonceWordK;
            aOrbiterK = (aWandererB + RotL64(aIngress, 13U)) + 10301458382103627331U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 19U)) + 3960233050857362414U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 17768665685046605837U) + aNonceWordM;
            aOrbiterI = ((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 14471018461213959767U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 43U)) + 10730597892721340453U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 27U)) + 14863394003122760542U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 54U)) + 9948587274816688296U) + aPhaseFOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aCross, 21U)) + 3573569431435100993U) + aNonceWordP;
            aOrbiterA = (aWandererF + RotL64(aIngress, 51U)) + 8153670675740450590U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 41U)) + 16438856577722561424U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15765587867581925041U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1082039522061775213U;
            aOrbiterG = RotL64((aOrbiterG * 17023740047246402641U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4202521649260798876U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15877659681260461141U;
            aOrbiterB = RotL64((aOrbiterB * 11369910758551088173U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2551560426129646123U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 3005102326163906320U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4241583192662435107U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 1675501058857208089U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 12774812270956702043U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5488437008504905105U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1044886020922563597U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 4857445127457225171U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 13223560654459705259U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 11548725551787560962U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 2434677823189765161U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 4283026044563670969U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9606875320524736294U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13732615866277657704U;
            aOrbiterC = RotL64((aOrbiterC * 3905528919281629775U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13921743663803299567U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13350829301153929899U;
            aOrbiterK = RotL64((aOrbiterK * 11858642286713079795U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9473349030551400156U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7446792050826434742U;
            aOrbiterI = RotL64((aOrbiterI * 6619682184124713031U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17970527747978977453U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 2326714817603921480U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14581676978186226887U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7875511075130474136U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 17225673071833726819U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1196024136909896027U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 30U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterH, 43U));
            aWandererH = aWandererH + ((RotL64(aScatter, 44U) + RotL64(aOrbiterA, 57U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterE, 41U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 11U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 35U)) + aOrbiterE) + aNonceWordD);
            aWandererG = aWandererG + ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterI, 20U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 27U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 29U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 52U) + aOrbiterK) + RotL64(aOrbiterD, 39U));
            aWandererF = aWandererF + (((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 50U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10449U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5720U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9345U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneB[((aIndex + 6812U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCross, 5U) + RotL64(aIngress, 18U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererJ + RotL64(aCross, 51U)) + 9654059367478508868U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 19U)) + 6473006635864677427U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 5U)) + 6944184481315853243U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 23U)) + 4061496421939102306U) + aPhaseFOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 3U)) + 15791809275719085463U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 48U)) + 14050798802646323055U) + aNonceWordL;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 12072905924741758266U) + aNonceWordA;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 17639076509231343896U;
            aOrbiterA = (aWandererH + RotL64(aCross, 3U)) + 12195388285571234715U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 57U)) + 4325404419499496529U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = (aWandererE + RotL64(aIngress, 38U)) + 5910567888204238382U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 13092940059929942699U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13381962590820308761U;
            aOrbiterC = RotL64((aOrbiterC * 6345904465930943295U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15622862439323440527U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14027151901132249793U;
            aOrbiterB = RotL64((aOrbiterB * 2273573821630510087U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 4584410023907605157U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15763755180625487157U;
            aOrbiterJ = RotL64((aOrbiterJ * 6755736130607297639U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17023059745666559199U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5298529579288492971U;
            aOrbiterH = RotL64((aOrbiterH * 2483562793328357721U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2870152867331654736U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 12017191100173748848U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 9958191466506480519U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 15899529176182436062U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16482713846343388735U;
            aOrbiterI = RotL64((aOrbiterI * 719465695044265601U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12943393531812774449U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 9881108254540483225U;
            aOrbiterF = RotL64((aOrbiterF * 8011108108007885059U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3532054586199716750U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7142230313294797435U;
            aOrbiterD = RotL64((aOrbiterD * 14154176174768868421U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 733958394016131587U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2060800099014517137U;
            aOrbiterG = RotL64((aOrbiterG * 12988885554457108631U), 39U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 2278498033811574812U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15342071118593803929U;
            aOrbiterE = RotL64((aOrbiterE * 7842196613533603835U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12987212219357101955U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9654059367478508868U;
            aOrbiterK = RotL64((aOrbiterK * 11796100167917742307U), 37U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 43U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 46U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterC, 4U));
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 47U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 13U)) + aOrbiterH) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 56U) + aOrbiterJ) + RotL64(aOrbiterG, 53U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterJ, 37U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 35U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 27U)) + aOrbiterF) + aPhaseFWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 57U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 6U) + aOrbiterK) + RotL64(aOrbiterE, 6U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 41U)) + aOrbiterC) + aNonceWordE) + aPhaseFWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 30U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14915U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13448U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11134U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15758U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 36U) + RotL64(aCarry, 11U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 41U)) + 10038936806177516123U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 34U)) + 1773168435195292638U;
            aOrbiterB = ((((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 35U)) + 10655711161526628072U) + aPhaseFOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 14422295664639740437U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aPrevious, 53U)) + 4125228715513159576U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 11U)) + 3670449653158650845U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 21U)) + 17553727567180813057U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 5U)) + 5111401772713882743U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 23U)) + 7688573124662314413U) + aNonceWordE;
            aOrbiterG = (aWandererD + RotL64(aScatter, 56U)) + 9438375825507814395U;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 14177477039902118886U) + aNonceWordB;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16329942595859623928U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3990536794006836672U;
            aOrbiterB = RotL64((aOrbiterB * 579024714339065373U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5072881436583180756U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16789727877867289997U;
            aOrbiterF = RotL64((aOrbiterF * 8766246302636197905U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17313956922306689438U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11530878396329822041U;
            aOrbiterI = RotL64((aOrbiterI * 11356860047841383129U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3612616532321160196U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 4172189825359187763U;
            aOrbiterH = RotL64((aOrbiterH * 12938945495299393177U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8677279703778052804U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1912172980909479362U;
            aOrbiterD = RotL64((aOrbiterD * 10053289257955474143U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 1460085850227494500U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12116763868122868147U;
            aOrbiterG = RotL64((aOrbiterG * 6076945628020280957U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 17571840610366424432U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 15581362592611080868U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1129054058044872003U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14434700039977611666U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 4534294602623329152U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5860911553425182045U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 865998255725903702U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16407778704555344108U;
            aOrbiterC = RotL64((aOrbiterC * 15571344643129797977U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 1948990288894429805U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 18218556219056835250U;
            aOrbiterE = RotL64((aOrbiterE * 16574160087642377293U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1309229265173143398U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10038936806177516123U;
            aOrbiterA = RotL64((aOrbiterA * 12954594462760207923U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 26U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterK, 14U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 57U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aPrevious, 56U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterH, 23U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterK, 11U));
            aWandererG = aWandererG + (((RotL64(aIngress, 50U) + aOrbiterC) + RotL64(aOrbiterK, 26U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 21U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterI, 39U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterD, 41U)) + aNonceWordH);
            aWandererH = aWandererH + ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterG, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 6U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18552U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 18515U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17054U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17037U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 20U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = ((aWandererA + RotL64(aScatter, 27U)) + 15813325389431304548U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 57U)) + 2223874171125403602U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 35U)) + 5510483568496824130U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aIngress, 24U)) + 15474152493495661876U) + aNonceWordB;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 11U)) + 16846339705130829195U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 29U)) + 1289670576865739669U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 5U)) + 18017354919647006944U) + aNonceWordF;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 14U)) + RotL64(aCarry, 57U)) + 8539685539928984921U) + aNonceWordH;
            aOrbiterA = (aWandererJ + RotL64(aCross, 47U)) + 3333721400836704048U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 19U)) + 2261560416623815491U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 53U)) + 4377786131746816567U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 18047393176583722719U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 8184724021940434631U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 9800116157750921119U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10469895939183324807U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14543391765109879223U;
            aOrbiterG = RotL64((aOrbiterG * 4817987697437667225U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5757225781746158178U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3539000495894022869U;
            aOrbiterE = RotL64((aOrbiterE * 1032298408884695925U), 35U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 11288971092707065923U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2761384065186568294U;
            aOrbiterF = RotL64((aOrbiterF * 3323838837427471051U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 7120580145300417101U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6977246291769372866U;
            aOrbiterH = RotL64((aOrbiterH * 15170353875184253779U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 17625434527765525937U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3299714663631376190U;
            aOrbiterA = RotL64((aOrbiterA * 6532628892760776767U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10331889953489885250U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 8550932256881727932U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13085531621192583719U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11151195711186126257U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2552002192824926483U;
            aOrbiterD = RotL64((aOrbiterD * 9754056316698523849U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 8038115194286715268U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16594489591573505305U;
            aOrbiterC = RotL64((aOrbiterC * 1241387574663818247U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 13476964484361081681U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2136330439951908303U;
            aOrbiterJ = RotL64((aOrbiterJ * 12728359054660550527U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 231990686776499700U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15813325389431304548U;
            aOrbiterI = RotL64((aOrbiterI * 9155088985405261637U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 30U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterB, 3U)) + aOrbiterI) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 53U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterA, 37U));
            aWandererI = aWandererI + ((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterG, 47U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 24U) + RotL64(aOrbiterD, 41U)) + aOrbiterK) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 58U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterF, 29U)) + aNonceWordK);
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 43U)) + aOrbiterF) + aNonceWordL);
            aWandererA = aWandererA ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterD, 35U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 22U)) + aOrbiterI) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererG, 46U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26458U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 22016U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22638U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24970U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 51U)) ^ (RotL64(aIngress, 20U) + RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aIngress, 51U)) + 4622023259121087483U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 27U)) + 10253505250223501352U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 17133877904420462669U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 54U)) + 6162827793741796700U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 43U)) + 9610986424765907615U) + aPhaseFOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aCross, 29U)) + 11210747154264753754U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 3U)) + 16554205219580654546U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 14U)) + 10352576357413766388U) + aPhaseFOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aPrevious, 41U)) + 3651845783283479752U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 18145542190463500476U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 23U)) + 5415609566767162857U) + aNonceWordE;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2033734872464201570U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3507213117125813345U;
            aOrbiterE = RotL64((aOrbiterE * 5453058336688881113U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8716253393049851856U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 695984869565941856U;
            aOrbiterG = RotL64((aOrbiterG * 8377921610764044735U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7661578828878284931U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 906654265099155956U;
            aOrbiterA = RotL64((aOrbiterA * 8117625377607536949U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6050049984731254612U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17882717590338190821U;
            aOrbiterJ = RotL64((aOrbiterJ * 10807367411402733215U), 41U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 4996521991532815957U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4246460672800604436U;
            aOrbiterI = RotL64((aOrbiterI * 12047466401960824903U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8700148116452518842U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10039050281847466206U;
            aOrbiterK = RotL64((aOrbiterK * 11884791271239660157U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4513844680425845372U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3037563127442815153U;
            aOrbiterF = RotL64((aOrbiterF * 18363509277992292407U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 1005237931570968724U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1373258132025712065U;
            aOrbiterB = RotL64((aOrbiterB * 10458020799382532395U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12759144329395682277U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 5139371668116336931U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10761543179345026943U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3211005174890625715U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 18045286961878287418U;
            aOrbiterC = RotL64((aOrbiterC * 4536094526540761611U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 4454078771279674978U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 4622023259121087483U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 8991756794989027019U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 21U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (RotL64(aOrbiterC, 50U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterK, 23U));
            aWandererA = aWandererA + (((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 20U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterH, 47U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterK, 11U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterF, 53U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 60U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterI, 13U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 41U)) + aOrbiterB) + aNonceWordC) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aPrevious, 58U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC);
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterH, 57U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 26U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30419U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29879U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28028U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27956U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aIngress, 26U)) ^ (RotL64(aCross, 53U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererH + RotL64(aIngress, 11U)) + 5160910997561396461U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 39U)) + 14920764751058512062U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 43U)) + 6080952401749660022U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 23U)) + 17667234330526298627U) + aPhaseFOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aScatter, 13U)) + 760630072638686756U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 6U)) + 3504157162816997476U) + aNonceWordA;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 51U)) + 9489022223422585882U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 23U)) + 1149898536879968964U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 10492284328940025310U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 54U)) + 13213275606286399312U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 41U)) + 10557118912847180413U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15618980209023994776U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5268600749854045564U;
            aOrbiterB = RotL64((aOrbiterB * 3849660559223919613U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8011552687609649990U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 3148133096349525066U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5245156554959620007U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12032847944237867285U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14999005703490824673U;
            aOrbiterA = RotL64((aOrbiterA * 6631584955208646049U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5426735969392906710U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 3593177531650386729U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12997284886192717043U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1701444719333347373U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 15928731228196894960U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1919318226904213433U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5960179456039157036U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5716434224061596483U;
            aOrbiterJ = RotL64((aOrbiterJ * 3731976564761202801U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 2136841536293340279U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12969550408652728526U;
            aOrbiterE = RotL64((aOrbiterE * 7612191387451455137U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3641997570461447114U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4677572491523684525U;
            aOrbiterH = RotL64((aOrbiterH * 2730358077882211651U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2741372094325164504U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 4998631511811832690U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 10619395395977372695U), 19U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 6260464862798783617U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16489087874167346533U;
            aOrbiterF = RotL64((aOrbiterF * 11278053967185244867U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7043760915859224327U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5160910997561396461U;
            aOrbiterG = RotL64((aOrbiterG * 15260149870590431675U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 51U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 10U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterK, 3U)) + aOrbiterE) + aNonceWordJ);
            aWandererK = aWandererK + ((((RotL64(aIngress, 20U) + aOrbiterK) + RotL64(aOrbiterH, 58U)) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 35U)) + aOrbiterB) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 37U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterG, 39U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 26U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterE, 29U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aScatter, 44U) + aOrbiterD) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterJ, 11U));
            aWandererB = aWandererB + ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 51U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterH, 5U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 14U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ aNonceWordN;
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

void TwistExpander_Karate_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x979C530744D2EB13ULL + 0xC762DAA99B8F0ABBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA8F6D1ECE8DB9EC5ULL + 0xD1E9B5063538BA7CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC37CC8B384A2B1D7ULL + 0xA8BBEEC10E2FEA86ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA6D6654FC9A0EFC3ULL + 0xD93831DF33C78BB6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB499196724B96E1FULL + 0xEC496AB88EA1DDE1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xAB99A19001EF0F1BULL + 0xA01FCD3EB7BA6157ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD5651B24C18ECF0DULL + 0xDD0952B143BF5875ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8E06A73AF21577DDULL + 0x88B5BF6B74B11087ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8188F96D6B027493ULL + 0xF71ADD7859F2EB08ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE10C8886B365EDD7ULL + 0xF07B1ACA4E1AC161ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x924DB91142CD5239ULL + 0xB80EAD9171AAE9A2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD5427DC85D806207ULL + 0x8E97873D5DE5848BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD52D24F8EB619B8DULL + 0xF981A56F84B97224ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xFDA44898A97C61F3ULL + 0xD84CB32437FB2A53ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xEA6F002A8863A0E5ULL + 0xFDAD6A21FCF1D106ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xAB1663959EC1F059ULL + 0xD99736C29C91B7D9ULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1446U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((aIndex + 4648U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1478U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 2960U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 41U)) + (RotL64(aPrevious, 4U) ^ RotL64(aCarry, 29U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 15813325389431304548U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 39U)) + 2223874171125403602U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 53U)) + 5510483568496824130U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aIngress, 48U)) + 15474152493495661876U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 13U)) + 16846339705130829195U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 1289670576865739669U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 41U)) + 18017354919647006944U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 29U)) + 8539685539928984921U) + aNonceWordE;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 39U)) + 3333721400836704048U) + aNonceWordM;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 50U)) + 2261560416623815491U) + aPhaseFOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aScatter, 35U)) + 4377786131746816567U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 18047393176583722719U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8184724021940434631U;
            aOrbiterD = RotL64((aOrbiterD * 9800116157750921119U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 10469895939183324807U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14543391765109879223U;
            aOrbiterA = RotL64((aOrbiterA * 4817987697437667225U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5757225781746158178U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3539000495894022869U;
            aOrbiterE = RotL64((aOrbiterE * 1032298408884695925U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11288971092707065923U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 2761384065186568294U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 3323838837427471051U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7120580145300417101U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6977246291769372866U;
            aOrbiterG = RotL64((aOrbiterG * 15170353875184253779U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 17625434527765525937U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3299714663631376190U;
            aOrbiterB = RotL64((aOrbiterB * 6532628892760776767U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10331889953489885250U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8550932256881727932U;
            aOrbiterJ = RotL64((aOrbiterJ * 13085531621192583719U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11151195711186126257U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 2552002192824926483U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 9754056316698523849U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8038115194286715268U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16594489591573505305U;
            aOrbiterF = RotL64((aOrbiterF * 1241387574663818247U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13476964484361081681U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2136330439951908303U;
            aOrbiterH = RotL64((aOrbiterH * 12728359054660550527U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 231990686776499700U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15813325389431304548U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9155088985405261637U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 37U);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 34U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 5U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterI, 37U)) + aNonceWordK);
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 30U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterA, 51U)) + aOrbiterD) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterA, 19U));
            aWandererB = aWandererB + ((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterK, 43U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterI, 14U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 14U) + aOrbiterJ) + RotL64(aOrbiterI, 47U));
            aWandererE = aWandererE + ((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterI, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 24U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererH, 42U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6201U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8282U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5663U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10003U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 60U) ^ RotL64(aPrevious, 43U)) + (RotL64(aIngress, 11U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = ((aWandererG + RotL64(aCross, 26U)) + 12632404972795375757U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aPrevious, 41U)) + 5351879979055988456U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 37U)) + 3597737727467443413U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 19U)) + 2830846754917852318U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 56U)) + 17311925960294518018U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 3U)) + 2083584640523695383U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 11U)) + 15049343611387010158U) + aNonceWordM;
            aOrbiterK = ((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 37U)) + 6443050378205811147U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 6021965178697344070U) + aPhaseFOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aIngress, 29U)) + 5080289878758029976U;
            aOrbiterI = (aWandererB + RotL64(aCross, 21U)) + 576927745306972983U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 4728489691382690859U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 6184355840165758855U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 1515043910404156423U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11220539885798595450U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11091438724966718214U;
            aOrbiterE = RotL64((aOrbiterE * 8225347114759391961U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17184210490020062419U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2150997767099116408U;
            aOrbiterG = RotL64((aOrbiterG * 8058553821648892499U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 7021953562676903717U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17159676348343312834U;
            aOrbiterJ = RotL64((aOrbiterJ * 13877284519668483549U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 10367891770525239784U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11922478487264201233U;
            aOrbiterF = RotL64((aOrbiterF * 9195137452661956029U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 17815162358981720634U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9582631251085100284U;
            aOrbiterC = RotL64((aOrbiterC * 11838992994130850483U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 872593750259572264U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 17832330100262167302U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 1114416841510028467U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16601139856969287418U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14931287111691324985U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16757174577841001179U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11413072442039115924U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15253605470589905889U;
            aOrbiterK = RotL64((aOrbiterK * 10832817442285245673U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3653487723581514107U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14891378240114471865U;
            aOrbiterB = RotL64((aOrbiterB * 1386594204573386051U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15659724464711852035U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12632404972795375757U;
            aOrbiterI = RotL64((aOrbiterI * 2407347385127296647U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 21U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterD, 56U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 46U) + aOrbiterD) + RotL64(aOrbiterK, 5U)) + aNonceWordP);
            aWandererD = aWandererD + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 53U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 51U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterH, 48U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 41U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterC, 37U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 39U)) + aOrbiterD);
            aWandererA = aWandererA + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 27U)) + aOrbiterH) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterA, 43U));
            aWandererB = aWandererB + ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterF, 58U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterI, 23U)) + aNonceWordF) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 28U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererE, 44U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 13189U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11871U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14072U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((aIndex + 13469U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 6U)) + (RotL64(aPrevious, 19U) + RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 18U)) + 11410829607777684449U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 21U)) + 7502698839700975347U;
            aOrbiterC = (aWandererI + RotL64(aCross, 57U)) + 13267685058252106173U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 29U)) + 238242706996630625U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 8184695499511454281U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 43U)) + 12767823220461985403U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 53U)) + 12293198423143850330U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 11149495229952495939U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 23U)) + 7556992689338382800U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 46U)) + 3431338808774134649U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 16863099140844995099U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17872458049880677604U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16760153457252546974U;
            aOrbiterC = RotL64((aOrbiterC * 11225037229069712805U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3115544493537438408U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 4359882942759752958U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 561477566995575801U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13387113067202396536U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12955690074544490161U;
            aOrbiterI = RotL64((aOrbiterI * 12449941770827974511U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15614054443728226807U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1939441328066616114U;
            aOrbiterA = RotL64((aOrbiterA * 4484917074808974359U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4599016263007782537U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9962305629016158048U;
            aOrbiterE = RotL64((aOrbiterE * 1496184427500037279U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8428467674122750557U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3938884087806393439U;
            aOrbiterF = RotL64((aOrbiterF * 12810531094050481761U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6018636830758044658U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 1510372000641305416U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9002834928626918247U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17592782466215337843U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 8119921507606870360U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 1299795061644535485U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8753237702359236964U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12389957327067768090U;
            aOrbiterD = RotL64((aOrbiterD * 4586786761936601607U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 17791633199762408683U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 11606494383812053915U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13041480602055778521U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4418614662439151979U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11410829607777684449U;
            aOrbiterG = RotL64((aOrbiterG * 3342270212301058781U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 20U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 22U) + RotL64(aOrbiterD, 26U)) + aOrbiterH);
            aWandererH = aWandererH + ((((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 5U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterC, 53U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterG, 23U));
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterK, 10U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 43U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 39U)) + aOrbiterA) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 37U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 56U) + aOrbiterF) + RotL64(aOrbiterK, 35U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20715U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20472U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16431U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19934U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aIngress, 28U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererK + RotL64(aIngress, 20U)) + 12046647397183218524U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 47U)) + 2760779375026461991U) + aNonceWordE;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 39U)) + 13735454443176855650U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aPrevious, 3U)) + 4370377000586647724U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 37U)) + 14566322384189969094U) + aPhaseFOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 18U)) + 5056565959818422786U) + aNonceWordG;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 41U)) + 8795403810686579209U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 57U)) + 9625947666256011567U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 1703669290934254701U;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 11U)) + 6664070663184147951U) + aNonceWordI;
            aOrbiterG = (aWandererG + RotL64(aScatter, 23U)) + 2104148316797553431U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 1197910004222596145U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 9922977170060903197U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13047828062605568603U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 2048376210852567829U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12568990647075931409U;
            aOrbiterJ = RotL64((aOrbiterJ * 9860242601194210927U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 15026894775772902751U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3439447160137900629U;
            aOrbiterI = RotL64((aOrbiterI * 1813754963043785165U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6532671388552829796U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17261098369835997661U;
            aOrbiterE = RotL64((aOrbiterE * 568292591215203521U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3171300991007459947U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5935563269327662024U;
            aOrbiterK = RotL64((aOrbiterK * 11271790283157765003U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14290941734320455612U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12371794745736518824U;
            aOrbiterC = RotL64((aOrbiterC * 12208762336145168647U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 8782840145467637373U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4067525421190366741U;
            aOrbiterB = RotL64((aOrbiterB * 6671002797916227485U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11854812920571789853U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17564890418553131451U;
            aOrbiterG = RotL64((aOrbiterG * 16657184504366731805U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6250004085193517531U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2362659992682660827U;
            aOrbiterF = RotL64((aOrbiterF * 4365619310373869859U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4597159873252831182U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 13197238269207675773U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 379653377172816575U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8552479493772820372U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12046647397183218524U;
            aOrbiterD = RotL64((aOrbiterD * 17918033655125400323U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 24U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterB, 37U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 46U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 34U) + aOrbiterI) + RotL64(aOrbiterE, 35U)) + aPhaseFWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 19U)) + aOrbiterE) + aPhaseFWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterA, 48U)) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 21U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aCross, 60U) + aOrbiterJ) + RotL64(aOrbiterI, 53U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterC, 13U));
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterG, 57U)) + aNonceWordO);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterI, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordH);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26992U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 26028U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22859U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22141U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 38U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 2330952702412094686U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 7820188225935060799U) + aNonceWordC;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 41U)) + 9347644591709839145U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 34U)) + 2288624878446846870U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 51U)) + 9358977729492824128U;
            aOrbiterG = (((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 27U)) + 1858511275052455039U) + aNonceWordI;
            aOrbiterD = (aWandererG + RotL64(aCross, 23U)) + 13715478509322292552U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 5U)) + 16413396625604260455U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 43U)) + 17714322215518432705U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 57U)) + 16188315436202861122U) + aNonceWordJ;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 26U)) + 5564445841368207813U) + aPhaseFOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13717068949900594673U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 14143659432287313765U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17281441046722262917U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 5729546141908425670U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4297827922736712074U;
            aOrbiterG = RotL64((aOrbiterG * 13631630436759768885U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 829520109395163673U) + aNonceWordE;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 11547160328525174295U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4759690159673049775U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2907177944512117206U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11100346409065275671U;
            aOrbiterA = RotL64((aOrbiterA * 17927994356809011637U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1344592529249949068U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6470438516791143572U;
            aOrbiterE = RotL64((aOrbiterE * 13339390828725370475U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5217751823741520847U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5371275223586938039U;
            aOrbiterF = RotL64((aOrbiterF * 12318403075523724125U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 14218103150268532919U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1367628876596800571U;
            aOrbiterD = RotL64((aOrbiterD * 13777531272321533137U), 53U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 2372041991018455610U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9870744274890595581U;
            aOrbiterI = RotL64((aOrbiterI * 12093443117747395585U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15531376915156611594U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11166549148968363252U;
            aOrbiterH = RotL64((aOrbiterH * 10024372567841218915U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 8555942275137258839U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3304132937209624841U;
            aOrbiterJ = RotL64((aOrbiterJ * 7965093976633155809U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14825330575158830172U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2330952702412094686U;
            aOrbiterC = RotL64((aOrbiterC * 9146641978165131495U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 44U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterH, 43U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 14U) + aOrbiterK) + RotL64(aOrbiterG, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 21U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 60U)) + aOrbiterI) + aNonceWordP) + aPhaseFWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 57U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 51U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterK, 19U));
            aWandererE = aWandererE + (((RotL64(aScatter, 26U) + aOrbiterE) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterB, 38U));
            aWandererH = aWandererH + ((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 47U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 3U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32051U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 30568U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30277U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 31980U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 48U) ^ RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (((aWandererG + RotL64(aCross, 48U)) + RotL64(aCarry, 27U)) + 7722279280863371124U) + aNonceWordI;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 53U)) + 11584220561732385598U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 37U)) + 7834679350105534657U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 11347994382444180879U) + aNonceWordL;
            aOrbiterH = (aWandererK + RotL64(aIngress, 39U)) + 9449903188047063431U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 5U)) + 6516243976652795170U;
            aOrbiterB = (aWandererB + RotL64(aCross, 21U)) + 8420815253991184777U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 29U)) + 9081386852515170937U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 10U)) + 14375955191735286867U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 27U)) + 880757589768436072U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aScatter, 35U)) + 3349856625725164229U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7826309957607577207U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8057435761214313635U;
            aOrbiterF = RotL64((aOrbiterF * 4718430712767038607U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9565237500443303103U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15893066735310588501U;
            aOrbiterH = RotL64((aOrbiterH * 8457633439171452397U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3276844534476430842U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6828644383891274120U;
            aOrbiterK = RotL64((aOrbiterK * 979580351653410157U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2815676923011504251U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 5030251870850928417U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 7075653570570819253U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13464083008377887034U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8994560761846897590U;
            aOrbiterE = RotL64((aOrbiterE * 9892839554658865143U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8398813387154468736U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8136429428340910892U;
            aOrbiterD = RotL64((aOrbiterD * 3348811490733577295U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 418587250696862341U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4111667833838312094U;
            aOrbiterG = RotL64((aOrbiterG * 860949442143849147U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6075478294190926371U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 2208124955874142264U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15741988616251072075U), 13U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 4726538724576443010U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6524078248882840425U;
            aOrbiterJ = RotL64((aOrbiterJ * 9784875566721689069U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14521003220464811621U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 16916247868211621303U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 1911638054294853877U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 18207293125461843123U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7722279280863371124U;
            aOrbiterA = RotL64((aOrbiterA * 14303108475807941791U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 54U));
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterH, 21U)) + aNonceWordN);
            aWandererD = aWandererD + ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 19U)) + aOrbiterB);
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterF, 23U)) + aOrbiterB) + aNonceWordH);
            aWandererB = aWandererB + ((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterH, 46U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterB, 41U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterJ, 57U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + aPhaseFWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterG, 26U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 11U)) + aOrbiterA) + aPhaseFWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 39U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterH, 37U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 10U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordP;
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

void TwistExpander_Karate_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3620U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[((aIndex + 3366U)) & W_KEY1], 22U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 577U)) & W_KEY1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1026U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererG + RotL64(aScatter, 19U)) + 9446153639709651566U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 12U)) + 10550762260670758167U;
            aOrbiterG = (((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 41U)) + 7062634922142578383U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 43U)) + 9178499097812764515U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aCross, 23U)) + 6887103379773525538U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 47U)) + 6239750312052010257U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 6U)) + 17645022614523287959U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 29U)) + 3639618183259408272U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 3131737117548745095U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7253994382396406554U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 15217993711938379561U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17853313384747259923U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12594152227603630033U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11250170200489647869U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 546800378327864723U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 12936942656624279424U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10990736056052106149U;
            aOrbiterE = RotL64((aOrbiterE * 7123916809953459187U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12787293075893090465U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17154990205620778151U;
            aOrbiterF = RotL64((aOrbiterF * 10031369940028159521U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1270827262969060301U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17337623431665013136U;
            aOrbiterI = RotL64((aOrbiterI * 1517262088236356107U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 830330490987911853U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6828309232554560547U;
            aOrbiterC = RotL64((aOrbiterC * 9742464176986145819U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 11470087853413986203U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10470148870747884420U;
            aOrbiterH = RotL64((aOrbiterH * 6766079738799967443U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 18315536891901859637U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12264670822285914271U;
            aOrbiterA = RotL64((aOrbiterA * 5841574505408674119U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10931842095884524879U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 11134871340959676257U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11714837622285605745U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 34U) + RotL64(aOrbiterG, 30U)) + aOrbiterK) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 5U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterB, 47U));
            aWandererH = aWandererH + ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 19U)) + aOrbiterF);
            aWandererG = aWandererG ^ (((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterH, 13U)) + aPhaseCWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 6U) + aOrbiterG) + RotL64(aOrbiterI, 38U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 57U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 11075U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 12464U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 12149U)) & W_KEY1], 23U) ^ RotL64(aKeyRowReadB[((aIndex + 11286U)) & W_KEY1], 14U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 44U)) + (RotL64(aCross, 21U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererF + RotL64(aScatter, 10U)) + 14214886793361825363U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 29U)) + 17267959031078766320U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 43U)) + 16436067429484887644U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 57U)) + 9885951769332633820U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 4U)) + RotL64(aCarry, 47U)) + 12971711341813893304U;
            aOrbiterC = (aWandererE + RotL64(aCross, 23U)) + 199970353398450154U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 1237341696444162094U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 19U)) + 7991128854417613360U) + aPhaseCOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aCross, 29U)) + 14809029847149045833U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2559509556915775947U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 14336829730147834160U;
            aOrbiterH = RotL64((aOrbiterH * 15103242520064900873U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8853631886733610440U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13346159398673246914U;
            aOrbiterJ = RotL64((aOrbiterJ * 13660497151446983393U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 12121095718571872976U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 16239781125815589804U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5157009090454962231U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9051377033794324106U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13805815136723461780U;
            aOrbiterK = RotL64((aOrbiterK * 571129481747181357U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14849157800322754413U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 18116651528452542634U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3638480428016835537U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4105057226952948599U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5911714320560994391U;
            aOrbiterD = RotL64((aOrbiterD * 1796514171654961389U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4439149331729987587U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10278532228230163632U;
            aOrbiterI = RotL64((aOrbiterI * 17428224919864716517U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2342456582668741750U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2360578572554664800U;
            aOrbiterC = RotL64((aOrbiterC * 1108428466956691925U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12132934875391401246U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 17213278726790245812U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11904899990681410419U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + RotL64(aOrbiterD, 52U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 57U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 42U) + aOrbiterF) + RotL64(aOrbiterH, 48U));
            aWandererC = aWandererC + ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 13U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 43U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterC, 5U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 39U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterC, 28U)) + RotL64(aCarry, 3U)) + aPhaseCWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 53U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 14U) + aOrbiterD) + RotL64(aOrbiterC, 21U)) + aPhaseCWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 14U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 20800U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneA[((aIndex + 20436U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 24476U)) & W_KEY1], 42U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 17312U)) & W_KEY1], 27U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 5U)) + (RotL64(aIngress, 37U) ^ RotL64(aCross, 50U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 41U)) + 14249093584376402677U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aCross, 13U)) + 8756965951816492264U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 24U)) + RotL64(aCarry, 23U)) + 11221139480258176330U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 43U)) + 17218894445564194851U;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 8064642692524949490U) + aPhaseCOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aCross, 57U)) + 5822093203710704646U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 47U)) + 3217799620158102238U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 53U)) + 2613757677892120843U;
            aOrbiterG = (aWandererG + RotL64(aCross, 20U)) + 13647481499551657237U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 3545714196663685016U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9735422670576621521U;
            aOrbiterH = RotL64((aOrbiterH * 7276207208162697249U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3911046580637583767U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9315984027042049203U;
            aOrbiterJ = RotL64((aOrbiterJ * 12568550776487242469U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 8926367674641729058U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11035347490524961446U;
            aOrbiterC = RotL64((aOrbiterC * 10948288997163592463U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 10748158733051120339U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2467801787989056455U;
            aOrbiterE = RotL64((aOrbiterE * 12621934274702358977U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9244415080474351390U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8517784887959492079U;
            aOrbiterK = RotL64((aOrbiterK * 17022899813765884147U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8409307332803038455U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11043806021873232950U;
            aOrbiterB = RotL64((aOrbiterB * 8294888329708842989U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17512395828450251457U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16849067939795823992U;
            aOrbiterI = RotL64((aOrbiterI * 9361991804481514337U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17541946638063238056U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 11430501673960586718U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15074409630605450091U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 78307505705383302U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4834528975263832983U;
            aOrbiterG = RotL64((aOrbiterG * 17245673681686752861U), 41U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 30U) + RotL64(aOrbiterH, 34U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterI, 27U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 19U)) + aOrbiterC);
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 5U)) + aOrbiterH) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterH, 47U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 57U)) + aOrbiterG) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 6U) + aOrbiterJ) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterI, 23U));
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 52U)) + aOrbiterK) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31382U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24836U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28400U)) & S_BLOCK1], 38U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 32179U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCross, 13U)) ^ (RotL64(aCarry, 60U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererA + RotL64(aCross, 29U)) + 15904465836916519864U) + aPhaseCOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aScatter, 53U)) + 17725629806317789307U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 10U)) + RotL64(aCarry, 11U)) + 13794170125914914828U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 35U)) + 2149055907476874332U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 57U)) + 5342047776745074649U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 8268148484060546838U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 24U)) + RotL64(aCarry, 19U)) + 10821151364028563719U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 19U)) + 4294213820894407378U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aCross, 3U)) + 10884726101307943090U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16432210042202444824U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15196602644336228055U;
            aOrbiterJ = RotL64((aOrbiterJ * 12680438355124070237U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14117787670220328165U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 219833877949480215U;
            aOrbiterA = RotL64((aOrbiterA * 10736293047771972173U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 3326396981881473962U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 14918513066311426279U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14269763278564574663U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11795234681370163206U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3068267285352664813U;
            aOrbiterH = RotL64((aOrbiterH * 15746255933920904619U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 245233356957999496U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 709926406353796673U;
            aOrbiterF = RotL64((aOrbiterF * 13627039596842073595U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5378105439430271038U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10114555061122044430U;
            aOrbiterB = RotL64((aOrbiterB * 5351295043424885549U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13233010815716769713U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 8231291294833548389U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10840516135212753869U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7160760224172419829U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14767926435411546785U;
            aOrbiterD = RotL64((aOrbiterD * 1643485739468851073U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4464245330038080103U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15778166658285494712U;
            aOrbiterE = RotL64((aOrbiterE * 13980891936095282989U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 14U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 5U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 43U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aPhaseCWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterF, 54U)) + aOrbiterE) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 58U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 39U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterI, 35U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 13U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aCross, 36U) + RotL64(aOrbiterC, 60U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 29U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 22U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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

void TwistExpander_Karate_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2301U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7083U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4064U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 6231U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 27U)) ^ (RotL64(aCross, 60U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 6318740973868639425U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 5487840061430920881U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 27U)) + 10258706763248072672U;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 18356875269730338208U) + aPhaseDOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aScatter, 14U)) + 12883160282903147010U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1010140474942697730U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 17733939421700898293U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9233534157871885251U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 13693055887924981201U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14574732452793385269U;
            aOrbiterC = RotL64((aOrbiterC * 9373765929885750185U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 10832873941223609012U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 8212600587135328040U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5334613996794796145U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5312744319781971178U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6173741211706546923U;
            aOrbiterE = RotL64((aOrbiterE * 12854414066390848249U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3693249147883790810U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 18365859989736602556U;
            aOrbiterF = RotL64((aOrbiterF * 3348463719324104997U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (RotL64(aOrbiterD, 20U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterC, 13U));
            aWandererF = aWandererF + (((RotL64(aCross, 53U) + RotL64(aOrbiterF, 60U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 35U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 51U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 44U) + RotL64(aOrbiterE, 5U)) + aOrbiterF) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererB, 22U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14445U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10781U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13846U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14599U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 40U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 17668251151213543491U) + aPhaseDOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 16101602509895104517U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aIngress, 18U)) + 9083915270773304935U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 12810720730318214811U;
            aOrbiterF = (aWandererF + RotL64(aCross, 43U)) + 18113428002071925621U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1582208899354109878U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 4180688104819188154U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3391785441902730815U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 8954598189262820611U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15360094153175355879U;
            aOrbiterF = RotL64((aOrbiterF * 8177798855402983685U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8383954114668216260U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15626783326234049197U;
            aOrbiterD = RotL64((aOrbiterD * 15058420415480073793U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10609978564404958066U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17656516608997517984U;
            aOrbiterH = RotL64((aOrbiterH * 4590620354119899777U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 760077259110786536U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 3597338735888033063U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6548831472863517621U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 29U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterD, 43U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 13U)) + aOrbiterG) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 21U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22805U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16618U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17157U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((aIndex + 19413U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 57U)) + (RotL64(aPrevious, 22U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 58U)) + RotL64(aCarry, 41U)) + 16189787374324972735U) + aPhaseDOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 17563763730956242224U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aCross, 3U)) + 10572803498593789385U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 19U)) + 7713105232072974166U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 41U)) + 10760839534772718139U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13397069448391230253U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4569255679998375682U;
            aOrbiterE = RotL64((aOrbiterE * 15163488708398248639U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9888769350817876949U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 11351796060878856300U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13356749147334008399U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 18153775071965707204U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1282846411145853435U;
            aOrbiterD = RotL64((aOrbiterD * 12294455920906257823U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16457743979262460660U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 173493260775251032U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4935807229040883505U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3927345926316409630U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5158769729850853623U;
            aOrbiterJ = RotL64((aOrbiterJ * 2446452358663812945U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 34U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 51U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 29U)) + aOrbiterD);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 42U) + aOrbiterB) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterE, 4U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterE, 13U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25702U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((aIndex + 24863U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27474U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 32537U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 41U) + RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 11U)) + 12809562813316740345U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 21U)) + 17084212535326321199U;
            aOrbiterC = (((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 53U)) + 16074921689983846769U) + aPhaseDOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 14027986153007120145U;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 38U)) + RotL64(aCarry, 23U)) + 7633455951809250227U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 340989348513370174U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 5307820377645020116U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8402492604131262157U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5605285015771527274U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5293500434746182790U;
            aOrbiterJ = RotL64((aOrbiterJ * 17674669610895537063U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7263156475892261811U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10672879570907433005U;
            aOrbiterF = RotL64((aOrbiterF * 2506338667179450741U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 16659226780900986107U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 9774892622769850665U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7487477727543183211U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10728057184108279042U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5032485856947407217U;
            aOrbiterH = RotL64((aOrbiterH * 16651577903809154285U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterJ, 23U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 48U) + aOrbiterC) + RotL64(aOrbiterI, 34U)) + aPhaseDWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 43U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Karate_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4338U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6885U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4369U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 7887U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aPrevious, 26U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 23U)) + 1297415699043177788U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 17583786534509260153U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 60U)) + RotL64(aCarry, 23U)) + 643197858925708798U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 5062653766915694874U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 47U)) + 7034273638367180511U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 37U)) + 2026909726972916996U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 53U)) + 2785690475553211646U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 2910341716302991892U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2834181605200829791U;
            aOrbiterJ = RotL64((aOrbiterJ * 1510617068750957651U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13323052600571281928U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10434901530315760460U;
            aOrbiterH = RotL64((aOrbiterH * 2042210188346767033U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 247903955625194782U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5196515747387257163U;
            aOrbiterI = RotL64((aOrbiterI * 1799024689023272275U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 7196305682377987476U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 14777739876892587484U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 95220583948241581U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10609060796540136671U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 8386027207212484155U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4855610536246556893U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 729659744301903424U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2350564261412606157U;
            aOrbiterG = RotL64((aOrbiterG * 16713856782349084977U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16611987556673864177U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1525195188708550503U;
            aOrbiterK = RotL64((aOrbiterK * 10045858602151004553U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 11U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aCross, 41U) + RotL64(aOrbiterH, 30U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 51U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 13U)) + aPhaseEWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterK, 57U)) + aPhaseEWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 41U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererC, 10U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11305U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((aIndex + 12347U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12392U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15578U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 6U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererB + RotL64(aCross, 53U)) + 9133751643283278896U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 37U)) + 8971581804375380408U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 12559650383714566592U) + aPhaseEOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 15753206088872859163U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 37U)) + 7640756270450762350U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 11U)) + 7340073357551376125U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 60U)) + 5270256573644196046U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 3567367996479995928U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11939634537492733738U;
            aOrbiterB = RotL64((aOrbiterB * 5640541900117183639U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7051817732424527120U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1730487669951837941U;
            aOrbiterH = RotL64((aOrbiterH * 15191634337956285841U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 18009252467909454817U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2361024272031696442U;
            aOrbiterC = RotL64((aOrbiterC * 15215151562500226027U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15902755877642960397U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12243517544704116184U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2576071074148141447U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16846181962302186187U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 636121425116506681U;
            aOrbiterD = RotL64((aOrbiterD * 17075030673338779993U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6887385655828217318U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 3705834550934775862U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11275428284929594435U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11165142437077969438U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6426659930331618269U;
            aOrbiterG = RotL64((aOrbiterG * 17170640810530893705U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 43U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 6U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 41U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 47U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aIngress, 22U) + RotL64(aOrbiterF, 54U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterF, 35U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 29U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterB, 19U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 4U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23842U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 19233U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19575U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18939U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 47U)) ^ (RotL64(aCarry, 10U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 29U)) + 13481227414590594621U;
            aOrbiterC = (aWandererD + RotL64(aCross, 29U)) + 17425964381118918026U;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 47U)) + 4792004356135956581U) + aPhaseEOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 11926849936000639098U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 56U)) + 990697329347742142U;
            aOrbiterI = (aWandererK + RotL64(aCross, 13U)) + 9307721505373076588U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 41U)) + 17605732738841908719U) + aPhaseEOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13110764518634187439U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17970109897810645911U;
            aOrbiterF = RotL64((aOrbiterF * 10395095143998920213U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10273133817644703654U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11239046688920468137U;
            aOrbiterC = RotL64((aOrbiterC * 5197802934333553327U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8355821483275763145U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15522151127786049345U;
            aOrbiterE = RotL64((aOrbiterE * 4844278537850520413U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5381663179722418112U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 9551368011768104906U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14202470972121732997U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 16264476585232221270U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7721417776432288282U;
            aOrbiterG = RotL64((aOrbiterG * 10267770327791051869U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 339418090653475277U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3247926250495935511U;
            aOrbiterI = RotL64((aOrbiterI * 16824669543765729097U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3390560045236418590U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 3894024951542543635U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10599637790900418767U), 43U);
            //
            aIngress = RotL64(aOrbiterH, 13U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 60U));
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterF, 18U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterI, 29U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterG, 53U)) + aPhaseEWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 47U)) + aOrbiterE) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 35U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aIngress, 34U) + RotL64(aOrbiterA, 41U)) + aOrbiterI) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 48U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28128U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 25994U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25712U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24600U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 24U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 28U)) + RotL64(aCarry, 19U)) + 2783898056762489197U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 47U)) + 7177192902873343053U;
            aOrbiterG = (aWandererE + RotL64(aCross, 21U)) + 12254703232691980774U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 39U)) + RotL64(aCarry, 41U)) + 15446547245691219559U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 13U)) + 888475203006174856U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 3U)) + 3649183529366307877U;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 4642631047518805167U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 6108329730724782250U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8334054653023816636U;
            aOrbiterG = RotL64((aOrbiterG * 9352516059501924393U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5891895375031474350U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3176720746238477862U;
            aOrbiterA = RotL64((aOrbiterA * 1869961473768307911U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6111038696865301675U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11914998302228682704U;
            aOrbiterI = RotL64((aOrbiterI * 11738924766359642853U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17005063057791320948U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 18333780598768130670U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5416759844884107303U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2056115016443263153U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10245512728872962677U;
            aOrbiterF = RotL64((aOrbiterF * 707106795383284903U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 4810366069422162351U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 3051442983125942469U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13558537578054436423U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9285068547223654308U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13067251130180968842U;
            aOrbiterH = RotL64((aOrbiterH * 7000687697769766605U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 10U) + aOrbiterJ) + RotL64(aOrbiterB, 3U));
            aWandererE = aWandererE + ((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 47U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 36U)) + aOrbiterI);
            aWandererA = aWandererA + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 21U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 53U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 27U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterA, 11U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 28U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Karate_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1027U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((aIndex + 2540U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 734U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 1101U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 36U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCross, 57U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererC + RotL64(aCross, 29U)) + 4739486756133131180U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 10U)) + RotL64(aCarry, 23U)) + 16089707555501328184U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 21U)) + 15310047330238536453U;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 7901411596386834955U) + aPhaseFOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 3U)) + 4357555491060982163U) + aPhaseFOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 15667085602825720102U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 8520635334382269253U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7348648918661047791U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1772509779231068315U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15336170957886025677U;
            aOrbiterE = RotL64((aOrbiterE * 10996880551392077399U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8628770833489469980U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15469234024247246228U;
            aOrbiterI = RotL64((aOrbiterI * 8905266995119987947U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10796430900884288328U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10660110397012853289U;
            aOrbiterK = RotL64((aOrbiterK * 9140007610912037461U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 11202284258711214794U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 17509491802893182994U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9329107599972703671U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 30U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 18U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterI, 57U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 47U)) + aOrbiterD) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 18U) + aOrbiterE) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererD, 58U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12942U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((aIndex + 11208U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13595U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14612U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 57U)) + (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 30U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererC + RotL64(aIngress, 54U)) + 4204560462077827182U;
            aOrbiterD = (aWandererG + RotL64(aCross, 43U)) + 6572370199668594039U;
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 35U)) + 15958999876732622825U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 47U)) + 9969349486879280377U;
            aOrbiterB = (((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 19U)) + 15450238998293956181U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9128619863683138259U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 5691270563628979565U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2170424734274640859U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5901029710568933106U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10442738941988588834U;
            aOrbiterB = RotL64((aOrbiterB * 7386621444831603817U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 3508116020325721993U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 13221917083569767259U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6845108555710135357U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 11627915460377128176U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17858261365514253433U;
            aOrbiterD = RotL64((aOrbiterD * 7535577636975884641U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4294837988806295989U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11242915481585070249U;
            aOrbiterJ = RotL64((aOrbiterJ * 17540688242763829319U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 37U);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterD, 11U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterB, 41U));
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterB, 20U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 57U)) + aOrbiterB) + aPhaseFWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20169U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16990U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23347U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21218U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aIngress, 26U)) + (RotL64(aPrevious, 57U) + RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 39U)) + 6973892330986118220U;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 9886813896272094864U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 10996306582517553173U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 5U)) + 8490648283899856223U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aCross, 46U)) + 105141713530704655U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 3114337422810562588U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 980857684690886131U;
            aOrbiterF = RotL64((aOrbiterF * 17407927633910728721U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 6562042345807072665U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15665371138706353619U;
            aOrbiterG = RotL64((aOrbiterG * 8086237578564620623U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 18113013571374375028U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17405346422601997299U;
            aOrbiterE = RotL64((aOrbiterE * 11162604605443005253U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5130876096426182506U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1813821672299154629U;
            aOrbiterA = RotL64((aOrbiterA * 15478100342425611875U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 15793814882743306728U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 13925299440495476399U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12049601510660117401U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 54U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 13U)) + aOrbiterA) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 60U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterG, 21U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aCross, 21U) + RotL64(aOrbiterG, 47U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 39U)) + aOrbiterA) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30091U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 28508U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28376U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 32711U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 42U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererC + RotL64(aScatter, 47U)) + 13442819395490639310U;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 8187292523194120936U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 38U)) + RotL64(aCarry, 3U)) + 11469697159823131388U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 13414083692375929653U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 57U)) + 11404010733687907517U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 6783212827186218247U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 8561131439340372614U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7426867125542470683U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6252609642004429113U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 12804867444200448952U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3114688959081972615U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2739648749603690781U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14808861217017399752U;
            aOrbiterJ = RotL64((aOrbiterJ * 373911885694012101U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17588866502571268888U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 5882260142735642980U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7688252946143263869U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15493099088132862949U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5175647411532429582U;
            aOrbiterK = RotL64((aOrbiterK * 15226544495598541883U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterK, 40U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 60U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 19U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 11U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 56U) + aOrbiterF) + RotL64(aOrbiterI, 43U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_Karate_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 3786U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1293U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1515U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneD[((aIndex + 799U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 20U) + RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererG + RotL64(aIngress, 21U)) + 11039986441331892533U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 56U)) + RotL64(aCarry, 41U)) + 6256024955965426119U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 11U)) + 9857443189988995666U;
            aOrbiterF = (((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 11900944813380998208U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 21U)) + 8422577734978875541U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3100835100713928724U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11871553509810206993U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15501681886909921677U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17614749493763417027U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3638372131856199916U;
            aOrbiterC = RotL64((aOrbiterC * 480683274898147025U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6582275259281025770U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17016882418498941958U;
            aOrbiterF = RotL64((aOrbiterF * 4269869255230867823U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1747214688658984715U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 9356088987044015278U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16221733545319753695U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 4056238112133473456U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 16013150119949532998U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12913648646318115315U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 13U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 44U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 57U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 3U)) + aPhaseGWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 40U) + aOrbiterB) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterF, 48U)) + aPhaseGWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15809U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14828U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16265U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneA[((aIndex + 10736U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 4U) ^ RotL64(aCarry, 53U)) + (RotL64(aPrevious, 35U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 27U)) + 14499676118633326000U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 17191273593018552288U;
            aOrbiterF = (((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 41U)) + 4085176294948097737U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 29U)) + 11112671474158908186U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 52U)) + 8745787969012266485U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 18074049663777707948U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2543758649719164688U;
            aOrbiterF = RotL64((aOrbiterF * 7153845562786344373U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4659584749412700523U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 974639159259871273U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17918719351847605523U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9211220687971081987U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8567024626862182714U;
            aOrbiterI = RotL64((aOrbiterI * 7755874089832496393U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 5803002132294840900U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 11968489432878148467U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4501441062617123165U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9470807228394903442U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1692347973120388469U;
            aOrbiterJ = RotL64((aOrbiterJ * 17433393164156231575U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterI, 11U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterB, 19U)) + aPhaseGWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 52U) + RotL64(aOrbiterI, 54U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 21550U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((aIndex + 24520U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17151U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((aIndex + 16834U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 27U)) ^ (RotL64(aPrevious, 12U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 27U)) + 15726877954695761686U) + aPhaseGOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 14187652171881943587U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 35U)) + 8420423151313882782U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 4U)) + RotL64(aCarry, 57U)) + 14942322692433259283U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 51U)) + 7272331475919796255U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 154504365041805840U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 17475491222554948786U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2095330528612694779U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5759181483165339605U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5993060214499322845U;
            aOrbiterE = RotL64((aOrbiterE * 10799489831896153301U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10901786237875941844U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17135786595614068473U;
            aOrbiterB = RotL64((aOrbiterB * 15923538730142047043U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 5208202073886811165U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6821452921018900631U;
            aOrbiterG = RotL64((aOrbiterG * 13119330055184115669U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 13348064837402206969U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8967943922403445136U;
            aOrbiterJ = RotL64((aOrbiterJ * 300168481725373093U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterG, 3U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 28U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 37U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterJ, 11U)) + aPhaseGWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 37U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 25822U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29959U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30963U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 25049U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 26U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererE + RotL64(aIngress, 21U)) + 13714409587461539863U;
            aOrbiterE = (((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 14101156723903265839U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 39U)) + 7063754562895369001U;
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 56U)) + RotL64(aCarry, 23U)) + 12320578575245519386U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aIngress, 13U)) + 11744826789631008424U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8744816505096675597U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10405435520084528645U;
            aOrbiterH = RotL64((aOrbiterH * 13279521344071568023U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 1463157688070683543U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12379603577919617703U;
            aOrbiterG = RotL64((aOrbiterG * 14858901470015109311U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 1343439118031348146U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16118850268070235540U;
            aOrbiterA = RotL64((aOrbiterA * 11184386483735388257U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 14116264435819277136U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5251698273012432109U;
            aOrbiterE = RotL64((aOrbiterE * 1495818611622063967U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 14806408656041403829U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11569345414052398227U;
            aOrbiterI = RotL64((aOrbiterI * 9913158908301414861U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 30U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 57U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 50U) + RotL64(aOrbiterA, 29U)) + aOrbiterH) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 40U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 18U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Karate_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 6821U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 7622U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7802U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3050U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 28U)) + (RotL64(aPrevious, 41U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererC + RotL64(aIngress, 6U)) + RotL64(aCarry, 3U)) + 12029393034357490020U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 39U)) + 4526754731580694987U) + aPhaseHOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 17060419646421271853U) + aPhaseHOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 4128488893837059683U;
            aOrbiterH = (aWandererH + RotL64(aCross, 53U)) + 12706894827547160110U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12506324593645825056U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12581344490649250025U;
            aOrbiterC = RotL64((aOrbiterC * 16311882267466003291U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14357032418199130132U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 15341977701796331249U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6332369248718076031U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7086602307544733241U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12398300065276832486U;
            aOrbiterK = RotL64((aOrbiterK * 18157408831225635333U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 2499745046076601988U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 7249361592814001829U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14597139848072319685U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3254456186337366437U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 3472973415969046680U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14583566953969168353U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 24U));
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 43U)) + aOrbiterK);
            aWandererC = aWandererC + ((((RotL64(aIngress, 30U) + aOrbiterC) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 27U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 58U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterF, 13U)) + aOrbiterH) + aPhaseHWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererD, 56U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 16144U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11570U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10101U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9760U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 6U)) + (RotL64(aCarry, 37U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererJ + RotL64(aCross, 13U)) + 4751694786009671052U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 16362725160370844224U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (((aWandererH + RotL64(aScatter, 4U)) + RotL64(aCarry, 13U)) + 6360885380915941057U) + aPhaseHOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 41U)) + 5154536007972297036U;
            aOrbiterB = (aWandererA + RotL64(aCross, 43U)) + 9362540581874808253U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 13902493871525612934U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 10208452885367546542U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12067703239567933105U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3117030377279160998U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17286247690414027870U;
            aOrbiterB = RotL64((aOrbiterB * 4896931759653832095U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 3930314320040949141U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7289525252391668404U;
            aOrbiterJ = RotL64((aOrbiterJ * 15452162299105112187U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3434167955466809185U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 17852573095128575663U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1485660158767033425U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6137259687928853253U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13992510605237574698U;
            aOrbiterE = RotL64((aOrbiterE * 15346263295995333395U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (RotL64(aOrbiterD, 4U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 14U) + RotL64(aOrbiterE, 41U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 60U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterE, 29U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterF, 11U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 18778U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20005U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19324U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18865U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 56U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererF + RotL64(aIngress, 21U)) + 9654059367478508868U) + aPhaseHOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 6473006635864677427U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 51U)) + 6944184481315853243U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 52U)) + RotL64(aCarry, 35U)) + 4061496421939102306U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aIngress, 13U)) + 15791809275719085463U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 14050798802646323055U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12072905924741758266U;
            aOrbiterC = RotL64((aOrbiterC * 4757104346636738119U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 17639076509231343896U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12195388285571234715U;
            aOrbiterG = RotL64((aOrbiterG * 4317060502521195769U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4325404419499496529U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5910567888204238382U;
            aOrbiterD = RotL64((aOrbiterD * 11503787177122206937U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 13092940059929942699U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13381962590820308761U;
            aOrbiterB = RotL64((aOrbiterB * 6345904465930943295U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 15622862439323440527U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14027151901132249793U;
            aOrbiterA = RotL64((aOrbiterA * 2273573821630510087U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterB, 4U)) + aPhaseHWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 47U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterC, 39U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 4U) + aOrbiterA) + RotL64(aOrbiterC, 27U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 52U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 27925U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24672U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30202U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneC[((aIndex + 27212U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 56U) + RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererH + RotL64(aCross, 3U)) + 11700815697312060726U) + aPhaseHOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aIngress, 27U)) + 11808423452327465441U) + aPhaseHOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 8670503858631730886U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 18U)) + RotL64(aCarry, 5U)) + 2400061067991988544U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 16163118178366229686U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3280178595904941068U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3298683600817047727U;
            aOrbiterA = RotL64((aOrbiterA * 9865649058799255343U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16321624053445183574U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6730229877611375225U;
            aOrbiterF = RotL64((aOrbiterF * 2022290495153519279U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 10162830636713641322U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15646771327759599256U;
            aOrbiterK = RotL64((aOrbiterK * 15333053762177144775U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 14841751262270544102U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 9545541117228834895U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11529769874752969377U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 14676615635857599982U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1231768638470558855U;
            aOrbiterJ = RotL64((aOrbiterJ * 2716808508509014677U), 39U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 19U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 28U) + aOrbiterD) + RotL64(aOrbiterA, 29U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 5U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 50U));
            aWandererG = aWandererG + ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 41U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
