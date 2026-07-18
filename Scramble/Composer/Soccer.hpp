//
//  Soccer.hpp
//  Cover Lettur
//

#ifndef Soccer_hpp
#define Soccer_hpp

#include "TwistFarmSalt.hpp"
#include "TwistWorkSpace.hpp"

#include "EncryptionLayer.hpp"

#include "TwistExpander_Gemma.hpp"

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

#include "LayeredCrypt.hpp"
#include "Jelly.hpp"

#include <cstddef>
#include <cstdint>

class Soccer {
public:
    
    static bool                                 AttemptSeed_Encrypt(std::uint8_t *pPassword,
                                                                    std::size_t pPasswordByteLength,
                                                                    std::uint64_t pNonce,
                                                                    std::uint32_t *pAckWord);
    
    static bool                                 AttemptSeed_Decrypt(std::uint8_t *pPassword,
                                                                    std::size_t pPasswordByteLength,
                                                                    std::uint64_t pNonce,
                                                                    std::uint32_t pAckWord);
    
    static bool                                 EncryptBlock(std::uint8_t *pSource,
                                                             std::uint8_t *pDestination);
    static bool                                 DecryptBlock(std::uint8_t *pSource,
                                                             std::uint8_t *pDestination);
    
    static inline std::uint8_t                  mMaterialA[SOCCER_BLOCK_SIZE];
    static inline std::uint8_t                  mMaterialB[SOCCER_BLOCK_SIZE];
    static inline std::uint8_t                  mMaterialC[SOCCER_BLOCK_SIZE];
    static inline std::uint8_t                  mMaterialD[SOCCER_BLOCK_SIZE];

    static inline std::uint8_t                  mMaterialE[SOCCER_BLOCK_SIZE];
    static inline std::uint8_t                  mMaterialF[SOCCER_BLOCK_SIZE];
    static inline std::uint8_t                  mMaterialG[SOCCER_BLOCK_SIZE];
    static inline std::uint8_t                  mMaterialH[SOCCER_BLOCK_SIZE];

    static inline std::uint8_t                  mMaterialI[SOCCER_BLOCK_SIZE];
    static inline std::uint8_t                  mMaterialJ[SOCCER_BLOCK_SIZE];
    static inline std::uint8_t                  mMaterialK[SOCCER_BLOCK_SIZE];
    static inline std::uint8_t                  mMaterialL[SOCCER_BLOCK_SIZE];
    
    static inline std::uint8_t                  mMaterialM[SOCCER_BLOCK_SIZE];
    static inline std::uint8_t                  mMaterialN[SOCCER_BLOCK_SIZE];
    static inline std::uint8_t                  mMaterialO[SOCCER_BLOCK_SIZE];
    static inline std::uint8_t                  mMaterialP[SOCCER_BLOCK_SIZE];
    
private:
    
    // This is only used for the initial shuffle.
    static inline TwistExpander_Gemma           mStarter;
    
    static inline TwistWorkSpace                mWorkSpaceA;
    static inline TwistWorkSpace                mWorkSpaceB;
    static inline TwistWorkSpace                mWorkSpaceC;
    static inline TwistWorkSpace                mWorkSpaceD;
    static inline TwistWorkSpace                mWorkSpaceE;
    static inline TwistWorkSpace                mWorkSpaceF;
    static inline TwistWorkSpace                mWorkSpaceG;
    static inline TwistWorkSpace                mWorkSpaceH;
    static inline TwistWorkSpace                mWorkSpaceI;
    static inline TwistWorkSpace                mWorkSpaceJ;
    static inline TwistWorkSpace                mWorkSpaceK;
    static inline TwistWorkSpace                mWorkSpaceL;
    static inline TwistWorkSpace                mWorkSpaceM;
    static inline TwistWorkSpace                mWorkSpaceN;
    static inline TwistWorkSpace                mWorkSpaceO;
    static inline TwistWorkSpace                mWorkSpaceP;
    
    static inline TwistFarmSalt                 mFarmSalt;
    
