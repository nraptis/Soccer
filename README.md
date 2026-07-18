# Soccer

Soccer is a 19th generation password expander for offline file encryption,
developed by a cryptography-focused engineer with 16 years of experience and
about 10 months of concentrated work on this design.

The proposal is that Soccer is many thousands of times stronger than AES for
its intended offline password-encryption role, because each password attempt
is deliberately expensive and expands into a large encryption state. That
said, Soccer is not battle tested. It should be studied, attacked, benchmarked,
and reviewed before anyone treats it like established cryptographic
infrastructure.

![alt text](https://raw.githubusercontent.com/nraptis/Scramble/refs/heads/main/image.png)

## `secure.test.encrypted` challenge

The repository includes `secure.test.encrypted` as a public crack challenge. Whoever
cracks it first gets their choice:

**Disclaimer:** The challenge does not go live until 2027. I am giving myself
time to find and fix any remaining bugs or oversights; however, the challenge
is unlikely to change at this point.

- Choice A: $10,000 USD
- Choice B: $5,000 and their name tattooed on my right forearm (up to 15 small
  characters or 5 large characters)

The challenge file uses this nonce:

```cpp
98765432123456789
```

The ack word is provided so password attempts can fail early when the
password is wrong:

```cpp
0xFB47B0AB
```

This challenge expires at the end of the year 2029, in the EST time zone.

This challenge was generated with my network card unplugged. I generated the challenge, moved it onto an external hard-drive, then factory reset my Mac. Both OS instances used FileVault. So, there should be no public timeline of the encryption event.

## Encrypt and decrypt one block

This example encrypts the string `Hello, Soccer!` inside one zero-padded L3
block, prints the first 64 encrypted bytes, then decrypts the block and prints
the recovered string.

### 1.) Seed

```cpp
#include "Soccer.hpp"

#include <cstddef>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <string>
#include <vector>

const std::uint64_t aNonce = 0xF00DFACECAFEBEEFULL;
const std::string aPassword = "readme-password";

std::vector<std::uint8_t> aPasswordBytes(aPassword.begin(), aPassword.end());
std::vector<std::uint8_t> aOriginal(SOCCER_BLOCK_SIZE, 0U);

const std::string aMessage = "Hello, Soccer!";
std::memcpy(aOriginal.data(), aMessage.data(), aMessage.size());

// Encrypt generates the aAckWord. You need this to decrypt.
std::uint32_t aAckWord = 0U;
if (!Soccer::AttemptSeed_Encrypt(aPasswordBytes.data(),
                                 aPasswordBytes.size(),
                                 aNonce,
                                 &aAckWord)) {
    std::printf("Failed to seed encryption\n");
    return false;
}
```

### 2.) Encrypt

```cpp
// Encrypt in 1MB sized blocks.
std::vector<std::uint8_t> aEncrypted(SOCCER_BLOCK_SIZE, 0U);
if (!Soccer::EncryptBlock(aOriginal.data(), aEncrypted.data())) {
    std::printf("Failed to encrypt block\n");
    return false;
}

// Print the encrypted data.
std::printf("Encrypted first 64 bytes:\n");
for (std::size_t aIndex = 0U; aIndex < 64U; aIndex += 1U) {
    std::printf("%02X%s",
                aEncrypted[aIndex],
                ((aIndex + 1U) % 16U == 0U) ? "\n" : " ");
}
```

### 3.) Decrypt

```cpp
std::vector<std::uint8_t> aUnencrypted(SOCCER_BLOCK_SIZE, 0U);
if (!Soccer::AttemptSeed_Decrypt(aPasswordBytes.data(),
                                 aPasswordBytes.size(),
                                 aNonce,
                                 aAckWord)) {
    std::printf("Failed to seed decryption\n");
    return false;
}

if (!Soccer::DecryptBlock(aEncrypted.data(), aUnencrypted.data())) {
    std::printf("Failed to decrypt block\n");
    return false;
}

// Print the decrypted data.
const std::string aRecovered(reinterpret_cast<const char *>(aUnencrypted.data()),
                             aMessage.size());
std::printf("Unencrypted: %s\n", aRecovered.c_str());
```

When encrypting, store the nonce and the ack word with the ciphertext.
The same nonce is required for decryption, and the ack word lets Soccer stop
early when the password is wrong. This matters because seeding is deliberately
expensive and can take about 40 seconds.

## Example of Soccer process:

### L3

```text
Apply key 0b100100111000010100011011001101 at size L3.
Rotate by 396810 with mask 0b10100100 @ block size L3.
Apply key 0b010101010101000101101111001011 at size L3.
Rotate by 785849 with mask 0b00101100 @ block size L3.
```

### L2

```text
Apply key 0b111111100011111010111001000101 at size L2.
Rotate by 96221 with mask 0b00110011 @ block size L2.
Apply key 0b101101001011100100110110011001 at size L2.
Rotate by 395877 with mask 0b00111000 @ block size L2.
```

### L1

```text
Apply key 0b110011011011010101101101000100 at size L1.
Rotate by 74490 with mask 0b00100101 @ block size L1.
Apply key 0b101001010110010011001001010001 at size L1.
Rotate by 198127 with mask 0b11000001 @ block size L1.
```

### Final L3

```text
Apply key 0b000001011001011000101000110011 at size L3 (final).
Rotate by 311376 with mask 0b01000110 @ block size L3 (final).
Apply key 0b001001110010111011011101110100 at size L3 (final).
Rotate by 547399 with mask 0b01010010 @ block size L3 (final).
```

![alt text](https://raw.githubusercontent.com/nraptis/Soccer/refs/heads/main/byte%20diagrams/KDFA.png)

![alt text](https://raw.githubusercontent.com/nraptis/Soccer/refs/heads/main/byte%20diagrams/KDFB.png)

![alt text](https://raw.githubusercontent.com/nraptis/Soccer/refs/heads/main/byte%20diagrams/SEED_1.png)

![alt text](https://raw.githubusercontent.com/nraptis/Soccer/refs/heads/main/byte%20diagrams/SEED_2.png)

![alt text](https://raw.githubusercontent.com/nraptis/Soccer/refs/heads/main/byte%20diagrams/TWIST_1.png)

![alt text](https://raw.githubusercontent.com/nraptis/Soccer/refs/heads/main/byte%20diagrams/TWIST_2.png)

## Static library builds

The portable build is driven by CMake and exports a static library target named
`soccer`. The installed library is still `libsoccer`.

To build the release folders available on the current machine:

```
./build.sh
```

This script writes:

```
release/libsoccer-Mac
release/libsoccer-Linux
release/libsoccer-Win64
```

The Mac build runs on macOS. The Linux and Win64 builds require either those
native platforms or matching cross-toolchains. For custom cross-toolchains, set
`SOCCER_LINUX_TOOLCHAIN_FILE` or `SOCCER_WIN64_TOOLCHAIN_FILE`.

To fail unless all three targets are actually built:

```
./build.sh --require-all
```

Public headers are installed to:

```
include/soccer
```

`Soccer.hpp` is the public header. The expander and encrypter implementation
headers are private build details.

Build on macOS or Linux:

```
cmake -S . -B build/cmake -DCMAKE_BUILD_TYPE=Release
cmake --build build/cmake --config Release
cmake --install build/cmake --prefix dist/libsoccer
```

Build a universal macOS library:

```
cmake -S . -B build/cmake-macos-universal -DCMAKE_BUILD_TYPE=Release -DCMAKE_OSX_ARCHITECTURES="arm64;x86_64"
cmake --build build/cmake-macos-universal --config Release
cmake --install build/cmake-macos-universal --prefix dist/libsoccer
```

Build on Windows with MSVC x64:

```
cmake -S . -B build/cmake-msvc-x64 -G "Visual Studio 17 2022" -A x64
cmake --build build/cmake-msvc-x64 --config Release
cmake --install build/cmake-msvc-x64 --config Release --prefix dist/libsoccer
```

By default the Windows build uses the MSVC DLL runtime (`/MD`). To build a
static runtime (`/MT`) variant:

```
cmake -S . -B build/cmake-msvc-x64-mt -G "Visual Studio 17 2022" -A x64 -DSOCCER_MSVC_STATIC_RUNTIME=ON
cmake --build build/cmake-msvc-x64-mt --config Release
cmake --install build/cmake-msvc-x64-mt --config Release --prefix dist/libsoccer
```

Typical output library names:

```
macOS:   libsoccer.a
Linux:   libsoccer.a
Windows: soccer.lib
```

Build one library per operating system, architecture, and compiler/runtime
combination you want to support. For Windows, start with x64 MSVC unless you
specifically need ARM64 Windows, 32-bit Windows, or MinGW.

## License

Soccer is available under the
[PolyForm Noncommercial License 1.0.0](LICENSE.md). You may use, study, modify,
and redistribute the software for noncommercial purposes. Commercial use,
including selling the software or derivatives, is not permitted under this
license.
