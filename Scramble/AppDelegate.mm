//
//  AppDelegate.mm
//  Scramble
//
//  Created by icarus black on 6/26/26.
//

#import "AppDelegate.h"

#include "Soccer2.hpp"

#include <chrono>
#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <string>
#include <vector>

namespace {

constexpr std::size_t kMediumLaneCount = 8U;
constexpr std::size_t kCiphertextPreviewByteCount = 128U;
constexpr std::size_t kCiphertextPreviewLineByteCount = 32U;

bool IsRunningUnderXCTest() {
    return (std::getenv("XCTestConfigurationFilePath") != nullptr) ||
           (std::getenv("XCTestBundlePath") != nullptr);
}

struct SoccerAvalancheScore {
    std::size_t mDifferentBytes = 0U;
    std::size_t mDifferentBits = 0U;
};

SoccerAvalancheScore ScoreBuffers(const std::uint8_t *pBufferA,
                                  const std::uint8_t *pBufferB,
                                  std::size_t pByteCount) {
    SoccerAvalancheScore aScore;

    for (std::size_t aIndex=0U; aIndex<pByteCount; aIndex++) {
        const std::uint8_t aDifference =
            static_cast<std::uint8_t>(pBufferA[aIndex] ^ pBufferB[aIndex]);
        if (aDifference != 0U) {
            aScore.mDifferentBytes++;
            aScore.mDifferentBits += static_cast<std::size_t>(
                __builtin_popcount(static_cast<unsigned int>(aDifference)));
        }
    }

    return aScore;
}

double Percent(std::size_t pCount, std::size_t pTotal) {
    if (pTotal == 0U) {
        return 0.0;
    }

    return (static_cast<double>(pCount) * 100.0) /
           static_cast<double>(pTotal);
}

void PrintCiphertextPreview(const std::uint8_t *pCiphertext) {
    std::printf("\nEncrypted first %zu bytes:\n", kCiphertextPreviewByteCount);

    for (std::size_t aIndex=0U; aIndex<kCiphertextPreviewByteCount; aIndex++) {
        std::printf("%02X",
                    static_cast<unsigned int>(pCiphertext[aIndex]));

        const bool aLineFinished =
            ((aIndex + 1U) % kCiphertextPreviewLineByteCount) == 0U;
        std::printf("%s", aLineFinished ? "\n" : " ");
    }
}

void PrintLaneAvalancheGrid(
    const std::vector<std::vector<std::uint8_t>> &pLanes) {
    std::printf("\nMedium material-lane avalanche (different bits)\n");
    std::printf("%8s", "");
    for (std::size_t aLaneIndex=0U; aLaneIndex<kMediumLaneCount; aLaneIndex++) {
        std::printf("%11s%zu", "Lane ", aLaneIndex);
    }
    std::printf("\n");

    const std::size_t aTotalBitCount = SOCCER_BLOCK_SIZE * 8U;
    for (std::size_t aRowIndex=0U; aRowIndex<kMediumLaneCount; aRowIndex++) {
        std::printf("Lane %-3zu", aRowIndex);

        for (std::size_t aColumnIndex=0U;
             aColumnIndex<kMediumLaneCount;
             aColumnIndex++) {
            const SoccerAvalancheScore aScore =
                ScoreBuffers(pLanes[aRowIndex].data(),
                             pLanes[aColumnIndex].data(),
                             SOCCER_BLOCK_SIZE);
            std::printf("%11.4f%%",
                        Percent(aScore.mDifferentBits, aTotalBitCount));
        }
        std::printf("\n");
    }
}

void PrintStreamAvalanche(const std::uint8_t *pCiphertextA,
                          const std::uint8_t *pCiphertextB) {
    const SoccerAvalancheScore aScore =
        ScoreBuffers(pCiphertextA, pCiphertextB, SOCCER_BLOCK_SIZE);
    const std::size_t aTotalBitCount = SOCCER_BLOCK_SIZE * 8U;

    std::printf("\nPassword-change ciphertext avalanche\n");
    std::printf("Different bytes: %zu / %zu (%.6f%%)\n",
                aScore.mDifferentBytes,
                static_cast<std::size_t>(SOCCER_BLOCK_SIZE),
                Percent(aScore.mDifferentBytes, SOCCER_BLOCK_SIZE));
    std::printf("Different bits:  %zu / %zu (%.6f%%)\n",
                aScore.mDifferentBits,
                aTotalBitCount,
                Percent(aScore.mDifferentBits, aTotalBitCount));
}

bool RunReadmeSoccerExample() {
    constexpr std::uint64_t aNonce = 0xF00DFACECAFEBEEFULL;
    const std::string aMessage = "Hello, Soccer!!";
    const std::string aPasswordA = "readme-password-A";
    const std::string aPasswordB = "readme-password-B";

    std::vector<std::uint8_t> aPasswordBytesA(aPasswordA.begin(), aPasswordA.end());
    std::vector<std::uint8_t> aPasswordBytesB(aPasswordB.begin(), aPasswordB.end());
    std::vector<std::uint8_t> aPlaintext(SOCCER_BLOCK_SIZE, 0U);
    std::vector<std::uint8_t> aCiphertextA(SOCCER_BLOCK_SIZE, 0U);
    std::vector<std::uint8_t> aCiphertextB(SOCCER_BLOCK_SIZE, 0U);
    std::vector<std::uint8_t> aDecrypted(SOCCER_BLOCK_SIZE, 0U);

    std::memcpy(aPlaintext.data(), aMessage.data(), aMessage.size());

    std::printf("\nSoccer2 medium-encryption example\n");
    std::printf("Plaintext: \"%s\"\n", aMessage.c_str());
    std::printf("Password A: \"%s\"\n", aPasswordA.c_str());

    Soccer2::Zero();

    std::uint32_t aAckWordA = 0U;
    const auto aEncryptionStart = std::chrono::steady_clock::now();
    if (!Soccer2::AttemptSeed_Encrypt(EncryptionStrength::kNormal,
                                      aPasswordBytesA.data(),
                                      aPasswordBytesA.size(),
                                      aNonce,
                                      &aAckWordA)) {
        std::printf("Soccer2 medium encryption seed failed.\n");
        return false;
    }
    if (!Soccer2::EncryptBlock(aPlaintext.data(), aCiphertextA.data())) {
        std::printf("Soccer2 medium encryption failed.\n");
        return false;
    }
    const auto aEncryptionEnd = std::chrono::steady_clock::now();

    std::vector<std::vector<std::uint8_t>> aMaterialLanes(
        kMediumLaneCount,
        std::vector<std::uint8_t>(SOCCER_BLOCK_SIZE));
    for (std::size_t aLaneIndex=0U; aLaneIndex<kMediumLaneCount; aLaneIndex++) {
        if (Soccer2::mMaterials[aLaneIndex] == nullptr) {
            std::printf("Soccer2 material lane %zu was null.\n", aLaneIndex);
            return false;
        }
        std::memcpy(aMaterialLanes[aLaneIndex].data(),
                    Soccer2::mMaterials[aLaneIndex],
                    SOCCER_BLOCK_SIZE);
    }

    const auto aDecryptionStart = std::chrono::steady_clock::now();
    if (!Soccer2::AttemptSeed_Decrypt(EncryptionStrength::kNormal,
                                      aPasswordBytesA.data(),
                                      aPasswordBytesA.size(),
                                      aNonce,
                                      aAckWordA)) {
        std::printf("Soccer2 medium decryption seed failed.\n");
        return false;
    }
    if (!Soccer2::DecryptBlock(aCiphertextA.data(), aDecrypted.data())) {
        std::printf("Soccer2 medium decryption failed.\n");
        return false;
    }
    const auto aDecryptionEnd = std::chrono::steady_clock::now();

    if (std::memcmp(aPlaintext.data(), aDecrypted.data(), SOCCER_BLOCK_SIZE) != 0) {
        std::printf("Soccer2 medium round trip failed.\n");
        return false;
    }

    PrintCiphertextPreview(aCiphertextA.data());
    PrintLaneAvalancheGrid(aMaterialLanes);

    const std::string aRecoveredMessage(
        reinterpret_cast<const char *>(aDecrypted.data()),
        aMessage.size());
    std::printf("\nFinal decrypted message: \"%s\"\n",
                aRecoveredMessage.c_str());

    const double aEncryptionMilliseconds =
        std::chrono::duration<double, std::milli>(
            aEncryptionEnd - aEncryptionStart).count();
    const double aDecryptionMilliseconds =
        std::chrono::duration<double, std::milli>(
            aDecryptionEnd - aDecryptionStart).count();
    std::printf("Encryption time: %.3f ms\n", aEncryptionMilliseconds);
    std::printf("Decryption time: %.3f ms\n", aDecryptionMilliseconds);
    std::printf("Round-trip crypto time: %.3f ms\n",
                aEncryptionMilliseconds + aDecryptionMilliseconds);

    std::printf("\nPassword B: \"%s\" (one character changed)\n",
                aPasswordB.c_str());

    std::uint32_t aAckWordB = 0U;
    if (!Soccer2::AttemptSeed_Encrypt(EncryptionStrength::kNormal,
                                      aPasswordBytesB.data(),
                                      aPasswordBytesB.size(),
                                      aNonce,
                                      &aAckWordB)) {
        std::printf("Soccer2 second medium encryption seed failed.\n");
        return false;
    }
    if (!Soccer2::EncryptBlock(aPlaintext.data(), aCiphertextB.data())) {
        std::printf("Soccer2 second medium encryption failed.\n");
        return false;
    }

    PrintStreamAvalanche(aCiphertextA.data(), aCiphertextB.data());
    return true;
}

} // namespace

@interface AppDelegate ()

@property (strong) IBOutlet NSWindow *window;

@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    (void)aNotification;
    
    if (IsRunningUnderXCTest()) {
        std::printf("Skipping App Delegate Test Code, On Test Target\n");
        return;
    }
    
    if (!RunReadmeSoccerExample()) {
        std::printf("Soccer2 README example failed.\n");
    }
    
}

@end
