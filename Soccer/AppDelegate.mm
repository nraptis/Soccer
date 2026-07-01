//
//  AppDelegate.m
//  Army
//
//  Created by icarus black on 6/26/26.
//

#import "AppDelegate.h"
#include "Avalancher.hpp"
#include "TwistExpander_Soccer.hpp"
#include "TwistFarmSalt.hpp"
#include <cstdio>

@interface AppDelegate ()

@property (strong) IBOutlet NSWindow *window;
@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    // Insert code here to initialize your application
    
TwistExpander_Soccer aSoccer;

std::uint8_t aTinyPassword[2];
aTinyPassword[0] = 'a';
aTinyPassword[1] = 'Z';

const int aBlockCount = 32;

TwistWorkSpace aWorkSpace;
TwistFarmSalt aFarmSalt;
std::uint64_t aNonce = 3333333333333333333;
std::uint8_t aDest[S_BLOCK * aBlockCount];

aSoccer.Seed(&aWorkSpace,
             &aFarmSalt,
             aNonce,
             aTinyPassword, // password
             2, // password length
             aDest);
    for (int aBlockIndex=1; aBlockIndex<aBlockCount; aBlockIndex++) {
        aSoccer.TwistBlock(&aWorkSpace,
                           aNonce,
                           &aDest[(aBlockIndex - 1) * S_BLOCK], // source
                           aBlockIndex,
                           aBlockCount,
                           &aDest[(aBlockIndex) * S_BLOCK]); // dest
    }
    

    const int aTotalByteCount = S_BLOCK * aBlockCount;

    for (int i = 0; i < aTotalByteCount; i++) {
        std::printf("%02X", aDest[i]);

        if ((i & 31) == 31) { // 32 bytes per line
            std::printf("\n");
        }
    }

    if ((aTotalByteCount & 31) != 0) {
        std::printf("\n");
    }
    
    
    {
        // Measure the avalanche
        std::string aPasswordA = "cat";
        std::string aPasswordB = "eat";
        Avalancher aAvalancher;
        aAvalancher.SetExpander(&aSoccer);
        auto aResult = aAvalancher.DiffAB(aPasswordA, aPasswordB);
        aResult.PrintExtended("Soccer");
        aResult.PrintQuick("Soccer");
    }
    
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}


- (BOOL)applicationSupportsSecureRestorableState:(NSApplication *)app {
    return YES;
}


@end
