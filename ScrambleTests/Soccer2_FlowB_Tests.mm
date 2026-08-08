//
//  Soccer2_FlowB_Tests.m
//  ScrambleTests
//
//  Created by nick on 8/6/26.
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

@interface Soccer2_FlowB_Tests : XCTestCase

@end

@implementation Soccer2_FlowB_Tests

- (void)test_Prologue_A_B_Shuffle_Weak {
    
    std::unordered_set<std::string> aHashesMaterials;
    std::unordered_set<std::string> aHashesExpanders;
    std::unordered_set<std::string> aHashesWorkSpaces;
    
    for (std::size_t aTrial=0; aTrial<16; aTrial++) {
        
        
        std::uint64_t aNonce = Random::Get64();
        
        std::uint8_t aPassword[3];
        for (std::size_t aIndex=0; aIndex<3; aIndex++) {
            aPassword[aIndex] = Random::GetByte();
        }
        
        Soccer2::Zero();
        Soccer2::mStrength = EncryptionStrength::kWeak;
        Soccer2::InitializeExpanders();
        Soccer2::InitializeWorkSpaces();
        Soccer2::InitializeMaterials();
        Soccer2::SeedPrologue_Regular_A(aPassword, 3, aNonce);
        
        if (Soccer2::mClaimedExpanderCount != 4) {
            XCTFail("test_Prologue_A_B_Shuffle_Weak: expecting 4 claimed expanders.");
            return;
        }
        if (Soccer2::mClaimedMaterialCount != 4) {
            XCTFail("test_Prologue_A_B_Shuffle_Weak: expecting 4 claimed materials.");
            return;
        }
        if (Soccer2::mClaimedWorkSpaceCount != 4) {
            XCTFail("test_Prologue_A_B_Shuffle_Weak: expecting 4 claimed work spaces.");
            return;
        }
        
        
        std::unordered_set<TwistExpander *> aClaimedExpanderSet;
        for (std::size_t aExpanderIndex=0; aExpanderIndex<Soccer2::mClaimedExpanderCount; aExpanderIndex++) {
            aClaimedExpanderSet.insert(Soccer2::mClaimedExpanders[aExpanderIndex]);
        }
        
        std::unordered_set<std::uint8_t *> aClaimedMaterialSet;
        const std::size_t aWarmUpStartIndex = (32 - 4) * S_BLOCK;
        for (std::size_t aMaterialIndex=0; aMaterialIndex<Soccer2::mClaimedMaterialCount; aMaterialIndex++) {
            aClaimedMaterialSet.insert(Soccer2::mClaimedMaterials[aMaterialIndex]);
            std::size_t aByteRichness = LaneTool::ByteRichness(&Soccer2::mClaimedMaterials[aMaterialIndex][aWarmUpStartIndex], S_BLOCK);
            if (aByteRichness < 512) {
                XCTFail("test_Prologue_A_B_Shuffle_Weak: expecting claimed material [%zu] early block to be byte rich. (got %zu)", aMaterialIndex, aByteRichness);
                return;
            }
        }
        
        std::unordered_set<TwistWorkSpace *> aClaimedWorkSpaceSet;
        for (std::size_t aWorkSpaceIndex=0; aWorkSpaceIndex<Soccer2::mClaimedWorkSpaceCount; aWorkSpaceIndex++) {
            aClaimedWorkSpaceSet.insert(Soccer2::mClaimedWorkSpaces[aWorkSpaceIndex]);
        }
        
        std::unordered_set<std::uint8_t *> aAllMaterialSet;
        for (std::size_t aOuterMaterialIndex=0; aOuterMaterialIndex<16; aOuterMaterialIndex++) {
            
            aAllMaterialSet.insert(Soccer2::mMaterials[aOuterMaterialIndex]);
            
            if (aClaimedMaterialSet.contains(Soccer2::mMaterials[aOuterMaterialIndex])) {
                for (std::size_t aBlockIndex=0; aBlockIndex<32; aBlockIndex++) {
                    std::size_t aByteRichness = LaneTool::ByteRichness(&Soccer2::mMaterials[aOuterMaterialIndex][S_BLOCK * aBlockIndex], S_BLOCK);
                    
                    if (aBlockIndex == 28) {
                        if (aByteRichness < 512) {
                            XCTFail("test_Prologue_A_B_Shuffle_Weak: expecting claimed material [%zu] block [%zu] to be byte rich. (got %zu)", aOuterMaterialIndex, aBlockIndex, aByteRichness);
                            return;
                        }
                    } else {
                        if (aByteRichness > 64) {
                            XCTFail("test_Prologue_A_B_Shuffle_Weak: expecting claimed material [%zu] block [%zu] to be byte rich. (got %zu)", aOuterMaterialIndex, aBlockIndex, aByteRichness);
                            return;
                        }
                    }
                }
            } else {
                for (std::size_t aBlockIndex=0; aBlockIndex<32; aBlockIndex++) {
                    std::size_t aByteRichness = LaneTool::ByteRichness(&Soccer2::mMaterials[aOuterMaterialIndex][S_BLOCK * aBlockIndex], S_BLOCK);
                    if (aByteRichness > 64) {
                        XCTFail("test_Prologue_A_B_Shuffle_Weak: expecting claimed material [%zu] block [%zu] to be byte rich. (got %zu)", aOuterMaterialIndex, aBlockIndex, aByteRichness);
                        return;
                    }
                }
            }
            
            Soccer2::SeedPrologue_Regular_B();
            
            std::unordered_set<std::string> aShuffleHashesMaterials;
            std::unordered_set<std::string> aShuffleHashesExpanders;
            std::unordered_set<std::string> aShuffleHashesWorkSpaces;
            
            for (std::size_t aShuffleTrialIndex=0; aShuffleTrialIndex<8; aShuffleTrialIndex++) {
                
                std::unordered_set<std::uint8_t *> aCheckedMaterialSet;
                std::unordered_set<TwistExpander *> aCheckedExpanderSet;
                std::unordered_set<TwistWorkSpace *> aCheckedWorkSpaceSet;
                
                aShuffleHashesMaterials.insert(ToString(Soccer2::mMaterials, Soccer2::mClaimedMaterialCount));
                aShuffleHashesExpanders.insert(ToString(Soccer2::mExpanders, Soccer2::mClaimedExpanderCount));
                aShuffleHashesWorkSpaces.insert(ToString(Soccer2::mWorkSpaces, Soccer2::mClaimedWorkSpaceCount));
                
                if (aShuffleTrialIndex == 0) {
                    for (std::size_t aExpanderIndex=0; aExpanderIndex<SOCCER_EXPANDER_COUNT; aExpanderIndex++) {
                        if (aExpanderIndex < Soccer2::mClaimedExpanderCount) {
                            if (!aClaimedExpanderSet.contains(Soccer2::mExpanders[aExpanderIndex])) {
                                XCTFail("test_Prologue_A_B_Shuffle_Weak: expecting claimed expander [%zu], was not claimed. (shuffle #%zu)", aExpanderIndex, aShuffleTrialIndex);
                                return;
                            }
                        }
                        aCheckedExpanderSet.insert(Soccer2::mExpanders[aExpanderIndex]);
                    }
                } else {
                    for (std::size_t aExpanderIndex=0; aExpanderIndex<SOCCER_EXPANDER_COUNT; aExpanderIndex++) {
                        aCheckedExpanderSet.insert(Soccer2::mExpanders[aExpanderIndex]);
                    }
                }
                
                for (std::size_t aMaterialIndex=0; aMaterialIndex<16; aMaterialIndex++) {
                    if (aMaterialIndex < Soccer2::mClaimedMaterialCount) {
                        if (!aClaimedMaterialSet.contains(Soccer2::mMaterials[aMaterialIndex])) {
                            XCTFail("test_Prologue_A_B_Shuffle_Weak: expecting claimed material [%zu], was not claimed. (shuffle #%zu)", aMaterialIndex, aShuffleTrialIndex);
                            return;
                        }
                    }
                    aCheckedMaterialSet.insert(Soccer2::mMaterials[aMaterialIndex]);
                }
                
                for (std::size_t aWorkSpaceIndex=0; aWorkSpaceIndex<16; aWorkSpaceIndex++) {
                    if (aWorkSpaceIndex < Soccer2::mClaimedWorkSpaceCount) {
                        if (!aClaimedWorkSpaceSet.contains(Soccer2::mWorkSpaces[aWorkSpaceIndex])) {
                            XCTFail("test_Prologue_A_B_Shuffle_Weak: expecting claimed work space [%zu], was not claimed. (shuffle #%zu)", aWorkSpaceIndex, aShuffleTrialIndex);
                            return;
                        }
                    }
                    aCheckedWorkSpaceSet.insert(Soccer2::mWorkSpaces[aWorkSpaceIndex]);
                }
                
                if (aCheckedExpanderSet.size() != SOCCER_EXPANDER_COUNT) {
                    XCTFail("test_Prologue_A_B_Shuffle_Weak: expecting %d unique expanders. (shuffle #%zu)", SOCCER_EXPANDER_COUNT, aShuffleTrialIndex);
                    return;
                }
                if (aCheckedMaterialSet.size() != 16) {
                    XCTFail("test_Prologue_A_B_Shuffle_Weak: expecting 16 unique materials. (shuffle #%zu)", aShuffleTrialIndex);
                    return;
                }
                if (aCheckedWorkSpaceSet.size() != 16) {
                    XCTFail("test_Prologue_A_B_Shuffle_Weak: expecting 16 unique work spaces. (shuffle #%zu)", aShuffleTrialIndex);
                    return;
                }
                
                WorkSpaceTools::FillBytes(Soccer2::mRandom, S_BLOCK);
                Soccer2::Shuffle_CROWSCIMASSORMATEX();
            }
            
            if (aShuffleHashesMaterials.size() < 3) {
                XCTFail("test_Prologue_A_B_Shuffle_Weak: expecting 3 unique shuffles for material hashes, got %zu", aShuffleHashesMaterials.size());
                return;
            }
            
            if (aShuffleHashesExpanders.size() < 6) {
                XCTFail("test_Prologue_A_B_Shuffle_Weak: expecting 6 unique shuffles for expanders hashes, got %zu", aShuffleHashesExpanders.size());
                return;
            }
            
            if (aShuffleHashesWorkSpaces.size() < 3) {
                XCTFail("test_Prologue_A_B_Shuffle_Weak: expecting 3 unique shuffles for work space hashes, got %zu", aShuffleHashesWorkSpaces.size());
                return;
            }
        }
        
        aHashesMaterials.insert(ToString(Soccer2::mClaimedMaterials, Soccer2::mClaimedMaterialCount));
        aHashesExpanders.insert(ToString(Soccer2::mClaimedExpanders, Soccer2::mClaimedExpanderCount));
        aHashesWorkSpaces.insert(ToString(Soccer2::mClaimedWorkSpaces, Soccer2::mClaimedWorkSpaceCount));

        const std::size_t aFirstSaltSlot = static_cast<std::size_t>(TwistWorkSpaceSlot::kKeyRotateASaltOrbiterAssignA);
        const std::size_t aLastSaltSlot = static_cast<std::size_t>(TwistWorkSpaceSlot::kKeySpawnBSaltWandererUpdateH);

        for (std::size_t aWorkSpaceIndex=0U; aWorkSpaceIndex<Soccer2::mClaimedWorkSpaceCount; aWorkSpaceIndex++) {
            for (std::size_t aSaltSlot=aFirstSaltSlot; aSaltSlot<=aLastSaltSlot; aSaltSlot++) {
                std::uint8_t *aSalt = TwistWorkSpace::GetBuffer(Soccer2::mWorkSpaces[aWorkSpaceIndex],
                                                               static_cast<TwistWorkSpaceSlot>(aSaltSlot));
                const std::size_t aByteRichness = LaneTool::ByteRichness(aSalt, S_SALT * sizeof(std::uint64_t));
                const std::size_t aSaltIndex = aSaltSlot - aFirstSaltSlot;

                if (aByteRichness < 480U) {
                    XCTFail("test_Prologue_A_B_Shuffle_Weak: expected work space [%zu], salt %zu to have 480 byte richness, got %zu.",
                            aWorkSpaceIndex, aSaltIndex, aByteRichness);
                    return;
                }
            }
        }
        
    }
    
    if (aHashesMaterials.size() < 12) {
        XCTFail("test_Prologue_A_Weak: expected more unique claimed material configurations");
        return;
    }
    if (aHashesExpanders.size() < 12) {
        XCTFail("test_Prologue_A_Weak: expected more unique claimed expander configurations");
        return;
    }
    if (aHashesWorkSpaces.size() < 12) {
        XCTFail("test_Prologue_A_Weak: expected more unique claimed work space configurations");
        return;
    }
    
}

