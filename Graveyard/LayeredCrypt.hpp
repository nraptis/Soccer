#ifndef JELLY_CORE_LAYERED_CRYPT_HPP_
#define JELLY_CORE_LAYERED_CRYPT_HPP_

#include <cstddef>
#include <cstdint>

#include "EncryptionLayer.hpp"

class LayeredCrypt final {
public:
    LayeredCrypt() = default;

    EncryptionLayer& Layer1() { return mLayer1; }
    EncryptionLayer& Layer2() { return mLayer2; }
    EncryptionLayer& Layer3() { return mLayer3; }

    const EncryptionLayer& Layer1() const { return mLayer1; }
    const EncryptionLayer& Layer2() const { return mLayer2; }
    const EncryptionLayer& Layer3() const { return mLayer3; }
    
    bool SealData(const std::uint8_t* pSource,
                  std::uint8_t* pWorkerA,
                  std::uint8_t* pWorkerB,
                  std::uint8_t* pDestination,
                  std::size_t pLength,
                  CipherErrorCode *pErrorCode) const;

    bool UnsealData(const std::uint8_t* pSource,
                    std::uint8_t* pWorkerA,
                    std::uint8_t* pWorkerB,
                    std::uint8_t* pDestination,
                    std::size_t pLength,
                    CipherErrorCode *pErrorCode) const;

private:
    EncryptionLayer mLayer1;
    EncryptionLayer mLayer2;
    EncryptionLayer mLayer3;
};

#endif  // JELLY_CORE_LAYERED_CRYPT_HPP_
