//
//  Soccer2_FlowA_Tests.m
//  ScrambleTests
//
//  Created by nick on 8/5/26.
//

#import <XCTest/XCTest.h>
#include "Soccer2.hpp"
#include "WorkSpaceTools.hpp"
#include "LaneTool.hpp"
#include "Random.hpp"
#include <cstdint>
#include <cstring>
#include <string>
#include <unordered_set>

namespace {
template <typename T> std::string ToString(T **pList, std::size_t pCount) {
    if (pList == nullptr) {
        return "";
    }
    
    std::string aResult;
    aResult.reserve(pCount * sizeof(std::uintptr_t));
    
    for (std::size_t aIndex=0; aIndex<pCount; aIndex++) {
        const std::uintptr_t aPointer = reinterpret_cast<std::uintptr_t>(pList[aIndex]);
        aResult.append(reinterpret_cast<const char *>(&aPointer), sizeof(aPointer));
    }
    
    return aResult;
}

std::string ToString(const std::uint8_t *pList, std::size_t pCount) {
    if (pList == nullptr) {
        return "";
    }
    
    constexpr char cHex[] = "0123456789ABCDEF";
    
    std::string aResult;
    aResult.reserve(pCount * 2U);
    
    for (std::size_t aIndex=0U; aIndex<pCount; aIndex++) {
        const std::uint8_t aByte = pList[aIndex];
        aResult.push_back(cHex[aByte >> 4U]);
        aResult.push_back(cHex[aByte & 0x0FU]);
    }
    
    return aResult;
}
}

@interface Soccer2_FlowA_Tests : XCTestCase

@end

@implementation Soccer2_FlowA_Tests

- (void)test_PreludeA {
    
    std::uint8_t aScratch[S_BLOCK];
    
    for (std::size_t aTrial=0; aTrial<16; aTrial++) {
        
        std::uint64_t aNonce = Random::Get64();
        
        std::uint8_t aPassword[1];
        aPassword[0] = Random::GetByte();
        
        Soccer2::Zero();
        Soccer2::SeedPrelude_Regular_A(aPassword, 1, aNonce);
        
        std::uint8_t aWrapBytes[9];
        aWrapBytes[0] = aPassword[0];
        aWrapBytes[1] = static_cast<std::uint8_t>(aNonce >>  0);
        aWrapBytes[2] = static_cast<std::uint8_t>(aNonce >>  8);
        aWrapBytes[3] = static_cast<std::uint8_t>(aNonce >> 16);
        aWrapBytes[4] = static_cast<std::uint8_t>(aNonce >> 24);
        aWrapBytes[5] = static_cast<std::uint8_t>(aNonce >> 32);
        aWrapBytes[6] = static_cast<std::uint8_t>(aNonce >> 40);
        aWrapBytes[7] = static_cast<std::uint8_t>(aNonce >> 48);
        aWrapBytes[8] = static_cast<std::uint8_t>(aNonce >> 56);
        
        std::size_t aWriteIndex = 0;
        while (aWriteIndex < S_BLOCK) {
            std::size_t aWrapIndex = 0;
            while ((aWrapIndex < 9) && (aWriteIndex < S_BLOCK)) {
                aScratch[aWriteIndex] = aWrapBytes[aWrapIndex];
                aWrapIndex++;
                aWriteIndex++;
            }
        }
        
        if (std::memcmp(Soccer2Internal::SOCCER_SCRATCH_WORKER_A, aScratch, S_BLOCK) != 0) {
            XCTFail("test_PreludeA_weak: failed unroll step.");
            return;
        }
    }
}