- (void)test_Prologue_A_B_Shuffle_Normal {
    
    std::unordered_set<std::string> aHashesMaterials;
    std::unordered_set<std::string> aHashesExpanders;
    std::unordered_set<std::string> aHashesWorkSpaces;
    
    for (std::size_t aTrial=0; aTrial<12; aTrial++) {
        
        
        std::uint64_t aNonce = Random::Get64();
        
        std::uint8_t aPassword[3];
        for (std::size_t aIndex=0; aIndex<3; aIndex++) {
            aPassword[aIndex] = Random::GetByte();
        }
        
        Soccer2::Zero();
        Soccer2::mStrength = EncryptionStrength::kNormal;
        Soccer2::InitializeExpanders();
        Soccer2::InitializeWorkSpaces();
        Soccer2::InitializeMaterials();
        Soccer2::SeedPrologue_Regular_A(aPassword, 3, aNonce);
        
        if (Soccer2::mClaimedExpanderCount != 8) {
            XCTFail("test_Prologue_A_B_Shuffle_Normal: expecting 8 claimed expanders.");
            return;
        }
        if (Soccer2::mClaimedMaterialCount != 8) {
            XCTFail("test_Prologue_A_B_Shuffle_Normal: expecting 8 claimed materials.");
            return;
        }
        if (Soccer2::mClaimedWorkSpaceCount != 8) {
            XCTFail("test_Prologue_A_B_Shuffle_Normal: expecting 8 claimed work spaces.");
            return;
        }
        
        
        std::unordered_set<TwistExpander *> aClaimedExpanderSet;
        for (std::size_t aExpanderIndex=0; aExpanderIndex<Soccer2::mClaimedExpanderCount; aExpanderIndex++) {
            aClaimedExpanderSet.insert(Soccer2::mClaimedExpanders[aExpanderIndex]);
        }
        
        std::unordered_set<std::uint8_t *> aClaimedMaterialSet;
        const std::size_t aWarmUpStartIndex = (32 - 4) * S_BLOCK;
        for (std::size_t aMaterialIndex=0; aMaterialIndex<Soccer2::mClaimedMaterialCount; aMaterialIndex++) {
            aClaimedMaterialSet.insert(Soccer2::mClaimedMaterials[aMaterialIndex]);
            std::size_t aByteRichness = LaneTool::ByteRichness(&Soccer2::mClaimedMaterials[aMaterialIndex][aWarmUpStartIndex], S_BLOCK);
            if (aByteRichness < 512) {
                XCTFail("test_Prologue_A_B_Shuffle_Normal: expecting claimed material [%zu] early block to be byte rich. (got %zu)", aMaterialIndex, aByteRichness);
                return;
            }
        }
        
        std::unordered_set<TwistWorkSpace *> aClaimedWorkSpaceSet;
        for (std::size_t aWorkSpaceIndex=0; aWorkSpaceIndex<Soccer2::mClaimedWorkSpaceCount; aWorkSpaceIndex++) {
            aClaimedWorkSpaceSet.insert(Soccer2::mClaimedWorkSpaces[aWorkSpaceIndex]);
        }
        
        std::unordered_set<std::uint8_t *> aAllMaterialSet;
        for (std::size_t aOuterMaterialIndex=0; aOuterMaterialIndex<16; aOuterMaterialIndex++) {
            
            aAllMaterialSet.insert(Soccer2::mMaterials[aOuterMaterialIndex]);
            
            if (aClaimedMaterialSet.contains(Soccer2::mMaterials[aOuterMaterialIndex])) {
                for (std::size_t aBlockIndex=0; aBlockIndex<32; aBlockIndex++) {
                    std::size_t aByteRichness = LaneTool::ByteRichness(&Soccer2::mMaterials[aOuterMaterialIndex][S_BLOCK * aBlockIndex], S_BLOCK);
                    
                    if (aBlockIndex == 28) {
                        if (aByteRichness < 512) {
                            XCTFail("test_Prologue_A_B_Shuffle_Normal: expecting claimed material [%zu] block [%zu] to be byte rich. (got %zu)", aOuterMaterialIndex, aBlockIndex, aByteRichness);
                            return;
                        }
                    } else {
                        if (aByteRichness > 64) {
                            XCTFail("test_Prologue_A_B_Shuffle_Normal: expecting claimed material [%zu] block [%zu] to be byte rich. (got %zu)", aOuterMaterialIndex, aBlockIndex, aByteRichness);
                            return;
                        }
                    }
                }
            } else {
                for (std::size_t aBlockIndex=0; aBlockIndex<32; aBlockIndex++) {
                    std::size_t aByteRichness = LaneTool::ByteRichness(&Soccer2::mMaterials[aOuterMaterialIndex][S_BLOCK * aBlockIndex], S_BLOCK);
                    if (aByteRichness > 64) {
                        XCTFail("test_Prologue_A_B_Shuffle_Normal: expecting claimed material [%zu] block [%zu] to be byte rich. (got %zu)", aOuterMaterialIndex, aBlockIndex, aByteRichness);
                        return;
                    }
                }
            }
            
            Soccer2::SeedPrologue_Regular_B();
            
            std::unordered_set<std::string> aShuffleHashesMaterials;
            std::unordered_set<std::string> aShuffleHashesExpanders;
            std::unordered_set<std::string> aShuffleHashesWorkSpaces;
            
            for (std::size_t aShuffleTrialIndex=0; aShuffleTrialIndex<8; aShuffleTrialIndex++) {
                
                std::unordered_set<std::uint8_t *> aCheckedMaterialSet;
                std::unordered_set<TwistExpander *> aCheckedExpanderSet;
                std::unordered_set<TwistWorkSpace *> aCheckedWorkSpaceSet;
                
                aShuffleHashesMaterials.insert(ToString(Soccer2::mMaterials, Soccer2::mClaimedMaterialCount));
                aShuffleHashesExpanders.insert(ToString(Soccer2::mExpanders, Soccer2::mClaimedExpanderCount));
                aShuffleHashesWorkSpaces.insert(ToString(Soccer2::mWorkSpaces, Soccer2::mClaimedWorkSpaceCount));
                
                if (aShuffleTrialIndex == 0) {
                    for (std::size_t aExpanderIndex=0; aExpanderIndex<SOCCER_EXPANDER_COUNT; aExpanderIndex++) {
                        if (aExpanderIndex < Soccer2::mClaimedExpanderCount) {
                            if (!aClaimedExpanderSet.contains(Soccer2::mExpanders[aExpanderIndex])) {
                                XCTFail("test_Prologue_A_B_Shuffle_Normal: expecting claimed expander [%zu], was not claimed. (shuffle #%zu)", aExpanderIndex, aShuffleTrialIndex);
                                return;
                            }
                        }
                        aCheckedExpanderSet.insert(Soccer2::mExpanders[aExpanderIndex]);
                    }
                } else {
                    for (std::size_t aExpanderIndex=0; aExpanderIndex<SOCCER_EXPANDER_COUNT; aExpanderIndex++) {
                        aCheckedExpanderSet.insert(Soccer2::mExpanders[aExpanderIndex]);
                    }
                }
                
                for (std::size_t aMaterialIndex=0; aMaterialIndex<16; aMaterialIndex++) {
                    if (aMaterialIndex < Soccer2::mClaimedMaterialCount) {
                        if (!aClaimedMaterialSet.contains(Soccer2::mMaterials[aMaterialIndex])) {
                            XCTFail("test_Prologue_A_B_Shuffle_Normal: expecting claimed material [%zu], was not claimed. (shuffle #%zu)", aMaterialIndex, aShuffleTrialIndex);
                            return;
                        }
                    }
                    aCheckedMaterialSet.insert(Soccer2::mMaterials[aMaterialIndex]);
                }
                
                for (std::size_t aWorkSpaceIndex=0; aWorkSpaceIndex<16; aWorkSpaceIndex++) {
                    if (aWorkSpaceIndex < Soccer2::mClaimedWorkSpaceCount) {
                        if (!aClaimedWorkSpaceSet.contains(Soccer2::mWorkSpaces[aWorkSpaceIndex])) {
                            XCTFail("test_Prologue_A_B_Shuffle_Normal: expecting claimed work space [%zu], was not claimed. (shuffle #%zu)", aWorkSpaceIndex, aShuffleTrialIndex);
                            return;
                        }
                    }
                    aCheckedWorkSpaceSet.insert(Soccer2::mWorkSpaces[aWorkSpaceIndex]);
                }
                
                if (aCheckedExpanderSet.size() != SOCCER_EXPANDER_COUNT) {
                    XCTFail("test_Prologue_A_B_Shuffle_Normal: expecting %d unique expanders. (shuffle #%zu)", SOCCER_EXPANDER_COUNT, aShuffleTrialIndex);
                    return;
                }
                if (aCheckedMaterialSet.size() != 16) {
                    XCTFail("test_Prologue_A_B_Shuffle_Normal: expecting 16 unique materials. (shuffle #%zu)", aShuffleTrialIndex);
                    return;
                }
                if (aCheckedWorkSpaceSet.size() != 16) {
                    XCTFail("test_Prologue_A_B_Shuffle_Normal: expecting 16 unique work spaces. (shuffle #%zu)", aShuffleTrialIndex);
                    return;
                }
                
                WorkSpaceTools::FillBytes(Soccer2::mRandom, S_BLOCK);
                Soccer2::Shuffle_CROWSCIMASSORMATEX();
            }
            
            if (aShuffleHashesMaterials.size() < 3) {
                XCTFail("test_Prologue_A_B_Shuffle_Normal: expecting 3 unique shuffles for material hashes, got %zu", aShuffleHashesMaterials.size());
                return;
            }
            
            if (aShuffleHashesExpanders.size() < 6) {
                XCTFail("test_Prologue_A_B_Shuffle_Normal: expecting 6 unique shuffles for expanders hashes, got %zu", aShuffleHashesExpanders.size());
                return;
            }
            
            if (aShuffleHashesWorkSpaces.size() < 3) {
                XCTFail("test_Prologue_A_B_Shuffle_Normal: expecting 3 unique shuffles for work space hashes, got %zu", aShuffleHashesWorkSpaces.size());
                return;
            }
        }
        
        aHashesMaterials.insert(ToString(Soccer2::mClaimedMaterials, Soccer2::mClaimedMaterialCount));
        aHashesExpanders.insert(ToString(Soccer2::mClaimedExpanders, Soccer2::mClaimedExpanderCount));
        aHashesWorkSpaces.insert(ToString(Soccer2::mClaimedWorkSpaces, Soccer2::mClaimedWorkSpaceCount));

        const std::size_t aFirstSaltSlot = static_cast<std::size_t>(TwistWorkSpaceSlot::kKeyRotateASaltOrbiterAssignA);
        const std::size_t aLastSaltSlot = static_cast<std::size_t>(TwistWorkSpaceSlot::kKeySpawnBSaltWandererUpdateH);

        for (std::size_t aWorkSpaceIndex=0U; aWorkSpaceIndex<Soccer2::mClaimedWorkSpaceCount; aWorkSpaceIndex++) {
            for (std::size_t aSaltSlot=aFirstSaltSlot; aSaltSlot<=aLastSaltSlot; aSaltSlot++) {
                std::uint8_t *aSalt = TwistWorkSpace::GetBuffer(Soccer2::mWorkSpaces[aWorkSpaceIndex],
                                                               static_cast<TwistWorkSpaceSlot>(aSaltSlot));
                const std::size_t aByteRichness = LaneTool::ByteRichness(aSalt, S_SALT * sizeof(std::uint64_t));
                const std::size_t aSaltIndex = aSaltSlot - aFirstSaltSlot;

                if (aByteRichness < 480U) {
                    XCTFail("test_Prologue_A_B_Shuffle_Normal: expected work space [%zu], salt %zu to have 480 byte richness, got %zu.",
                            aWorkSpaceIndex, aSaltIndex, aByteRichness);
                    return;
                }
            }
        }
        
    }
    
    if (aHashesMaterials.size() < 8) {
        XCTFail("test_Prologue_A_B_Shuffle_Normal: expected more unique claimed material configurations");
        return;
    }
    if (aHashesExpanders.size() < 8) {
        XCTFail("test_Prologue_A_B_Shuffle_Normal: expected more unique claimed expander configurations");
        return;
    }
    if (aHashesWorkSpaces.size() < 8) {
        XCTFail("test_Prologue_A_B_Shuffle_Normal: expected more unique claimed work space configurations");
        return;
    }
    
}

