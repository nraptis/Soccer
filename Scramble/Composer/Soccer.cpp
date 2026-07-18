//
//  Soccer.cpp
//  Cover Lettur
//
//  Created by icarus black on 7/6/26.
//

#include "Soccer.hpp"

#include "PasswordXORCipher.hpp"
#include "CascadeJumpXORCipher.hpp"
#include "CascadeXORCipher.hpp"
#include "PasswordAddCipher.hpp"
#include "PasswordJumpAddCipher.hpp"
#include "PasswordJumpXORCipher.hpp"
#include "PasswordSubtractCipher.hpp"
#include "PepperDualJumpNoiseXORCipher.hpp"
#include "PepperJumpNoiseXORCipher.hpp"
#include "PepperNoiseXORCipher.hpp"

#include "RotateMaskCipher.hpp"

#include "TwistMix32.hpp"
#include "TwistMix64.hpp"
#include "TwistFunctional.hpp"

#include <memory>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define BLOCK_COUNT (SOCCER_BLOCK_SIZE / S_BLOCK)

namespace {

std::uint8_t mMaterialA[SOCCER_BLOCK_SIZE];
std::uint8_t mMaterialB[SOCCER_BLOCK_SIZE];
std::uint8_t mMaterialC[SOCCER_BLOCK_SIZE];
std::uint8_t mMaterialD[SOCCER_BLOCK_SIZE];

std::uint8_t mMaterialE[SOCCER_BLOCK_SIZE];
std::uint8_t mMaterialF[SOCCER_BLOCK_SIZE];
std::uint8_t mMaterialG[SOCCER_BLOCK_SIZE];
std::uint8_t mMaterialH[SOCCER_BLOCK_SIZE];

std::uint8_t mMaterialI[SOCCER_BLOCK_SIZE];
std::uint8_t mMaterialJ[SOCCER_BLOCK_SIZE];
std::uint8_t mMaterialK[SOCCER_BLOCK_SIZE];
std::uint8_t mMaterialL[SOCCER_BLOCK_SIZE];

std::uint8_t mMaterialM[SOCCER_BLOCK_SIZE];
std::uint8_t mMaterialN[SOCCER_BLOCK_SIZE];
std::uint8_t mMaterialO[SOCCER_BLOCK_SIZE];
std::uint8_t mMaterialP[SOCCER_BLOCK_SIZE];

// This is only used for the initial shuffle.
TwistExpander_Gemma mStarter;

TwistWorkSpace mWorkSpaceA;
TwistWorkSpace mWorkSpaceB;
TwistWorkSpace mWorkSpaceC;
TwistWorkSpace mWorkSpaceD;
TwistWorkSpace mWorkSpaceE;
TwistWorkSpace mWorkSpaceF;
TwistWorkSpace mWorkSpaceG;
TwistWorkSpace mWorkSpaceH;
TwistWorkSpace mWorkSpaceI;
TwistWorkSpace mWorkSpaceJ;
TwistWorkSpace mWorkSpaceK;
TwistWorkSpace mWorkSpaceL;
TwistWorkSpace mWorkSpaceM;
TwistWorkSpace mWorkSpaceN;
TwistWorkSpace mWorkSpaceO;
TwistWorkSpace mWorkSpaceP;

std::uint8_t mRandom[S_BLOCK];
std::uint8_t mScratch[SOCCER_BLOCK_SIZE];

std::uint8_t mCrushA[S_BLOCK];
std::uint8_t mCrushB[S_BLOCK];
std::uint8_t mCrushC[S_BLOCK];
std::uint8_t mCrushD[S_BLOCK];

std::uint8_t mCryptTemp[SOCCER_BLOCK_SIZE];

} // namespace

TwistFarmSalt Soccer::mFarmSalt;

TwistExpander_Achernar Soccer::mAchernar;
TwistExpander_Alcor Soccer::mAlcor;
TwistExpander_Aldebaran Soccer::mAldebaran;
TwistExpander_Alioth Soccer::mAlioth;
TwistExpander_Alkaid Soccer::mAlkaid;
TwistExpander_Alnitak Soccer::mAlnitak;
TwistExpander_Altair Soccer::mAltair;
TwistExpander_Ankaa Soccer::mAnkaa;
TwistExpander_Antares Soccer::mAntares;
TwistExpander_Arcturus Soccer::mArcturus;
TwistExpander_Athebyne Soccer::mAthebyne;
TwistExpander_Bellatrix Soccer::mBellatrix;
TwistExpander_Betelgeuse Soccer::mBetelgeuse;
TwistExpander_Canopus Soccer::mCanopus;
TwistExpander_Capella Soccer::mCapella;
TwistExpander_Castor Soccer::mCastor;
TwistExpander_Mebsuta Soccer::mMebsuta;
TwistExpander_Menkent Soccer::mMenkent;
TwistExpander_Mimosa Soccer::mMimosa;
TwistExpander_Miram Soccer::mMiram;
TwistExpander_Mirfak Soccer::mMirfak;
TwistExpander_Mothallah Soccer::mMothallah;
TwistExpander_Naos Soccer::mNaos;
TwistExpander_Polaris Soccer::mPolaris;
TwistExpander_Pollux Soccer::mPollux;
TwistExpander_Procyon Soccer::mProcyon;
TwistExpander_Regulus Soccer::mRegulus;
TwistExpander_Rigel Soccer::mRigel;
TwistExpander_Saiph Soccer::mSaiph;
TwistExpander_Sirius Soccer::mSirius;
TwistExpander_Suhail Soccer::mSuhail;
TwistExpander_Vega Soccer::mVega;

std::uint8_t Soccer::mMasks[32];

std::uint8_t *Soccer::mMaterials[16];
TwistExpander *Soccer::mExpanders[32];
TwistWorkSpace *Soccer::mWorkSpaces[16];
std::uint8_t *Soccer::mSources[16];

TwistExpander *Soccer::mClaimedExpanders[16];
std::size_t Soccer::mClaimedExpanderCount;

std::uint8_t *Soccer::mClaimedMaterials[16];
std::size_t Soccer::mClaimedMaterialCount;

TwistWorkSpace *Soccer::mClaimedWorkSpaces[16];
std::size_t Soccer::mClaimedWorkSpaceCount;

std::uint8_t Soccer::mCiphersIdentifiersA[64];
std::uint8_t Soccer::mCiphersIdentifiersB[64];

std::uint64_t Soccer::mRotationAmountsL3[2];
std::uint64_t Soccer::mRotationAmountsL2[2];
std::uint64_t Soccer::mRotationAmountsL1[2];
std::uint64_t Soccer::mRotationAmountsFinal[2];

LayeredCrypt Soccer::mCrypt;
EncryptionLayer Soccer::mFinalL3;

std::uint8_t *Soccer::mShuffleMaterials[16];
TwistExpander *Soccer::mShuffleExpanders[32];
TwistWorkSpace *Soccer::mShuffleWorkSpaces[16];

void Soccer::InitializeAvalancheReferenceMaterials(const std::uint8_t *(&pMaterials)[16]) {
    pMaterials[ 0] = mMaterialA;
    pMaterials[ 1] = mMaterialB;
    pMaterials[ 2] = mMaterialC;
    pMaterials[ 3] = mMaterialD;
    pMaterials[ 4] = mMaterialE;
    pMaterials[ 5] = mMaterialF;
    pMaterials[ 6] = mMaterialG;
    pMaterials[ 7] = mMaterialH;
    pMaterials[ 8] = mMaterialI;
    pMaterials[ 9] = mMaterialJ;
    pMaterials[10] = mMaterialK;
    pMaterials[11] = mMaterialL;
    pMaterials[12] = mMaterialM;
    pMaterials[13] = mMaterialN;
    pMaterials[14] = mMaterialO;
    pMaterials[15] = mMaterialP;
}

std::uint64_t Soccer::Read64(const std::uint8_t *pSource) {
    return static_cast<std::uint64_t>(pSource[0]) |
    (static_cast<std::uint64_t>(pSource[1]) << 8) |
    (static_cast<std::uint64_t>(pSource[2]) << 16) |
    (static_cast<std::uint64_t>(pSource[3]) << 24) |
    (static_cast<std::uint64_t>(pSource[4]) << 32) |
    (static_cast<std::uint64_t>(pSource[5]) << 40) |
    (static_cast<std::uint64_t>(pSource[6]) << 48) |
    (static_cast<std::uint64_t>(pSource[7]) << 56);
}

void Soccer::FoldAllMaterialsIntoRandomForBlock(std::size_t pBlockIndex) {
    
    const std::size_t aStartIndex = pBlockIndex * S_BLOCK;
    for (std::size_t aBlockIndex=0; aBlockIndex<S_BLOCK; aBlockIndex++) {
        
        const std::size_t aMaterialIndex = aStartIndex + aBlockIndex;
        const std::uint32_t aCrushIngressA =
            (static_cast<std::uint32_t>(mMaterials[ 0][aMaterialIndex]) <<  0U) |
            (static_cast<std::uint32_t>(mMaterials[ 1][aMaterialIndex]) <<  8U) |
            (static_cast<std::uint32_t>(mMaterials[ 2][aMaterialIndex]) << 16U) |
            (static_cast<std::uint32_t>(mMaterials[ 3][aMaterialIndex]) << 24U);
        
        mCrushA[aBlockIndex] = TwistMix32::DiffuseA(aCrushIngressA);

        const std::uint32_t aCrushIngressB =
            (static_cast<std::uint32_t>(mMaterials[ 4][aMaterialIndex]) <<  0U) |
            (static_cast<std::uint32_t>(mMaterials[ 5][aMaterialIndex]) <<  8U) |
            (static_cast<std::uint32_t>(mMaterials[ 6][aMaterialIndex]) << 16U) |
            (static_cast<std::uint32_t>(mMaterials[ 7][aMaterialIndex]) << 24U);
        
        mCrushB[aBlockIndex] = TwistMix32::DiffuseA(aCrushIngressB);

        const std::uint32_t aCrushIngressC =
            (static_cast<std::uint32_t>(mMaterials[ 8][aMaterialIndex]) <<  0U) |
            (static_cast<std::uint32_t>(mMaterials[ 9][aMaterialIndex]) <<  8U) |
            (static_cast<std::uint32_t>(mMaterials[10][aMaterialIndex]) << 16U) |
            (static_cast<std::uint32_t>(mMaterials[11][aMaterialIndex]) << 24U);
        
        mCrushC[aBlockIndex] = TwistMix32::DiffuseA(aCrushIngressC);

        const std::uint32_t aCrushIngressD =
            (static_cast<std::uint32_t>(mMaterials[12][aMaterialIndex]) <<  0U) |
            (static_cast<std::uint32_t>(mMaterials[13][aMaterialIndex]) <<  8U) |
            (static_cast<std::uint32_t>(mMaterials[14][aMaterialIndex]) << 16U) |
            (static_cast<std::uint32_t>(mMaterials[15][aMaterialIndex]) << 24U);
        
        mCrushD[aBlockIndex] = TwistMix32::DiffuseA(aCrushIngressD);
    }
    
    for (std::size_t aBlockIndex=0; aBlockIndex<S_BLOCK; aBlockIndex++) {
        
        const std::uint32_t aRandomIngress =
            (static_cast<std::uint32_t>(mCrushA[aBlockIndex]) <<  0U) |
            (static_cast<std::uint32_t>(mCrushB[aBlockIndex]) <<  8U) |
            (static_cast<std::uint32_t>(mCrushC[aBlockIndex]) << 16U) |
            (static_cast<std::uint32_t>(mCrushD[aBlockIndex]) << 24U);
        
        mRandom[aBlockIndex] = TwistMix32::DiffuseA(aRandomIngress);
    }
}

void Soccer::ShuffleSEWMMCC() {
    
    
    
    for (std::size_t aIndex=4096; aIndex<8192; aIndex+=2) {
        const std::uint8_t aIndexA = mRandom[aIndex + 0U] & 31U;
        const std::uint8_t aIndexB = mRandom[aIndex + 1U] & 31U;
        const std::uint8_t aHold = mMasks[aIndexA];
        mMasks[aIndexA] = mMasks[aIndexB];
        mMasks[aIndexB] = aHold;
    }
    
    // 8,192
    for (std::size_t aIndex=8192; aIndex<12288; aIndex+=2) {
        const std::uint8_t aIndexA = mRandom[aIndex + 0U] & 15U;
        const std::uint8_t aIndexB = mRandom[aIndex + 1U] & 15U;
        std::uint8_t *aHold = mMaterials[aIndexA];
        mMaterials[aIndexA] = mMaterials[aIndexB];
        mMaterials[aIndexB] = aHold;
    }

    // 12,288
    for (std::size_t aIndex=12288; aIndex<16384; aIndex+=2) {
        const std::uint8_t aIndexA = mRandom[aIndex + 0U] & 15U;
        const std::uint8_t aIndexB = mRandom[aIndex + 1U] & 15U;
        std::uint8_t *aHold = mSources[aIndexA];
        mSources[aIndexA] = mSources[aIndexB];
        mSources[aIndexB] = aHold;
    }

    // 16,384
    for (std::size_t aIndex=16384; aIndex<20480; aIndex+=2) {
        const std::uint8_t aIndexA = mRandom[aIndex + 0U] & 31U;
        const std::uint8_t aIndexB = mRandom[aIndex + 1U] & 31U;
        TwistExpander *aHold = mExpanders[aIndexA];
        mExpanders[aIndexA] = mExpanders[aIndexB];
        mExpanders[aIndexB] = aHold;
    }

    // 20,480
    for (std::size_t aIndex=20480; aIndex<24576; aIndex+=2) {
        const std::uint8_t aIndexA = mRandom[aIndex + 0U] & 15U;
        const std::uint8_t aIndexB = mRandom[aIndex + 1U] & 15U;
        TwistWorkSpace *aHold = mWorkSpaces[aIndexA];
        mWorkSpaces[aIndexA] = mWorkSpaces[aIndexB];
        mWorkSpaces[aIndexB] = aHold;
    }

    // 24,576
    for (std::size_t aIndex=24576; aIndex<28672; aIndex+=2) {
        const std::uint8_t aIndexA = mRandom[aIndex + 0U] & 63U;
        const std::uint8_t aIndexB = mRandom[aIndex + 1U] & 63U;
        const std::uint8_t aHold = mCiphersIdentifiersA[aIndexA];
        mCiphersIdentifiersA[aIndexA] = mCiphersIdentifiersA[aIndexB];
        mCiphersIdentifiersA[aIndexB] = aHold;
    }

    // 28,672
    for (std::size_t aIndex=28672; aIndex<32768; aIndex+=2) {
        const std::uint8_t aIndexA = mRandom[aIndex + 0U] & 63U;
        const std::uint8_t aIndexB = mRandom[aIndex + 1U] & 63U;
        const std::uint8_t aHold = mCiphersIdentifiersB[aIndexA];
        mCiphersIdentifiersB[aIndexA] = mCiphersIdentifiersB[aIndexB];
        mCiphersIdentifiersB[aIndexB] = aHold;
    }
}

