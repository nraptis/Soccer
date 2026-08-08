//
//  Soccer2.cpp
//  Scramble
//
//  Created by nick on 8/1/26.
//

#include "Soccer2.hpp"
#include "SoccerFolding.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"
#include "EncryptionPlan.hpp"
#include "SoccerRotationBank.hpp"

#include <algorithm>
#include <cstring>

/*
 Rotation-bank integration

 Cryptex and SoccerRotationBank use the same seven stages: L3A, L2A, L1A,
 L3B, L2B, L1B, and L3C.  Each stage owns one request count, one response
 array, and one cursor.  There are no synthetic final-stage buckets and no
 splitting at the middle L3B stage.

 The complete EncryptionPlan is created before any cipher.  Its Meson members
 are counted per stage and sent to SoccerRotationBank::Withdraw, which selects
 mutually non-contending full-, half-, and quarter-lane rotations.  PopRotation
 then advances a separate cursor for each stage.  A zero return is an
 exhausted or invalid bank entry; GenerateCipher treats it as construction
 failure instead of quietly creating a zero-distance rotation.

 Bank values are canonical effective encryption shifts.  RotateMaskCipher uses
 that value directly.  RotateCipher applies the inverse of its constructor value
 while sealing, so GenerateCipher passes laneLength - bankRotation to it.  This
 makes masked and non-masked rotation ciphers move in the same canonical
 direction and lets the bank compare their real effects rather than their
 differing constructor conventions.
 */

#define BLOCK_COUNT (SOCCER_BLOCK_SIZE / S_BLOCK)

#define COMPLEXITY_STRONG 16
#define COMPLEXITY_NORMAL 8
#define COMPLEXITY_WEAK 4

#define WARM_UP_BLOCKS 4

namespace {

constexpr std::uint8_t kStageL3A = 0U;
constexpr std::uint8_t kStageL2A = 1U;
constexpr std::uint8_t kStageL1A = 2U;
constexpr std::uint8_t kStageL3B = 3U;
constexpr std::uint8_t kStageL2B = 4U;
constexpr std::uint8_t kStageL1B = 5U;
constexpr std::uint8_t kStageL3C = 6U;

} // namespace

static_assert((SOCCER_BLOCK_SIZE % S_BLOCK) == 0U);
static_assert(BLOCK_COUNT >= WARM_UP_BLOCKS);

std::uint8_t                                Soccer2::mMaterialA[SOCCER_BLOCK_SIZE];
std::uint8_t                                Soccer2::mMaterialB[SOCCER_BLOCK_SIZE];
std::uint8_t                                Soccer2::mMaterialC[SOCCER_BLOCK_SIZE];
std::uint8_t                                Soccer2::mMaterialD[SOCCER_BLOCK_SIZE];

std::uint8_t                                Soccer2::mMaterialE[SOCCER_BLOCK_SIZE];
std::uint8_t                                Soccer2::mMaterialF[SOCCER_BLOCK_SIZE];
std::uint8_t                                Soccer2::mMaterialG[SOCCER_BLOCK_SIZE];
std::uint8_t                                Soccer2::mMaterialH[SOCCER_BLOCK_SIZE];

std::uint8_t                                Soccer2::mMaterialI[SOCCER_BLOCK_SIZE];
std::uint8_t                                Soccer2::mMaterialJ[SOCCER_BLOCK_SIZE];
std::uint8_t                                Soccer2::mMaterialK[SOCCER_BLOCK_SIZE];
std::uint8_t                                Soccer2::mMaterialL[SOCCER_BLOCK_SIZE];

std::uint8_t                                Soccer2::mMaterialM[SOCCER_BLOCK_SIZE];
std::uint8_t                                Soccer2::mMaterialN[SOCCER_BLOCK_SIZE];
std::uint8_t                                Soccer2::mMaterialO[SOCCER_BLOCK_SIZE];
std::uint8_t                                Soccer2::mMaterialP[SOCCER_BLOCK_SIZE];

TwistFarmSalt                               cFarmSalt;

TwistExpander_Gemma                         cStarter;

TwistExpander_Achernar                      cAchernar; // 1
TwistExpander_Alcor                         cAlcor; // 2
TwistExpander_Aldebaran                     cAldebaran; // 3
TwistExpander_Alioth                        cAlioth; // 4
TwistExpander_Alkaid                        cAlkaid; // 5
TwistExpander_Alnitak                       cAlnitak; // 6
TwistExpander_Altair                        cAltair; // 7
TwistExpander_Ankaa                         cAnkaa; // 8
TwistExpander_Antares                       cAntares; // 9
TwistExpander_Arcturus                      cArcturus; // 10
TwistExpander_Athebyne                      cAthebyne; // 11
TwistExpander_Bellatrix                     cBellatrix; // 12
TwistExpander_Betelgeuse                    cBetelgeuse; // 13
TwistExpander_Canopus                       cCanopus; // 14
TwistExpander_Capella                       cCapella; // 15
TwistExpander_Castor                        cCastor; // 16
TwistExpander_Mebsuta                       cMebsuta; // 17
TwistExpander_Menkent                       cMenkent; // 18
TwistExpander_Mimosa                        cMimosa; // 19
TwistExpander_Miram                         cMiram; // 20
TwistExpander_Mirfak                        cMirfak; // 21
TwistExpander_Mothallah                     cMothallah; // 22
TwistExpander_Naos                          cNaos; // 23
TwistExpander_Polaris                       cPolaris; // 24
TwistExpander_Pollux                        cPollux; // 25
TwistExpander_Procyon                       cProcyon; // 26
TwistExpander_Regulus                       cRegulus; // 27
TwistExpander_Rigel                         cRigel; // 28
TwistExpander_Saiph                         cSaiph; // 29
TwistExpander_Sirius                        cSirius; // 30
TwistExpander_Suhail                        cSuhail; // 31
TwistExpander_Vega                          cVega; // 32

TwistWorkSpace                              Soccer2::mWorkSpaceA;
TwistWorkSpace                              Soccer2::mWorkSpaceB;
TwistWorkSpace                              Soccer2::mWorkSpaceC;
TwistWorkSpace                              Soccer2::mWorkSpaceD;
TwistWorkSpace                              Soccer2::mWorkSpaceE;
TwistWorkSpace                              Soccer2::mWorkSpaceF;
TwistWorkSpace                              Soccer2::mWorkSpaceG;
TwistWorkSpace                              Soccer2::mWorkSpaceH;
TwistWorkSpace                              Soccer2::mWorkSpaceI;
TwistWorkSpace                              Soccer2::mWorkSpaceJ;
TwistWorkSpace                              Soccer2::mWorkSpaceK;
TwistWorkSpace                              Soccer2::mWorkSpaceL;
TwistWorkSpace                              Soccer2::mWorkSpaceM;
TwistWorkSpace                              Soccer2::mWorkSpaceN;
TwistWorkSpace                              Soccer2::mWorkSpaceO;
TwistWorkSpace                              Soccer2::mWorkSpaceP;

std::uint8_t                                Soccer2::mRandom[S_BLOCK];
std::uint8_t                                Soccer2::mScratch[SOCCER_BLOCK_SIZE];
std::uint8_t                                Soccer2::mCryptTemp[SOCCER_BLOCK_SIZE];

std::uint8_t                                Soccer2::mCollapseLaneA[SOCCER_BLOCK_SIZE];
std::uint8_t                                Soccer2::mCollapseLaneB[SOCCER_BLOCK_SIZE];
std::uint8_t                                Soccer2::mCollapseLaneC[SOCCER_BLOCK_SIZE];
std::uint8_t                                Soccer2::mCollapseLaneD[SOCCER_BLOCK_SIZE];

std::uint8_t                                Soccer2::mShrinkLaneA[SOCCER_BLOCK_SIZE_L1];
std::uint8_t                                Soccer2::mShrinkLaneB[SOCCER_BLOCK_SIZE_L1];
std::uint8_t                                Soccer2::mShrinkLaneC[SOCCER_BLOCK_SIZE_L1];
std::uint8_t                                Soccer2::mShrinkLaneD[SOCCER_BLOCK_SIZE_L1];

std::uint8_t                                Soccer2::mCompressLaneA[SOCCER_BLOCK_SIZE_C2];
std::uint8_t                                Soccer2::mCompressLaneB[SOCCER_BLOCK_SIZE_C2];
std::uint8_t                                Soccer2::mCompressLaneC[SOCCER_BLOCK_SIZE_C2];
std::uint8_t                                Soccer2::mCompressLaneD[SOCCER_BLOCK_SIZE_C2];

//std::uint8_t                                Soccer2::mCompactLaneA[SOCCER_BLOCK_SIZE_C1];
//std::uint8_t                                Soccer2::mCompactLaneB[SOCCER_BLOCK_SIZE_C1];
//std::uint8_t                                Soccer2::mCompactLaneC[SOCCER_BLOCK_SIZE_C1];
//std::uint8_t                                Soccer2::mCompactLaneD[SOCCER_BLOCK_SIZE_C1];

std::uint8_t                                Soccer2::mCrushA[S_BLOCK];
std::uint8_t                                Soccer2::mCrushB[S_BLOCK];
std::uint8_t                                Soccer2::mCrushC[S_BLOCK];
std::uint8_t                                Soccer2::mCrushD[S_BLOCK];

std::size_t                                 Soccer2::mIndexListA[2048];
std::size_t                                 Soccer2::mIndexListB[2048];

std::uint64_t                               Soccer2::mRolledA[256];
std::uint64_t                               Soccer2::mRolledB[256];

std::uint64_t                               Soccer2::mRotationSeedS3[SOCCER_ROTATION_WORD_COUNT_S3];
std::uint64_t                               Soccer2::mRotationSeedS2[SOCCER_ROTATION_WORD_COUNT_S2];
std::uint64_t                               Soccer2::mRotationSeedS1[SOCCER_ROTATION_WORD_COUNT_S1];






std::uint8_t                                Soccer2::mMasks[32];

std::uint8_t                                *Soccer2::mMaterials[16];
TwistExpander                               *Soccer2::mExpanders[32];
TwistWorkSpace                              *Soccer2::mWorkSpaces[16];
std::uint8_t                                *Soccer2::mSources[16];
std::uint8_t                                *Soccer2::mCross[4][16];

bool                                        Soccer2::mClaimed[32];

TwistExpander                               *Soccer2::mClaimedExpanders[16];
std::size_t                                 Soccer2::mClaimedExpanderCount;

std::uint8_t                                *Soccer2::mClaimedMaterials[16];
std::size_t                                 Soccer2::mClaimedMaterialCount;

TwistWorkSpace                              *Soccer2::mClaimedWorkSpaces[16];
std::size_t                                 Soccer2::mClaimedWorkSpaceCount;

Cryptex                                     Soccer2::mCryptex;

std::uint8_t                                *Soccer2::mShuffleMaterials[16];
TwistExpander                               *Soccer2::mShuffleExpanders[32];
TwistWorkSpace                              *Soccer2::mShuffleWorkSpaces[16];

CipherType                                  Soccer2::mCiphers[256];

EncryptionStrength                          Soccer2::mStrength = EncryptionStrength::kNormal;

uint32_t                                    Soccer2::mTestBlockLength = SOCCER_BLOCK_SIZE;

std::uint32_t                               cRandIndexA = 0;
std::uint32_t                               cRandIndexB = 0;
bool                                        cRandLane = false;


std::size_t                                 cMaskIndex = 0;

std::size_t                                 cMaterialIndex = 0;
std::size_t                                 cMaterialQuarter = 0;

std::size_t                                 Soccer2::mRotationBankCursorL3A = 0;
std::size_t                                 Soccer2::mRotationBankCursorL2A = 0;
std::size_t                                 Soccer2::mRotationBankCursorL1A = 0;

