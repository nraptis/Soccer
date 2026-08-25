//
//  Soccer2.cpp
//  Scramble
//
//  Created by Icarus Black on 8/1/26.
//

#include "Soccer2.hpp"
#include "SoccerFolding.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"
#include "EncryptionPlan.hpp"
#include "SoccerMaskBank.hpp"

#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_set>


#define BLOCK_COUNT (SOCCER_BLOCK_SIZE / S_BLOCK)

#define COMPLEXITY_STRONG 16
#define COMPLEXITY_NORMAL 8
#define COMPLEXITY_WEAK 4

#define WARM_UP_ROUNDS 5
#define WARM_UP_BLOCKS (WARM_UP_ROUNDS + 1)

#define READ_IN_MUTABLE_PARAMS_INTERNAL \
    std::uint64_t aIngress = *pIngress; \
    std::uint64_t aCarry = *pCarry; \
    std::uint64_t aWandererA = *pWandererA; \
    std::uint64_t aWandererB = *pWandererB; \
    std::uint64_t aWandererC = *pWandererC; \
    std::uint64_t aWandererD = *pWandererD; \
    std::uint64_t aWandererE = *pWandererE; \
    std::uint64_t aWandererF = *pWandererF; \
    std::uint64_t aWandererG = *pWandererG; \
    std::uint64_t aWandererH = *pWandererH; \
    std::uint64_t aWandererI = *pWandererI; \
    std::uint64_t aWandererJ = *pWandererJ; \
    std::uint64_t aWandererK = *pWandererK

namespace {

constexpr std::uint8_t kStageL3A = 0U;
constexpr std::uint8_t kStageL2A = 1U;
constexpr std::uint8_t kStageL1A = 2U;
constexpr std::uint8_t kStageL3B = 3U;
constexpr std::uint8_t kStageL2B = 4U;
constexpr std::uint8_t kStageL1B = 5U;
constexpr std::uint8_t kStageL3C = 6U;
constexpr std::uint8_t kStageL2C = 7U;
constexpr std::uint8_t kStageL1C = 8U;

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

TwistExpander_Betelgeuse                    Soccer2::mStarter;

TwistExpander_Aldebaran                     Soccer2::mAldebaran; // 1
TwistExpander_Altair                        Soccer2::mAltair; // 2
TwistExpander_Antares                       Soccer2::mAntares; // 3
TwistExpander_Arcturus                      Soccer2::mArcturus; // 4
TwistExpander_Bellatrix                     Soccer2::mBellatrix; // 5
TwistExpander_Capella                       Soccer2::mCapella; // 6
TwistExpander_Castor                        Soccer2::mCastor; // 7
TwistExpander_Mimosa                        Soccer2::mMimosa; // 8
TwistExpander_Polaris                       Soccer2::mPolaris; // 9
TwistExpander_Pollux                        Soccer2::mPollux; // 10
TwistExpander_Procyon                       Soccer2::mProcyon; // 11
TwistExpander_Regulus                       Soccer2::mRegulus; // 12
TwistExpander_Rigel                         Soccer2::mRigel; // 13
TwistExpander_Saiph                         Soccer2::mSaiph; // 14
TwistExpander_Sirius                        Soccer2::mSirius; // 15
TwistExpander_Vega                          Soccer2::mVega; // 16

/*
TwistExpander_Aldebaran                    Soccer2::mStarter;

TwistExpander_Aldebaran                     Soccer2::mAldebaran; // 1
TwistExpander_Aldebaran                     Soccer2::mAltair; // 2
TwistExpander_Aldebaran                     Soccer2::mAntares; // 3
TwistExpander_Aldebaran                     Soccer2::mArcturus; // 4
TwistExpander_Aldebaran                     Soccer2::mBellatrix; // 5
TwistExpander_Aldebaran                     Soccer2::mCapella; // 6
TwistExpander_Aldebaran                     Soccer2::mCastor; // 7
TwistExpander_Aldebaran                     Soccer2::mMimosa; // 8
TwistExpander_Aldebaran                     Soccer2::mPolaris; // 9
TwistExpander_Aldebaran                     Soccer2::mPollux; // 10
TwistExpander_Aldebaran                     Soccer2::mProcyon; // 11
TwistExpander_Aldebaran                     Soccer2::mRegulus; // 12
TwistExpander_Aldebaran                     Soccer2::mRigel; // 13
TwistExpander_Aldebaran                     Soccer2::mSaiph; // 14
TwistExpander_Aldebaran                     Soccer2::mSirius; // 15
TwistExpander_Aldebaran                     Soccer2::mVega; // 16
*/

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

std::uint8_t                                Soccer2::mCollapseLaneA[SOCCER_BLOCK_SIZE];
std::uint8_t                                Soccer2::mCollapseLaneB[SOCCER_BLOCK_SIZE];
std::uint8_t                                Soccer2::mCollapseLaneC[SOCCER_BLOCK_SIZE];
std::uint8_t                                Soccer2::mCollapseLaneD[SOCCER_BLOCK_SIZE];

std::uint8_t                                Soccer2::mCondenseLaneA[SOCCER_BLOCK_SIZE_L1];
std::uint8_t                                Soccer2::mCondenseLaneB[SOCCER_BLOCK_SIZE_L1];
std::uint8_t                                Soccer2::mCondenseLaneC[SOCCER_BLOCK_SIZE_L1];
std::uint8_t                                Soccer2::mCondenseLaneD[SOCCER_BLOCK_SIZE_L1];

std::size_t                                 Soccer2::mIndexListA[2048];
std::size_t                                 Soccer2::mIndexListB[2048];

std::uint64_t                               Soccer2::mPremiumSeed[256];

std::uint8_t                                Soccer2::mMasks[SoccerMaskBank::mMaskGridWidth];

std::int32_t                                Soccer2::mRotationsL3[3];
std::int32_t                                Soccer2::mRotationsL2[3];
std::int32_t                                Soccer2::mRotationsL1[3];


std::uint8_t                                *Soccer2::mMaterials[16];
TwistExpander                               *Soccer2::mExpanders[SOCCER_EXPANDER_COUNT];
TwistWorkSpace                              *Soccer2::mWorkSpaces[16];
std::uint8_t                                *Soccer2::mSources[16];
std::uint8_t                                *Soccer2::mCross[4][16];

std::uint8_t                                *Soccer2::mCrossPool[16][64];
std::size_t                                 Soccer2::mCrossPoolCount[16];
std::size_t                                 Soccer2::mCrossPermutations[16][64];

bool                                        Soccer2::mClaimed[SOCCER_EXPANDER_COUNT];

TwistExpander                               *Soccer2::mClaimedExpanders[16];
std::size_t                                 Soccer2::mClaimedExpanderCount;

std::uint8_t                                *Soccer2::mClaimedMaterials[16];
std::size_t                                 Soccer2::mClaimedMaterialCount;

TwistWorkSpace                              *Soccer2::mClaimedWorkSpaces[16];
std::size_t                                 Soccer2::mClaimedWorkSpaceCount;

Cryptex6                                    Soccer2::mCryptex6;
Cryptex9                                    Soccer2::mCryptex9;

std::uint8_t                                *Soccer2::mShuffleMaterials[16];
TwistExpander                               *Soccer2::mShuffleExpanders[SOCCER_EXPANDER_COUNT];
TwistWorkSpace                              *Soccer2::mShuffleWorkSpaces[16];

CipherType                                  Soccer2::mCiphers[256];

EncryptionStrength                          Soccer2::mStrength = EncryptionStrength::kNormal;

uint32_t                                    Soccer2::mTestBlockLength = SOCCER_BLOCK_SIZE;

std::size_t                                 Soccer2::mMaterialIndex = 0;
std::size_t                                 Soccer2::mMaterialQuarter = 0;

std::size_t                                 Soccer2::mMaskCursor = 0;

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
    
    for (std::size_t aIndex=0U; aIndex<15U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kSplintMaskBlockCipher32; }
    for (std::size_t aIndex=0U; aIndex<15U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kSplintMaskBlockCipher64; }
    
    for (std::size_t aIndex=0U; aIndex<10U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kInvertMaskCipher; }
    for (std::size_t aIndex=0U; aIndex<20U; aIndex++) { mCiphers[aCipherIndex++] = CipherType::kRotateCipher; }
    
    while (aCipherIndex < 256) {
        mCiphers[aCipherIndex] = CipherType::kRotateMaskCipher;
        aCipherIndex++;
    }
}

void Soccer2::InitializeExpanders() {
    mExpanders[ 0] = &mAldebaran; mExpanders[ 1] = &mAltair;   mExpanders[ 2] = &mAntares;  mExpanders[ 3] = &mArcturus;
    mExpanders[ 4] = &mBellatrix; mExpanders[ 5] = &mCapella;  mExpanders[ 6] = &mCastor;   mExpanders[ 7] = &mMimosa;
    mExpanders[ 8] = &mPolaris;   mExpanders[ 9] = &mPollux;   mExpanders[10] = &mProcyon;  mExpanders[11] = &mRegulus;
    mExpanders[12] = &mRigel;     mExpanders[13] = &mSaiph;    mExpanders[14] = &mSirius;   mExpanders[15] = &mVega;
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
            SOCCER_SCRATCH_WORKER_A[aScratchIndex] = pPassword[aPasswordIndex];
            aScratchIndex++;
            aPasswordIndex++;
        }
        std::size_t aNonceIndex = 0;
        while ((aNonceIndex < 8) && (aScratchIndex < SOCCER_BLOCK_SIZE)) {
            SOCCER_SCRATCH_WORKER_A[aScratchIndex] = aNonceBytes[aNonceIndex];
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
            SOCCER_SCRATCH_WORKER_A[aScratchIndex] = pPassword[aPasswordIndex];
            aScratchIndex++;
            aPasswordIndex++;
        }
        std::size_t aNonceIndex = 0;
        while ((aNonceIndex < 8) && (aScratchIndex < S_BLOCK)) {
            SOCCER_SCRATCH_WORKER_A[aScratchIndex] = aNonceBytes[aNonceIndex];
            aScratchIndex++;
            aNonceIndex++;
        }
    }
}

std::uint8_t *Soccer2::PopLaneS3() {
    if (mMaterialQuarter != 0U) {
        mMaterialIndex++;
        mMaterialQuarter = 0U;
    }
    if (mMaterialIndex >= 16U) {
        return nullptr;
    }

    std::uint8_t *aResult = mMaterials[mMaterialIndex];
    mMaterialIndex++;
    return aResult;
}

std::uint8_t *Soccer2::PopLaneS2() {
    if ((mMaterialQuarter + 2U) > 4U) {
        mMaterialIndex++;
        mMaterialQuarter = 0U;
    }
    if (mMaterialIndex >= 16U) {
        return nullptr;
    }

    std::uint8_t *aResult = mMaterials[mMaterialIndex] + (mMaterialQuarter * SOCCER_BLOCK_SIZE_L1);
    mMaterialQuarter += 2U;
    if (mMaterialQuarter == 4U) {
        mMaterialIndex++;
        mMaterialQuarter = 0U;
    }
    return aResult;
}

