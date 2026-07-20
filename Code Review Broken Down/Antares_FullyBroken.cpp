#include "TwistExpander_Antares_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Antares_Arx::KDF_A_A() {
    // [kdf-a arx]
    // GSeedRunKDF_A_A kdf_a_loop_a (start)
    {
        //
        // kdf_a_loop_a loop 1
        //
        // Ingress:
        //      aSource (-->), pSnow (-->)
        //
        // Cross:
        //      pSnow (<--), aSource (<--)
        //
        // Destination:
        //      aScrapLaneA
        //

        //
        // kdf_a_loop_a loop 2
        //
        // Ingress:
        //      aScrapLaneA (-->), aSource (-->)
        //
        // Cross:
        //      aScrapLaneA (<--), pSnow (<--)
        //
        // Destination:
        //      aScrapLaneB
        //

        //
        // kdf_a_loop_a loop 3
        //
        // Ingress:
        //      aScrapLaneB (-->), aSource (<-?->)
        //
        // Cross:
        //      pSnow (<--), aScrapLaneA (<-?->)
        //
        // Destination:
        //      aEarthLaneA
        //

        //
        // kdf_a_loop_a loop 4
        //
        // Ingress:
        //      aEarthLaneA (-->), aScrapLaneB (<-?->)
        //
        // Cross:
        //      aScrapLaneA (<--), aSource (<-?->)
        //
        // Destination:
        //      aEarthLaneB
        //

        //
        // kdf_a_loop_a loop 5
        //
        // Ingress:
        //      aEarthLaneB (-->), aScrapLaneB (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), pSnow (<-?->)
        //
        // Destination:
        //      aEarthLaneC
        //

        //
        // kdf_a_loop_a loop 6
        //
        // Ingress:
        //      aEarthLaneC (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aEarthLaneB (<--), aScrapLaneA (<-?->)
        //
        // Destination:
        //      aEarthLaneD
        //
    }
}

void TwistExpander_Antares_Arx::KDF_A_B() {
    // [kdf-a arx]
    // GSeedRunKDF_A_B kdf_a_loop_b (start)
    {
        //
        // kdf_a_loop_b loop 1
        //
        // Ingress:
        //      aEarthLaneA (-->), aEarthLaneB (-->), pSnow (<-?->)
        //
        // Cross:
        //      aEarthLaneC (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aFireLaneA
        //

        //
        // kdf_a_loop_b loop 2
        //
        // Ingress:
        //      aFireLaneA (-->), aEarthLaneC (-->), aSource (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aEarthLaneD (<--)
        //
        // Destination:
        //      aFireLaneB
        //

        //
        // kdf_a_loop_b loop 3
        //
        // Ingress:
        //      aFireLaneB (-->), aEarthLaneD (-->), aScrapLaneA (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aEarthLaneB (<--)
        //
        // Destination:
        //      aFireLaneC
        //

        //
        // kdf_a_loop_b loop 4
        //
        // Ingress:
        //      aFireLaneC (-->), aFireLaneA (-->), aScrapLaneB (<-?->)
        //
        // Cross:
        //      aFireLaneB (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aFireLaneD
        //
    }
}

void TwistExpander_Antares_Arx::KDF_A_C() {
    // [kdf-a arx]
    // GSeedRunKDF_A_C kdf_a_loop_c (start)
    {
        //
        // kdf_a_loop_c loop 1
        //
        // Ingress:
        //      aFireLaneA (-->), aFireLaneB (-->), aEarthLaneB (<-?->)
        //
        // Cross:
        //      aFireLaneC (<--), aFireLaneD (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aOperationLaneA
        //

        //
        // kdf_a_loop_c loop 2
        //
        // Ingress:
        //      aOperationLaneA (-->), aFireLaneC (-->), aSource (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), aScrapLaneB (<-?->)
        //
        // Destination:
        //      aOperationLaneB
        //

        //
        // kdf_a_loop_c loop 3
        //
        // Ingress:
        //      aOperationLaneB (-->), aFireLaneD (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aFireLaneB (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneC
        //

        //
        // kdf_a_loop_c loop 4
        //
        // Ingress:
        //      aOperationLaneC (-->), aOperationLaneA (-->), aScrapLaneA (<-?->)
        //
        // Cross:
        //      aOperationLaneB (<--), aFireLaneC (<--), pSnow (<-?->)
        //
        // Destination:
        //      aOperationLaneD
        //
    }
}

