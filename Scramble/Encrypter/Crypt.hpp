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

/*

 For ciphers that migrate to this project:
 1.) changing the types from "unsigned char *" to "std::uint8_t *"
 2.) use my spacing style for pointers, like this: "std::uint8_t *pWorker"
 3.) "BLOCK_GRANULARITY" is now "SOCCER_BLOCK_GRANULARITY" defined in "Jelly.hpp"
 4.) make "IGNORE_SIMD" work with "HolyStorms" tests, as well as this project. e.g. at compile time.
 5.) we want flat imports, not '#include "../../../PeanutButter.hpp"', instead '#include "Jelly.hpp"'
 6.) not using "peanutbutter", instead no namespace, except for a local namespace in the cpp file
 7.) no signed types, prefer std::size_t for "integer" type params
 8.) we always have the same block sized of 8, 16, 32, 64. we should make separate optimized files for each.
 9.) we should gravitate away from different lengths, in this project, all lengths are going to be the same.
 //     i.) for example, std::size_t pMaskLength, this parameter is not needed. It's implied that "pMaskLength" is the same as pLength on encrypt.
 //     ii.) this is true for everything, such as passwords, mask buffers, noise buffers,
 
 ---- below this line, codex add your own rules.
 
*/

#endif  // SOCCER_ENCRYPTION_CRYPT_HPP_
