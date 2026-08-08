# Soccer

Soccer2 is a 21st generation password expander for offline file encryption,
developed by a cryptography-focused engineer with 17+ years of experience and
about 41 months of concentrated work on this design.

![alt text](https://raw.githubusercontent.com/nraptis/Soccer/refs/heads/main/image.png)

## Encrypt and decrypt one block

This example encrypts the string `Hello, Soccer!` inside one zero-padded L3
block, prints the first 64 encrypted bytes, then decrypts the block and prints
the recovered string.

```cpp
#include "Soccer2.hpp"

#include <cstddef>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <string>
#include <vector>

int main() {
    const std::uint64_t aNonce = 0xF00DFACECAFEBEEFULL;
    const std::string aPassword = "readme-password";

    std::vector<std::uint8_t> aPasswordBytes(aPassword.begin(), aPassword.end());
    std::vector<std::uint8_t> aOriginal(SOCCER_BLOCK_SIZE, 0U);

    const std::string aMessage = "Hello, Soccer!";
    std::memcpy(aOriginal.data(), aMessage.data(), aMessage.size());

    // Encrypt generates the ack word. You need this to decrypt.
    std::uint32_t aAckWord = 0U;
    if (!Soccer2::AttemptSeed_Encrypt(EncryptionStrength::kNormal,
                                      aPasswordBytes.data(),
                                      aPasswordBytes.size(),
                                      aNonce,
                                      &aAckWord)) {
        std::printf("Failed to seed encryption\n");
        
        // Factory reset when finished with your task.
        Soccer2::Zero();
        
        return 1;
    }

    // Encrypt in 1 MiB blocks.
    std::vector<std::uint8_t> aEncrypted(SOCCER_BLOCK_SIZE, 0U);
    Soccer2::EncryptBlock(aOriginal.data(), aEncrypted.data());
    
    // Factory reset when finished with your task.
    Soccer2::Zero();

    std::printf("Encrypted first 64 bytes:\n");
    for (std::size_t aIndex=0U; aIndex<64U; aIndex++) {
        std::printf("%02X%s",
                    static_cast<unsigned int>(aEncrypted[aIndex]),
                    ((aIndex + 1U) % 16U == 0U) ? "\n" : " ");
    }

    std::vector<std::uint8_t> aUnencrypted(SOCCER_BLOCK_SIZE, 0U);
    if (!Soccer2::AttemptSeed_Decrypt(EncryptionStrength::kNormal,
                                      aPasswordBytes.data(),
                                      aPasswordBytes.size(),
                                      aNonce,
                                      aAckWord)) {
        std::printf("Failed to seed decryption\n");
                                            
        // Factory reset when finished with your task.
        Soccer2::Zero();
        
        return 1;
    }

    Soccer2::DecryptBlock(aEncrypted.data(), aUnencrypted.data());
    if (std::memcmp(aOriginal.data(),
                    aUnencrypted.data(),
                    SOCCER_BLOCK_SIZE) != 0) {
        std::printf("Failed to decrypt block\n");
            
        // Factory reset when finished with your task.
        Soccer2::Zero();
        
        return 1;
    }
    
    // Factory reset when finished with your task.
    Soccer2::Zero();

    const std::string aRecovered(
        reinterpret_cast<const char *>(aUnencrypted.data()),
        aMessage.size());
    std::printf("Unencrypted: %s\n", aRecovered.c_str());
    return 0;
}
```

When encrypting, store the nonce and the ack word with the ciphertext.
The same nonce is required for decryption, and the ack word lets Soccer stop
early when the password is wrong. This matters because seeding is deliberately
expensive and can take about 40 seconds.

## Example of Soccer process:

### L3

```text
Apply key 100100111000010100011011001101100001001010011100 at size L3.
Rotate by 628478 every bit matching mask 10100100 wrapping @ block size L3.
Apply key 010101010101000101101111001010110101101001010100 at size L3.
Rotate by 878516 every bit matching mask 00101100 wrapping @ block size L3.
```

### L2

```text
Apply key 111111100011111010111001001001011001000111110100 at size L2.
Rotate by 332374 every bit matching mask 00110011 wrapping @ block size L2.
Apply key 101101001011100100110110011000011001110001001010 at size L2.
Rotate by 489449 every bit matching mask 00111000 wrapping @ block size L2.
```

### L1

```text
Apply key 110011011011010101101101000110000010100001100010 at size L1.
Rotate by 72731 every bit matching mask 00100101 wrapping @ block size L1.
Apply key 101001010110010011001001010001011011001111001110 at size L1.
Rotate by 245208 every bit matching mask 11000001 wrapping @ block size L1.
```

### Final L3

```text
Apply key 000001011001011000101000110110111001000101101011 at size L3 (final).
Rotate by 717233 every bit matching mask 01000110 wrapping @ block size L3 (final).
Apply key 001001110010111011011101111001001010101110011011 at size L3 (final).
Rotate by 1007156 every bit matching mask 01010010 wrapping @ block size L3 (final).
```

## License

Soccer is available under the
[PolyForm Noncommercial License 1.0.0](LICENSE.md). You may use, study, modify,
and redistribute the software for noncommercial purposes. Commercial use,
including selling the software or derivatives, is not permitted under this
license.

## Final 180 Hearts

![Final 180 Hearts](https://raw.githubusercontent.com/nraptis/Soccer/refs/heads/main/180_heart_demo_a.png)

## 14 "best" of 2,667,804

![14 best of 2,667,804](https://raw.githubusercontent.com/nraptis/Soccer/refs/heads/main/180_heart_demo_b.png)

## Misleading Data, we lost days of work due to scoring bias!

![Misleading scoring data](https://raw.githubusercontent.com/nraptis/Soccer/refs/heads/main/misleading_graph.png)
