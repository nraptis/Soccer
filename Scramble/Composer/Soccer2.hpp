//
//  Soccer2.hpp
//  Scramble
//
//  Created by nick on 8/1/26.
//

// Note: We want to remove weave ciphers

#ifndef Soccer2_hpp
#define Soccer2_hpp

#include "TwistFarmSalt.hpp"
#include "TwistWorkSpace.hpp"
#include "TwistShuffle.hpp"
#include "TwistFunctional.hpp"
#include "SoccerTypes.hpp"


#include "EncryptionLayer.hpp"

#include "Cryptex.hpp"
#include "Jelly.hpp"

#include "TwistExpander_Aldebaran.hpp"
#include "TwistExpander_Altair.hpp"
#include "TwistExpander_Antares.hpp"
#include "TwistExpander_Arcturus.hpp"
#include "TwistExpander_Bellatrix.hpp"
#include "TwistExpander_Betelgeuse.hpp"
#include "TwistExpander_Capella.hpp"
#include "TwistExpander_Castor.hpp"
#include "TwistExpander_Mimosa.hpp"
#include "TwistExpander_Polaris.hpp"
#include "TwistExpander_Pollux.hpp"
#include "TwistExpander_Procyon.hpp"
#include "TwistExpander_Regulus.hpp"
#include "TwistExpander_Rigel.hpp"
#include "TwistExpander_Saiph.hpp"
#include "TwistExpander_Sirius.hpp"
#include "TwistExpander_Vega.hpp"

#include <cstddef>
#include <cstdint>

#define SOCCER_ROTATION_WORD_COUNT_S3 248
#define SOCCER_ROTATION_WORD_COUNT_S2 124
#define SOCCER_ROTATION_WORD_COUNT_S1 124
#define SOCCER_EXPANDER_COUNT 16

class Soccer2Internal {
public:
    
    static std::uint8_t                         mMaterialA[SOCCER_BLOCK_SIZE];
    static std::uint8_t                         mMaterialB[SOCCER_BLOCK_SIZE];
    static std::uint8_t                         mMaterialC[SOCCER_BLOCK_SIZE];
    static std::uint8_t                         mMaterialD[SOCCER_BLOCK_SIZE];
    
    static std::uint8_t                         mMaterialE[SOCCER_BLOCK_SIZE];
    static std::uint8_t                         mMaterialF[SOCCER_BLOCK_SIZE];
    static std::uint8_t                         mMaterialG[SOCCER_BLOCK_SIZE];
    static std::uint8_t                         mMaterialH[SOCCER_BLOCK_SIZE];
    
    static std::uint8_t                         mMaterialI[SOCCER_BLOCK_SIZE];
    static std::uint8_t                         mMaterialJ[SOCCER_BLOCK_SIZE];
    static std::uint8_t                         mMaterialK[SOCCER_BLOCK_SIZE];
    static std::uint8_t                         mMaterialL[SOCCER_BLOCK_SIZE];
    
    static std::uint8_t                         mMaterialM[SOCCER_BLOCK_SIZE];
    static std::uint8_t                         mMaterialN[SOCCER_BLOCK_SIZE];
    static std::uint8_t                         mMaterialO[SOCCER_BLOCK_SIZE];
    static std::uint8_t                         mMaterialP[SOCCER_BLOCK_SIZE];
    
    static TwistWorkSpace                       mWorkSpaceA;
    static TwistWorkSpace                       mWorkSpaceB;
    static TwistWorkSpace                       mWorkSpaceC;
    static TwistWorkSpace                       mWorkSpaceD;
    static TwistWorkSpace                       mWorkSpaceE;
    static TwistWorkSpace                       mWorkSpaceF;
    static TwistWorkSpace                       mWorkSpaceG;
    static TwistWorkSpace                       mWorkSpaceH;
    static TwistWorkSpace                       mWorkSpaceI;
    static TwistWorkSpace                       mWorkSpaceJ;
    static TwistWorkSpace                       mWorkSpaceK;
    static TwistWorkSpace                       mWorkSpaceL;
    static TwistWorkSpace                       mWorkSpaceM;
    static TwistWorkSpace                       mWorkSpaceN;
    static TwistWorkSpace                       mWorkSpaceO;
    static TwistWorkSpace                       mWorkSpaceP;
    