- (void)test_Prologue_A_B_Shuffle_Strong {
    
    std::unordered_set<std::string> aHashesMaterials;
    std::unordered_set<std::string> aHashesExpanders;
    std::unordered_set<std::string> aHashesWorkSpaces;
    
    for (std::size_t aTrial=0; aTrial<8; aTrial++) {
        
        
        std::uint64_t aNonce = Random::Get64();
        
        std::uint8_t aPassword[3];
        for (std::size_t aIndex=0; aIndex<3; aIndex++) {
            aPassword[aIndex] = Random::GetByte();
        }

        Soccer2::Zero();
        Soccer2::mStrength = EncryptionStrength::kStrong;
        Soccer2::InitializeExpanders();
        Soccer2::InitializeWorkSpaces();
        Soccer2::InitializeMaterials();
        Soccer2::SeedPrologue_Regular_A(aPassword, 3, aNonce);
        
        if (Soccer2::mClaimedExpanderCount != 16) {
            XCTFail("test_Prologue_A_B_Shuffle_Strong: expecting 16 claimed expanders.");
            return;
        }
        if (Soccer2::mClaimedMaterialCount != 16) {
            XCTFail("test_Prologue_A_B_Shuffle_Strong: expecting 16 claimed materials.");
            return;
        }
        if (Soccer2::mClaimedWorkSpaceCount != 16) {
            XCTFail("test_Prologue_A_B_Shuffle_Strong: expecting 16 claimed work spaces.");
            return;
        }
        
        
        std::unordered_set<TwistExpander *> aClaimedExpanderSet;
        for (std::size_t aExpanderIndex=0; aExpanderIndex<Soccer2::mClaimedExpanderCount; aExpanderIndex++) {
            aClaimedExpanderSet.insert(Soccer2::mClaimedExpanders[aExpanderIndex]);
        }
        
        std::unordered_set<std::uint8_t *> aClaimedMaterialSet;
        const std::size_t aWarmUpStartIndex = (32 - 4) * S_BLOCK;
        for (std::size_t aMaterialIndex=0; aMaterialIndex<Soccer2::mClaimedMaterialCount; aMaterialIndex++) {
            aClaimedMaterialSet.insert(Soccer2::mClaimedMaterials[aMaterialIndex]);
            std::size_t aByteRichness = LaneTool::ByteRichness(&Soccer2::mClaimedMaterials[aMaterialIndex][aWarmUpStartIndex], S_BLOCK);
            if (aByteRichness < 512) {
                XCTFail("test_Prologue_A_B_Shuffle_Strong: expecting claimed material [%zu] early block to be byte rich. (got %zu)", aMaterialIndex, aByteRichness);
                return;
            }
        }
        
        std::unordered_set<TwistWorkSpace *> aClaimedWorkSpaceSet;
        for (std::size_t aWorkSpaceIndex=0; aWorkSpaceIndex<Soccer2::mClaimedWorkSpaceCount; aWorkSpaceIndex++) {
            aClaimedWorkSpaceSet.insert(Soccer2::mClaimedWorkSpaces[aWorkSpaceIndex]);
        }
        
        std::unordered_set<std::uint8_t *> aAllMaterialSet;
        for (std::size_t aOuterMaterialIndex=0; aOuterMaterialIndex<16; aOuterMaterialIndex++) {
            
            aAllMaterialSet.insert(Soccer2::mMaterials[aOuterMaterialIndex]);
            
            if (aClaimedMaterialSet.contains(Soccer2::mMaterials[aOuterMaterialIndex])) {
                for (std::size_t aBlockIndex=0; aBlockIndex<32; aBlockIndex++) {
                    std::size_t aByteRichness = LaneTool::ByteRichness(&Soccer2::mMaterials[aOuterMaterialIndex][S_BLOCK * aBlockIndex], S_BLOCK);
                    
                    if (aBlockIndex == 28) {
                        if (aByteRichness < 512) {
                            XCTFail("test_Prologue_A_B_Shuffle_Strong: expecting claimed material [%zu] block [%zu] to be byte rich. (got %zu)", aOuterMaterialIndex, aBlockIndex, aByteRichness);
                            return;
                        }
                    } else {
                        if (aByteRichness > 64) {
                            XCTFail("test_Prologue_A_B_Shuffle_Strong: expecting claimed material [%zu] block [%zu] to be byte rich. (got %zu)", aOuterMaterialIndex, aBlockIndex, aByteRichness);
                            return;
                        }
                    }
                }
            } else {
                for (std::size_t aBlockIndex=0; aBlockIndex<32; aBlockIndex++) {
                    std::size_t aByteRichness = LaneTool::ByteRichness(&Soccer2::mMaterials[aOuterMaterialIndex][S_BLOCK * aBlockIndex], S_BLOCK);
                    if (aByteRichness > 64) {
                        XCTFail("test_Prologue_A_B_Shuffle_Strong: expecting claimed material [%zu] block [%zu] to be byte rich. (got %zu)", aOuterMaterialIndex, aBlockIndex, aByteRichness);
                        return;
                    }
                }
            }
            
            Soccer2::SeedPrologue_Regular_B();
            
            std::unordered_set<std::string> aShuffleHashesMaterials;
            std::unordered_set<std::string> aShuffleHashesExpanders;
            std::unordered_set<std::string> aShuffleHashesWorkSpaces;
            
            for (std::size_t aShuffleTrialIndex=0; aShuffleTrialIndex<8; aShuffleTrialIndex++) {
                
                std::unordered_set<std::uint8_t *> aCheckedMaterialSet;
                std::unordered_set<TwistExpander *> aCheckedExpanderSet;
                std::unordered_set<TwistWorkSpace *> aCheckedWorkSpaceSet;
                
                aShuffleHashesMaterials.insert(ToString(Soccer2::mMaterials, Soccer2::mClaimedMaterialCount));
                aShuffleHashesExpanders.insert(ToString(Soccer2::mExpanders, Soccer2::mClaimedExpanderCount));
                aShuffleHashesWorkSpaces.insert(ToString(Soccer2::mWorkSpaces, Soccer2::mClaimedWorkSpaceCount));
                
                if (aShuffleTrialIndex == 0) {
                    for (std::size_t aExpanderIndex=0; aExpanderIndex<SOCCER_EXPANDER_COUNT; aExpanderIndex++) {
                        if (aExpanderIndex < Soccer2::mClaimedExpanderCount) {
                            if (!aClaimedExpanderSet.contains(Soccer2::mExpanders[aExpanderIndex])) {
                                XCTFail("test_Prologue_A_B_Shuffle_Strong: expecting claimed expander [%zu], was not claimed. (shuffle #%zu)", aExpanderIndex, aShuffleTrialIndex);
                                return;
                            }
                        }
                        aCheckedExpanderSet.insert(Soccer2::mExpanders[aExpanderIndex]);
                    }
                } else {
                    for (std::size_t aExpanderIndex=0; aExpanderIndex<SOCCER_EXPANDER_COUNT; aExpanderIndex++) {
                        aCheckedExpanderSet.insert(Soccer2::mExpanders[aExpanderIndex]);
                    }
                }
                
                for (std::size_t aMaterialIndex=0; aMaterialIndex<16; aMaterialIndex++) {
                    if (aMaterialIndex < Soccer2::mClaimedMaterialCount) {
                        if (!aClaimedMaterialSet.contains(Soccer2::mMaterials[aMaterialIndex])) {
                            XCTFail("test_Prologue_A_B_Shuffle_Strong: expecting claimed material [%zu], was not claimed. (shuffle #%zu)", aMaterialIndex, aShuffleTrialIndex);
                            return;
                        }
                    }
                    aCheckedMaterialSet.insert(Soccer2::mMaterials[aMaterialIndex]);
                }
                
                for (std::size_t aWorkSpaceIndex=0; aWorkSpaceIndex<16; aWorkSpaceIndex++) {
                    if (aWorkSpaceIndex < Soccer2::mClaimedWorkSpaceCount) {
                        if (!aClaimedWorkSpaceSet.contains(Soccer2::mWorkSpaces[aWorkSpaceIndex])) {
                            XCTFail("test_Prologue_A_B_Shuffle_Strong: expecting claimed work space [%zu], was not claimed. (shuffle #%zu)", aWorkSpaceIndex, aShuffleTrialIndex);
                            return;
                        }
                    }
                    aCheckedWorkSpaceSet.insert(Soccer2::mWorkSpaces[aWorkSpaceIndex]);
                }
                
                if (aCheckedExpanderSet.size() != SOCCER_EXPANDER_COUNT) {
                    XCTFail("test_Prologue_A_B_Shuffle_Strong: expecting %d unique expanders. (shuffle #%zu)", SOCCER_EXPANDER_COUNT, aShuffleTrialIndex);
                    return;
                }
                if (aCheckedMaterialSet.size() != 16) {
                    XCTFail("test_Prologue_A_B_Shuffle_Strong: expecting 16 unique materials. (shuffle #%zu)", aShuffleTrialIndex);
                    return;
                }
                if (aCheckedWorkSpaceSet.size() != 16) {
                    XCTFail("test_Prologue_A_B_Shuffle_Strong: expecting 16 unique work spaces. (shuffle #%zu)", aShuffleTrialIndex);
                    return;
                }
                
                WorkSpaceTools::FillBytes(Soccer2::mRandom, S_BLOCK);
                Soccer2::Shuffle_CROWSCIMASSORMATEX();
            }
            
            if (aShuffleHashesMaterials.size() < 3) {
                XCTFail("test_Prologue_A_B_Shuffle_Strong: expecting 3 unique shuffles for material hashes, got %zu", aShuffleHashesMaterials.size());
                return;
            }
            
            if (aShuffleHashesExpanders.size() < 6) {
                XCTFail("test_Prologue_A_B_Shuffle_Strong: expecting 6 unique shuffles for expanders hashes, got %zu", aShuffleHashesExpanders.size());
                return;
            }
            
            if (aShuffleHashesWorkSpaces.size() < 3) {
                XCTFail("test_Prologue_A_B_Shuffle_Strong: expecting 3 unique shuffles for work space hashes, got %zu", aShuffleHashesWorkSpaces.size());
                return;
            }
        }
        
        aHashesMaterials.insert(ToString(Soccer2::mClaimedMaterials, Soccer2::mClaimedMaterialCount));
        aHashesExpanders.insert(ToString(Soccer2::mClaimedExpanders, Soccer2::mClaimedExpanderCount));
        aHashesWorkSpaces.insert(ToString(Soccer2::mClaimedWorkSpaces, Soccer2::mClaimedWorkSpaceCount));

        const std::size_t aFirstSaltSlot = static_cast<std::size_t>(TwistWorkSpaceSlot::kKeyRotateASaltOrbiterAssignA);
        const std::size_t aLastSaltSlot = static_cast<std::size_t>(TwistWorkSpaceSlot::kKeySpawnBSaltWandererUpdateH);

        for (std::size_t aWorkSpaceIndex=0U; aWorkSpaceIndex<Soccer2::mClaimedWorkSpaceCount; aWorkSpaceIndex++) {
            for (std::size_t aSaltSlot=aFirstSaltSlot; aSaltSlot<=aLastSaltSlot; aSaltSlot++) {
                std::uint8_t *aSalt = TwistWorkSpace::GetBuffer(Soccer2::mWorkSpaces[aWorkSpaceIndex],
                                                               static_cast<TwistWorkSpaceSlot>(aSaltSlot));
                const std::size_t aByteRichness = LaneTool::ByteRichness(aSalt, S_SALT * sizeof(std::uint64_t));
                const std::size_t aSaltIndex = aSaltSlot - aFirstSaltSlot;

                if (aByteRichness < 480U) {
                    XCTFail("test_Prologue_A_B_Shuffle_Strong: expected work space [%zu], salt %zu to have 480 byte richness, got %zu.",
                            aWorkSpaceIndex, aSaltIndex, aByteRichness);
                    return;
                }
            }
        }
        
    }
    
    if (aHashesMaterials.size() < 6) {
        XCTFail("test_Prologue_A_B_Shuffle_Strong: expected more unique claimed material configurations");
        return;
    }
    if (aHashesExpanders.size() < 6) {
        XCTFail("test_Prologue_A_B_Shuffle_Strong: expected more unique claimed expander configurations");
        return;
    }
    if (aHashesWorkSpaces.size() < 6) {
        XCTFail("test_Prologue_A_B_Shuffle_Strong: expected more unique claimed work space configurations");
        return;
    }
    
}

@end