std::size_t                                 Soccer2::mRotationBankCursorL3B = 0;
std::size_t                                 Soccer2::mRotationBankCursorL2B = 0;
std::size_t                                 Soccer2::mRotationBankCursorL1B = 0;

std::size_t                                 Soccer2::mRotationBankCursorL3C = 0;

SoccerRotationBankResponse                  cRotationBankResponse;

std::uint64_t                               SoccerRand() {
    if (cRandLane == true) {
        cRandLane = false;
        cRandIndexA = ((cRandIndexA + 1) & 0xFFU);
        return Soccer2::mRolledA[cRandIndexA];
    } else {
        cRandLane = true;
        cRandIndexB = ((cRandIndexB + 1) & 0xFFU);
        return Soccer2::mRolledB[cRandIndexB];
    }
}

std::uint8_t *Soccer2::PopLaneS3() {
    if (cMaterialQuarter != 0U) {
        cMaterialIndex++;
        cMaterialQuarter = 0U;
    }
    if (cMaterialIndex >= 16U) {
        return nullptr;
    }

    std::uint8_t *aResult = mMaterials[cMaterialIndex];
    cMaterialIndex++;
    return aResult;
}

std::uint8_t *Soccer2::PopLaneS2() {
    if ((cMaterialQuarter + 2U) > 4U) {
        cMaterialIndex++;
        cMaterialQuarter = 0U;
    }
    if (cMaterialIndex >= 16U) {
        return nullptr;
    }

    std::uint8_t *aResult = mMaterials[cMaterialIndex] + (cMaterialQuarter * SOCCER_BLOCK_SIZE_L1);
    cMaterialQuarter += 2U;
    if (cMaterialQuarter == 4U) {
        cMaterialIndex++;
        cMaterialQuarter = 0U;
    }
    return aResult;
}

std::uint8_t *Soccer2::PopLaneS1() {
    if (cMaterialIndex >= 16U) {
        return nullptr;
    }

    std::uint8_t *aResult = mMaterials[cMaterialIndex] + (cMaterialQuarter * SOCCER_BLOCK_SIZE_L1);
    cMaterialQuarter++;
    if (cMaterialQuarter == 4U) {
        cMaterialIndex++;
        cMaterialQuarter = 0U;
    }
    return aResult;
}

std::uint8_t Soccer2::PopMask() {
    const std::uint8_t aResult = mMasks[cMaskIndex];
    cMaskIndex++;
    if (cMaskIndex == 32U) {
        cMaskIndex = 0U;
    }
    return aResult;
}

std::int32_t Soccer2::PopRotation(std::uint8_t pStage) {
    if (pStage == kStageL3A) {
        if (mRotationBankCursorL3A >= 4U) { return 0U; }
        return cRotationBankResponse.mAmountL3A[mRotationBankCursorL3A++];
    }
    if (pStage == kStageL2A) {
        if (mRotationBankCursorL2A >= 4U) { return 0U; }
        return cRotationBankResponse.mAmountL2A[mRotationBankCursorL2A++];
    }
    if (pStage == kStageL1A) {
        if (mRotationBankCursorL1A >= 4U) { return 0U; }
        return cRotationBankResponse.mAmountL1A[mRotationBankCursorL1A++];
    }
    if (pStage == kStageL3B) {
        if (mRotationBankCursorL3B >= 4U) { return 0U; }
        return cRotationBankResponse.mAmountL3B[mRotationBankCursorL3B++];
    }
    if (pStage == kStageL2B) {
        if (mRotationBankCursorL2B >= 4U) { return 0U; }
        return cRotationBankResponse.mAmountL2B[mRotationBankCursorL2B++];
    }
    if (pStage == kStageL1B) {
        if (mRotationBankCursorL1B >= 4U) { return 0U; }
        return cRotationBankResponse.mAmountL1B[mRotationBankCursorL1B++];
    }
    if (pStage == kStageL3C) {
        if (mRotationBankCursorL3C >= 4U) { return 0U; }
        return cRotationBankResponse.mAmountL3C[mRotationBankCursorL3C++];
    }
    return 0U;
}

Crypt *Soccer2::GenerateCipher(CipherType pType, std::uint8_t pStage) {
    if (pStage > kStageL3C) {
        return nullptr;
    }

    auto PopLane = [pStage]() -> std::uint8_t * {
        if ((pStage == kStageL3A) ||
            (pStage == kStageL3B) ||
            (pStage == kStageL3C)) {
            return PopLaneS3();
        }
        if ((pStage == kStageL2A) || (pStage == kStageL2B)) {
            return PopLaneS2();
        }
        return PopLaneS1();
    };

    switch (pType) {
        case CipherType::kPasswordXORCipher:
            return new PasswordXORCipher(PopLane());
        case CipherType::kPasswordAddCipher:
            return new PasswordAddCipher(PopLane());
        case CipherType::kPasswordSubtractCipher:
            return new PasswordSubtractCipher(PopLane());

        case CipherType::kPasswordJumpXORCipher: {
            std::uint8_t *aPassword = PopLane();
            std::uint8_t *aJumps = PopLane();
            return new PasswordJumpXORCipher(aPassword, aJumps);
        }
        case CipherType::kPasswordJumpAddCipher: {
            std::uint8_t *aPassword = PopLane();
            std::uint8_t *aJumps = PopLane();
            return new PasswordJumpAddCipher(aPassword, aJumps);
        }
        case CipherType::kPasswordJumpSubtractCipher: {
            std::uint8_t *aPassword = PopLane();
            std::uint8_t *aJumps = PopLane();
            return new PasswordJumpSubtractCipher(aPassword, aJumps);
        }

        case CipherType::kPepperNoiseXORCipher: {
            std::uint8_t *aMask = PopLane();
            std::uint8_t *aNoise = PopLane();
            return new PepperNoiseXORCipher(aMask, aNoise);
        }
        case CipherType::kPepperJumpNoiseXORCipher: {
            std::uint8_t *aMask = PopLane();
            std::uint8_t *aNoise = PopLane();
            std::uint8_t *aJumps = PopLane();
            return new PepperJumpNoiseXORCipher(aMask, aNoise, aJumps);
        }
        case CipherType::kPepperDualJumpNoiseXORCipher: {
            std::uint8_t *aMask = PopLane();
            std::uint8_t *aNoise = PopLane();
            std::uint8_t *aMaskJumps = PopLane();
            std::uint8_t *aNoiseJumps = PopLane();
            return new PepperDualJumpNoiseXORCipher(aMask, aNoise, aMaskJumps, aNoiseJumps);
        }
        case CipherType::kCascadeCipher:
            return new CascadeCipher(PopLane());
        case CipherType::kCascadeJumpCipher: {
            std::uint8_t *aMask = PopLane();
            std::uint8_t *aJumps = PopLane();
            return new CascadeJumpCipher(aMask, aJumps);
        }
        case CipherType::kRotateMaskCipher: {
            const std::int32_t aRotation = PopRotation(pStage);
            if (aRotation == 0) { return nullptr; }
            const std::uint8_t aMask = PopMask();
            return new RotateMaskCipher(aMask, aRotation);
        }
        case CipherType::kReverseMaskCipher:
            return new ReverseMaskCipher(PopMask());
        case CipherType::kInvertMaskCipher:
            return new InvertMaskCipher(PopMask());
        case CipherType::kReverseMaskByteBlockCipher32:
            return new ReverseMaskByteBlockCipher32(PopMask());
        case CipherType::kReverseMaskByteBlockCipher64:
            return new ReverseMaskByteBlockCipher64(PopMask());
        case CipherType::kSplintMaskBlockCipher32:
            return new SplintMaskBlockCipher32(PopMask());
        case CipherType::kSplintMaskBlockCipher64:
            return new SplintMaskBlockCipher64(PopMask());
        case CipherType::kRippleMaskBlockCipher32:
            return new RippleMaskBlockCipher32(PopMask());
        case CipherType::kRippleMaskBlockCipher64:
            return new RippleMaskBlockCipher64(PopMask());
        case CipherType::kRotateCipher: {
            const std::int32_t aRotation = PopRotation(pStage);
            if (aRotation == 0) { return nullptr; }

            std::int32_t aLaneLength = static_cast<std::int32_t>(SOCCER_BLOCK_SIZE_L1);
            if ((pStage == kStageL3A) ||
                (pStage == kStageL3B) ||
                (pStage == kStageL3C)) {
                aLaneLength = static_cast<std::int32_t>(SOCCER_BLOCK_SIZE);
            } else if ((pStage == kStageL2A) || (pStage == kStageL2B)) {
                aLaneLength = static_cast<std::int32_t>(SOCCER_BLOCK_SIZE_L2);
            }

            const std::int32_t aShift = aLaneLength - aRotation;
            return new RotateCipher(aShift);
        }
        default:
            return nullptr;
    }
}