    static std::uint8_t                         mRandom[S_BLOCK];
    static std::uint8_t                         mScratch[SOCCER_BLOCK_SIZE];
    static std::uint8_t                         mCryptTemp[SOCCER_BLOCK_SIZE];
    
    static std::uint8_t                         mCollapseLaneA[SOCCER_BLOCK_SIZE];
    static std::uint8_t                         mCollapseLaneB[SOCCER_BLOCK_SIZE];
    static std::uint8_t                         mCollapseLaneC[SOCCER_BLOCK_SIZE];
    static std::uint8_t                         mCollapseLaneD[SOCCER_BLOCK_SIZE];
    
    static std::uint8_t                         mShrinkLaneA[SOCCER_BLOCK_SIZE_L1];
    static std::uint8_t                         mShrinkLaneB[SOCCER_BLOCK_SIZE_L1];
    static std::uint8_t                         mShrinkLaneC[SOCCER_BLOCK_SIZE_L1];
    static std::uint8_t                         mShrinkLaneD[SOCCER_BLOCK_SIZE_L1];
    
    static std::uint8_t                         mCompressLaneA[SOCCER_BLOCK_SIZE_C2];
    static std::uint8_t                         mCompressLaneB[SOCCER_BLOCK_SIZE_C2];
    static std::uint8_t                         mCompressLaneC[SOCCER_BLOCK_SIZE_C2];
    static std::uint8_t                         mCompressLaneD[SOCCER_BLOCK_SIZE_C2];
    
    static std::uint8_t                         mCrushA[S_BLOCK];
    static std::uint8_t                         mCrushB[S_BLOCK];
    static std::uint8_t                         mCrushC[S_BLOCK];
    static std::uint8_t                         mCrushD[S_BLOCK];
    
    static std::size_t                          mIndexListA[2048];
    static std::size_t                          mIndexListB[2048];
    
    static std::uint64_t                        mRolledA[256];
    static std::uint64_t                        mRolledB[256];
    static std::uint64_t                        mRotationSeedS3[SOCCER_ROTATION_WORD_COUNT_S3];
    static std::uint64_t                        mRotationSeedS2[SOCCER_ROTATION_WORD_COUNT_S2];
    static std::uint64_t                        mRotationSeedS1[SOCCER_ROTATION_WORD_COUNT_S1];
    
    
    static void                                 Zero();
    
    static void                                 ConfigureTestBuffers(std::uint32_t pTestBlockLength); // SOCCER_BLOCK_SIZE (L3 size)
    
    //#define SOCCER_BLOCK_SIZE_L1 262144
    //#define SOCCER_BLOCK_SIZE_L2 524288
    //#define SOCCER_BLOCK_SIZE 1048576
    
    static bool                                 AttemptSeed_Encrypt(EncryptionStrength pStrength,
                                                                    std::uint8_t *pPassword,
                                                                    std::size_t pPasswordByteLength,
                                                                    std::uint64_t pNonce,
                                                                    std::uint32_t *pAckWord);
    
    static bool                                 AttemptSeed_Decrypt(EncryptionStrength pStrength,
                                                                    std::uint8_t *pPassword,
                                                                    std::size_t pPasswordByteLength,
                                                                    std::uint64_t pNonce,
                                                                    std::uint32_t pAckWord);
    
    
    
    
    
    //prologue
    
    
    static void                                 EncryptBlock(std::uint8_t *pSource,
                                                             std::uint8_t *pDestination);
    static void                                 DecryptBlock(std::uint8_t *pSource,
                                                             std::uint8_t *pDestination);
    
    //private:
    
