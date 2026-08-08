//
//  ScrambleTests.m
//  ScrambleTests
//
//  Created by icarus black on 7/7/26.
//

#import <XCTest/XCTest.h>

#include "Random.hpp"
#include "Soccer2.hpp"
#include "WorkSpaceTools.hpp"

#include <cstdint>
#include <cstring>
#include <vector>

@interface ScrambleTests : XCTestCase

@end

@implementation ScrambleTests

- (void)test_encryptDecryptWeak {
    static std::uint8_t aOriginal[SOCCER_BLOCK_SIZE];
    static std::uint8_t aEncrypted[SOCCER_BLOCK_SIZE];
    static std::uint8_t aDecrypted[SOCCER_BLOCK_SIZE];
    std::uint8_t aPassword[32U];

    for (std::size_t aIndex=0U; aIndex<SOCCER_BLOCK_SIZE; aIndex++) {
        aOriginal[aIndex] = static_cast<std::uint8_t>((aIndex * 43U) + 7U);
    }
    for (std::size_t aIndex=0U; aIndex<32U; aIndex++) {
        aPassword[aIndex] = static_cast<std::uint8_t>((aIndex * 29U) + 5U);
    }

    constexpr std::uint64_t aNonce = 0x123456789ABCDEF0ULL;
    std::uint32_t aAckWord = 0U;

    if (!Soccer2::AttemptSeed_Encrypt(EncryptionStrength::kWeak,
                                      aPassword,
                                      sizeof(aPassword),
                                      aNonce,
                                      &aAckWord)) {
        XCTFail("test_encryptDecryptWeak: failed seed encrypt.");
        return;
    }

    Soccer2::EncryptBlock(aOriginal, aEncrypted);
    if (std::memcmp(aOriginal, aEncrypted, SOCCER_BLOCK_SIZE) == 0) {
        XCTFail("test_encryptDecryptWeak: encrypted data matched source.");
        return;
    }

    if (!Soccer2::AttemptSeed_Decrypt(EncryptionStrength::kWeak,
                                      aPassword,
                                      sizeof(aPassword),
                                      aNonce,
                                      aAckWord)) {
        XCTFail("test_encryptDecryptWeak: failed seed decrypt.");
        return;
    }

    Soccer2::DecryptBlock(aEncrypted, aDecrypted);
    if (std::memcmp(aOriginal, aDecrypted, SOCCER_BLOCK_SIZE) != 0) {
        XCTFail("test_encryptDecryptWeak: decrypted data did not match source.");
        return;
    }
}

- (void)test_encryptDecryptFiveRunsEachStrength {
    static std::uint8_t aOriginal[SOCCER_BLOCK_SIZE];
    static std::uint8_t aEncrypted[SOCCER_BLOCK_SIZE];
    static std::uint8_t aDecrypted[SOCCER_BLOCK_SIZE];

    const EncryptionStrength aStrengths[3] = {
        EncryptionStrength::kWeak,
        EncryptionStrength::kNormal,
        EncryptionStrength::kStrong
    };
    const char *aStrengthNames[3] = {
        "Weak",
        "Normal",
        "Strong"
    };

    for (std::size_t aStrengthIndex=0U; aStrengthIndex<3U; aStrengthIndex++) {
        for (std::size_t aTrial=0U; aTrial<5U; aTrial++) {
            std::uint8_t aPassword[32U];

            for (std::size_t aIndex=0U; aIndex<SOCCER_BLOCK_SIZE; aIndex++) {
                aOriginal[aIndex] = static_cast<std::uint8_t>(
                    (aIndex * 43U) +
                    (aStrengthIndex * 67U) +
                    (aTrial * 101U) +
                    7U);
            }
            for (std::size_t aIndex=0U; aIndex<32U; aIndex++) {
                aPassword[aIndex] = static_cast<std::uint8_t>(
                    (aIndex * 29U) +
                    (aStrengthIndex * 31U) +
                    (aTrial * 47U) +
                    5U);
            }

            const std::uint64_t aNonce =
                0x123456789ABCDEF0ULL ^
                (static_cast<std::uint64_t>(aStrengthIndex) << 56U) ^
                static_cast<std::uint64_t>(aTrial);
            std::uint32_t aAckWord = 0U;

            if (!Soccer2::AttemptSeed_Encrypt(aStrengths[aStrengthIndex],
                                              aPassword,
                                              sizeof(aPassword),
                                              aNonce,
                                              &aAckWord)) {
                XCTFail("test_encryptDecryptFiveRunsEachStrength: %s trial %zu failed seed encrypt.",
                        aStrengthNames[aStrengthIndex],
                        aTrial);
                return;
            }

            Soccer2::EncryptBlock(aOriginal, aEncrypted);
            if (std::memcmp(aOriginal, aEncrypted, SOCCER_BLOCK_SIZE) == 0) {
                XCTFail("test_encryptDecryptFiveRunsEachStrength: %s trial %zu encrypted data matched source.",
                        aStrengthNames[aStrengthIndex],
                        aTrial);
                return;
            }

            if (!Soccer2::AttemptSeed_Decrypt(aStrengths[aStrengthIndex],
                                              aPassword,
                                              sizeof(aPassword),
                                              aNonce,
                                              aAckWord)) {
                XCTFail("test_encryptDecryptFiveRunsEachStrength: %s trial %zu failed seed decrypt.",
                        aStrengthNames[aStrengthIndex],
                        aTrial);
                return;
            }

            Soccer2::DecryptBlock(aEncrypted, aDecrypted);
            if (std::memcmp(aOriginal, aDecrypted, SOCCER_BLOCK_SIZE) != 0) {
                XCTFail("test_encryptDecryptFiveRunsEachStrength: %s trial %zu decrypted data did not match source.",
                        aStrengthNames[aStrengthIndex],
                        aTrial);
                return;
            }

            printf("test_encryptDecryptFiveRunsEachStrength: %s trial %zu of 5 passed.\n",
                   aStrengthNames[aStrengthIndex],
                   aTrial + 1U);
            fflush(stdout);
        }
    }
}

