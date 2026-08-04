//
//  Soccer2.cpp
//  Scramble
//
//  Created by nick on 8/1/26.
//

#include "Soccer2.hpp"

#define BLOCK_COUNT (SOCCER_BLOCK_SIZE / S_BLOCK)

std::uint8_t                                cMaterialA[SOCCER_BLOCK_SIZE];
std::uint8_t                                cMaterialB[SOCCER_BLOCK_SIZE];
std::uint8_t                                cMaterialC[SOCCER_BLOCK_SIZE];
std::uint8_t                                cMaterialD[SOCCER_BLOCK_SIZE];

std::uint8_t                                cMaterialE[SOCCER_BLOCK_SIZE];
std::uint8_t                                cMaterialF[SOCCER_BLOCK_SIZE];
std::uint8_t                                cMaterialG[SOCCER_BLOCK_SIZE];
std::uint8_t                                cMaterialH[SOCCER_BLOCK_SIZE];

std::uint8_t                                cMaterialI[SOCCER_BLOCK_SIZE];
std::uint8_t                                cMaterialJ[SOCCER_BLOCK_SIZE];
std::uint8_t                                cMaterialK[SOCCER_BLOCK_SIZE];
std::uint8_t                                cMaterialL[SOCCER_BLOCK_SIZE];

std::uint8_t                                cMaterialM[SOCCER_BLOCK_SIZE];
std::uint8_t                                cMaterialN[SOCCER_BLOCK_SIZE];
std::uint8_t                                cMaterialO[SOCCER_BLOCK_SIZE];
std::uint8_t                                cMaterialP[SOCCER_BLOCK_SIZE];

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

TwistWorkSpace                              cWorkSpaceA;
TwistWorkSpace                              cWorkSpaceB;
TwistWorkSpace                              cWorkSpaceC;
TwistWorkSpace                              cWorkSpaceD;
TwistWorkSpace                              cWorkSpaceE;
TwistWorkSpace                              cWorkSpaceF;
TwistWorkSpace                              cWorkSpaceG;
TwistWorkSpace                              cWorkSpaceH;
TwistWorkSpace                              cWorkSpaceI;
TwistWorkSpace                              cWorkSpaceJ;
TwistWorkSpace                              cWorkSpaceK;
TwistWorkSpace                              cWorkSpaceL;
TwistWorkSpace                              cWorkSpaceM;
TwistWorkSpace                              cWorkSpaceN;
TwistWorkSpace                              cWorkSpaceO;
TwistWorkSpace                              cWorkSpaceP;

std::uint8_t                                cRandom[S_BLOCK];
std::uint8_t                                cScratch[SOCCER_BLOCK_SIZE];

std::uint8_t                                cCrushA[S_BLOCK];
std::uint8_t                                cCrushB[S_BLOCK];
std::uint8_t                                cCrushC[S_BLOCK];
std::uint8_t                                cCrushD[S_BLOCK];

std::uint8_t                                cCryptTemp[SOCCER_BLOCK_SIZE];

std::uint8_t                                Soccer2::mMasks[32];

std::uint8_t                                *Soccer2::mMaterials[16];
TwistExpander                               *Soccer2::mExpanders[32];
TwistWorkSpace                              *Soccer2::mWorkSpaces[16];
std::uint8_t                                *Soccer2::mSources[16];
std::uint8_t                                *Soccer2::mCross[4][16];

TwistExpander                               *Soccer2::mClaimedExpanders[16];
std::size_t                                 Soccer2::mClaimedExpanderCount;

std::uint8_t                                *Soccer2::mClaimedMaterials[16];
std::size_t                                 Soccer2::mClaimedMaterialCount;

TwistWorkSpace                              *Soccer2::mClaimedWorkSpaces[16];
std::size_t                                 Soccer2::mClaimedWorkSpaceCount;

LayeredCrypt                                Soccer2::mCrypt;
EncryptionLayer                             Soccer2::mFinalL3;