std::uint8_t *Soccer2::PopLaneS1() {
    if (mMaterialIndex >= 16U) {
        return nullptr;
    }
    
    std::uint8_t *aResult = mMaterials[mMaterialIndex] + (mMaterialQuarter * SOCCER_BLOCK_SIZE_L1);
    mMaterialQuarter++;
    if (mMaterialQuarter == 4U) {
        mMaterialIndex++;
        mMaterialQuarter = 0U;
    }
    return aResult;
}

std::uint8_t Soccer2::PopMask() {
    const std::uint8_t aResult = mMasks[mMaskCursor];
    mMaskCursor = ((mMaskCursor + 1) % SoccerMaskBank::mMaskGridWidth);
    return aResult;
}

std::int32_t Soccer2::PopRotation(std::uint8_t pStage) {
    switch (pStage) {
        case kStageL3A: return mRotationsL3[0];
        case kStageL2A: return mRotationsL2[0];
        case kStageL1A: return mRotationsL1[0];
        case kStageL3B: return mRotationsL3[1];
        case kStageL2B: return mRotationsL2[1];
        case kStageL1B: return mRotationsL1[1];
        case kStageL3C: return mRotationsL3[2];
        case kStageL2C: return mRotationsL2[2];
        case kStageL1C: return mRotationsL1[2];
    }
    return 0;
}