void Soccer2::Zero() {
    std::memset(mMaterialA, 0, sizeof(mMaterialA));
    std::memset(mMaterialB, 0, sizeof(mMaterialB));
    std::memset(mMaterialC, 0, sizeof(mMaterialC));
    std::memset(mMaterialD, 0, sizeof(mMaterialD));
    std::memset(mMaterialE, 0, sizeof(mMaterialE));
    std::memset(mMaterialF, 0, sizeof(mMaterialF));
    std::memset(mMaterialG, 0, sizeof(mMaterialG));
    std::memset(mMaterialH, 0, sizeof(mMaterialH));
    std::memset(mMaterialI, 0, sizeof(mMaterialI));
    std::memset(mMaterialJ, 0, sizeof(mMaterialJ));
    std::memset(mMaterialK, 0, sizeof(mMaterialK));
    std::memset(mMaterialL, 0, sizeof(mMaterialL));
    std::memset(mMaterialM, 0, sizeof(mMaterialM));
    std::memset(mMaterialN, 0, sizeof(mMaterialN));
    std::memset(mMaterialO, 0, sizeof(mMaterialO));
    std::memset(mMaterialP, 0, sizeof(mMaterialP));

    std::memset(mRandom, 0, sizeof(mRandom));
    std::memset(mScratch, 0, sizeof(mScratch));
    std::memset(mCollapseLaneA, 0, sizeof(mCollapseLaneA));
    std::memset(mCollapseLaneB, 0, sizeof(mCollapseLaneB));
    std::memset(mCollapseLaneC, 0, sizeof(mCollapseLaneC));
    std::memset(mCollapseLaneD, 0, sizeof(mCollapseLaneD));
    std::memset(mShrinkLaneA, 0, sizeof(mShrinkLaneA));
    std::memset(mShrinkLaneB, 0, sizeof(mShrinkLaneB));
    std::memset(mShrinkLaneC, 0, sizeof(mShrinkLaneC));
    std::memset(mShrinkLaneD, 0, sizeof(mShrinkLaneD));
    std::memset(mCompressLaneA, 0, sizeof(mCompressLaneA));
    std::memset(mCompressLaneB, 0, sizeof(mCompressLaneB));
    std::memset(mCompressLaneC, 0, sizeof(mCompressLaneC));
    std::memset(mCompressLaneD, 0, sizeof(mCompressLaneD));
    std::memset(mCrushA, 0, sizeof(mCrushA));
    std::memset(mCrushB, 0, sizeof(mCrushB));
    std::memset(mCrushC, 0, sizeof(mCrushC));
    std::memset(mCrushD, 0, sizeof(mCrushD));
    std::memset(mIndexListA, 0, sizeof(mIndexListA));
    std::memset(mIndexListB, 0, sizeof(mIndexListB));
    std::memset(mRolledA, 0, sizeof(mRolledA));
    std::memset(mRolledB, 0, sizeof(mRolledB));
    std::memset(mRotationSeedS1, 0, sizeof(mRotationSeedS1));
    std::memset(mRotationSeedS2, 0, sizeof(mRotationSeedS2));
    std::memset(mRotationSeedS3, 0, sizeof(mRotationSeedS3));

    cRotationBankResponse = {};
    mRotationBankCursorL3A = 0U;
    mRotationBankCursorL2A = 0U;
    mRotationBankCursorL1A = 0U;
    mRotationBankCursorL3B = 0U;
    mRotationBankCursorL2B = 0U;
    mRotationBankCursorL1B = 0U;
    mRotationBankCursorL3C = 0U;

    std::memset(mCryptTemp, 0, sizeof(mCryptTemp));

    mWorkSpaceA.Zero();
    mWorkSpaceB.Zero();
    mWorkSpaceC.Zero();
    mWorkSpaceD.Zero();
    mWorkSpaceE.Zero();
    mWorkSpaceF.Zero();
    mWorkSpaceG.Zero();
    mWorkSpaceH.Zero();
    mWorkSpaceI.Zero();
    mWorkSpaceJ.Zero();
    mWorkSpaceK.Zero();
    mWorkSpaceL.Zero();
    mWorkSpaceM.Zero();
    mWorkSpaceN.Zero();
    mWorkSpaceO.Zero();
    mWorkSpaceP.Zero();

    cFarmSalt.Zero();
    
    cStarter.Zero();
    
    cAchernar.Zero();
    cAlcor.Zero();
    cAldebaran.Zero();
    cAlioth.Zero();
    cAlkaid.Zero();
    cAlnitak.Zero();
    cAltair.Zero();
    cAnkaa.Zero();
    cAntares.Zero();
    cArcturus.Zero();
    cAthebyne.Zero();
    cBellatrix.Zero();
    cBetelgeuse.Zero();
    cCanopus.Zero();
    cCapella.Zero();
    cCastor.Zero();
    cMebsuta.Zero();
    cMenkent.Zero();
    cMimosa.Zero();
    cMiram.Zero();
    cMirfak.Zero();
    cMothallah.Zero();
    cNaos.Zero();
    cPolaris.Zero();
    cPollux.Zero();
    cProcyon.Zero();
    cRegulus.Zero();
    cRigel.Zero();
    cSaiph.Zero();
    cSirius.Zero();
    cSuhail.Zero();
    cVega.Zero();

    std::memset(mMasks, 0, sizeof(mMasks));
    for (std::size_t aIndex=0U; aIndex<256U; aIndex++) {
        mCiphers[aIndex] = CipherType::kNone;
    }

    for (std::size_t aIndex=0U; aIndex<32U; aIndex++) {
        mExpanders[aIndex] = nullptr;
        mClaimed[aIndex] = false;
        mShuffleExpanders[aIndex] = nullptr;
    }

    for (std::size_t aIndex=0U; aIndex<16U; aIndex++) {
        mMaterials[aIndex] = nullptr;
        mWorkSpaces[aIndex] = nullptr;
        mSources[aIndex] = nullptr;

        mClaimedExpanders[aIndex] = nullptr;
        mClaimedMaterials[aIndex] = nullptr;
        mClaimedWorkSpaces[aIndex] = nullptr;

        mShuffleMaterials[aIndex] = nullptr;
        mShuffleWorkSpaces[aIndex] = nullptr;
    }

    for (std::size_t aCrossIndex=0U; aCrossIndex<4U; aCrossIndex++) {
        for (std::size_t aLaneIndex=0U; aLaneIndex<16U; aLaneIndex++) {
            mCross[aCrossIndex][aLaneIndex] = nullptr;
        }
    }

    mClaimedExpanderCount = 0U;
    mClaimedMaterialCount = 0U;
    mClaimedWorkSpaceCount = 0U;

    mCryptex.Free();
    
}


void Soccer2::Shuffle_CROWSCIMASSORMATEX() {
    constexpr std::size_t cSpan = 1024U;
    static_assert(S_BLOCK == (32U * cSpan));
    
    // Cross 0: entropy slices 5 and 25.
    if (mStrength == EncryptionStrength::kWeak) {
        TwistShuffle::ShuffleList4(mCross[0], mRandom,  5U * cSpan,  6U * cSpan, 1U);
        TwistShuffle::ShuffleList4(mCross[0], mRandom, 25U * cSpan, 26U * cSpan, 1U);
    } else if (mStrength == EncryptionStrength::kStrong) {
        TwistShuffle::ShuffleList16(mCross[0], mRandom,  5U * cSpan,  6U * cSpan, 1U);
        TwistShuffle::ShuffleList16(mCross[0], mRandom, 25U * cSpan, 26U * cSpan, 1U);
    } else {
        TwistShuffle::ShuffleList8(mCross[0], mRandom,  5U * cSpan,  6U * cSpan, 1U);
        TwistShuffle::ShuffleList8(mCross[0], mRandom, 25U * cSpan, 26U * cSpan, 1U);
    }

    // Cross 1: entropy slices 7 and 27.
    if (mStrength == EncryptionStrength::kWeak) {
        TwistShuffle::ShuffleList4(mCross[1], mRandom,  7U * cSpan,  8U * cSpan, 1U);
        TwistShuffle::ShuffleList4(mCross[1], mRandom, 27U * cSpan, 28U * cSpan, 1U);
    } else if (mStrength == EncryptionStrength::kStrong) {
        TwistShuffle::ShuffleList16(mCross[1], mRandom,  7U * cSpan,  8U * cSpan, 1U);
        TwistShuffle::ShuffleList16(mCross[1], mRandom, 27U * cSpan, 28U * cSpan, 1U);
    } else {
        TwistShuffle::ShuffleList8(mCross[1], mRandom,  7U * cSpan,  8U * cSpan, 1U);
        TwistShuffle::ShuffleList8(mCross[1], mRandom, 27U * cSpan, 28U * cSpan, 1U);
    }

    // Cross 2: entropy slices 9 and 29.
    if (mStrength == EncryptionStrength::kWeak) {
        TwistShuffle::ShuffleList4(mCross[2], mRandom,  9U * cSpan, 10U * cSpan, 1U);
        TwistShuffle::ShuffleList4(mCross[2], mRandom, 29U * cSpan, 30U * cSpan, 1U);
    } else if (mStrength == EncryptionStrength::kStrong) {
        TwistShuffle::ShuffleList16(mCross[2], mRandom,  9U * cSpan, 10U * cSpan, 1U);
        TwistShuffle::ShuffleList16(mCross[2], mRandom, 29U * cSpan, 30U * cSpan, 1U);
    } else {
        TwistShuffle::ShuffleList8(mCross[2], mRandom,  9U * cSpan, 10U * cSpan, 1U);
        TwistShuffle::ShuffleList8(mCross[2], mRandom, 29U * cSpan, 30U * cSpan, 1U);
    }

    // Cross 3: entropy slices 11 and 31.
    if (mStrength == EncryptionStrength::kWeak) {
        TwistShuffle::ShuffleList4(mCross[3], mRandom, 11U * cSpan, 12U * cSpan, 1U);
        TwistShuffle::ShuffleList4(mCross[3], mRandom, 31U * cSpan, 32U * cSpan, 1U);
    } else if (mStrength == EncryptionStrength::kStrong) {
        TwistShuffle::ShuffleList16(mCross[3], mRandom, 11U * cSpan, 12U * cSpan, 1U);
        TwistShuffle::ShuffleList16(mCross[3], mRandom, 31U * cSpan, 32U * cSpan, 1U);
    } else {
        TwistShuffle::ShuffleList8(mCross[3], mRandom, 11U * cSpan, 12U * cSpan, 1U);
        TwistShuffle::ShuffleList8(mCross[3], mRandom, 31U * cSpan, 32U * cSpan, 1U);
    }

    // Masks: entropy slices 0, 12, and 20.
    TwistShuffle::ShuffleList32(mMasks, mRandom,  0U * cSpan,  1U * cSpan, 1U);
    TwistShuffle::ShuffleList32(mMasks, mRandom, 12U * cSpan, 13U * cSpan, 1U);
    TwistShuffle::ShuffleList32(mMasks, mRandom, 20U * cSpan, 21U * cSpan, 1U);

    // Materials: entropy slices 4, 16, and 24.
    if (mStrength == EncryptionStrength::kWeak) {
        TwistShuffle::ShuffleList4(mMaterials, mRandom,  4U * cSpan,  5U * cSpan, 1U);
        TwistShuffle::ShuffleList4(mMaterials, mRandom, 16U * cSpan, 17U * cSpan, 1U);
        TwistShuffle::ShuffleList4(mMaterials, mRandom, 24U * cSpan, 25U * cSpan, 1U);
    } else if (mStrength == EncryptionStrength::kStrong) {
        TwistShuffle::ShuffleList16(mMaterials, mRandom,  4U * cSpan,  5U * cSpan, 1U);
        TwistShuffle::ShuffleList16(mMaterials, mRandom, 16U * cSpan, 17U * cSpan, 1U);
        TwistShuffle::ShuffleList16(mMaterials, mRandom, 24U * cSpan, 25U * cSpan, 1U);
    } else {
        TwistShuffle::ShuffleList8(mMaterials, mRandom,  4U * cSpan,  5U * cSpan, 1U);
        TwistShuffle::ShuffleList8(mMaterials, mRandom, 16U * cSpan, 17U * cSpan, 1U);
        TwistShuffle::ShuffleList8(mMaterials, mRandom, 24U * cSpan, 25U * cSpan, 1U);
    }

    // Expanders: entropy slices 8, 18, and 28.
    TwistShuffle::ShuffleList32(mExpanders, mRandom,  8U * cSpan,  9U * cSpan, 1U);
    TwistShuffle::ShuffleList32(mExpanders, mRandom, 18U * cSpan, 19U * cSpan, 1U);
    TwistShuffle::ShuffleList32(mExpanders, mRandom, 28U * cSpan, 29U * cSpan, 1U);

    // Work spaces: entropy slices 6, 17, and 26.
    if (mStrength == EncryptionStrength::kWeak) {
        TwistShuffle::ShuffleList4(mWorkSpaces, mRandom,  6U * cSpan,  7U * cSpan, 1U);
        TwistShuffle::ShuffleList4(mWorkSpaces, mRandom, 17U * cSpan, 18U * cSpan, 1U);
        TwistShuffle::ShuffleList4(mWorkSpaces, mRandom, 26U * cSpan, 27U * cSpan, 1U);
    } else if (mStrength == EncryptionStrength::kStrong) {
        TwistShuffle::ShuffleList16(mWorkSpaces, mRandom,  6U * cSpan,  7U * cSpan, 1U);
        TwistShuffle::ShuffleList16(mWorkSpaces, mRandom, 17U * cSpan, 18U * cSpan, 1U);
        TwistShuffle::ShuffleList16(mWorkSpaces, mRandom, 26U * cSpan, 27U * cSpan, 1U);
    } else {
        TwistShuffle::ShuffleList8(mWorkSpaces, mRandom,  6U * cSpan,  7U * cSpan, 1U);
        TwistShuffle::ShuffleList8(mWorkSpaces, mRandom, 17U * cSpan, 18U * cSpan, 1U);
        TwistShuffle::ShuffleList8(mWorkSpaces, mRandom, 26U * cSpan, 27U * cSpan, 1U);
    }

    // Ciphers: entropy slices 1-3, 13-15, and 21-23.
    TwistShuffle::ShuffleList256(mCiphers, mRandom,  1U * cSpan,  4U * cSpan, 2U);
    TwistShuffle::ShuffleList256(mCiphers, mRandom, 13U * cSpan, 16U * cSpan, 2U);
    TwistShuffle::ShuffleList256(mCiphers, mRandom, 21U * cSpan, 24U * cSpan, 2U);

    // Sources: entropy slices 10, 19, and 30.
    if (mStrength == EncryptionStrength::kWeak) {
        TwistShuffle::ShuffleList4(mSources, mRandom, 10U * cSpan, 11U * cSpan, 1U);
        TwistShuffle::ShuffleList4(mSources, mRandom, 19U * cSpan, 20U * cSpan, 1U);
        TwistShuffle::ShuffleList4(mSources, mRandom, 30U * cSpan, 31U * cSpan, 1U);
    } else if (mStrength == EncryptionStrength::kStrong) {
        TwistShuffle::ShuffleList16(mSources, mRandom, 10U * cSpan, 11U * cSpan, 1U);
        TwistShuffle::ShuffleList16(mSources, mRandom, 19U * cSpan, 20U * cSpan, 1U);
        TwistShuffle::ShuffleList16(mSources, mRandom, 30U * cSpan, 31U * cSpan, 1U);
    } else {
        TwistShuffle::ShuffleList8(mSources, mRandom, 10U * cSpan, 11U * cSpan, 1U);
        TwistShuffle::ShuffleList8(mSources, mRandom, 19U * cSpan, 20U * cSpan, 1U);
        TwistShuffle::ShuffleList8(mSources, mRandom, 30U * cSpan, 31U * cSpan, 1U);
    }
}

