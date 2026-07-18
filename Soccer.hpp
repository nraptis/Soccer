//
//  Soccer.hpp
//  Public libsoccer API
//

#ifndef SoccerPublic_hpp
#define SoccerPublic_hpp

#include <cstddef>
#include <cstdint>

#define SOCCER_BLOCK_SIZE 1048576

class Soccer {
public:
    static bool AttemptSeed_Encrypt(std::uint8_t *pPassword,
                                    std::size_t pPasswordByteLength,
                                    std::uint64_t pNonce,
                                    std::uint32_t *pAckWord);
    
    static bool AttemptSeed_Decrypt(std::uint8_t *pPassword,
                                    std::size_t pPasswordByteLength,
                                    std::uint64_t pNonce,
                                    std::uint32_t pAckWord);
    
    static bool EncryptBlock(std::uint8_t *pSource,
                             std::uint8_t *pDestination);
    
    static bool DecryptBlock(std::uint8_t *pSource,
                             std::uint8_t *pDestination);
};

#endif /* SoccerPublic_hpp */
