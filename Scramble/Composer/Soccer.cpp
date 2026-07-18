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
    aRotSampleIndex += static_cast<std::size_t>(mMaterialA[   73]) + static_cast<std::size_t>(mMaterialE[  911]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialI[ 1777]) + static_cast<std::size_t>(mMaterialM[ 2603]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[  149]) + static_cast<std::size_t>(mMaterialF[ 1021]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialJ[ 1889]) + static_cast<std::size_t>(mMaterialN[ 2711]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialC[  263]) + static_cast<std::size_t>(mMaterialG[ 1151]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialK[ 1999]) + static_cast<std::size_t>(mMaterialO[ 2833]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[  379]) + static_cast<std::size_t>(mMaterialH[ 1277]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[ 2131]) + static_cast<std::size_t>(mMaterialP[ 2953]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialA[ 3079]) + static_cast<std::size_t>(mMaterialE[ 3203]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialI[ 3319]) + static_cast<std::size_t>(mMaterialM[ 3449]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[ 3581]) + static_cast<std::size_t>(mMaterialF[ 3701]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialJ[ 3821]) + static_cast<std::size_t>(mMaterialN[ 3943]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialC[ 4057]) + static_cast<std::size_t>(mMaterialG[ 4211]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialK[ 4337]) + static_cast<std::size_t>(mMaterialO[ 4463]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[ 4591]) + static_cast<std::size_t>(mMaterialH[ 4721]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[ 4861]) + static_cast<std::size_t>(mMaterialP[ 4993]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialA[ 5107]) + static_cast<std::size_t>(mMaterialE[ 5231]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialI[ 5351]) + static_cast<std::size_t>(mMaterialM[ 5483]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[ 5623]) + static_cast<std::size_t>(mMaterialF[ 5749]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialJ[ 5879]) + static_cast<std::size_t>(mMaterialN[ 6007]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialC[ 6131]) + static_cast<std::size_t>(mMaterialG[ 6263]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialK[ 6397]) + static_cast<std::size_t>(mMaterialO[ 6521]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[ 6653]) + static_cast<std::size_t>(mMaterialH[ 6781]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[ 6917]) + static_cast<std::size_t>(mMaterialP[ 7043]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialA[ 7177]) + static_cast<std::size_t>(mMaterialE[ 7309]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialI[ 7433]) + static_cast<std::size_t>(mMaterialM[ 7561]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[ 7691]) + static_cast<std::size_t>(mMaterialF[ 7823]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialJ[ 7951]) + static_cast<std::size_t>(mMaterialN[ 8081]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialC[ 8219]) + static_cast<std::size_t>(mMaterialG[ 8353]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialK[ 8477]) + static_cast<std::size_t>(mMaterialO[ 8609]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[ 8731]) + static_cast<std::size_t>(mMaterialH[ 8863]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[ 8999]) + static_cast<std::size_t>(mMaterialP[ 9127]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialA[ 9257]) + static_cast<std::size_t>(mMaterialE[ 9391]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialI[ 9521]) + static_cast<std::size_t>(mMaterialM[ 9649]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[ 9781]) + static_cast<std::size_t>(mMaterialF[ 9907]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialJ[10039]) + static_cast<std::size_t>(mMaterialN[10169]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialC[10297]) + static_cast<std::size_t>(mMaterialG[10429]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialK[10559]) + static_cast<std::size_t>(mMaterialO[10687]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[10817]) + static_cast<std::size_t>(mMaterialH[10949]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[11083]) + static_cast<std::size_t>(mMaterialP[11213]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialA[11351]) + static_cast<std::size_t>(mMaterialE[11483]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialI[11617]) + static_cast<std::size_t>(mMaterialM[11743]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[11873]) + static_cast<std::size_t>(mMaterialF[12007]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialJ[12143]) + static_cast<std::size_t>(mMaterialN[12269]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialC[12401]) + static_cast<std::size_t>(mMaterialG[12533]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialK[12659]) + static_cast<std::size_t>(mMaterialO[12791]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[12919]) + static_cast<std::size_t>(mMaterialH[13049]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[13183]) + static_cast<std::size_t>(mMaterialP[13309]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialA[13441]) + static_cast<std::size_t>(mMaterialE[13577]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialI[13709]) + static_cast<std::size_t>(mMaterialM[13837]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[13967]) + static_cast<std::size_t>(mMaterialF[14099]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialJ[14221]) + static_cast<std::size_t>(mMaterialN[14359]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialC[14489]) + static_cast<std::size_t>(mMaterialG[14621]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialK[14747]) + static_cast<std::size_t>(mMaterialO[14879]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[15013]) + static_cast<std::size_t>(mMaterialH[15139]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[15269]) + static_cast<std::size_t>(mMaterialP[15401]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialA[15527]) + static_cast<std::size_t>(mMaterialE[15661]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialI[15791]) + static_cast<std::size_t>(mMaterialM[15923]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialB[16057]) + static_cast<std::size_t>(mMaterialF[16183]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialJ[16319]) + static_cast<std::size_t>(mMaterialN[16447]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialC[16573]) + static_cast<std::size_t>(mMaterialG[16703]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialK[16831]) + static_cast<std::size_t>(mMaterialO[16963]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialD[17093]) + static_cast<std::size_t>(mMaterialH[17221]);
    aRotSampleIndex += static_cast<std::size_t>(mMaterialL[17351]) + static_cast<std::size_t>(mMaterialP[17477]);

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

    MixRotRoundA(aRandFinalB, mMaterialA[1791], mMaterialI[ 400]);
    MixRotRoundA(aRandL1B,    mMaterialB[ 233], mMaterialJ[3017]);
    MixRotRoundA(aRandFinalA, mMaterialC[4099], mMaterialK[ 877]);
    MixRotRoundA(aRandL1A,    mMaterialD[  97], mMaterialL[6211]);
    MixRotRoundA(aRandL3A,    mMaterialE[1543], mMaterialM[ 711]);
    MixRotRoundA(aRandL3B,    mMaterialF[2887], mMaterialN[ 190]);
    MixRotRoundA(aRandL2B,    mMaterialG[ 503], mMaterialO[4519]);
    MixRotRoundA(aRandL2A,    mMaterialH[3761], mMaterialP[1297]);

    MixRotRoundB(aRandL3B,    mMaterialI[ 547], mMaterialP[ 281]);
    MixRotRoundB(aRandL2A,    mMaterialJ[3329], mMaterialA[1907]);
    MixRotRoundB(aRandFinalA, mMaterialK[ 743], mMaterialB[4621]);
    MixRotRoundB(aRandL1B,    mMaterialL[5701], mMaterialC[ 359]);
    MixRotRoundB(aRandL3A,    mMaterialM[2189], mMaterialD[1003]);
    MixRotRoundB(aRandFinalB, mMaterialN[ 127], mMaterialE[5413]);
    MixRotRoundB(aRandL2B,    mMaterialO[3893], mMaterialF[ 617]);
    MixRotRoundB(aRandL1A,    mMaterialP[2011], mMaterialG[3209]);

    MixRotRoundA(aRandL1A,    mMaterialH[ 829], mMaterialA[4871]);
    MixRotRoundA(aRandFinalB, mMaterialA[2579], mMaterialI[ 109]);
    MixRotRoundA(aRandL2B,    mMaterialB[ 601], mMaterialJ[5237]);
    MixRotRoundA(aRandL3A,    mMaterialC[3467], mMaterialK[ 941]);
    MixRotRoundA(aRandFinalA, mMaterialD[ 151], mMaterialL[2899]);
    MixRotRoundA(aRandL1B,    mMaterialE[4723], mMaterialM[ 733]);
    MixRotRoundA(aRandL2A,    mMaterialF[1181], mMaterialN[3659]);
    MixRotRoundA(aRandL3B,    mMaterialG[4229], mMaterialO[ 317]);

    MixRotRoundB(aRandL2A,    mMaterialP[ 563], mMaterialH[4951]);
    MixRotRoundB(aRandL3A,    mMaterialO[2741], mMaterialG[ 181]);
    MixRotRoundB(aRandL1B,    mMaterialN[ 397], mMaterialF[5807]);
    MixRotRoundB(aRandFinalB, mMaterialM[3253], mMaterialE[1051]);
    MixRotRoundB(aRandL2B,    mMaterialL[ 677], mMaterialD[2447]);
    MixRotRoundB(aRandL1A,    mMaterialK[5009], mMaterialC[ 229]);
    MixRotRoundB(aRandL3B,    mMaterialJ[1433], mMaterialB[4363]);
    MixRotRoundB(aRandFinalA, mMaterialI[3671], mMaterialA[ 887]);

    MixRotRoundA(aRandFinalA, mMaterialA[ 619], mMaterialH[5333]);
    MixRotRoundA(aRandL2B,    mMaterialC[2081], mMaterialJ[ 491]);
    MixRotRoundA(aRandL3B,    mMaterialE[4513], mMaterialL[1379]);
    MixRotRoundA(aRandL1A,    mMaterialG[ 337], mMaterialN[6029]);
    MixRotRoundA(aRandFinalB, mMaterialI[2749], mMaterialP[ 157]);
    MixRotRoundA(aRandL2A,    mMaterialK[ 811], mMaterialB[4201]);
    MixRotRoundA(aRandL1B,    mMaterialM[5723], mMaterialD[1019]);
    MixRotRoundA(aRandL3A,    mMaterialO[1877], mMaterialF[3499]);

    MixRotRoundB(aRandL3A,    mMaterialB[ 293], mMaterialI[4831]);
    MixRotRoundB(aRandL1B,    mMaterialD[4421], mMaterialK[ 557]);
    MixRotRoundB(aRandL2A,    mMaterialF[1223], mMaterialM[6151]);
    MixRotRoundB(aRandFinalA, mMaterialH[3613], mMaterialO[ 211]);
    MixRotRoundB(aRandL3B,    mMaterialJ[ 769], mMaterialA[5279]);
    MixRotRoundB(aRandL1A,    mMaterialL[5903], mMaterialC[1327]);
    MixRotRoundB(aRandFinalB, mMaterialN[ 463], mMaterialE[4001]);
    MixRotRoundB(aRandL2B,    mMaterialP[2519], mMaterialG[ 953]);

    MixRotRoundA(aRandL2B,    mMaterialC[ 541], mMaterialP[5689]);
    MixRotRoundA(aRandFinalA, mMaterialF[3313], mMaterialB[ 173]);
    MixRotRoundA(aRandL1A,    mMaterialI[4921], mMaterialE[1201]);
    MixRotRoundA(aRandL3B,    mMaterialL[ 887], mMaterialH[6361]);
    MixRotRoundA(aRandL2A,    mMaterialO[3011], mMaterialK[ 389]);
    MixRotRoundA(aRandFinalB, mMaterialB[5801], mMaterialN[1447]);
    MixRotRoundA(aRandL3A,    mMaterialE[ 223], mMaterialA[4703]);
    MixRotRoundA(aRandL1B,    mMaterialH[4117], mMaterialD[ 659]);

    MixRotRoundB(aRandFinalB, mMaterialD[ 971], mMaterialM[5209]);
    MixRotRoundB(aRandL3B,    mMaterialH[2879], mMaterialA[ 431]);
    MixRotRoundB(aRandL1A,    mMaterialL[6199], mMaterialE[1187]);
    MixRotRoundB(aRandL2A,    mMaterialP[ 353], mMaterialI[4441]);
    MixRotRoundB(aRandL1B,    mMaterialC[2693], mMaterialN[ 739]);
    MixRotRoundB(aRandL3A,    mMaterialG[5077], mMaterialB[ 199]);
    MixRotRoundB(aRandFinalA, mMaterialK[1559], mMaterialF[5881]);
    MixRotRoundB(aRandL2B,    mMaterialO[6013], mMaterialJ[ 823]);

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