    static void                                 InitializeMasks();
    static void                                 InitializeCiphers();
    static void                                 InitializeExpanders();
    static void                                 InitializeWorkSpaces();
    static void                                 InitializeMaterials();
    
    
    static void                                 UnrollNonceAndPasswordToScratch_Test(std::uint8_t *pPassword,
                                                                                     std::size_t pPasswordByteLength,
                                                                                     std::uint64_t pNonce);
    static void                                 UnrollNonceAndPasswordToScratch_Regular(std::uint8_t *pPassword,
                                                                                        std::size_t pPasswordByteLength,
                                                                                        std::uint64_t pNonce);
    
    
    static bool                                 SeedPrelude_Test(std::uint8_t *pPassword,
                                                                 std::size_t pPasswordByteLength,
                                                                 std::uint64_t pNonce);
    static void                                 SeedPrelude_Regular_A(std::uint8_t *pPassword,
                                                                      std::size_t pPasswordByteLength,
                                                                      std::uint64_t pNonce);
    static void                                 SeedPrelude_Regular_B(std::uint64_t pNonce);
    static void                                 SeedPrelude_Regular_C();
    
    
    static void                                 SeedPrologue_Regular_A(std::uint8_t *pPassword,
                                                                       std::size_t pPasswordByteLength,
                                                                       std::uint64_t pNonce);
    static void                                 SeedPrologue_Regular_B();
    static bool                                 SeedPrologue_Regular_C(std::uint32_t *pAckWord,
                                                                       bool pForwardDeploy);
    static void                                 SeedPrologue_Regular_D();
    
    
    static void                                 TwistRound(std::size_t pBlockIndex);
    
    
    
    
    static void                                 SeedEpilogue_Regular_A();
    static std::uint64_t                        SeedEpilogue_Regular_B();
    static void                                 SeedEpilogue_Regular_C(std::uint64_t pCipherWord);
    
    
    
    static void                                 ShuffleMEWBlockZero(std::uint8_t *pMaterial);
    
    // MAT WS CI EX MAS SOR CRO1 CRO2 CRO3 CRO4
    static void                                 Shuffle_CROWSCIMASSORMATEX();
    
    static void                                 FoldMaterialsIntoRandomForBlock_4(std::size_t pBlockIndex);
    static void                                 FoldMaterialsIntoRandomForBlock_8(std::size_t pBlockIndex);
    static void                                 FoldMaterialsIntoRandomForBlock_16(std::size_t pBlockIndex);
    
    static void                                 RotateSourcesIntoCross();
    
    static std::uint8_t                         mMasks[32];
    
    static std::uint8_t                         *mMaterials[16];
    static TwistExpander                        *mExpanders[SOCCER_EXPANDER_COUNT];
    static TwistWorkSpace                       *mWorkSpaces[16];
    
    static std::uint8_t                         *mSources[16];
    static std::uint8_t                         *mCross[4][16];
    static CipherType                           mCiphers[256];
    
    
    static bool                                 mClaimed[SOCCER_EXPANDER_COUNT];
    
    static TwistExpander                        *mClaimedExpanders[16];
    static std::size_t                          mClaimedExpanderCount;
    
    static std::uint8_t                         *mClaimedMaterials[16];
    static std::size_t                          mClaimedMaterialCount;
    
    static TwistWorkSpace                       *mClaimedWorkSpaces[16];
    static std::size_t                          mClaimedWorkSpaceCount;
    
    static Cryptex                              mCryptex;
    
    static std::uint8_t                         *mShuffleMaterials[16];
    static TwistExpander                        *mShuffleExpanders[SOCCER_EXPANDER_COUNT];
    static TwistWorkSpace                       *mShuffleWorkSpaces[16];
    
    static EncryptionStrength                   mStrength;
    
    static uint32_t                             mTestBlockLength;
    
    static Crypt                                *GenerateCipher(CipherType pType, std::uint8_t pStage);
    static std::uint8_t                         *PopLaneS3();
    static std::uint8_t                         *PopLaneS2();
    static std::uint8_t                         *PopLaneS1();
    static std::uint8_t                         PopMask();
    static std::int32_t                         PopRotation(std::uint8_t pStage);
    
    
    static std::size_t                          mRotationBankCursorL3A;
    static std::size_t                          mRotationBankCursorL2A;
    static std::size_t                          mRotationBankCursorL1A;
    
    static std::size_t                          mRotationBankCursorL3B;
    static std::size_t                          mRotationBankCursorL2B;
    static std::size_t                          mRotationBankCursorL1B;
    
    static std::size_t                          mRotationBankCursorL3C;
    
    
};

#ifndef SOCCER2_DISABLE_COMPAT_ALIAS
using Soccer2 = Soccer2Internal;
#endif

#endif /* Soccer2_hpp */