void Soccer::ShuffleMEWBlockZero(std::uint8_t *pMaterial) {
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

    // Materials: [2048, 4096) relative to the zero block.
    for (std::size_t aIndex=2048; aIndex<4096; aIndex+=2) {
        const std::uint8_t aIndexA = pMaterial[aIndex + 0U] & 15U;
        const std::uint8_t aIndexB = pMaterial[aIndex + 1U] & 15U;
        std::uint8_t *aHold = mShuffleMaterials[aIndexA];
        mShuffleMaterials[aIndexA] = mShuffleMaterials[aIndexB];
        mShuffleMaterials[aIndexB] = aHold;
    }

    // Expanders: [6144, 8192) relative to the zero block.
    for (std::size_t aIndex=6144; aIndex<8192; aIndex+=2) {
        const std::uint8_t aIndexA = pMaterial[aIndex + 0U] & 31U;
        const std::uint8_t aIndexB = pMaterial[aIndex + 1U] & 31U;
        TwistExpander *aHold = mShuffleExpanders[aIndexA];
        mShuffleExpanders[aIndexA] = mShuffleExpanders[aIndexB];
        mShuffleExpanders[aIndexB] = aHold;
    }

    // Work spaces: [10240, 12288) relative to the zero block.
    for (std::size_t aIndex=10240; aIndex<12288; aIndex+=2) {
        const std::uint8_t aIndexA = pMaterial[aIndex + 0U] & 15U;
        const std::uint8_t aIndexB = pMaterial[aIndex + 1U] & 15U;
        TwistWorkSpace *aHold = mShuffleWorkSpaces[aIndexA];
        mShuffleWorkSpaces[aIndexA] = mShuffleWorkSpaces[aIndexB];
        mShuffleWorkSpaces[aIndexB] = aHold;
    }
    
    // Materials: [14336, 16384) relative to the zero block.
    for (std::size_t aIndex=14336; aIndex<16384; aIndex+=2) {
        const std::uint8_t aIndexA = pMaterial[aIndex + 0U] & 15U;
        const std::uint8_t aIndexB = pMaterial[aIndex + 1U] & 15U;
        std::uint8_t *aHold = mShuffleMaterials[aIndexA];
        mShuffleMaterials[aIndexA] = mShuffleMaterials[aIndexB];
        mShuffleMaterials[aIndexB] = aHold;
    }

    // Expanders: [18432, 20480) relative to the zero block.
    for (std::size_t aIndex=18432; aIndex<20480; aIndex+=2) {
        const std::uint8_t aIndexA = pMaterial[aIndex + 0U] & 31U;
        const std::uint8_t aIndexB = pMaterial[aIndex + 1U] & 31U;
        TwistExpander *aHold = mShuffleExpanders[aIndexA];
        mShuffleExpanders[aIndexA] = mShuffleExpanders[aIndexB];
        mShuffleExpanders[aIndexB] = aHold;
    }

    // Work spaces: [22528, 24576) relative to the zero block.
    for (std::size_t aIndex=22528; aIndex<24576; aIndex+=2) {
        const std::uint8_t aIndexA = pMaterial[aIndex + 0U] & 15U;
        const std::uint8_t aIndexB = pMaterial[aIndex + 1U] & 15U;
        TwistWorkSpace *aHold = mShuffleWorkSpaces[aIndexA];
        mShuffleWorkSpaces[aIndexA] = mShuffleWorkSpaces[aIndexB];
        mShuffleWorkSpaces[aIndexB] = aHold;
    }
    
    std::size_t aUnclaimedMaterialCount = 16U;
    for (std::size_t aClaimedIndex=0; aClaimedIndex<mClaimedMaterialCount; aClaimedIndex++) {
        for (std::size_t aIndex=0; aIndex<aUnclaimedMaterialCount; aIndex++) {
            if (mShuffleMaterials[aIndex] == mClaimedMaterials[aClaimedIndex]) {
                aUnclaimedMaterialCount--;
                std::uint8_t *aHold = mShuffleMaterials[aIndex];
                mShuffleMaterials[aIndex] = mShuffleMaterials[aUnclaimedMaterialCount];
                mShuffleMaterials[aUnclaimedMaterialCount] = aHold;
                break;
            }
        }
    }

    std::size_t aUnclaimedExpanderCount = 32U;
    for (std::size_t aClaimedIndex=0; aClaimedIndex<mClaimedExpanderCount; aClaimedIndex++) {
        for (std::size_t aIndex=0; aIndex<aUnclaimedExpanderCount; aIndex++) {
            if (mShuffleExpanders[aIndex] == mClaimedExpanders[aClaimedIndex]) {
                aUnclaimedExpanderCount--;
                TwistExpander *aHold = mShuffleExpanders[aIndex];
                mShuffleExpanders[aIndex] = mShuffleExpanders[aUnclaimedExpanderCount];
                mShuffleExpanders[aUnclaimedExpanderCount] = aHold;
                break;
            }
        }
    }

    std::size_t aUnclaimedWorkSpaceCount = 16U;
    for (std::size_t aClaimedIndex=0; aClaimedIndex<mClaimedWorkSpaceCount; aClaimedIndex++) {
        for (std::size_t aIndex=0; aIndex<aUnclaimedWorkSpaceCount; aIndex++) {
            if (mShuffleWorkSpaces[aIndex] == mClaimedWorkSpaces[aClaimedIndex]) {
                aUnclaimedWorkSpaceCount--;
                TwistWorkSpace *aHold = mShuffleWorkSpaces[aIndex];
                mShuffleWorkSpaces[aIndex] = mShuffleWorkSpaces[aUnclaimedWorkSpaceCount];
                mShuffleWorkSpaces[aUnclaimedWorkSpaceCount] = aHold;
                break;
            }
        }
    }

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

bool Soccer::AttemptSeed_Encrypt(std::uint8_t *pPassword,
                                 std::size_t pPasswordByteLength,
                                 std::uint64_t pNonce,
                                 std::uint32_t *pAckWord) {
    
    if (pAckWord == nullptr) {
        return false;
    }
    
    if (!SeedPrelude(pPassword, pPasswordByteLength, pNonce)) {
        return false;
    }
    
    mClaimedExpanders[0] = mExpanders[0];
    mClaimedExpanders[1] = mExpanders[1];
    mClaimedExpanderCount += 2;
    
    mClaimedMaterials[0] = mMaterials[0];
    mClaimedMaterials[1] = mMaterials[1];
    mClaimedMaterialCount += 2;
    
    mClaimedWorkSpaces[0] = mWorkSpaces[0];
    mClaimedWorkSpaces[1] = mWorkSpaces[1];
    mClaimedWorkSpaceCount += 2;
    
    mClaimedExpanders[0]->Seed(mClaimedWorkSpaces[0], &mFarmSalt, pNonce, pPassword, pPasswordByteLength, &mClaimedMaterials[0][0]);
    mClaimedExpanders[1]->Seed(mClaimedWorkSpaces[1], &mFarmSalt, pNonce, &mClaimedMaterials[0][0], S_BLOCK, &mClaimedMaterials[1][0]);
    
    ShuffleMEWBlockZero(&mClaimedMaterials[1][0]);
    
    mClaimedExpanders[2] = mExpanders[0];
    mClaimedExpanders[3] = mExpanders[1];
    mClaimedExpanderCount += 2;
    
    mClaimedMaterials[2] = mMaterials[0];
    mClaimedMaterials[3] = mMaterials[1];
    mClaimedMaterialCount += 2;
    
    mClaimedWorkSpaces[2] = mWorkSpaces[0];
    mClaimedWorkSpaces[3] = mWorkSpaces[1];
    mClaimedWorkSpaceCount += 2;
    
    mClaimedExpanders[2]->Seed(mClaimedWorkSpaces[2], &mFarmSalt, pNonce, pPassword, pPasswordByteLength, &mClaimedMaterials[2][0]);
    mClaimedExpanders[3]->Seed(mClaimedWorkSpaces[3], &mFarmSalt, pNonce, &mClaimedMaterials[2][0], S_BLOCK, &mClaimedMaterials[3][0]);
    
    // Acknowledge byte 1 after four seeds.
    std::uint32_t aAckWord = static_cast<std::uint32_t>(mClaimedMaterials[3][S_BLOCK - 1]);
    
    ShuffleMEWBlockZero(&mClaimedMaterials[3][0]);
    
    mClaimedExpanders[4] = mExpanders[0];
    mClaimedExpanders[5] = mExpanders[1];
    mClaimedExpanderCount += 2;
    
    mClaimedMaterials[4] = mMaterials[0];
    mClaimedMaterials[5] = mMaterials[1];
    mClaimedMaterialCount += 2;
    
    mClaimedWorkSpaces[4] = mWorkSpaces[0];
    mClaimedWorkSpaces[5] = mWorkSpaces[1];
    mClaimedWorkSpaceCount += 2;
    
    mClaimedExpanders[4]->Seed(mClaimedWorkSpaces[4], &mFarmSalt, pNonce, pPassword, pPasswordByteLength, &mClaimedMaterials[4][0]);
    mClaimedExpanders[5]->Seed(mClaimedWorkSpaces[5], &mFarmSalt, pNonce, &mClaimedMaterials[4][0], S_BLOCK, &mClaimedMaterials[5][0]);
    
    ShuffleMEWBlockZero(&mClaimedMaterials[5][0]);
    
    mClaimedExpanders[6] = mExpanders[0];
    mClaimedExpanders[7] = mExpanders[1];
    mClaimedExpanderCount += 2;
    
    mClaimedMaterials[6] = mMaterials[0];
    mClaimedMaterials[7] = mMaterials[1];
    mClaimedMaterialCount += 2;
    
    mClaimedWorkSpaces[6] = mWorkSpaces[0];
    mClaimedWorkSpaces[7] = mWorkSpaces[1];
    mClaimedWorkSpaceCount += 2;
    
    mClaimedExpanders[6]->Seed(mClaimedWorkSpaces[6], &mFarmSalt, pNonce, pPassword, pPasswordByteLength, &mClaimedMaterials[6][0]);
    mClaimedExpanders[7]->Seed(mClaimedWorkSpaces[7], &mFarmSalt, pNonce, &mClaimedMaterials[6][0], S_BLOCK, &mClaimedMaterials[7][0]);
    
    // Acknowledge byte 2 after eight seeds.
    aAckWord |= static_cast<std::uint32_t>(mClaimedMaterials[7][S_BLOCK - 1]) << 8U;
    
    ShuffleMEWBlockZero(&mClaimedMaterials[7][0]);
    
    mClaimedExpanders[8] = mExpanders[0];
    mClaimedExpanders[9] = mExpanders[1];
    mClaimedExpanderCount += 2;
    
    mClaimedMaterials[8] = mMaterials[0];
    mClaimedMaterials[9] = mMaterials[1];
    mClaimedMaterialCount += 2;
    
    mClaimedWorkSpaces[8] = mWorkSpaces[0];
    mClaimedWorkSpaces[9] = mWorkSpaces[1];
    mClaimedWorkSpaceCount += 2;
    
    mClaimedExpanders[8]->Seed(mClaimedWorkSpaces[8], &mFarmSalt, pNonce, pPassword, pPasswordByteLength, &mClaimedMaterials[8][0]);
    mClaimedExpanders[9]->Seed(mClaimedWorkSpaces[9], &mFarmSalt, pNonce, &mClaimedMaterials[8][0], S_BLOCK, &mClaimedMaterials[9][0]);
    
    ShuffleMEWBlockZero(&mClaimedMaterials[9][0]);
    
    mClaimedExpanders[10] = mExpanders[0];
    mClaimedExpanders[11] = mExpanders[1];
    mClaimedExpanderCount += 2;
    
    mClaimedMaterials[10] = mMaterials[0];
    mClaimedMaterials[11] = mMaterials[1];
    mClaimedMaterialCount += 2;
    
    mClaimedWorkSpaces[10] = mWorkSpaces[0];
    mClaimedWorkSpaces[11] = mWorkSpaces[1];
    mClaimedWorkSpaceCount += 2;
    
    mClaimedExpanders[10]->Seed(mClaimedWorkSpaces[10], &mFarmSalt, pNonce, pPassword, pPasswordByteLength, &mClaimedMaterials[10][0]);
    mClaimedExpanders[11]->Seed(mClaimedWorkSpaces[11], &mFarmSalt, pNonce, &mClaimedMaterials[10][0], S_BLOCK, &mClaimedMaterials[11][0]);
    
    // Acknowledge byte 3 after twelve seeds.
    aAckWord |= static_cast<std::uint32_t>(mClaimedMaterials[11][S_BLOCK - 1]) << 16U;
    
    ShuffleMEWBlockZero(&mClaimedMaterials[11][0]);
    
    mClaimedExpanders[12] = mExpanders[0];
    mClaimedExpanders[13] = mExpanders[1];
    mClaimedExpanderCount += 2;
    
    mClaimedMaterials[12] = mMaterials[0];
    mClaimedMaterials[13] = mMaterials[1];
    mClaimedMaterialCount += 2;
    
    mClaimedWorkSpaces[12] = mWorkSpaces[0];
    mClaimedWorkSpaces[13] = mWorkSpaces[1];
    mClaimedWorkSpaceCount += 2;
    
    mClaimedExpanders[12]->Seed(mClaimedWorkSpaces[12], &mFarmSalt, pNonce, pPassword, pPasswordByteLength, &mClaimedMaterials[12][0]);
    mClaimedExpanders[13]->Seed(mClaimedWorkSpaces[13], &mFarmSalt, pNonce, &mClaimedMaterials[12][0], S_BLOCK, &mClaimedMaterials[13][0]);
    
    ShuffleMEWBlockZero(&mClaimedMaterials[13][0]);
    
    mClaimedExpanders[14] = mExpanders[0];
    mClaimedExpanders[15] = mExpanders[1];
    mClaimedExpanderCount += 2;
    
    mClaimedMaterials[14] = mMaterials[0];
    mClaimedMaterials[15] = mMaterials[1];
    mClaimedMaterialCount += 2;
    
    mClaimedWorkSpaces[14] = mWorkSpaces[0];
    mClaimedWorkSpaces[15] = mWorkSpaces[1];
    mClaimedWorkSpaceCount += 2;
    
    mClaimedExpanders[14]->Seed(mClaimedWorkSpaces[14], &mFarmSalt, pNonce, pPassword, pPasswordByteLength, &mClaimedMaterials[14][0]);
    mClaimedExpanders[15]->Seed(mClaimedWorkSpaces[15], &mFarmSalt, pNonce, &mClaimedMaterials[14][0], S_BLOCK, &mClaimedMaterials[15][0]);
    
    // Acknowledge byte 4 after sixteen seeds.
    aAckWord |= static_cast<std::uint32_t>(mClaimedMaterials[15][S_BLOCK - 1]) << 24U;
    
    *pAckWord = aAckWord;
    
    SeedEpilogue();
    
    return true;
}

bool Soccer::AttemptSeed_Decrypt(std::uint8_t *pPassword,
                                 std::size_t pPasswordByteLength,
                                 std::uint64_t pNonce,
                                 std::uint32_t pAckWord) {
    
    if (!SeedPrelude(pPassword, pPasswordByteLength, pNonce)) {
        return false;
    }
    
    mClaimedExpanders[0] = mExpanders[0];
    mClaimedExpanders[1] = mExpanders[1];
    mClaimedExpanderCount += 2;
    
    mClaimedMaterials[0] = mMaterials[0];
    mClaimedMaterials[1] = mMaterials[1];
    mClaimedMaterialCount += 2;
    
    mClaimedWorkSpaces[0] = mWorkSpaces[0];
    mClaimedWorkSpaces[1] = mWorkSpaces[1];
    mClaimedWorkSpaceCount += 2;
    
    mClaimedExpanders[0]->Seed(mClaimedWorkSpaces[0], &mFarmSalt, pNonce, pPassword, pPasswordByteLength, &mClaimedMaterials[0][0]);
    mClaimedExpanders[1]->Seed(mClaimedWorkSpaces[1], &mFarmSalt, pNonce, &mClaimedMaterials[0][0], S_BLOCK, &mClaimedMaterials[1][0]);
    
    ShuffleMEWBlockZero(&mClaimedMaterials[1][0]);
    
    mClaimedExpanders[2] = mExpanders[0];
    mClaimedExpanders[3] = mExpanders[1];
    mClaimedExpanderCount += 2;
    
    mClaimedMaterials[2] = mMaterials[0];
    mClaimedMaterials[3] = mMaterials[1];
    mClaimedMaterialCount += 2;
    
    mClaimedWorkSpaces[2] = mWorkSpaces[0];
    mClaimedWorkSpaces[3] = mWorkSpaces[1];
    mClaimedWorkSpaceCount += 2;
    
    mClaimedExpanders[2]->Seed(mClaimedWorkSpaces[2], &mFarmSalt, pNonce, pPassword, pPasswordByteLength, &mClaimedMaterials[2][0]);
    mClaimedExpanders[3]->Seed(mClaimedWorkSpaces[3], &mFarmSalt, pNonce, &mClaimedMaterials[2][0], S_BLOCK, &mClaimedMaterials[3][0]);
    
    // Check acknowledge byte 1 after four seeds.
    if (static_cast<std::uint32_t>(mClaimedMaterials[3][S_BLOCK - 1]) != (pAckWord & 0x000000FFU)) {
        return false;
    }
    
    ShuffleMEWBlockZero(&mClaimedMaterials[3][0]);
    
    mClaimedExpanders[4] = mExpanders[0];
    mClaimedExpanders[5] = mExpanders[1];
    mClaimedExpanderCount += 2;
    
    mClaimedMaterials[4] = mMaterials[0];
    mClaimedMaterials[5] = mMaterials[1];
    mClaimedMaterialCount += 2;
    
    mClaimedWorkSpaces[4] = mWorkSpaces[0];
    mClaimedWorkSpaces[5] = mWorkSpaces[1];
    mClaimedWorkSpaceCount += 2;
    
    mClaimedExpanders[4]->Seed(mClaimedWorkSpaces[4], &mFarmSalt, pNonce, pPassword, pPasswordByteLength, &mClaimedMaterials[4][0]);
    mClaimedExpanders[5]->Seed(mClaimedWorkSpaces[5], &mFarmSalt, pNonce, &mClaimedMaterials[4][0], S_BLOCK, &mClaimedMaterials[5][0]);
    
    ShuffleMEWBlockZero(&mClaimedMaterials[5][0]);
    
    mClaimedExpanders[6] = mExpanders[0];
    mClaimedExpanders[7] = mExpanders[1];
    mClaimedExpanderCount += 2;
    
    mClaimedMaterials[6] = mMaterials[0];
    mClaimedMaterials[7] = mMaterials[1];
    mClaimedMaterialCount += 2;
    
    mClaimedWorkSpaces[6] = mWorkSpaces[0];
    mClaimedWorkSpaces[7] = mWorkSpaces[1];
    mClaimedWorkSpaceCount += 2;
    
    mClaimedExpanders[6]->Seed(mClaimedWorkSpaces[6], &mFarmSalt, pNonce, pPassword, pPasswordByteLength, &mClaimedMaterials[6][0]);
    mClaimedExpanders[7]->Seed(mClaimedWorkSpaces[7], &mFarmSalt, pNonce, &mClaimedMaterials[6][0], S_BLOCK, &mClaimedMaterials[7][0]);
    
    // Check acknowledge byte 2 after eight seeds.
    if (static_cast<std::uint32_t>(mClaimedMaterials[7][S_BLOCK - 1]) != ((pAckWord >> 8U) & 0x000000FFU)) {
        return false;
    }
    
    ShuffleMEWBlockZero(&mClaimedMaterials[7][0]);
    
    mClaimedExpanders[8] = mExpanders[0];
    mClaimedExpanders[9] = mExpanders[1];
    mClaimedExpanderCount += 2;
    
    mClaimedMaterials[8] = mMaterials[0];
    mClaimedMaterials[9] = mMaterials[1];
    mClaimedMaterialCount += 2;
    
    mClaimedWorkSpaces[8] = mWorkSpaces[0];
    mClaimedWorkSpaces[9] = mWorkSpaces[1];
    mClaimedWorkSpaceCount += 2;
    
    mClaimedExpanders[8]->Seed(mClaimedWorkSpaces[8], &mFarmSalt, pNonce, pPassword, pPasswordByteLength, &mClaimedMaterials[8][0]);
    mClaimedExpanders[9]->Seed(mClaimedWorkSpaces[9], &mFarmSalt, pNonce, &mClaimedMaterials[8][0], S_BLOCK, &mClaimedMaterials[9][0]);
    
    ShuffleMEWBlockZero(&mClaimedMaterials[9][0]);
    
    mClaimedExpanders[10] = mExpanders[0];
    mClaimedExpanders[11] = mExpanders[1];
    mClaimedExpanderCount += 2;
    
    mClaimedMaterials[10] = mMaterials[0];
    mClaimedMaterials[11] = mMaterials[1];
    mClaimedMaterialCount += 2;
    
    mClaimedWorkSpaces[10] = mWorkSpaces[0];
    mClaimedWorkSpaces[11] = mWorkSpaces[1];
    mClaimedWorkSpaceCount += 2;
    
    mClaimedExpanders[10]->Seed(mClaimedWorkSpaces[10], &mFarmSalt, pNonce, pPassword, pPasswordByteLength, &mClaimedMaterials[10][0]);
    mClaimedExpanders[11]->Seed(mClaimedWorkSpaces[11], &mFarmSalt, pNonce, &mClaimedMaterials[10][0], S_BLOCK, &mClaimedMaterials[11][0]);
    
    // Check acknowledge byte 3 after twelve seeds.
    if (static_cast<std::uint32_t>(mClaimedMaterials[11][S_BLOCK - 1]) != ((pAckWord >> 16U) & 0x000000FFU)) {
        return false;
    }
    
    ShuffleMEWBlockZero(&mClaimedMaterials[11][0]);
    
    mClaimedExpanders[12] = mExpanders[0];
    mClaimedExpanders[13] = mExpanders[1];
    mClaimedExpanderCount += 2;
    
    mClaimedMaterials[12] = mMaterials[0];
    mClaimedMaterials[13] = mMaterials[1];
    mClaimedMaterialCount += 2;
    
    mClaimedWorkSpaces[12] = mWorkSpaces[0];
    mClaimedWorkSpaces[13] = mWorkSpaces[1];
    mClaimedWorkSpaceCount += 2;
    
    mClaimedExpanders[12]->Seed(mClaimedWorkSpaces[12], &mFarmSalt, pNonce, pPassword, pPasswordByteLength, &mClaimedMaterials[12][0]);
    mClaimedExpanders[13]->Seed(mClaimedWorkSpaces[13], &mFarmSalt, pNonce, &mClaimedMaterials[12][0], S_BLOCK, &mClaimedMaterials[13][0]);
    
    ShuffleMEWBlockZero(&mClaimedMaterials[13][0]);
    
    mClaimedExpanders[14] = mExpanders[0];
    mClaimedExpanders[15] = mExpanders[1];
    mClaimedExpanderCount += 2;
    
    mClaimedMaterials[14] = mMaterials[0];
    mClaimedMaterials[15] = mMaterials[1];
    mClaimedMaterialCount += 2;
    
    mClaimedWorkSpaces[14] = mWorkSpaces[0];
    mClaimedWorkSpaces[15] = mWorkSpaces[1];
    mClaimedWorkSpaceCount += 2;
    
    mClaimedExpanders[14]->Seed(mClaimedWorkSpaces[14], &mFarmSalt, pNonce, pPassword, pPasswordByteLength, &mClaimedMaterials[14][0]);
    mClaimedExpanders[15]->Seed(mClaimedWorkSpaces[15], &mFarmSalt, pNonce, &mClaimedMaterials[14][0], S_BLOCK, &mClaimedMaterials[15][0]);
    
    // Check acknowledge byte 4 after sixteen seeds.
    if (static_cast<std::uint32_t>(mClaimedMaterials[15][S_BLOCK - 1]) != ((pAckWord >> 24U) & 0x000000FFU)) {
        return false;
    }
    
    SeedEpilogue();
    
    return true;
}

bool Soccer::SeedPrelude(std::uint8_t *pPassword,
                         std::size_t pPasswordByteLength,
                         std::uint64_t pNonce) {
    
    if (pPassword == nullptr) { return false; }
    if (pPasswordByteLength == 0) { return false; }
    
    for (std::size_t aIndex=0; aIndex<16; aIndex++) {
        mClaimedExpanders[aIndex] = nullptr;
    }
    mClaimedExpanderCount = 0;
    
    for (std::size_t aIndex=0; aIndex<16; aIndex++) {
        mClaimedMaterials[aIndex] = nullptr;
    }
    mClaimedMaterialCount = 0;
    
    for (std::size_t aIndex=0; aIndex<16; aIndex++) {
        mClaimedWorkSpaces[aIndex] = nullptr;
    }
    mClaimedWorkSpaceCount = 0;
    
    mWorkSpaces[ 0] = &mWorkSpaceA; mWorkSpaces[ 1] = &mWorkSpaceB; mWorkSpaces[ 2] = &mWorkSpaceC; mWorkSpaces[ 3] = &mWorkSpaceD;
    mWorkSpaces[ 4] = &mWorkSpaceE; mWorkSpaces[ 5] = &mWorkSpaceF; mWorkSpaces[ 6] = &mWorkSpaceG; mWorkSpaces[ 7] = &mWorkSpaceH;
    mWorkSpaces[ 8] = &mWorkSpaceI; mWorkSpaces[ 9] = &mWorkSpaceJ; mWorkSpaces[10] = &mWorkSpaceK; mWorkSpaces[11] = &mWorkSpaceL;
    mWorkSpaces[12] = &mWorkSpaceM; mWorkSpaces[13] = &mWorkSpaceN; mWorkSpaces[14] = &mWorkSpaceO; mWorkSpaces[15] = &mWorkSpaceP;

    mMasks[0] = 0xF0u; mMasks[1] = 0x0Fu; mMasks[2] = 0x33u; mMasks[3] = 0xCCu;
    mMasks[4] = 0x55u; mMasks[5] = 0xAAu; mMasks[6] = 0x69u; mMasks[7] = 0x96u;
    mMasks[8] = 0x19u; mMasks[9] = 0x98u; mMasks[10] = 0x1Au; mMasks[11] = 0x58u;
    mMasks[12] = 0x1Cu; mMasks[13] = 0x38u; mMasks[14] = 0x25u; mMasks[15] = 0xA4u;
    mMasks[16] = 0x26u; mMasks[17] = 0x64u; mMasks[18] = 0x2Cu; mMasks[19] = 0x34u;
    mMasks[20] = 0x43u; mMasks[21] = 0xC2u; mMasks[22] = 0x46u; mMasks[23] = 0x62u;
    mMasks[24] = 0x4Au; mMasks[25] = 0x52u; mMasks[26] = 0x83u; mMasks[27] = 0xC1u;
    mMasks[28] = 0x85u; mMasks[29] = 0xA1u; mMasks[30] = 0x89u; mMasks[31] = 0x91u;
    
    mMaterials[ 0] = mMaterialA; mMaterials[ 1] = mMaterialB; mMaterials[ 2] = mMaterialC; mMaterials[ 3] = mMaterialD;
    mMaterials[ 4] = mMaterialE; mMaterials[ 5] = mMaterialF; mMaterials[ 6] = mMaterialG; mMaterials[ 7] = mMaterialH;
    mMaterials[ 8] = mMaterialI; mMaterials[ 9] = mMaterialJ; mMaterials[10] = mMaterialK; mMaterials[11] = mMaterialL;
    mMaterials[12] = mMaterialM; mMaterials[13] = mMaterialN; mMaterials[14] = mMaterialO; mMaterials[15] = mMaterialP;
    
    mExpanders[0] = &mAchernar; mExpanders[1] = &mAlcor; mExpanders[2] = &mAldebaran; mExpanders[3] = &mAlioth;
    mExpanders[4] = &mAlkaid; mExpanders[5] = &mAlnitak; mExpanders[6] = &mAltair; mExpanders[7] = &mAnkaa;
    mExpanders[8] = &mAntares; mExpanders[9] = &mArcturus; mExpanders[10] = &mAthebyne; mExpanders[11] = &mBellatrix;
    mExpanders[12] = &mBetelgeuse; mExpanders[13] = &mCanopus; mExpanders[14] = &mCapella; mExpanders[15] = &mCastor;
    mExpanders[16] = &mMebsuta; mExpanders[17] = &mMenkent; mExpanders[18] = &mMimosa; mExpanders[19] = &mMiram;
    mExpanders[20] = &mMirfak; mExpanders[21] = &mMothallah; mExpanders[22] = &mNaos; mExpanders[23] = &mPolaris;
    mExpanders[24] = &mPollux; mExpanders[25] = &mProcyon; mExpanders[26] = &mRegulus; mExpanders[27] = &mRigel;
    mExpanders[28] = &mSaiph; mExpanders[29] = &mSirius; mExpanders[30] = &mSuhail; mExpanders[31] = &mVega;
    
    
    mCiphersIdentifiersA[40] = 1; mCiphersIdentifiersA[41] = 2; mCiphersIdentifiersA[42] = 0; mCiphersIdentifiersA[43] = 1;
    mCiphersIdentifiersA[12] = 0; mCiphersIdentifiersA[13] = 1; mCiphersIdentifiersA[14] = 2; mCiphersIdentifiersA[15] = 0;
    mCiphersIdentifiersB[ 0] = 0; mCiphersIdentifiersB[ 1] = 1; mCiphersIdentifiersB[ 2] = 2; mCiphersIdentifiersB[ 3] = 3;
    mCiphersIdentifiersB[ 4] = 4; mCiphersIdentifiersB[ 5] = 0; mCiphersIdentifiersB[ 6] = 1; mCiphersIdentifiersB[ 7] = 2;
    mCiphersIdentifiersB[52] = 2; mCiphersIdentifiersB[53] = 3; mCiphersIdentifiersB[54] = 5; mCiphersIdentifiersB[55] = 5;
    mCiphersIdentifiersA[16] = 1; mCiphersIdentifiersA[17] = 2; mCiphersIdentifiersA[18] = 0; mCiphersIdentifiersA[19] = 1;
    mCiphersIdentifiersA[20] = 2; mCiphersIdentifiersA[21] = 0; mCiphersIdentifiersA[22] = 1; mCiphersIdentifiersA[23] = 2;
    mCiphersIdentifiersA[36] = 0; mCiphersIdentifiersA[37] = 1; mCiphersIdentifiersA[38] = 2; mCiphersIdentifiersA[39] = 0;
    mCiphersIdentifiersA[44] = 2; mCiphersIdentifiersA[45] = 0; mCiphersIdentifiersA[46] = 1; mCiphersIdentifiersA[47] = 2;
    mCiphersIdentifiersB[48] = 3; mCiphersIdentifiersB[49] = 4; mCiphersIdentifiersB[50] = 0; mCiphersIdentifiersB[51] = 1;
    mCiphersIdentifiersA[56] = 2; mCiphersIdentifiersA[57] = 0; mCiphersIdentifiersA[58] = 1; mCiphersIdentifiersA[59] = 2;
    mCiphersIdentifiersA[ 4] = 1; mCiphersIdentifiersA[ 5] = 2; mCiphersIdentifiersA[ 6] = 0; mCiphersIdentifiersA[ 7] = 1;
    mCiphersIdentifiersA[ 8] = 2; mCiphersIdentifiersA[ 9] = 0; mCiphersIdentifiersA[10] = 1; mCiphersIdentifiersA[11] = 2;
    mCiphersIdentifiersB[40] = 0; mCiphersIdentifiersB[41] = 1; mCiphersIdentifiersB[42] = 2; mCiphersIdentifiersB[43] = 3;
    mCiphersIdentifiersB[44] = 4; mCiphersIdentifiersB[45] = 0; mCiphersIdentifiersB[46] = 1; mCiphersIdentifiersB[47] = 2;
    mCiphersIdentifiersA[ 0] = 0; mCiphersIdentifiersA[ 1] = 1; mCiphersIdentifiersA[ 2] = 2; mCiphersIdentifiersA[ 3] = 0;
    mCiphersIdentifiersA[48] = 0; mCiphersIdentifiersA[49] = 1; mCiphersIdentifiersA[50] = 2; mCiphersIdentifiersA[51] = 0;
    mCiphersIdentifiersA[52] = 1; mCiphersIdentifiersA[53] = 2; mCiphersIdentifiersA[54] = 0; mCiphersIdentifiersA[55] = 1;
    mCiphersIdentifiersB[20] = 0; mCiphersIdentifiersB[21] = 1; mCiphersIdentifiersB[22] = 2; mCiphersIdentifiersB[23] = 3;
    mCiphersIdentifiersB[32] = 2; mCiphersIdentifiersB[33] = 3; mCiphersIdentifiersB[34] = 4; mCiphersIdentifiersB[35] = 0;
    mCiphersIdentifiersB[36] = 1; mCiphersIdentifiersB[37] = 2; mCiphersIdentifiersB[38] = 3; mCiphersIdentifiersB[39] = 4;
    mCiphersIdentifiersA[24] = 0; mCiphersIdentifiersA[25] = 1; mCiphersIdentifiersA[26] = 2; mCiphersIdentifiersA[27] = 0;
    mCiphersIdentifiersB[56] = 6; mCiphersIdentifiersB[57] = 6; mCiphersIdentifiersB[58] = 7; mCiphersIdentifiersB[59] = 7;
    mCiphersIdentifiersB[60] = 8; mCiphersIdentifiersB[61] = 8; mCiphersIdentifiersB[62] = 9; mCiphersIdentifiersB[63] = 9;
    mCiphersIdentifiersA[32] = 2; mCiphersIdentifiersA[33] = 0; mCiphersIdentifiersA[34] = 1; mCiphersIdentifiersA[35] = 2;
    mCiphersIdentifiersB[ 8] = 3; mCiphersIdentifiersB[ 9] = 4; mCiphersIdentifiersB[10] = 0; mCiphersIdentifiersB[11] = 1;
    mCiphersIdentifiersB[12] = 2; mCiphersIdentifiersB[13] = 3; mCiphersIdentifiersB[14] = 4; mCiphersIdentifiersB[15] = 0;
    mCiphersIdentifiersA[28] = 1; mCiphersIdentifiersA[29] = 2; mCiphersIdentifiersA[30] = 0; mCiphersIdentifiersA[31] = 1;
    mCiphersIdentifiersB[16] = 1; mCiphersIdentifiersB[17] = 2; mCiphersIdentifiersB[18] = 3; mCiphersIdentifiersB[19] = 4;
    mCiphersIdentifiersA[60] = 0; mCiphersIdentifiersA[61] = 1; mCiphersIdentifiersA[62] = 2; mCiphersIdentifiersA[63] = 0;
    mCiphersIdentifiersB[24] = 4; mCiphersIdentifiersB[25] = 0; mCiphersIdentifiersB[26] = 1; mCiphersIdentifiersB[27] = 2;
    mCiphersIdentifiersB[28] = 3; mCiphersIdentifiersB[29] = 4; mCiphersIdentifiersB[30] = 0; mCiphersIdentifiersB[31] = 1;
    
    std::uint8_t aNonceBytes[8] = {
        static_cast<std::uint8_t>(pNonce >>  0),
        static_cast<std::uint8_t>(pNonce >>  8),
        static_cast<std::uint8_t>(pNonce >> 16),
        static_cast<std::uint8_t>(pNonce >> 24),
        static_cast<std::uint8_t>(pNonce >> 32),
        static_cast<std::uint8_t>(pNonce >> 40),
        static_cast<std::uint8_t>(pNonce >> 48),
        static_cast<std::uint8_t>(pNonce >> 56)
    };
    
    std::size_t aScratchIndex = 0;
    while (aScratchIndex < S_BLOCK) {
        for (int aByteIndex=0; (aByteIndex<8) && (aScratchIndex<S_BLOCK); aByteIndex++) {
            mScratch[aScratchIndex++] = aNonceBytes[aByteIndex];
        }
        for (int aByteIndex=0; (aByteIndex<pPasswordByteLength) && (aScratchIndex<S_BLOCK); aByteIndex++) {
            mScratch[aScratchIndex++] = pPassword[aByteIndex];
        }
    }
    
    mStarter.Seed(&mWorkSpaceA,
                &mFarmSalt,
                pNonce,
                pPassword,
                pPasswordByteLength,
                mRandom);

    // Block 0: masks, 32 entries
    for (std::size_t aIndex=0; aIndex<4096; aIndex+=2) {
        std::uint8_t aIndexA = mRandom[aIndex + 0] & 31U;
        std::uint8_t aIndexB = mRandom[aIndex + 1] & 31U;
        std::uint8_t aHold = mMasks[aIndexA];
        mMasks[aIndexA] = mMasks[aIndexB];
        mMasks[aIndexB] = aHold;
    }

    // Block 1: expanders, 32 entries
    for (std::size_t aIndex=4096; aIndex<8192; aIndex+=2) {
        std::uint8_t aIndexA = mRandom[aIndex + 0] & 31U;
        std::uint8_t aIndexB = mRandom[aIndex + 1] & 31U;
        TwistExpander *aHold = mExpanders[aIndexA];
        mExpanders[aIndexA] = mExpanders[aIndexB];
        mExpanders[aIndexB] = aHold;
    }

    // Block 2: work spaces, 16 entries
    for (std::size_t aIndex=8192; aIndex<12288; aIndex+=2) {
        std::uint8_t aIndexA = mRandom[aIndex + 0] & 15U;
        std::uint8_t aIndexB = mRandom[aIndex + 1] & 15U;
        TwistWorkSpace *aHold = mWorkSpaces[aIndexA];
        mWorkSpaces[aIndexA] = mWorkSpaces[aIndexB];
        mWorkSpaces[aIndexB] = aHold;
    }
    
    // Block 3: materials, 16 entries
    for (std::size_t aIndex=12288; aIndex<16384; aIndex+=2) {
        std::uint8_t aIndexA = mRandom[aIndex + 0] & 15U;
        std::uint8_t aIndexB = mRandom[aIndex + 1] & 15U;
        std::uint8_t *aHold = mMaterials[aIndexA];
        mMaterials[aIndexA] = mMaterials[aIndexB];
        mMaterials[aIndexB] = aHold;
    }
    
    // Block 4: cipher identifiers A, 64 entries
    for (std::size_t aIndex=16384; aIndex<20480; aIndex+=2) {
        std::uint8_t aIndexA = mRandom[aIndex + 0] & 63U;
        std::uint8_t aIndexB = mRandom[aIndex + 1] & 63U;
        std::uint8_t aHold = mCiphersIdentifiersA[aIndexA];
        mCiphersIdentifiersA[aIndexA] = mCiphersIdentifiersA[aIndexB];
        mCiphersIdentifiersA[aIndexB] = aHold;
    }

    // Block 5: cipher identifiers B, 64 entries
    for (std::size_t aIndex=20480; aIndex<24576; aIndex+=2) {
        std::uint8_t aIndexA = mRandom[aIndex + 0] & 63U;
        std::uint8_t aIndexB = mRandom[aIndex + 1] & 63U;
        std::uint8_t aHold = mCiphersIdentifiersB[aIndexA];
        mCiphersIdentifiersB[aIndexA] = mCiphersIdentifiersB[aIndexB];
        mCiphersIdentifiersB[aIndexB] = aHold;
    }

    // Block 6: re-shuffle expanders, 32 entries
    for (std::size_t aIndex=24576; aIndex<28672; aIndex+=2) {
        std::uint8_t aIndexA = mRandom[aIndex + 0] & 31U;
        std::uint8_t aIndexB = mRandom[aIndex + 1] & 31U;
        TwistExpander *aHold = mExpanders[aIndexA];
        mExpanders[aIndexA] = mExpanders[aIndexB];
        mExpanders[aIndexB] = aHold;
    }

    // Block 7: re-shuffle work spaces, 16 entries
    for (std::size_t aIndex=28672; aIndex<32768; aIndex+=2) {
        std::uint8_t aIndexA = mRandom[aIndex + 0] & 15U;
        std::uint8_t aIndexB = mRandom[aIndex + 1] & 15U;
        TwistWorkSpace *aHold = mWorkSpaces[aIndexA];
        mWorkSpaces[aIndexA] = mWorkSpaces[aIndexB];
        mWorkSpaces[aIndexB] = aHold;
    }
    
    return true;
}

void Soccer::SeedEpilogue() {
    
    for (std::size_t aIndex=0; aIndex<16; aIndex++) {
        mMaterials[aIndex] = mClaimedMaterials[aIndex];
    }
    for (std::size_t aIndex=0; aIndex<16; aIndex++) {
        mWorkSpaces[aIndex] = mClaimedWorkSpaces[aIndex];
    }
    
    mExpanders[0] = &mAchernar; mExpanders[1] = &mAlcor; mExpanders[2] = &mAldebaran; mExpanders[3] = &mAlioth;
    mExpanders[4] = &mAlkaid; mExpanders[5] = &mAlnitak; mExpanders[6] = &mAltair; mExpanders[7] = &mAnkaa;
    mExpanders[8] = &mAntares; mExpanders[9] = &mArcturus; mExpanders[10] = &mAthebyne; mExpanders[11] = &mBellatrix;
    mExpanders[12] = &mBetelgeuse; mExpanders[13] = &mCanopus; mExpanders[14] = &mCapella; mExpanders[15] = &mCastor;
    mExpanders[16] = &mMebsuta; mExpanders[17] = &mMenkent; mExpanders[18] = &mMimosa; mExpanders[19] = &mMiram;
    mExpanders[20] = &mMirfak; mExpanders[21] = &mMothallah; mExpanders[22] = &mNaos; mExpanders[23] = &mPolaris;
    mExpanders[24] = &mPollux; mExpanders[25] = &mProcyon; mExpanders[26] = &mRegulus; mExpanders[27] = &mRigel;
    mExpanders[28] = &mSaiph; mExpanders[29] = &mSirius; mExpanders[30] = &mSuhail; mExpanders[31] = &mVega;
    
    for (std::size_t aIndex=0; aIndex<16; aIndex++) {
        mSources[aIndex] = mMaterials[aIndex];
    }
    
    FoldAllMaterialsIntoRandomForBlock(0);
    ShuffleSEWMMCC();
    
    std::size_t aBlockIndex = 1;
    
    while (aBlockIndex < BLOCK_COUNT) {
        const std::size_t aSourceIndex = (aBlockIndex - 1U) * S_BLOCK;
        const std::size_t aDestinationIndex = aBlockIndex * S_BLOCK;
        
        mExpanders[11]->TwistBlock(mWorkSpaces[14], &mSources[ 2][aSourceIndex], &mMaterials[ 7][aDestinationIndex]);
        mExpanders[ 4]->TwistBlock(mWorkSpaces[ 7], &mSources[11][aSourceIndex], &mMaterials[ 0][aDestinationIndex]);
        mExpanders[15]->TwistBlock(mWorkSpaces[ 2], &mSources[ 6][aSourceIndex], &mMaterials[11][aDestinationIndex]);
        mExpanders[ 2]->TwistBlock(mWorkSpaces[ 5], &mSources[ 9][aSourceIndex], &mMaterials[14][aDestinationIndex]);
        mExpanders[ 9]->TwistBlock(mWorkSpaces[12], &mSources[ 0][aSourceIndex], &mMaterials[ 5][aDestinationIndex]);
        mExpanders[ 0]->TwistBlock(mWorkSpaces[ 3], &mSources[ 7][aSourceIndex], &mMaterials[12][aDestinationIndex]);
        mExpanders[13]->TwistBlock(mWorkSpaces[ 6], &mSources[ 4][aSourceIndex], &mMaterials[ 9][aDestinationIndex]);
        mExpanders[ 6]->TwistBlock(mWorkSpaces[ 9], &mSources[13][aSourceIndex], &mMaterials[ 2][aDestinationIndex]);
        mExpanders[ 1]->TwistBlock(mWorkSpaces[ 4], &mSources[ 8][aSourceIndex], &mMaterials[13][aDestinationIndex]);
        mExpanders[14]->TwistBlock(mWorkSpaces[ 1], &mSources[ 5][aSourceIndex], &mMaterials[10][aDestinationIndex]);
        mExpanders[ 7]->TwistBlock(mWorkSpaces[10], &mSources[14][aSourceIndex], &mMaterials[ 3][aDestinationIndex]);
        mExpanders[10]->TwistBlock(mWorkSpaces[13], &mSources[ 1][aSourceIndex], &mMaterials[ 6][aDestinationIndex]);
        mExpanders[ 3]->TwistBlock(mWorkSpaces[ 0], &mSources[10][aSourceIndex], &mMaterials[15][aDestinationIndex]);
        mExpanders[12]->TwistBlock(mWorkSpaces[15], &mSources[ 3][aSourceIndex], &mMaterials[ 8][aDestinationIndex]);
        mExpanders[ 5]->TwistBlock(mWorkSpaces[ 8], &mSources[12][aSourceIndex], &mMaterials[ 1][aDestinationIndex]);
        mExpanders[ 8]->TwistBlock(mWorkSpaces[11], &mSources[15][aSourceIndex], &mMaterials[ 4][aDestinationIndex]);
        
        FoldAllMaterialsIntoRandomForBlock(aBlockIndex);
        
        const std::size_t aReverseEndIndex = aDestinationIndex + S_BLOCK;
        for (std::size_t aMaterialIndex=0U; aMaterialIndex<4U; aMaterialIndex++) {
            std::reverse(mMaterials[aMaterialIndex] + aDestinationIndex,
                         mMaterials[aMaterialIndex] + aReverseEndIndex);
        }

        if (aBlockIndex == (BLOCK_COUNT - 1U)) {
            for (std::size_t aMaterialIndex=0U; aMaterialIndex<8U; aMaterialIndex++) {
                std::reverse(mMaterials[aMaterialIndex],
                             mMaterials[aMaterialIndex] + SOCCER_BLOCK_SIZE);
            }
        }
        
        ShuffleSEWMMCC();
        
        aBlockIndex++;
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
    
    std::uint64_t aRandFinalB = 0ULL;
    std::uint64_t aRandL1B = 0ULL;
    std::uint64_t aRandFinalA = 0ULL;
    std::uint64_t aRandL1A = 0ULL;
    std::uint64_t aRandL3A = 0ULL;
    std::uint64_t aRandL3B = 0ULL;
    std::uint64_t aRandL2B = 0ULL;
    std::uint64_t aRandL2A = 0ULL;
    
    constexpr std::size_t aRotSampleCount = S_BLOCK - sizeof(std::uint64_t) + 1U;
    std::size_t aRotSampleIndex = 0U;

    aRotSampleIndex += static_cast<std::size_t>(mMaterialM[13268U]) + static_cast<std::size_t>(mMaterialI[30513U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[15984U]) + static_cast<std::size_t>(mMaterialC[5212U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialF[4492U]) + static_cast<std::size_t>(mMaterialJ[436U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialG[22270U]) + static_cast<std::size_t>(mMaterialP[5459U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialN[27873U]) + static_cast<std::size_t>(mMaterialL[28586U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[20892U]) + static_cast<std::size_t>(mMaterialH[20567U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialA[20398U]) + static_cast<std::size_t>(mMaterialE[19163U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialO[1324U]) + static_cast<std::size_t>(mMaterialK[26568U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[38745U]) + static_cast<std::size_t>(mMaterialC[55734U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialN[41262U]) + static_cast<std::size_t>(mMaterialG[49571U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[51479U]) + static_cast<std::size_t>(mMaterialH[40893U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[52507U]) + static_cast<std::size_t>(mMaterialF[45388U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialO[63366U]) + static_cast<std::size_t>(mMaterialJ[56760U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialP[33278U]) + static_cast<std::size_t>(mMaterialA[52877U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialI[40064U]) + static_cast<std::size_t>(mMaterialK[58191U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialE[41577U]) + static_cast<std::size_t>(mMaterialM[50988U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[94774U]) + static_cast<std::size_t>(mMaterialD[86657U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialC[68044U]) + static_cast<std::size_t>(mMaterialH[74747U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialO[86906U]) + static_cast<std::size_t>(mMaterialL[91324U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialG[68382U]) + static_cast<std::size_t>(mMaterialI[76843U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialK[68523U]) + static_cast<std::size_t>(mMaterialJ[66795U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialN[66792U]) + static_cast<std::size_t>(mMaterialE[88548U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialM[75513U]) + static_cast<std::size_t>(mMaterialP[71661U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialA[69167U]) + static_cast<std::size_t>(mMaterialF[88235U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialP[104812U]) + static_cast<std::size_t>(mMaterialF[109521U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialJ[117056U]) + static_cast<std::size_t>(mMaterialB[108739U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[119108U]) + static_cast<std::size_t>(mMaterialA[113218U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialO[127689U]) + static_cast<std::size_t>(mMaterialC[118949U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[130668U]) + static_cast<std::size_t>(mMaterialK[107028U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialN[107307U]) + static_cast<std::size_t>(mMaterialI[128068U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialH[99570U]) + static_cast<std::size_t>(mMaterialE[106756U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialM[120270U]) + static_cast<std::size_t>(mMaterialG[103658U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialM[132394U]) + static_cast<std::size_t>(mMaterialE[137953U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialJ[161854U]) + static_cast<std::size_t>(mMaterialA[150384U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialI[151689U]) + static_cast<std::size_t>(mMaterialL[156551U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[140289U]) + static_cast<std::size_t>(mMaterialC[140674U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialP[157717U]) + static_cast<std::size_t>(mMaterialK[144926U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[159621U]) + static_cast<std::size_t>(mMaterialN[136868U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialG[144853U]) + static_cast<std::size_t>(mMaterialF[138709U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialO[156910U]) + static_cast<std::size_t>(mMaterialH[161195U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[187307U]) + static_cast<std::size_t>(mMaterialB[181489U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialO[169473U]) + static_cast<std::size_t>(mMaterialH[196592U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialF[179235U]) + static_cast<std::size_t>(mMaterialK[191425U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialM[174812U]) + static_cast<std::size_t>(mMaterialE[175796U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialI[164849U]) + static_cast<std::size_t>(mMaterialP[172225U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialC[186664U]) + static_cast<std::size_t>(mMaterialG[195640U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialN[191568U]) + static_cast<std::size_t>(mMaterialJ[184323U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[178363U]) + static_cast<std::size_t>(mMaterialA[183673U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialP[211932U]) + static_cast<std::size_t>(mMaterialC[218710U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialO[201968U]) + static_cast<std::size_t>(mMaterialL[226759U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialG[198442U]) + static_cast<std::size_t>(mMaterialK[218036U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialI[213409U]) + static_cast<std::size_t>(mMaterialH[205177U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialN[212609U]) + static_cast<std::size_t>(mMaterialM[220554U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[209314U]) + static_cast<std::size_t>(mMaterialB[197919U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialE[218906U]) + static_cast<std::size_t>(mMaterialA[228713U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialJ[217627U]) + static_cast<std::size_t>(mMaterialF[198664U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[261204U]) + static_cast<std::size_t>(mMaterialG[241114U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialO[247579U]) + static_cast<std::size_t>(mMaterialD[255244U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialN[240948U]) + static_cast<std::size_t>(mMaterialI[229401U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialM[242206U]) + static_cast<std::size_t>(mMaterialE[258546U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialA[239034U]) + static_cast<std::size_t>(mMaterialH[239382U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialP[252940U]) + static_cast<std::size_t>(mMaterialB[231241U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialK[240244U]) + static_cast<std::size_t>(mMaterialC[242944U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialF[242244U]) + static_cast<std::size_t>(mMaterialJ[231564U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialM[289199U]) + static_cast<std::size_t>(mMaterialG[284934U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialN[271838U]) + static_cast<std::size_t>(mMaterialF[282298U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialJ[262167U]) + static_cast<std::size_t>(mMaterialP[274745U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialE[286991U]) + static_cast<std::size_t>(mMaterialD[280662U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialA[263585U]) + static_cast<std::size_t>(mMaterialL[282215U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialK[282308U]) + static_cast<std::size_t>(mMaterialI[293778U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialC[274903U]) + static_cast<std::size_t>(mMaterialO[292511U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[266832U]) + static_cast<std::size_t>(mMaterialH[281535U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialM[295544U]) + static_cast<std::size_t>(mMaterialE[311717U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialJ[308822U]) + static_cast<std::size_t>(mMaterialC[326128U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialF[316482U]) + static_cast<std::size_t>(mMaterialP[295895U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialA[301620U]) + static_cast<std::size_t>(mMaterialK[313162U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[298493U]) + static_cast<std::size_t>(mMaterialG[310481U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[313204U]) + static_cast<std::size_t>(mMaterialI[309897U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialO[316368U]) + static_cast<std::size_t>(mMaterialL[317617U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialN[300877U]) + static_cast<std::size_t>(mMaterialH[323727U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialP[339827U]) + static_cast<std::size_t>(mMaterialA[355078U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialG[335802U]) + static_cast<std::size_t>(mMaterialM[355659U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialI[359973U]) + static_cast<std::size_t>(mMaterialN[346964U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[359275U]) + static_cast<std::size_t>(mMaterialF[347361U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialC[344016U]) + static_cast<std::size_t>(mMaterialL[353493U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[345613U]) + static_cast<std::size_t>(mMaterialE[334565U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialK[330169U]) + static_cast<std::size_t>(mMaterialJ[357581U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialO[354197U]) + static_cast<std::size_t>(mMaterialH[354898U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialO[384911U]) + static_cast<std::size_t>(mMaterialJ[378878U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[365488U]) + static_cast<std::size_t>(mMaterialF[363254U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialN[365168U]) + static_cast<std::size_t>(mMaterialI[386579U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialH[374397U]) + static_cast<std::size_t>(mMaterialM[373939U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[390897U]) + static_cast<std::size_t>(mMaterialA[371999U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialK[383709U]) + static_cast<std::size_t>(mMaterialP[379418U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[383860U]) + static_cast<std::size_t>(mMaterialC[376620U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialE[384517U]) + static_cast<std::size_t>(mMaterialG[366763U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[401902U]) + static_cast<std::size_t>(mMaterialF[407371U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialM[414243U]) + static_cast<std::size_t>(mMaterialC[418099U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[409905U]) + static_cast<std::size_t>(mMaterialK[424303U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialE[403810U]) + static_cast<std::size_t>(mMaterialG[411002U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialP[399709U]) + static_cast<std::size_t>(mMaterialA[413204U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialJ[415594U]) + static_cast<std::size_t>(mMaterialI[399048U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialH[393593U]) + static_cast<std::size_t>(mMaterialO[394616U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialN[403884U]) + static_cast<std::size_t>(mMaterialL[398186U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialH[439857U]) + static_cast<std::size_t>(mMaterialP[454953U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[440296U]) + static_cast<std::size_t>(mMaterialO[432647U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialA[449308U]) + static_cast<std::size_t>(mMaterialJ[447170U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialC[433906U]) + static_cast<std::size_t>(mMaterialE[435043U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialG[454273U]) + static_cast<std::size_t>(mMaterialK[428607U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialN[428201U]) + static_cast<std::size_t>(mMaterialF[446589U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialM[433265U]) + static_cast<std::size_t>(mMaterialB[446442U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialI[445984U]) + static_cast<std::size_t>(mMaterialL[449910U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialN[462450U]) + static_cast<std::size_t>(mMaterialD[463266U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialA[485381U]) + static_cast<std::size_t>(mMaterialJ[464590U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialF[486761U]) + static_cast<std::size_t>(mMaterialC[484466U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialM[468125U]) + static_cast<std::size_t>(mMaterialI[482900U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[467497U]) + static_cast<std::size_t>(mMaterialK[465566U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialO[484294U]) + static_cast<std::size_t>(mMaterialH[468756U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialP[486189U]) + static_cast<std::size_t>(mMaterialB[464936U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialG[485153U]) + static_cast<std::size_t>(mMaterialE[482590U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialE[507751U]) + static_cast<std::size_t>(mMaterialH[507618U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialF[504392U]) + static_cast<std::size_t>(mMaterialJ[509705U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialC[507610U]) + static_cast<std::size_t>(mMaterialB[513273U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialP[516566U]) + static_cast<std::size_t>(mMaterialA[498440U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[519531U]) + static_cast<std::size_t>(mMaterialO[522681U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialM[499823U]) + static_cast<std::size_t>(mMaterialI[507965U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialK[522963U]) + static_cast<std::size_t>(mMaterialN[511604U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[521756U]) + static_cast<std::size_t>(mMaterialG[516312U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialC[544509U]) + static_cast<std::size_t>(mMaterialO[549635U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialA[554357U]) + static_cast<std::size_t>(mMaterialI[525244U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialP[551625U]) + static_cast<std::size_t>(mMaterialM[544810U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[539168U]) + static_cast<std::size_t>(mMaterialJ[537109U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialE[544432U]) + static_cast<std::size_t>(mMaterialH[539688U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialG[551986U]) + static_cast<std::size_t>(mMaterialB[525753U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialK[532976U]) + static_cast<std::size_t>(mMaterialF[553087U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[540454U]) + static_cast<std::size_t>(mMaterialN[538284U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialJ[583530U]) + static_cast<std::size_t>(mMaterialM[577695U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[574875U]) + static_cast<std::size_t>(mMaterialE[588001U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialK[585932U]) + static_cast<std::size_t>(mMaterialA[582584U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialP[569287U]) + static_cast<std::size_t>(mMaterialG[575832U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialO[574205U]) + static_cast<std::size_t>(mMaterialI[561789U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialH[579853U]) + static_cast<std::size_t>(mMaterialD[573244U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialC[573238U]) + static_cast<std::size_t>(mMaterialF[576687U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[570459U]) + static_cast<std::size_t>(mMaterialN[570244U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialE[614514U]) + static_cast<std::size_t>(mMaterialM[619422U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialO[622497U]) + static_cast<std::size_t>(mMaterialC[612127U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialP[608756U]) + static_cast<std::size_t>(mMaterialL[605583U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialG[591090U]) + static_cast<std::size_t>(mMaterialJ[619085U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialH[619587U]) + static_cast<std::size_t>(mMaterialD[594601U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialF[620385U]) + static_cast<std::size_t>(mMaterialI[621479U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[600900U]) + static_cast<std::size_t>(mMaterialA[620380U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialN[614098U]) + static_cast<std::size_t>(mMaterialK[613571U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[645188U]) + static_cast<std::size_t>(mMaterialO[652313U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialG[639822U]) + static_cast<std::size_t>(mMaterialP[635806U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[634871U]) + static_cast<std::size_t>(mMaterialL[623014U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialK[651477U]) + static_cast<std::size_t>(mMaterialE[632442U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialM[638256U]) + static_cast<std::size_t>(mMaterialJ[654813U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialA[643378U]) + static_cast<std::size_t>(mMaterialC[632347U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialF[624374U]) + static_cast<std::size_t>(mMaterialI[645649U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialN[623348U]) + static_cast<std::size_t>(mMaterialH[628267U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialP[684337U]) + static_cast<std::size_t>(mMaterialA[672059U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialM[684332U]) + static_cast<std::size_t>(mMaterialH[664698U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialE[673913U]) + static_cast<std::size_t>(mMaterialD[680812U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialC[682340U]) + static_cast<std::size_t>(mMaterialJ[687321U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialO[680674U]) + static_cast<std::size_t>(mMaterialF[679257U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialK[656338U]) + static_cast<std::size_t>(mMaterialN[661272U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialI[676617U]) + static_cast<std::size_t>(mMaterialG[667505U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[679164U]) + static_cast<std::size_t>(mMaterialL[686758U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialO[699239U]) + static_cast<std::size_t>(mMaterialC[713876U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[703484U]) + static_cast<std::size_t>(mMaterialK[716869U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialH[705999U]) + static_cast<std::size_t>(mMaterialA[693965U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialG[692060U]) + static_cast<std::size_t>(mMaterialN[717931U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialJ[702279U]) + static_cast<std::size_t>(mMaterialF[690651U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialM[705119U]) + static_cast<std::size_t>(mMaterialE[707062U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[697354U]) + static_cast<std::size_t>(mMaterialD[696520U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialP[688926U]) + static_cast<std::size_t>(mMaterialI[697302U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[733135U]) + static_cast<std::size_t>(mMaterialM[735711U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialH[752864U]) + static_cast<std::size_t>(mMaterialJ[724037U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialE[729452U]) + static_cast<std::size_t>(mMaterialD[751740U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[737294U]) + static_cast<std::size_t>(mMaterialC[739772U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialF[727143U]) + static_cast<std::size_t>(mMaterialK[745821U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialP[725289U]) + static_cast<std::size_t>(mMaterialO[736921U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialI[739153U]) + static_cast<std::size_t>(mMaterialA[728092U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialG[740138U]) + static_cast<std::size_t>(mMaterialN[745793U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[766501U]) + static_cast<std::size_t>(mMaterialM[779762U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialH[773129U]) + static_cast<std::size_t>(mMaterialN[763739U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialF[762885U]) + static_cast<std::size_t>(mMaterialK[770178U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialP[757919U]) + static_cast<std::size_t>(mMaterialD[776353U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialI[762886U]) + static_cast<std::size_t>(mMaterialA[762786U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialC[764405U]) + static_cast<std::size_t>(mMaterialO[761119U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialJ[783562U]) + static_cast<std::size_t>(mMaterialL[758191U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialG[758793U]) + static_cast<std::size_t>(mMaterialE[781759U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialP[795437U]) + static_cast<std::size_t>(mMaterialL[795423U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialK[790773U]) + static_cast<std::size_t>(mMaterialB[808087U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialI[810342U]) + static_cast<std::size_t>(mMaterialG[818398U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[802603U]) + static_cast<std::size_t>(mMaterialA[791631U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialM[809189U]) + static_cast<std::size_t>(mMaterialJ[799138U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialF[813067U]) + static_cast<std::size_t>(mMaterialO[809290U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialN[814041U]) + static_cast<std::size_t>(mMaterialC[811438U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialH[802903U]) + static_cast<std::size_t>(mMaterialE[788237U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialA[850732U]) + static_cast<std::size_t>(mMaterialK[829947U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[839105U]) + static_cast<std::size_t>(mMaterialN[836154U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialC[849400U]) + static_cast<std::size_t>(mMaterialM[822791U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialH[841669U]) + static_cast<std::size_t>(mMaterialJ[820010U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialP[838629U]) + static_cast<std::size_t>(mMaterialG[839139U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialF[828192U]) + static_cast<std::size_t>(mMaterialI[848232U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialE[836131U]) + static_cast<std::size_t>(mMaterialO[832316U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[850853U]) + static_cast<std::size_t>(mMaterialB[851958U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialN[873358U]) + static_cast<std::size_t>(mMaterialB[877900U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialA[883750U]) + static_cast<std::size_t>(mMaterialK[854137U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialE[868611U]) + static_cast<std::size_t>(mMaterialG[866538U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialI[873826U]) + static_cast<std::size_t>(mMaterialP[864045U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[875026U]) + static_cast<std::size_t>(mMaterialM[860471U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[879346U]) + static_cast<std::size_t>(mMaterialO[860869U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialJ[862795U]) + static_cast<std::size_t>(mMaterialH[854505U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialC[857354U]) + static_cast<std::size_t>(mMaterialF[858285U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[892563U]) + static_cast<std::size_t>(mMaterialK[892550U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialP[888653U]) + static_cast<std::size_t>(mMaterialD[887665U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialH[887390U]) + static_cast<std::size_t>(mMaterialB[900944U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialA[914585U]) + static_cast<std::size_t>(mMaterialO[910856U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialJ[887233U]) + static_cast<std::size_t>(mMaterialG[888527U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialE[895821U]) + static_cast<std::size_t>(mMaterialM[916848U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialC[903483U]) + static_cast<std::size_t>(mMaterialI[900346U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialN[911521U]) + static_cast<std::size_t>(mMaterialF[909916U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialM[949288U]) + static_cast<std::size_t>(mMaterialB[924299U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialP[932354U]) + static_cast<std::size_t>(mMaterialG[941653U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[929589U]) + static_cast<std::size_t>(mMaterialN[946555U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialE[924973U]) + static_cast<std::size_t>(mMaterialD[941864U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialK[927145U]) + static_cast<std::size_t>(mMaterialJ[931193U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialO[933582U]) + static_cast<std::size_t>(mMaterialF[934661U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialI[937576U]) + static_cast<std::size_t>(mMaterialA[943642U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialH[945302U]) + static_cast<std::size_t>(mMaterialC[939366U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[959567U]) + static_cast<std::size_t>(mMaterialB[959340U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialM[960313U]) + static_cast<std::size_t>(mMaterialK[962440U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialI[971702U]) + static_cast<std::size_t>(mMaterialD[953867U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialO[962026U]) + static_cast<std::size_t>(mMaterialC[972456U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialE[979830U]) + static_cast<std::size_t>(mMaterialA[958890U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialG[975957U]) + static_cast<std::size_t>(mMaterialF[977655U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialH[965135U]) + static_cast<std::size_t>(mMaterialP[974020U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialJ[975885U]) + static_cast<std::size_t>(mMaterialN[975679U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialC[985284U]) + static_cast<std::size_t>(mMaterialG[1006527U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[999589U]) + static_cast<std::size_t>(mMaterialN[1008638U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialK[999491U]) + static_cast<std::size_t>(mMaterialJ[1000953U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialE[998854U]) + static_cast<std::size_t>(mMaterialA[1004381U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialM[1012716U]) + static_cast<std::size_t>(mMaterialP[1002843U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[1003486U]) + static_cast<std::size_t>(mMaterialH[991200U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialO[996922U]) + static_cast<std::size_t>(mMaterialF[1004393U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialI[989712U]) + static_cast<std::size_t>(mMaterialB[1002161U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    aRotSampleIndex += static_cast<std::size_t>(mMaterialI[1027619U]) + static_cast<std::size_t>(mMaterialO[1038909U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[1019834U]) + static_cast<std::size_t>(mMaterialG[1031464U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialM[1041729U]) + static_cast<std::size_t>(mMaterialF[1046005U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialE[1033633U]) + static_cast<std::size_t>(mMaterialL[1047040U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialP[1031293U]) + static_cast<std::size_t>(mMaterialB[1045749U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialA[1037084U]) + static_cast<std::size_t>(mMaterialN[1040007U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialJ[1032171U]) + static_cast<std::size_t>(mMaterialH[1041811U]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialC[1027927U]) + static_cast<std::size_t>(mMaterialK[1042061U]);

    aRotSampleIndex %= aRotSampleCount;

    auto AdvanceRotSample = [&](std::uint64_t pMix, std::size_t pHop) {
        const std::size_t aNearIndex = (aRotSampleIndex + 8U + pHop) % S_BLOCK;
        const std::size_t aFarIndex = static_cast<std::size_t>((pMix ^ (pMix >> 32U)) % S_BLOCK);
        aRotSampleIndex = (aRotSampleIndex + mRandom[aNearIndex] + mRandom[aFarIndex] + pHop) % aRotSampleCount;
    };

    auto MixRotRoundA = [&](std::uint64_t &pValue, std::size_t pHop, std::uint64_t pRotation) {

        const std::uint64_t aSample = Read64(&mRandom[aRotSampleIndex]);
        pValue = (pValue ^ aSample) + RotL64(pValue + pHop, pRotation);
        AdvanceRotSample(pValue ^ RotL64(aSample, pRotation), pHop);
    };

    auto MixRotRoundB = [&](std::uint64_t &pValue, std::size_t pHop, std::uint64_t pRotation) {

        const std::uint64_t aSample = Read64(&mRandom[aRotSampleIndex]);
        pValue = RotL64(pValue ^ aSample, pRotation) + (aSample ^ static_cast<std::uint64_t>(pHop));
        AdvanceRotSample(pValue + RotL64(aSample + pValue, pRotation), pHop);
    };
    MixRotRoundA(aRandL3B, mMaterialB[700083U], mMaterialA[906320U]);
    MixRotRoundA(aRandL3A, mMaterialI[763743U], mMaterialE[371481U]);
    MixRotRoundA(aRandL2A, mMaterialN[851673U], mMaterialG[175136U]);
    MixRotRoundA(aRandFinalB, mMaterialJ[241663U], mMaterialM[119337U]);
    MixRotRoundA(aRandL1B, mMaterialF[817205U], mMaterialD[733776U]);
    MixRotRoundA(aRandL1A, mMaterialH[593380U], mMaterialO[511517U]);
    MixRotRoundA(aRandFinalA, mMaterialL[563785U], mMaterialC[206397U]);
    MixRotRoundA(aRandL2B, mMaterialP[58922U], mMaterialK[881986U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundB(aRandL1A, mMaterialB[269845U], mMaterialH[27020U]);
    MixRotRoundB(aRandFinalB, mMaterialC[929180U], mMaterialE[1005140U]);
    MixRotRoundB(aRandL3B, mMaterialJ[767414U], mMaterialP[670183U]);
    MixRotRoundB(aRandL1B, mMaterialK[1035935U], mMaterialM[303125U]);
    MixRotRoundB(aRandL2A, mMaterialI[184036U], mMaterialF[879973U]);
    MixRotRoundB(aRandL3A, mMaterialD[530148U], mMaterialO[335396U]);
    MixRotRoundB(aRandL2B, mMaterialA[833777U], mMaterialG[83401U]);
    MixRotRoundB(aRandFinalA, mMaterialN[750176U], mMaterialL[519737U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundA(aRandFinalB, mMaterialP[1008089U], mMaterialN[57836U]);
    MixRotRoundA(aRandL2B, mMaterialA[448999U], mMaterialC[339057U]);
    MixRotRoundA(aRandL2A, mMaterialL[862794U], mMaterialE[93666U]);
    MixRotRoundA(aRandL1A, mMaterialI[938994U], mMaterialB[249271U]);
    MixRotRoundA(aRandL1B, mMaterialG[112982U], mMaterialO[1022881U]);
    MixRotRoundA(aRandL3B, mMaterialF[487023U], mMaterialH[560705U]);
    MixRotRoundA(aRandL3A, mMaterialD[659129U], mMaterialM[283406U]);
    MixRotRoundA(aRandFinalA, mMaterialK[146018U], mMaterialJ[205171U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundB(aRandL1B, mMaterialH[867028U], mMaterialG[292700U]);
    MixRotRoundB(aRandL1A, mMaterialL[142575U], mMaterialP[885737U]);
    MixRotRoundB(aRandL2A, mMaterialE[303190U], mMaterialI[716722U]);
    MixRotRoundB(aRandFinalA, mMaterialF[727156U], mMaterialA[368582U]);
    MixRotRoundB(aRandL2B, mMaterialC[653064U], mMaterialN[1002484U]);
    MixRotRoundB(aRandFinalB, mMaterialM[757929U], mMaterialO[619374U]);
    MixRotRoundB(aRandL3A, mMaterialJ[342837U], mMaterialD[410937U]);
    MixRotRoundB(aRandL3B, mMaterialB[197481U], mMaterialK[529312U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundA(aRandL3B, mMaterialN[549770U], mMaterialC[109163U]);
    MixRotRoundA(aRandFinalB, mMaterialA[739898U], mMaterialG[916076U]);
    MixRotRoundA(aRandL3A, mMaterialM[441530U], mMaterialO[695127U]);
    MixRotRoundA(aRandL2A, mMaterialI[72643U], mMaterialH[217530U]);
    MixRotRoundA(aRandFinalA, mMaterialJ[174457U], mMaterialF[1048202U]);
    MixRotRoundA(aRandL1A, mMaterialL[356795U], mMaterialB[953693U]);
    MixRotRoundA(aRandL2B, mMaterialP[796007U], mMaterialD[580443U]);
    MixRotRoundA(aRandL1B, mMaterialK[622691U], mMaterialE[393461U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundB(aRandL1A, mMaterialE[844595U], mMaterialO[261395U]);
    MixRotRoundB(aRandL3B, mMaterialB[179335U], mMaterialJ[122434U]);
    MixRotRoundB(aRandL3A, mMaterialM[387845U], mMaterialK[29279U]);
    MixRotRoundB(aRandL1B, mMaterialC[283425U], mMaterialH[329930U]);
    MixRotRoundB(aRandL2A, mMaterialG[433931U], mMaterialN[801602U]);
    MixRotRoundB(aRandFinalB, mMaterialL[632005U], mMaterialF[596385U]);
    MixRotRoundB(aRandL2B, mMaterialD[883644U], mMaterialI[319398U]);
    MixRotRoundB(aRandFinalA, mMaterialP[472844U], mMaterialA[675296U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundA(aRandFinalA, mMaterialO[84995U], mMaterialH[965632U]);
    MixRotRoundA(aRandL2A, mMaterialC[1011322U], mMaterialK[124942U]);
    MixRotRoundA(aRandL1A, mMaterialP[6112U], mMaterialJ[44835U]);
    MixRotRoundA(aRandL3B, mMaterialL[175976U], mMaterialD[238921U]);
    MixRotRoundA(aRandL3A, mMaterialF[932841U], mMaterialN[639905U]);
    MixRotRoundA(aRandFinalB, mMaterialB[831763U], mMaterialA[1027342U]);
    MixRotRoundA(aRandL2B, mMaterialE[580031U], mMaterialI[655372U]);
    MixRotRoundA(aRandL1B, mMaterialM[458897U], mMaterialG[801368U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundB(aRandFinalB, mMaterialA[705520U], mMaterialH[56286U]);
    MixRotRoundB(aRandL2A, mMaterialK[888772U], mMaterialG[501582U]);
    MixRotRoundB(aRandL1A, mMaterialI[572237U], mMaterialM[1021214U]);
    MixRotRoundB(aRandFinalA, mMaterialF[70360U], mMaterialO[394815U]);
    MixRotRoundB(aRandL3A, mMaterialC[804774U], mMaterialE[228329U]);
    MixRotRoundB(aRandL2B, mMaterialD[971461U], mMaterialJ[537403U]);
    MixRotRoundB(aRandL3B, mMaterialP[765326U], mMaterialL[1003704U]);
    MixRotRoundB(aRandL1B, mMaterialB[142424U], mMaterialN[264601U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundA(aRandL1A, mMaterialK[604423U], mMaterialF[145669U]);
    MixRotRoundA(aRandL2A, mMaterialO[631724U], mMaterialA[41042U]);
    MixRotRoundA(aRandL3A, mMaterialJ[927216U], mMaterialI[117139U]);
    MixRotRoundA(aRandL3B, mMaterialC[689633U], mMaterialE[910253U]);
    MixRotRoundA(aRandFinalB, mMaterialD[799875U], mMaterialH[500857U]);
    MixRotRoundA(aRandFinalA, mMaterialG[296252U], mMaterialB[758749U]);
    MixRotRoundA(aRandL2B, mMaterialN[684133U], mMaterialM[964694U]);
    MixRotRoundA(aRandL1B, mMaterialL[1042425U], mMaterialP[397732U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundB(aRandL1A, mMaterialJ[492149U], mMaterialH[798612U]);
    MixRotRoundB(aRandFinalA, mMaterialC[1040816U], mMaterialF[825192U]);
    MixRotRoundB(aRandL3A, mMaterialB[25725U], mMaterialN[366056U]);
    MixRotRoundB(aRandL2B, mMaterialA[952748U], mMaterialK[727524U]);
    MixRotRoundB(aRandL1B, mMaterialM[235327U], mMaterialP[86013U]);
    MixRotRoundB(aRandFinalB, mMaterialI[360092U], mMaterialE[115770U]);
    MixRotRoundB(aRandL2A, mMaterialG[718701U], mMaterialO[144529U]);
    MixRotRoundB(aRandL3B, mMaterialL[472935U], mMaterialD[1005709U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundA(aRandFinalA, mMaterialM[639687U], mMaterialB[612313U]);
    MixRotRoundA(aRandL3B, mMaterialF[913119U], mMaterialD[380614U]);
    MixRotRoundA(aRandFinalB, mMaterialH[664393U], mMaterialL[416474U]);
    MixRotRoundA(aRandL2B, mMaterialE[947213U], mMaterialP[181617U]);
    MixRotRoundA(aRandL1B, mMaterialJ[567780U], mMaterialA[264708U]);
    MixRotRoundA(aRandL1A, mMaterialK[846700U], mMaterialN[969983U]);
    MixRotRoundA(aRandL3A, mMaterialC[860868U], mMaterialG[333044U]);
    MixRotRoundA(aRandL2A, mMaterialI[492378U], mMaterialO[468357U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundB(aRandL2B, mMaterialP[630442U], mMaterialJ[823318U]);
    MixRotRoundB(aRandL3B, mMaterialD[719815U], mMaterialA[512968U]);
    MixRotRoundB(aRandFinalB, mMaterialK[166989U], mMaterialB[411820U]);
    MixRotRoundB(aRandFinalA, mMaterialE[596141U], mMaterialI[741546U]);
    MixRotRoundB(aRandL1B, mMaterialO[366653U], mMaterialN[336780U]);
    MixRotRoundB(aRandL2A, mMaterialF[775543U], mMaterialL[950859U]);
    MixRotRoundB(aRandL1A, mMaterialH[305357U], mMaterialG[525402U]);
    MixRotRoundB(aRandL3A, mMaterialM[797077U], mMaterialC[63483U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundA(aRandL2B, mMaterialH[109254U], mMaterialN[503078U]);
    MixRotRoundA(aRandFinalB, mMaterialK[769014U], mMaterialO[953570U]);
    MixRotRoundA(aRandL3A, mMaterialM[669439U], mMaterialJ[901540U]);
    MixRotRoundA(aRandL1B, mMaterialI[822413U], mMaterialG[739802U]);
    MixRotRoundA(aRandFinalA, mMaterialL[270363U], mMaterialE[152699U]);
    MixRotRoundA(aRandL2A, mMaterialD[346572U], mMaterialA[569629U]);
    MixRotRoundA(aRandL3B, mMaterialC[437690U], mMaterialB[1015700U]);
    MixRotRoundA(aRandL1A, mMaterialF[231142U], mMaterialP[1040917U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundB(aRandL3A, mMaterialD[608915U], mMaterialJ[969915U]);
    MixRotRoundB(aRandL2A, mMaterialO[936276U], mMaterialG[984451U]);
    MixRotRoundB(aRandL2B, mMaterialE[673847U], mMaterialK[358121U]);
    MixRotRoundB(aRandFinalB, mMaterialI[365648U], mMaterialH[230106U]);
    MixRotRoundB(aRandL1A, mMaterialL[209531U], mMaterialF[495427U]);
    MixRotRoundB(aRandL3B, mMaterialM[894834U], mMaterialA[474208U]);
    MixRotRoundB(aRandL1B, mMaterialN[145225U], mMaterialC[169001U]);
    MixRotRoundB(aRandFinalA, mMaterialB[301872U], mMaterialP[551681U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundA(aRandL2B, mMaterialM[994369U], mMaterialL[256880U]);
    MixRotRoundA(aRandFinalA, mMaterialD[1040831U], mMaterialP[151007U]);
    MixRotRoundA(aRandL3B, mMaterialO[756230U], mMaterialA[812553U]);
    MixRotRoundA(aRandFinalB, mMaterialC[962577U], mMaterialI[448770U]);
    MixRotRoundA(aRandL1A, mMaterialB[75928U], mMaterialN[878431U]);
    MixRotRoundA(aRandL3A, mMaterialH[690200U], mMaterialK[208297U]);
    MixRotRoundA(aRandL2A, mMaterialJ[309350U], mMaterialG[63021U]);
    MixRotRoundA(aRandL1B, mMaterialF[27496U], mMaterialE[747330U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundB(aRandL2A, mMaterialB[950048U], mMaterialA[1003994U]);
    MixRotRoundB(aRandL3B, mMaterialD[469570U], mMaterialK[585608U]);
    MixRotRoundB(aRandL1B, mMaterialI[280842U], mMaterialF[543062U]);
    MixRotRoundB(aRandL2B, mMaterialN[399303U], mMaterialG[955644U]);
    MixRotRoundB(aRandL1A, mMaterialJ[707802U], mMaterialE[437142U]);
    MixRotRoundB(aRandFinalB, mMaterialP[839350U], mMaterialC[246350U]);
    MixRotRoundB(aRandL3A, mMaterialH[1021723U], mMaterialM[179852U]);
    MixRotRoundB(aRandFinalA, mMaterialO[21774U], mMaterialL[604851U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundA(aRandL2B, mMaterialL[938535U], mMaterialA[152176U]);
    MixRotRoundA(aRandL1A, mMaterialG[417795U], mMaterialD[5200U]);
    MixRotRoundA(aRandL3A, mMaterialB[430475U], mMaterialO[124941U]);
    MixRotRoundA(aRandFinalB, mMaterialJ[360491U], mMaterialC[84800U]);
    MixRotRoundA(aRandL1B, mMaterialF[357185U], mMaterialK[695764U]);
    MixRotRoundA(aRandFinalA, mMaterialI[1000278U], mMaterialN[600757U]);
    MixRotRoundA(aRandL3B, mMaterialP[570744U], mMaterialE[789140U]);
    MixRotRoundA(aRandL2A, mMaterialH[755584U], mMaterialM[837551U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundB(aRandFinalA, mMaterialJ[802449U], mMaterialA[235346U]);
    MixRotRoundB(aRandL1A, mMaterialG[1028472U], mMaterialF[314646U]);
    MixRotRoundB(aRandFinalB, mMaterialK[435187U], mMaterialC[479251U]);
    MixRotRoundB(aRandL2B, mMaterialO[829213U], mMaterialI[863007U]);
    MixRotRoundB(aRandL3B, mMaterialN[783522U], mMaterialB[545762U]);
    MixRotRoundB(aRandL2A, mMaterialP[917939U], mMaterialE[338689U]);
    MixRotRoundB(aRandL3A, mMaterialD[174247U], mMaterialM[593926U]);
    MixRotRoundB(aRandL1B, mMaterialH[1012593U], mMaterialL[901046U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundA(aRandL1A, mMaterialJ[740542U], mMaterialC[685395U]);
    MixRotRoundA(aRandL3B, mMaterialP[245174U], mMaterialA[336508U]);
    MixRotRoundA(aRandL2B, mMaterialO[986953U], mMaterialL[381512U]);
    MixRotRoundA(aRandL3A, mMaterialK[82775U], mMaterialI[535045U]);
    MixRotRoundA(aRandL2A, mMaterialB[465271U], mMaterialE[11424U]);
    MixRotRoundA(aRandFinalB, mMaterialM[858509U], mMaterialH[452160U]);
    MixRotRoundA(aRandFinalA, mMaterialD[291535U], mMaterialF[189121U]);
    MixRotRoundA(aRandL1B, mMaterialN[712395U], mMaterialG[566720U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundB(aRandL1B, mMaterialH[843737U], mMaterialK[996917U]);
    MixRotRoundB(aRandL3B, mMaterialN[113189U], mMaterialC[529931U]);
    MixRotRoundB(aRandL2B, mMaterialJ[149459U], mMaterialA[944549U]);
    MixRotRoundB(aRandL3A, mMaterialE[260501U], mMaterialM[503177U]);
    MixRotRoundB(aRandL2A, mMaterialL[52855U], mMaterialO[660260U]);
    MixRotRoundB(aRandFinalA, mMaterialI[598776U], mMaterialP[267400U]);
    MixRotRoundB(aRandL1A, mMaterialD[317913U], mMaterialF[391263U]);
    MixRotRoundB(aRandFinalB, mMaterialB[876745U], mMaterialG[7083U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundA(aRandL1A, mMaterialL[530622U], mMaterialE[974847U]);
    MixRotRoundA(aRandL1B, mMaterialH[137527U], mMaterialJ[625430U]);
    MixRotRoundA(aRandFinalB, mMaterialG[780387U], mMaterialK[816087U]);
    MixRotRoundA(aRandFinalA, mMaterialM[925527U], mMaterialD[848015U]);
    MixRotRoundA(aRandL2B, mMaterialC[26828U], mMaterialF[670498U]);
    MixRotRoundA(aRandL3B, mMaterialB[339953U], mMaterialO[580301U]);
    MixRotRoundA(aRandL3A, mMaterialI[233289U], mMaterialA[77849U]);
    MixRotRoundA(aRandL2A, mMaterialP[432902U], mMaterialN[897788U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundB(aRandL1A, mMaterialH[262166U], mMaterialO[175188U]);
    MixRotRoundB(aRandFinalB, mMaterialC[364617U], mMaterialM[396300U]);
    MixRotRoundB(aRandL3A, mMaterialD[625559U], mMaterialF[201638U]);
    MixRotRoundB(aRandFinalA, mMaterialA[859851U], mMaterialE[549653U]);
    MixRotRoundB(aRandL3B, mMaterialP[600884U], mMaterialN[1047148U]);
    MixRotRoundB(aRandL1B, mMaterialJ[431963U], mMaterialG[668671U]);
    MixRotRoundB(aRandL2B, mMaterialL[782617U], mMaterialB[893740U]);
    MixRotRoundB(aRandL2A, mMaterialK[922068U], mMaterialI[52580U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundA(aRandL1B, mMaterialF[55872U], mMaterialL[740134U]);
    MixRotRoundA(aRandFinalB, mMaterialA[179038U], mMaterialG[247435U]);
    MixRotRoundA(aRandL1A, mMaterialI[623501U], mMaterialE[262543U]);
    MixRotRoundA(aRandL2A, mMaterialC[592476U], mMaterialH[486082U]);
    MixRotRoundA(aRandFinalA, mMaterialB[496364U], mMaterialD[888197U]);
    MixRotRoundA(aRandL3A, mMaterialP[301134U], mMaterialO[533025U]);
    MixRotRoundA(aRandL3B, mMaterialM[199565U], mMaterialK[665019U]);
    MixRotRoundA(aRandL2B, mMaterialJ[1036362U], mMaterialN[77097U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundB(aRandFinalA, mMaterialP[507917U], mMaterialL[107383U]);
    MixRotRoundB(aRandL3A, mMaterialK[266244U], mMaterialO[317555U]);
    MixRotRoundB(aRandL1B, mMaterialC[891864U], mMaterialA[605928U]);
    MixRotRoundB(aRandL2B, mMaterialG[471597U], mMaterialE[858870U]);
    MixRotRoundB(aRandL2A, mMaterialD[227514U], mMaterialB[65490U]);
    MixRotRoundB(aRandFinalB, mMaterialH[166804U], mMaterialM[744387U]);
    MixRotRoundB(aRandL3B, mMaterialJ[1005277U], mMaterialN[10002U]);
    MixRotRoundB(aRandL1A, mMaterialI[399980U], mMaterialF[692401U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundA(aRandFinalB, mMaterialP[701762U], mMaterialH[901996U]);
    MixRotRoundA(aRandL3B, mMaterialC[741159U], mMaterialE[639549U]);
    MixRotRoundA(aRandL1B, mMaterialL[458735U], mMaterialJ[489906U]);
    MixRotRoundA(aRandL1A, mMaterialF[962740U], mMaterialM[574664U]);
    MixRotRoundA(aRandFinalA, mMaterialA[226245U], mMaterialG[598795U]);
    MixRotRoundA(aRandL2A, mMaterialK[373420U], mMaterialO[45194U]);
    MixRotRoundA(aRandL3A, mMaterialI[150009U], mMaterialN[947428U]);
    MixRotRoundA(aRandL2B, mMaterialD[101547U], mMaterialB[812699U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundB(aRandL3A, mMaterialF[436142U], mMaterialL[838773U]);
    MixRotRoundB(aRandL2A, mMaterialA[761760U], mMaterialI[1033951U]);
    MixRotRoundB(aRandL1B, mMaterialK[51923U], mMaterialD[66517U]);
    MixRotRoundB(aRandFinalB, mMaterialP[119618U], mMaterialH[420500U]);
    MixRotRoundB(aRandL2B, mMaterialE[708245U], mMaterialG[637744U]);
    MixRotRoundB(aRandL1A, mMaterialJ[863440U], mMaterialC[157432U]);
    MixRotRoundB(aRandL3B, mMaterialB[571102U], mMaterialN[167909U]);
    MixRotRoundB(aRandFinalA, mMaterialM[4204U], mMaterialO[726391U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundA(aRandL2A, mMaterialA[116592U], mMaterialD[439252U]);
    MixRotRoundA(aRandFinalA, mMaterialN[296898U], mMaterialJ[606629U]);
    MixRotRoundA(aRandL3A, mMaterialO[810179U], mMaterialG[209142U]);
    MixRotRoundA(aRandL2B, mMaterialL[679260U], mMaterialF[1014367U]);
    MixRotRoundA(aRandL1A, mMaterialE[763981U], mMaterialC[581111U]);
    MixRotRoundA(aRandL1B, mMaterialI[4002U], mMaterialP[975460U]);
    MixRotRoundA(aRandFinalB, mMaterialB[1016701U], mMaterialM[355986U]);
    MixRotRoundA(aRandL3B, mMaterialK[421021U], mMaterialH[741113U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundB(aRandL1B, mMaterialP[196980U], mMaterialC[398027U]);
    MixRotRoundB(aRandL2A, mMaterialJ[662985U], mMaterialG[875389U]);
    MixRotRoundB(aRandL3B, mMaterialK[296088U], mMaterialE[505158U]);
    MixRotRoundB(aRandL3A, mMaterialN[261123U], mMaterialH[375945U]);
    MixRotRoundB(aRandFinalB, mMaterialA[641734U], mMaterialD[769585U]);
    MixRotRoundB(aRandL1A, mMaterialF[105426U], mMaterialL[97998U]);
    MixRotRoundB(aRandFinalA, mMaterialO[889941U], mMaterialI[807068U]);
    MixRotRoundB(aRandL2B, mMaterialB[737451U], mMaterialM[158327U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundA(aRandFinalB, mMaterialA[319888U], mMaterialM[713848U]);
    MixRotRoundA(aRandFinalA, mMaterialO[876536U], mMaterialE[186055U]);
    MixRotRoundA(aRandL2A, mMaterialH[540381U], mMaterialD[47151U]);
    MixRotRoundA(aRandL1A, mMaterialN[437219U], mMaterialC[501397U]);
    MixRotRoundA(aRandL3B, mMaterialF[400792U], mMaterialJ[28600U]);
    MixRotRoundA(aRandL2B, mMaterialP[374062U], mMaterialL[815956U]);
    MixRotRoundA(aRandL3A, mMaterialK[464254U], mMaterialB[634428U]);
    MixRotRoundA(aRandL1B, mMaterialG[936635U], mMaterialI[200677U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundB(aRandL2B, mMaterialL[22813U], mMaterialI[951946U]);
    MixRotRoundB(aRandL2A, mMaterialD[140100U], mMaterialK[504626U]);
    MixRotRoundB(aRandL1A, mMaterialB[101627U], mMaterialP[739481U]);
    MixRotRoundB(aRandL3A, mMaterialF[579897U], mMaterialH[646289U]);
    MixRotRoundB(aRandL3B, mMaterialJ[269886U], mMaterialA[402815U]);
    MixRotRoundB(aRandFinalA, mMaterialG[384633U], mMaterialN[463247U]);
    MixRotRoundB(aRandL1B, mMaterialM[84629U], mMaterialE[57739U]);
    MixRotRoundB(aRandFinalB, mMaterialO[221550U], mMaterialC[778680U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundA(aRandL3A, mMaterialE[1033309U], mMaterialJ[394026U]);
    MixRotRoundA(aRandFinalB, mMaterialG[146966U], mMaterialP[328457U]);
    MixRotRoundA(aRandL3B, mMaterialF[269921U], mMaterialL[306040U]);
    MixRotRoundA(aRandL2B, mMaterialI[479872U], mMaterialH[72589U]);
    MixRotRoundA(aRandL2A, mMaterialM[555482U], mMaterialB[680997U]);
    MixRotRoundA(aRandL1B, mMaterialD[930491U], mMaterialO[429016U]);
    MixRotRoundA(aRandFinalA, mMaterialC[821071U], mMaterialK[965720U]);
    MixRotRoundA(aRandL1A, mMaterialA[16867U], mMaterialN[205734U]);

    //
    // $$$$$$$$$$$$$$$$
    //

    MixRotRoundB(aRandL3B, mMaterialD[504174U], mMaterialO[282854U]);
    MixRotRoundB(aRandL2B, mMaterialJ[68553U], mMaterialH[949572U]);
    MixRotRoundB(aRandL1A, mMaterialF[630456U], mMaterialA[547174U]);
    MixRotRoundB(aRandFinalA, mMaterialG[834683U], mMaterialL[699763U]);
    MixRotRoundB(aRandFinalB, mMaterialK[242121U], mMaterialC[317705U]);
    MixRotRoundB(aRandL3A, mMaterialP[865157U], mMaterialN[580924U]);
    MixRotRoundB(aRandL1B, mMaterialM[44338U], mMaterialB[387378U]);
    MixRotRoundB(aRandL2A, mMaterialI[889934U], mMaterialE[482256U]);

    aRandFinalB = TwistMix64::DiffuseA(aRandFinalB);
    aRandL1B = TwistMix64::DiffuseA(aRandL1B);
    aRandFinalA = TwistMix64::DiffuseA(aRandFinalA);
    aRandL1A = TwistMix64::DiffuseA(aRandL1A);
    aRandL3A = TwistMix64::DiffuseA(aRandL3A);
    aRandL3B = TwistMix64::DiffuseA(aRandL3B);
    aRandL2B = TwistMix64::DiffuseA(aRandL2B);
    aRandL2A = TwistMix64::DiffuseA(aRandL2A);
    
    constexpr std::uint64_t aRotationRange = 131072ULL;
    constexpr std::uint64_t aRotationMask = aRotationRange - 1ULL;
    
    mRotationAmountsL3[1]       = ((aRandL3B >> 9U)     & aRotationMask) + 786432ULL;
    mRotationAmountsL1[0]       = ((aRandL1A >> 21U)    & aRotationMask);
    mRotationAmountsFinal[0]    = ((aRandFinalA >> 11U) & aRotationMask) + 655360ULL;
    mRotationAmountsFinal[1]    = ((aRandFinalB >> 13U) & aRotationMask) + 917504ULL;
    mRotationAmountsL3[0]       = ((aRandL3A >> 7U)     & aRotationMask) + 524288ULL;
    mRotationAmountsL2[1]       = ((aRandL2B >> 25U)    & aRotationMask) + 393216ULL;
    mRotationAmountsL2[0]       = ((aRandL2A >> 17U)    & aRotationMask) + 262144ULL;
    mRotationAmountsL1[1]       = ((aRandL1B >> 27U)    & aRotationMask) + 131072ULL;
    
    std::size_t aLaneIndex = 0u;
    std::size_t aLaneOffset = 0u;
    
    auto NextMaterial = [&](std::size_t pByteCount) -> std::uint8_t * {
        if ((aLaneOffset + pByteCount) > SOCCER_BLOCK_SIZE) {
            ++aLaneIndex;
            aLaneOffset = 0u;
        }
        
        /*
         if (aLaneIndex == 16u) {
         aLaneIndex = 0u;
         }
         */
        
        std::uint8_t *aResult = mMaterials[aLaneIndex] + aLaneOffset;
        aLaneOffset += pByteCount;
        return aResult;
    };
    
    auto AddCipherA = [&](EncryptionLayer &pLayer,
                          std::uint8_t pIdentifier,
                          std::size_t pLayerByteLength) {
        std::uint8_t *aPassword = NextMaterial(pLayerByteLength);
        switch (pIdentifier) {
            case 0:
                pLayer.AddCipher(std::make_unique<PasswordAddCipher>(aPassword));
                break;
            case 1:
                pLayer.AddCipher(std::make_unique<PasswordXORCipher>(aPassword));
                break;
            default:
                pLayer.AddCipher(std::make_unique<PasswordSubtractCipher>(aPassword));
                break;
        }
    };
    
    auto AddCipherB = [&](EncryptionLayer &pLayer,
                          std::uint8_t pIdentifier,
                          std::size_t pLayerByteLength) {
        
        auto TakeMaterial = [&](const char *pCipherName,
                                const char *pMaterialName) -> std::uint8_t * {
            std::uint8_t *aResult = NextMaterial(pLayerByteLength);
            return aResult;
        };
        
        switch (pIdentifier) {
            case 0: {
                std::uint8_t *aPassword = TakeMaterial("PasswordJumpAddCipher", "pPassword");
                std::uint8_t *aJumps = TakeMaterial("PasswordJumpAddCipher", "pJumps");
                pLayer.AddCipher(std::make_unique<PasswordJumpAddCipher>(aPassword, aJumps));
                break;
            }
                
            case 1: {
                std::uint8_t *aPassword = TakeMaterial("PasswordJumpXORCipher", "pPassword");
                std::uint8_t *aJumps = TakeMaterial("PasswordJumpXORCipher", "pJumps");
                pLayer.AddCipher(std::make_unique<PasswordJumpXORCipher>(aPassword, aJumps));
                break;
            }
                
            case 2: {
                std::uint8_t *aMask = TakeMaterial("PepperNoiseXORCipher", "pMask");
                std::uint8_t *aNoise = TakeMaterial("PepperNoiseXORCipher", "pNoise");
                pLayer.AddCipher(std::make_unique<PepperNoiseXORCipher>(aMask, aNoise));
                break;
            }
                
            case 3: {
                std::uint8_t *aMask = TakeMaterial("PepperJumpNoiseXORCipher", "pMask");
                std::uint8_t *aNoise = TakeMaterial("PepperJumpNoiseXORCipher", "pNoise");
                std::uint8_t *aJumps = TakeMaterial("PepperJumpNoiseXORCipher", "pJumps");
                pLayer.AddCipher(std::make_unique<PepperJumpNoiseXORCipher>(aMask, aNoise, aJumps));
                break;
            }
                
            case 4: {
                std::uint8_t *aMask = TakeMaterial("PepperDualJumpNoiseXORCipher", "pMask");
                std::uint8_t *aNoise = TakeMaterial("PepperDualJumpNoiseXORCipher", "pNoise");
                std::uint8_t *aMaskJumps = TakeMaterial("PepperDualJumpNoiseXORCipher", "pMaskJumps");
                std::uint8_t *aNoiseJumps = TakeMaterial("PepperDualJumpNoiseXORCipher", "pNoiseJumps");
                pLayer.AddCipher(std::make_unique<PepperDualJumpNoiseXORCipher>(aMask, aNoise, aMaskJumps, aNoiseJumps));
                break;
            }
                
            case 5: {
                std::uint8_t *aMask = TakeMaterial("CascadeJumpXORCipher", "pMask");
                std::uint8_t *aJumps = TakeMaterial("CascadeJumpXORCipher", "pJumps");
                pLayer.AddCipher(std::make_unique<CascadeJumpXORCipher>(aMask, aJumps));
                break;
            }
                
            case 6: {
                std::uint8_t *aMask = TakeMaterial("CascadeXORCipher", "pMask");
                pLayer.AddCipher(std::make_unique<CascadeXORCipher>(aMask));
                break;
            }
                
            case 7: {
                std::uint8_t *aPassword = TakeMaterial("PasswordAddCipher", "pPassword");
                pLayer.AddCipher(std::make_unique<PasswordAddCipher>(aPassword));
                break;
            }
            case 8: {
                std::uint8_t *aPassword = TakeMaterial("PasswordXORCipher", "pPassword");
                pLayer.AddCipher(std::make_unique<PasswordXORCipher>(aPassword));
                break;
            }
            default: {
                std::uint8_t *aPassword = TakeMaterial("PasswordSubtractCipher", "pPassword");
                pLayer.AddCipher(std::make_unique<PasswordSubtractCipher>(aPassword));
                break;
            }
        }
    };
    
    const std::size_t aLayerSizeL1 = SOCCER_BLOCK_SIZE >> 2u;
    const std::size_t aLayerSizeL2 = SOCCER_BLOCK_SIZE >> 1u;
    const std::size_t aLayerSizeL3 = SOCCER_BLOCK_SIZE;
    
    mCrypt.Layer1().ClearCiphers();
    AddCipherA(mCrypt.Layer1(), mCiphersIdentifiersA[0], aLayerSizeL1);
    mCrypt.Layer1().AddCipher(std::make_unique<RotateMaskCipher>(mMasks[0], mRotationAmountsL1[0]));
    AddCipherB(mCrypt.Layer1(), mCiphersIdentifiersB[0], aLayerSizeL1);
    mCrypt.Layer1().AddCipher(std::make_unique<RotateMaskCipher>(mMasks[1], mRotationAmountsL1[1]));
    
    mCrypt.Layer2().ClearCiphers();
    AddCipherA(mCrypt.Layer2(), mCiphersIdentifiersA[1], aLayerSizeL2);
    mCrypt.Layer2().AddCipher(std::make_unique<RotateMaskCipher>(mMasks[2], mRotationAmountsL2[0]));
    AddCipherB(mCrypt.Layer2(), mCiphersIdentifiersB[1], aLayerSizeL2);
    mCrypt.Layer2().AddCipher(std::make_unique<RotateMaskCipher>(mMasks[3], mRotationAmountsL2[1]));
    
    mCrypt.Layer3().ClearCiphers();
    AddCipherA(mCrypt.Layer3(), mCiphersIdentifiersA[2], aLayerSizeL3);
    mCrypt.Layer3().AddCipher(std::make_unique<RotateMaskCipher>(mMasks[4], mRotationAmountsL3[0]));
    AddCipherB(mCrypt.Layer3(), mCiphersIdentifiersB[2], aLayerSizeL3);
    mCrypt.Layer3().AddCipher(std::make_unique<RotateMaskCipher>(mMasks[5], mRotationAmountsL3[1]));
    
    mFinalL3.ClearCiphers();
    AddCipherA(mFinalL3, mCiphersIdentifiersA[3], aLayerSizeL3);
    mFinalL3.AddCipher(std::make_unique<RotateMaskCipher>(mMasks[6], mRotationAmountsFinal[0]));
    AddCipherB(mFinalL3, mCiphersIdentifiersB[3], aLayerSizeL3);
    mFinalL3.AddCipher(std::make_unique<RotateMaskCipher>(mMasks[7], mRotationAmountsFinal[1]));
}

bool Soccer::EncryptBlock(std::uint8_t *pSource,
                          std::uint8_t *pDestination) {
    if ((pSource == nullptr) || (pDestination == nullptr)) {
        return false;
    }
    
    CipherErrorCode aErrorCode = CipherErrorCode::kNone;
    
    if (!mCrypt.SealData(pSource,
                         pDestination,
                         mCryptTemp,
                         mScratch,
                         SOCCER_BLOCK_SIZE,
                         &aErrorCode)) {
        return false;
    }
    
    return mFinalL3.SealData(mScratch,
                             mCryptTemp,
                             pDestination,
                             SOCCER_BLOCK_SIZE,
                             &aErrorCode);
}

bool Soccer::DecryptBlock(std::uint8_t *pSource,
                          std::uint8_t *pDestination) {
    if ((pSource == nullptr) || (pDestination == nullptr)) {
        return false;
    }
    
    CipherErrorCode aErrorCode = CipherErrorCode::kNone;
    
    if (!mFinalL3.UnsealData(pSource,
                             mCryptTemp,
                             pDestination,
                             SOCCER_BLOCK_SIZE,
                             &aErrorCode)) {
        return false;
    }
    
    return mCrypt.UnsealData(pDestination,
                             mCryptTemp,
                             mScratch,
                             pDestination,
                             SOCCER_BLOCK_SIZE,
                             &aErrorCode);
}
