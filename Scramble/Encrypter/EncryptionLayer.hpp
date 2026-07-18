#ifndef JELLY_CORE_ENCRYPTION_LAYER_HPP_
#define JELLY_CORE_ENCRYPTION_LAYER_HPP_

#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>

#include "Crypt.hpp"

class EncryptionLayer final : public Crypt {
 public:
  EncryptionLayer() = default;

  using Crypt::SealData;
  using Crypt::UnsealData;

  void AddCipher(std::unique_ptr<Crypt> pCipher);
  void ClearCiphers();
  std::size_t CipherCount() const;

  bool SealData(const std::uint8_t* pSource,
                std::uint8_t* pScratch,
                std::uint8_t* pDestination,
                std::size_t pLength,
                CipherErrorCode *pErrorCode) const override;

  bool UnsealData(const std::uint8_t* pSource,
                  std::uint8_t* pScratch,
                  std::uint8_t* pDestination,
                  std::size_t pLength,
                  CipherErrorCode *pErrorCode) const override;

 private:
    
  std::vector<std::unique_ptr<Crypt>> mCiphers;
};

#endif  // JELLY_CORE_ENCRYPTION_LAYER_HPP_