void Soccer2::TwistRound(std::size_t pBlockIndex) {
    if (pBlockIndex >= BLOCK_COUNT) {
        return;
    }

    std::size_t aComplexity = 0U;
    std::size_t aReverseCount = 0U;
    if (mStrength == EncryptionStrength::kWeak) {
        aComplexity = COMPLEXITY_WEAK;
        aReverseCount = 1U;
    } else if (mStrength == EncryptionStrength::kStrong) {
        aComplexity = COMPLEXITY_STRONG;
        aReverseCount = 4U;
    } else {
        aComplexity = COMPLEXITY_NORMAL;
        aReverseCount = 2U;
    }

    const std::size_t aDestinationByteIndex = pBlockIndex * S_BLOCK;

    for (std::size_t aLaneIndex=0U; aLaneIndex<aComplexity; aLaneIndex++) {
        mExpanders[aLaneIndex]->TwistBlock(mWorkSpaces[aLaneIndex],
                                            mSources[aLaneIndex],
                                            mCross[0][aLaneIndex],
                                            mCross[1][aLaneIndex],
                                            mCross[2][aLaneIndex],
                                            mCross[3][aLaneIndex],
                                            &mMaterials[aLaneIndex][aDestinationByteIndex]);
    }

    RotateSourcesIntoCross();

    for (std::size_t aLaneIndex=0U; aLaneIndex<aComplexity; aLaneIndex++) {
        mSources[aLaneIndex] = &mMaterials[aLaneIndex][aDestinationByteIndex];
    }

    if (mStrength == EncryptionStrength::kWeak) {
        FoldMaterialsIntoRandomForBlock_4(pBlockIndex);
    } else if (mStrength == EncryptionStrength::kStrong) {
        FoldMaterialsIntoRandomForBlock_16(pBlockIndex);
    } else {
        FoldMaterialsIntoRandomForBlock_8(pBlockIndex);
    }

    for (std::size_t aMaterialIndex=0U; aMaterialIndex<aReverseCount; aMaterialIndex++) {
        std::reverse(mMaterials[aMaterialIndex] + aDestinationByteIndex,
                     mMaterials[aMaterialIndex] + aDestinationByteIndex + S_BLOCK);
    }

    Shuffle_CROWSCIMASSORMATEX();
}

void Soccer2::SeedPrologue_Regular_A(std::uint8_t *pPassword,
                                     std::size_t pPasswordByteLength,
                                     std::uint64_t pNonce) {
    
    std::size_t aPower = 0U;
    if (mStrength == EncryptionStrength::kWeak) {
        aPower = 1U;
    } else if (mStrength == EncryptionStrength::kStrong) {
        aPower = 4U;
    } else {
        aPower = 2U;
    }
    
    const std::size_t aWarmUpStartIndex = (BLOCK_COUNT - WARM_UP_BLOCKS) * S_BLOCK;

    for (std::size_t aSpanIndex=0U; aSpanIndex<4U; aSpanIndex++) {
        for (std::size_t aPowerIndex=0U; aPowerIndex<aPower; aPowerIndex++) {
            const std::size_t aClaimedIndex = mClaimedMaterialCount;

            mClaimedExpanders[aClaimedIndex] = mExpanders[aPowerIndex];
            mClaimedExpanderCount++;

            mClaimedMaterials[aClaimedIndex] = mMaterials[aPowerIndex];
            mClaimedMaterialCount++;

            mClaimedWorkSpaces[aClaimedIndex] = mWorkSpaces[aPowerIndex];
            mClaimedWorkSpaceCount++;

            mClaimedExpanders[aClaimedIndex]->Seed(mClaimedWorkSpaces[aClaimedIndex],
                                                   &cFarmSalt,
                                                   pNonce,
                                                   pPassword,
                                                   pPasswordByteLength,
                                                   &mClaimedMaterials[aClaimedIndex][aWarmUpStartIndex]);
        }

        if (aSpanIndex < 3U) {
            ShuffleMEWBlockZero(&mClaimedMaterials[mClaimedMaterialCount - 1U][aWarmUpStartIndex]);
        }
    }
}

void Soccer2::SeedPrologue_Regular_B() {
    for (std::size_t aIndex=0U; aIndex<mClaimedMaterialCount; aIndex++) {
        mMaterials[aIndex] = mClaimedMaterials[aIndex];
    }

    std::size_t aMaterialWriteIndex = mClaimedMaterialCount;
    for (std::size_t aShuffledIndex=0U; aShuffledIndex<16U; aShuffledIndex++) {
        bool aIsClaimed = false;
        for (std::size_t aClaimedIndex=0U; aClaimedIndex<mClaimedMaterialCount; aClaimedIndex++) {
            if (mShuffleMaterials[aShuffledIndex] == mClaimedMaterials[aClaimedIndex]) {
                aIsClaimed = true;
                break;
            }
        }
        if (!aIsClaimed) {
            mMaterials[aMaterialWriteIndex] = mShuffleMaterials[aShuffledIndex];
            aMaterialWriteIndex++;
        }
    }

    for (std::size_t aIndex=0U; aIndex<mClaimedExpanderCount; aIndex++) {
        mExpanders[aIndex] = mClaimedExpanders[aIndex];
    }

    std::size_t aExpanderWriteIndex = mClaimedExpanderCount;
    for (std::size_t aShuffledIndex=0U; aShuffledIndex<32U; aShuffledIndex++) {
        bool aIsClaimed = false;
        for (std::size_t aClaimedIndex=0U; aClaimedIndex<mClaimedExpanderCount; aClaimedIndex++) {
            if (mShuffleExpanders[aShuffledIndex] == mClaimedExpanders[aClaimedIndex]) {
                aIsClaimed = true;
                break;
            }
        }
        if (!aIsClaimed) {
            mExpanders[aExpanderWriteIndex] = mShuffleExpanders[aShuffledIndex];
            aExpanderWriteIndex++;
        }
    }

    for (std::size_t aIndex=0U; aIndex<mClaimedWorkSpaceCount; aIndex++) {
        mWorkSpaces[aIndex] = mClaimedWorkSpaces[aIndex];
    }

    std::size_t aWorkSpaceWriteIndex = mClaimedWorkSpaceCount;
    for (std::size_t aShuffledIndex=0U; aShuffledIndex<16U; aShuffledIndex++) {
        bool aIsClaimed = false;
        for (std::size_t aClaimedIndex=0U; aClaimedIndex<mClaimedWorkSpaceCount; aClaimedIndex++) {
            if (mShuffleWorkSpaces[aShuffledIndex] == mClaimedWorkSpaces[aClaimedIndex]) {
                aIsClaimed = true;
                break;
            }
        }
        if (!aIsClaimed) {
            mWorkSpaces[aWorkSpaceWriteIndex] = mShuffleWorkSpaces[aShuffledIndex];
            aWorkSpaceWriteIndex++;
        }
    }

    const std::size_t aFirstWarmUpBlockIndex = BLOCK_COUNT - WARM_UP_BLOCKS;
    const std::size_t aFirstWarmUpByteIndex = aFirstWarmUpBlockIndex * S_BLOCK;
    if (mStrength == EncryptionStrength::kWeak) {
        FoldMaterialsIntoRandomForBlock_4(aFirstWarmUpBlockIndex);
        
        for (std::size_t aIndex=0U; aIndex<COMPLEXITY_WEAK; aIndex++) {
            mSources[aIndex] = &mMaterials[aIndex][aFirstWarmUpByteIndex];
            mCross[0][aIndex] = &mMaterials[aIndex][aFirstWarmUpByteIndex];
            mCross[1][aIndex] = &mMaterials[aIndex][aFirstWarmUpByteIndex];
            mCross[2][aIndex] = &mMaterials[aIndex][aFirstWarmUpByteIndex];
            mCross[3][aIndex] = &mMaterials[aIndex][aFirstWarmUpByteIndex];
        }

        mCross[0][0] = mScratch; mCross[0][1] = mScratch;
        mCross[1][1] = mScratch; mCross[1][2] = mScratch;
        mCross[2][2] = mScratch; mCross[2][3] = mScratch;
        mCross[3][3] = mScratch; mCross[3][0] = mScratch;
        
    } else if (mStrength == EncryptionStrength::kStrong) {
        FoldMaterialsIntoRandomForBlock_16(aFirstWarmUpBlockIndex);
        
        for (std::size_t aIndex=0U; aIndex<COMPLEXITY_STRONG; aIndex++) {
            mSources[aIndex] = &mMaterials[aIndex][aFirstWarmUpByteIndex];
            mCross[0][aIndex] = &mMaterials[aIndex][aFirstWarmUpByteIndex];
            mCross[1][aIndex] = &mMaterials[aIndex][aFirstWarmUpByteIndex];
            mCross[2][aIndex] = &mMaterials[aIndex][aFirstWarmUpByteIndex];
            mCross[3][aIndex] = &mMaterials[aIndex][aFirstWarmUpByteIndex];
        }

        mCross[0][0] = mScratch; mCross[0][15] = mScratch;
        mCross[1][1] = mScratch; mCross[1][14] = mScratch;
        mCross[2][2] = mScratch; mCross[2][13] = mScratch;
        mCross[3][3] = mScratch; mCross[3][12] = mScratch;
    } else {
        FoldMaterialsIntoRandomForBlock_8(aFirstWarmUpBlockIndex);
        
        for (std::size_t aIndex=0U; aIndex<COMPLEXITY_NORMAL; aIndex++) {
            mSources[aIndex] = &mMaterials[aIndex][aFirstWarmUpByteIndex];
            mCross[0][aIndex] = &mMaterials[aIndex][aFirstWarmUpByteIndex];
            mCross[1][aIndex] = &mMaterials[aIndex][aFirstWarmUpByteIndex];
            mCross[2][aIndex] = &mMaterials[aIndex][aFirstWarmUpByteIndex];
            mCross[3][aIndex] = &mMaterials[aIndex][aFirstWarmUpByteIndex];
        }

        mCross[0][0] = mScratch; mCross[0][4] = mScratch;
        mCross[1][1] = mScratch; mCross[1][5] = mScratch;
        mCross[2][2] = mScratch; mCross[2][6] = mScratch;
        mCross[3][3] = mScratch; mCross[3][7] = mScratch;
    }
}

