#ifndef SOCCER_ENCRYPTION_CRYPT_HPP_
#define SOCCER_ENCRYPTION_CRYPT_HPP_

#include <cstddef>
#include <cstdint>

#include "CipherErrorCodes.hpp"

class Crypt {
 public:
  virtual ~Crypt() = default;
  virtual bool SealData(const std::uint8_t *pSource,
                        std::uint8_t *pWorker,
                        std::uint8_t *pDestination,
                        std::size_t pLength,
                        CipherErrorCode *pErrorCode) const = 0;
  virtual bool UnsealData(const std::uint8_t *pSource,
                          std::uint8_t *pWorker,
                          std::uint8_t *pDestination,
                          std::size_t pLength,
                          CipherErrorCode *pErrorCode) const = 0;
};

#endif  // SOCCER_ENCRYPTION_CRYPT_HPP_
