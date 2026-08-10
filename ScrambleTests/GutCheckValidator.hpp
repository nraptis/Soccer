//
//  GutCheckValidator.hpp
//  ScrambleTests
//
//  Created by nick on 8/9/26.
//

#ifndef GutCheckValidator_hpp
#define GutCheckValidator_hpp

#include "Random.hpp"
#include "Soccer2.hpp"
#include "WorkSpaceTools.hpp"

struct GutCheckAvalancheScore {
    std::size_t mDifferentBytes = 0U;
    std::size_t mDifferentBits = 0U;
};


class GutCheckValidator {
    
public:
    
    static bool                     Validate(const char *pTestName,
                                             EncryptionStrength pStrength,
                                             std::uint8_t *pPassword,
                                             std::size_t pPasswordByteLength,
                                             std::uint64_t pNonce);
    
    static bool                     ValidatePostSeed(const char *pTestName,
                                                     EncryptionStrength pStrength);
    
    
    static bool                     ValidateMaterials(const char *pTestName,
                                                      EncryptionStrength pStrength);
    static bool                     ValidateIndex2048(const char *pTestName);
    static bool                     ValidateMask(const char *pTestName);
    static bool                     ValidateRotation(const char *pTestName);
    
    static GutCheckAvalancheScore   ScoreBuffers(const std::uint8_t *pBufferA,
                                                 const std::uint8_t *pBufferB);
    
    
};

#endif /* GutCheckValidator_hpp */
