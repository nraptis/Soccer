//
//  AppDelegate.m
//  Cover Lettur
//
//  Created by icarus black on 6/26/26.
//

#import "AppDelegate.h"

#include "FileIO.hpp"
#include "Soccer.hpp"

#include <cstddef>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

namespace {

bool IsRunningUnderXCTest() {
    return (std::getenv("XCTestConfigurationFilePath") != nullptr) ||
    (std::getenv("XCTestBundlePath") != nullptr);
}


struct SoccerMaterialScore {
    std::size_t mDifferentBytes = 0U;
    std::size_t mDifferentBits = 0U;
};

static SoccerMaterialScore ScoreSoccerMaterials(const std::vector<std::uint8_t> &pA,
                                                const std::vector<std::uint8_t> &pB) {
    SoccerMaterialScore aScore;
    const std::size_t aByteCount = std::min(pA.size(), pB.size());
    if (aByteCount == 0U) {
        return aScore;
    }
    
    for (std::size_t aIndex = 0U; aIndex < aByteCount; aIndex += 1U) {
        const std::uint8_t aDiff = static_cast<std::uint8_t>(pA[aIndex] ^ pB[aIndex]);
        if (aDiff != 0U) {
            aScore.mDifferentBytes += 1U;
            aScore.mDifferentBits += static_cast<std::size_t>(__builtin_popcount(static_cast<unsigned int>(aDiff)));
        }
    }
    
    return aScore;
}

static void PrintSoccerByteGrid(const char *pTitle,
                                const std::vector<std::vector<std::uint8_t>> &pMaterials,
                                const std::vector<const char *> &pNames) {
    std::printf("\n%s\n", pTitle);
    std::printf("%24s", "");
    for (const char *aName : pNames) {
        std::printf("%18s", aName);
    }
    std::printf("\n");
    
    for (std::size_t aRowIndex = 0U; aRowIndex < pMaterials.size(); aRowIndex += 1U) {
        std::printf("%16s", pNames[aRowIndex]);
        for (std::size_t aColumnIndex = 0U; aColumnIndex < pMaterials.size(); aColumnIndex += 1U) {
            const SoccerMaterialScore aScore = ScoreSoccerMaterials(pMaterials[aRowIndex],
                                                                     pMaterials[aColumnIndex]);
            const std::size_t aByteCount = std::min(pMaterials[aRowIndex].size(),
                                                    pMaterials[aColumnIndex].size());
            const double aRatio = static_cast<double>(aScore.mDifferentBytes) /
                static_cast<double>(aByteCount);
            std::printf("%17.4f%%", aRatio * 100.0);
        }
        std::printf("\n");
    }
}

static void PrintSoccerByteMaterialGridPair(
    const char *pTitle,
    const std::vector<std::vector<std::uint8_t>> &pMaterials,
    const std::vector<const char *> &pNames,
    std::size_t pFirstGroupStart,
    std::size_t pSecondGroupStart) {
    constexpr std::size_t kMaterialGroupSize = 4U;
    std::vector<std::vector<std::uint8_t>> aGridMaterials;
    std::vector<const char *> aGridNames;
    aGridMaterials.reserve(kMaterialGroupSize * 2U);
    aGridNames.reserve(kMaterialGroupSize * 2U);

    for (std::size_t aOffset = 0U; aOffset < kMaterialGroupSize; aOffset += 1U) {
        const std::size_t aIndex = pFirstGroupStart + aOffset;
        aGridMaterials.push_back(pMaterials[aIndex]);
        aGridNames.push_back(pNames[aIndex]);
    }
    for (std::size_t aOffset = 0U; aOffset < kMaterialGroupSize; aOffset += 1U) {
        const std::size_t aIndex = pSecondGroupStart + aOffset;
        aGridMaterials.push_back(pMaterials[aIndex]);
        aGridNames.push_back(pNames[aIndex]);
    }

    PrintSoccerByteGrid(pTitle, aGridMaterials, aGridNames);
}

static void PrintSoccerBitGrid(const char *pTitle,
                               const std::vector<std::vector<std::uint8_t>> &pMaterials,
                               const std::vector<const char *> &pNames) {
    std::printf("\n%s\n", pTitle);
    std::printf("%24s", "");
    for (const char *aName : pNames) {
        std::printf("%18s", aName);
    }
    std::printf("\n");
    
    for (std::size_t aRowIndex = 0U; aRowIndex < pMaterials.size(); aRowIndex += 1U) {
        std::printf("%16s", pNames[aRowIndex]);
        for (std::size_t aColumnIndex = 0U; aColumnIndex < pMaterials.size(); aColumnIndex += 1U) {
            const SoccerMaterialScore aScore = ScoreSoccerMaterials(pMaterials[aRowIndex],
                                                                     pMaterials[aColumnIndex]);
            const std::size_t aByteCount = std::min(pMaterials[aRowIndex].size(),
                                                    pMaterials[aColumnIndex].size());
            const double aRatio = static_cast<double>(aScore.mDifferentBits) /
                static_cast<double>(aByteCount * 8U);
            std::printf("%17.4f%%", aRatio * 100.0);
        }
        std::printf("\n");
    }
}

static void PrintSoccerBitMaterialGridPair(
    const char *pTitle,
    const std::vector<std::vector<std::uint8_t>> &pMaterials,
    const std::vector<const char *> &pNames,
    std::size_t pFirstGroupStart,
    std::size_t pSecondGroupStart) {
    constexpr std::size_t kMaterialGroupSize = 4U;
    std::vector<std::vector<std::uint8_t>> aGridMaterials;
    std::vector<const char *> aGridNames;
    aGridMaterials.reserve(kMaterialGroupSize * 2U);
    aGridNames.reserve(kMaterialGroupSize * 2U);

    for (std::size_t aOffset = 0U; aOffset < kMaterialGroupSize; aOffset += 1U) {
        const std::size_t aIndex = pFirstGroupStart + aOffset;
        aGridMaterials.push_back(pMaterials[aIndex]);
        aGridNames.push_back(pNames[aIndex]);
    }
    for (std::size_t aOffset = 0U; aOffset < kMaterialGroupSize; aOffset += 1U) {
        const std::size_t aIndex = pSecondGroupStart + aOffset;
        aGridMaterials.push_back(pMaterials[aIndex]);
        aGridNames.push_back(pNames[aIndex]);
    }

    PrintSoccerBitGrid(pTitle, aGridMaterials, aGridNames);
}

static void AppendBytes(std::vector<std::uint8_t> &pBytes,
                        const void *pSource,
                        std::size_t pLength) {
    const std::uint8_t *aBegin = static_cast<const std::uint8_t *>(pSource);
    pBytes.insert(pBytes.end(), aBegin, aBegin + pLength);
}

static bool RunReadmeSoccerExample() {
    
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
    
    return true;
}

} // namespace

