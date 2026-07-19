//
//  RepeatActionTest.mm
//  ScrambleTests
//
//  Created by nick on 7/19/26.
//

#import <XCTest/XCTest.h>

#include "ExpanderFactory.hpp"
#include "TwistFarmSalt.hpp"

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <vector>

@interface RepeatActionTest : XCTestCase

@end

@implementation RepeatActionTest

- (void)testRepeatAction {

    std::uint8_t aPassword[] = {
        'R', 'e', 'p', 'e', 'a', 't', 'A', 'c', 't', 'i', 'o', 'n'
    };
    constexpr std::uint64_t aNonce = 0x7AB19D42E6503FC8ULL;

    std::vector<ExpanderItem> aExpanderItems = ExpanderFactory::Get();
    for (ExpanderItem &aExpanderItem : aExpanderItems) {
        TwistWorkSpace aWorkSpace;
        TwistFarmSalt aFarmSalt;
        std::uint8_t aEncryptedA[S_BLOCK];
        std::uint8_t aEncryptedB[S_BLOCK];

        aExpanderItem.mExpander->AutoSeedThenTwist(&aWorkSpace,
                                                   &aFarmSalt,
                                                   aNonce,
                                                   aPassword,
                                                   sizeof(aPassword),
                                                   aEncryptedA,
                                                   S_BLOCK);

        aWorkSpace.Zero();
        aExpanderItem.mExpander->Zero();

        aExpanderItem.mExpander->AutoSeedThenTwist(&aWorkSpace,
                                                   &aFarmSalt,
                                                   aNonce,
                                                   aPassword,
                                                   sizeof(aPassword),
                                                   aEncryptedB,
                                                   S_BLOCK);

        const bool aMatches = std::memcmp(aEncryptedA, aEncryptedB, S_BLOCK) == 0;
        std::printf("Repeat action %s: %s\n",
                    aExpanderItem.mName.c_str(),
                    aMatches ? "matched" : "did not match");
        XCTAssertTrue(aMatches,
                      @"%s produced different output after workspace and expander zeroing",
                      aExpanderItem.mName.c_str());
    }

}

@end
