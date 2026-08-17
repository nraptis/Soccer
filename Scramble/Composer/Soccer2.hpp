//
//  Soccer2.hpp
//  Scramble
//
//  Created by nick on 8/1/26.
//

// Note: We want to remove weave ciphers

#ifndef Soccer2_hpp
#define Soccer2_hpp

#include "TwistWorkSpace.hpp"
#include "TwistShuffle.hpp"
#include "TwistFunctional.hpp"
#include "SoccerTypes.hpp"
#include "SoccerMaskBank.hpp"

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

#define SOCCER_EXPANDER_COUNT 16

#define SOCCER_PRELUDE_RAND mCollapseLaneB
#define SOCCER_SCRATCH_WORKER_A mCollapseLaneB
#define SOCCER_WORKER_B mCollapseLaneD

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
    static std::uint8_t                         *mMaterials[16];
    
    static std::uint8_t                         *mClaimedMaterials[16];
    static std::size_t                          mClaimedMaterialCount;
    
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
    static TwistWorkSpace                       *mWorkSpaces[16];
    static TwistWorkSpace                       *mClaimedWorkSpaces[16];
    static std::size_t                          mClaimedWorkSpaceCount;
    
    
    static TwistExpander_Betelgeuse             mStarter;
    static TwistExpander_Aldebaran              mAldebaran; // 1
    static TwistExpander_Altair                 mAltair; // 2
    static TwistExpander_Antares                mAntares; // 3
    static TwistExpander_Arcturus               mArcturus; // 4
    static TwistExpander_Bellatrix              mBellatrix; // 5
    static TwistExpander_Capella                mCapella; // 6
    static TwistExpander_Castor                 mCastor; // 7
    static TwistExpander_Mimosa                 mMimosa; // 8
    static TwistExpander_Polaris                mPolaris; // 9
    static TwistExpander_Pollux                 mPollux; // 10
    static TwistExpander_Procyon                mProcyon; // 11
    static TwistExpander_Regulus                mRegulus; // 12
    static TwistExpander_Rigel                  mRigel; // 13
    static TwistExpander_Saiph                  mSaiph; // 14
    static TwistExpander_Sirius                 mSirius; // 15
    static TwistExpander_Vega                   mVega; // 16
    
    /*
    static TwistExpander_Aldebaran             mStarter;
    static TwistExpander_Aldebaran              mAldebaran; // 1
    static TwistExpander_Aldebaran                 mAltair; // 2
    static TwistExpander_Aldebaran                mAntares; // 3
    static TwistExpander_Aldebaran               mArcturus; // 4
    static TwistExpander_Aldebaran              mBellatrix; // 5
    static TwistExpander_Aldebaran                mCapella; // 6
    static TwistExpander_Aldebaran                 mCastor; // 7
    static TwistExpander_Aldebaran                 mMimosa; // 8
    static TwistExpander_Aldebaran                mPolaris; // 9
    static TwistExpander_Aldebaran                 mPollux; // 10
    static TwistExpander_Aldebaran                mProcyon; // 11
    static TwistExpander_Aldebaran                mRegulus; // 12
    static TwistExpander_Aldebaran                  mRigel; // 13
    static TwistExpander_Aldebaran                  mSaiph; // 14
    static TwistExpander_Aldebaran                 mSirius; // 15
    static TwistExpander_Aldebaran                   mVega; // 16
    */
    
    
    static TwistExpander                        *mExpanders[SOCCER_EXPANDER_COUNT];
    static TwistExpander                        *mClaimedExpanders[16];
    static std::size_t                          mClaimedExpanderCount;
    
    static std::uint8_t                         mRandom[S_BLOCK];
    
    static std::uint8_t                         mCollapseLaneA[SOCCER_BLOCK_SIZE];
    static std::uint8_t                         mCollapseLaneB[SOCCER_BLOCK_SIZE];
    static std::uint8_t                         mCollapseLaneC[SOCCER_BLOCK_SIZE];
    static std::uint8_t                         mCollapseLaneD[SOCCER_BLOCK_SIZE];
    
    static std::uint8_t                         mCondenseLaneA[SOCCER_BLOCK_SIZE_L1];
    static std::uint8_t                         mCondenseLaneB[SOCCER_BLOCK_SIZE_L1];
    static std::uint8_t                         mCondenseLaneC[SOCCER_BLOCK_SIZE_L1];
    static std::uint8_t                         mCondenseLaneD[SOCCER_BLOCK_SIZE_L1];
    
    static std::uint8_t                         mMasks[SoccerMaskBank::mMaskGridWidth];
    
    static std::int32_t                         mRotationsL3[3];
    static std::int32_t                         mRotationsL2[3];
    static std::int32_t                         mRotationsL1[3];
    
    static std::uint8_t                         *mSources[16];
    static CipherType                           mCiphers[256];
    
    static std::uint8_t                         *mCross[4][16];
    static std::uint8_t                         *mCrossPool[16][64];
    static std::size_t                          mCrossPoolCount[16];
    static std::size_t                          mCrossPermutations[16][64];
    
    static bool                                 mClaimed[SOCCER_EXPANDER_COUNT];
    
    static Cryptex6                             mCryptex6;
    static Cryptex9                             mCryptex9;
    
    static std::uint8_t                         *mShuffleMaterials[16];
    static TwistExpander                        *mShuffleExpanders[SOCCER_EXPANDER_COUNT];
    static TwistWorkSpace                       *mShuffleWorkSpaces[16];
    
    static EncryptionStrength                   mStrength;
    static std::size_t                          mMaskCursor;
    
    static uint32_t                             mTestBlockLength;
    
    static std::size_t                          mIndexListA[2048];
    static std::size_t                          mIndexListB[2048];
    
    static std::uint64_t                        mPremiumSeed[256];
    
    static std::size_t                          mMaterialIndex;
    static std::size_t                          mMaterialQuarter;
    
    static void                                 Zero();
    
    static void                                 ConfigureTestBuffers(std::uint32_t pTestBlockLength); // SOCCER_BLOCK_SIZE (L3 size)
    
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
    
    static bool                                 EncryptBlock(std::uint8_t *pSource,
                                                             std::uint8_t *pDestination);
    static bool                                 DecryptBlock(std::uint8_t *pSource,
                                                             std::uint8_t *pDestination);
    
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
    static void                                 SeedPrelude_Regular_B(std::uint64_t pNonce, MUTABLE_PARAMS);
    static void                                 SeedPrelude_Regular_C();
    
    
    static void                                 SeedPrologue_Regular_A(std::uint8_t *pPassword,
                                                                       std::size_t pPasswordByteLength,
                                                                       std::uint64_t pNonce,
                                                                       MUTABLE_PARAMS);
    static void                                 SeedPrologue_Regular_B();
    static bool                                 SeedPrologue_Regular_C(std::uint32_t *pAckWord,
                                                                       bool pForwardDeploy,
                                                                       MUTABLE_PARAMS);
    static void                                 SeedPrologue_Regular_D(MUTABLE_PARAMS);
    
    
    static void                                 TwistRound(std::size_t pBlockIndex,
                                                           bool pIsWarmUpRound,
                                                           MUTABLE_PARAMS);
    
    
    static void                                 ArrangeCrossPool(std::size_t pComplexity);
    static void                                 InitializeCrossPermutations();
    static void                                 BuildCrossPool_WarmUp1(std::size_t pComplexity,
                                                                       std::size_t pCurrentByteIndex);
    static void                                 BuildCrossPool_WarmUp2(std::size_t pComplexity,
                                                                       std::size_t pPreviousByteIndex,
                                                                       std::size_t pCurrentByteIndex);
    static void                                 BuildCrossPool_WarmUp4(std::size_t pComplexity,
                                                                       std::size_t pThreeRoundsBackByteIndex,
                                                                       std::size_t pTwoRoundsBackByteIndex,
                                                                       std::size_t pOneRoundBackByteIndex);
    static void                                 BuildCrossPool_Regular(std::size_t pComplexity,
                                                                      std::size_t pFourRoundsBackByteIndex,
                                                                      std::size_t pThreeRoundsBackByteIndex,
                                                                      std::size_t pTwoRoundsBackByteIndex,
                                                                      std::size_t pOneRoundBackByteIndex);
    
    static void                                 SeedEpilogue_Regular_A();
    static void                                 SeedEpilogue_Regular_B();
    static void                                 SeedEpilogue_Regular_C();
    static bool                                 SeedEpilogue_Regular_D();
    
    
    
    static void                                 Shuffle_MEWBlockZero(std::uint8_t *pMaterial);
    
    // MAT WS CI EX MAS SOR CRO1 CRO2 CRO3 CRO4
    static void                                 Shuffle_CROWSCIMASSORMATEX();
    static void                                 Shuffle_CROSSPERMUTATIONS(std::size_t pPermutationCount);
    
    static void                                 FoldMaterialsIntoRandomForBlock_4(std::size_t pBlockIndex);
    static void                                 FoldMaterialsIntoRandomForBlock_8(std::size_t pBlockIndex);
    static void                                 FoldMaterialsIntoRandomForBlock_16(std::size_t pBlockIndex);
    
    static Cipher                               *GenerateCipher(CipherType pType, std::uint8_t pStage);
    static std::uint8_t                         *PopLaneS3();
    static std::uint8_t                         *PopLaneS2();
    static std::uint8_t                         *PopLaneS1();
    static std::uint8_t                         PopMask();
    static std::int32_t                         PopRotation(std::uint8_t pStage);
    
    
    
    
};

#ifndef SOCCER2_DISABLE_COMPAT_ALIAS
using Soccer2 = Soccer2Internal;
#endif

#endif /* Soccer2_hpp */
