#ifndef Soccer2Public_hpp
#define Soccer2Public_hpp

#include <cstddef>
#include <cstdint>

enum class EncryptionStrength : std::uint8_t {
    kTest = 3,
    kWeak = 0,
    kNormal = 1,
    kStrong = 2,
};

#define SOCCER_BLOCK_SIZE 1048576

class Soccer2 {
public:
    static bool AttemptSeed_Encrypt(EncryptionStrength pStrength,
                                    std::uint8_t *pPassword,
                                    std::size_t pPasswordByteLength,
                                    std::uint64_t pNonce,
                                    std::uint32_t *pAckWord);

    static bool AttemptSeed_Decrypt(EncryptionStrength pStrength,
                                    std::uint8_t *pPassword,
                                    std::size_t pPasswordByteLength,
                                    std::uint64_t pNonce,
                                    std::uint32_t pAckWord);

    static bool EncryptBlock(std::uint8_t *pSource,
                             std::uint8_t *pDestination);

    static bool DecryptBlock(std::uint8_t *pSource,
                             std::uint8_t *pDestination);

    static void Zero();
};

#endif /* Soccer2Public_hpp */
