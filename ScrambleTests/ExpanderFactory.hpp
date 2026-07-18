//
//  ExpanderFactory.hpp
//  ScrambleTests
//
//  Created by nicholas raptis on 7/17/26.
//

#ifndef ExpanderFactory_hpp
#define ExpanderFactory_hpp

#include <stdio.h>
#include <string>
#include <vector>

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


struct ExpanderItem {
    TwistExpander       *mExpander;
    std::string         mName;
};

class ExpanderFactory {
    
    static inline TwistExpander_Gemma           mGemma;
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
    
public:
    
    static std::vector<ExpanderItem>        Get() {
        
        std::vector<ExpanderItem> aResult;
        
        aResult.push_back({&mAchernar, "Achernar"});
        aResult.push_back({&mAlcor, "Alcor"});
        aResult.push_back({&mAldebaran, "Aldebaran"});
        aResult.push_back({&mAlioth, "Alioth"});
        
        aResult.push_back({&mAlkaid, "Alkaid"});
        aResult.push_back({&mAlnitak, "Alnitak"});
        aResult.push_back({&mAltair, "Altair"});
        aResult.push_back({&mAnkaa, "Ankaa"});
        
        aResult.push_back({&mAntares, "Antares"});
        aResult.push_back({&mArcturus, "Arcturus"});
        aResult.push_back({&mAthebyne, "Athebyne"});
        aResult.push_back({&mBellatrix, "Bellatrix"});
        
        aResult.push_back({&mBetelgeuse, "Betelgeuse"});
        aResult.push_back({&mCanopus, "Canopus"});
        aResult.push_back({&mCapella, "Capella"});
        aResult.push_back({&mCastor, "Castor"});
        
        aResult.push_back({&mGemma, "Gemma"});
        
        aResult.push_back({&mMebsuta, "mMebsuta"});
        aResult.push_back({&mMenkent, "mMenkent"});
        aResult.push_back({&mMimosa, "mMimosa"});
        aResult.push_back({&mMiram, "mMiram"});
        
        aResult.push_back({&mMirfak, "Mirfak"});
        aResult.push_back({&mMothallah, "Mothallah"});
        aResult.push_back({&mNaos, "Naos"});
        aResult.push_back({&mPolaris, "Polaris"});
        
        aResult.push_back({&mPollux, "Pollux"});
        aResult.push_back({&mProcyon, "Procyon"});
        aResult.push_back({&mRegulus, "Regulus"});
        aResult.push_back({&mRigel, "Rigel"});
        
        aResult.push_back({&mSaiph, "Saiph"});
        aResult.push_back({&mSirius, "Sirius"});
        aResult.push_back({&mSuhail, "Suhail"});
        aResult.push_back({&mVega, "Vega"});
        
        return aResult;
    }
    
};

#endif /* ExpanderFactory_hpp */