std::uint8_t                                *Soccer2::mShuffleMaterials[16];
TwistExpander                               *Soccer2::mShuffleExpanders[32];
TwistWorkSpace                              *Soccer2::mShuffleWorkSpaces[16];

CipherType                                  Soccer2::mCiphersMoveA[32];


bool Soccer2::AttemptSeed_Encrypt(EncryptionStrength pStrength,
                                  std::uint8_t *pPassword,
                                  std::size_t pPasswordByteLength,
                                  std::uint64_t pNonce,
                                  std::uint32_t *pAckWord) {
    
    std::uint32_t aAckWord = 0;
    
    if (pStrength == EncryptionStrength::kTest) {
        if (!SeedPrelude_Test(pPassword, pPasswordByteLength, pNonce)) {
            return false;
        }
        aAckWord |= static_cast<std::uint32_t>(cMaterialA[S_BLOCK * 1]) << 24U;
        aAckWord |= static_cast<std::uint32_t>(cMaterialA[S_BLOCK * 2]) << 16U;
        aAckWord |= static_cast<std::uint32_t>(cMaterialA[S_BLOCK * 3]) << 8U;
        aAckWord |= static_cast<std::uint32_t>(cMaterialA[S_BLOCK * 4]) << 0U;
        *pAckWord = aAckWord;
        return true;
    }
    
    
    
    
    
    return true;
}

bool Soccer2::AttemptSeed_Decrypt(EncryptionStrength pStrength,
                                  std::uint8_t *pPassword,
                                  std::size_t pPasswordByteLength,
                                  std::uint64_t pNonce,
                                  std::uint32_t pAckWord) {
    return true;
}

void Soccer2::EncryptBlock(std::uint8_t *pSource,
                           std::uint8_t *pDestination) {
    
}

void Soccer2::DecryptBlock(std::uint8_t *pSource,
                           std::uint8_t *pDestination) {
    
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
    mMaterials[ 0] = cMaterialA; mMaterials[ 1] = cMaterialB; mMaterials[ 2] = cMaterialC; mMaterials[ 3] = cMaterialD;
    mMaterials[ 4] = cMaterialE; mMaterials[ 5] = cMaterialF; mMaterials[ 6] = cMaterialG; mMaterials[ 7] = cMaterialH;
    mMaterials[ 8] = cMaterialI; mMaterials[ 9] = cMaterialJ; mMaterials[10] = cMaterialK; mMaterials[11] = cMaterialL;
    mMaterials[12] = cMaterialM; mMaterials[13] = cMaterialN; mMaterials[14] = cMaterialO; mMaterials[15] = cMaterialP;
}

void Soccer2::InitializeWorkSpaces() {
    mWorkSpaces[ 0] = &cWorkSpaceA; mWorkSpaces[ 1] = &cWorkSpaceB; mWorkSpaces[ 2] = &cWorkSpaceC; mWorkSpaces[ 3] = &cWorkSpaceD;
    mWorkSpaces[ 4] = &cWorkSpaceE; mWorkSpaces[ 5] = &cWorkSpaceF; mWorkSpaces[ 6] = &cWorkSpaceG; mWorkSpaces[ 7] = &cWorkSpaceH;
    mWorkSpaces[ 8] = &cWorkSpaceI; mWorkSpaces[ 9] = &cWorkSpaceJ; mWorkSpaces[10] = &cWorkSpaceK; mWorkSpaces[11] = &cWorkSpaceL;
    mWorkSpaces[12] = &cWorkSpaceM; mWorkSpaces[13] = &cWorkSpaceN; mWorkSpaces[14] = &cWorkSpaceO; mWorkSpaces[15] = &cWorkSpaceP;
}

void Soccer2::UnrollNonceAndPasswordToScratch(std::uint8_t *pPassword,
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
            cScratch[aScratchIndex++] = pPassword[aPasswordIndex];
        }
        std::size_t aNonceIndex = 0;
        while ((aNonceIndex < 8) && (aScratchIndex < S_BLOCK)) {
            cScratch[aScratchIndex++] = aNonceBytes[aNonceIndex];
        }
    }
}

