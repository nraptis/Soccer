#include "Soccer2.hpp"

#define SOCCER_ENCRYPTION_STRENGTH_DEFINED
#define SOCCER2_DISABLE_COMPAT_ALIAS
#include "../Composer/Soccer2.hpp"

bool Soccer2::AttemptSeed_Encrypt(EncryptionStrength pStrength,
                                  std::uint8_t *pPassword,
                                  std::size_t pPasswordByteLength,
                                  std::uint64_t pNonce,
                                  std::uint32_t *pAckWord) {
    return Soccer2Internal::AttemptSeed_Encrypt(pStrength,
                                                pPassword,
                                                pPasswordByteLength,
                                                pNonce,
                                                pAckWord);
}

bool Soccer2::AttemptSeed_Decrypt(EncryptionStrength pStrength,
                                  std::uint8_t *pPassword,
                                  std::size_t pPasswordByteLength,
                                  std::uint64_t pNonce,
                                  std::uint32_t pAckWord) {
    return Soccer2Internal::AttemptSeed_Decrypt(pStrength,
                                                pPassword,
                                                pPasswordByteLength,
                                                pNonce,
                                                pAckWord);
}

bool Soccer2::EncryptBlock(std::uint8_t *pSource,
                           std::uint8_t *pDestination) {
    return Soccer2Internal::EncryptBlock(pSource, pDestination);
}

bool Soccer2::DecryptBlock(std::uint8_t *pSource,
                           std::uint8_t *pDestination) {
    return Soccer2Internal::DecryptBlock(pSource, pDestination);
}

void Soccer2::Zero() {
    Soccer2Internal::Zero();
}
