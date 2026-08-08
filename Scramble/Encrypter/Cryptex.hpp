//
//  Cryptex.hpp
//  Scramble
//
//  Created by nick on 8/6/26.
//

#ifndef Cryptex_hpp
#define Cryptex_hpp

#include <cstddef>
#include <cstdint>

#include "EncryptionLayer.hpp"

#include "PasswordXORCipher.hpp"
#include "PasswordAddCipher.hpp"
#include "PasswordSubtractCipher.hpp"
#include "PasswordJumpXORCipher.hpp"
#include "PasswordJumpAddCipher.hpp"
#include "PasswordJumpSubtractCipher.hpp"
#include "PepperNoiseXORCipher.hpp"
#include "PepperJumpNoiseXORCipher.hpp"
#include "PepperDualJumpNoiseXORCipher.hpp"
#include "CascadeCipher.hpp"
#include "CascadeJumpCipher.hpp"

#include "RotateMaskCipher.hpp"
#include "ReverseMaskCipher.hpp"
#include "InvertMaskCipher.hpp"
#include "ReverseMaskByteBlockCipher32.hpp"
#include "ReverseMaskByteBlockCipher64.hpp"
#include "SplintMaskBlockCipher32.hpp"
#include "SplintMaskBlockCipher64.hpp"
#include "RotateCipher.hpp"
#include "RippleMaskBlockCipher32.hpp"
#include "RippleMaskBlockCipher64.hpp"

class Cryptex {
public:

    void                        AddCipherL3A(Crypt *pCipher);
    void                        AddCipherL2A(Crypt *pCipher);
    void                        AddCipherL1A(Crypt *pCipher);
    
    void                        AddCipherL3B(Crypt *pCipher);
    void                        AddCipherL2B(Crypt *pCipher);
    void                        AddCipherL1B(Crypt *pCipher);
    
    void                        AddCipherL3C(Crypt *pCipher);
    
    
    
    void                        Free();
    
    bool                        SealData(const std::uint8_t *pSource,
                                        std::uint8_t *pWorkerA,
                                        std::uint8_t *pWorkerB,
                                        std::uint8_t *pDestination,
                                        std::size_t pLength,
                                        CipherErrorCode *pErrorCode) const;

    bool                        UnsealData(const std::uint8_t *pSource,
                                          std::uint8_t *pWorkerA,
                                          std::uint8_t *pWorkerB,
                                          std::uint8_t *pDestination,
                                          std::size_t pLength,
                                          CipherErrorCode *pErrorCode) const;
    
private:

    EncryptionLayer             mLayerL3A;
    EncryptionLayer             mLayerL2A;
    EncryptionLayer             mLayerL1A;
    EncryptionLayer             mLayerL3B;
    EncryptionLayer             mLayerL2B;
    EncryptionLayer             mLayerL1B;
    EncryptionLayer             mLayerL3C;
};

#endif /* Cryptex_hpp */
