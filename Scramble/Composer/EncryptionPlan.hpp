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

    kMoverPrimaryRotationNotFound = 4,
    kMoverSecondaryOrPrimaryNotFound = 8,
    kMoverSecondaryOnlyNotFound = 9,
    kMoverNonRotationAnyNotFound = 10,
    
    
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
    std::size_t mCountL3 = 0;
    std::size_t mCountL2 = 0;
    std::size_t mCountL1 = 0;
    std::size_t mCountF3 = 0;
};

class EncryptionPlanTool {
    
public:
  
    static EncryptionPlan               MakePlanWeak(std::uint64_t pLaneSelect,
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

    // masked or not masked
    static CipherType                   RingFetchMoverPrimaryRotation(CipherType *pShuffledCiphers, std::size_t *pIndex, EncryptionPlanError *pError);

    // Any mover without the rotation flag, including primary and secondary movers.
    static CipherType                   RingFetchMoverNonRotationAny(CipherType *pShuffledCiphers, std::size_t *pIndex, EncryptionPlanError *pError);


    // kSplintMaskBlockCipher32, kSplintMaskBlockCipher64, kRippleMaskBlockCipher32, kRippleMaskBlockCipher64, kReverseMaskByteBlockCipher32, kReverseMaskByteBlockCipher64
    // kRotateMaskCipher, kReverseMaskCipher, kInvertMaskCipher, kWeaveMaskCipher, kWeaveMaskBlockCipher32, kWeaveMaskBlockCipher64, kRotateCipher
    static CipherType                   RingFetchMoverSecondaryOrPrimary(CipherType *pShuffledCiphers, std::size_t *pIndex, EncryptionPlanError *pError);


    // kSplintMaskBlockCipher32, kSplintMaskBlockCipher64, kRippleMaskBlockCipher32, kRippleMaskBlockCipher64, kReverseMaskByteBlockCipher32, kReverseMaskByteBlockCipher64
    static CipherType                   RingFetchMoverSecondaryOnly(CipherType *pShuffledCiphers, std::size_t *pIndex, EncryptionPlanError *pError);
    
};

#endif /* EncryptionPlan_hpp */
