//
//  AppDelegate.m
//  Cover Lettur
//
//  Created by icarus black on 6/26/26.
//

#import "AppDelegate.h"

#include "FileIO.hpp"
#include "Soccer2.hpp"
#include "Composer/LaneCombinations.hpp"
#include "Composer/SoccerFoldingTool.hpp"
#include "Composer/SoccerTypes.hpp"

#include <cstddef>
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <limits>
#include <string>
#include <vector>

namespace {

using LaneCountOptions = std::vector<std::uint8_t>;
using LaneStageOptions = std::vector<LaneCountOptions>;

struct LaneGeneratorSpecification {
    const char *mCombinationTypeName;
    const char *mStaticMemberName;
    const char *mStaticCountName;
    std::size_t mMinimumQuarterLaneCount;
    std::size_t mMaximumQuarterLaneCount;
    std::size_t mMinimumCount3;
    std::size_t mMaximumCount3;
    std::size_t mMinimumCount4;
    std::size_t mMaximumCount4;
    LaneStageOptions mL3;
    LaneStageOptions mF3;
    LaneStageOptions mL2;
    LaneStageOptions mL1;
};

struct GeneratedLaneCombination {
    std::vector<std::uint8_t> mL3;
    std::vector<std::uint8_t> mF3;
    std::vector<std::uint8_t> mL2;
    std::vector<std::uint8_t> mL1;
};

enum class LaneGeneratorStage : std::uint8_t {
    kL3,
    kF3,
    kL2,
    kL1,
};

struct LaneGeneratorSlot {
    LaneGeneratorStage mStage;
    std::size_t mStageIndex;
    std::size_t mQuarterLaneMultiplier;
    const LaneCountOptions *mOptions;
};

static bool MakeLaneGeneratorSpecification(EncryptionStrength pStrength,
                                           LaneGeneratorSpecification &pSpecification) {
    switch (pStrength) {
        case EncryptionStrength::kWeak:
            pSpecification = LaneGeneratorSpecification{
                "WeakLaneCombination",
                "mWeak",
                "mWeakCount",
                13U,
                16U,
                0U,
                1U,
                0U,
                1U,
                // L3: Simple
                {{1U, 2U}},
                // F3: Simple
                {{1U, 2U}},
                // L2: Any
                {{1U, 2U, 3U, 4U}},
                // L1: Any
                {{1U, 2U, 3U, 4U}},
            };
            return true;

        case EncryptionStrength::kNormal:
            pSpecification = LaneGeneratorSpecification{
                "NormalLaneCombination",
                "mNormal",
                "mNormalCount",
                29U,
                32U,
                0U,
                1U,
                0U,
                1U,
                // L3: Complex
                {{1U, 2U, 3U, 4U}},
                // F3: Simple, Any
                {{1U, 2U}, {1U, 2U, 3U, 4U}},
                // L2: Simple, Simple
                {{1U, 2U}, {1U, 2U}},
                // L1: Any, Any
                {{1U, 2U, 3U, 4U}, {1U, 2U, 3U, 4U}},
            };
            return true;

        case EncryptionStrength::kStrong:
            pSpecification = LaneGeneratorSpecification{
                "StrongLaneCombination",
                "mStrong",
                "mStrongCount",
                61U,
                64U,
                1U,
                1U,
                1U,
                1U,
                // L3: Simple, Any, Any, Complex
                {
                    {1U, 2U},
                    {1U, 2U, 3U, 4U},
                    {1U, 2U, 3U, 4U},
                    {1U, 2U, 3U, 4U},
                },
                // F3: Simple, Any, Any, Complex
                {
                    {1U, 2U},
                    {1U, 2U, 3U, 4U},
                    {1U, 2U, 3U, 4U},
                    {1U, 2U, 3U, 4U},
                },
                // L2: Simple, Complex, Simple
                {
                    {1U, 2U},
                    {1U, 2U, 3U, 4U},
                    {1U, 2U},
                },
                // L1: Simple, Complex, Any
                {
                    {1U, 2U},
                    {1U, 2U, 3U, 4U},
                    {1U, 2U, 3U, 4U},
                },
            };
            return true;

        case EncryptionStrength::kTest:
            return false;
    }

    return false;
}

static void AppendLaneGeneratorSlots(std::vector<LaneGeneratorSlot> &pSlots,
                                     LaneGeneratorStage pStage,
                                     std::size_t pQuarterLaneMultiplier,
                                     const LaneStageOptions &pStageOptions) {
    for (std::size_t aIndex = 0U; aIndex < pStageOptions.size(); ++aIndex) {
        pSlots.push_back(LaneGeneratorSlot{
            pStage,
            aIndex,
            pQuarterLaneMultiplier,
            &pStageOptions[aIndex],
        });
    }
}

static void SetGeneratedLaneCount(GeneratedLaneCombination &pCombination,
                                  const LaneGeneratorSlot &pSlot,
                                  std::uint8_t pLaneCount) {
    switch (pSlot.mStage) {
        case LaneGeneratorStage::kL3:
            pCombination.mL3[pSlot.mStageIndex] = pLaneCount;
            break;
        case LaneGeneratorStage::kF3:
            pCombination.mF3[pSlot.mStageIndex] = pLaneCount;
            break;
        case LaneGeneratorStage::kL2:
            pCombination.mL2[pSlot.mStageIndex] = pLaneCount;
            break;
        case LaneGeneratorStage::kL1:
            pCombination.mL1[pSlot.mStageIndex] = pLaneCount;
            break;
    }
}

static bool CanReachLaneTarget(const LaneGeneratorSpecification &pSpecification,
                               const std::vector<LaneGeneratorSlot> &pSlots,
                               std::size_t pSlotIndex,
                               std::size_t pConsumedQuarterLaneCount) {
    std::size_t aMinimumRemaining = 0U;
    std::size_t aMaximumRemaining = 0U;

    for (std::size_t aIndex = pSlotIndex; aIndex < pSlots.size(); ++aIndex) {
        const LaneGeneratorSlot &aSlot = pSlots[aIndex];
        if (aSlot.mOptions->empty()) {
            return false;
        }

        const auto aBounds = std::minmax_element(aSlot.mOptions->begin(),
                                                 aSlot.mOptions->end());
        aMinimumRemaining +=
            static_cast<std::size_t>(*aBounds.first) * aSlot.mQuarterLaneMultiplier;
        aMaximumRemaining +=
            static_cast<std::size_t>(*aBounds.second) * aSlot.mQuarterLaneMultiplier;
    }

    return (pConsumedQuarterLaneCount + aMinimumRemaining <=
            pSpecification.mMaximumQuarterLaneCount) &&
           (pConsumedQuarterLaneCount + aMaximumRemaining >=
            pSpecification.mMinimumQuarterLaneCount);
}

static void PrintLaneCountList(const std::vector<std::uint8_t> &pCounts) {
    std::printf("{");
    for (std::size_t aIndex = 0U; aIndex < pCounts.size(); ++aIndex) {
        std::printf("%uU%s",
                    static_cast<unsigned int>(pCounts[aIndex]),
                    (aIndex + 1U < pCounts.size()) ? ", " : "");
    }
    std::printf("}");
}

static void PrintGeneratedLaneCombination(const GeneratedLaneCombination &pCombination) {
    std::printf("    {");
    PrintLaneCountList(pCombination.mL3);
    std::printf(", ");
    PrintLaneCountList(pCombination.mF3);
    std::printf(", ");
    PrintLaneCountList(pCombination.mL2);
    std::printf(", ");
    PrintLaneCountList(pCombination.mL1);
    std::printf("},\n");
}

static void GenerateLaneCombinations(const LaneGeneratorSpecification &pSpecification,
                                     const std::vector<LaneGeneratorSlot> &pSlots,
                                     std::size_t pSlotIndex,
                                     std::size_t pConsumedQuarterLaneCount,
                                     std::size_t pCount3,
                                     std::size_t pCount4,
                                     GeneratedLaneCombination &pCombination,
                                     std::size_t &pCombinationCount) {
    if (!CanReachLaneTarget(pSpecification,
                            pSlots,
                            pSlotIndex,
                            pConsumedQuarterLaneCount)) {
        return;
    }

    if (pSlotIndex == pSlots.size()) {
        if ((pCount3 < pSpecification.mMinimumCount3) ||
            (pCount4 < pSpecification.mMinimumCount4)) {
            return;
        }

        PrintGeneratedLaneCombination(pCombination);
        pCombinationCount += 1U;
        return;
    }

    const LaneGeneratorSlot &aSlot = pSlots[pSlotIndex];
    for (const std::uint8_t aLaneCount : *aSlot.mOptions) {
        const std::size_t aCount3 = pCount3 + ((aLaneCount == 3U) ? 1U : 0U);
        const std::size_t aCount4 = pCount4 + ((aLaneCount == 4U) ? 1U : 0U);

        if ((aCount3 > pSpecification.mMaximumCount3) ||
            (aCount4 > pSpecification.mMaximumCount4)) {
            continue;
        }

        const std::size_t aConsumedQuarterLaneCount =
            pConsumedQuarterLaneCount +
            (static_cast<std::size_t>(aLaneCount) * aSlot.mQuarterLaneMultiplier);
        if (aConsumedQuarterLaneCount > pSpecification.mMaximumQuarterLaneCount) {
            continue;
        }

        SetGeneratedLaneCount(pCombination, aSlot, aLaneCount);
        GenerateLaneCombinations(pSpecification,
                                 pSlots,
                                 pSlotIndex + 1U,
                                 aConsumedQuarterLaneCount,
                                 aCount3,
                                 aCount4,
                                 pCombination,
                                 pCombinationCount);
    }
}

static void PrintLaneCombinationsAsCode(EncryptionStrength pStrength) {
    LaneGeneratorSpecification aSpecification{};
    if (!MakeLaneGeneratorSpecification(pStrength, aSpecification)) {
        std::printf("Lane generator does not support this encryption strength.\n");
        return;
    }

    GeneratedLaneCombination aCombination{
        std::vector<std::uint8_t>(aSpecification.mL3.size()),
        std::vector<std::uint8_t>(aSpecification.mF3.size()),
        std::vector<std::uint8_t>(aSpecification.mL2.size()),
        std::vector<std::uint8_t>(aSpecification.mL1.size()),
    };

    // Pack in decreasing piece size. The planner can withdraw in reverse without wrapping.
    std::vector<LaneGeneratorSlot> aSlots;
    AppendLaneGeneratorSlots(aSlots, LaneGeneratorStage::kL3, 4U, aSpecification.mL3);
    AppendLaneGeneratorSlots(aSlots, LaneGeneratorStage::kF3, 4U, aSpecification.mF3);
    AppendLaneGeneratorSlots(aSlots, LaneGeneratorStage::kL2, 2U, aSpecification.mL2);
    AppendLaneGeneratorSlots(aSlots, LaneGeneratorStage::kL1, 1U, aSpecification.mL1);

    std::printf("\nconst %s LaneCombinations::%s[] = {\n",
                aSpecification.mCombinationTypeName,
                aSpecification.mStaticMemberName);

    std::size_t aCombinationCount = 0U;
    GenerateLaneCombinations(aSpecification,
                             aSlots,
                             0U,
                             0U,
                             0U,
                             0U,
                             aCombination,
                             aCombinationCount);

    std::printf("};\n\n");
    std::printf("const std::size_t LaneCombinations::%s =\n",
                aSpecification.mStaticCountName);
    std::printf("    sizeof(LaneCombinations::%s) / sizeof(LaneCombinations::%s[0]);\n",
                aSpecification.mStaticMemberName,
                aSpecification.mStaticMemberName);
    std::printf("// Combination count: %zu\n\n", aCombinationCount);
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
    
    /*
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
    */
    
    return true;
}

} // namespace

@interface AppDelegate ()

@property (strong) IBOutlet NSWindow *window;
@end

@implementation AppDelegate

void Make10_000Challnge() {

    /*
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
    */
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    constexpr std::uint64_t aRunSeed = 0xD1B54F32DC92ED03ULL;
    std::size_t aRandomTrialCount = 250U;

    while (true) {
        std::printf("SoccerFoldingTool: starting %zu trials per roll.\n",
                    aRandomTrialCount);
        if (!SoccerFoldingTool::Run(aRandomTrialCount, aRunSeed)) {
            std::printf("SoccerFoldingTool failed at %zu trials per roll.\n",
                        aRandomTrialCount);
            return;
        }

        if (aRandomTrialCount >
            (std::numeric_limits<std::size_t>::max() / 2U)) {
            std::printf("SoccerFoldingTool: trial count cannot be doubled again.\n");
            return;
        }
        aRandomTrialCount *= 2U;
    }
}

@end