@interface AppDelegate ()

@property (strong) IBOutlet NSWindow *window;
@end

@implementation AppDelegate

void Make10_000Challnge() {

    std::string aPassword = "????????????????????????????????";

    std::string aFileName = "missing.pdf";
    std::string aFilePath = FileIO::ProjectRoot(aFileName);

    std::vector<std::uint8_t> aFileData;
    if (!FileIO::Load(aFilePath, aFileData)) {
        std::printf("Failed to load challenge file\n");
        return;
    }

    const std::size_t aFileByteCount = aFileData.size();
    const std::size_t aBlockCount = (aFileByteCount + SOCCER_BLOCK_SIZE - 1U) / SOCCER_BLOCK_SIZE;
    const std::size_t aAllocatedByteCount = aBlockCount * SOCCER_BLOCK_SIZE;

    aFileData.resize(aAllocatedByteCount, 0U);
    std::vector<std::uint8_t> aEncrypted(aAllocatedByteCount, 0U);

    std::uint32_t aAckWord = 0U;

    if (!Soccer::AttemptSeed_Encrypt(reinterpret_cast<std::uint8_t *>(aPassword.data()),
                                     aPassword.size(),
                                     98765432123456789ULL,
                                     &aAckWord)) {
        std::printf("Failed to seed challenge encryption\n");
        return;
    }

    std::printf("32-bit acknowledge: 0x%08X\n",
                static_cast<unsigned int>(aAckWord));

    for (std::size_t aBlockIndex=0; aBlockIndex<aBlockCount; aBlockIndex++) {
        const std::size_t aBlockOffset = aBlockIndex * SOCCER_BLOCK_SIZE;
        if (!Soccer::EncryptBlock(&aFileData[aBlockOffset],
                                  &aEncrypted[aBlockOffset])) {
            std::printf("Failed to encrypt challenge block %zu\n", aBlockIndex);
            return;
        }
    }

    std::string aOutputName = "secure.test.encrypted";
    std::string aOutputPath = FileIO::ProjectRoot(aOutputName);
    if (!FileIO::Save(aOutputPath, aEncrypted)) {
        std::printf("Failed to save encrypted challenge file\n");
        return;
    }

    aFileData.clear();
    if (!FileIO::Load(aOutputPath, aFileData)) {
        std::printf("Failed to reload encrypted challenge file\n");
        return;
    }

    if (!Soccer::AttemptSeed_Decrypt(reinterpret_cast<std::uint8_t *>(aPassword.data()),
                                     aPassword.size(),
                                     98765432123456789ULL,
                                     aAckWord)) {
        std::printf("Failed to seed challenge decryption\n");
        return;
    }

    std::vector<std::uint8_t> aDecrypted(aAllocatedByteCount, 0U);
    for (std::size_t aBlockIndex=0; aBlockIndex<aBlockCount; aBlockIndex++) {
        const std::size_t aBlockOffset = aBlockIndex * SOCCER_BLOCK_SIZE;
        if (!Soccer::DecryptBlock(&aFileData[aBlockOffset],
                                  &aDecrypted[aBlockOffset])) {
            std::printf("Failed to decrypt challenge block %zu\n", aBlockIndex);
            return;
        }
    }

    aDecrypted.resize(aFileByteCount);

    std::string aDecryptedName = "decrypted";
    std::string aDecryptedPath = FileIO::ProjectRoot(aDecryptedName);
    if (!FileIO::Save(aDecryptedPath, aDecrypted)) {
        std::printf("Failed to save decrypted challenge file\n");
    }
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    
    if (IsRunningUnderXCTest()) {
        printf("RUNNING TEST ===> IGNORING APP DELEGATE CODE...\n");
        return;
    }
    
    RunReadmeSoccerExample();
    
    std::uint8_t aPassword[] = {'s', 'o', 'c', 'c', 'e', 'r'};
    std::uint8_t *aPasswordData = aPassword;
    int aPasswordLength = static_cast<int>(sizeof(aPassword));
    
    std::uint32_t aAckWord = 0U;
    
    Soccer::AttemptSeed_Encrypt(aPasswordData,
                                aPasswordLength,
                                11746948407655524690U,
                                &aAckWord);
    
    std::printf("\nSoccer seed ack: %08X\n",
                static_cast<unsigned int>(aAckWord));
    
    std::vector<std::vector<std::uint8_t>> aOriginalMaterials(16U);
    const std::uint8_t *aAvalancheReferenceMaterials[16];
    Soccer::InitializeAvalancheReferenceMaterials(aAvalancheReferenceMaterials);
    for (std::size_t aMaterialIndex = 0U; aMaterialIndex < 16U; aMaterialIndex += 1U) {
        const std::uint8_t *aMaterial = aAvalancheReferenceMaterials[aMaterialIndex];
        aOriginalMaterials[aMaterialIndex].assign(aMaterial,
                                                   aMaterial + SOCCER_BLOCK_SIZE);
    }
    
    const std::vector<const char *> aMaterialNames = {
        "mMaterialA",
        "mMaterialB",
        "mMaterialC",
        "mMaterialD",
        "mMaterialE",
        "mMaterialF",
        "mMaterialG",
        "mMaterialH",
        "mMaterialI",
        "mMaterialJ",
        "mMaterialK",
        "mMaterialL",
        "mMaterialM",
        "mMaterialN",
        "mMaterialO",
        "mMaterialP"
    };
    
    PrintSoccerByteMaterialGridPair("Soccer byte material grid: mats A-D, E-H",
                                    aOriginalMaterials, aMaterialNames, 0U, 4U);
    PrintSoccerByteMaterialGridPair("Soccer byte material grid: mats A-D, I-L",
                                    aOriginalMaterials, aMaterialNames, 0U, 8U);
    PrintSoccerByteMaterialGridPair("Soccer byte material grid: mats A-D, M-P",
                                    aOriginalMaterials, aMaterialNames, 0U, 12U);
    PrintSoccerByteMaterialGridPair("Soccer byte material grid: mats E-H, I-L",
                                    aOriginalMaterials, aMaterialNames, 4U, 8U);
    PrintSoccerByteMaterialGridPair("Soccer byte material grid: mats E-H, M-P",
                                    aOriginalMaterials, aMaterialNames, 4U, 12U);
    PrintSoccerByteMaterialGridPair("Soccer byte material grid: mats I-L, M-P",
                                    aOriginalMaterials, aMaterialNames, 8U, 12U);

    PrintSoccerBitMaterialGridPair("Soccer bit material grid: mats A-D, E-H",
                                   aOriginalMaterials, aMaterialNames, 0U, 4U);
    PrintSoccerBitMaterialGridPair("Soccer bit material grid: mats A-D, I-L",
                                   aOriginalMaterials, aMaterialNames, 0U, 8U);
    PrintSoccerBitMaterialGridPair("Soccer bit material grid: mats A-D, M-P",
                                   aOriginalMaterials, aMaterialNames, 0U, 12U);
    PrintSoccerBitMaterialGridPair("Soccer bit material grid: mats E-H, I-L",
                                   aOriginalMaterials, aMaterialNames, 4U, 8U);
    PrintSoccerBitMaterialGridPair("Soccer bit material grid: mats E-H, M-P",
                                   aOriginalMaterials, aMaterialNames, 4U, 12U);
    PrintSoccerBitMaterialGridPair("Soccer bit material grid: mats I-L, M-P",
                                   aOriginalMaterials, aMaterialNames, 8U, 12U);
}

@end
