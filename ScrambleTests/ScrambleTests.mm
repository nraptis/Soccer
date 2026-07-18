//
//  ScrambleTests.m
//  ScrambleTests
//
//  Created by icarus black on 7/7/26.
//

#import <XCTest/XCTest.h>

#include "Random.hpp"
#include "Soccer.hpp"

#include <cstdint>
#include <cstring>
#include <vector>

@interface ScrambleTests : XCTestCase

@end

@implementation ScrambleTests

- (void)test_encryptDecrypt {
    std::vector<std::uint8_t> aOriginal(SOCCER_BLOCK_SIZE);
    for (std::uint8_t &aByte : aOriginal) {
        aByte = Random::GetByte();
    }
    
    std::vector<std::uint8_t> aPassword(256U);
    for (std::uint8_t &aByte : aPassword) {
        aByte = Random::GetByte();
    }
    
    const std::uint64_t aNonce = Random::Get64();
    
    std::vector<std::uint8_t> aEncrypted(SOCCER_BLOCK_SIZE);
    for (std::uint8_t &aByte : aEncrypted) {
        aByte = Random::GetByte();
    }
    
    std::uint32_t aAckWord = 0U;
    
    XCTAssertTrue(Soccer::AttemptSeed_Encrypt(aPassword.data(),
                                              aPassword.size(),
                                              aNonce,
                                              &aAckWord));
    
    XCTAssertTrue(Soccer::EncryptBlock(aOriginal.data(), aEncrypted.data()));
    
    XCTAssertTrue(Soccer::AttemptSeed_Decrypt(aPassword.data(),
                                              aPassword.size(),
                                              aNonce,
                                              aAckWord));
    
    std::vector<std::uint8_t> aDecrypted(SOCCER_BLOCK_SIZE);
    XCTAssertTrue(Soccer::DecryptBlock(aEncrypted.data(), aDecrypted.data()));
    XCTAssertEqual(std::memcmp(aOriginal.data(), aDecrypted.data(), aOriginal.size()), 0);
}

- (void)test_encryptDecrypt11 {
    
    for (int i=0; i<100; i++) {
        
        std::vector<std::uint8_t> aOriginalA(SOCCER_BLOCK_SIZE);
        for (std::uint8_t &aByte : aOriginalA) {
            aByte = Random::GetByte();
        }
        
        std::vector<std::uint8_t> aOriginalB(SOCCER_BLOCK_SIZE);
        for (std::uint8_t &aByte : aOriginalB) {
            aByte = Random::GetByte();
        }
        
        std::vector<std::uint8_t> aOriginalC(SOCCER_BLOCK_SIZE);
        for (std::uint8_t &aByte : aOriginalC) {
            aByte = Random::GetByte();
        }
        
        std::vector<std::uint8_t> aOriginalD(SOCCER_BLOCK_SIZE);
        for (std::uint8_t &aByte : aOriginalD) {
            aByte = Random::GetByte();
        }
        
        std::vector<std::uint8_t> aOriginalE(SOCCER_BLOCK_SIZE);
        for (std::uint8_t &aByte : aOriginalE) {
            aByte = Random::GetByte();
        }
        
        std::vector<std::uint8_t> aPassword(256U);
        for (std::uint8_t &aByte : aPassword) {
            aByte = Random::GetByte();
        }
        
        const std::uint64_t aNonce = Random::Get64();
        
        std::vector<std::uint8_t> aEncryptedA(SOCCER_BLOCK_SIZE);
        std::vector<std::uint8_t> aEncryptedB(SOCCER_BLOCK_SIZE);
        std::vector<std::uint8_t> aEncryptedC(SOCCER_BLOCK_SIZE);
        std::vector<std::uint8_t> aEncryptedD(SOCCER_BLOCK_SIZE);
        std::vector<std::uint8_t> aEncryptedE(SOCCER_BLOCK_SIZE);
        
        std::uint32_t aAckWord = 0U;
        
        if (!Soccer::AttemptSeed_Encrypt(aPassword.data(),
                                         aPassword.size(),
                                         aNonce,
                                         &aAckWord)) {
            XCTFail("failed seed encrypt");
            return;
        }
        
        if (!Soccer::EncryptBlock(aOriginalA.data(), aEncryptedA.data())) {
            XCTFail("failed encrypt a");
            return;
        }

        if (!Soccer::EncryptBlock(aOriginalB.data(), aEncryptedB.data())) {
            XCTFail("failed encrypt b");
            return;
        }

        if (!Soccer::EncryptBlock(aOriginalC.data(), aEncryptedC.data())) {
            XCTFail("failed encrypt c");
            return;
        }

        if (!Soccer::EncryptBlock(aOriginalD.data(), aEncryptedD.data())) {
            XCTFail("failed encrypt d");
            return;
        }

        if (!Soccer::EncryptBlock(aOriginalE.data(), aEncryptedE.data())) {
            XCTFail("failed encrypt e");
            return;
        }
        
        if (!Soccer::AttemptSeed_Decrypt(aPassword.data(),
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
        
        if (!Soccer::DecryptBlock(aEncryptedA.data(), aDecryptedA.data())) {
            XCTFail("failed decrypt a");
            return;
        }

        if (!Soccer::DecryptBlock(aEncryptedB.data(), aDecryptedB.data())) {
            XCTFail("failed decrypt b");
            return;
        }

        if (!Soccer::DecryptBlock(aEncryptedC.data(), aDecryptedC.data())) {
            XCTFail("failed decrypt c");
            return;
        }

        if (!Soccer::DecryptBlock(aEncryptedD.data(), aDecryptedD.data())) {
            XCTFail("failed decrypt d");
            return;
        }

        if (!Soccer::DecryptBlock(aEncryptedE.data(), aDecryptedE.data())) {
            XCTFail("failed decrypt e");
            return;
        }
        
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