void TwistExpander_Antares_Arx::KDF_A_D() {
    // [kdf-a arx]
    // GSeedRunKDF_A_D kdf_a_loop_d (start)
    {
        //
        // kdf_a_loop_d loop 1
        //
        // Ingress:
        //      aOperationLaneA (-->), aOperationLaneB (-->), aFireLaneD (-->), aEarthLaneB (<-?->)
        //
        // Cross:
        //      aOperationLaneC (<--), aOperationLaneD (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        
        //
        // kdf_a_loop_d loop 2
        //
        // Ingress:
        //      aFuseLaneA (-->), aOperationLaneC (-->), aFireLaneC (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aOperationLaneD (<--), aScrapLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //

        //
        // kdf_a_loop_d loop 3
        //
        // Ingress:
        //      aFuseLaneB (-->), aOperationLaneD (-->), pSnow (-->), aSource (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aOperationLaneB (<--), aFireLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //

        //
        // kdf_a_loop_d loop 4
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aEarthLaneD (-->), aScrapLaneA (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aOperationLaneC (<--), aFireLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
    }
}

void TwistExpander_Antares_Arx::KDF_A_E() {
    // [kdf-a arx]
    // GSeedRunKDF_A_E kdf_a_loop_e (start)
    {
        //
        // kdf_a_loop_e loop 1
        //
        // Ingress:
        //      aWindLaneA (-->), aWindLaneB (-->), aEarthLaneA (-->), aOperationLaneC (<-?->)
        //
        // Cross:
        //      aWindLaneC (<--), aWindLaneD (<--), aOperationLaneD (<--), aFireLaneD (<-?->)
        //
        // Destination:
        //      aWaterLaneA
        //

        //
        // kdf_a_loop_e loop 2
        //
        // Ingress:
        //      aWaterLaneA (-->), aWindLaneC (-->), aFireLaneA (-->), pSnow (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aWindLaneD (<--), aOperationLaneB (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aWaterLaneB
        //

        //
        // kdf_a_loop_e loop 3
        //
        // Ingress:
        //      aWaterLaneB (-->), aWindLaneD (-->), aFireLaneC (-->), aEarthLaneC (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWindLaneB (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aWaterLaneC
        //

        //
        // kdf_a_loop_e loop 4
        //
        // Ingress:
        //      aWaterLaneC (-->), aWaterLaneA (-->), aSource (-->), aOperationLaneA (<-?->)
        //
        // Cross:
        //      aWaterLaneB (<--), aWindLaneC (<--), aFireLaneB (<-?->)
        //
        // Destination:
        //      aWaterLaneD
        //
    }
}

void TwistExpander_Antares_Arx::KDF_B_A() {
    // [kdf-a arx]
    // GSeedRunKDF_B_A kdf_b_loop_a (start)
    {
        //
        // kdf_b_loop_a loop 1
        //
        // Ingress:
        //      aWaterLaneA (-->), aWaterLaneB (-->), aWindLaneD (-->), aWindLaneB (<-?->)
        //
        // Cross:
        //      aWaterLaneC (<--), aWaterLaneD (<--), aFireLaneB (<-?->)
        //
        // Destination:
        //      aScrapLaneA
        //

        //
        // kdf_b_loop_a loop 2
        //
        // Ingress:
        //      aScrapLaneA (-->), aWaterLaneC (-->), aFireLaneD (-->), aOperationLaneB (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWaterLaneD (<--), aSource (<-?->)
        //
        // Destination:
        //      aScrapLaneB
        //

        //
        // kdf_b_loop_a loop 3
        //
        // Ingress:
        //      aScrapLaneB (-->), aWaterLaneD (-->), aWindLaneA (-->), aFireLaneC (<-?->)
        //
        // Cross:
        //      aScrapLaneA (<--), aWaterLaneB (<--), aOperationLaneD (<-?->)
        //
        // Destination:
        //      aScrapLaneC
        //

        //
        // kdf_b_loop_a loop 4
        //
        // Ingress:
        //      aScrapLaneC (-->), aScrapLaneA (-->), aWindLaneC (-->), aOperationLaneA (<-?->)
        //
        // Cross:
        //      aScrapLaneB (<--), aWaterLaneC (<--), aOperationLaneC (<-?->)
        //
        // Destination:
        //      aScrapLaneD
        //
    }
}

void TwistExpander_Antares_Arx::KDF_B_B() {
    // [kdf-a arx]
    // GSeedRunKDF_B_B kdf_b_loop_b (start)
    {
        //
        // kdf_b_loop_b loop 1
        //
        // Ingress:
        //      aScrapLaneA (-->), aScrapLaneB (-->), aSource (-->), aWaterLaneB (<-?->)
        //
        // Cross:
        //      aScrapLaneC (<--), aScrapLaneD (<--), aWindLaneD (<--), aFireLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneA
        //
        
        //
        // kdf_b_loop_b loop 2
        //
        // Ingress:
        //      aOperationLaneA (-->), aScrapLaneC (-->), aWindLaneC (-->), aWaterLaneA (<-?->)
        //
        // Cross:
        //      aScrapLaneA (<--), aScrapLaneD (<--), aWindLaneB (<--), aWaterLaneC (<-?->)
        //
        // Destination:
        //      aOperationLaneB
        //
        
        //
        // kdf_b_loop_b loop 3
        //
        // Ingress:
        //      aOperationLaneB (-->), aScrapLaneD (-->), aEarthLaneA (-->), aEarthLaneC (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aScrapLaneB (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneC
        //

        //
        // kdf_b_loop_b loop 4
        //
        // Ingress:
        //      aOperationLaneC (-->), aOperationLaneA (-->), aWaterLaneD (-->), aEarthLaneB (<-?->)
        //
        // Cross:
        //      aOperationLaneB (<--), aScrapLaneC (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aOperationLaneD
        //
    }
}

void TwistExpander_Antares_Arx::KDF_B_C() {
    // [kdf-a arx]
    // GSeedRunKDF_B_C kdf_b_loop_c (start)
    {
        //
        // kdf_b_loop_c loop 1
        //
        // Ingress:
        //      aOperationLaneA (-->), aOperationLaneB (-->), aFireLaneD (-->), aWindLaneC (<-?->)
        //
        // Cross:
        //      aOperationLaneC (<--), aOperationLaneD (<--), aWaterLaneA (<--), aScrapLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //

        //
        // kdf_b_loop_c loop 2
        //
        // Ingress:
        //      aFuseLaneA (-->), aOperationLaneC (-->), aScrapLaneA (-->), aFireLaneB (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aOperationLaneD (<--), aWindLaneA (<--), aScrapLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //

        //
        // kdf_b_loop_c loop 3
        //
        // Ingress:
        //      aFuseLaneB (-->), aOperationLaneD (-->), aWaterLaneB (-->), aFireLaneA (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aOperationLaneB (<--), aWaterLaneD (<--), aFireLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //

        //
        // kdf_b_loop_c loop 4
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aWindLaneD (-->), aScrapLaneC (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aOperationLaneC (<--), aWaterLaneC (<--), aWindLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
    }
}

void TwistExpander_Antares_Arx::KDF_B_D() {
    // [kdf-a arx]
    // GSeedRunKDF_B_D kdf_b_loop_d (start)
    {
        //
        // kdf_b_loop_d loop 1
        //
        // Ingress:
        //      aWorkLaneA (-->), aWorkLaneB (-->), aScrapLaneA (-->), aWaterLaneA (<-?->)
        //
        // Cross:
        //      aWorkLaneC (<--), aWorkLaneD (<--), aOperationLaneB (<--), aWindLaneB (<-?->)
        //
        // Destination:
        //      aExpandLaneA
        //

        //
        // kdf_b_loop_d loop 2
        //
        // Ingress:
        //      aExpandLaneA (-->), aWorkLaneC (-->), aWindLaneC (-->), aWaterLaneD (<-?->)
        //
        // Cross:
        //      aWorkLaneA (<--), aWorkLaneD (<--), aOperationLaneC (<--), aScrapLaneC (<-?->)
        //
        // Destination:
        //      aExpandLaneB
        //

        //
        // kdf_b_loop_d loop 3
        //
        // Ingress:
        //      aExpandLaneB (-->), aWorkLaneD (-->), aScrapLaneD (-->), aSource (<-?->)
        //
        // Cross:
        //      aExpandLaneA (<--), aWorkLaneB (<--), aWindLaneD (<--), aWaterLaneB (<-?->)
        //
        // Destination:
        //      aExpandLaneC
        //

        //
        // kdf_b_loop_d loop 4
        //
        // Ingress:
        //      aExpandLaneC (-->), aExpandLaneA (-->), aWaterLaneC (-->), aOperationLaneA (<-?->)
        //
        // Cross:
        //      aExpandLaneB (<--), aWorkLaneC (<--), aScrapLaneB (<--), aOperationLaneD (<-?->)
        //
        // Destination:
        //      aExpandLaneD
        //
    }
}

void TwistExpander_Antares_Arx::Seed_A() {
    
    // [seed arx]
    // GSeedRunSeed_A seed_loop_a (start)
    {
        //
        // seed_loop_a loop 1
        //
        // Ingress:
        //      aSource (-->), aKeyRowReadA (-->)
        //
        // Cross:
        //      aSource (<--), aKeyRowReadB (<--)
        //
        // Destination:
        //      aWorkLaneA
        //

        //
        // seed_loop_a loop 2
        //
        // Ingress:
        //      aWorkLaneA (-->), aKeyRowReadB (-->)
        //
        // Cross:
        //      aSource (<--), aKeyRowReadA (<--)
        //
        // Destination:
        //      aWorkLaneB
        //

        //
        // seed_loop_a loop 3
        //
        // Ingress:
        //      aWorkLaneB (-->), aSource (-->), aKeyRowReadB (-->)
        //
        // Cross:
        //      aKeyRowReadA (<--), aWorkLaneA (<-?->)
        //
        // Destination:
        //      aExpandLaneA
        //

        //
        // seed_loop_a loop 4
        //
        // Ingress:
        //      aExpandLaneA (-->), aWorkLaneA (<-?->)
        //
        // Cross:
        //      aWorkLaneB (<--), aKeyRowReadB (<-?->)
        //
        // Destination:
        //      aExpandLaneB
        //

        //
        // seed_loop_a loop 5
        //
        // Ingress:
        //      aExpandLaneB (-->), aWorkLaneB (<-?->)
        //
        // Cross:
        //      aExpandLaneA (<--), aKeyRowReadA (<-?->)
        //
        // Destination:
        //      aExpandLaneC
        //

        //
        // seed_loop_a loop 6
        //
        // Ingress:
        //      aExpandLaneC (-->), aExpandLaneA (<-?->)
        //
        // Cross:
        //      aExpandLaneB (<--), aWorkLaneB (<-?->)
        //
        // Destination:
        //      aExpandLaneD
        //
    }
}

void TwistExpander_Antares_Arx::Seed_B() {
    // [seed arx]
    // GSeedRunSeed_B seed_loop_e (start)
    {
        //
        // seed_loop_e loop 1
        //
        // Ingress:
        //      aExpandLaneA (-->), aExpandLaneB (-->), aKeyRowReadB (<-?->)
        //
        // Cross:
        //      aExpandLaneC (<--), aExpandLaneD (<-?->)
        //
        // Destination:
        //      aWorkLaneC
        //

        //
        // seed_loop_e loop 2
        //
        // Ingress:
        //      aWorkLaneC (-->), aExpandLaneC (-->), aWorkLaneA (<-?->)
        //
        // Cross:
        //      aExpandLaneA (<--), aExpandLaneD (<--)
        //
        // Destination:
        //      aWorkLaneD
        //

        //
        // seed_loop_e loop 3
        //
        // Ingress:
        //      aWorkLaneD (-->), aExpandLaneA (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aWorkLaneC (<--), aExpandLaneC (<-?->)
        //
        // Destination:
        //      aEarthLaneA
        //

        //
        // seed_loop_e loop 4
        //
        // Ingress:
        //      aEarthLaneA (-->), aExpandLaneD (-->), aWorkLaneB (<-?->)
        //
        // Cross:
        //      aWorkLaneD (<--), aExpandLaneA (<-?->)
        //
        // Destination:
        //      aEarthLaneB
        //

        //
        // seed_loop_e loop 5
        //
        // Ingress:
        //      aEarthLaneB (-->), aWorkLaneD (-->), aSource (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aWorkLaneC (<-?->)
        //
        // Destination:
        //      aEarthLaneC
        //

        //
        // seed_loop_e loop 6
        //
        // Ingress:
        //      aEarthLaneC (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aEarthLaneB (<--), aExpandLaneB (<--)
        //
        // Destination:
        //      aEarthLaneD
        //
    }
}

void TwistExpander_Antares_Arx::Seed_C() {
    // [seed arx]
    // GSeedRunSeed_C seed_loop_d (start)
    {
        //
        // seed_loop_d loop 1
        //
        // Ingress:
        //      aEarthLaneA (-->), aEarthLaneB (-->), aWorkLaneD (<-?->)
        //
        // Cross:
        //      aEarthLaneC (<--), aEarthLaneD (<--), aExpandLaneA (<-?->)
        //
        // Destination:
        //      aScrapLaneA
        //

        //
        // seed_loop_d loop 2
        //
        // Ingress:
        //      aScrapLaneA (-->), aEarthLaneC (-->), aWorkLaneA (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aEarthLaneD (<--), aExpandLaneC (<-?->)
        //
        // Destination:
        //      aScrapLaneB
        //

        //
        // seed_loop_d loop 3
        //
        // Ingress:
        //      aScrapLaneB (-->), aEarthLaneA (-->), aSource (<-?->)
        //
        // Cross:
        //      aScrapLaneA (<--), aEarthLaneC (<--), aExpandLaneB (<-?->)
        //
        // Destination:
        //      aOperationLaneA
        //

        //
        // seed_loop_d loop 4
        //
        // Ingress:
        //      aOperationLaneA (-->), aEarthLaneD (-->), aWorkLaneB (<-?->)
        //
        // Cross:
        //      aScrapLaneB (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneB
        //

        //
        // seed_loop_d loop 5
        //
        // Ingress:
        //      aOperationLaneB (-->), aScrapLaneB (-->), aWorkLaneC (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aScrapLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneC
        //

        //
        // seed_loop_d loop 6
        //
        // Ingress:
        //      aOperationLaneC (-->), aOperationLaneA (-->), aExpandLaneD (<-?->)
        //
        // Cross:
        //      aOperationLaneB (<--), aEarthLaneB (<--)
        //
        // Destination:
        //      aOperationLaneD
        //
    }
}

void TwistExpander_Antares_Arx::Seed_D() {
    
    // [seed arx]
    // GSeedRunSeed_D seed_loop_c (start)
    {
        //
        // seed_loop_c loop 1
        //
        // Ingress:
        //      aOperationLaneA (-->), aOperationLaneB (-->), aExpandLaneB (<-?->)
        //
        // Cross:
        //      aOperationLaneC (<--), aOperationLaneD (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aScrapLaneC
        //

        //
        // seed_loop_c loop 2
        //
        // Ingress:
        //      aScrapLaneC (-->), aOperationLaneC (-->), aScrapLaneA (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aOperationLaneD (<--), aScrapLaneB (<-?->)
        //
        // Destination:
        //      aScrapLaneD
        //

        //
        // seed_loop_c loop 3
        //
        // Ingress:
        //      aScrapLaneD (-->), aOperationLaneA (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aScrapLaneC (<--), aOperationLaneC (<--), aKeyRowReadA (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //

        //
        // seed_loop_c loop 4
        //
        // Ingress:
        //      aFuseLaneA (-->), aOperationLaneD (-->), aWorkLaneD (<-?->)
        //
        // Cross:
        //      aScrapLaneD (<--), aOperationLaneA (<--), aExpandLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //

        //
        // seed_loop_c loop 5
        //
        // Ingress:
        //      aFuseLaneB (-->), aScrapLaneD (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aScrapLaneC (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //

        //
        // seed_loop_c loop 6
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aExpandLaneD (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aOperationLaneB (<--), aExpandLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
    }
}

void TwistExpander_Antares_Arx::Seed_E() {
    
    // [seed arx]
    // GSeedRunSeed_E seed_loop_b (start)
    {
        //
        // seed_loop_b loop 1
        //
        // Ingress:
        //      aFireLaneA (-->), aFireLaneB (-->), aEarthLaneC (-->), aKeyRowReadB (<-?->)
        //
        // Cross:
        //      aFireLaneC (<--), aFireLaneD (<--), aScrapLaneC (<-?->)
        //
        // Destination:
        //      aWaterLaneC
        //

        //
        // seed_loop_b loop 2
        //
        // Ingress:
        //      aWaterLaneC (-->), aFireLaneC (-->), aOperationLaneB (-->), aScrapLaneD (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aWaterLaneD
        //

        //
        // seed_loop_b loop 3
        //
        // Ingress:
        //      aWaterLaneD (-->), aFireLaneA (-->), aOperationLaneA (<-?->)
        //
        // Cross:
        //      aWaterLaneC (<--), aFireLaneC (<--), aWorkLaneC (<-?->)
        //
        // Destination:
        //      aInvestLaneA
        //

        //
        // seed_loop_b loop 4
        //
        // Ingress:
        //      aInvestLaneA (-->), aFireLaneD (-->), aOperationLaneD (<-?->)
        //
        // Cross:
        //      aWaterLaneD (<--), aFireLaneA (<--), aScrapLaneB (<-?->)
        //
        // Destination:
        //      aInvestLaneB
        //

        //
        // seed_loop_b loop 5
        //
        // Ingress:
        //      aInvestLaneB (-->), aWaterLaneD (-->), aOperationLaneC (<-?->)
        //
        // Cross:
        //      aInvestLaneA (<--), aWaterLaneC (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aInvestLaneC
        //

        //
        // seed_loop_b loop 6
        //
        // Ingress:
        //      aInvestLaneC (-->), aInvestLaneA (-->), aEarthLaneB (<-?->)
        //
        // Cross:
        //      aInvestLaneB (<--), aFireLaneB (<--), aScrapLaneA (<-?->)
        //
        // Destination:
        //      aInvestLaneD
        //
    }
}

void TwistExpander_Antares_Arx::Seed_F() {
    // [seed arx]
    // GSeedRunSeed_F seed_loop_c (start)
    {
        //
        // seed_loop_c loop 1
        //
        // Ingress:
        //      aInvestLaneA (-->), aInvestLaneB (-->), aOperationLaneB (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aInvestLaneC (<--), aInvestLaneD (<--), aOperationLaneA (<-?->)
        //
        // Destination:
        //      aSnowLaneC
        //

        //
        // seed_loop_c loop 2
        //
        // Ingress:
        //      aSnowLaneC (-->), aInvestLaneC (-->), aFireLaneD (-->), aFireLaneA (<-?->)
        //
        // Cross:
        //      aInvestLaneA (<--), aInvestLaneD (<--), aScrapLaneA (<-?->)
        //
        // Destination:
        //      aSnowLaneD
        //

        //
        // seed_loop_c loop 3
        //
        // Ingress:
        //      aSnowLaneD (-->), aInvestLaneA (-->), aScrapLaneD (-->), aWaterLaneD (<-?->)
        //
        // Cross:
        //      aSnowLaneC (<--), aInvestLaneC (<--), aWaterLaneC (<-?->)
        //
        // Destination:
        //      aWindLaneA
        //

        //
        // seed_loop_c loop 4
        //
        // Ingress:
        //      aWindLaneA (-->), aInvestLaneD (-->), aScrapLaneC (-->), aFireLaneB (<-?->)
        //
        // Cross:
        //      aSnowLaneD (<--), aInvestLaneA (<--), aOperationLaneC (<-?->)
        //
        // Destination:
        //      aWindLaneB
        //

        //
        // seed_loop_c loop 5
        //
        // Ingress:
        //      aWindLaneB (-->), aSnowLaneD (-->), aSource (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aSnowLaneC (<--), aOperationLaneD (<-?->)
        //
        // Destination:
        //      aWindLaneC
        //

        //
        // seed_loop_c loop 6
        //
        // Ingress:
        //      aWindLaneC (-->), aWindLaneA (-->), aScrapLaneB (<-?->)
        //
        // Cross:
        //      aWindLaneB (<--), aInvestLaneB (<--), aFireLaneC (<-?->)
        //
        // Destination:
        //      aWindLaneD
        //
    }
}

void TwistExpander_Antares_Arx::Seed_G() {
    // [seed arx]
    // GSeedRunSeed_G seed_loop_d (start)
    {
        //
        // seed_loop_d loop 1
        //
        // Ingress:
        //      aWindLaneA (-->), aWindLaneB (-->), aWaterLaneC (-->), aFireLaneA (<-?->)
        //
        // Cross:
        //      aWindLaneC (<--), aWindLaneD (<--), aInvestLaneC (<-?->)
        //
        // Destination:
        //      aWaterLaneA
        //

        //
        // seed_loop_d loop 2
        //
        // Ingress:
        //      aWaterLaneA (-->), aWindLaneC (-->), aEarthLaneB (-->), aWaterLaneD (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aWindLaneD (<--), aInvestLaneB (<-?->)
        //
        // Destination:
        //      aWaterLaneB
        //

        //
        // seed_loop_d loop 3
        //
        // Ingress:
        //      aWaterLaneB (-->), aWindLaneA (-->), aInvestLaneA (-->), aInvestLaneD (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWindLaneC (<--), aSnowLaneD (<-?->)
        //
        // Destination:
        //      aOperationLaneA
        //

        //
        // seed_loop_d loop 4
        //
        // Ingress:
        //      aOperationLaneA (-->), aWindLaneD (-->), aEarthLaneA (-->), aScrapLaneD (<-?->)
        //
        // Cross:
        //      aWaterLaneB (<--), aWindLaneA (<--), aScrapLaneC (<-?->)
        //
        // Destination:
        //      aOperationLaneB
        //

        //
        // seed_loop_d loop 5
        //
        // Ingress:
        //      aOperationLaneB (-->), aWaterLaneB (-->), aFireLaneB (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aWaterLaneA (<--), aSnowLaneC (<-?->)
        //
        // Destination:
        //      aOperationLaneC
        //

        //
        // seed_loop_d loop 6
        //
        // Ingress:
        //      aOperationLaneC (-->), aOperationLaneA (-->), aEarthLaneC (-->), aFireLaneD (<-?->)
        //
        // Cross:
        //      aOperationLaneB (<--), aWindLaneB (<--), aFireLaneC (<-?->)
        //
        // Destination:
        //      aOperationLaneD
        //
    }
}

void TwistExpander_Antares_Arx::Seed_H() {
    
    // [seed arx]
    // GSeedRunSeed_H seed_loop_e (start)
    {
        //
        // seed_loop_e loop 1
        //
        // Ingress:
        //      aOperationLaneA (-->), aOperationLaneB (-->), aFireLaneB (-->), aWindLaneD (<-?->)
        //
        // Cross:
        //      aOperationLaneC (<--), aOperationLaneD (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aSnowLaneA
        //

        //
        // seed_loop_e loop 2
        //
        // Ingress:
        //      aSnowLaneA (-->), aOperationLaneC (-->), aWaterLaneB (-->), aInvestLaneD (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aOperationLaneD (<--), aInvestLaneB (<-?->)
        //
        // Destination:
        //      aSnowLaneB
        //

        //
        // seed_loop_e loop 3
        //
        // Ingress:
        //      aSnowLaneB (-->), aOperationLaneA (-->), aKeyRowReadB (-->), aInvestLaneA (<-?->)
        //
        // Cross:
        //      aSnowLaneA (<--), aOperationLaneC (<--), aExpandLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //

        //
        // seed_loop_e loop 4
        //
        // Ingress:
        //      aFuseLaneA (-->), aOperationLaneD (-->), aWaterLaneA (-->), aWindLaneA (<-?->)
        //
        // Cross:
        //      aSnowLaneB (<--), aOperationLaneA (<--), aInvestLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //

        //
        // seed_loop_e loop 5
        //
        // Ingress:
        //      aFuseLaneB (-->), aSnowLaneB (-->), aWindLaneB (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aSnowLaneA (<--), aSnowLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //

        //
        // seed_loop_e loop 6
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aSnowLaneD (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aOperationLaneB (<--), aFireLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
    }
}

void TwistExpander_Antares_Arx::Seed_I() {
    
    // [seed arx]
    // GSeedRunSeed_I seed_loop_f (start)
    {
        //
        // seed_loop_f loop 1
        //
        // Ingress:
        //      aInvestLaneE (-->), aInvestLaneF (-->), aWaterLaneB (-->), aOperationLaneB (<-?->)
        //
        // Cross:
        //      aInvestLaneG (<--), aInvestLaneH (<--), aExpandLaneB (<-?->)
        //
        // Destination:
        //      aSnowLaneC
        //

        //
        // seed_loop_f loop 2
        //
        // Ingress:
        //      aSnowLaneC (-->), aInvestLaneG (-->), aWindLaneD (-->), aOperationLaneC (<-?->)
        //
        // Cross:
        //      aInvestLaneE (<--), aInvestLaneH (<--), aWindLaneB (<-?->)
        //
        // Destination:
        //      aSnowLaneD
        //

        //
        // seed_loop_f loop 3
        //
        // Ingress:
        //      aSnowLaneD (-->), aInvestLaneE (-->), aFireLaneC (-->), aWindLaneC (<-?->)
        //
        // Cross:
        //      aSnowLaneC (<--), aInvestLaneG (<--), aWaterLaneA (<-?->)
        //
        // Destination:
        //      aWorkLaneA
        //

        //
        // seed_loop_f loop 4
        //
        // Ingress:
        //      aWorkLaneA (-->), aInvestLaneH (-->), aSnowLaneA (-->), aFireLaneD (<-?->)
        //
        // Cross:
        //      aSnowLaneD (<--), aInvestLaneE (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aWorkLaneB
        //

        //
        // seed_loop_f loop 5
        //
        // Ingress:
        //      aWorkLaneB (-->), aSnowLaneD (-->), aOperationLaneD (<-?->)
        //
        // Cross:
        //      aWorkLaneA (<--), aSnowLaneC (<--), aExpandLaneA (<-?->)
        //
        // Destination:
        //      aWorkLaneC
        //

        //
        // seed_loop_f loop 6
        //
        // Ingress:
        //      aWorkLaneC (-->), aWorkLaneA (-->), aSnowLaneB (<-?->)
        //
        // Cross:
        //      aWorkLaneB (<--), aInvestLaneF (<--), aOperationLaneA (<-?->)
        //
        // Destination:
        //      aWorkLaneD
        //
    }
}

void TwistExpander_Antares_Arx::Twist_A() {
    // [twist arx]
    // GTwistRunTwist_A twist_loop_a (start)
    {
        //
        // twist_loop_a loop 1
        //
        // Ingress:
        //      aSource (-->), aKeyRowReadA (-->)
        //
        // Cross:
        //      aSource (<--), aKeyRowReadB (<--)
        //
        // Destination:
        //      aScrapLaneA
        //

        //
        // twist_loop_a loop 2
        //
        // Ingress:
        //      aScrapLaneA (-->), aKeyRowReadB (-->)
        //
        // Cross:
        //      aSource (<--), aKeyRowReadA (<--)
        //
        // Destination:
        //      aScrapLaneB
        //

        //
        // twist_loop_a loop 3
        //
        // Ingress:
        //      aScrapLaneB (-->), aSource (-->), aKeyRowReadB (-->)
        //
        // Cross:
        //      aKeyRowReadA (<--), aScrapLaneA (<-?->)
        //
        // Destination:
        //      aWindLaneA
        //

        //
        // twist_loop_a loop 4
        //
        // Ingress:
        //      aWindLaneA (-->), aScrapLaneA (<-?->)
        //
        // Cross:
        //      aScrapLaneB (<--), aKeyRowReadB (<-?->)
        //
        // Destination:
        //      aWindLaneB
        //

        //
        // twist_loop_a loop 5
        //
        // Ingress:
        //      aWindLaneB (-->), aScrapLaneB (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aKeyRowReadA (<-?->)
        //
        // Destination:
        //      aWindLaneC
        //

        //
        // twist_loop_a loop 6
        //
        // Ingress:
        //      aWindLaneC (-->), aWindLaneA (<-?->)
        //
        // Cross:
        //      aWindLaneB (<--), aScrapLaneB (<-?->)
        //
        // Destination:
        //      aWindLaneD
        //
    }
}

void TwistExpander_Antares_Arx::Twist_B() {
    // [twist arx]
    // GTwistRunTwist_B twist_loop_b (start)
    {
        //
        // twist_loop_b loop 1
        //
        // Ingress:
        //      aWindLaneA (-->), aWindLaneB (-->), aKeyRowReadB (<-?->)
        //
        // Cross:
        //      aWindLaneC (<--), aWindLaneD (<-?->)
        //
        // Destination:
        //      aWorkLaneA
        //

        //
        // twist_loop_b loop 2
        //
        // Ingress:
        //      aWorkLaneA (-->), aWindLaneC (-->), aScrapLaneA (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aWindLaneD (<--)
        //
        // Destination:
        //      aWorkLaneB
        //

        //
        // twist_loop_b loop 3
        //
        // Ingress:
        //      aWorkLaneB (-->), aWindLaneA (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aWorkLaneA (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aSnowLaneA
        //

        //
        // twist_loop_b loop 4
        //
        // Ingress:
        //      aSnowLaneA (-->), aWindLaneD (-->), aScrapLaneB (<-?->)
        //
        // Cross:
        //      aWorkLaneB (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aSnowLaneB
        //

        //
        // twist_loop_b loop 5
        //
        // Ingress:
        //      aSnowLaneB (-->), aWorkLaneB (-->), aSource (<-?->)
        //
        // Cross:
        //      aSnowLaneA (<--), aWorkLaneA (<-?->)
        //
        // Destination:
        //      aSnowLaneC
        //

        //
        // twist_loop_b loop 6
        //
        // Ingress:
        //      aSnowLaneC (-->), aSnowLaneA (<-?->)
        //
        // Cross:
        //      aSnowLaneB (<--), aWindLaneB (<--)
        //
        // Destination:
        //      aSnowLaneD
        //
    }
}

void TwistExpander_Antares_Arx::Twist_C() {
    // [twist arx]
    // GTwistRunTwist_C twist_loop_c (start)
    {
        //
        // twist_loop_c loop 1
        //
        // Ingress:
        //      aSnowLaneA (-->), aSnowLaneB (-->), aWindLaneB (<-?->)
        //
        // Cross:
        //      aSnowLaneC (<--), aSnowLaneD (<--), aScrapLaneB (<-?->)
        //
        // Destination:
        //      aInvestLaneA
        //

        //
        // twist_loop_c loop 2
        //
        // Ingress:
        //      aInvestLaneA (-->), aSnowLaneC (-->), aSource (<-?->)
        //
        // Cross:
        //      aSnowLaneA (<--), aSnowLaneD (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aInvestLaneB
        //

        //
        // twist_loop_c loop 3
        //
        // Ingress:
        //      aInvestLaneB (-->), aSnowLaneA (-->), aWindLaneD (<-?->)
        //
        // Cross:
        //      aInvestLaneA (<--), aSnowLaneC (<--), aWorkLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneA
        //

        //
        // twist_loop_c loop 4
        //
        // Ingress:
        //      aOperationLaneA (-->), aSnowLaneD (-->), aWindLaneC (<-?->)
        //
        // Cross:
        //      aInvestLaneB (<--), aSnowLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneB
        //

        //
        // twist_loop_c loop 5
        //
        // Ingress:
        //      aOperationLaneB (-->), aInvestLaneB (-->), aWorkLaneB (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aInvestLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneC
        //

        //
        // twist_loop_c loop 6
        //
        // Ingress:
        //      aOperationLaneC (-->), aOperationLaneA (-->), aScrapLaneA (<-?->)
        //
        // Cross:
        //      aOperationLaneB (<--), aSnowLaneB (<--)
        //
        // Destination:
        //      aOperationLaneD
        //
    }
}

void TwistExpander_Antares_Arx::Twist_D() {
    // [twist arx]
    // GTwistRunTwist_D twist_loop_d (start)
    {
        //
        // twist_loop_d loop 1
        //
        // Ingress:
        //      aOperationLaneA (-->), aOperationLaneB (-->), aSnowLaneB (<-?->)
        //
        // Cross:
        //      aOperationLaneC (<--), aOperationLaneD (<--), aWindLaneD (<-?->)
        //
        // Destination:
        //      aScrapLaneC
        //

        //
        // twist_loop_d loop 2
        //
        // Ingress:
        //      aScrapLaneC (-->), aOperationLaneC (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aOperationLaneD (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aScrapLaneD
        //

        //
        // twist_loop_d loop 3
        //
        // Ingress:
        //      aScrapLaneD (-->), aOperationLaneA (-->), aInvestLaneB (<-?->)
        //
        // Cross:
        //      aScrapLaneC (<--), aOperationLaneC (<--), aInvestLaneA (<-?->)
        //
        // Destination:
        //      aWaterLaneA
        //

        //
        // twist_loop_d loop 4
        //
        // Ingress:
        //      aWaterLaneA (-->), aOperationLaneD (-->), aSnowLaneD (<-?->)
        //
        // Cross:
        //      aScrapLaneD (<--), aOperationLaneA (<--), aSnowLaneC (<-?->)
        //
        // Destination:
        //      aWaterLaneB
        //

        //
        // twist_loop_d loop 5
        //
        // Ingress:
        //      aWaterLaneB (-->), aScrapLaneD (-->), aSnowLaneA (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aScrapLaneC (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aWaterLaneC
        //

        //
        // twist_loop_d loop 6
        //
        // Ingress:
        //      aWaterLaneC (-->), aWaterLaneA (-->), aWindLaneB (<-?->)
        //
        // Cross:
        //      aWaterLaneB (<--), aOperationLaneB (<--)
        //
        // Destination:
        //      aWaterLaneD
        //
    }
}

void TwistExpander_Antares_Arx::Twist_E() {
    // [twist arx]
    // GTwistRunTwist_E twist_loop_e (start)
    {
        //
        // twist_loop_e loop 1
        //
        // Ingress:
        //      aWaterLaneA (-->), aWaterLaneB (-->), aOperationLaneC (<-?->)
        //
        // Cross:
        //      aWaterLaneC (<--), aWaterLaneD (<--), aScrapLaneC (<-?->)
        //
        // Destination:
        //      aInvestLaneC
        //

        //
        // twist_loop_e loop 2
        //
        // Ingress:
        //      aInvestLaneC (-->), aWaterLaneC (-->), aSnowLaneD (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWaterLaneD (<--), aOperationLaneA (<-?->)
        //
        // Destination:
        //      aInvestLaneD
        //

        //
        // twist_loop_e loop 3
        //
        // Ingress:
        //      aInvestLaneD (-->), aWaterLaneA (-->), aSnowLaneA (<-?->)
        //
        // Cross:
        //      aInvestLaneC (<--), aWaterLaneC (<--), aSnowLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //

        //
        // twist_loop_e loop 4
        //
        // Ingress:
        //      aFuseLaneA (-->), aWaterLaneD (-->), aInvestLaneA (<-?->)
        //
        // Cross:
        //      aInvestLaneD (<--), aWaterLaneA (<--), aOperationLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //

        //
        // twist_loop_e loop 5
        //
        // Ingress:
        //      aFuseLaneB (-->), aInvestLaneD (-->), aKeyRowReadB (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aInvestLaneC (<--), aScrapLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //

        //
        // twist_loop_e loop 6
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aOperationLaneD (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aWaterLaneB (<--), aSnowLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
    }
}

void TwistExpander_Antares_Arx::Twist_F() {
    // [twist arx]
    // GTwistRunTwist_F twist_loop_f (start)
    {
        //
        // twist_loop_f loop 1
        //
        // Ingress:
        //      aFireLaneA (-->), aFireLaneB (-->), aScrapLaneD (-->), aOperationLaneC (<-?->)
        //
        // Cross:
        //      aFireLaneC (<--), aFireLaneD (<--), aScrapLaneC (<-?->)
        //
        // Destination:
        //      aInvestLaneE
        //

        //
        // twist_loop_f loop 2
        //
        // Ingress:
        //      aInvestLaneE (-->), aFireLaneC (-->), aWaterLaneD (-->), aOperationLaneD (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), aOperationLaneB (<-?->)
        //
        // Destination:
        //      aInvestLaneF
        //

        //
        // twist_loop_f loop 3
        //
        // Ingress:
        //      aInvestLaneF (-->), aFireLaneA (-->), aSnowLaneB (-->), aSource (<-?->)
        //
        // Cross:
        //      aInvestLaneE (<--), aFireLaneC (<--), aInvestLaneD (<-?->)
        //
        // Destination:
        //      aEarthLaneA
        //

        //
        // twist_loop_f loop 4
        //
        // Ingress:
        //      aEarthLaneA (-->), aFireLaneD (-->), aInvestLaneC (-->), aWaterLaneC (<-?->)
        //
        // Cross:
        //      aInvestLaneF (<--), aFireLaneA (<--), aSnowLaneA (<-?->)
        //
        // Destination:
        //      aEarthLaneB
        //

        //
        // twist_loop_f loop 5
        //
        // Ingress:
        //      aEarthLaneB (-->), aInvestLaneF (-->), aScrapLaneA (-->), aOperationLaneA (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aInvestLaneE (<--), aInvestLaneB (<-?->)
        //
        // Destination:
        //      aEarthLaneC
        //

        //
        // twist_loop_f loop 6
        //
        // Ingress:
        //      aEarthLaneC (-->), aEarthLaneA (-->), aScrapLaneB (-->), aWaterLaneA (<-?->)
        //
        // Cross:
        //      aEarthLaneB (<--), aFireLaneB (<--), aWaterLaneB (<-?->)
        //
        // Destination:
        //      aEarthLaneD
        //
    }
}

void TwistExpander_Antares_Arx::Twist_G() {
    // [twist arx]
    // GTwistRunTwist_G twist_loop_g (start)
    {
        //
        // twist_loop_g loop 1
        //
        // Ingress:
        //      aEarthLaneA (-->), aEarthLaneB (-->), aSnowLaneD (-->), aWaterLaneC (<-?->)
        //
        // Cross:
        //      aEarthLaneC (<--), aEarthLaneD (<--), aInvestLaneC (<-?->)
        //
        // Destination:
        //      aInvestLaneG
        //

        //
        // twist_loop_g loop 2
        //
        // Ingress:
        //      aInvestLaneG (-->), aEarthLaneC (-->), aWaterLaneA (-->), aInvestLaneE (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aEarthLaneD (<--), aFireLaneC (<-?->)
        //
        // Destination:
        //      aInvestLaneH
        //

        //
        // twist_loop_g loop 3
        //
        // Ingress:
        //      aInvestLaneH (-->), aEarthLaneA (-->), aInvestLaneF (-->), aFireLaneA (<-?->)
        //
        // Cross:
        //      aInvestLaneG (<--), aEarthLaneC (<--), aWaterLaneB (<-?->)
        //
        // Destination:
        //      aWorkLaneA
        //

        //
        // twist_loop_g loop 4
        //
        // Ingress:
        //      aWorkLaneA (-->), aEarthLaneD (-->), aInvestLaneA (-->), aFireLaneD (<-?->)
        //
        // Cross:
        //      aInvestLaneH (<--), aEarthLaneA (<--), aSnowLaneC (<-?->)
        //
        // Destination:
        //      aWorkLaneB
        //

        //
        // twist_loop_g loop 5
        //
        // Ingress:
        //      aWorkLaneB (-->), aInvestLaneH (-->), aInvestLaneD (-->), aWaterLaneD (<-?->)
        //
        // Cross:
        //      aWorkLaneA (<--), aInvestLaneG (<--), aKeyRowReadB (<-?->)
        //
        // Destination:
        //      aWorkLaneC
        //

        //
        // twist_loop_g loop 6
        //
        // Ingress:
        //      aWorkLaneC (-->), aWorkLaneA (-->), aFireLaneB (-->), aInvestLaneB (<-?->)
        //
        // Cross:
        //      aWorkLaneB (<--), aEarthLaneB (<--), aKeyRowReadA (<-?->)
        //
        // Destination:
        //      aWorkLaneD
        //
    }
}

void TwistExpander_Antares_Arx::GROW_A() {
    // [grow arx]
    // GROW_A grow_key_a (start)
    {
        //
        // grow_key_a loop 1
        //
        // Ingress:
        //      aWorkLaneA (-->), aWorkLaneB (-->), aFireLaneB (-->), aWaterLaneA (<-?->)
        //
        // Cross:
        //      aWorkLaneC (<--), aWorkLaneD (<--), aInvestLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneB
        //

        //
        // grow_key_a loop 2
        //
        // Ingress:
        //      aOperationLaneB (-->), aWorkLaneC (-->), aInvestLaneE (-->), aFireLaneD (<-?->)
        //
        // Cross:
        //      aWorkLaneA (<--), aWorkLaneD (<--), aOperationLaneC (<-?->)
        //
        // Destination:
        //      aOperationLaneD
        //

        //
        // grow_key_a loop 3
        //
        // Ingress:
        //      aOperationLaneD (-->), aWorkLaneA (-->), aEarthLaneB (-->), aSnowLaneB (<-?->)
        //
        // Cross:
        //      aOperationLaneB (<--), aWorkLaneC (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aExpandLaneA
        //

        //
        // grow_key_a loop 4
        //
        // Ingress:
        //      aExpandLaneA (-->), aWorkLaneD (-->), aScrapLaneD (-->), aInvestLaneB (<-?->)
        //
        // Cross:
        //      aOperationLaneD (<--), aWorkLaneA (<--), aScrapLaneA (<-?->)
        //
        // Destination:
        //      aExpandLaneB
        //

        //
        // grow_key_a loop 5
        //
        // Ingress:
        //      aExpandLaneB (-->), aOperationLaneD (-->), aWaterLaneC (-->), aScrapLaneC (<-?->)
        //
        // Cross:
        //      aExpandLaneA (<--), aOperationLaneB (<--), aScrapLaneB (<-?->)
        //
        // Destination:
        //      aExpandLaneC
        //

        //
        // grow_key_a loop 6
        //
        // Ingress:
        //      aExpandLaneC (-->), aExpandLaneA (-->), aSnowLaneD (-->), aOperationLaneA (<-?->)
        //
        // Cross:
        //      aExpandLaneB (<--), aWorkLaneB (<--), aInvestLaneF (<-?->)
        //
        // Destination:
        //      aExpandLaneD
        //
    }
}

void TwistExpander_Antares_Arx::GROW_B() {
    // [grow arx]
    // GROW_B grow_key_b (start)
    {
        //
        // grow_key_b loop 1
        //
        // Ingress:
        //      aExpandLaneA (-->), aExpandLaneB (-->), aFireLaneC (-->), aInvestLaneC (<-?->)
        //
        // Cross:
        //      aExpandLaneC (<--), aExpandLaneD (<--), aInvestLaneG (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //

        //
        // grow_key_b loop 2
        //
        // Ingress:
        //      aFuseLaneC (-->), aExpandLaneC (-->), aFireLaneA (-->), aEarthLaneC (<-?->)
        //
        // Cross:
        //      aExpandLaneA (<--), aExpandLaneD (<--), aWaterLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //

        //
        // grow_key_b loop 3
        //
        // Ingress:
        //      aFuseLaneD (-->), aExpandLaneA (-->), aInvestLaneH (-->), aOperationLaneD (<-?->)
        //
        // Cross:
        //      aFuseLaneC (<--), aExpandLaneC (<--), aWindLaneB (<-?->)
        //
        // Destination:
        //      aWorkLaneA
        //

        //
        // grow_key_b loop 4
        //
        // Ingress:
        //      aWorkLaneA (-->), aExpandLaneD (-->), aWindLaneD (-->), aInvestLaneD (<-?->)
        //
        // Cross:
        //      aFuseLaneD (<--), aExpandLaneA (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aWorkLaneB
        //

        //
        // grow_key_b loop 5
        //
        // Ingress:
        //      aWorkLaneB (-->), aFuseLaneD (-->), aSnowLaneA (-->), aWaterLaneD (<-?->)
        //
        // Cross:
        //      aWorkLaneA (<--), aFuseLaneC (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aWorkLaneC
        //

        //
        // grow_key_b loop 6
        //
        // Ingress:
        //      aWorkLaneC (-->), aWorkLaneA (-->), aSnowLaneC (-->), aOperationLaneB (<-?->)
        //
        // Cross:
        //      aWorkLaneB (<--), aExpandLaneB (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aWorkLaneD
        //
    }
}
