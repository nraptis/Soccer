//
//  Soccer2.hpp
//  Scramble
//
//  Created by nick on 8/1/26.
//

#ifndef Soccer2_hpp
#define Soccer2_hpp

#include "TwistFarmSalt.hpp"
#include "TwistWorkSpace.hpp"
#include "TwistShuffle.hpp"
#include "TwistFunctional.hpp"
#include "SoccerTypes.hpp"


#include "EncryptionLayer.hpp"

#include "LayeredCrypt.hpp"
#include "Jelly.hpp"

#include "TwistExpander_Achernar.hpp"
#include "TwistExpander_Alcor.hpp"
#include "TwistExpander_Aldebaran.hpp"
#include "TwistExpander_Alioth.hpp"
#include "TwistExpander_Alkaid.hpp"
#include "TwistExpander_Alnitak.hpp"
#include "TwistExpander_Altair.hpp"
#include "TwistExpander_Ankaa.hpp"
#include "TwistExpander_Antares.hpp"
#include "TwistExpander_Arcturus.hpp"
#include "TwistExpander_Athebyne.hpp"
#include "TwistExpander_Bellatrix.hpp"
#include "TwistExpander_Betelgeuse.hpp"
#include "TwistExpander_Canopus.hpp"
#include "TwistExpander_Capella.hpp"
#include "TwistExpander_Castor.hpp"
#include "TwistExpander_Gemma.hpp"
#include "TwistExpander_Mebsuta.hpp"
#include "TwistExpander_Menkent.hpp"
#include "TwistExpander_Mimosa.hpp"
#include "TwistExpander_Miram.hpp"
#include "TwistExpander_Mirfak.hpp"
#include "TwistExpander_Mothallah.hpp"
#include "TwistExpander_Naos.hpp"
#include "TwistExpander_Polaris.hpp"
#include "TwistExpander_Pollux.hpp"
#include "TwistExpander_Procyon.hpp"
#include "TwistExpander_Regulus.hpp"
#include "TwistExpander_Rigel.hpp"
#include "TwistExpander_Saiph.hpp"
#include "TwistExpander_Sirius.hpp"
#include "TwistExpander_Suhail.hpp"
#include "TwistExpander_Vega.hpp"

#include <cstddef>
#include <cstdint>


class Soccer2 {
public:
    
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
    static bool                                 SeedPrelude_Regular(std::uint8_t *pPassword,
                                                            std::size_t pPasswordByteLength,
                                                            std::uint64_t pNonce);
    
    
    static bool                                 SeedPrologue_A(std::uint8_t *pPassword,
                                                               std::size_t pPasswordByteLength,
                                                               std::uint64_t pNonce,
                                                               std::uint32_t *pAckWord,
                                                               bool pForwardDeploy);
    
    static void                                 SeedPrologue_B();
    
    static void                                 TwistRound(std::size_t pBlockIndex);
    
    
    
    
    static void                                 SeedEpilogue();
    
    static void                                 ShuffleMEWBlockZero(std::uint8_t *pMaterial);
    
    // MAT WS CI EX MAS SOR CRO1 CRO2 CRO3 CRO4
    static void                                 Shuffle_CROWSCIMASSORMATEX();
    
    static void                                 FoldMaterialsIntoRandomForBlock_4(std::size_t pBlockIndex);
    static void                                 FoldMaterialsIntoRandomForBlock_8(std::size_t pBlockIndex);
    static void                                 FoldMaterialsIntoRandomForBlock_16(std::size_t pBlockIndex);
    
    static void                                 RotateSourcesIntoCross();
    
    
    static std::uint8_t                         mMasks[32];

    static std::uint8_t                         *mMaterials[16];
    static TwistExpander                        *mExpanders[32];
    static TwistWorkSpace                       *mWorkSpaces[16];
    
    static std::uint8_t                         *mSources[16];
    static std::uint8_t                         *mCross[4][16];
    static CipherType                           mCiphers[256];
    
    
    static bool                                 mClaimed[32];
    
    static TwistExpander                        *mClaimedExpanders[16];
    static std::size_t                          mClaimedExpanderCount;

    static std::uint8_t                         *mClaimedMaterials[16];
    static std::size_t                          mClaimedMaterialCount;

    static TwistWorkSpace                       *mClaimedWorkSpaces[16];
    static std::size_t                          mClaimedWorkSpaceCount;

    static LayeredCrypt                         mCrypt;
    static EncryptionLayer                      mFinalL3;
    
    static std::uint8_t                         *mShuffleMaterials[16];
    static TwistExpander                        *mShuffleExpanders[32];
    static TwistWorkSpace                       *mShuffleWorkSpaces[16];
    
    
    
    static EncryptionStrength                   mStrength;
    
    static uint32_t                             mTestBlockLength;
    
    
};

#endif /* Soccer2_hpp */