bool Soccer2::SeedPrelude_Test(std::uint8_t *pPassword,
                               std::size_t pPasswordByteLength,
                               std::uint64_t pNonce) {
    
    UnrollNonceAndPasswordToScratch(pPassword, pPasswordByteLength, pNonce);
    
    std::uint64_t aValue = 0x00;
    for (std::size_t aIndex=0; aIndex<SOCCER_BLOCK_SIZE; aIndex++) {
        aValue = RotL64(aValue, 3);
        aValue ^= static_cast<std::uint64_t>(cScratch[aIndex]);
        aValue = (aValue * 3333333333333333333ULL);
        cMaterialA[aIndex] = static_cast<std::uint8_t>(aValue);
    }
    
    return true;
}

bool Soccer2::SeedPrelude_Regular(std::uint8_t *pPassword,
                                  std::size_t pPasswordByteLength,
                                  std::uint64_t pNonce) {
    
    InitializeExpanders();
    InitializeWorkSpaces();
    InitializeMaterials();
    InitializeMasks();
    
    memset(mClaimedExpanders, 0, sizeof(mClaimedExpanders));
    mClaimedExpanderCount = 0;
    
    memset(mClaimedMaterials, 0, sizeof(mClaimedMaterials));
    mClaimedMaterialCount = 0;
    
    memset(mClaimedWorkSpaces, 0, sizeof(mClaimedWorkSpaces));
    mClaimedWorkSpaceCount = 0;
    
    UnrollNonceAndPasswordToScratch(pPassword, pPasswordByteLength, pNonce);
    
    cStarter.Seed(&cWorkSpaceA, &cFarmSalt, pNonce, pPassword, pPasswordByteLength, cRandom);
    
    TwistShuffle::ShuffleList32(mMasks,         cRandom,     0,  4096, 4);
    TwistShuffle::ShuffleList32(mExpanders,     cRandom,  4096,  8192, 4);
    TwistShuffle::ShuffleList16(mWorkSpaces,    cRandom,  8192, 12288, 4);
    TwistShuffle::ShuffleList16(mMaterials,     cRandom, 12288, 16384, 4);
    
    TwistShuffle::ShuffleList32(mMasks,         cRandom, 16384, 20480, 4);
    TwistShuffle::ShuffleList32(mExpanders,     cRandom, 20480, 24576, 4);
    TwistShuffle::ShuffleList16(mWorkSpaces,    cRandom, 24576, 28672, 4);
    TwistShuffle::ShuffleList16(mMaterials,     cRandom, 28672, 32768, 4);
    
    return true;
}