- (void)test_PreludeB {
    
    static std::uint8_t aEntropy[S_BLOCK];
    WorkSpaceTools::FillBytes(aEntropy, S_BLOCK);
    
    static std::uint8_t aZero[S_BLOCK];
    memset(aZero, 0, sizeof(aZero));
    
    static std::uint8_t aWriteA[S_BLOCK];
    static std::uint8_t aWriteB[S_BLOCK];
    static std::uint8_t aWriteC[S_BLOCK];
    static std::uint8_t aWriteD[S_BLOCK];
    
    for (std::size_t aTrial=0; aTrial<4; aTrial++) {
        
        memset(aWriteA, 0, sizeof(aZero));
        memset(aWriteB, 0, sizeof(aZero));
        memset(aWriteC, 0, sizeof(aZero));
        memset(aWriteD, 0, sizeof(aZero));
        
        std::uint64_t aNonce = Random::Get64();
        
        Soccer2::Zero();
        memcpy(Soccer2::SOCCER_SCRATCH_WORKER_A, aZero, S_BLOCK);
        Soccer2::SeedPrelude_Regular_B(aNonce);
        memcpy(aWriteA, Soccer2::SOCCER_PRELUDE_RAND, S_BLOCK);
        
        
        if (std::memcmp(Soccer2::SOCCER_PRELUDE_RAND, aZero, S_BLOCK) == 0) {
            XCTFail("test_PreludeB: expected random not to be 0 (a).");
            return;
        }
        
        if (LaneTool::ByteRichness(Soccer2::SOCCER_PRELUDE_RAND, S_BLOCK) < 512) {
            XCTFail("test_PreludeB: expected random to be byte rich (a).");
            return;
        }
        
        Soccer2::Zero();
        
        memcpy(Soccer2::SOCCER_SCRATCH_WORKER_A, aZero, S_BLOCK);
        Soccer2::SeedPrelude_Regular_B(aNonce);
        memcpy(aWriteB, Soccer2::SOCCER_PRELUDE_RAND, S_BLOCK);
        if (std::memcmp(Soccer2::SOCCER_PRELUDE_RAND, aZero, S_BLOCK) == 0) {
            XCTFail("test_PreludeB: expected random not to be 0 (b).");
            return;
        }
        
        if (LaneTool::ByteRichness(Soccer2::SOCCER_PRELUDE_RAND, S_BLOCK) < 512) {
            XCTFail("test_PreludeB: expected random to be byte rich (b).");
            return;
        }
        
        Soccer2::Zero();
        
        memcpy(Soccer2::SOCCER_SCRATCH_WORKER_A, aEntropy, S_BLOCK);
        Soccer2::SeedPrelude_Regular_B(aNonce);
        memcpy(aWriteC, Soccer2::SOCCER_PRELUDE_RAND, S_BLOCK);
        if (std::memcmp(Soccer2::SOCCER_PRELUDE_RAND, aZero, S_BLOCK) == 0) {
            XCTFail("test_PreludeB: expected random not to be 0 (c).");
            return;
        }
        
        if (LaneTool::ByteRichness(Soccer2::SOCCER_PRELUDE_RAND, S_BLOCK) < 512) {
            XCTFail("test_PreludeB: expected random to be byte rich (c).");
            return;
        }
        
        Soccer2::Zero();
        
        memcpy(Soccer2::SOCCER_SCRATCH_WORKER_A, aEntropy, S_BLOCK);
        Soccer2::SeedPrelude_Regular_B(aNonce);
        memcpy(aWriteD, Soccer2::SOCCER_PRELUDE_RAND, S_BLOCK);
        if (std::memcmp(Soccer2::SOCCER_PRELUDE_RAND, aZero, S_BLOCK) == 0) {
            XCTFail("test_PreludeB: expected random not to be 0 (d).");
            return;
        }
        
        if (LaneTool::ByteRichness(Soccer2::SOCCER_PRELUDE_RAND, S_BLOCK) < 512) {
            XCTFail("test_PreludeB: expected random to be byte rich (d).");
            return;
        }
        
        if (std::memcmp(aWriteA, aWriteB, S_BLOCK) != 0) {
            XCTFail("test_PreludeB: expected aWriteA to be same as aWriteB.");
            return;
        }
        
        if (std::memcmp(aWriteC, aWriteD, S_BLOCK) != 0) {
            XCTFail("test_PreludeB: expected aWriteC to be same as aWriteD.");
            return;
        }
        
        if (std::memcmp(aWriteA, aWriteC, S_BLOCK) == 0) {
            XCTFail("test_PreludeB: expected aWriteA to be different than aWriteC.");
            return;
        }
        
        if (std::memcmp(aWriteB, aWriteD, S_BLOCK) == 0) {
            XCTFail("test_PreludeB: expected aWriteB to be different than aWriteD.");
            return;
        }
    }
}

- (void)test_PreludeC {
    
    std::unordered_set<std::string> aHashesMaterials;
    std::unordered_set<std::string> aHashesExpanders;
    std::unordered_set<std::string> aHashesWorkSpaces;
    
    for (std::size_t aTrial=0; aTrial<32; aTrial++) {
        
        Soccer2::Zero();
        Soccer2::InitializeExpanders();
        Soccer2::InitializeWorkSpaces();
        Soccer2::InitializeMaterials();
        
        aHashesMaterials.insert(ToString(Soccer2::mMaterials, 16));
        aHashesExpanders.insert(ToString(Soccer2::mExpanders, SOCCER_EXPANDER_COUNT));
        aHashesWorkSpaces.insert(ToString(Soccer2::mWorkSpaces, 16));
    }
    
    if (aHashesMaterials.size() != 1) {
        XCTFail("test_PreludeC: expected material hashes all to be the same.");
        return;
    }
    if (aHashesExpanders.size() != 1) {
        XCTFail("test_PreludeC: expected expander hashes all to be the same.");
        return;
    }
    if (aHashesWorkSpaces.size() != 1) {
        XCTFail("test_PreludeC: expected work space hashes all to be the same.");
        return;
    }
    
    aHashesMaterials.clear();
    aHashesExpanders.clear();
    aHashesWorkSpaces.clear();
    
    for (std::size_t aTrial=0; aTrial<32; aTrial++) {
        
        Soccer2::Zero();
        Soccer2::InitializeExpanders();
        Soccer2::InitializeWorkSpaces();
        Soccer2::InitializeMaterials();
        
        WorkSpaceTools::FillBytes(Soccer2::SOCCER_PRELUDE_RAND, S_BLOCK);
        Soccer2::SeedPrelude_Regular_C();
        
        aHashesMaterials.insert(ToString(Soccer2::mMaterials, 16));
        aHashesExpanders.insert(ToString(Soccer2::mExpanders, SOCCER_EXPANDER_COUNT));
        aHashesWorkSpaces.insert(ToString(Soccer2::mWorkSpaces, 16));
    }
    
    if (aHashesMaterials.size() < 10) {
        XCTFail("test_PreludeC: expected material hashes mostly to be different.");
        return;
    }
    if (aHashesExpanders.size() < 24) {
        XCTFail("test_PreludeC: expected expander hashes mostly to be different.");
        return;
    }
    if (aHashesWorkSpaces.size() < 10) {
        XCTFail("test_PreludeC: expected work spaces hashes mostly to be different.");
        return;
    }
    
}


@end