bool Soccer2::SeedPrologue_Regular_C(std::uint32_t *pAckWord,
                             bool pForwardDeploy) {
    
    Shuffle_CROWSCIMASSORMATEX();

    for (std::size_t aWarmUpRound=1U; aWarmUpRound<WARM_UP_BLOCKS; aWarmUpRound++) {
        TwistRound((BLOCK_COUNT - WARM_UP_BLOCKS) + aWarmUpRound);
    }

    const std::size_t aAckByteIndex = SOCCER_BLOCK_SIZE - 1U;
    std::uint32_t aGeneratedAckWord = 0U;
    if (mStrength == EncryptionStrength::kWeak) {
        aGeneratedAckWord |= static_cast<std::uint32_t>(mMaterials[0][aAckByteIndex]) <<  0U;
        aGeneratedAckWord |= static_cast<std::uint32_t>(mMaterials[1][aAckByteIndex]) <<  8U;
        aGeneratedAckWord |= static_cast<std::uint32_t>(mMaterials[2][aAckByteIndex]) << 16U;
        aGeneratedAckWord |= static_cast<std::uint32_t>(mMaterials[3][aAckByteIndex]) << 24U;
    } else if (mStrength == EncryptionStrength::kStrong) {
        aGeneratedAckWord |= static_cast<std::uint32_t>(mMaterials[ 3][aAckByteIndex]) <<  0U;
        aGeneratedAckWord |= static_cast<std::uint32_t>(mMaterials[ 7][aAckByteIndex]) <<  8U;
        aGeneratedAckWord |= static_cast<std::uint32_t>(mMaterials[11][aAckByteIndex]) << 16U;
        aGeneratedAckWord |= static_cast<std::uint32_t>(mMaterials[15][aAckByteIndex]) << 24U;
    } else {
        aGeneratedAckWord |= static_cast<std::uint32_t>(mMaterials[1][aAckByteIndex]) <<  0U;
        aGeneratedAckWord |= static_cast<std::uint32_t>(mMaterials[3][aAckByteIndex]) <<  8U;
        aGeneratedAckWord |= static_cast<std::uint32_t>(mMaterials[5][aAckByteIndex]) << 16U;
        aGeneratedAckWord |= static_cast<std::uint32_t>(mMaterials[7][aAckByteIndex]) << 24U;
    }

    if (pForwardDeploy) {
        *pAckWord = aGeneratedAckWord;
        return true;
    }

    return aGeneratedAckWord == *pAckWord;
}

void Soccer2::SeedPrologue_Regular_D() {
    for (std::size_t aRoundIndex=0U; aRoundIndex<BLOCK_COUNT; aRoundIndex++) {
        TwistRound(aRoundIndex);
        printf("SeedPrologue_Regular_D: completed round %zu.\n", aRoundIndex + 1U);
    }
    
    mWorkSpaceN.Zero();
    mWorkSpaceO.Zero();
    mWorkSpaceP.Zero();
    mWorkSpaceD.Zero();
    mWorkSpaceE.Zero();
    mWorkSpaceF.Zero();
    mWorkSpaceJ.Zero();
    mWorkSpaceI.Zero();
    mWorkSpaceH.Zero();
    mWorkSpaceG.Zero();
    mWorkSpaceB.Zero();
    mWorkSpaceK.Zero();
    mWorkSpaceC.Zero();
    mWorkSpaceM.Zero();
    mWorkSpaceA.Zero();
    mWorkSpaceL.Zero();

    for (std::size_t aIndex=0U; aIndex<32U; aIndex++) {
        mExpanders[aIndex] = nullptr;
        mClaimed[aIndex] = false;
        mShuffleExpanders[aIndex] = nullptr;
    }

    for (std::size_t aIndex=0U; aIndex<16U; aIndex++) {
        mWorkSpaces[aIndex] = nullptr;
        mSources[aIndex] = nullptr;

        mClaimedExpanders[aIndex] = nullptr;
        mClaimedMaterials[aIndex] = nullptr;
        mClaimedWorkSpaces[aIndex] = nullptr;

        mShuffleMaterials[aIndex] = nullptr;
        mShuffleWorkSpaces[aIndex] = nullptr;
    }

    for (std::size_t aCrossIndex=0U; aCrossIndex<4U; aCrossIndex++) {
        for (std::size_t aLaneIndex=0U; aLaneIndex<16U; aLaneIndex++) {
            mCross[aCrossIndex][aLaneIndex] = nullptr;
        }
    }

    mClaimedExpanderCount = 0U;
    mClaimedMaterialCount = 0U;
    mClaimedWorkSpaceCount = 0U;
}

void Soccer2::FoldMaterialsIntoRandomForBlock_4(std::size_t pBlockIndex) {
    const std::size_t aStartIndex = pBlockIndex * S_BLOCK;
    for (std::size_t aByteIndex=0U; aByteIndex<S_BLOCK; aByteIndex++) {
        const std::size_t aMaterialIndex = aStartIndex + aByteIndex;
        const std::uint32_t aRandomIngress =
            (static_cast<std::uint32_t>(mMaterials[0][aMaterialIndex]) <<  0U) |
            (static_cast<std::uint32_t>(mMaterials[1][aMaterialIndex]) <<  8U) |
            (static_cast<std::uint32_t>(mMaterials[2][aMaterialIndex]) << 16U) |
            (static_cast<std::uint32_t>(mMaterials[3][aMaterialIndex]) << 24U);

        mRandom[aByteIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aRandomIngress));
    }
}

void Soccer2::FoldMaterialsIntoRandomForBlock_8(std::size_t pBlockIndex) {
    const std::size_t aStartIndex = pBlockIndex * S_BLOCK;
    for (std::size_t aByteIndex=0U; aByteIndex<S_BLOCK; aByteIndex++) {
        const std::size_t aMaterialIndex = aStartIndex + aByteIndex;
        const std::uint64_t aRandomIngress =
            (static_cast<std::uint64_t>(mMaterials[0][aMaterialIndex]) <<  0U) |
            (static_cast<std::uint64_t>(mMaterials[1][aMaterialIndex]) <<  8U) |
            (static_cast<std::uint64_t>(mMaterials[2][aMaterialIndex]) << 16U) |
            (static_cast<std::uint64_t>(mMaterials[3][aMaterialIndex]) << 24U) |
            (static_cast<std::uint64_t>(mMaterials[4][aMaterialIndex]) << 32U) |
            (static_cast<std::uint64_t>(mMaterials[5][aMaterialIndex]) << 40U) |
            (static_cast<std::uint64_t>(mMaterials[6][aMaterialIndex]) << 48U) |
            (static_cast<std::uint64_t>(mMaterials[7][aMaterialIndex]) << 56U);

        mRandom[aByteIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aRandomIngress));
    }
}

void Soccer2::FoldMaterialsIntoRandomForBlock_16(std::size_t pBlockIndex) {
    const std::size_t aStartIndex = pBlockIndex * S_BLOCK;
    for (std::size_t aByteIndex=0U; aByteIndex<S_BLOCK; aByteIndex++) {
        const std::size_t aMaterialIndex = aStartIndex + aByteIndex;

        const std::uint32_t aCrushIngressA =
            (static_cast<std::uint32_t>(mMaterials[ 0][aMaterialIndex]) <<  0U) |
            (static_cast<std::uint32_t>(mMaterials[ 1][aMaterialIndex]) <<  8U) |
            (static_cast<std::uint32_t>(mMaterials[ 2][aMaterialIndex]) << 16U) |
            (static_cast<std::uint32_t>(mMaterials[ 3][aMaterialIndex]) << 24U);
        mCrushA[aByteIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aCrushIngressA));

        const std::uint32_t aCrushIngressB =
            (static_cast<std::uint32_t>(mMaterials[ 4][aMaterialIndex]) <<  0U) |
            (static_cast<std::uint32_t>(mMaterials[ 5][aMaterialIndex]) <<  8U) |
            (static_cast<std::uint32_t>(mMaterials[ 6][aMaterialIndex]) << 16U) |
            (static_cast<std::uint32_t>(mMaterials[ 7][aMaterialIndex]) << 24U);
        mCrushB[aByteIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aCrushIngressB));

        const std::uint32_t aCrushIngressC =
            (static_cast<std::uint32_t>(mMaterials[ 8][aMaterialIndex]) <<  0U) |
            (static_cast<std::uint32_t>(mMaterials[ 9][aMaterialIndex]) <<  8U) |
            (static_cast<std::uint32_t>(mMaterials[10][aMaterialIndex]) << 16U) |
            (static_cast<std::uint32_t>(mMaterials[11][aMaterialIndex]) << 24U);
        mCrushC[aByteIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aCrushIngressC));

        const std::uint32_t aCrushIngressD =
            (static_cast<std::uint32_t>(mMaterials[12][aMaterialIndex]) <<  0U) |
            (static_cast<std::uint32_t>(mMaterials[13][aMaterialIndex]) <<  8U) |
            (static_cast<std::uint32_t>(mMaterials[14][aMaterialIndex]) << 16U) |
            (static_cast<std::uint32_t>(mMaterials[15][aMaterialIndex]) << 24U);
        mCrushD[aByteIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aCrushIngressD));
    }

    for (std::size_t aByteIndex=0U; aByteIndex<S_BLOCK; aByteIndex++) {
        const std::uint32_t aRandomIngress =
            (static_cast<std::uint32_t>(mCrushA[aByteIndex]) <<  0U) |
            (static_cast<std::uint32_t>(mCrushB[aByteIndex]) <<  8U) |
            (static_cast<std::uint32_t>(mCrushC[aByteIndex]) << 16U) |
            (static_cast<std::uint32_t>(mCrushD[aByteIndex]) << 24U);

        mRandom[aByteIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aRandomIngress));
    }
}

bool Soccer2::AttemptSeed_Encrypt(EncryptionStrength pStrength,
                                  std::uint8_t *pPassword,
                                  std::size_t pPasswordByteLength,
                                  std::uint64_t pNonce,
                                  std::uint32_t *pAckWord) {
    
    if ((pPassword == nullptr) || (pPasswordByteLength == 0U) || (pAckWord == nullptr)) {
        return false;
    }

    std::uint32_t aAckWord = 0U;
    mStrength = pStrength;
    mCryptex.Free();
    
    if (pStrength == EncryptionStrength::kTest) {
        if (!SeedPrelude_Test(pPassword, pPasswordByteLength, pNonce)) {
            return false;
        }
        aAckWord |= static_cast<std::uint32_t>(mMaterialA[S_BLOCK * 1]) <<  0U;
        aAckWord |= static_cast<std::uint32_t>(mMaterialA[S_BLOCK * 2]) <<  8U;
        aAckWord |= static_cast<std::uint32_t>(mMaterialA[S_BLOCK * 3]) << 16U;
        aAckWord |= static_cast<std::uint32_t>(mMaterialA[S_BLOCK * 4]) << 24U;
        *pAckWord = aAckWord;
        return true;
    }
    
    SeedPrelude_Regular_A(pPassword, pPasswordByteLength, pNonce);
    SeedPrelude_Regular_B(pNonce);
    SeedPrelude_Regular_C();
    
    SeedPrologue_Regular_A(pPassword, pPasswordByteLength, pNonce);
    SeedPrologue_Regular_B();
    if (!SeedPrologue_Regular_C(pAckWord, true)) {
        return false;
    }
    SeedPrologue_Regular_D();
    SeedEpilogue_Regular_A();
    
    return true;
}

bool Soccer2::AttemptSeed_Decrypt(EncryptionStrength pStrength,
                                  std::uint8_t *pPassword,
                                  std::size_t pPasswordByteLength,
                                  std::uint64_t pNonce,
                                  std::uint32_t pAckWord) {
    
    if ((pPassword == nullptr) || (pPasswordByteLength == 0U)) {
        return false;
    }

    mStrength = pStrength;
    mCryptex.Free();
    
    if (pStrength == EncryptionStrength::kTest) {
        if (!SeedPrelude_Test(pPassword, pPasswordByteLength, pNonce)) {
            return false;
        }
        if (mMaterialA[S_BLOCK * 1] != static_cast<std::uint8_t>(((pAckWord >>  0) & 0xFFU))) { return false; }
        if (mMaterialA[S_BLOCK * 2] != static_cast<std::uint8_t>(((pAckWord >>  8) & 0xFFU))) { return false; }
        if (mMaterialA[S_BLOCK * 3] != static_cast<std::uint8_t>(((pAckWord >> 16) & 0xFFU))) { return false; }
        if (mMaterialA[S_BLOCK * 4] != static_cast<std::uint8_t>(((pAckWord >> 24) & 0xFFU))) { return false; }
        return true;
    }
    
    SeedPrelude_Regular_A(pPassword, pPasswordByteLength, pNonce);
    SeedPrelude_Regular_B(pNonce);
    SeedPrelude_Regular_C();
    
    std::uint32_t aAckWord = pAckWord;
    SeedPrologue_Regular_A(pPassword, pPasswordByteLength, pNonce);
    SeedPrologue_Regular_B();
    if (!SeedPrologue_Regular_C(&aAckWord, false)) {
        return false;
    }
    SeedPrologue_Regular_D();
    SeedEpilogue_Regular_A();
    
    return true;
}

