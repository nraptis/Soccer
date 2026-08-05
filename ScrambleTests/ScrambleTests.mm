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

- (void)test_encryptDecrypt11 {
    
    for (int i=0; i<256; i++) {
        
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
