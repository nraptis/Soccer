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

class Cryptex {
public:

    void                        AddCipherL3(Crypt *pCipher);
    void                        AddCipherL2(Crypt *pCipher);
    void                        AddCipherL1(Crypt *pCipher);
    void                        AddCipherF3(Crypt *pCipher);
    
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

    EncryptionLayer             mLayerL3;
    EncryptionLayer             mLayerL2;
    EncryptionLayer             mLayerL1;
    EncryptionLayer             mLayerF3;
    
};

#endif /* Cryptex_hpp */