void Soccer2::ConfigureTestBuffers(std::uint32_t pTestBlockLength) {
    mTestBlockLength = pTestBlockLength;
}


void Soccer2::EncryptBlock(std::uint8_t *pSource,
                           std::uint8_t *pDestination) {
    if ((pSource == nullptr) || (pDestination == nullptr)) {
        return;
    }

    if (mStrength == EncryptionStrength::kTest) {
        for (std::size_t aIndex=0; aIndex<mTestBlockLength; aIndex++) {
            pDestination[aIndex] = pSource[aIndex] ^ mMaterialA[aIndex];
        }
        return;
    }

    CipherErrorCode aErrorCode = CipherErrorCode::kNone;
    if (!mCryptex.SealData(pSource,
                           mScratch,
                           mCryptTemp,
                           pDestination,
                           SOCCER_BLOCK_SIZE,
                           &aErrorCode)) {
        printf("Soccer2::EncryptBlock failed with cipher error %u.\n",
               static_cast<std::uint32_t>(aErrorCode));
    }
}

void Soccer2::DecryptBlock(std::uint8_t *pSource,
                           std::uint8_t *pDestination) {
    if ((pSource == nullptr) || (pDestination == nullptr)) {
        return;
    }

    if (mStrength == EncryptionStrength::kTest) {
        for (std::size_t aIndex=0; aIndex<mTestBlockLength; aIndex++) {
            pDestination[aIndex] = pSource[aIndex] ^ mMaterialA[aIndex];
        }
        return;
    }

    CipherErrorCode aErrorCode = CipherErrorCode::kNone;
    if (!mCryptex.UnsealData(pSource,
                             mScratch,
                             mCryptTemp,
                             pDestination,
                             SOCCER_BLOCK_SIZE,
                             &aErrorCode)) {
        printf("Soccer2::DecryptBlock failed with cipher error %u.\n",
               static_cast<std::uint32_t>(aErrorCode));
    }
}

void Soccer2::InitializeMasks() {
    mMasks[0] = 0xF0u;  mMasks[1] = 0x0Fu;  mMasks[2] = 0x33u;  mMasks[3] = 0xCCu;
    mMasks[4] = 0x55u;  mMasks[5] = 0xAAu;  mMasks[6] = 0x69u;  mMasks[7] = 0x96u;
    mMasks[8] = 0x19u;  mMasks[9] = 0x98u;  mMasks[10] = 0x1Au; mMasks[11] = 0x58u;
    mMasks[12] = 0x1Cu; mMasks[13] = 0x38u; mMasks[14] = 0x25u; mMasks[15] = 0xA4u;
    mMasks[16] = 0x26u; mMasks[17] = 0x64u; mMasks[18] = 0x2Cu; mMasks[19] = 0x34u;
    mMasks[20] = 0x43u; mMasks[21] = 0xC2u; mMasks[22] = 0x46u; mMasks[23] = 0x62u;
    mMasks[24] = 0x4Au; mMasks[25] = 0x52u; mMasks[26] = 0x83u; mMasks[27] = 0xC1u;
    mMasks[28] = 0x85u; mMasks[29] = 0xA1u; mMasks[30] = 0x89u; mMasks[31] = 0x91u;
}

void Soccer2::InitializeCiphers() {
    std::size_t aCipherIndex = 0U;

    for (std::size_t aIndex=0U; aIndex<8U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kPasswordXORCipher; }
    for (std::size_t aIndex=0U; aIndex<8U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kPasswordAddCipher; }
    for (std::size_t aIndex=0U; aIndex<8U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kPasswordSubtractCipher; }

    for (std::size_t aIndex=0U; aIndex<7U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kPasswordJumpXORCipher; }
    for (std::size_t aIndex=0U; aIndex<7U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kPasswordJumpAddCipher; }
    for (std::size_t aIndex=0U; aIndex<7U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kPasswordJumpSubtractCipher; }

    for (std::size_t aIndex=0U; aIndex<7U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kPepperNoiseXORCipher; }
    for (std::size_t aIndex=0U; aIndex<7U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kPepperJumpNoiseXORCipher; }
    for (std::size_t aIndex=0U; aIndex<7U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kPepperDualJumpNoiseXORCipher; }

    for (std::size_t aIndex=0U; aIndex<3U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kCascadeCipher; }
    for (std::size_t aIndex=0U; aIndex<3U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kCascadeJumpCipher; }

    for (std::size_t aIndex=0U; aIndex<20U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kReverseMaskCipher; }
    for (std::size_t aIndex=0U; aIndex<15U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kReverseMaskByteBlockCipher32; }
    for (std::size_t aIndex=0U; aIndex<15U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kReverseMaskByteBlockCipher64; }
    
    for (std::size_t aIndex=0U; aIndex<15U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kRippleMaskBlockCipher32; }
    for (std::size_t aIndex=0U; aIndex<15U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kRippleMaskBlockCipher64; }

    //for (std::size_t aIndex=0U; aIndex<20U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kWeaveMaskCipher; }
    //for (std::size_t aIndex=0U; aIndex<15U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kWeaveMaskBlockCipher32; }
    //for (std::size_t aIndex=0U; aIndex<15U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kWeaveMaskBlockCipher64; }

    for (std::size_t aIndex=0U; aIndex<15U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kSplintMaskBlockCipher32; }
    for (std::size_t aIndex=0U; aIndex<15U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kSplintMaskBlockCipher64; }
    
    for (std::size_t aIndex=0U; aIndex<10U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kInvertMaskCipher; }
    for (std::size_t aIndex=0U; aIndex<20U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kRotateCipher; }
    
    // 50 kRotateMaskCipher entries fill the remaining slots.
    while (aCipherIndex < 256) {
        mCiphers[aCipherIndex] = CipherType::kRotateMaskCipher;
        aCipherIndex++;
    }
}

void Soccer2::InitializeExpanders() {
    mExpanders[0] = &cAchernar; mExpanders[1] = &cAlcor; mExpanders[2] = &cAldebaran; mExpanders[3] = &cAlioth;
    mExpanders[4] = &cAlkaid; mExpanders[5] = &cAlnitak; mExpanders[6] = &cAltair; mExpanders[7] = &cAnkaa;
    mExpanders[8] = &cAntares; mExpanders[9] = &cArcturus; mExpanders[10] = &cAthebyne; mExpanders[11] = &cBellatrix;
    mExpanders[12] = &cBetelgeuse; mExpanders[13] = &cCanopus; mExpanders[14] = &cCapella; mExpanders[15] = &cCastor;
    mExpanders[16] = &cMebsuta; mExpanders[17] = &cMenkent; mExpanders[18] = &cMimosa; mExpanders[19] = &cMiram;
    mExpanders[20] = &cMirfak; mExpanders[21] = &cMothallah; mExpanders[22] = &cNaos; mExpanders[23] = &cPolaris;
    mExpanders[24] = &cPollux; mExpanders[25] = &cProcyon; mExpanders[26] = &cRegulus; mExpanders[27] = &cRigel;
    mExpanders[28] = &cSaiph; mExpanders[29] = &cSirius; mExpanders[30] = &cSuhail; mExpanders[31] = &cVega;
}

void Soccer2::InitializeMaterials() {
    mMaterials[ 0] = mMaterialA; mMaterials[ 1] = mMaterialB; mMaterials[ 2] = mMaterialC; mMaterials[ 3] = mMaterialD;
    mMaterials[ 4] = mMaterialE; mMaterials[ 5] = mMaterialF; mMaterials[ 6] = mMaterialG; mMaterials[ 7] = mMaterialH;
    mMaterials[ 8] = mMaterialI; mMaterials[ 9] = mMaterialJ; mMaterials[10] = mMaterialK; mMaterials[11] = mMaterialL;
    mMaterials[12] = mMaterialM; mMaterials[13] = mMaterialN; mMaterials[14] = mMaterialO; mMaterials[15] = mMaterialP;
}

void Soccer2::InitializeWorkSpaces() {
    mWorkSpaces[ 0] = &mWorkSpaceA; mWorkSpaces[ 1] = &mWorkSpaceB; mWorkSpaces[ 2] = &mWorkSpaceC; mWorkSpaces[ 3] = &mWorkSpaceD;
    mWorkSpaces[ 4] = &mWorkSpaceE; mWorkSpaces[ 5] = &mWorkSpaceF; mWorkSpaces[ 6] = &mWorkSpaceG; mWorkSpaces[ 7] = &mWorkSpaceH;
    mWorkSpaces[ 8] = &mWorkSpaceI; mWorkSpaces[ 9] = &mWorkSpaceJ; mWorkSpaces[10] = &mWorkSpaceK; mWorkSpaces[11] = &mWorkSpaceL;
    mWorkSpaces[12] = &mWorkSpaceM; mWorkSpaces[13] = &mWorkSpaceN; mWorkSpaces[14] = &mWorkSpaceO; mWorkSpaces[15] = &mWorkSpaceP;
}

void Soccer2::UnrollNonceAndPasswordToScratch_Test(std::uint8_t *pPassword,
                                                   std::size_t pPasswordByteLength,
                                                   std::uint64_t pNonce) {
    std::uint8_t aNonceBytes[8];
    aNonceBytes[0] = static_cast<std::uint8_t>(pNonce >>  0); aNonceBytes[1] = static_cast<std::uint8_t>(pNonce >>  8);
    aNonceBytes[2] = static_cast<std::uint8_t>(pNonce >> 16); aNonceBytes[3] = static_cast<std::uint8_t>(pNonce >> 24);
    aNonceBytes[4] = static_cast<std::uint8_t>(pNonce >> 32); aNonceBytes[5] = static_cast<std::uint8_t>(pNonce >> 40);
    aNonceBytes[6] = static_cast<std::uint8_t>(pNonce >> 48); aNonceBytes[7] = static_cast<std::uint8_t>(pNonce >> 56);
    
    std::size_t aScratchIndex = 0;
    while (aScratchIndex < SOCCER_BLOCK_SIZE) {
        std::size_t aPasswordIndex = 0;
        while ((aPasswordIndex < pPasswordByteLength) && (aScratchIndex < SOCCER_BLOCK_SIZE)) {
            mScratch[aScratchIndex] = pPassword[aPasswordIndex];
            aScratchIndex++;
            aPasswordIndex++;
        }
        std::size_t aNonceIndex = 0;
        while ((aNonceIndex < 8) && (aScratchIndex < SOCCER_BLOCK_SIZE)) {
            mScratch[aScratchIndex] = aNonceBytes[aNonceIndex];
            aScratchIndex++;
            aNonceIndex++;
        }
    }
}