void Soccer2::SeedEpilogue() {
    
    /*
    for (std::size_t aIndex=0; aIndex<16; aIndex++) {
        mMaterials[aIndex] = mClaimedMaterials[aIndex];
    }
    
    for (std::size_t aIndex=0; aIndex<16; aIndex++) {
        mWorkSpaces[aIndex] = mClaimedWorkSpaces[aIndex];
    }
    */
    
    InitializeExpanders();
    
    for (std::size_t aIndex=0; aIndex<16; aIndex++) {
        mSources[aIndex] = mMaterials[aIndex];
    }
    
    FoldAllMaterialsIntoRandomForBlock(0);
    ShuffleSEWMMCC();
    
    std::size_t aBlockIndex = 1;
    
    /*
    while (aBlockIndex < BLOCK_COUNT) {
        const std::size_t aSourceIndex = (aBlockIndex - 1U) * S_BLOCK;
        const std::size_t aDestinationIndex = aBlockIndex * S_BLOCK;
        
        mExpanders[11]->TwistBlock(mWorkSpaces[14], &mSources[ 2][aSourceIndex], mCrossA[0], mCrossA[1], mCrossA[2], mCrossA[3], &mMaterials[ 7][aDestinationIndex]);
        mExpanders[ 4]->TwistBlock(mWorkSpaces[ 7], &mSources[11][aSourceIndex], mCrossA[0], mCrossA[1], mCrossA[2], mCrossA[3], &mMaterials[ 0][aDestinationIndex]);
        mExpanders[15]->TwistBlock(mWorkSpaces[ 2], &mSources[ 6][aSourceIndex], mCrossA[0], mCrossA[1], mCrossA[2], mCrossA[3], &mMaterials[11][aDestinationIndex]);
        mExpanders[ 2]->TwistBlock(mWorkSpaces[ 5], &mSources[ 9][aSourceIndex], mCrossA[0], mCrossA[1], mCrossA[2], mCrossA[3], &mMaterials[14][aDestinationIndex]);
        mExpanders[ 9]->TwistBlock(mWorkSpaces[12], &mSources[ 0][aSourceIndex], mCrossA[0], mCrossA[1], mCrossA[2], mCrossA[3], &mMaterials[ 5][aDestinationIndex]);
        mExpanders[ 0]->TwistBlock(mWorkSpaces[ 3], &mSources[ 7][aSourceIndex], mCrossA[0], mCrossA[1], mCrossA[2], mCrossA[3], &mMaterials[12][aDestinationIndex]);
        mExpanders[13]->TwistBlock(mWorkSpaces[ 6], &mSources[ 4][aSourceIndex], mCrossA[0], mCrossA[1], mCrossA[2], mCrossA[3], &mMaterials[ 9][aDestinationIndex]);
        mExpanders[ 6]->TwistBlock(mWorkSpaces[ 9], &mSources[13][aSourceIndex], mCrossA[0], mCrossA[1], mCrossA[2], mCrossA[3], &mMaterials[ 2][aDestinationIndex]);
        mExpanders[ 1]->TwistBlock(mWorkSpaces[ 4], &mSources[ 8][aSourceIndex], mCrossA[0], mCrossA[1], mCrossA[2], mCrossA[3], &mMaterials[13][aDestinationIndex]);
        mExpanders[14]->TwistBlock(mWorkSpaces[ 1], &mSources[ 5][aSourceIndex], mCrossA[0], mCrossA[1], mCrossA[2], mCrossA[3], &mMaterials[10][aDestinationIndex]);
        mExpanders[ 7]->TwistBlock(mWorkSpaces[10], &mSources[14][aSourceIndex], mCrossA[0], mCrossA[1], mCrossA[2], mCrossA[3], &mMaterials[ 3][aDestinationIndex]);
        mExpanders[10]->TwistBlock(mWorkSpaces[13], &mSources[ 1][aSourceIndex], mCrossA[0], mCrossA[1], mCrossA[2], mCrossA[3], &mMaterials[ 6][aDestinationIndex]);
        mExpanders[ 3]->TwistBlock(mWorkSpaces[ 0], &mSources[10][aSourceIndex], mCrossA[0], mCrossA[1], mCrossA[2], mCrossA[3], &mMaterials[15][aDestinationIndex]);
        mExpanders[12]->TwistBlock(mWorkSpaces[15], &mSources[ 3][aSourceIndex], mCrossA[0], mCrossA[1], mCrossA[2], mCrossA[3], &mMaterials[ 8][aDestinationIndex]);
        mExpanders[ 5]->TwistBlock(mWorkSpaces[ 8], &mSources[12][aSourceIndex], mCrossA[0], mCrossA[1], mCrossA[2], mCrossA[3], &mMaterials[ 1][aDestinationIndex]);
        mExpanders[ 8]->TwistBlock(mWorkSpaces[11], &mSources[15][aSourceIndex], mCrossA[0], mCrossA[1], mCrossA[2], mCrossA[3], &mMaterials[ 4][aDestinationIndex]);
        
        FoldAllMaterialsIntoRandomForBlock(aBlockIndex);
        
        const std::size_t aReverseEndIndex = aDestinationIndex + S_BLOCK;
        for (std::size_t aMaterialIndex=6U; aMaterialIndex<8U; aMaterialIndex++) {
            std::reverse(mMaterials[aMaterialIndex] + aDestinationIndex, mMaterials[aMaterialIndex] + aReverseEndIndex);
        }
        
        if (aBlockIndex == (BLOCK_COUNT - 1U)) {
            for (std::size_t aMaterialIndex=0U; aMaterialIndex<8U; aMaterialIndex++) {
                std::reverse(mMaterials[aMaterialIndex], mMaterials[aMaterialIndex] + SOCCER_BLOCK_SIZE);
            }
        }
        
        ShuffleSEWMMCC();
        
        aBlockIndex++;
    }
    */
    
    cWorkSpaceN.Zero();
    cWorkSpaceO.Zero();
    cWorkSpaceP.Zero();
    cWorkSpaceD.Zero();
    cWorkSpaceE.Zero();
    cWorkSpaceF.Zero();
    cWorkSpaceJ.Zero();
    cWorkSpaceI.Zero();
    cWorkSpaceH.Zero();
    cWorkSpaceG.Zero();
    cWorkSpaceB.Zero();
    cWorkSpaceK.Zero();
    cWorkSpaceC.Zero();
    cWorkSpaceM.Zero();
    cWorkSpaceA.Zero();
    cWorkSpaceL.Zero();
    


    /*
    mCrypt.Layer1().ClearCiphers();
    AddCipherA(mCrypt.Layer1(), mCiphersIdentifiersA[0], SOCCER_BLOCK_SIZE_L1);
    mCrypt.Layer1().AddCipher(std::make_unique<RotateMaskCipher>(mMasks[0], mRotationAmountsL1[0]));
    AddCipherB(mCrypt.Layer1(), mCiphersIdentifiersB[0], SOCCER_BLOCK_SIZE_L1);
    mCrypt.Layer1().AddCipher(std::make_unique<RotateMaskCipher>(mMasks[1], mRotationAmountsL1[1]));
    
    mCrypt.Layer2().ClearCiphers();
    AddCipherA(mCrypt.Layer2(), mCiphersIdentifiersA[1], SOCCER_BLOCK_SIZE_L2);
    mCrypt.Layer2().AddCipher(std::make_unique<RotateMaskCipher>(mMasks[2], mRotationAmountsL2[0]));
    AddCipherB(mCrypt.Layer2(), mCiphersIdentifiersB[1], SOCCER_BLOCK_SIZE_L2);
    mCrypt.Layer2().AddCipher(std::make_unique<RotateMaskCipher>(mMasks[3], mRotationAmountsL2[1]));
    
    mCrypt.Layer3().ClearCiphers();
    AddCipherA(mCrypt.Layer3(), mCiphersIdentifiersA[2], SOCCER_BLOCK_SIZE);
    mCrypt.Layer3().AddCipher(std::make_unique<RotateMaskCipher>(mMasks[4], mRotationAmountsL3[0]));
    AddCipherB(mCrypt.Layer3(), mCiphersIdentifiersB[2], SOCCER_BLOCK_SIZE);
    mCrypt.Layer3().AddCipher(std::make_unique<RotateMaskCipher>(mMasks[5], mRotationAmountsL3[1]));
    
    mFinalL3.ClearCiphers();
    AddCipherA(mFinalL3, mCiphersIdentifiersA[3], SOCCER_BLOCK_SIZE);
    mFinalL3.AddCipher(std::make_unique<RotateMaskCipher>(mMasks[6], mRotationAmountsFinal[0]));
    AddCipherB(mFinalL3, mCiphersIdentifiersB[3], SOCCER_BLOCK_SIZE);
    mFinalL3.AddCipher(std::make_unique<RotateMaskCipher>(mMasks[7], mRotationAmountsFinal[1]));
    */
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
    
    //TwistShuffle::ShuffleExpanderList32(mShuffleExpanders, pMaterial, 0, 200, 4);
    
    //TwistShuffle::ShuffleCipherTypeList32(mCiphersMoveA, pMaterial, 200, 400, 4);
    

    /*
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
    */
}

void Soccer2::ShuffleSEWMMCC() {
    
}

void Soccer2::FoldAllMaterialsIntoRandomForBlock(std::size_t pBlockIndex) {
    
}