Cipher *Soccer2::GenerateCipher(CipherType pType, std::uint8_t pStage) {
    if (pStage > kStageL1C) {
        return nullptr;
    }

    auto PopLane = [pStage]() -> std::uint8_t * {
        if ((pStage == kStageL3A) ||
            (pStage == kStageL3B) ||
            (pStage == kStageL3C)) {
            return PopLaneS3();
        }
        if ((pStage == kStageL2A) ||
            (pStage == kStageL2B) ||
            (pStage == kStageL2C)) {
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
            return new RotateCipher(aRotation);
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
    std::memset(mCollapseLaneA, 0, sizeof(mCollapseLaneA));
    std::memset(mCollapseLaneB, 0, sizeof(mCollapseLaneB));
    std::memset(mCollapseLaneC, 0, sizeof(mCollapseLaneC));
    std::memset(mCollapseLaneD, 0, sizeof(mCollapseLaneD));
    std::memset(mCondenseLaneA, 0, sizeof(mCondenseLaneA));
    std::memset(mCondenseLaneB, 0, sizeof(mCondenseLaneB));
    std::memset(mCondenseLaneC, 0, sizeof(mCondenseLaneC));
    std::memset(mCondenseLaneD, 0, sizeof(mCondenseLaneD));
    std::memset(mIndexListA, 0, sizeof(mIndexListA));
    std::memset(mIndexListB, 0, sizeof(mIndexListB));
    std::memset(mPremiumSeed, 0, sizeof(mPremiumSeed));
    std::memset(mMasks, 0, sizeof(mMasks));
    
    mRotationsL1[0] = 0;
    mRotationsL1[1] = 0;
    mRotationsL1[2] = 0;
    
    mRotationsL2[0] = 0;
    mRotationsL2[1] = 0;
    mRotationsL2[2] = 0;
    
    mRotationsL3[0] = 0;
    mRotationsL3[1] = 0;
    mRotationsL3[2] = 0;
    
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
    
    mStarter.Zero();
    
    mAldebaran.Zero();
    mAltair.Zero();
    mAntares.Zero();
    mArcturus.Zero();
    mBellatrix.Zero();
    mCapella.Zero();
    mCastor.Zero();
    mMimosa.Zero();
    mPolaris.Zero();
    mPollux.Zero();
    mProcyon.Zero();
    mRegulus.Zero();
    mRigel.Zero();
    mSaiph.Zero();
    mSirius.Zero();
    mVega.Zero();
    
    InitializeCiphers();
    InitializeExpanders();
    InitializeWorkSpaces();
    InitializeMaterials();

    for (std::size_t aIndex=0U; aIndex<SOCCER_EXPANDER_COUNT; aIndex++) {
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

    for (std::size_t aLaneIndex=0U; aLaneIndex<16U; aLaneIndex++) {
        mCrossPoolCount[aLaneIndex] = 0U;
        for (std::size_t aPoolIndex=0U; aPoolIndex<64U; aPoolIndex++) {
            mCrossPool[aLaneIndex][aPoolIndex] = nullptr;
            mCrossPermutations[aLaneIndex][aPoolIndex] = 0U;
        }
    }

    mCryptex6.Zero();
    mCryptex9.Zero();

    mCryptex6.Free();
    mCryptex9.Free();

    mClaimedExpanderCount = 0U;
    mClaimedMaterialCount = 0U;
    mClaimedWorkSpaceCount = 0U;

    mMaskCursor = 0U;
    mMaterialIndex = 0U;
    mMaterialQuarter = 0U;
    mTestBlockLength = 0U;

    mStrength = EncryptionStrength::kNormal;
}

void Soccer2::Shuffle_CROWSCIMASSORMATEX() {
    constexpr std::size_t cSpan = 256U;
    constexpr std::size_t cBlockSpan = 4U * cSpan;
    static_assert(S_BLOCK == (32U * cBlockSpan));
    
    
    /*

     materials // block 0
     sources // block 1
     work_spaces // block 2
     expanders // block 3
     ciphers // block 4
     permute_0_3 // block 5
     permute_4_7 // block 6
     permute_8_11 // block 7
     permute_12_15 // block 8
     
     materials // block 9
     sources // block 10
     work_spaces // block 11
     expanders // block 12
     ciphers // block 13
     permute_0_3 // block 14
     permute_4_7 // block 15
     permute_8_11 // block 16
     permute_12_15 // block 17
     
     materials // block 18
     sources // block 19
     work_spaces // block 20
     expanders // block 21
     ciphers // block 22
     permute_0_3 // block 23
     permute_4_7 // block 24
     permute_8_11 // block 25
     permute_12_15 // block 26
     
     materials // block 27
     sources // block 28
     work_spaces // block 29
     expanders // block 30
     ciphers // block 31
    */
    
    // Materials: blocks 0, 9, 18, and 27.
    if (mStrength == EncryptionStrength::kWeak) {
        TwistShuffle::ShuffleList4(mMaterials, mRandom,  0U * cBlockSpan,  1U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList4(mMaterials, mRandom,  9U * cBlockSpan, 10U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList4(mMaterials, mRandom, 18U * cBlockSpan, 19U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList4(mMaterials, mRandom, 27U * cBlockSpan, 28U * cBlockSpan, 1U);
    } else if (mStrength == EncryptionStrength::kStrong) {
        TwistShuffle::ShuffleList16(mMaterials, mRandom,  0U * cBlockSpan,  1U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList16(mMaterials, mRandom,  9U * cBlockSpan, 10U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList16(mMaterials, mRandom, 18U * cBlockSpan, 19U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList16(mMaterials, mRandom, 27U * cBlockSpan, 28U * cBlockSpan, 1U);
    } else {
        TwistShuffle::ShuffleList8(mMaterials, mRandom,  0U * cBlockSpan,  1U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList8(mMaterials, mRandom,  9U * cBlockSpan, 10U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList8(mMaterials, mRandom, 18U * cBlockSpan, 19U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList8(mMaterials, mRandom, 27U * cBlockSpan, 28U * cBlockSpan, 1U);
    }

    // Expanders: blocks 3, 12, 21, and 30.
    TwistShuffle::ShuffleList16(mExpanders, mRandom,  3U * cBlockSpan,  4U * cBlockSpan, 1U);
    TwistShuffle::ShuffleList16(mExpanders, mRandom, 12U * cBlockSpan, 13U * cBlockSpan, 1U);
    TwistShuffle::ShuffleList16(mExpanders, mRandom, 21U * cBlockSpan, 22U * cBlockSpan, 1U);
    TwistShuffle::ShuffleList16(mExpanders, mRandom, 30U * cBlockSpan, 31U * cBlockSpan, 1U);

    // Work spaces: blocks 2, 11, 20, and 29.
    if (mStrength == EncryptionStrength::kWeak) {
        TwistShuffle::ShuffleList4(mWorkSpaces, mRandom,  2U * cBlockSpan,  3U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList4(mWorkSpaces, mRandom, 11U * cBlockSpan, 12U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList4(mWorkSpaces, mRandom, 20U * cBlockSpan, 21U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList4(mWorkSpaces, mRandom, 29U * cBlockSpan, 30U * cBlockSpan, 1U);
    } else if (mStrength == EncryptionStrength::kStrong) {
        TwistShuffle::ShuffleList16(mWorkSpaces, mRandom,  2U * cBlockSpan,  3U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList16(mWorkSpaces, mRandom, 11U * cBlockSpan, 12U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList16(mWorkSpaces, mRandom, 20U * cBlockSpan, 21U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList16(mWorkSpaces, mRandom, 29U * cBlockSpan, 30U * cBlockSpan, 1U);
    } else {
        TwistShuffle::ShuffleList8(mWorkSpaces, mRandom,  2U * cBlockSpan,  3U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList8(mWorkSpaces, mRandom, 11U * cBlockSpan, 12U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList8(mWorkSpaces, mRandom, 20U * cBlockSpan, 21U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList8(mWorkSpaces, mRandom, 29U * cBlockSpan, 30U * cBlockSpan, 1U);
    }

    // Ciphers: blocks 4, 13, 22, and 31.
    TwistShuffle::ShuffleList256(mCiphers, mRandom,  4U * cBlockSpan,  5U * cBlockSpan, 1U);
    TwistShuffle::ShuffleList256(mCiphers, mRandom, 13U * cBlockSpan, 14U * cBlockSpan, 1U);
    TwistShuffle::ShuffleList256(mCiphers, mRandom, 22U * cBlockSpan, 23U * cBlockSpan, 1U);
    TwistShuffle::ShuffleList256(mCiphers, mRandom, 31U * cBlockSpan, 32U * cBlockSpan, 1U);

    // Sources: blocks 1, 10, 19, and 28.
    if (mStrength == EncryptionStrength::kWeak) {
        TwistShuffle::ShuffleList4(mSources, mRandom,  1U * cBlockSpan,  2U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList4(mSources, mRandom, 10U * cBlockSpan, 11U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList4(mSources, mRandom, 19U * cBlockSpan, 20U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList4(mSources, mRandom, 28U * cBlockSpan, 29U * cBlockSpan, 1U);
    } else if (mStrength == EncryptionStrength::kStrong) {
        TwistShuffle::ShuffleList16(mSources, mRandom,  1U * cBlockSpan,  2U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList16(mSources, mRandom, 10U * cBlockSpan, 11U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList16(mSources, mRandom, 19U * cBlockSpan, 20U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList16(mSources, mRandom, 28U * cBlockSpan, 29U * cBlockSpan, 1U);
    } else {
        TwistShuffle::ShuffleList8(mSources, mRandom,  1U * cBlockSpan,  2U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList8(mSources, mRandom, 10U * cBlockSpan, 11U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList8(mSources, mRandom, 19U * cBlockSpan, 20U * cBlockSpan, 1U);
        TwistShuffle::ShuffleList8(mSources, mRandom, 28U * cBlockSpan, 29U * cBlockSpan, 1U);
    }
}

void Soccer2::Shuffle_CROSSPERMUTATIONS(std::size_t pPermutationCount) {
    constexpr std::size_t cSpan = 256U;
    constexpr std::size_t cBlockSpan = 4U * cSpan;
    constexpr std::size_t cCrossBlocks[3][4] = {
        { 5U,  6U,  7U,  8U},
        {14U, 15U, 16U, 17U},
        {23U, 24U, 25U, 26U},
    };
    static_assert(S_BLOCK == (32U * cBlockSpan));
    
    for (std::size_t aRoundIndex=0U; aRoundIndex<3U; aRoundIndex++) {
        for (std::size_t aLaneGroup=0U; aLaneGroup<4U; aLaneGroup++) {
            const std::size_t aBlockIndex = cCrossBlocks[aRoundIndex][aLaneGroup];
            for (std::size_t aQuarterIndex=0U; aQuarterIndex<4U; aQuarterIndex++) {
                const std::size_t aLaneIndex = (aLaneGroup * 4U) + aQuarterIndex;
                const std::size_t aStartIndex = (aBlockIndex * cBlockSpan) + (aQuarterIndex * cSpan);
                const std::size_t aCeilingIndex = aStartIndex + cSpan;

                if (pPermutationCount == 4U) {
                    TwistShuffle::ShuffleList4(mCrossPermutations[aLaneIndex],
                                               mRandom,
                                               aStartIndex,
                                               aCeilingIndex,
                                               1U);
                } else if (pPermutationCount == 8U) {
                    TwistShuffle::ShuffleList8(mCrossPermutations[aLaneIndex],
                                               mRandom,
                                               aStartIndex,
                                               aCeilingIndex,
                                               1U);
                } else if (pPermutationCount == 16U) {
                    TwistShuffle::ShuffleList16(mCrossPermutations[aLaneIndex],
                                                mRandom,
                                                aStartIndex,
                                                aCeilingIndex,
                                                1U);
                } else if (pPermutationCount == 32U) {
                    TwistShuffle::ShuffleList32(mCrossPermutations[aLaneIndex],
                                                mRandom,
                                                aStartIndex,
                                                aCeilingIndex,
                                                1U);
                } else {
                    TwistShuffle::ShuffleList64(mCrossPermutations[aLaneIndex],
                                                mRandom,
                                                aStartIndex,
                                                aCeilingIndex,
                                                1U);
                }
            }
        }
    }
}

void Soccer2::TwistRound(std::size_t pBlockIndex,
                         bool pIsWarmUpRound,
                         MUTABLE_PARAMS) {
    
    std::size_t aComplexity = COMPLEXITY_NORMAL;
    std::size_t aReverseCount = 2U;
    if (mStrength == EncryptionStrength::kWeak) {
        aComplexity = COMPLEXITY_WEAK;
        aReverseCount = 1U;
    } else if (mStrength == EncryptionStrength::kStrong) {
        aComplexity = COMPLEXITY_STRONG;
        aReverseCount = 4U;
    }
    
    static_assert(BLOCK_COUNT >= H_KEY);
    const bool aStifleKey =
        (!pIsWarmUpRound) && (pBlockIndex >= (BLOCK_COUNT - H_KEY));
    
    READ_IN_MUTABLE_PARAMS_INTERNAL;
    const std::size_t aDestinationByteIndex = pBlockIndex * S_BLOCK;
    for (std::size_t aLaneIndex=0U; aLaneIndex<aComplexity; aLaneIndex++) {
        mExpanders[aLaneIndex]->TwistBlock(mWorkSpaces[aLaneIndex],
                                           mSources[aLaneIndex],
                                           mCross[0][aLaneIndex],
                                           mCross[1][aLaneIndex],
                                           mCross[2][aLaneIndex],
                                           mCross[3][aLaneIndex],
                                           &mMaterials[aLaneIndex][aDestinationByteIndex],
                                           aStifleKey,
                                           ARX_STATE_VARS);
    }

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
    
    WRITE_OUT_MUTABLE_PARAMS;
}

void Soccer2::SeedPrologue_Regular_A(std::uint8_t *pPassword,
                                     std::size_t pPasswordByteLength,
                                     std::uint64_t pNonce,
                                     MUTABLE_PARAMS) {
    
    std::size_t aPower = 0U;
    if (mStrength == EncryptionStrength::kWeak) {
        aPower = 1U;
    } else if (mStrength == EncryptionStrength::kStrong) {
        aPower = 4U;
    } else {
        aPower = 2U;
    }
    
    const std::size_t aWarmUpStartIndex = (BLOCK_COUNT - WARM_UP_BLOCKS) * S_BLOCK;
    
    READ_IN_MUTABLE_PARAMS_INTERNAL;
    
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
                                                   pNonce,
                                                   pPassword,
                                                   pPasswordByteLength,
                                                   &mClaimedMaterials[aClaimedIndex][aWarmUpStartIndex],
                                                   ARX_STATE_VARS);
        }

        if (aSpanIndex < 3U) {
            Shuffle_MEWBlockZero(&mClaimedMaterials[mClaimedMaterialCount - 1U][aWarmUpStartIndex]);
        }
    }
    
    WRITE_OUT_MUTABLE_PARAMS;
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
    for (std::size_t aShuffledIndex=0U; aShuffledIndex<SOCCER_EXPANDER_COUNT; aShuffledIndex++) {
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
        }
        
    } else if (mStrength == EncryptionStrength::kStrong) {
        FoldMaterialsIntoRandomForBlock_16(aFirstWarmUpBlockIndex);
        
        for (std::size_t aIndex=0U; aIndex<COMPLEXITY_STRONG; aIndex++) {
            mSources[aIndex] = &mMaterials[aIndex][aFirstWarmUpByteIndex];
        }
    } else {
        FoldMaterialsIntoRandomForBlock_8(aFirstWarmUpBlockIndex);
        
        for (std::size_t aIndex=0U; aIndex<COMPLEXITY_NORMAL; aIndex++) {
            mSources[aIndex] = &mMaterials[aIndex][aFirstWarmUpByteIndex];
        }
    }
}

void Soccer2::ArrangeCrossPool(std::size_t pComplexity) {
    constexpr std::size_t aCrossCount = 4U;
    constexpr std::size_t aCrossPoolCapacity = 64U;

    for (std::size_t aLaneIndex=0U; aLaneIndex<pComplexity; aLaneIndex++) {
        const std::size_t aPoolCount = mCrossPoolCount[aLaneIndex];
        if ((aPoolCount < aCrossCount) || (aPoolCount > aCrossPoolCapacity)) {
            printf("Fatal: cross pool count %zu is outside 4...64.\n", aPoolCount);
            exit(0);
        }

        for (std::size_t aCrossIndex=0U; aCrossIndex<aCrossCount; aCrossIndex++) {
            const std::size_t aPoolIndex =
                mCrossPermutations[aLaneIndex][aCrossIndex];
            if (aPoolIndex >= aPoolCount) {
                printf("Fatal: cross pool permutation index %zu exceeds count %zu.\n",
                       aPoolIndex,
                       aPoolCount);
                exit(0);
            }
            mCross[aCrossIndex][aLaneIndex] = mCrossPool[aLaneIndex][aPoolIndex];
        }
    }
}

void Soccer2::InitializeCrossPermutations() {
    for (std::size_t aLaneIndex=0U; aLaneIndex<16U; aLaneIndex++) {
        for (std::size_t aPoolIndex=0U; aPoolIndex<64U; aPoolIndex++) {
            mCrossPermutations[aLaneIndex][aPoolIndex] = aPoolIndex;
        }
    }
}

void Soccer2::BuildCrossPool_WarmUp1(std::size_t pComplexity,
                                     std::size_t pCurrentByteIndex) {
    static_assert((COMPLEXITY_STRONG * 2U) == 32U);

    InitializeCrossPermutations();

    for (std::size_t aLaneIndex=0U; aLaneIndex<pComplexity; aLaneIndex++) {
        mCrossPoolCount[aLaneIndex] = 0U;
        for (std::size_t aPoolIndex=0U; aPoolIndex<64U; aPoolIndex++) {
            mCrossPool[aLaneIndex][aPoolIndex] = nullptr;
        }

        for (std::size_t aMaterialIndex=0U;
             aMaterialIndex<pComplexity;
             aMaterialIndex++) {
            std::uint8_t *aCandidate =
                &mMaterials[aMaterialIndex][pCurrentByteIndex];
            if (aCandidate != mSources[aLaneIndex]) {
                mCrossPool[aLaneIndex][mCrossPoolCount[aLaneIndex]] = aCandidate;
                mCrossPoolCount[aLaneIndex]++;
            }
        }

        mCrossPool[aLaneIndex][mCrossPoolCount[aLaneIndex]] = SOCCER_PRELUDE_RAND;
        mCrossPoolCount[aLaneIndex]++;
    }
}

void Soccer2::BuildCrossPool_WarmUp2(std::size_t pComplexity,
                                     std::size_t pPreviousByteIndex,
                                     std::size_t pCurrentByteIndex) {
    InitializeCrossPermutations();

    for (std::size_t aLaneIndex=0U; aLaneIndex<pComplexity; aLaneIndex++) {
        mCrossPoolCount[aLaneIndex] = 0U;
        for (std::size_t aPoolIndex=0U; aPoolIndex<64U; aPoolIndex++) {
            mCrossPool[aLaneIndex][aPoolIndex] = nullptr;
        }

        for (std::size_t aMaterialIndex=0U;
             aMaterialIndex<pComplexity;
             aMaterialIndex++) {
            mCrossPool[aLaneIndex][mCrossPoolCount[aLaneIndex]] =
                &mMaterials[aMaterialIndex][pPreviousByteIndex];
            mCrossPoolCount[aLaneIndex]++;
        }

        for (std::size_t aMaterialIndex=0U;
             aMaterialIndex<pComplexity;
             aMaterialIndex++) {
            std::uint8_t *aCandidate =
                &mMaterials[aMaterialIndex][pCurrentByteIndex];
            if (aCandidate != mSources[aLaneIndex]) {
                mCrossPool[aLaneIndex][mCrossPoolCount[aLaneIndex]] = aCandidate;
                mCrossPoolCount[aLaneIndex]++;
            }
        }

        mCrossPool[aLaneIndex][mCrossPoolCount[aLaneIndex]] = SOCCER_PRELUDE_RAND;
        mCrossPoolCount[aLaneIndex]++;
    }
}

void Soccer2::BuildCrossPool_WarmUp4(std::size_t pComplexity,
                                     std::size_t pThreeRoundsBackByteIndex,
                                     std::size_t pTwoRoundsBackByteIndex,
                                     std::size_t pOneRoundBackByteIndex) {
    static_assert((COMPLEXITY_STRONG * 4U) == 64U);

    InitializeCrossPermutations();

    for (std::size_t aLaneIndex=0U; aLaneIndex<pComplexity; aLaneIndex++) {
        mCrossPoolCount[aLaneIndex] = 0U;
        for (std::size_t aPoolIndex=0U; aPoolIndex<64U; aPoolIndex++) {
            mCrossPool[aLaneIndex][aPoolIndex] = nullptr;
        }

        for (std::size_t aMaterialIndex=0U;
             aMaterialIndex<pComplexity;
             aMaterialIndex++) {
            if (mSources[aMaterialIndex] != mSources[aLaneIndex]) {
                mCrossPool[aLaneIndex][mCrossPoolCount[aLaneIndex]] =
                    mSources[aMaterialIndex];
                mCrossPoolCount[aLaneIndex]++;
            }
        }

        mCrossPool[aLaneIndex][mCrossPoolCount[aLaneIndex]] = SOCCER_PRELUDE_RAND;
        mCrossPoolCount[aLaneIndex]++;

        for (std::size_t aMaterialIndex=0U; aMaterialIndex<pComplexity; aMaterialIndex++) {
            mCrossPool[aLaneIndex][mCrossPoolCount[aLaneIndex]] = &mMaterials[aMaterialIndex][pThreeRoundsBackByteIndex];
            mCrossPoolCount[aLaneIndex]++;
        }

        for (std::size_t aMaterialIndex=0U; aMaterialIndex<pComplexity; aMaterialIndex++) {
            mCrossPool[aLaneIndex][mCrossPoolCount[aLaneIndex]] = &mMaterials[aMaterialIndex][pTwoRoundsBackByteIndex];
            mCrossPoolCount[aLaneIndex]++;
        }

        for (std::size_t aMaterialIndex=0U; aMaterialIndex<pComplexity; aMaterialIndex++) {
            mCrossPool[aLaneIndex][mCrossPoolCount[aLaneIndex]] = &mMaterials[aMaterialIndex][pOneRoundBackByteIndex];
            mCrossPoolCount[aLaneIndex]++;
        }
    }
}

void Soccer2::BuildCrossPool_Regular(std::size_t pComplexity,
                                     std::size_t pFourRoundsBackByteIndex,
                                     std::size_t pThreeRoundsBackByteIndex,
                                     std::size_t pTwoRoundsBackByteIndex,
                                     std::size_t pOneRoundBackByteIndex) {
    static_assert((COMPLEXITY_STRONG * 4U) == 64U);

    InitializeCrossPermutations();

    for (std::size_t aLaneIndex=0U; aLaneIndex<pComplexity; aLaneIndex++) {
        mCrossPoolCount[aLaneIndex] = 0U;
        for (std::size_t aPoolIndex=0U; aPoolIndex<64U; aPoolIndex++) {
            mCrossPool[aLaneIndex][aPoolIndex] = nullptr;
        }
        
        for (std::size_t aMaterialIndex=0U; aMaterialIndex<pComplexity; aMaterialIndex++) {
            if (mSources[aMaterialIndex] != mSources[aLaneIndex]) {
                mCrossPool[aLaneIndex][mCrossPoolCount[aLaneIndex]] =
                    mSources[aMaterialIndex];
                mCrossPoolCount[aLaneIndex]++;
            }
        }

        mCrossPool[aLaneIndex][mCrossPoolCount[aLaneIndex]] = &mMaterials[aLaneIndex][pFourRoundsBackByteIndex];
        mCrossPoolCount[aLaneIndex]++;

        for (std::size_t aMaterialIndex=0U; aMaterialIndex<pComplexity; aMaterialIndex++) {
            mCrossPool[aLaneIndex][mCrossPoolCount[aLaneIndex]] = &mMaterials[aMaterialIndex][pThreeRoundsBackByteIndex];
            mCrossPoolCount[aLaneIndex]++;
        }

        for (std::size_t aMaterialIndex=0U; aMaterialIndex<pComplexity; aMaterialIndex++) {
            mCrossPool[aLaneIndex][mCrossPoolCount[aLaneIndex]] = &mMaterials[aMaterialIndex][pTwoRoundsBackByteIndex];
            mCrossPoolCount[aLaneIndex]++;
        }

        for (std::size_t aMaterialIndex=0U; aMaterialIndex<pComplexity; aMaterialIndex++) {
            mCrossPool[aLaneIndex][mCrossPoolCount[aLaneIndex]] = &mMaterials[aMaterialIndex][pOneRoundBackByteIndex];
            mCrossPoolCount[aLaneIndex]++;
        }
    }
}

bool Soccer2::SeedPrologue_Regular_C(std::uint32_t *pAckWord,
                             bool pForwardDeploy,
                                     MUTABLE_PARAMS) {
    
    std::size_t aComplexity = COMPLEXITY_NORMAL;
    if (mStrength == EncryptionStrength::kWeak) {
        aComplexity = COMPLEXITY_WEAK;
    } else if (mStrength == EncryptionStrength::kStrong) {
        aComplexity = COMPLEXITY_STRONG;
    }

    static_assert(WARM_UP_ROUNDS == 5U);
    static_assert(WARM_UP_BLOCKS == 6U);
    const std::size_t aWarmUpSeedBlockIndex = BLOCK_COUNT - WARM_UP_BLOCKS;
    const std::size_t aWarmUpSeedByteIndex = aWarmUpSeedBlockIndex * S_BLOCK;
    const std::size_t aWarmUp1ByteIndex = (aWarmUpSeedBlockIndex + 1U) * S_BLOCK;
    const std::size_t aWarmUp2ByteIndex = (aWarmUpSeedBlockIndex + 2U) * S_BLOCK;
    const std::size_t aWarmUp3ByteIndex = (aWarmUpSeedBlockIndex + 3U) * S_BLOCK;
    
    READ_IN_MUTABLE_PARAMS_INTERNAL;

    Shuffle_CROWSCIMASSORMATEX();

    BuildCrossPool_WarmUp1(aComplexity, aWarmUpSeedByteIndex);
    Shuffle_CROSSPERMUTATIONS(mCrossPoolCount[0]);
    ArrangeCrossPool(aComplexity);
    TwistRound(aWarmUpSeedBlockIndex + 1U, true, ARX_STATE_VARS);

    BuildCrossPool_WarmUp2(aComplexity,
                           aWarmUpSeedByteIndex,
                           aWarmUp1ByteIndex);
    Shuffle_CROSSPERMUTATIONS(mCrossPoolCount[0]);
    ArrangeCrossPool(aComplexity);
    TwistRound(aWarmUpSeedBlockIndex + 2U, true, ARX_STATE_VARS);

    BuildCrossPool_WarmUp2(aComplexity,
                           aWarmUp1ByteIndex,
                           aWarmUp2ByteIndex);
    Shuffle_CROSSPERMUTATIONS(mCrossPoolCount[0]);
    ArrangeCrossPool(aComplexity);
    TwistRound(aWarmUpSeedBlockIndex + 3U, true, ARX_STATE_VARS);

    BuildCrossPool_WarmUp4(aComplexity,
                           aWarmUpSeedByteIndex,
                           aWarmUp1ByteIndex,
                           aWarmUp2ByteIndex);
    Shuffle_CROSSPERMUTATIONS(mCrossPoolCount[0]);
    ArrangeCrossPool(aComplexity);
    TwistRound(aWarmUpSeedBlockIndex + 4U, true, ARX_STATE_VARS);

    BuildCrossPool_Regular(aComplexity,
                           aWarmUpSeedByteIndex,
                           aWarmUp1ByteIndex,
                           aWarmUp2ByteIndex,
                           aWarmUp3ByteIndex);
    Shuffle_CROSSPERMUTATIONS(mCrossPoolCount[0]);
    ArrangeCrossPool(aComplexity);
    TwistRound(aWarmUpSeedBlockIndex + 5U, true, ARX_STATE_VARS);
    
    WRITE_OUT_MUTABLE_PARAMS;

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

void Soccer2::SeedPrologue_Regular_D(MUTABLE_PARAMS) {
    std::size_t aComplexity = COMPLEXITY_NORMAL;
    if (mStrength == EncryptionStrength::kWeak) {
        aComplexity = COMPLEXITY_WEAK;
    } else if (mStrength == EncryptionStrength::kStrong) {
        aComplexity = COMPLEXITY_STRONG;
    }
    
    READ_IN_MUTABLE_PARAMS_INTERNAL;

    for (std::size_t aRoundIndex=0U; aRoundIndex<BLOCK_COUNT; aRoundIndex++) {
        const std::size_t aFourRoundsBackBlockIndex = (aRoundIndex + BLOCK_COUNT - 5U) % BLOCK_COUNT;
        const std::size_t aThreeRoundsBackBlockIndex = (aRoundIndex + BLOCK_COUNT - 4U) % BLOCK_COUNT;
        const std::size_t aTwoRoundsBackBlockIndex = (aRoundIndex + BLOCK_COUNT - 3U) % BLOCK_COUNT;
        const std::size_t aOneRoundBackBlockIndex = (aRoundIndex + BLOCK_COUNT - 2U) % BLOCK_COUNT;
        BuildCrossPool_Regular(aComplexity,
                               aFourRoundsBackBlockIndex * S_BLOCK,
                               aThreeRoundsBackBlockIndex * S_BLOCK,
                               aTwoRoundsBackBlockIndex * S_BLOCK,
                               aOneRoundBackBlockIndex * S_BLOCK);
        Shuffle_CROSSPERMUTATIONS(mCrossPoolCount[0]);
        ArrangeCrossPool(aComplexity);
        TwistRound(aRoundIndex, false, ARX_STATE_VARS);
    }
    
    WRITE_OUT_MUTABLE_PARAMS;
    
    /*
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

    for (std::size_t aIndex=0U; aIndex<SOCCER_EXPANDER_COUNT; aIndex++) {
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

    for (std::size_t aLaneIndex=0U; aLaneIndex<16U; aLaneIndex++) {
        mCrossPoolCount[aLaneIndex] = 0U;
        for (std::size_t aPoolIndex=0U; aPoolIndex<64U; aPoolIndex++) {
            mCrossPool[aLaneIndex][aPoolIndex] = nullptr;
            mCrossPermutations[aLaneIndex][aPoolIndex] = 0U;
        }
    }

    mClaimedExpanderCount = 0U;
    mClaimedMaterialCount = 0U;
    mClaimedWorkSpaceCount = 0U;
    */
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
        const std::uint8_t aCrushA = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aCrushIngressA));

        const std::uint32_t aCrushIngressB =
            (static_cast<std::uint32_t>(mMaterials[ 4][aMaterialIndex]) <<  0U) |
            (static_cast<std::uint32_t>(mMaterials[ 5][aMaterialIndex]) <<  8U) |
            (static_cast<std::uint32_t>(mMaterials[ 6][aMaterialIndex]) << 16U) |
            (static_cast<std::uint32_t>(mMaterials[ 7][aMaterialIndex]) << 24U);
        const std::uint8_t aCrushB = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aCrushIngressB));

        const std::uint32_t aCrushIngressC =
            (static_cast<std::uint32_t>(mMaterials[ 8][aMaterialIndex]) <<  0U) |
            (static_cast<std::uint32_t>(mMaterials[ 9][aMaterialIndex]) <<  8U) |
            (static_cast<std::uint32_t>(mMaterials[10][aMaterialIndex]) << 16U) |
            (static_cast<std::uint32_t>(mMaterials[11][aMaterialIndex]) << 24U);
        const std::uint8_t aCrushC = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aCrushIngressC));

        const std::uint32_t aCrushIngressD =
            (static_cast<std::uint32_t>(mMaterials[12][aMaterialIndex]) <<  0U) |
            (static_cast<std::uint32_t>(mMaterials[13][aMaterialIndex]) <<  8U) |
            (static_cast<std::uint32_t>(mMaterials[14][aMaterialIndex]) << 16U) |
            (static_cast<std::uint32_t>(mMaterials[15][aMaterialIndex]) << 24U);
        const std::uint8_t aCrushD = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aCrushIngressD));

        const std::uint32_t aRandomIngress =
            (static_cast<std::uint32_t>(aCrushA) <<  0U) |
            (static_cast<std::uint32_t>(aCrushB) <<  8U) |
            (static_cast<std::uint32_t>(aCrushC) << 16U) |
            (static_cast<std::uint32_t>(aCrushD) << 24U);

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
    mCryptex6.Free();
    mCryptex9.Free();
    
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
    
    std::uint64_t aIngress = 0xE025CAEA83AB99CFULL;
    std::uint64_t aCarry = 0x6530BC4A53A443B8ULL;
    std::uint64_t aWandererA = 0x4E06885276D20E3DULL;
    std::uint64_t aWandererB = 0xEBF1E1AB6DF26920ULL;
    std::uint64_t aWandererC = 0x99478E05E833FBB1ULL;
    std::uint64_t aWandererD = 0x73A9F7B5B01778B2ULL;
    std::uint64_t aWandererE = 0xB9AB363EA936D1EDULL;
    std::uint64_t aWandererF = 0x847430D62AD62F79ULL;
    std::uint64_t aWandererG = 0x0D6FE89E3169B0E1ULL;
    std::uint64_t aWandererH = 0xD22934C37E3EE9B7ULL;
    std::uint64_t aWandererI = 0x648E293C4DCD6ED1ULL;
    std::uint64_t aWandererJ = 0xA31C40A884CAD927ULL;
    std::uint64_t aWandererK = 0x183169CC43C8BCE3ULL;
    
    // Chapter I - Prelude
    SeedPrelude_Regular_A(pPassword, pPasswordByteLength, pNonce);
    SeedPrelude_Regular_B(pNonce, ARX_STATE_VARS);
    SeedPrelude_Regular_C();
    
    // Chapter II - Prologue
    SeedPrologue_Regular_A(pPassword, pPasswordByteLength, pNonce, ARX_STATE_VARS);
    SeedPrologue_Regular_B();
    if (!SeedPrologue_Regular_C(pAckWord, true, ARX_STATE_VARS)) {
        return false;
    }
    SeedPrologue_Regular_D(ARX_STATE_VARS);
    
    // Chapter III - Epilogue
    SeedEpilogue_Regular_A();
    SeedEpilogue_Regular_B();
    SeedEpilogue_Regular_C();
    if (!SeedEpilogue_Regular_D()) {
        return false;
    }
    
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
    mCryptex6.Free();
    mCryptex9.Free();
    
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
    
    std::uint64_t aIngress = 0xE025CAEA83AB99CFULL;
    std::uint64_t aCarry = 0x6530BC4A53A443B8ULL;
    std::uint64_t aWandererA = 0x4E06885276D20E3DULL;
    std::uint64_t aWandererB = 0xEBF1E1AB6DF26920ULL;
    std::uint64_t aWandererC = 0x99478E05E833FBB1ULL;
    std::uint64_t aWandererD = 0x73A9F7B5B01778B2ULL;
    std::uint64_t aWandererE = 0xB9AB363EA936D1EDULL;
    std::uint64_t aWandererF = 0x847430D62AD62F79ULL;
    std::uint64_t aWandererG = 0x0D6FE89E3169B0E1ULL;
    std::uint64_t aWandererH = 0xD22934C37E3EE9B7ULL;
    std::uint64_t aWandererI = 0x648E293C4DCD6ED1ULL;
    std::uint64_t aWandererJ = 0xA31C40A884CAD927ULL;
    std::uint64_t aWandererK = 0x183169CC43C8BCE3ULL;
    
    // Chapter I - Prelude
    SeedPrelude_Regular_A(pPassword, pPasswordByteLength, pNonce);
    SeedPrelude_Regular_B(pNonce, ARX_STATE_VARS);
    SeedPrelude_Regular_C();
    
    // Chapter II - Prologue
    std::uint32_t aAckWord = pAckWord;
    SeedPrologue_Regular_A(pPassword, pPasswordByteLength, pNonce, ARX_STATE_VARS);
    SeedPrologue_Regular_B();
    if (!SeedPrologue_Regular_C(&aAckWord, false, ARX_STATE_VARS)) {
        return false;
    }
    SeedPrologue_Regular_D(ARX_STATE_VARS);
    
    // Chapter III - Epilogue
    SeedEpilogue_Regular_A();
    SeedEpilogue_Regular_B();
    SeedEpilogue_Regular_C();
    if (!SeedEpilogue_Regular_D()) {
        return false;
    }
    
    return true;
}

void Soccer2::ConfigureTestBuffers(std::uint32_t pTestBlockLength) {
    mTestBlockLength = pTestBlockLength;
}

bool Soccer2::EncryptBlock(std::uint8_t *pSource,
                           std::uint8_t *pDestination) {
    if ((pSource == nullptr) || (pDestination == nullptr)) {
        return false;
    }

    if (mStrength == EncryptionStrength::kTest) {
        for (std::size_t aIndex=0; aIndex<mTestBlockLength; aIndex++) {
            pDestination[aIndex] = pSource[aIndex] ^ mMaterialA[aIndex];
        }
        return true;
    }

    CipherErrorCode aErrorCode = CipherErrorCode::kNone;
    bool aSuccess = false;
    if (mStrength == EncryptionStrength::kWeak) {
        aSuccess = mCryptex6.SealData(pSource,
                                      SOCCER_SCRATCH_WORKER_A,
                                      SOCCER_WORKER_B,
                                      pDestination,
                                      SOCCER_BLOCK_SIZE,
                                      &aErrorCode);
    } else if (mStrength == EncryptionStrength::kStrong) {
        aSuccess = mCryptex9.SealData(pSource,
                                      SOCCER_SCRATCH_WORKER_A,
                                      SOCCER_WORKER_B,
                                      pDestination,
                                      SOCCER_BLOCK_SIZE,
                                      &aErrorCode);
    } else {
        aSuccess = mCryptex6.SealData(pSource,
                                      SOCCER_SCRATCH_WORKER_A,
                                      SOCCER_WORKER_B,
                                      pDestination,
                                      SOCCER_BLOCK_SIZE,
                                      &aErrorCode);
    }
    if (!aSuccess) {
        printf("Soccer2::EncryptBlock failed with cipher error %u.\n",
               static_cast<std::uint32_t>(aErrorCode));
    }
    return aSuccess;
}

bool Soccer2::DecryptBlock(std::uint8_t *pSource,
                           std::uint8_t *pDestination) {
    if ((pSource == nullptr) || (pDestination == nullptr)) {
        return false;
    }

    if (mStrength == EncryptionStrength::kTest) {
        for (std::size_t aIndex=0; aIndex<mTestBlockLength; aIndex++) {
            pDestination[aIndex] = pSource[aIndex] ^ mMaterialA[aIndex];
        }
        return true;
    }

    CipherErrorCode aErrorCode = CipherErrorCode::kNone;
    bool aSuccess = false;
    if (mStrength == EncryptionStrength::kWeak) {
        aSuccess = mCryptex6.UnsealData(pSource,
                                        SOCCER_SCRATCH_WORKER_A,
                                        SOCCER_WORKER_B,
                                        pDestination,
                                        SOCCER_BLOCK_SIZE,
                                        &aErrorCode);
    } else if (mStrength == EncryptionStrength::kStrong) {
        aSuccess = mCryptex9.UnsealData(pSource,
                                        SOCCER_SCRATCH_WORKER_A,
                                        SOCCER_WORKER_B,
                                        pDestination,
                                        SOCCER_BLOCK_SIZE,
                                        &aErrorCode);
    } else {
        aSuccess = mCryptex6.UnsealData(pSource,
                                        SOCCER_SCRATCH_WORKER_A,
                                        SOCCER_WORKER_B,
                                        pDestination,
                                        SOCCER_BLOCK_SIZE,
                                        &aErrorCode);
    }
    if (!aSuccess) {
        printf("Soccer2::DecryptBlock failed with cipher error %u.\n",
               static_cast<std::uint32_t>(aErrorCode));
    }
    return aSuccess;
}

bool Soccer2::SeedPrelude_Test(std::uint8_t *pPassword,
                               std::size_t pPasswordByteLength,
                               std::uint64_t pNonce) {
    
    UnrollNonceAndPasswordToScratch_Test(pPassword, pPasswordByteLength, pNonce);
    
    std::uint64_t aValue = 0x00;
    for (std::size_t aIndex=0; aIndex<SOCCER_BLOCK_SIZE; aIndex++) {
        aValue = RotL64(aValue, 3);
        aValue ^= static_cast<std::uint64_t>(SOCCER_SCRATCH_WORKER_A[aIndex]);
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
    InitializeCiphers();
    
    memset(mClaimedExpanders, 0, sizeof(mClaimedExpanders));
    mClaimedExpanderCount = 0;
    
    memset(mClaimedMaterials, 0, sizeof(mClaimedMaterials));
    mClaimedMaterialCount = 0;
    
    memset(mClaimedWorkSpaces, 0, sizeof(mClaimedWorkSpaces));
    mClaimedWorkSpaceCount = 0;
    
    UnrollNonceAndPasswordToScratch_Regular(pPassword, pPasswordByteLength, pNonce);
}

void Soccer2::SeedPrelude_Regular_B(std::uint64_t pNonce, MUTABLE_PARAMS) {
    
    READ_IN_MUTABLE_PARAMS_INTERNAL;
    
    mStarter.Seed(&mWorkSpaceA, pNonce, SOCCER_SCRATCH_WORKER_A, S_BLOCK, mCollapseLaneB, ARX_STATE_VARS);
    
    WRITE_OUT_MUTABLE_PARAMS;
}

void Soccer2::SeedPrelude_Regular_C() {
    TwistShuffle::ShuffleList256(mCiphers,      SOCCER_PRELUDE_RAND,     0,  4096, 4);
    TwistShuffle::ShuffleList16(mExpanders,     SOCCER_PRELUDE_RAND,  4096,  8192, 4);
    TwistShuffle::ShuffleList16(mWorkSpaces,    SOCCER_PRELUDE_RAND,  8192, 12288, 4);
    TwistShuffle::ShuffleList16(mMaterials,     SOCCER_PRELUDE_RAND, 12288, 16384, 4);
    
    TwistShuffle::ShuffleList256(mCiphers,      SOCCER_PRELUDE_RAND, 16384, 20480, 4);
    TwistShuffle::ShuffleList16(mExpanders,     SOCCER_PRELUDE_RAND, 20480, 24576, 4);
    TwistShuffle::ShuffleList16(mWorkSpaces,    SOCCER_PRELUDE_RAND, 24576, 28672, 4);
    TwistShuffle::ShuffleList16(mMaterials,     SOCCER_PRELUDE_RAND, 28672, 32768, 4);
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
        SoccerFolding::Collapse_Stage3_Outer_16(mMaterials[0], mMaterials[1], mMaterials[2], mMaterials[3],
                                                mMaterials[4], mMaterials[5], mMaterials[6], mMaterials[7],
                                                mMaterials[8], mMaterials[9], mMaterials[10], mMaterials[11],
                                                mMaterials[12], mMaterials[13], mMaterials[14], mMaterials[15],
                                                mCollapseLaneA, mCollapseLaneB, mCollapseLaneC, mCollapseLaneD);
        
        aShrinkSourceA = mCollapseLaneA;
        aShrinkSourceB = mCollapseLaneB;
        aShrinkSourceC = mCollapseLaneC;
        aShrinkSourceD = mCollapseLaneD;
    } else {
        SoccerFolding::Collapse_Stage3_Outer_8(mMaterials[0], mMaterials[1], mMaterials[2], mMaterials[3],
                                               mMaterials[4], mMaterials[5], mMaterials[6], mMaterials[7],
                                               mCollapseLaneA, mCollapseLaneB, mCollapseLaneC, mCollapseLaneD);
        
        aShrinkSourceA = mCollapseLaneA;
        aShrinkSourceB = mCollapseLaneB;
        aShrinkSourceC = mCollapseLaneC;
        aShrinkSourceD = mCollapseLaneD;
    }
    
    SoccerFolding::Collapse_Stage2_4(aShrinkSourceA, aShrinkSourceB, aShrinkSourceC, aShrinkSourceD,
                                     mCondenseLaneA, mCondenseLaneB, mCondenseLaneC, mCondenseLaneD);
    
    // Shrink has consumed the collapse lanes, so alternate back into them.
    SoccerFolding::Collapse_Stage1_4(mCondenseLaneA, mCondenseLaneB, mCondenseLaneC, mCondenseLaneD,
                                     mCollapseLaneA, mCollapseLaneB, mCollapseLaneC, mCollapseLaneD);
    
    // Compress has consumed the shrink lanes; they now hold the final crush material.
    SoccerFolding::Collapse_Stage0_4(mCollapseLaneA, mCollapseLaneB, mCollapseLaneC, mCollapseLaneD,
                                     mCondenseLaneA, mCondenseLaneB, mCondenseLaneC, mCondenseLaneD);
    
    mMaterialIndex = 0;
    mMaterialQuarter = 0;
    
    mMaskCursor = 0;
}

void Soccer2::SeedEpilogue_Regular_B() {
    
    for (std::size_t aIndex=0; aIndex<2048U; aIndex++) { mIndexListA[aIndex] = aIndex; }
    for (std::size_t aIndex=0; aIndex<2048U; aIndex++) { mIndexListB[aIndex] = aIndex; }
    
    constexpr std::size_t aShuffleSpanByteCount = 256U;
    static_assert((SOCCER_BLOCK_SIZE_C1 % aShuffleSpanByteCount) == 0U);
    static_assert((aShuffleSpanByteCount % sizeof(std::uint32_t)) == 0U);
    
    constexpr std::size_t aIndexShuffleSpanStartBlockIndex = 0U;
    constexpr std::size_t aIndexShuffleSpanEndBlockIndex = 35U;
    
    constexpr std::size_t aPremiumShuffleSpanStartBlockIndex = 36U;
    constexpr std::size_t aPremiumShuffleSpanEndBlockIndex = 47U;
    
    constexpr std::size_t aShuffleSpanBlockCount = SOCCER_BLOCK_SIZE_C1 / aShuffleSpanByteCount;
    static_assert(aShuffleSpanBlockCount == 64U);
    static_assert(aIndexShuffleSpanStartBlockIndex == 0U);
    static_assert((aIndexShuffleSpanEndBlockIndex + 1U) ==
                  aPremiumShuffleSpanStartBlockIndex);
    static_assert((aPremiumShuffleSpanEndBlockIndex + 1U) == 48U);
    static_assert(aPremiumShuffleSpanEndBlockIndex < aShuffleSpanBlockCount);
    
    for (std::size_t aSpanIndex=aIndexShuffleSpanStartBlockIndex;
         aSpanIndex<=aIndexShuffleSpanEndBlockIndex;
         aSpanIndex++) {
        std::size_t *aIndexList = ((aSpanIndex & 1U) == 0U) ? mIndexListA : mIndexListB;
        const std::size_t aStartIndex = aSpanIndex * aShuffleSpanByteCount;
        const std::size_t aCeilingIndex = aStartIndex + aShuffleSpanByteCount;
        
        for (std::size_t aIndex=aStartIndex; aIndex<aCeilingIndex; aIndex+=4U) {
            const std::uint32_t aShuffleWord = TwistMix32::DiffuseA(Load32LE(&mCondenseLaneC[aIndex]));
            const std::size_t aSwapIndexA = static_cast<std::size_t>(aShuffleWord & 2047U);
            const std::size_t aSwapIndexB = static_cast<std::size_t>((aShuffleWord >> 11U) & 2047U);
            
            const std::size_t aHold = aIndexList[aSwapIndexA];
            aIndexList[aSwapIndexA] = aIndexList[aSwapIndexB];
            aIndexList[aSwapIndexB] = aHold;
        }
    }
    
    for (std::size_t aSpanIndex=aIndexShuffleSpanStartBlockIndex;
         aSpanIndex<=aIndexShuffleSpanEndBlockIndex;
         aSpanIndex++) {
        std::size_t *aIndexList = ((aSpanIndex & 1U) == 0U) ? mIndexListB : mIndexListA;
        const std::size_t aStartIndex = aSpanIndex * aShuffleSpanByteCount;
        const std::size_t aCeilingIndex = aStartIndex + aShuffleSpanByteCount;
        
        for (std::size_t aIndex=aStartIndex; aIndex<aCeilingIndex; aIndex+=4U) {
            const std::uint32_t aShuffleWord = TwistMix32::DiffuseA(Load32LE(&mCondenseLaneD[aIndex]));
            const std::size_t aSwapIndexA = static_cast<std::size_t>(aShuffleWord & 2047U);
            const std::size_t aSwapIndexB = static_cast<std::size_t>((aShuffleWord >> 11U) & 2047U);
            
            const std::size_t aHold = aIndexList[aSwapIndexA];
            aIndexList[aSwapIndexA] = aIndexList[aSwapIndexB];
            aIndexList[aSwapIndexB] = aHold;
        }
    }
    
    static_assert(SOCCER_BLOCK_SIZE_C1 == (2048U * sizeof(std::uint64_t)));
    
    for (std::size_t aRolledIndex=0U; aRolledIndex<128U; aRolledIndex++) {
        const std::size_t aIndex = aRolledIndex * 16U;
        std::uint64_t aFold = 0ULL;
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneA[mIndexListA[aIndex + 0U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneA[mIndexListA[aIndex + 1U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneA[mIndexListA[aIndex + 2U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneA[mIndexListA[aIndex + 3U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneA[mIndexListA[aIndex + 4U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneA[mIndexListA[aIndex + 5U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneA[mIndexListA[aIndex + 6U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneA[mIndexListA[aIndex + 7U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneA[mIndexListA[aIndex + 8U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneA[mIndexListA[aIndex + 9U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneA[mIndexListA[aIndex + 10U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneA[mIndexListA[aIndex + 11U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneA[mIndexListA[aIndex + 12U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneA[mIndexListA[aIndex + 13U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneA[mIndexListA[aIndex + 14U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneA[mIndexListA[aIndex + 15U] * 8U]));
        mPremiumSeed[aRolledIndex * 2 + 0] = aFold;
    }
    
    for (std::size_t aRolledIndex=0U; aRolledIndex<128U; aRolledIndex++) {
        const std::size_t aIndex = aRolledIndex * 16U;
        std::uint64_t aFold = 0ULL;
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneB[mIndexListB[aIndex + 0U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneB[mIndexListB[aIndex + 1U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneB[mIndexListB[aIndex + 2U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneB[mIndexListB[aIndex + 3U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneB[mIndexListB[aIndex + 4U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneB[mIndexListB[aIndex + 5U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneB[mIndexListB[aIndex + 6U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneB[mIndexListB[aIndex + 7U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneB[mIndexListB[aIndex + 8U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneB[mIndexListB[aIndex + 9U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneB[mIndexListB[aIndex + 10U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneB[mIndexListB[aIndex + 11U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneB[mIndexListB[aIndex + 12U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneB[mIndexListB[aIndex + 13U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneB[mIndexListB[aIndex + 14U] * 8U]));
        aFold = TwistMix64::DiffuseA(aFold ^ Load64LE(&mCondenseLaneB[mIndexListB[aIndex + 15U] * 8U]));
        mPremiumSeed[aRolledIndex * 2 + 1] = aFold;
    }
    
    static_assert((sizeof(mPremiumSeed) / sizeof(mPremiumSeed[0])) == 256U);
    
    for (std::size_t aSpanIndex=aPremiumShuffleSpanStartBlockIndex;
         aSpanIndex<=aPremiumShuffleSpanEndBlockIndex;
         aSpanIndex++) {
        const std::size_t aStartIndex = aSpanIndex * aShuffleSpanByteCount;
        const std::size_t aCeilingIndex = aStartIndex + aShuffleSpanByteCount;
        
        for (std::size_t aIndex=aStartIndex; aIndex<aCeilingIndex; aIndex+=4U) {
            const std::uint32_t aShuffleWord = TwistMix32::DiffuseA(Load32LE(&mCondenseLaneC[aIndex]));
            const std::size_t aSwapIndexA = static_cast<std::size_t>(aShuffleWord & 255U);
            const std::size_t aSwapIndexB = static_cast<std::size_t>((aShuffleWord >> 8U) & 255U);
            
            const std::uint64_t aHold = mPremiumSeed[aSwapIndexA];
            mPremiumSeed[aSwapIndexA] = mPremiumSeed[aSwapIndexB];
            mPremiumSeed[aSwapIndexB] = aHold;
        }
    }
    
    for (std::size_t aSpanIndex=aPremiumShuffleSpanStartBlockIndex;
         aSpanIndex<=aPremiumShuffleSpanEndBlockIndex;
         aSpanIndex++) {
        const std::size_t aStartIndex = aSpanIndex * aShuffleSpanByteCount;
        const std::size_t aCeilingIndex = aStartIndex + aShuffleSpanByteCount;
        
        for (std::size_t aIndex=aStartIndex; aIndex<aCeilingIndex; aIndex+=4U) {
            const std::uint32_t aShuffleWord = TwistMix32::DiffuseA(Load32LE(&mCondenseLaneD[aIndex]));
            const std::size_t aSwapIndexA = static_cast<std::size_t>(aShuffleWord & 255U);
            const std::size_t aSwapIndexB = static_cast<std::size_t>((aShuffleWord >> 8U) & 255U);
            
            const std::uint64_t aHold = mPremiumSeed[aSwapIndexA];
            mPremiumSeed[aSwapIndexA] = mPremiumSeed[aSwapIndexB];
            mPremiumSeed[aSwapIndexB] = aHold;
        }
    }
}

void Soccer2::SeedEpilogue_Regular_C() {
    
    constexpr std::size_t aMaskShuffleSpanStartBlockIndex = 48U;
    constexpr std::size_t aMaskShuffleSpanEndBlockIndex = 55U;
    
    constexpr std::size_t aMaterialShuffleSpanStartBlockIndex = 56U;
    constexpr std::size_t aMaterialShuffleSpanEndBlockIndex = 63U;
    
    constexpr std::size_t kWordsForMask = 8U;
    
    constexpr std::uint64_t kRotationFloorL1 = 1ULL;
    constexpr std::uint64_t kRotationFloorL2 = SOCCER_BLOCK_SIZE_L1 + 1ULL;
    constexpr std::uint64_t kRotationFloorL3 = SOCCER_BLOCK_SIZE_L2 + 1ULL;

    constexpr std::uint64_t kRotationRangeL1 = SOCCER_BLOCK_SIZE_L1 - 1ULL;
    constexpr std::uint64_t kRotationRangeL2 = SOCCER_BLOCK_SIZE_L1 - 1ULL;
    constexpr std::uint64_t kRotationRangeL3 = SOCCER_BLOCK_SIZE_L2 - 1ULL;
    
    constexpr std::size_t kWordsPerRotation = 8U;
    constexpr std::size_t kRotationCountPerLayer = 3U;
    constexpr std::size_t kRotationLayerCount = 3U;
    constexpr std::size_t kRotationWordCount =
        kWordsPerRotation * kRotationCountPerLayer * kRotationLayerCount;
    static_assert((kRotationWordCount + SoccerMaskBank::mMaskGridWidth) <=
                  (sizeof(mPremiumSeed) / sizeof(mPremiumSeed[0])));
    
    std::size_t aPremiumIndex = 0U;
    for (std::size_t aRotationPlane=0U; aRotationPlane<kRotationCountPerLayer; aRotationPlane++) {
        for (std::size_t aRotationLayer=0U; aRotationLayer<kRotationLayerCount; aRotationLayer++) {
            
            std::uint64_t aWord = 0ULL;
            for (std::size_t aLoop=0U; aLoop<kWordsPerRotation; aLoop++) {
                const std::uint64_t aDiffused = TwistMix64::DiffuseA(mPremiumSeed[aPremiumIndex++]);
                const std::uint64_t aLowByte = aDiffused & 0xFFULL;
                aWord |= aLowByte << (aLoop * 8U);
            }

            if (aRotationLayer == 0U) {
                mRotationsL3[aRotationPlane] = static_cast<std::int32_t>(kRotationFloorL3 + (aWord % kRotationRangeL3));
            } else if (aRotationLayer == 1U) {
                mRotationsL2[aRotationPlane] = static_cast<std::int32_t>(kRotationFloorL2 + (aWord % kRotationRangeL2));
            } else {
                mRotationsL1[aRotationPlane] = static_cast<std::int32_t>(kRotationFloorL1 + (aWord % kRotationRangeL1));
            }
        }
    }
    
    // aPremiumIndex == 72
    
    std::uint64_t aMaskListIndexLong = 0ULL;
    for (std::size_t aLoop=0U; aLoop<kWordsForMask; aLoop++) {
        const std::uint64_t aDiffused = TwistMix64::DiffuseA(mPremiumSeed[aPremiumIndex++]);
        const std::uint64_t aLowByte = aDiffused & 0xFFULL;
        aMaskListIndexLong |= aLowByte << (aLoop * 8U);
    }
    
    std::size_t aMaskListIndex = static_cast<std::size_t>(aMaskListIndexLong % SoccerMaskBank::mMaskGridHeight);
    for (std::size_t aMaskIndex=0U; aMaskIndex<SoccerMaskBank::mMaskGridWidth; aMaskIndex++) {
        mMasks[aMaskIndex] = SoccerMaskBank::mMaskGrid[aMaskListIndex][aMaskIndex];
    }
    
    // aPremiumIndex == 80
    
    constexpr std::size_t kPremiumMaterialShuffleEndIndex = 160U;
    constexpr std::size_t kPremiumMaterialReverseEndIndex = 168U;
    constexpr std::size_t kPremiumSeedCount = sizeof(mPremiumSeed) / sizeof(mPremiumSeed[0]);
    
    static_assert(kRotationWordCount + kWordsForMask == 80U);
    static_assert(kPremiumMaterialReverseEndIndex -
                  kPremiumMaterialShuffleEndIndex == 8U);
    static_assert(kPremiumMaterialReverseEndIndex < kPremiumSeedCount);
    static_assert(kPremiumSeedCount == 256U);

    std::size_t aMaterialCount = 8U;
    if (mStrength == EncryptionStrength::kWeak) {
        aMaterialCount = 4U;
    } else if (mStrength == EncryptionStrength::kStrong) {
        aMaterialCount = 16U;
    }
    const std::size_t aMaterialIndexMask = aMaterialCount - 1U;

    for (; aPremiumIndex<kPremiumMaterialShuffleEndIndex; aPremiumIndex++) {
        const std::uint64_t aShuffleWord = mPremiumSeed[aPremiumIndex];
        const std::size_t aSwapIndexA = static_cast<std::size_t>(static_cast<std::uint32_t>(aShuffleWord)) & aMaterialIndexMask;
        const std::size_t aSwapIndexB = static_cast<std::size_t>(static_cast<std::uint32_t>(aShuffleWord >> 32U)) & aMaterialIndexMask;

        std::uint8_t *aHold = mMaterials[aSwapIndexA];
        mMaterials[aSwapIndexA] = mMaterials[aSwapIndexB];
        mMaterials[aSwapIndexB] = aHold;
    }

    std::size_t aMaterialReverseCount = 4U;
    if (mStrength == EncryptionStrength::kWeak) {
        aMaterialReverseCount = 2U;
    } else if (mStrength == EncryptionStrength::kStrong) {
        aMaterialReverseCount = 8U;
    }

    bool aReverseMaterial[16] = {};
    for (std::size_t aReverseSeedIndex=0U; aPremiumIndex<kPremiumMaterialReverseEndIndex; aPremiumIndex++, aReverseSeedIndex++) {
        if (aReverseSeedIndex < aMaterialReverseCount) {
            const std::size_t aMaterialIndex = static_cast<std::size_t>(mPremiumSeed[aPremiumIndex]) & aMaterialIndexMask;
            aReverseMaterial[aMaterialIndex] = true;
        }
    }

    for (; aPremiumIndex<kPremiumSeedCount; aPremiumIndex++) {
        const std::uint64_t aShuffleWord = mPremiumSeed[aPremiumIndex];
        const std::size_t aSwapIndexA = static_cast<std::size_t>(static_cast<std::uint32_t>(aShuffleWord)) % SoccerMaskBank::mMaskGridWidth;
        const std::size_t aSwapIndexB = static_cast<std::size_t>(static_cast<std::uint32_t>(aShuffleWord >> 32U)) % SoccerMaskBank::mMaskGridWidth;

        std::uint8_t aHold = mMasks[aSwapIndexA];
        mMasks[aSwapIndexA] = mMasks[aSwapIndexB];
        mMasks[aSwapIndexB] = aHold;
    }

    for (std::size_t aMaterialIndex=0U; aMaterialIndex<aMaterialCount; aMaterialIndex++) {
        if (aReverseMaterial[aMaterialIndex]) {
            std::reverse(mMaterials[aMaterialIndex], mMaterials[aMaterialIndex] + SOCCER_BLOCK_SIZE);
        }
    }

    constexpr std::size_t aShuffleSpanByteCount = 256U;
    static_assert(aMaskShuffleSpanEndBlockIndex + 1U == aMaterialShuffleSpanStartBlockIndex);
    static_assert((aMaterialShuffleSpanEndBlockIndex + 1U) * aShuffleSpanByteCount == SOCCER_BLOCK_SIZE_C1);
    static_assert((aShuffleSpanByteCount % sizeof(std::uint64_t)) == 0U);
    
    for (std::size_t aSpanIndex=aMaterialShuffleSpanStartBlockIndex;
         aSpanIndex<=aMaterialShuffleSpanEndBlockIndex;
         aSpanIndex++) {
        const std::size_t aStartIndex = aSpanIndex * aShuffleSpanByteCount;
        const std::size_t aCeilingIndex = aStartIndex + aShuffleSpanByteCount;

        for (std::size_t aIndex=aStartIndex; aIndex<aCeilingIndex; aIndex+=8U) {
            const std::uint64_t aShuffleWord = TwistMix64::DiffuseA(Load64LE(&mCondenseLaneC[aIndex]));
            const std::size_t aSwapIndexA = static_cast<std::size_t>(static_cast<std::uint32_t>(aShuffleWord)) & aMaterialIndexMask;
            const std::size_t aSwapIndexB = static_cast<std::size_t>(static_cast<std::uint32_t>(aShuffleWord >> 32U)) & aMaterialIndexMask;

            std::uint8_t *aHold = mMaterials[aSwapIndexA];
            mMaterials[aSwapIndexA] = mMaterials[aSwapIndexB];
            mMaterials[aSwapIndexB] = aHold;
        }
    }

    for (std::size_t aSpanIndex=aMaterialShuffleSpanStartBlockIndex;
         aSpanIndex<=aMaterialShuffleSpanEndBlockIndex;
         aSpanIndex++) {
        const std::size_t aStartIndex = aSpanIndex * aShuffleSpanByteCount;
        const std::size_t aCeilingIndex = aStartIndex + aShuffleSpanByteCount;
        
        for (std::size_t aIndex=aStartIndex; aIndex<aCeilingIndex; aIndex+=8U) {
            const std::uint64_t aShuffleWord = TwistMix64::DiffuseA(Load64LE(&mCondenseLaneD[aIndex]));
            const std::size_t aSwapIndexA = static_cast<std::size_t>(static_cast<std::uint32_t>(aShuffleWord)) & aMaterialIndexMask;
            const std::size_t aSwapIndexB = static_cast<std::size_t>(static_cast<std::uint32_t>(aShuffleWord >> 32U)) & aMaterialIndexMask;
            
            std::uint8_t *aHold = mMaterials[aSwapIndexA];
            mMaterials[aSwapIndexA] = mMaterials[aSwapIndexB];
            mMaterials[aSwapIndexB] = aHold;
        }
    }

    for (std::size_t aSpanIndex=aMaskShuffleSpanStartBlockIndex;
         aSpanIndex<=aMaskShuffleSpanEndBlockIndex;
         aSpanIndex++) {
        const std::size_t aStartIndex = aSpanIndex * aShuffleSpanByteCount;
        const std::size_t aCeilingIndex = aStartIndex + aShuffleSpanByteCount;
        
        for (std::size_t aIndex=aStartIndex; aIndex<aCeilingIndex; aIndex+=8U) {
            const std::uint64_t aShuffleWord = TwistMix64::DiffuseA(Load64LE(&mCondenseLaneC[aIndex]));
            const std::size_t aSwapIndexA = static_cast<std::size_t>(static_cast<std::uint32_t>(aShuffleWord)) % SoccerMaskBank::mMaskGridWidth;
            const std::size_t aSwapIndexB = static_cast<std::size_t>(static_cast<std::uint32_t>(aShuffleWord >> 32U)) % SoccerMaskBank::mMaskGridWidth;
            
            std::uint8_t aHold = mMasks[aSwapIndexA];
            mMasks[aSwapIndexA] = mMasks[aSwapIndexB];
            mMasks[aSwapIndexB] = aHold;
        }
    }

    for (std::size_t aSpanIndex=aMaskShuffleSpanStartBlockIndex;
         aSpanIndex<=aMaskShuffleSpanEndBlockIndex;
         aSpanIndex++) {
        const std::size_t aStartIndex = aSpanIndex * aShuffleSpanByteCount;
        const std::size_t aCeilingIndex = aStartIndex + aShuffleSpanByteCount;

        for (std::size_t aIndex=aStartIndex; aIndex<aCeilingIndex; aIndex+=8U) {
            const std::uint64_t aShuffleWord = TwistMix64::DiffuseA(Load64LE(&mCondenseLaneD[aIndex]));
            const std::size_t aSwapIndexA = static_cast<std::size_t>(static_cast<std::uint32_t>(aShuffleWord)) % SoccerMaskBank::mMaskGridWidth;
            const std::size_t aSwapIndexB = static_cast<std::size_t>(static_cast<std::uint32_t>(aShuffleWord >> 32U)) % SoccerMaskBank::mMaskGridWidth;

            std::uint8_t aHold = mMasks[aSwapIndexA];
            mMasks[aSwapIndexA] = mMasks[aSwapIndexB];
            mMasks[aSwapIndexB] = aHold;
        }
    }
}

bool Soccer2::SeedEpilogue_Regular_D() {
    constexpr std::size_t kPremiumPlanIndex = 0U;
    const std::uint64_t aPlanSelect = mPremiumSeed[kPremiumPlanIndex];
    
    EncryptionPlan aPlan = EncryptionPlanTool::MakePlanNormal(aPlanSelect, mCiphers);
    Cryptex3 *aCryptexA = &mCryptex6;
    Cryptex6 *aCryptexB = &mCryptex6;
    
    if (mStrength == EncryptionStrength::kWeak) {
        aPlan = EncryptionPlanTool::MakePlanWeak(aPlanSelect, mCiphers);
    } else if (mStrength == EncryptionStrength::kStrong) {
        aPlan = EncryptionPlanTool::MakePlanStrong(aPlanSelect, mCiphers);
        aCryptexA = &mCryptex9;
        aCryptexB = &mCryptex9;
    }
    
    // Consume key material in descending lane size so the quarter-lane cursor
    // does not strand material needed by a larger lane.
    for (std::size_t aCipherIndex=0U; aCipherIndex<aPlan.mL3A.mCount; aCipherIndex++) {
        Cipher *aCipher = GenerateCipher(aPlan.mL3A.mType[aCipherIndex], kStageL3A);
        if (aCipher == nullptr) {
            printf("Fatal: failed to generate L3A cipher %zu.\n", aCipherIndex);
            return false;
        }
        aCryptexA->AddCipherL3A(aCipher);
    }
    
    for (std::size_t aCipherIndex=0U; aCipherIndex<aPlan.mL3B.mCount; aCipherIndex++) {
        Cipher *aCipher = GenerateCipher(aPlan.mL3B.mType[aCipherIndex], kStageL3B);
        if (aCipher == nullptr) {
            printf("Fatal: failed to generate L3B cipher %zu.\n", aCipherIndex);
            return false;
        }
        aCryptexB->AddCipherL3B(aCipher);
    }
    
    for (std::size_t aCipherIndex=0U; aCipherIndex<aPlan.mL3C.mCount; aCipherIndex++) {
        Cipher *aCipher = GenerateCipher(aPlan.mL3C.mType[aCipherIndex], kStageL3C);
        if (aCipher == nullptr) {
            printf("Fatal: failed to generate L3C cipher %zu.\n", aCipherIndex);
            return false;
        }
        mCryptex9.AddCipherL3C(aCipher);
    }
    
    for (std::size_t aCipherIndex=0U; aCipherIndex<aPlan.mL2A.mCount; aCipherIndex++) {
        Cipher *aCipher = GenerateCipher(aPlan.mL2A.mType[aCipherIndex], kStageL2A);
        if (aCipher == nullptr) {
            printf("Fatal: failed to generate L2A cipher %zu.\n", aCipherIndex);
            return false;
        }
        aCryptexA->AddCipherL2A(aCipher);
    }
    
    for (std::size_t aCipherIndex=0U; aCipherIndex<aPlan.mL2B.mCount; aCipherIndex++) {
        Cipher *aCipher = GenerateCipher(aPlan.mL2B.mType[aCipherIndex], kStageL2B);
        if (aCipher == nullptr) {
            printf("Fatal: failed to generate L2B cipher %zu.\n", aCipherIndex);
            return false;
        }
        aCryptexB->AddCipherL2B(aCipher);
    }
    
    for (std::size_t aCipherIndex=0U; aCipherIndex<aPlan.mL2C.mCount; aCipherIndex++) {
        Cipher *aCipher = GenerateCipher(aPlan.mL2C.mType[aCipherIndex], kStageL2C);
        if (aCipher == nullptr) {
            printf("Fatal: failed to generate L2C cipher %zu.\n", aCipherIndex);
            return false;
        }
        mCryptex9.AddCipherL2C(aCipher);
    }
    
    for (std::size_t aCipherIndex=0U; aCipherIndex<aPlan.mL1A.mCount; aCipherIndex++) {
        Cipher *aCipher = GenerateCipher(aPlan.mL1A.mType[aCipherIndex], kStageL1A);
        if (aCipher == nullptr) {
            printf("Fatal: failed to generate L1A cipher %zu.\n", aCipherIndex);
            return false;
        }
        aCryptexA->AddCipherL1A(aCipher);
    }
    
    for (std::size_t aCipherIndex=0U; aCipherIndex<aPlan.mL1B.mCount; aCipherIndex++) {
        Cipher *aCipher = GenerateCipher(aPlan.mL1B.mType[aCipherIndex], kStageL1B);
        if (aCipher == nullptr) {
            printf("Fatal: failed to generate L1B cipher %zu.\n", aCipherIndex);
            return false;
        }
        aCryptexB->AddCipherL1B(aCipher);
    }
    
    for (std::size_t aCipherIndex=0U; aCipherIndex<aPlan.mL1C.mCount; aCipherIndex++) {
        Cipher *aCipher = GenerateCipher(aPlan.mL1C.mType[aCipherIndex], kStageL1C);
        if (aCipher == nullptr) {
            printf("Fatal: failed to generate L1C cipher %zu.\n", aCipherIndex);
            return false;
        }
        mCryptex9.AddCipherL1C(aCipher);
    }
    
    return true;
}

void Soccer2::Shuffle_MEWBlockZero(std::uint8_t *pMaterial) {
    
    for (std::size_t aIndex=0; aIndex<16; aIndex++) {
        mShuffleMaterials[aIndex] = mMaterials[aIndex];
    }
    for (std::size_t aIndex=0; aIndex<SOCCER_EXPANDER_COUNT; aIndex++) {
        mShuffleExpanders[aIndex] = mExpanders[aIndex];
    }
    for (std::size_t aIndex=0; aIndex<16; aIndex++) {
        mShuffleWorkSpaces[aIndex] = mWorkSpaces[aIndex];
    }
    
    TwistShuffle::ShuffleList16(mShuffleMaterials,  pMaterial,     0U,  3600U, 1U);
    TwistShuffle::ShuffleList16(mShuffleExpanders,  pMaterial,  3600U,  7200U, 1U);
    TwistShuffle::ShuffleList16(mShuffleWorkSpaces, pMaterial,  7200U, 10800U, 1U);

    TwistShuffle::ShuffleList16(mShuffleMaterials,  pMaterial, 10800U, 14400U, 1U);
    TwistShuffle::ShuffleList16(mShuffleExpanders,  pMaterial, 14400U, 18000U, 1U);
    TwistShuffle::ShuffleList16(mShuffleWorkSpaces, pMaterial, 18000U, 21600U, 1U);

    TwistShuffle::ShuffleList16(mShuffleMaterials,  pMaterial, 21600U, 25200U, 1U);
    TwistShuffle::ShuffleList16(mShuffleExpanders,  pMaterial, 25200U, 28800U, 1U);
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
    for (std::size_t aIndex=0; aIndex<SOCCER_EXPANDER_COUNT; aIndex++) {
        mClaimed[aIndex] = false;
        for (std::size_t aClaimedIndex=0; aClaimedIndex<mClaimedExpanderCount; aClaimedIndex++) {
            if (mShuffleExpanders[aIndex] == mClaimedExpanders[aClaimedIndex]) {
                mClaimed[aIndex] = true;
                break;
            }
        }
    }

    TwistShuffle::MoveClaimedToEnd16(mClaimed, mShuffleExpanders);

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
    for (std::size_t aIndex=0; aIndex<SOCCER_EXPANDER_COUNT; aIndex++) {
        mExpanders[aIndex] = mShuffleExpanders[aIndex];
    }
    for (std::size_t aIndex=0; aIndex<16; aIndex++) {
        mWorkSpaces[aIndex] = mShuffleWorkSpaces[aIndex];
    }
}