void Soccer2::UnrollNonceAndPasswordToScratch_Regular(std::uint8_t *pPassword,
                                                      std::size_t pPasswordByteLength,
                                                      std::uint64_t pNonce) {
    std::uint8_t aNonceBytes[8];
    aNonceBytes[0] = static_cast<std::uint8_t>(pNonce >>  0); aNonceBytes[1] = static_cast<std::uint8_t>(pNonce >>  8);
    aNonceBytes[2] = static_cast<std::uint8_t>(pNonce >> 16); aNonceBytes[3] = static_cast<std::uint8_t>(pNonce >> 24);
    aNonceBytes[4] = static_cast<std::uint8_t>(pNonce >> 32); aNonceBytes[5] = static_cast<std::uint8_t>(pNonce >> 40);
    aNonceBytes[6] = static_cast<std::uint8_t>(pNonce >> 48); aNonceBytes[7] = static_cast<std::uint8_t>(pNonce >> 56);
    
    std::size_t aScratchIndex = 0;
    while (aScratchIndex < S_BLOCK) {
        std::size_t aPasswordIndex = 0;
        while ((aPasswordIndex < pPasswordByteLength) && (aScratchIndex < S_BLOCK)) {
            mScratch[aScratchIndex] = pPassword[aPasswordIndex];
            aScratchIndex++;
            aPasswordIndex++;
        }
        std::size_t aNonceIndex = 0;
        while ((aNonceIndex < 8) && (aScratchIndex < S_BLOCK)) {
            mScratch[aScratchIndex] = aNonceBytes[aNonceIndex];
            aScratchIndex++;
            aNonceIndex++;
        }
    }
}


bool Soccer2::SeedPrelude_Test(std::uint8_t *pPassword,
                               std::size_t pPasswordByteLength,
                               std::uint64_t pNonce) {
    
    UnrollNonceAndPasswordToScratch_Test(pPassword, pPasswordByteLength, pNonce);
    
    std::uint64_t aValue = 0x00;
    for (std::size_t aIndex=0; aIndex<SOCCER_BLOCK_SIZE; aIndex++) {
        aValue = RotL64(aValue, 3);
        aValue ^= static_cast<std::uint64_t>(mScratch[aIndex]);
        aValue = (aValue * 3333333333333333333ULL);
        mMaterialA[aIndex] = static_cast<std::uint8_t>(aValue);
    }
    
    return true;
}

void Soccer2::SeedPrelude_Regular_A(std::uint8_t *pPassword,
                                    std::size_t pPasswordByteLength,
                                    std::uint64_t pNonce) {
    
    InitializeExpanders();
    InitializeWorkSpaces();
    InitializeMaterials();
    InitializeMasks();
    InitializeCiphers();
    
    memset(mClaimedExpanders, 0, sizeof(mClaimedExpanders));
    mClaimedExpanderCount = 0;
    
    memset(mClaimedMaterials, 0, sizeof(mClaimedMaterials));
    mClaimedMaterialCount = 0;
    
    memset(mClaimedWorkSpaces, 0, sizeof(mClaimedWorkSpaces));
    mClaimedWorkSpaceCount = 0;
    
    UnrollNonceAndPasswordToScratch_Regular(pPassword, pPasswordByteLength, pNonce);
}

void Soccer2::SeedPrelude_Regular_B(std::uint64_t pNonce) {
    cStarter.Seed(&mWorkSpaceA, &cFarmSalt, pNonce, mScratch, S_BLOCK, mRandom);
}

void Soccer2::SeedPrelude_Regular_C() {
    TwistShuffle::ShuffleList32(mMasks,         mRandom,     0,  4096, 4);
    TwistShuffle::ShuffleList32(mExpanders,     mRandom,  4096,  8192, 4);
    TwistShuffle::ShuffleList16(mWorkSpaces,    mRandom,  8192, 12288, 4);
    TwistShuffle::ShuffleList16(mMaterials,     mRandom, 12288, 16384, 4);
    
    TwistShuffle::ShuffleList32(mMasks,         mRandom, 16384, 20480, 4);
    TwistShuffle::ShuffleList32(mExpanders,     mRandom, 20480, 24576, 4);
    TwistShuffle::ShuffleList16(mWorkSpaces,    mRandom, 24576, 28672, 4);
    TwistShuffle::ShuffleList16(mMaterials,     mRandom, 28672, 32768, 4);
}