    static inline TwistExpander_Achernar        mAchernar; // 1
    static inline TwistExpander_Alcor           mAlcor; // 2
    static inline TwistExpander_Aldebaran       mAldebaran; // 3
    static inline TwistExpander_Alioth          mAlioth; // 4
    static inline TwistExpander_Alkaid          mAlkaid; // 5
    static inline TwistExpander_Alnitak         mAlnitak; // 6
    static inline TwistExpander_Altair          mAltair; // 7
    static inline TwistExpander_Ankaa           mAnkaa; // 8
    static inline TwistExpander_Antares         mAntares; // 9
    static inline TwistExpander_Arcturus        mArcturus; // 10
    static inline TwistExpander_Athebyne        mAthebyne; // 11
    static inline TwistExpander_Bellatrix       mBellatrix; // 12
    static inline TwistExpander_Betelgeuse      mBetelgeuse; // 13
    static inline TwistExpander_Canopus         mCanopus; // 14
    static inline TwistExpander_Capella         mCapella; // 15
    static inline TwistExpander_Castor          mCastor; // 16
    static inline TwistExpander_Mebsuta         mMebsuta; // 17
    static inline TwistExpander_Menkent         mMenkent; // 18
    static inline TwistExpander_Mimosa          mMimosa; // 19
    static inline TwistExpander_Miram           mMiram; // 20
    static inline TwistExpander_Mirfak          mMirfak; // 21
    static inline TwistExpander_Mothallah       mMothallah; // 22
    static inline TwistExpander_Naos            mNaos; // 23
    static inline TwistExpander_Polaris         mPolaris; // 24
    static inline TwistExpander_Pollux          mPollux; // 25
    static inline TwistExpander_Procyon         mProcyon; // 26
    static inline TwistExpander_Regulus         mRegulus; // 27
    static inline TwistExpander_Rigel           mRigel; // 28
    static inline TwistExpander_Saiph           mSaiph; // 29
    static inline TwistExpander_Sirius          mSirius; // 30
    static inline TwistExpander_Suhail          mSuhail; // 31
    static inline TwistExpander_Vega            mVega; // 32
    
    static inline std::uint8_t                  mMasks[32];

    static inline std::uint8_t                  *mMaterials[16];
    static inline TwistExpander                 *mExpanders[32];
    static inline TwistWorkSpace                *mWorkSpaces[16];
    static inline std::uint8_t                  *mSources[16];

    static inline TwistExpander                 *mClaimedExpanders[16];
    static inline std::size_t                   mClaimedExpanderCount;
    
    static inline uint8_t                       *mClaimedMaterials[16];
    static inline std::size_t                   mClaimedMaterialCount;
    
    static inline TwistWorkSpace                *mClaimedWorkSpaces[16];
    static inline std::size_t                   mClaimedWorkSpaceCount;
    
    static inline std::uint8_t                  mCiphersIdentifiersA[64];
    static inline std::uint8_t                  mCiphersIdentifiersB[64];
    
    static inline std::uint8_t                  mRandom[S_BLOCK];
    
    static inline std::uint8_t                  mScratch[SOCCER_BLOCK_SIZE];
    
    static inline std::uint8_t                  mCrushA[S_BLOCK];
    static inline std::uint8_t                  mCrushB[S_BLOCK];
    static inline std::uint8_t                  mCrushC[S_BLOCK];
    static inline std::uint8_t                  mCrushD[S_BLOCK];
    
    static inline std::uint64_t                 mRotationAmountsL3[2];
    static inline std::uint64_t                 mRotationAmountsL2[2];
    static inline std::uint64_t                 mRotationAmountsL1[2];
    static inline std::uint64_t                 mRotationAmountsFinal[2];
    
    static inline LayeredCrypt                  mCrypt;
    static inline EncryptionLayer               mFinalL3;
    
    static inline std::uint8_t                  mCryptTemp[SOCCER_BLOCK_SIZE];

    static std::uint64_t                        Read64(const std::uint8_t *pSource);
    

    
    static bool                                 SeedPrelude(std::uint8_t *pPassword,
                                                            std::size_t pPasswordByteLength,
                                                            std::uint64_t pNonce);
    static void                                 SeedEpilogue();
    
    static void                                 ShuffleMEWBlockZero(std::uint8_t *pMaterial);
    
    static void                                 ShuffleSEWMMCC();
    
    
    static void                                 FoldAllMaterialsIntoRandomForBlock(std::size_t pBlockIndex);
    
    
    static void                                 PrintDebugLists(bool pIsEncrypt);
    
    static inline std::uint8_t                  *mShuffleMaterials[16];
    static inline TwistExpander                 *mShuffleExpanders[32];
    static inline TwistWorkSpace                *mShuffleWorkSpaces[16];
    
    
};

#endif /* Soccer_hpp */
