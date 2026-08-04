//
//  EncryptionPlan.hpp
//  Scramble
//
//  Created by nick on 8/4/26.
//

#ifndef EncryptionPlan_hpp
#define EncryptionPlan_hpp

#include "SoccerTypes.hpp"
#include <cstddef>
#include <cstdint>

#define SHUFFLED_CIPHERS_LENGTH 256

enum class EncryptionPlanError : std::uint8_t {
    kNone = 0,
    
    kKeyInvalidLaneCount = 70,
    
    kKeySimpleNotFound = 1,
    kKeyComplexNotFound = 2,
    kKeyAnyNotFound = 3,
    
    
};

/*
enum class CipherCategory : std::uint8_t {
    kNone = 0,
    
    kKeyConsumeSimple = 0xA1,
    // [kPasswordXORCipher, kPasswordAddCipher, kPasswordSubtractCipher, kPasswordJumpXORCipher,
    //  kPasswordJumpAddCipher, kPasswordJumpSubtractCipher]
    
    kKeyConsumeComplex = 0xA2,
    // [kPepperNoiseXORCipher, kPepperJumpNoiseXORCipher, kPepperDualJumpNoiseXORCipher,
    //  kCascadeCipher, kCascadeJumpCipher]
    
    kKeyConsumeAny = 0xA3,
    // [kPasswordXORCipher, kPasswordAddCipher, kPasswordSubtractCipher, kPasswordJumpXORCipher
    // kPasswordJumpAddCipher, kPasswordJumpSubtractCipher, kPepperNoiseXORCipher
    // kPepperJumpNoiseXORCipher, kPepperDualJumpNoiseXORCipher, kCascadeCipher, kCascadeJumpCipher]
    
    
    kMoverPrimary = 0xB1,
    // [kRotateMaskCipher]
    
    kMoverAny = 0xB1,
    // [kWeaveMaskCipher, kRotateCipher, kRippleMaskBlockCipher32, kRippleMaskBlockCipher64
    // kWeaveMaskBlockCipher32, kWeaveMaskBlockCipher64, kSplintMaskBlockCipher32, kSplintMaskBlockCipher64]
};
*/

struct EncryptionPlan {
    CipherType mTypeL3[12];
    CipherType mTypeL2[12];
    CipherType mTypeL1[12];
    CipherType mTypeF3[12];
    std::size_t mCountL3;
    std::size_t mCountL2;
    std::size_t mCountL1;
    std::size_t mCountF3;
};

struct EncryptionPlanBudget {
    std::size_t mRotationCountS3 = 5;
    std::size_t mRotationCountS2 = 3;
    std::size_t mRotationCountS1 = 3;
    std::size_t mWeaveCount = 2;
};

class EncryptionPlanTool {
  
    static EncryptionPlan               MakePlanWeak(std::uint64_t pLaneSelect,
                                                     EncryptionPlanBudget pBudget,
                                                     EncryptionStrength pStrength,
                                                     CipherType *pShuffledCiphers,
                                                     EncryptionPlanError *pError);
    
    
    //k = 0,
    //kNormal = 1,
    //kStrong = 2,
    
private:
    
    // pIndex can be [0...255]
    static CipherType                   RingFetchKeySimple(CipherType *pShuffledCiphers, std::uint8_t pLaneCount, std::size_t *pIndex, EncryptionPlanError *pError);
    static CipherType                   RingFetchKeyComplex(CipherType *pShuffledCiphers, std::uint8_t pLaneCount, std::size_t *pIndex, EncryptionPlanError *pError);
    static CipherType                   RingFetchKeyAny(CipherType *pShuffledCiphers, std::uint8_t pLaneCount, std::size_t *pIndex, EncryptionPlanError *pError);
    
    
};



#endif /* EncryptionPlan_hpp */
