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

    static void                                 InitializeAvalancheReferenceMaterials(const std::uint8_t *(&pMaterials)[16]);

private:

    static TwistFarmSalt                        mFarmSalt;

    static TwistExpander_Achernar               mAchernar; // 1
    static TwistExpander_Alcor                  mAlcor; // 2
    static TwistExpander_Aldebaran              mAldebaran; // 3
    static TwistExpander_Alioth                 mAlioth; // 4
    static TwistExpander_Alkaid                 mAlkaid; // 5
    static TwistExpander_Alnitak                mAlnitak; // 6
    static TwistExpander_Altair                 mAltair; // 7
    static TwistExpander_Ankaa                  mAnkaa; // 8
    static TwistExpander_Antares                mAntares; // 9
    static TwistExpander_Arcturus               mArcturus; // 10
    static TwistExpander_Athebyne               mAthebyne; // 11
    static TwistExpander_Bellatrix              mBellatrix; // 12
    static TwistExpander_Betelgeuse             mBetelgeuse; // 13
    static TwistExpander_Canopus                mCanopus; // 14
    static TwistExpander_Capella                mCapella; // 15
    static TwistExpander_Castor                 mCastor; // 16
    static TwistExpander_Mebsuta                mMebsuta; // 17
    static TwistExpander_Menkent                mMenkent; // 18
    static TwistExpander_Mimosa                 mMimosa; // 19
    static TwistExpander_Miram                  mMiram; // 20
    static TwistExpander_Mirfak                 mMirfak; // 21
    static TwistExpander_Mothallah              mMothallah; // 22
    static TwistExpander_Naos                   mNaos; // 23
    static TwistExpander_Polaris                mPolaris; // 24
    static TwistExpander_Pollux                 mPollux; // 25
    static TwistExpander_Procyon                mProcyon; // 26
    static TwistExpander_Regulus                mRegulus; // 27
    static TwistExpander_Rigel                  mRigel; // 28
    static TwistExpander_Saiph                  mSaiph; // 29
    static TwistExpander_Sirius                 mSirius; // 30
    static TwistExpander_Suhail                 mSuhail; // 31
    static TwistExpander_Vega                   mVega; // 32

    static std::uint8_t                         mMasks[32];

    static std::uint8_t                         *mMaterials[16];
    static TwistExpander                        *mExpanders[32];
    static TwistWorkSpace                       *mWorkSpaces[16];
    static std::uint8_t                         *mSources[16];

    static TwistExpander                        *mClaimedExpanders[16];
    static std::size_t                          mClaimedExpanderCount;

    static std::uint8_t                         *mClaimedMaterials[16];
    static std::size_t                          mClaimedMaterialCount;

    static TwistWorkSpace                       *mClaimedWorkSpaces[16];
    static std::size_t                          mClaimedWorkSpaceCount;

    static std::uint8_t                         mCiphersIdentifiersA[64];
    static std::uint8_t                         mCiphersIdentifiersB[64];

    static std::uint64_t                        mRotationAmountsL3[2];
    static std::uint64_t                        mRotationAmountsL2[2];
    static std::uint64_t                        mRotationAmountsL1[2];
    static std::uint64_t                        mRotationAmountsFinal[2];

    static LayeredCrypt                         mCrypt;
    static EncryptionLayer                      mFinalL3;

    static std::uint64_t                        Read64(const std::uint8_t *pSource);
    
    static bool                                 SeedPrelude(std::uint8_t *pPassword,
                                                            std::size_t pPasswordByteLength,
                                                            std::uint64_t pNonce);
    static void                                 SeedEpilogue();
    
    static void                                 ShuffleMEWBlockZero(std::uint8_t *pMaterial);
    
    static void                                 ShuffleSEWMMCC();
    
    static void                                 FoldAllMaterialsIntoRandomForBlock(std::size_t pBlockIndex);
    
    static std::uint8_t                         *mShuffleMaterials[16];
    static TwistExpander                        *mShuffleExpanders[32];
    static TwistWorkSpace                       *mShuffleWorkSpaces[16];
};

#endif /* Soccer_hpp */