- (void)test_encryptDecrypt11 {
    
    for (int i=0; i<12; i++) {
        
        std::vector<std::uint8_t> aOriginalA(SOCCER_BLOCK_SIZE);
        WorkSpaceTools::FillBytes(aOriginalA.data(), SOCCER_BLOCK_SIZE);
        
        std::vector<std::uint8_t> aOriginalB(SOCCER_BLOCK_SIZE);
        WorkSpaceTools::FillBytes(aOriginalB.data(), SOCCER_BLOCK_SIZE);
        
        std::vector<std::uint8_t> aOriginalC(SOCCER_BLOCK_SIZE);
        WorkSpaceTools::FillBytes(aOriginalC.data(), SOCCER_BLOCK_SIZE);
        
        std::vector<std::uint8_t> aOriginalD(SOCCER_BLOCK_SIZE);
        WorkSpaceTools::FillBytes(aOriginalD.data(), SOCCER_BLOCK_SIZE);
        
        std::vector<std::uint8_t> aOriginalE(SOCCER_BLOCK_SIZE);
        WorkSpaceTools::FillBytes(aOriginalE.data(), SOCCER_BLOCK_SIZE);
        
        std::vector<std::uint8_t> aPassword(256U);
        WorkSpaceTools::FillBytes(aPassword.data(), 256U);
        
        const std::uint64_t aNonce = Random::Get64();
        
        std::vector<std::uint8_t> aEncryptedA(SOCCER_BLOCK_SIZE);
        std::vector<std::uint8_t> aEncryptedB(SOCCER_BLOCK_SIZE);
        std::vector<std::uint8_t> aEncryptedC(SOCCER_BLOCK_SIZE);
        std::vector<std::uint8_t> aEncryptedD(SOCCER_BLOCK_SIZE);
        std::vector<std::uint8_t> aEncryptedE(SOCCER_BLOCK_SIZE);
        
        std::uint32_t aAckWord = 0U;
        
        if (!Soccer2::AttemptSeed_Encrypt(EncryptionStrength::kTest,
                                          aPassword.data(),
                                          aPassword.size(),
                                          aNonce,
                                          &aAckWord)) {
            XCTFail("failed seed encrypt");
            return;
        }
        Soccer2::EncryptBlock(aOriginalA.data(), aEncryptedA.data());
        Soccer2::EncryptBlock(aOriginalB.data(), aEncryptedB.data());
        Soccer2::EncryptBlock(aOriginalC.data(), aEncryptedC.data());
        Soccer2::EncryptBlock(aOriginalD.data(), aEncryptedD.data());
        Soccer2::EncryptBlock(aOriginalE.data(), aEncryptedE.data());
        
        
        
        if (!Soccer2::AttemptSeed_Decrypt(EncryptionStrength::kTest,
                                         aPassword.data(),
                                         aPassword.size(),
                                         aNonce,
                                         aAckWord)) {
            XCTFail("failed seed decrypt");
            return;
        }
        
        std::vector<std::uint8_t> aDecryptedA(SOCCER_BLOCK_SIZE);
        std::vector<std::uint8_t> aDecryptedB(SOCCER_BLOCK_SIZE);
        std::vector<std::uint8_t> aDecryptedC(SOCCER_BLOCK_SIZE);
        std::vector<std::uint8_t> aDecryptedD(SOCCER_BLOCK_SIZE);
        std::vector<std::uint8_t> aDecryptedE(SOCCER_BLOCK_SIZE);
        
        Soccer2::DecryptBlock(aEncryptedA.data(), aDecryptedA.data());
        Soccer2::DecryptBlock(aEncryptedB.data(), aDecryptedB.data());
        Soccer2::DecryptBlock(aEncryptedC.data(), aDecryptedC.data());
        Soccer2::DecryptBlock(aEncryptedD.data(), aDecryptedD.data());
        Soccer2::DecryptBlock(aEncryptedE.data(), aDecryptedE.data());
        
        if (std::memcmp(aOriginalA.data(), aDecryptedA.data(), aOriginalA.size()) != 0) {
            XCTFail("failed match a");
            return;
        }
        
        if (std::memcmp(aOriginalB.data(), aDecryptedB.data(), aOriginalB.size()) != 0) {
            XCTFail("failed match b");
            return;
        }
        
        if (std::memcmp(aOriginalC.data(), aDecryptedC.data(), aOriginalC.size()) != 0) {
            XCTFail("failed match c");
            return;
        }
        
        if (std::memcmp(aOriginalD.data(), aDecryptedD.data(), aOriginalD.size()) != 0) {
            XCTFail("failed match d");
            return;
        }
        
        if (std::memcmp(aOriginalE.data(), aDecryptedE.data(), aOriginalE.size()) != 0) {
            XCTFail("failed match e");
            return;
        }
        
        printf("Success! [%d] worked fine, no issue!\n", i);
        
    }
}

@end