void Soccer2::SeedEpilogue_Regular_A() {
    const std::uint8_t *aShrinkSourceA = nullptr;
    const std::uint8_t *aShrinkSourceB = nullptr;
    const std::uint8_t *aShrinkSourceC = nullptr;
    const std::uint8_t *aShrinkSourceD = nullptr;

    if (mStrength == EncryptionStrength::kWeak) {
        aShrinkSourceA = mMaterials[0];
        aShrinkSourceB = mMaterials[1];
        aShrinkSourceC = mMaterials[2];
        aShrinkSourceD = mMaterials[3];
    } else if (mStrength == EncryptionStrength::kStrong) {
        SoccerFolding::CollapseFold_Outer_16(mMaterials[0],
                                             mMaterials[1],
                                             mMaterials[2],
                                             mMaterials[3],
                                             mMaterials[4],
                                             mMaterials[5],
                                             mMaterials[6],
                                             mMaterials[7],
                                             mMaterials[8],
                                             mMaterials[9],
                                             mMaterials[10],
                                             mMaterials[11],
                                             mMaterials[12],
                                             mMaterials[13],
                                             mMaterials[14],
                                             mMaterials[15],
                                             mCollapseLaneA,
                                             mCollapseLaneB,
                                             mCollapseLaneC,
                                             mCollapseLaneD);

        aShrinkSourceA = mCollapseLaneA;
        aShrinkSourceB = mCollapseLaneB;
        aShrinkSourceC = mCollapseLaneC;
        aShrinkSourceD = mCollapseLaneD;
    } else {
        SoccerFolding::CollapseFold_Outer_8(mMaterials[0],
                                            mMaterials[1],
                                            mMaterials[2],
                                            mMaterials[3],
                                            mMaterials[4],
                                            mMaterials[5],
                                            mMaterials[6],
                                            mMaterials[7],
                                            mCollapseLaneA,
                                            mCollapseLaneB,
                                            mCollapseLaneC,
                                            mCollapseLaneD);

        aShrinkSourceA = mCollapseLaneA;
        aShrinkSourceB = mCollapseLaneB;
        aShrinkSourceC = mCollapseLaneC;
        aShrinkSourceD = mCollapseLaneD;
    }

    SoccerFolding::ShrinkFold_4(aShrinkSourceA,
                                aShrinkSourceB,
                                aShrinkSourceC,
                                aShrinkSourceD,
                                mShrinkLaneA,
                                mShrinkLaneB,
                                mShrinkLaneC,
                                mShrinkLaneD);

    SoccerFolding::CompressFold_4(mShrinkLaneA,
                                  mShrinkLaneB,
                                  mShrinkLaneC,
                                  mShrinkLaneD,
                                  mCompressLaneA,
                                  mCompressLaneB,
                                  mCompressLaneC,
                                  mCompressLaneD);

    SoccerFolding::CrushFold_4(mCompressLaneA,
                             mCompressLaneB,
                             mCompressLaneC,
                             mCompressLaneD,
                             mCrushA,
                             mCrushB,
                             mCrushC,
                             mCrushD);
    
    
    for (std::size_t aIndex=0; aIndex<2048; aIndex++) { mIndexListA[aIndex] = aIndex; }
    for (std::size_t aIndex=0; aIndex<2048; aIndex++) { mIndexListB[aIndex] = aIndex; }

    constexpr std::size_t aShuffleSpanByteCount = 256U;
    static_assert((SOCCER_BLOCK_SIZE_C1 % aShuffleSpanByteCount) == 0U);
    static_assert((aShuffleSpanByteCount % sizeof(std::uint32_t)) == 0U);
    
    cRandIndexA = 0;
    cRandIndexB = 0;
    cRandLane = false;
    
    for (std::size_t aSpanIndex=0U;
         aSpanIndex<(SOCCER_BLOCK_SIZE_C1 / aShuffleSpanByteCount);
         aSpanIndex++) {
        std::size_t *aIndexList = ((aSpanIndex & 1U) == 0U) ? mIndexListA : mIndexListB;
        const std::size_t aStartIndex = aSpanIndex * aShuffleSpanByteCount;
        const std::size_t aCeilingIndex = aStartIndex + aShuffleSpanByteCount;

        for (std::size_t aIndex=aStartIndex; aIndex<aCeilingIndex; aIndex+=4U) {
            const std::uint32_t aShuffleWord = TwistMix32::DiffuseA(Load32LE(&mCrushC[aIndex]));
            const std::size_t aSwapIndexA = static_cast<std::size_t>(aShuffleWord & 2047U);
            const std::size_t aSwapIndexB = static_cast<std::size_t>((aShuffleWord >> 11U) & 2047U);

            const std::size_t aHold = aIndexList[aSwapIndexA];
            aIndexList[aSwapIndexA] = aIndexList[aSwapIndexB];
            aIndexList[aSwapIndexB] = aHold;

            cRandIndexA = TwistMix32::DiffuseA(cRandIndexA + ((aShuffleWord >> 22U) & 15U));
            cRandIndexB = TwistMix32::DiffuseA(cRandIndexB + ((aShuffleWord >> 26U) & 15U));
            const std::uint32_t aLaneBits = (aShuffleWord >> 30U) & 3U;
            if ((aLaneBits == 1U) || (aLaneBits == 2U)) {
                cRandLane = !cRandLane;
            }
        }
    }

    for (std::size_t aSpanIndex=0U;
         aSpanIndex<(SOCCER_BLOCK_SIZE_C1 / aShuffleSpanByteCount);
         aSpanIndex++) {
        std::size_t *aIndexList = ((aSpanIndex & 1U) == 0U) ? mIndexListB : mIndexListA;
        const std::size_t aStartIndex = aSpanIndex * aShuffleSpanByteCount;
        const std::size_t aCeilingIndex = aStartIndex + aShuffleSpanByteCount;

        for (std::size_t aIndex=aStartIndex; aIndex<aCeilingIndex; aIndex+=4U) {
            const std::uint32_t aShuffleWord = TwistMix32::DiffuseA(Load32LE(&mCrushD[aIndex]));
            const std::size_t aSwapIndexA = static_cast<std::size_t>(aShuffleWord & 2047U);
            const std::size_t aSwapIndexB = static_cast<std::size_t>((aShuffleWord >> 11U) & 2047U);

            const std::size_t aHold = aIndexList[aSwapIndexA];
            aIndexList[aSwapIndexA] = aIndexList[aSwapIndexB];
            aIndexList[aSwapIndexB] = aHold;

            cRandIndexA = TwistMix32::DiffuseA(cRandIndexA + ((aShuffleWord >> 22U) & 15U));
            cRandIndexB = TwistMix32::DiffuseA(cRandIndexB + ((aShuffleWord >> 26U) & 15U));
            const std::uint32_t aLaneBits = (aShuffleWord >> 30U) & 3U;
            if ((aLaneBits == 1U) || (aLaneBits == 2U)) {
                cRandLane = !cRandLane;
            }
        }
    }
    
    static_assert(SOCCER_BLOCK_SIZE_C1 == (2048U * sizeof(std::uint64_t)));

    for (std::size_t aRolledIndex=0U; aRolledIndex<256U; aRolledIndex++) {
        const std::size_t aIndex = aRolledIndex * 8U;
        std::uint64_t aFold = 0ULL;
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCrushA[mIndexListA[aIndex + 0U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCrushA[mIndexListA[aIndex + 1U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCrushA[mIndexListA[aIndex + 2U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCrushA[mIndexListA[aIndex + 3U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCrushA[mIndexListA[aIndex + 4U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCrushA[mIndexListA[aIndex + 5U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCrushA[mIndexListA[aIndex + 6U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCrushA[mIndexListA[aIndex + 7U] * 8U]));
        mRolledA[aRolledIndex] = aFold;
    }

    for (std::size_t aRolledIndex=0U; aRolledIndex<256U; aRolledIndex++) {
        const std::size_t aIndex = aRolledIndex * 8U;
        std::uint64_t aFold = 0ULL;
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCrushB[mIndexListB[aIndex + 0U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCrushB[mIndexListB[aIndex + 1U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCrushB[mIndexListB[aIndex + 2U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCrushB[mIndexListB[aIndex + 3U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCrushB[mIndexListB[aIndex + 4U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCrushB[mIndexListB[aIndex + 5U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCrushB[mIndexListB[aIndex + 6U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCrushB[mIndexListB[aIndex + 7U] * 8U]));
        mRolledB[aRolledIndex] = aFold;
    }
    
    
    std::uint64_t aCipherWord = 0ULL;
    
    for (std::size_t aIndex=0; aIndex<16; aIndex++) {
        aCipherWord = TwistMix64::DiffuseA(aCipherWord ^ SoccerRand());
    }
    
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S3; aIndex++) {
        mRotationSeedS3[aIndex] = SoccerRand();
    }
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S2; aIndex++) {
        mRotationSeedS2[aIndex] = SoccerRand();
    }
    for (std::size_t aIndex=0; aIndex<SOCCER_ROTATION_WORD_COUNT_S1; aIndex++) {
        mRotationSeedS1[aIndex] = SoccerRand();
    }
    
    cMaterialIndex = 0;
    cMaterialQuarter = 0;
    
    cMaskIndex = 0;
    
    mRotationBankCursorL3A = 0;
    mRotationBankCursorL2A = 0;
    mRotationBankCursorL1A = 0;
    
    mRotationBankCursorL3B = 0;
    mRotationBankCursorL2B = 0;
    mRotationBankCursorL1B = 0;
    
    mRotationBankCursorL3C = 0;
    
    
    EncryptionPlan aPlan;
    if (mStrength == EncryptionStrength::kWeak) {
        aPlan = EncryptionPlanTool::MakePlanWeak(aCipherWord, mCiphers);
    } else if (mStrength == EncryptionStrength::kStrong) {
        aPlan = EncryptionPlanTool::MakePlanStrong(aCipherWord, mCiphers);
    } else {
        aPlan = EncryptionPlanTool::MakePlanNormal(aCipherWord, mCiphers);
    }

    auto CountRotations = [](const EncryptionPlanStage &pStage) -> std::size_t {
        std::size_t aCount = 0U;
        for (std::size_t aIndex=0U; aIndex<pStage.mCount; aIndex++) {
            if (IS_MESON(pStage.mType[aIndex])) {
                aCount++;
            }
        }
        return aCount;
    };

    auto MakeRotationCount = [](std::size_t pCount) -> SoccerRotationCount {
        if (pCount == 4U) { return SoccerRotationCount::kFour; }
        if (pCount == 3U) { return SoccerRotationCount::kThree; }
        if (pCount == 2U) { return SoccerRotationCount::kTwo; }
        if (pCount == 1U) { return SoccerRotationCount::kOne; }
        return SoccerRotationCount::kNone;
    };

    SoccerRotationBankRequest aRotationBankRequest;
    aRotationBankRequest.mL3A = MakeRotationCount(CountRotations(aPlan.mL3A));
    aRotationBankRequest.mL2A = MakeRotationCount(CountRotations(aPlan.mL2A));
    aRotationBankRequest.mL1A = MakeRotationCount(CountRotations(aPlan.mL1A));
    aRotationBankRequest.mL3B = MakeRotationCount(CountRotations(aPlan.mL3B));
    aRotationBankRequest.mL2B = MakeRotationCount(CountRotations(aPlan.mL2B));
    aRotationBankRequest.mL1B = MakeRotationCount(CountRotations(aPlan.mL1B));
    aRotationBankRequest.mL3C = MakeRotationCount(CountRotations(aPlan.mL3C));

    cRotationBankResponse = SoccerRotationBank::Withdraw(aRotationBankRequest);

    // Consume the material in descending lane size so the quarter-lane cursor
    // packs the selected key material without stranding larger spans.
    for (std::size_t aCipherIndex=0U; aCipherIndex<aPlan.mL3A.mCount; aCipherIndex++) {
        Crypt *aCipher = GenerateCipher(aPlan.mL3A.mType[aCipherIndex], kStageL3A);
        if (aCipher == nullptr) {
            printf("Fatal: failed to generate L3A cipher %zu.\n", aCipherIndex);
            exit(0);
        }
        mCryptex.AddCipherL3A(aCipher);
    }

    for (std::size_t aCipherIndex=0U; aCipherIndex<aPlan.mL3B.mCount; aCipherIndex++) {
        Crypt *aCipher = GenerateCipher(aPlan.mL3B.mType[aCipherIndex], kStageL3B);
        if (aCipher == nullptr) {
            printf("Fatal: failed to generate L3B cipher %zu.\n", aCipherIndex);
            exit(0);
        }
        mCryptex.AddCipherL3B(aCipher);
    }

    for (std::size_t aCipherIndex=0U; aCipherIndex<aPlan.mL3C.mCount; aCipherIndex++) {
        Crypt *aCipher = GenerateCipher(aPlan.mL3C.mType[aCipherIndex], kStageL3C);
        if (aCipher == nullptr) {
            printf("Fatal: failed to generate L3C cipher %zu.\n", aCipherIndex);
            exit(0);
        }
        mCryptex.AddCipherL3C(aCipher);
    }

    for (std::size_t aCipherIndex=0U; aCipherIndex<aPlan.mL2A.mCount; aCipherIndex++) {
        Crypt *aCipher = GenerateCipher(aPlan.mL2A.mType[aCipherIndex], kStageL2A);
        if (aCipher == nullptr) {
            printf("Fatal: failed to generate L2A cipher %zu.\n", aCipherIndex);
            exit(0);
        }
        mCryptex.AddCipherL2A(aCipher);
    }

    for (std::size_t aCipherIndex=0U; aCipherIndex<aPlan.mL2B.mCount; aCipherIndex++) {
        Crypt *aCipher = GenerateCipher(aPlan.mL2B.mType[aCipherIndex], kStageL2B);
        if (aCipher == nullptr) {
            printf("Fatal: failed to generate L2B cipher %zu.\n", aCipherIndex);
            exit(0);
        }
        mCryptex.AddCipherL2B(aCipher);
    }

    for (std::size_t aCipherIndex=0U; aCipherIndex<aPlan.mL1A.mCount; aCipherIndex++) {
        Crypt *aCipher = GenerateCipher(aPlan.mL1A.mType[aCipherIndex], kStageL1A);
        if (aCipher == nullptr) {
            printf("Fatal: failed to generate L1A cipher %zu.\n", aCipherIndex);
            exit(0);
        }
        mCryptex.AddCipherL1A(aCipher);
    }

    for (std::size_t aCipherIndex=0U; aCipherIndex<aPlan.mL1B.mCount; aCipherIndex++) {
        Crypt *aCipher = GenerateCipher(aPlan.mL1B.mType[aCipherIndex], kStageL1B);
        if (aCipher == nullptr) {
            printf("Fatal: failed to generate L1B cipher %zu.\n", aCipherIndex);
            exit(0);
        }
        mCryptex.AddCipherL1B(aCipher);
    }
}

void Soccer2::ShuffleMEWBlockZero(std::uint8_t *pMaterial) {
    
    if (pMaterial == nullptr) {
        return;
    }
    
    for (std::size_t aIndex=0; aIndex<16; aIndex++) {
        mShuffleMaterials[aIndex] = mMaterials[aIndex];
    }
    for (std::size_t aIndex=0; aIndex<32; aIndex++) {
        mShuffleExpanders[aIndex] = mExpanders[aIndex];
    }
    for (std::size_t aIndex=0; aIndex<16; aIndex++) {
        mShuffleWorkSpaces[aIndex] = mWorkSpaces[aIndex];
    }
    
    TwistShuffle::ShuffleList16(mShuffleMaterials,  pMaterial,     0U,  3600U, 1U);
    TwistShuffle::ShuffleList32(mShuffleExpanders,  pMaterial,  3600U,  7200U, 1U);
    TwistShuffle::ShuffleList16(mShuffleWorkSpaces, pMaterial,  7200U, 10800U, 1U);

    TwistShuffle::ShuffleList16(mShuffleMaterials,  pMaterial, 10800U, 14400U, 1U);
    TwistShuffle::ShuffleList32(mShuffleExpanders,  pMaterial, 14400U, 18000U, 1U);
    TwistShuffle::ShuffleList16(mShuffleWorkSpaces, pMaterial, 18000U, 21600U, 1U);

    TwistShuffle::ShuffleList16(mShuffleMaterials,  pMaterial, 21600U, 25200U, 1U);
    TwistShuffle::ShuffleList32(mShuffleExpanders,  pMaterial, 25200U, 28800U, 1U);
    TwistShuffle::ShuffleList16(mShuffleWorkSpaces, pMaterial, 28800U, 32400U, 1U);

    // Move claimed materials to the back.
    for (std::size_t aIndex=0; aIndex<16; aIndex++) {
        mClaimed[aIndex] = false;
        for (std::size_t aClaimedIndex=0; aClaimedIndex<mClaimedMaterialCount; aClaimedIndex++) {
            if (mShuffleMaterials[aIndex] == mClaimedMaterials[aClaimedIndex]) {
                mClaimed[aIndex] = true;
                break;
            }
        }
    }

    TwistShuffle::MoveClaimedToEnd16(mClaimed, mShuffleMaterials);

    // Move claimed expanders to the back.
    for (std::size_t aIndex=0; aIndex<32; aIndex++) {
        mClaimed[aIndex] = false;
        for (std::size_t aClaimedIndex=0; aClaimedIndex<mClaimedExpanderCount; aClaimedIndex++) {
            if (mShuffleExpanders[aIndex] == mClaimedExpanders[aClaimedIndex]) {
                mClaimed[aIndex] = true;
                break;
            }
        }
    }

    TwistShuffle::MoveClaimedToEnd32(mClaimed, mShuffleExpanders);

    // Move claimed work spaces to the back.
    for (std::size_t aIndex=0; aIndex<16; aIndex++) {
        mClaimed[aIndex] = false;
        for (std::size_t aClaimedIndex=0; aClaimedIndex<mClaimedWorkSpaceCount; aClaimedIndex++) {
            if (mShuffleWorkSpaces[aIndex] == mClaimedWorkSpaces[aClaimedIndex]) {
                mClaimed[aIndex] = true;
                break;
            }
        }
    }

    TwistShuffle::MoveClaimedToEnd16(mClaimed, mShuffleWorkSpaces);

    for (std::size_t aIndex=0; aIndex<16; aIndex++) {
        mMaterials[aIndex] = mShuffleMaterials[aIndex];
    }
    for (std::size_t aIndex=0; aIndex<32; aIndex++) {
        mExpanders[aIndex] = mShuffleExpanders[aIndex];
    }
    for (std::size_t aIndex=0; aIndex<16; aIndex++) {
        mWorkSpaces[aIndex] = mShuffleWorkSpaces[aIndex];
    }
}



void Soccer2::RotateSourcesIntoCross() {
    std::size_t aComplexity = 0U;
    if (mStrength == EncryptionStrength::kWeak) {
        aComplexity = COMPLEXITY_WEAK;
    } else if (mStrength == EncryptionStrength::kStrong) {
        aComplexity = COMPLEXITY_STRONG;
    } else {
        aComplexity = COMPLEXITY_NORMAL;
    }

    for (std::size_t aIndex=0U; aIndex<aComplexity; aIndex++) {
        mCross[0][aIndex] = mCross[1][aIndex];
    }
    for (std::size_t aIndex=0U; aIndex<aComplexity; aIndex++) {
        mCross[1][aIndex] = mCross[2][aIndex];
    }
    for (std::size_t aIndex=0U; aIndex<aComplexity; aIndex++) {
        mCross[2][aIndex] = mCross[3][aIndex];
    }
    for (std::size_t aIndex=0U; aIndex<aComplexity; aIndex++) {
        mCross[3][aIndex] = mSources[aIndex];
    }
}
