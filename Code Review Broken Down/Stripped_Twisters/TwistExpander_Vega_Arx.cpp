#include "TwistExpander_Vega_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Vega_Arx::KDF_A_A() {


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
        //      aPoisonLaneA
        //
        for (;;) {
            //
            aIngress = aSource[aIndex] ^ pSnow[aIndex];
            //
            aCross = pSnow[aIndex] ^ aSource[aIndex];
            //
            aPoisonLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_a loop 2
        //
        // Ingress:
        //      aPoisonLaneA (-->), aSource (-->)
        //
        // Cross:
        //      aPoisonLaneA (<--), pSnow (<--)
        //
        // Destination:
        //      aPoisonLaneB
        //
        for (;;) {
            //
            aIngress = aPoisonLaneA[aIndex] ^ aSource[aIndex];
            //
            aCross = aPoisonLaneA[aIndex] ^ pSnow[aIndex];
            //
            aPoisonLaneB[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_a loop 3
        //
        // Ingress:
        //      aPoisonLaneB (-->), aSource (<-?->)
        //
        // Cross:
        //      pSnow (<--), aPoisonLaneA (<-?->)
        //
        // Destination:
        //      aEarthLaneA
        //
        for (;;) {
            //
            aIngress = aPoisonLaneB[aIndex] ^ aSource[aIndex];
            //
            aCross = pSnow[aIndex] ^ aPoisonLaneA[aIndex];
            //
            aEarthLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_a loop 4
        //
        // Ingress:
        //      aEarthLaneA (-->), aPoisonLaneB (<-?->)
        //
        // Cross:
        //      aPoisonLaneA (<--), aSource (<-?->)
        //
        // Destination:
        //      aEarthLaneB
        //
        for (;;) {
            //
            aIngress = aEarthLaneA[aIndex] ^ aPoisonLaneB[aIndex];
            //
            aCross = aPoisonLaneA[aIndex] ^ aSource[aIndex];
            //
            aEarthLaneB[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_a loop 5
        //
        // Ingress:
        //      aEarthLaneB (-->), aPoisonLaneB (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), pSnow (<-?->)
        //
        // Destination:
        //      aEarthLaneC
        //
        for (;;) {
            //
            aIngress = aEarthLaneB[aIndex] ^ aPoisonLaneB[aIndex];
            //
            aCross = aEarthLaneA[aIndex] ^ pSnow[aIndex];
            //
            aEarthLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_a loop 6
        //
        // Ingress:
        //      aEarthLaneC (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aEarthLaneB (<--), aPoisonLaneA (<-?->)
        //
        // Destination:
        //      aEarthLaneD
        //
        for (;;) {
            //
            aIngress = aEarthLaneC[aIndex] ^ aEarthLaneA[aIndex];
            //
            aCross = aEarthLaneB[aIndex] ^ aPoisonLaneA[aIndex];
            //
            aEarthLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_A kdf_a_loop_a (end)

}

void TwistExpander_Vega_Arx::KDF_A_B() {


    // GSeedRunKDF_A_B kdf_a_loop_b (start)
    {
        //
        // kdf_a_loop_b loop 1
        //
        // Ingress:
        //      aEarthLaneA (-->), aEarthLaneB (-->), aPoisonLaneA (<-?->)
        //
        // Cross:
        //      aEarthLaneC (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aPoisonLaneC
        //
        for (;;) {
            //
            aIngress = aEarthLaneA[aIndex] ^ aEarthLaneB[aIndex];
            aIngress ^= aPoisonLaneA[aIndex];
            //
            aCross = aEarthLaneC[aIndex] ^ aEarthLaneD[aIndex];
            //
            aPoisonLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_b loop 2
        //
        // Ingress:
        //      aPoisonLaneC (-->), aEarthLaneC (-->), aSource (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aEarthLaneD (<--)
        //
        // Destination:
        //      aPoisonLaneD
        //
        for (;;) {
            //
            aIngress = aPoisonLaneC[aIndex] ^ aEarthLaneC[aIndex];
            aIngress ^= aSource[aIndex];
            //
            aCross = aEarthLaneA[aIndex] ^ aEarthLaneD[aIndex];
            //
            aPoisonLaneD[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_b loop 3
        //
        // Ingress:
        //      aPoisonLaneD (-->), aEarthLaneA (-->), aPoisonLaneB (<-?->)
        //
        // Cross:
        //      aPoisonLaneC (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aFireLaneA
        //
        for (;;) {
            //
            aIngress = aPoisonLaneD[aIndex] ^ aEarthLaneA[aIndex];
            aIngress ^= aPoisonLaneB[aIndex];
            //
            aCross = aPoisonLaneC[aIndex] ^ aEarthLaneC[aIndex];
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_b loop 4
        //
        // Ingress:
        //      aFireLaneA (-->), aEarthLaneD (-->), pSnow (<-?->)
        //
        // Cross:
        //      aPoisonLaneD (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aFireLaneB
        //
        for (;;) {
            //
            aIngress = aFireLaneA[aIndex] ^ aEarthLaneD[aIndex];
            aIngress ^= pSnow[aIndex];
            //
            aCross = aPoisonLaneD[aIndex] ^ aEarthLaneA[aIndex];
            //
            aFireLaneB[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_b loop 5
        //
        // Ingress:
        //      aFireLaneB (-->), aPoisonLaneD (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aPoisonLaneC (<-?->)
        //
        // Destination:
        //      aFireLaneC
        //
        for (;;) {
            //
            aIngress = aFireLaneB[aIndex] ^ aPoisonLaneD[aIndex];
            //
            aCross = aFireLaneA[aIndex] ^ aPoisonLaneC[aIndex];
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_b loop 6
        //
        // Ingress:
        //      aFireLaneC (-->), aFireLaneA (<-?->)
        //
        // Cross:
        //      aFireLaneB (<--), aEarthLaneB (<--)
        //
        // Destination:
        //      aFireLaneD
        //
        for (;;) {
            //
            aIngress = aFireLaneC[aIndex] ^ aFireLaneA[aIndex];
            //
            aCross = aFireLaneB[aIndex] ^ aEarthLaneB[aIndex];
            //
            aFireLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_B kdf_a_loop_b (end)

}

void TwistExpander_Vega_Arx::KDF_A_C() {


    // GSeedRunKDF_A_C kdf_a_loop_c (start)
    {
        //
        // kdf_a_loop_c loop 1
        //
        // Ingress:
        //      aFireLaneA (-->), aFireLaneB (-->), aPoisonLaneA (-->), aPoisonLaneB (<-?->)
        //
        // Cross:
        //      aFireLaneC (<--), aFireLaneD (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (;;) {
            //
            aIngress = aFireLaneA[aIndex] ^ aFireLaneB[aIndex];
            aIngress ^= (aPoisonLaneA[aIndex] ^ aPoisonLaneB[aIndex];
            //
            aCross = aFireLaneC[aIndex] ^ aFireLaneD[aIndex];
            aCross ^= aEarthLaneC[aIndex];
            //
            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_c loop 2
        //
        // Ingress:
        //      aFuseLaneA (-->), aFireLaneC (-->), aEarthLaneB (-->), aPoisonLaneC (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), pSnow (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (;;) {
            //
            aIngress = aFuseLaneA[aIndex] ^ aFireLaneC[aIndex];
            aIngress ^= (aEarthLaneB[aIndex] ^ aPoisonLaneC[aIndex];
            //
            aCross = aFireLaneA[aIndex] ^ aFireLaneD[aIndex];
            aCross ^= pSnow[aIndex];
            //
            aFuseLaneB[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_c loop 3
        //
        // Ingress:
        //      aFuseLaneB (-->), aFireLaneD (-->), aPoisonLaneD (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aFireLaneB (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (;;) {
            //
            aIngress = aFuseLaneB[aIndex] ^ aFireLaneD[aIndex];
            aIngress ^= aPoisonLaneD[aIndex];
            //
            aCross = aFuseLaneA[aIndex] ^ aFireLaneB[aIndex];
            aCross ^= aEarthLaneD[aIndex];
            //
            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_c loop 4
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aSource (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aFireLaneC (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (;;) {
            //
            aIngress = aFuseLaneC[aIndex] ^ aFuseLaneA[aIndex];
            aIngress ^= aSource[aIndex];
            //
            aCross = aFuseLaneB[aIndex] ^ aFireLaneC[aIndex];
            aCross ^= aEarthLaneA[aIndex];
            //
            aFuseLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_C kdf_a_loop_c (end)

}

void TwistExpander_Vega_Arx::KDF_A_D() {


    // GSeedRunKDF_A_D kdf_a_loop_d (start)
    {
        //
        // kdf_a_loop_d loop 1
        //
        // Ingress:
        //      aWindLaneA (-->), aWindLaneB (-->), aFireLaneB (-->), aFireLaneC (<-?->)
        //
        // Cross:
        //      aWindLaneC (<--), aWindLaneD (<--), aEarthLaneD (<--), aPoisonLaneB (<-?->)
        //
        // Destination:
        //      aWaterLaneA
        //
        for (;;) {
            //
            aIngress = aWindLaneA[aIndex] ^ aWindLaneB[aIndex];
            aIngress ^= (aFireLaneB[aIndex] ^ aFireLaneC[aIndex];
            //
            aCross = aWindLaneC[aIndex] ^ aWindLaneD[aIndex];
            aCross ^= aEarthLaneD[aIndex] ^ aPoisonLaneB[aIndex];
            //
            aWaterLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_d loop 2
        //
        // Ingress:
        //      aWaterLaneA (-->), aWindLaneC (-->), aFireLaneA (-->), pSnow (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aWindLaneD (<--), aPoisonLaneA (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aWaterLaneB
        //
        for (;;) {
            //
            aIngress = aWaterLaneA[aIndex] ^ aWindLaneC[aIndex];
            aIngress ^= (aFireLaneA[aIndex] ^ pSnow[aIndex];
            //
            aCross = aWindLaneA[aIndex] ^ aWindLaneD[aIndex];
            aCross ^= aPoisonLaneA[aIndex] ^ aEarthLaneC[aIndex];
            //
            aWaterLaneB[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_d loop 3
        //
        // Ingress:
        //      aWaterLaneB (-->), aWindLaneD (-->), aEarthLaneA (-->), aSource (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWindLaneB (<--), aPoisonLaneC (<-?->)
        //
        // Destination:
        //      aWaterLaneC
        //
        for (;;) {
            //
            aIngress = aWaterLaneB[aIndex] ^ aWindLaneD[aIndex];
            aIngress ^= (aEarthLaneA[aIndex] ^ aSource[aIndex];
            //
            aCross = aWaterLaneA[aIndex] ^ aWindLaneB[aIndex];
            aCross ^= aPoisonLaneC[aIndex];
            //
            aWaterLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_d loop 4
        //
        // Ingress:
        //      aWaterLaneC (-->), aWaterLaneA (-->), aFireLaneD (-->), aPoisonLaneD (<-?->)
        //
        // Cross:
        //      aWaterLaneB (<--), aWindLaneC (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aWaterLaneD
        //
        for (;;) {
            //
            aIngress = aWaterLaneC[aIndex] ^ aWaterLaneA[aIndex];
            aIngress ^= (aFireLaneD[aIndex] ^ aPoisonLaneD[aIndex];
            //
            aCross = aWaterLaneB[aIndex] ^ aWindLaneC[aIndex];
            aCross ^= aEarthLaneB[aIndex];
            //
            aWaterLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_D kdf_a_loop_d (end)

}

void TwistExpander_Vega_Arx::KDF_B_A() {


    // GSeedRunKDF_B_A kdf_b_loop_a (start)
    {
        //
        // kdf_b_loop_a loop 1
        //
        // Ingress:
        //      aWaterLaneA (-->), aWaterLaneB (-->), aFireLaneA (-->), aPoisonLaneB (<-?->)
        //
        // Cross:
        //      aWaterLaneC (<--), aWaterLaneD (<--), aWindLaneA (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aWoodLaneA
        //
        for (;;) {
            //
            aIngress = aWaterLaneA[aIndex] ^ aWaterLaneB[aIndex];
            aIngress ^= (aFireLaneA[aIndex] ^ aPoisonLaneB[aIndex];
            //
            aCross = aWaterLaneC[aIndex] ^ aWaterLaneD[aIndex];
            aCross ^= aWindLaneA[aIndex] ^ aWindLaneC[aIndex];
            //
            aWoodLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_a loop 2
        //
        // Ingress:
        //      aWoodLaneA (-->), aWaterLaneC (-->), aFireLaneB (-->), aEarthLaneB (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWaterLaneD (<--), aEarthLaneC (<--), aWindLaneD (<-?->)
        //
        // Destination:
        //      aWoodLaneB
        //
        for (;;) {
            //
            aIngress = aWoodLaneA[aIndex] ^ aWaterLaneC[aIndex];
            aIngress ^= (aFireLaneB[aIndex] ^ aEarthLaneB[aIndex];
            //
            aCross = aWaterLaneA[aIndex] ^ aWaterLaneD[aIndex];
            aCross ^= aEarthLaneC[aIndex] ^ aWindLaneD[aIndex];
            //
            aWoodLaneB[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_a loop 3
        //
        // Ingress:
        //      aWoodLaneB (-->), aWaterLaneD (-->), aEarthLaneD (-->), aFireLaneC (<-?->)
        //
        // Cross:
        //      aWoodLaneA (<--), aWaterLaneB (<--), aEarthLaneA (<--), aPoisonLaneA (<-?->)
        //
        // Destination:
        //      aWoodLaneC
        //
        for (;;) {
            //
            aIngress = aWoodLaneB[aIndex] ^ aWaterLaneD[aIndex];
            aIngress ^= (aEarthLaneD[aIndex] ^ aFireLaneC[aIndex];
            //
            aCross = aWoodLaneA[aIndex] ^ aWaterLaneB[aIndex];
            aCross ^= aEarthLaneA[aIndex] ^ aPoisonLaneA[aIndex];
            //
            aWoodLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_a loop 4
        //
        // Ingress:
        //      aWoodLaneC (-->), aWoodLaneA (-->), aSource (-->), aWindLaneB (<-?->)
        //
        // Cross:
        //      aWoodLaneB (<--), aFireLaneD (<--), aPoisonLaneD (<--), aPoisonLaneC (<-?->)
        //
        // Destination:
        //      aWoodLaneD
        //
        for (;;) {
            //
            aIngress = aWoodLaneC[aIndex] ^ aWoodLaneA[aIndex];
            aIngress ^= (aSource[aIndex] ^ aWindLaneB[aIndex];
            //
            aCross = aWoodLaneB[aIndex] ^ aFireLaneD[aIndex];
            aCross ^= aPoisonLaneD[aIndex] ^ aPoisonLaneC[aIndex];
            //
            aWoodLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_A kdf_b_loop_a (end)

}

void TwistExpander_Vega_Arx::KDF_B_B() {


    // GSeedRunKDF_B_B kdf_b_loop_b (start)
    {
        //
        // kdf_b_loop_b loop 1
        //
        // Ingress:
        //      aWoodLaneA (-->), aWoodLaneB (-->), aFireLaneC (-->), aFireLaneA (<-?->)
        //
        // Cross:
        //      aWoodLaneC (<--), aWoodLaneD (<--), aWindLaneD (<--), aFireLaneD (<-?->)
        //
        // Destination:
        //      aSpiritLaneA
        //
        for (;;) {
            //
            aIngress = aWoodLaneA[aIndex] ^ aWoodLaneB[aIndex];
            aIngress ^= (aFireLaneC[aIndex] ^ aFireLaneA[aIndex];
            //
            aCross = aWoodLaneC[aIndex] ^ aWoodLaneD[aIndex];
            aCross ^= aWindLaneD[aIndex] ^ aFireLaneD[aIndex];
            //
            aSpiritLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_b loop 2
        //
        // Ingress:
        //      aSpiritLaneA (-->), aWoodLaneC (-->), aWaterLaneD (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aWoodLaneA (<--), aWoodLaneD (<--), aEarthLaneC (<--), aWaterLaneA (<-?->)
        //
        // Destination:
        //      aSpiritLaneB
        //
        for (;;) {
            //
            aIngress = aSpiritLaneA[aIndex] ^ aWoodLaneC[aIndex];
            aIngress ^= (aWaterLaneD[aIndex] ^ aEarthLaneA[aIndex];
            //
            aCross = aWoodLaneA[aIndex] ^ aWoodLaneD[aIndex];
            aCross ^= aEarthLaneC[aIndex] ^ aWaterLaneA[aIndex];
            //
            aSpiritLaneB[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_b loop 3
        //
        // Ingress:
        //      aSpiritLaneB (-->), aWoodLaneD (-->), aWindLaneA (-->), aFireLaneB (<-?->)
        //
        // Cross:
        //      aSpiritLaneA (<--), aWoodLaneB (<--), aEarthLaneB (<--), aWaterLaneB (<-?->)
        //
        // Destination:
        //      aSpiritLaneC
        //
        for (;;) {
            //
            aIngress = aSpiritLaneB[aIndex] ^ aWoodLaneD[aIndex];
            aIngress ^= (aWindLaneA[aIndex] ^ aFireLaneB[aIndex];
            //
            aCross = aSpiritLaneA[aIndex] ^ aWoodLaneB[aIndex];
            aCross ^= aEarthLaneB[aIndex] ^ aWaterLaneB[aIndex];
            //
            aSpiritLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_b loop 4
        //
        // Ingress:
        //      aSpiritLaneC (-->), aSpiritLaneA (-->), aWindLaneC (-->), aSource (<-?->)
        //
        // Cross:
        //      aSpiritLaneB (<--), aWoodLaneC (<--), aWindLaneB (<--), aWaterLaneC (<-?->)
        //
        // Destination:
        //      aSpiritLaneD
        //
        for (;;) {
            //
            aIngress = aSpiritLaneC[aIndex] ^ aSpiritLaneA[aIndex];
            aIngress ^= (aWindLaneC[aIndex] ^ aSource[aIndex];
            //
            aCross = aSpiritLaneB[aIndex] ^ aWoodLaneC[aIndex];
            aCross ^= aWindLaneB[aIndex] ^ aWaterLaneC[aIndex];
            //
            aSpiritLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_B kdf_b_loop_b (end)

}

void TwistExpander_Vega_Arx::KDF_B_C() {


    // GSeedRunKDF_B_C kdf_b_loop_c (start)
    {
        //
        // kdf_b_loop_c loop 1
        //
        // Ingress:
        //      aSpiritLaneA (-->), aSpiritLaneB (-->), aWaterLaneC (-->), aFireLaneC (<-?->)
        //
        // Cross:
        //      aSpiritLaneC (<--), aSpiritLaneD (<--), aWindLaneA (<--), aWoodLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (;;) {
            //
            aIngress = aSpiritLaneA[aIndex] ^ aSpiritLaneB[aIndex];
            aIngress ^= (aWaterLaneC[aIndex] ^ aFireLaneC[aIndex];
            //
            aCross = aSpiritLaneC[aIndex] ^ aSpiritLaneD[aIndex];
            aCross ^= aWindLaneA[aIndex] ^ aWoodLaneC[aIndex];
            //
            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_c loop 2
        //
        // Ingress:
        //      aFuseLaneA (-->), aSpiritLaneC (-->), aWaterLaneA (-->), aWaterLaneD (<-?->)
        //
        // Cross:
        //      aSpiritLaneA (<--), aSpiritLaneD (<--), aWindLaneD (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (;;) {
            //
            aIngress = aFuseLaneA[aIndex] ^ aSpiritLaneC[aIndex];
            aIngress ^= (aWaterLaneA[aIndex] ^ aWaterLaneD[aIndex];
            //
            aCross = aSpiritLaneA[aIndex] ^ aSpiritLaneD[aIndex];
            aCross ^= aWindLaneD[aIndex] ^ aWindLaneC[aIndex];
            //
            aFuseLaneB[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_c loop 3
        //
        // Ingress:
        //      aFuseLaneB (-->), aSpiritLaneD (-->), aSource (-->), aWaterLaneB (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aSpiritLaneB (<--), aWoodLaneD (<--), aWoodLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (;;) {
            //
            aIngress = aFuseLaneB[aIndex] ^ aSpiritLaneD[aIndex];
            aIngress ^= (aSource[aIndex] ^ aWaterLaneB[aIndex];
            //
            aCross = aFuseLaneA[aIndex] ^ aSpiritLaneB[aIndex];
            aCross ^= aWoodLaneD[aIndex] ^ aWoodLaneB[aIndex];
            //
            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_c loop 4
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aWindLaneB (-->), aWoodLaneA (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aSpiritLaneC (<--), aEarthLaneD (<--), aFireLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (;;) {
            //
            aIngress = aFuseLaneC[aIndex] ^ aFuseLaneA[aIndex];
            aIngress ^= (aWindLaneB[aIndex] ^ aWoodLaneA[aIndex];
            //
            aCross = aFuseLaneB[aIndex] ^ aSpiritLaneC[aIndex];
            aCross ^= aEarthLaneD[aIndex] ^ aFireLaneD[aIndex];
            //
            aFuseLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_C kdf_b_loop_c (end)

}

void TwistExpander_Vega_Arx::KDF_B_D() {


    // GSeedRunKDF_B_D kdf_b_loop_d (start)
    {
        //
        // kdf_b_loop_d loop 1
        //
        // Ingress:
        //      aPoisonLaneA (-->), aPoisonLaneB (-->), aWindLaneC (-->), aSpiritLaneB (<-?->)
        //
        // Cross:
        //      aPoisonLaneC (<--), aPoisonLaneD (<--), aWaterLaneA (<--), aSpiritLaneD (<-?->)
        //
        // Destination:
        //      aHeartLaneA
        //
        for (;;) {
            //
            aIngress = aPoisonLaneA[aIndex] ^ aPoisonLaneB[aIndex];
            aIngress ^= (aWindLaneC[aIndex] ^ aSpiritLaneB[aIndex];
            //
            aCross = aPoisonLaneC[aIndex] ^ aPoisonLaneD[aIndex];
            aCross ^= aWaterLaneA[aIndex] ^ aSpiritLaneD[aIndex];
            //
            aHeartLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_d loop 2
        //
        // Ingress:
        //      aHeartLaneA (-->), aPoisonLaneC (-->), aSpiritLaneC (-->), aWoodLaneA (<-?->)
        //
        // Cross:
        //      aPoisonLaneA (<--), aPoisonLaneD (<--), aSpiritLaneA (<--), aWaterLaneC (<-?->)
        //
        // Destination:
        //      aHeartLaneB
        //
        for (;;) {
            //
            aIngress = aHeartLaneA[aIndex] ^ aPoisonLaneC[aIndex];
            aIngress ^= (aSpiritLaneC[aIndex] ^ aWoodLaneA[aIndex];
            //
            aCross = aPoisonLaneA[aIndex] ^ aPoisonLaneD[aIndex];
            aCross ^= aSpiritLaneA[aIndex] ^ aWaterLaneC[aIndex];
            //
            aHeartLaneB[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_d loop 3
        //
        // Ingress:
        //      aHeartLaneB (-->), aPoisonLaneD (-->), aWoodLaneB (-->), aWaterLaneD (<-?->)
        //
        // Cross:
        //      aHeartLaneA (<--), aPoisonLaneB (<--), aFireLaneB (<--), aWoodLaneD (<-?->)
        //
        // Destination:
        //      aHeartLaneC
        //
        for (;;) {
            //
            aIngress = aHeartLaneB[aIndex] ^ aPoisonLaneD[aIndex];
            aIngress ^= (aWoodLaneB[aIndex] ^ aWaterLaneD[aIndex];
            //
            aCross = aHeartLaneA[aIndex] ^ aPoisonLaneB[aIndex];
            aCross ^= aFireLaneB[aIndex] ^ aWoodLaneD[aIndex];
            //
            aHeartLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_d loop 4
        //
        // Ingress:
        //      aHeartLaneC (-->), aHeartLaneA (-->), aFireLaneA (-->), aWoodLaneC (<-?->)
        //
        // Cross:
        //      aHeartLaneB (<--), aPoisonLaneC (<--), aWindLaneD (<--), aWaterLaneB (<-?->)
        //
        // Destination:
        //      aHeartLaneD
        //
        for (;;) {
            //
            aIngress = aHeartLaneC[aIndex] ^ aHeartLaneA[aIndex];
            aIngress ^= (aFireLaneA[aIndex] ^ aWoodLaneC[aIndex];
            //
            aCross = aHeartLaneB[aIndex] ^ aPoisonLaneC[aIndex];
            aCross ^= aWindLaneD[aIndex] ^ aWaterLaneB[aIndex];
            //
            aHeartLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_D kdf_b_loop_d (end)

}

void TwistExpander_Vega_Arx::Seed_A() {


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
        //      aPoisonLaneA
        //
        for (;;) {
            //
            aIngress = aSource[aIndex] ^ aKeyRowReadA[aIndex];
            //
            aCross = aSource[aIndex] ^ aKeyRowReadB[W_KEY1 - aIndex];
            //
            aPoisonLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_a loop 2
        //
        // Ingress:
        //      aPoisonLaneA (-->), aKeyRowReadB (-->)
        //
        // Cross:
        //      aSource (<--), aKeyRowReadA (<--)
        //
        // Destination:
        //      aPoisonLaneB
        //
        for (;;) {
            //
            aIngress = aPoisonLaneA[aIndex] ^ aKeyRowReadB[aIndex];
            //
            aCross = aSource[aIndex] ^ aKeyRowReadA[W_KEY1 - aIndex];
            //
            aPoisonLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_a loop 3
        //
        // Ingress:
        //      aPoisonLaneB (-->), aSource (-->), aKeyRowReadB (-->)
        //
        // Cross:
        //      aKeyRowReadA (<--), aPoisonLaneA (<-?->)
        //
        // Destination:
        //      aEarthLaneA
        //
        for (;;) {
            //
            aIngress = aPoisonLaneB[aIndex] ^ aSource[aIndex];
            aIngress ^= aKeyRowReadB[aIndex];
            //
            aCross = aKeyRowReadA[W_KEY1 - aIndex] ^ aPoisonLaneA[aIndex];
            //
            aEarthLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_a loop 4
        //
        // Ingress:
        //      aEarthLaneA (-->), aPoisonLaneA (<-?->)
        //
        // Cross:
        //      aPoisonLaneB (<--), aKeyRowReadB (<-?->)
        //
        // Destination:
        //      aEarthLaneB
        //
        for (;;) {
            //
            aIngress = aEarthLaneA[aIndex] ^ aPoisonLaneA[aIndex];
            //
            aCross = aPoisonLaneB[aIndex] ^ aKeyRowReadB[aIndex];
            //
            aEarthLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_a loop 5
        //
        // Ingress:
        //      aEarthLaneB (-->), aPoisonLaneB (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aKeyRowReadA (<-?->)
        //
        // Destination:
        //      aEarthLaneC
        //
        for (;;) {
            //
            aIngress = aEarthLaneB[aIndex] ^ aPoisonLaneB[aIndex];
            //
            aCross = aEarthLaneA[aIndex] ^ aKeyRowReadA[W_KEY1 - aIndex];
            //
            aEarthLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_a loop 6
        //
        // Ingress:
        //      aEarthLaneC (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aEarthLaneB (<--), aPoisonLaneB (<-?->)
        //
        // Destination:
        //      aEarthLaneD
        //
        for (;;) {
            //
            aIngress = aEarthLaneC[aIndex] ^ aEarthLaneA[aIndex];
            //
            aCross = aEarthLaneB[aIndex] ^ aPoisonLaneB[aIndex];
            //
            aEarthLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_A seed_loop_a (end)

}

void TwistExpander_Vega_Arx::Seed_B() {


    // GSeedRunSeed_B seed_loop_b (start)
    {
        //
        // seed_loop_b loop 1
        //
        // Ingress:
        //      aEarthLaneA (-->), aEarthLaneB (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aEarthLaneC (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aPoisonLaneC
        //
        for (;;) {
            //
            aIngress = aEarthLaneA[aIndex] ^ aEarthLaneB[aIndex];
            aIngress ^= aKeyRowReadA[W_KEY1 - aIndex];
            //
            aCross = aEarthLaneC[aIndex] ^ aEarthLaneD[aIndex];
            //
            aPoisonLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_b loop 2
        //
        // Ingress:
        //      aPoisonLaneC (-->), aEarthLaneC (-->), aPoisonLaneA (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aEarthLaneD (<--)
        //
        // Destination:
        //      aPoisonLaneD
        //
        for (;;) {
            //
            aIngress = aPoisonLaneC[aIndex] ^ aEarthLaneC[aIndex];
            aIngress ^= aPoisonLaneA[aIndex];
            //
            aCross = aEarthLaneA[aIndex] ^ aEarthLaneD[aIndex];
            //
            aPoisonLaneD[aIndex] = aIngress;
        }
    
        //
        // seed_loop_b loop 3
        //
        // Ingress:
        //      aPoisonLaneD (-->), aEarthLaneA (-->), aSource (<-?->)
        //
        // Cross:
        //      aPoisonLaneC (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aFireLaneA
        //
        for (;;) {
            //
            aIngress = aPoisonLaneD[aIndex] ^ aEarthLaneA[aIndex];
            aIngress ^= aSource[aIndex];
            //
            aCross = aPoisonLaneC[aIndex] ^ aEarthLaneC[aIndex];
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_b loop 4
        //
        // Ingress:
        //      aFireLaneA (-->), aEarthLaneD (-->), aKeyRowReadB (<-?->)
        //
        // Cross:
        //      aPoisonLaneD (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aFireLaneB
        //
        for (;;) {
            //
            aIngress = aFireLaneA[aIndex] ^ aEarthLaneD[aIndex];
            aIngress ^= aKeyRowReadB[W_KEY1 - aIndex];
            //
            aCross = aPoisonLaneD[aIndex] ^ aEarthLaneA[aIndex];
            //
            aFireLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_b loop 5
        //
        // Ingress:
        //      aFireLaneB (-->), aPoisonLaneD (-->), aPoisonLaneB (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aPoisonLaneC (<-?->)
        //
        // Destination:
        //      aFireLaneC
        //
        for (;;) {
            //
            aIngress = aFireLaneB[aIndex] ^ aPoisonLaneD[aIndex];
            aIngress ^= aPoisonLaneB[aIndex];
            //
            aCross = aFireLaneA[aIndex] ^ aPoisonLaneC[aIndex];
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_b loop 6
        //
        // Ingress:
        //      aFireLaneC (-->), aFireLaneA (<-?->)
        //
        // Cross:
        //      aFireLaneB (<--), aEarthLaneB (<--)
        //
        // Destination:
        //      aFireLaneD
        //
        for (;;) {
            //
            aIngress = aFireLaneC[aIndex] ^ aFireLaneA[aIndex];
            //
            aCross = aFireLaneB[aIndex] ^ aEarthLaneB[aIndex];
            //
            aFireLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_B seed_loop_b (end)

}

void TwistExpander_Vega_Arx::Seed_C() {


    // GSeedRunSeed_C seed_loop_c (start)
    {
        //
        // seed_loop_c loop 1
        //
        // Ingress:
        //      aFireLaneA (-->), aFireLaneB (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aFireLaneC (<--), aFireLaneD (<--), aPoisonLaneA (<-?->)
        //
        // Destination:
        //      aHeartLaneA
        //
        for (;;) {
            //
            aIngress = aFireLaneA[aIndex] ^ aFireLaneB[aIndex];
            aIngress ^= aEarthLaneA[aIndex];
            //
            aCross = aFireLaneC[aIndex] ^ aFireLaneD[aIndex];
            aCross ^= aPoisonLaneA[aIndex];
            //
            aHeartLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 2
        //
        // Ingress:
        //      aHeartLaneA (-->), aFireLaneC (-->), aPoisonLaneB (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), aKeyRowReadB (<-?->)
        //
        // Destination:
        //      aHeartLaneB
        //
        for (;;) {
            //
            aIngress = aHeartLaneA[aIndex] ^ aFireLaneC[aIndex];
            aIngress ^= aPoisonLaneB[aIndex];
            //
            aCross = aFireLaneA[aIndex] ^ aFireLaneD[aIndex];
            aCross ^= aKeyRowReadB[W_KEY1 - aIndex];
            //
            aHeartLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 3
        //
        // Ingress:
        //      aHeartLaneB (-->), aFireLaneA (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aHeartLaneA (<--), aFireLaneC (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (;;) {
            //
            aIngress = aHeartLaneB[aIndex] ^ aFireLaneA[aIndex];
            aIngress ^= aEarthLaneD[aIndex];
            //
            aCross = aHeartLaneA[aIndex] ^ aFireLaneC[aIndex];
            aCross ^= aEarthLaneB[aIndex];
            //
            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 4
        //
        // Ingress:
        //      aFuseLaneA (-->), aFireLaneD (-->), aPoisonLaneC (<-?->)
        //
        // Cross:
        //      aHeartLaneB (<--), aFireLaneA (<--), aKeyRowReadA (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (;;) {
            //
            aIngress = aFuseLaneA[aIndex] ^ aFireLaneD[aIndex];
            aIngress ^= aPoisonLaneC[aIndex];
            //
            aCross = aHeartLaneB[aIndex] ^ aFireLaneA[aIndex];
            aCross ^= aKeyRowReadA[aIndex];
            //
            aFuseLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 5
        //
        // Ingress:
        //      aFuseLaneB (-->), aHeartLaneB (-->), aEarthLaneC (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aHeartLaneA (<--), aSource (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (;;) {
            //
            aIngress = aFuseLaneB[aIndex] ^ aHeartLaneB[aIndex];
            aIngress ^= aEarthLaneC[aIndex];
            //
            aCross = aFuseLaneA[aIndex] ^ aHeartLaneA[aIndex];
            aCross ^= aSource[aIndex];
            //
            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 6
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aPoisonLaneD (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aFireLaneB (<--)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (;;) {
            //
            aIngress = aFuseLaneC[aIndex] ^ aFuseLaneA[aIndex];
            aIngress ^= aPoisonLaneD[aIndex];
            //
            aCross = aFuseLaneB[aIndex] ^ aFireLaneB[aIndex];
            //
            aFuseLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_C seed_loop_c (end)

}

void TwistExpander_Vega_Arx::Seed_D() {


    // GSeedRunSeed_D seed_loop_d (start)
    {
        //
        // seed_loop_d loop 1
        //
        // Ingress:
        //      aWindLaneA (-->), aWindLaneB (-->), aKeyRowReadA (-->), aSource (<-?->)
        //
        // Cross:
        //      aWindLaneC (<--), aWindLaneD (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aHeartLaneC
        //
        for (;;) {
            //
            aIngress = aWindLaneA[aIndex] ^ aWindLaneB[aIndex];
            aIngress ^= (aKeyRowReadA[aIndex] ^ aSource[aIndex];
            //
            aCross = aWindLaneC[aIndex] ^ aWindLaneD[aIndex];
            aCross ^= aEarthLaneD[aIndex];
            //
            aHeartLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 2
        //
        // Ingress:
        //      aHeartLaneC (-->), aWindLaneC (-->), aEarthLaneA (-->), aPoisonLaneC (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aWindLaneD (<--), aKeyRowReadB (<-?->)
        //
        // Destination:
        //      aHeartLaneD
        //
        for (;;) {
            //
            aIngress = aHeartLaneC[aIndex] ^ aWindLaneC[aIndex];
            aIngress ^= (aEarthLaneA[aIndex] ^ aPoisonLaneC[aIndex];
            //
            aCross = aWindLaneA[aIndex] ^ aWindLaneD[aIndex];
            aCross ^= aKeyRowReadB[aIndex];
            //
            aHeartLaneD[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 3
        //
        // Ingress:
        //      aHeartLaneD (-->), aWindLaneA (-->), aHeartLaneA (-->), aFireLaneD (<-?->)
        //
        // Cross:
        //      aHeartLaneC (<--), aWindLaneC (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aWaterLaneA
        //
        for (;;) {
            //
            aIngress = aHeartLaneD[aIndex] ^ aWindLaneA[aIndex];
            aIngress ^= (aHeartLaneA[aIndex] ^ aFireLaneD[aIndex];
            //
            aCross = aHeartLaneC[aIndex] ^ aWindLaneC[aIndex];
            aCross ^= aEarthLaneC[aIndex];
            //
            aWaterLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 4
        //
        // Ingress:
        //      aWaterLaneA (-->), aWindLaneD (-->), aPoisonLaneA (-->), aFireLaneB (<-?->)
        //
        // Cross:
        //      aHeartLaneD (<--), aWindLaneA (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aWaterLaneB
        //
        for (;;) {
            //
            aIngress = aWaterLaneA[aIndex] ^ aWindLaneD[aIndex];
            aIngress ^= (aPoisonLaneA[aIndex] ^ aFireLaneB[aIndex];
            //
            aCross = aHeartLaneD[aIndex] ^ aWindLaneA[aIndex];
            aCross ^= aEarthLaneB[aIndex];
            //
            aWaterLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 5
        //
        // Ingress:
        //      aWaterLaneB (-->), aHeartLaneD (-->), aFireLaneA (-->), aPoisonLaneD (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aHeartLaneC (<--), aPoisonLaneB (<-?->)
        //
        // Destination:
        //      aWaterLaneC
        //
        for (;;) {
            //
            aIngress = aWaterLaneB[aIndex] ^ aHeartLaneD[aIndex];
            aIngress ^= (aFireLaneA[aIndex] ^ aPoisonLaneD[aIndex];
            //
            aCross = aWaterLaneA[aIndex] ^ aHeartLaneC[aIndex];
            aCross ^= aPoisonLaneB[aIndex];
            //
            aWaterLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 6
        //
        // Ingress:
        //      aWaterLaneC (-->), aWaterLaneA (-->), aFireLaneC (<-?->)
        //
        // Cross:
        //      aWaterLaneB (<--), aWindLaneB (<--), aHeartLaneB (<-?->)
        //
        // Destination:
        //      aWaterLaneD
        //
        for (;;) {
            //
            aIngress = aWaterLaneC[aIndex] ^ aWaterLaneA[aIndex];
            aIngress ^= aFireLaneC[aIndex];
            //
            aCross = aWaterLaneB[aIndex] ^ aWindLaneB[aIndex];
            aCross ^= aHeartLaneB[aIndex];
            //
            aWaterLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_D seed_loop_d (end)

}

void TwistExpander_Vega_Arx::Seed_E() {


    // GSeedRunSeed_E seed_loop_e (start)
    {
        //
        // seed_loop_e loop 1
        //
        // Ingress:
        //      aWaterLaneA (-->), aWaterLaneB (-->), aFireLaneC (-->), aKeyRowReadB (<-?->)
        //
        // Cross:
        //      aWaterLaneC (<--), aWaterLaneD (<--), aPoisonLaneD (<--), aHeartLaneD (<-?->)
        //
        // Destination:
        //      aWoodLaneA
        //
        for (;;) {
            //
            aIngress = aWaterLaneA[aIndex] ^ aWaterLaneB[aIndex];
            aIngress ^= (aFireLaneC[aIndex] ^ aKeyRowReadB[W_KEY1 - aIndex];
            //
            aCross = aWaterLaneC[aIndex] ^ aWaterLaneD[aIndex];
            aCross ^= aPoisonLaneD[aIndex] ^ aHeartLaneD[aIndex];
            //
            aWoodLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 2
        //
        // Ingress:
        //      aWoodLaneA (-->), aWaterLaneC (-->), aFireLaneD (-->), aHeartLaneB (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWaterLaneD (<--), aWindLaneC (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aWoodLaneB
        //
        for (;;) {
            //
            aIngress = aWoodLaneA[aIndex] ^ aWaterLaneC[aIndex];
            aIngress ^= (aFireLaneD[aIndex] ^ aHeartLaneB[aIndex];
            //
            aCross = aWaterLaneA[aIndex] ^ aWaterLaneD[aIndex];
            aCross ^= aWindLaneC[aIndex] ^ aEarthLaneA[aIndex];
            //
            aWoodLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 3
        //
        // Ingress:
        //      aWoodLaneB (-->), aWaterLaneA (-->), aWindLaneD (-->), aPoisonLaneA (<-?->)
        //
        // Cross:
        //      aWoodLaneA (<--), aWaterLaneC (<--), aHeartLaneA (<--), aPoisonLaneC (<-?->)
        //
        // Destination:
        //      aIceLaneA
        //
        for (;;) {
            //
            aIngress = aWoodLaneB[aIndex] ^ aWaterLaneA[aIndex];
            aIngress ^= (aWindLaneD[aIndex] ^ aPoisonLaneA[aIndex];
            //
            aCross = aWoodLaneA[aIndex] ^ aWaterLaneC[aIndex];
            aCross ^= aHeartLaneA[aIndex] ^ aPoisonLaneC[aIndex];
            //
            aIceLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 4
        //
        // Ingress:
        //      aIceLaneA (-->), aWaterLaneD (-->), aWindLaneA (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aWoodLaneB (<--), aWaterLaneA (<--), aSource (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aIceLaneB
        //
        for (;;) {
            //
            aIngress = aIceLaneA[aIndex] ^ aWaterLaneD[aIndex];
            aIngress ^= (aWindLaneA[aIndex] ^ aKeyRowReadA[aIndex];
            //
            aCross = aWoodLaneB[aIndex] ^ aWaterLaneA[aIndex];
            aCross ^= aSource[aIndex] ^ aEarthLaneB[aIndex];
            //
            aIceLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 5
        //
        // Ingress:
        //      aIceLaneB (-->), aWoodLaneB (-->), aPoisonLaneB (-->), aHeartLaneC (<-?->)
        //
        // Cross:
        //      aIceLaneA (<--), aWoodLaneA (<--), aWindLaneB (<--), aFireLaneB (<-?->)
        //
        // Destination:
        //      aIceLaneC
        //
        for (;;) {
            //
            aIngress = aIceLaneB[aIndex] ^ aWoodLaneB[aIndex];
            aIngress ^= (aPoisonLaneB[aIndex] ^ aHeartLaneC[aIndex];
            //
            aCross = aIceLaneA[aIndex] ^ aWoodLaneA[aIndex];
            aCross ^= aWindLaneB[aIndex] ^ aFireLaneB[aIndex];
            //
            aIceLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 6
        //
        // Ingress:
        //      aIceLaneC (-->), aIceLaneA (-->), aEarthLaneC (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aIceLaneB (<--), aWaterLaneB (<--), aFireLaneA (<-?->)
        //
        // Destination:
        //      aIceLaneD
        //
        for (;;) {
            //
            aIngress = aIceLaneC[aIndex] ^ aIceLaneA[aIndex];
            aIngress ^= (aEarthLaneC[aIndex] ^ aEarthLaneD[aIndex];
            //
            aCross = aIceLaneB[aIndex] ^ aWaterLaneB[aIndex];
            aCross ^= aFireLaneA[aIndex];
            //
            aIceLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_E seed_loop_e (end)

}

void TwistExpander_Vega_Arx::Seed_F() {


    // GSeedRunSeed_F seed_loop_f (start)
    {
        //
        // seed_loop_f loop 1
        //
        // Ingress:
        //      aIceLaneA (-->), aIceLaneB (-->), aWindLaneD (-->), aHeartLaneB (<-?->)
        //
        // Cross:
        //      aIceLaneC (<--), aIceLaneD (<--), aFireLaneB (<--), aSource (<-?->)
        //
        // Destination:
        //      aWoodLaneC
        //
        for (;;) {
            //
            aIngress = aIceLaneA[aIndex] ^ aIceLaneB[aIndex];
            aIngress ^= (aWindLaneD[aIndex] ^ aHeartLaneB[aIndex];
            //
            aCross = aIceLaneC[aIndex] ^ aIceLaneD[aIndex];
            aCross ^= aFireLaneB[aIndex] ^ aSource[aIndex];
            //
            aWoodLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 2
        //
        // Ingress:
        //      aWoodLaneC (-->), aIceLaneC (-->), aKeyRowReadB (-->), aWoodLaneB (<-?->)
        //
        // Cross:
        //      aIceLaneA (<--), aIceLaneD (<--), aFireLaneC (<--), aHeartLaneD (<-?->)
        //
        // Destination:
        //      aWoodLaneD
        //
        for (;;) {
            //
            aIngress = aWoodLaneC[aIndex] ^ aIceLaneC[aIndex];
            aIngress ^= (aKeyRowReadB[aIndex] ^ aWoodLaneB[aIndex];
            //
            aCross = aIceLaneA[aIndex] ^ aIceLaneD[aIndex];
            aCross ^= aFireLaneC[aIndex] ^ aHeartLaneD[aIndex];
            //
            aWoodLaneD[aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 3
        //
        // Ingress:
        //      aWoodLaneD (-->), aIceLaneA (-->), aWaterLaneB (-->), aWoodLaneA (<-?->)
        //
        // Cross:
        //      aWoodLaneC (<--), aIceLaneC (<--), aWaterLaneC (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (;;) {
            //
            aIngress = aWoodLaneD[aIndex] ^ aIceLaneA[aIndex];
            aIngress ^= (aWaterLaneB[aIndex] ^ aWoodLaneA[aIndex];
            //
            aCross = aWoodLaneC[aIndex] ^ aIceLaneC[aIndex];
            aCross ^= aWaterLaneC[aIndex] ^ aEarthLaneB[aIndex];
            //
            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 4
        //
        // Ingress:
        //      aFuseLaneA (-->), aIceLaneD (-->), aKeyRowReadA (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aWoodLaneD (<--), aIceLaneA (<--), aWindLaneB (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (;;) {
            //
            aIngress = aFuseLaneA[aIndex] ^ aIceLaneD[aIndex];
            aIngress ^= (aKeyRowReadA[aIndex] ^ aEarthLaneD[aIndex];
            //
            aCross = aWoodLaneD[aIndex] ^ aIceLaneA[aIndex];
            aCross ^= aWindLaneB[aIndex] ^ aEarthLaneC[aIndex];
            //
            aFuseLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 5
        //
        // Ingress:
        //      aFuseLaneB (-->), aWoodLaneD (-->), aHeartLaneC (-->), aFireLaneD (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aWoodLaneC (<--), aWaterLaneA (<--), aFireLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (;;) {
            //
            aIngress = aFuseLaneB[aIndex] ^ aWoodLaneD[aIndex];
            aIngress ^= (aHeartLaneC[aIndex] ^ aFireLaneD[aIndex];
            //
            aCross = aFuseLaneA[aIndex] ^ aWoodLaneC[aIndex];
            aCross ^= aWaterLaneA[aIndex] ^ aFireLaneA[aIndex];
            //
            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 6
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aWindLaneC (-->), aWaterLaneD (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aIceLaneB (<--), aWindLaneA (<--), aHeartLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (;;) {
            //
            aIngress = aFuseLaneC[aIndex] ^ aFuseLaneA[aIndex];
            aIngress ^= (aWindLaneC[aIndex] ^ aWaterLaneD[aIndex];
            //
            aCross = aFuseLaneB[aIndex] ^ aIceLaneB[aIndex];
            aCross ^= aWindLaneA[aIndex] ^ aHeartLaneA[aIndex];
            //
            aFuseLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_F seed_loop_f (end)

}

void TwistExpander_Vega_Arx::Seed_G() {


    // GSeedRunSeed_G seed_loop_g (start)
    {
        //
        // seed_loop_g loop 1
        //
        // Ingress:
        //      aSpiritLaneA (-->), aSpiritLaneB (-->), aSource (-->), aHeartLaneD (<-?->)
        //
        // Cross:
        //      aSpiritLaneC (<--), aSpiritLaneD (<--), aWaterLaneC (<--), aWindLaneD (<-?->)
        //
        // Destination:
        //      aEarthLaneC
        //
        for (;;) {
            //
            aIngress = aSpiritLaneA[aIndex] ^ aSpiritLaneB[aIndex];
            aIngress ^= (aSource[aIndex] ^ aHeartLaneD[aIndex];
            //
            aCross = aSpiritLaneC[aIndex] ^ aSpiritLaneD[aIndex];
            aCross ^= aWaterLaneC[aIndex] ^ aWindLaneD[aIndex];
            //
            aEarthLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_g loop 2
        //
        // Ingress:
        //      aEarthLaneC (-->), aSpiritLaneC (-->), aHeartLaneB (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aSpiritLaneA (<--), aSpiritLaneD (<--), aWoodLaneC (<--), aWaterLaneA (<-?->)
        //
        // Destination:
        //      aEarthLaneD
        //
        for (;;) {
            //
            aIngress = aEarthLaneC[aIndex] ^ aSpiritLaneC[aIndex];
            aIngress ^= (aHeartLaneB[aIndex] ^ aKeyRowReadA[aIndex];
            //
            aCross = aSpiritLaneA[aIndex] ^ aSpiritLaneD[aIndex];
            aCross ^= aWoodLaneC[aIndex] ^ aWaterLaneA[aIndex];
            //
            aEarthLaneD[aIndex] = aIngress;
        }
    
        //
        // seed_loop_g loop 3
        //
        // Ingress:
        //      aEarthLaneD (-->), aSpiritLaneA (-->), aEarthLaneA (-->), aWindLaneB (<-?->)
        //
        // Cross:
        //      aEarthLaneC (<--), aSpiritLaneC (<--), aWoodLaneA (<--), aWaterLaneD (<-?->)
        //
        // Destination:
        //      aFireLaneA
        //
        for (;;) {
            //
            aIngress = aEarthLaneD[aIndex] ^ aSpiritLaneA[aIndex];
            aIngress ^= (aEarthLaneA[aIndex] ^ aWindLaneB[aIndex];
            //
            aCross = aEarthLaneC[aIndex] ^ aSpiritLaneC[aIndex];
            aCross ^= aWoodLaneA[aIndex] ^ aWaterLaneD[aIndex];
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_g loop 4
        //
        // Ingress:
        //      aFireLaneA (-->), aSpiritLaneD (-->), aWindLaneA (-->), aKeyRowReadB (<-?->)
        //
        // Cross:
        //      aEarthLaneD (<--), aSpiritLaneA (<--), aIceLaneD (<--), aWoodLaneD (<-?->)
        //
        // Destination:
        //      aFireLaneB
        //
        for (;;) {
            //
            aIngress = aFireLaneA[aIndex] ^ aSpiritLaneD[aIndex];
            aIngress ^= (aWindLaneA[aIndex] ^ aKeyRowReadB[aIndex];
            //
            aCross = aEarthLaneD[aIndex] ^ aSpiritLaneA[aIndex];
            aCross ^= aIceLaneD[aIndex] ^ aWoodLaneD[aIndex];
            //
            aFireLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_g loop 5
        //
        // Ingress:
        //      aFireLaneB (-->), aEarthLaneD (-->), aIceLaneC (-->), aWoodLaneB (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aEarthLaneC (<--), aWindLaneC (<--), aIceLaneB (<-?->)
        //
        // Destination:
        //      aFireLaneC
        //
        for (;;) {
            //
            aIngress = aFireLaneB[aIndex] ^ aEarthLaneD[aIndex];
            aIngress ^= (aIceLaneC[aIndex] ^ aWoodLaneB[aIndex];
            //
            aCross = aFireLaneA[aIndex] ^ aEarthLaneC[aIndex];
            aCross ^= aWindLaneC[aIndex] ^ aIceLaneB[aIndex];
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_g loop 6
        //
        // Ingress:
        //      aFireLaneC (-->), aFireLaneA (-->), aIceLaneA (-->), aHeartLaneC (<-?->)
        //
        // Cross:
        //      aFireLaneB (<--), aSpiritLaneB (<--), aHeartLaneA (<--), aWaterLaneB (<-?->)
        //
        // Destination:
        //      aFireLaneD
        //
        for (;;) {
            //
            aIngress = aFireLaneC[aIndex] ^ aFireLaneA[aIndex];
            aIngress ^= (aIceLaneA[aIndex] ^ aHeartLaneC[aIndex];
            //
            aCross = aFireLaneB[aIndex] ^ aSpiritLaneB[aIndex];
            aCross ^= aHeartLaneA[aIndex] ^ aWaterLaneB[aIndex];
            //
            aFireLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_G seed_loop_g (end)

}

void TwistExpander_Vega_Arx::Seed_H() {


    // GSeedRunSeed_H seed_loop_h (start)
    {
        //
        // seed_loop_h loop 1
        //
        // Ingress:
        //      aFireLaneA (-->), aFireLaneB (-->), aIceLaneA (-->), aSpiritLaneB (<-?->)
        //
        // Cross:
        //      aFireLaneC (<--), aFireLaneD (<--), aWaterLaneA (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aEarthLaneC
        //
        for (;;) {
            //
            aIngress = aFireLaneA[aIndex] ^ aFireLaneB[aIndex];
            aIngress ^= (aIceLaneA[aIndex] ^ aSpiritLaneB[aIndex];
            //
            aCross = aFireLaneC[aIndex] ^ aFireLaneD[aIndex];
            aCross ^= aWaterLaneA[aIndex] ^ aWindLaneC[aIndex];
            //
            aEarthLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_h loop 2
        //
        // Ingress:
        //      aEarthLaneC (-->), aFireLaneC (-->), aWaterLaneD (-->), aSpiritLaneD (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), aWaterLaneB (<--), aIceLaneC (<-?->)
        //
        // Destination:
        //      aEarthLaneD
        //
        for (;;) {
            //
            aIngress = aEarthLaneC[aIndex] ^ aFireLaneC[aIndex];
            aIngress ^= (aWaterLaneD[aIndex] ^ aSpiritLaneD[aIndex];
            //
            aCross = aFireLaneA[aIndex] ^ aFireLaneD[aIndex];
            aCross ^= aWaterLaneB[aIndex] ^ aIceLaneC[aIndex];
            //
            aEarthLaneD[aIndex] = aIngress;
        }
    
        //
        // seed_loop_h loop 3
        //
        // Ingress:
        //      aEarthLaneD (-->), aFireLaneA (-->), aIceLaneD (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aEarthLaneC (<--), aFireLaneC (<--), aWindLaneA (<--), aSpiritLaneC (<-?->)
        //
        // Destination:
        //      aHeartLaneA
        //
        for (;;) {
            //
            aIngress = aEarthLaneD[aIndex] ^ aFireLaneA[aIndex];
            aIngress ^= (aIceLaneD[aIndex] ^ aKeyRowReadA[W_KEY1 - aIndex];
            //
            aCross = aEarthLaneC[aIndex] ^ aFireLaneC[aIndex];
            aCross ^= aWindLaneA[aIndex] ^ aSpiritLaneC[aIndex];
            //
            aHeartLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_h loop 4
        //
        // Ingress:
        //      aHeartLaneA (-->), aFireLaneD (-->), aWoodLaneA (-->), aKeyRowReadB (<-?->)
        //
        // Cross:
        //      aEarthLaneD (<--), aFireLaneA (<--), aSpiritLaneA (<--), aWindLaneD (<-?->)
        //
        // Destination:
        //      aHeartLaneB
        //
        for (;;) {
            //
            aIngress = aHeartLaneA[aIndex] ^ aFireLaneD[aIndex];
            aIngress ^= (aWoodLaneA[aIndex] ^ aKeyRowReadB[aIndex];
            //
            aCross = aEarthLaneD[aIndex] ^ aFireLaneA[aIndex];
            aCross ^= aSpiritLaneA[aIndex] ^ aWindLaneD[aIndex];
            //
            aHeartLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_h loop 5
        //
        // Ingress:
        //      aHeartLaneB (-->), aEarthLaneD (-->), aWoodLaneB (-->), aWoodLaneD (<-?->)
        //
        // Cross:
        //      aHeartLaneA (<--), aEarthLaneC (<--), aWaterLaneC (<--), aWindLaneB (<-?->)
        //
        // Destination:
        //      aHeartLaneC
        //
        for (;;) {
            //
            aIngress = aHeartLaneB[aIndex] ^ aEarthLaneD[aIndex];
            aIngress ^= (aWoodLaneB[aIndex] ^ aWoodLaneD[aIndex];
            //
            aCross = aHeartLaneA[aIndex] ^ aEarthLaneC[aIndex];
            aCross ^= aWaterLaneC[aIndex] ^ aWindLaneB[aIndex];
            //
            aHeartLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_h loop 6
        //
        // Ingress:
        //      aHeartLaneC (-->), aHeartLaneA (-->), aPoisonLaneD (-->), aIceLaneB (<-?->)
        //
        // Cross:
        //      aHeartLaneB (<--), aFireLaneB (<--), aPoisonLaneC (<--), aWoodLaneC (<-?->)
        //
        // Destination:
        //      aHeartLaneD
        //
        for (;;) {
            //
            aIngress = aHeartLaneC[aIndex] ^ aHeartLaneA[aIndex];
            aIngress ^= (aPoisonLaneD[aIndex] ^ aIceLaneB[aIndex];
            //
            aCross = aHeartLaneB[aIndex] ^ aFireLaneB[aIndex];
            aCross ^= aPoisonLaneC[aIndex] ^ aWoodLaneC[aIndex];
            //
            aHeartLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_H seed_loop_h (end)

}

void TwistExpander_Vega_Arx::Twist_A() {


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
        //      aPoisonLaneA
        //
        for (;;) {
            //
            aIngress = aSource[aIndex] ^ aKeyRowReadA[aIndex];
            //
            aCross = aSource[aIndex] ^ aKeyRowReadB[W_KEY1 - aIndex];
            //
            aPoisonLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_a loop 2
        //
        // Ingress:
        //      aPoisonLaneA (-->), aKeyRowReadB (-->)
        //
        // Cross:
        //      aSource (<--), aKeyRowReadA (<--)
        //
        // Destination:
        //      aPoisonLaneB
        //
        for (;;) {
            //
            aIngress = aPoisonLaneA[aIndex] ^ aKeyRowReadB[aIndex];
            //
            aCross = aSource[aIndex] ^ aKeyRowReadA[W_KEY1 - aIndex];
            //
            aPoisonLaneB[aIndex] = aIngress;
        }
    
        //
        // twist_loop_a loop 3
        //
        // Ingress:
        //      aPoisonLaneB (-->), aSource (-->), aKeyRowReadB (-->)
        //
        // Cross:
        //      aKeyRowReadA (<--), aPoisonLaneA (<-?->)
        //
        // Destination:
        //      aEarthLaneA
        //
        for (;;) {
            //
            aIngress = aPoisonLaneB[aIndex] ^ aSource[aIndex];
            aIngress ^= aKeyRowReadB[aIndex];
            //
            aCross = aKeyRowReadA[W_KEY1 - aIndex] ^ aPoisonLaneA[aIndex];
            //
            aEarthLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_a loop 4
        //
        // Ingress:
        //      aEarthLaneA (-->), aPoisonLaneA (<-?->)
        //
        // Cross:
        //      aPoisonLaneB (<--), aKeyRowReadB (<-?->)
        //
        // Destination:
        //      aEarthLaneB
        //
        for (;;) {
            //
            aIngress = aEarthLaneA[aIndex] ^ aPoisonLaneA[aIndex];
            //
            aCross = aPoisonLaneB[aIndex] ^ aKeyRowReadB[W_KEY1 - aIndex];
            //
            aEarthLaneB[aIndex] = aIngress;
        }
    
        //
        // twist_loop_a loop 5
        //
        // Ingress:
        //      aEarthLaneB (-->), aPoisonLaneB (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aKeyRowReadA (<-?->)
        //
        // Destination:
        //      aEarthLaneC
        //
        for (;;) {
            //
            aIngress = aEarthLaneB[aIndex] ^ aPoisonLaneB[aIndex];
            //
            aCross = aEarthLaneA[aIndex] ^ aKeyRowReadA[W_KEY1 - aIndex];
            //
            aEarthLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_a loop 6
        //
        // Ingress:
        //      aEarthLaneC (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aEarthLaneB (<--), aPoisonLaneB (<-?->)
        //
        // Destination:
        //      aEarthLaneD
        //
        for (;;) {
            //
            aIngress = aEarthLaneC[aIndex] ^ aEarthLaneA[aIndex];
            //
            aCross = aEarthLaneB[aIndex] ^ aPoisonLaneB[aIndex];
            //
            aEarthLaneD[aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_A twist_loop_a (end)

}

void TwistExpander_Vega_Arx::Twist_B() {


    // GTwistRunTwist_B twist_loop_b (start)
    {
        //
        // twist_loop_b loop 1
        //
        // Ingress:
        //      aEarthLaneA (-->), aEarthLaneB (-->), aPoisonLaneA (<-?->)
        //
        // Cross:
        //      aEarthLaneC (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aPoisonLaneC
        //
        for (;;) {
            //
            aIngress = aEarthLaneA[aIndex] ^ aEarthLaneB[aIndex];
            aIngress ^= aPoisonLaneA[aIndex];
            //
            aCross = aEarthLaneC[aIndex] ^ aEarthLaneD[aIndex];
            //
            aPoisonLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_b loop 2
        //
        // Ingress:
        //      aPoisonLaneC (-->), aEarthLaneC (-->), aPoisonLaneB (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aEarthLaneD (<--)
        //
        // Destination:
        //      aPoisonLaneD
        //
        for (;;) {
            //
            aIngress = aPoisonLaneC[aIndex] ^ aEarthLaneC[aIndex];
            aIngress ^= aPoisonLaneB[aIndex];
            //
            aCross = aEarthLaneA[aIndex] ^ aEarthLaneD[aIndex];
            //
            aPoisonLaneD[aIndex] = aIngress;
        }
    
        //
        // twist_loop_b loop 3
        //
        // Ingress:
        //      aPoisonLaneD (-->), aEarthLaneA (-->), aSource (<-?->)
        //
        // Cross:
        //      aPoisonLaneC (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aFireLaneA
        //
        for (;;) {
            //
            aIngress = aPoisonLaneD[aIndex] ^ aEarthLaneA[aIndex];
            aIngress ^= aSource[aIndex];
            //
            aCross = aPoisonLaneC[aIndex] ^ aEarthLaneC[aIndex];
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_b loop 4
        //
        // Ingress:
        //      aFireLaneA (-->), aEarthLaneD (-->), aKeyRowReadB (<-?->)
        //
        // Cross:
        //      aPoisonLaneD (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aFireLaneB
        //
        for (;;) {
            //
            aIngress = aFireLaneA[aIndex] ^ aEarthLaneD[aIndex];
            aIngress ^= aKeyRowReadB[aIndex];
            //
            aCross = aPoisonLaneD[aIndex] ^ aEarthLaneA[aIndex];
            //
            aFireLaneB[aIndex] = aIngress;
        }
    
        //
        // twist_loop_b loop 5
        //
        // Ingress:
        //      aFireLaneB (-->), aPoisonLaneD (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aPoisonLaneC (<-?->)
        //
        // Destination:
        //      aFireLaneC
        //
        for (;;) {
            //
            aIngress = aFireLaneB[aIndex] ^ aPoisonLaneD[aIndex];
            aIngress ^= aKeyRowReadA[aIndex];
            //
            aCross = aFireLaneA[aIndex] ^ aPoisonLaneC[aIndex];
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_b loop 6
        //
        // Ingress:
        //      aFireLaneC (-->), aFireLaneA (<-?->)
        //
        // Cross:
        //      aFireLaneB (<--), aEarthLaneB (<--)
        //
        // Destination:
        //      aFireLaneD
        //
        for (;;) {
            //
            aIngress = aFireLaneC[aIndex] ^ aFireLaneA[aIndex];
            //
            aCross = aFireLaneB[aIndex] ^ aEarthLaneB[aIndex];
            //
            aFireLaneD[aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_B twist_loop_b (end)

}

void TwistExpander_Vega_Arx::Twist_C() {


    // GTwistRunTwist_C twist_loop_c (start)
    {
        //
        // twist_loop_c loop 1
        //
        // Ingress:
        //      aFireLaneA (-->), aFireLaneB (-->), aPoisonLaneC (<-?->)
        //
        // Cross:
        //      aFireLaneC (<--), aFireLaneD (<--), aSource (<-?->)
        //
        // Destination:
        //      aWoodLaneA
        //
        for (;;) {
            //
            aIngress = aFireLaneA[aIndex] ^ aFireLaneB[aIndex];
            aIngress ^= aPoisonLaneC[aIndex];
            //
            aCross = aFireLaneC[aIndex] ^ aFireLaneD[aIndex];
            aCross ^= aSource[aIndex];
            //
            aWoodLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_c loop 2
        //
        // Ingress:
        //      aWoodLaneA (-->), aFireLaneC (-->), aEarthLaneB (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), aKeyRowReadB (<-?->)
        //
        // Destination:
        //      aWoodLaneB
        //
        for (;;) {
            //
            aIngress = aWoodLaneA[aIndex] ^ aFireLaneC[aIndex];
            aIngress ^= aEarthLaneB[aIndex];
            //
            aCross = aFireLaneA[aIndex] ^ aFireLaneD[aIndex];
            aCross ^= aKeyRowReadB[aIndex];
            //
            aWoodLaneB[aIndex] = aIngress;
        }
    
        //
        // twist_loop_c loop 3
        //
        // Ingress:
        //      aWoodLaneB (-->), aFireLaneA (-->), aPoisonLaneB (<-?->)
        //
        // Cross:
        //      aWoodLaneA (<--), aFireLaneC (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (;;) {
            //
            aIngress = aWoodLaneB[aIndex] ^ aFireLaneA[aIndex];
            aIngress ^= aPoisonLaneB[aIndex];
            //
            aCross = aWoodLaneA[aIndex] ^ aFireLaneC[aIndex];
            aCross ^= aEarthLaneC[aIndex];
            //
            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_c loop 4
        //
        // Ingress:
        //      aFuseLaneA (-->), aFireLaneD (-->), aPoisonLaneA (<-?->)
        //
        // Cross:
        //      aWoodLaneB (<--), aFireLaneA (<--), aKeyRowReadA (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (;;) {
            //
            aIngress = aFuseLaneA[aIndex] ^ aFireLaneD[aIndex];
            aIngress ^= aPoisonLaneA[aIndex];
            //
            aCross = aWoodLaneB[aIndex] ^ aFireLaneA[aIndex];
            aCross ^= aKeyRowReadA[aIndex];
            //
            aFuseLaneB[aIndex] = aIngress;
        }
    
        //
        // twist_loop_c loop 5
        //
        // Ingress:
        //      aFuseLaneB (-->), aWoodLaneB (-->), aPoisonLaneD (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aWoodLaneA (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (;;) {
            //
            aIngress = aFuseLaneB[aIndex] ^ aWoodLaneB[aIndex];
            aIngress ^= aPoisonLaneD[aIndex];
            //
            aCross = aFuseLaneA[aIndex] ^ aWoodLaneA[aIndex];
            aCross ^= aEarthLaneD[aIndex];
            //
            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_c loop 6
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aFireLaneB (<--)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (;;) {
            //
            aIngress = aFuseLaneC[aIndex] ^ aFuseLaneA[aIndex];
            aIngress ^= aEarthLaneA[aIndex];
            //
            aCross = aFuseLaneB[aIndex] ^ aFireLaneB[aIndex];
            //
            aFuseLaneD[aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_C twist_loop_c (end)

}

void TwistExpander_Vega_Arx::Twist_D() {


    // GTwistRunTwist_D twist_loop_d (start)
    {
        //
        // twist_loop_d loop 1
        //
        // Ingress:
        //      aWindLaneA (-->), aWindLaneB (-->), aPoisonLaneA (-->), aPoisonLaneC (<-?->)
        //
        // Cross:
        //      aWindLaneC (<--), aWindLaneD (<--), aPoisonLaneD (<-?->)
        //
        // Destination:
        //      aSpiritLaneA
        //
        for (;;) {
            //
            aIngress = aWindLaneA[aIndex] ^ aWindLaneB[aIndex];
            aIngress ^= (aPoisonLaneA[aIndex] ^ aPoisonLaneC[aIndex];
            //
            aCross = aWindLaneC[aIndex] ^ aWindLaneD[aIndex];
            aCross ^= aPoisonLaneD[aIndex];
            //
            aSpiritLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 2
        //
        // Ingress:
        //      aSpiritLaneA (-->), aWindLaneC (-->), aEarthLaneC (-->), aFireLaneC (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aWindLaneD (<--), aFireLaneD (<-?->)
        //
        // Destination:
        //      aSpiritLaneB
        //
        for (;;) {
            //
            aIngress = aSpiritLaneA[aIndex] ^ aWindLaneC[aIndex];
            aIngress ^= (aEarthLaneC[aIndex] ^ aFireLaneC[aIndex];
            //
            aCross = aWindLaneA[aIndex] ^ aWindLaneD[aIndex];
            aCross ^= aFireLaneD[aIndex];
            //
            aSpiritLaneB[aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 3
        //
        // Ingress:
        //      aSpiritLaneB (-->), aWindLaneA (-->), aSource (-->), aKeyRowReadB (<-?->)
        //
        // Cross:
        //      aSpiritLaneA (<--), aWindLaneC (<--), aFireLaneB (<-?->)
        //
        // Destination:
        //      aWaterLaneA
        //
        for (;;) {
            //
            aIngress = aSpiritLaneB[aIndex] ^ aWindLaneA[aIndex];
            aIngress ^= (aSource[aIndex] ^ aKeyRowReadB[W_KEY1 - aIndex];
            //
            aCross = aSpiritLaneA[aIndex] ^ aWindLaneC[aIndex];
            aCross ^= aFireLaneB[aIndex];
            //
            aWaterLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 4
        //
        // Ingress:
        //      aWaterLaneA (-->), aWindLaneD (-->), aFireLaneA (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aSpiritLaneB (<--), aWindLaneA (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aWaterLaneB
        //
        for (;;) {
            //
            aIngress = aWaterLaneA[aIndex] ^ aWindLaneD[aIndex];
            aIngress ^= (aFireLaneA[aIndex] ^ aEarthLaneA[aIndex];
            //
            aCross = aSpiritLaneB[aIndex] ^ aWindLaneA[aIndex];
            aCross ^= aEarthLaneD[aIndex];
            //
            aWaterLaneB[aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 5
        //
        // Ingress:
        //      aWaterLaneB (-->), aSpiritLaneB (-->), aPoisonLaneB (-->), aWoodLaneB (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aSpiritLaneA (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aWaterLaneC
        //
        for (;;) {
            //
            aIngress = aWaterLaneB[aIndex] ^ aSpiritLaneB[aIndex];
            aIngress ^= (aPoisonLaneB[aIndex] ^ aWoodLaneB[aIndex];
            //
            aCross = aWaterLaneA[aIndex] ^ aSpiritLaneA[aIndex];
            aCross ^= aEarthLaneB[aIndex];
            //
            aWaterLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 6
        //
        // Ingress:
        //      aWaterLaneC (-->), aWaterLaneA (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aWaterLaneB (<--), aWindLaneB (<--), aWoodLaneA (<-?->)
        //
        // Destination:
        //      aWaterLaneD
        //
        for (;;) {
            //
            aIngress = aWaterLaneC[aIndex] ^ aWaterLaneA[aIndex];
            aIngress ^= aKeyRowReadA[W_KEY1 - aIndex];
            //
            aCross = aWaterLaneB[aIndex] ^ aWindLaneB[aIndex];
            aCross ^= aWoodLaneA[aIndex];
            //
            aWaterLaneD[aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_D twist_loop_d (end)

}

void TwistExpander_Vega_Arx::Twist_E() {


    // GTwistRunTwist_E twist_loop_e (start)
    {
        //
        // twist_loop_e loop 1
        //
        // Ingress:
        //      aWaterLaneA (-->), aWaterLaneB (-->), aEarthLaneC (-->), aWindLaneD (<-?->)
        //
        // Cross:
        //      aWaterLaneC (<--), aWaterLaneD (<--), aFireLaneA (<--), aWoodLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (;;) {
            //
            aIngress = aWaterLaneA[aIndex] ^ aWaterLaneB[aIndex];
            aIngress ^= (aEarthLaneC[aIndex] ^ aWindLaneD[aIndex];
            //
            aCross = aWaterLaneC[aIndex] ^ aWaterLaneD[aIndex];
            aCross ^= aFireLaneA[aIndex] ^ aWoodLaneB[aIndex];
            //
            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 2
        //
        // Ingress:
        //      aFuseLaneA (-->), aWaterLaneC (-->), aWindLaneB (-->), aEarthLaneB (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWaterLaneD (<--), aWoodLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (;;) {
            //
            aIngress = aFuseLaneA[aIndex] ^ aWaterLaneC[aIndex];
            aIngress ^= (aWindLaneB[aIndex] ^ aEarthLaneB[aIndex];
            //
            aCross = aWaterLaneA[aIndex] ^ aWaterLaneD[aIndex];
            aCross ^= aWoodLaneA[aIndex];
            //
            aFuseLaneB[aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 3
        //
        // Ingress:
        //      aFuseLaneB (-->), aWaterLaneA (-->), aKeyRowReadB (-->), aWindLaneC (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aWaterLaneC (<--), aSource (<-?->)
        //
        // Destination:
        //      aHeartLaneA
        //
        for (;;) {
            //
            aIngress = aFuseLaneB[aIndex] ^ aWaterLaneA[aIndex];
            aIngress ^= (aKeyRowReadB[aIndex] ^ aWindLaneC[aIndex];
            //
            aCross = aFuseLaneA[aIndex] ^ aWaterLaneC[aIndex];
            aCross ^= aSource[aIndex];
            //
            aHeartLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 4
        //
        // Ingress:
        //      aHeartLaneA (-->), aWaterLaneD (-->), aEarthLaneD (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aWaterLaneA (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aHeartLaneB
        //
        for (;;) {
            //
            aIngress = aHeartLaneA[aIndex] ^ aWaterLaneD[aIndex];
            aIngress ^= (aEarthLaneD[aIndex] ^ aKeyRowReadA[W_KEY1 - aIndex];
            //
            aCross = aFuseLaneB[aIndex] ^ aWaterLaneA[aIndex];
            aCross ^= aEarthLaneA[aIndex];
            //
            aHeartLaneB[aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 5
        //
        // Ingress:
        //      aHeartLaneB (-->), aFuseLaneB (-->), aPoisonLaneC (-->), aWindLaneA (<-?->)
        //
        // Cross:
        //      aHeartLaneA (<--), aFuseLaneA (<--), aPoisonLaneD (<-?->)
        //
        // Destination:
        //      aHeartLaneC
        //
        for (;;) {
            //
            aIngress = aHeartLaneB[aIndex] ^ aFuseLaneB[aIndex];
            aIngress ^= (aPoisonLaneC[aIndex] ^ aWindLaneA[aIndex];
            //
            aCross = aHeartLaneA[aIndex] ^ aFuseLaneA[aIndex];
            aCross ^= aPoisonLaneD[aIndex];
            //
            aHeartLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 6
        //
        // Ingress:
        //      aHeartLaneC (-->), aHeartLaneA (-->), aFireLaneC (-->), aFireLaneB (<-?->)
        //
        // Cross:
        //      aHeartLaneB (<--), aWaterLaneB (<--), aFireLaneD (<-?->)
        //
        // Destination:
        //      aHeartLaneD
        //
        for (;;) {
            //
            aIngress = aHeartLaneC[aIndex] ^ aHeartLaneA[aIndex];
            aIngress ^= (aFireLaneC[aIndex] ^ aFireLaneB[aIndex];
            //
            aCross = aHeartLaneB[aIndex] ^ aWaterLaneB[aIndex];
            aCross ^= aFireLaneD[aIndex];
            //
            aHeartLaneD[aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_E twist_loop_e (end)

}

void TwistExpander_Vega_Arx::GROW_A() {


    // GROW_A grow_key_a (start)
    {
        //
        // grow_key_a loop 1
        //
        // Ingress:
        //      aHeartLaneA (-->), aHeartLaneB (-->), aEarthLaneC (-->), aPoisonLaneC (<-?->)
        //
        // Cross:
        //      aHeartLaneC (<--), aHeartLaneD (<--), aPoisonLaneB (<--), aSpiritLaneA (<-?->)
        //
        // Destination:
        //      aIceLaneA
        //
        for (;;) {
            //
            aIngress = aHeartLaneA[aIndex] ^ aHeartLaneB[aIndex];
            aIngress ^= (aEarthLaneC[aIndex] ^ aPoisonLaneC[aIndex];
            //
            aCross = aHeartLaneC[aIndex] ^ aHeartLaneD[aIndex];
            aCross ^= aPoisonLaneB[aIndex] ^ aSpiritLaneA[aIndex];
            //
            aIceLaneA[aIndex] = aIngress;
        }
    
        //
        // grow_key_a loop 2
        //
        // Ingress:
        //      aIceLaneA (-->), aHeartLaneC (-->), aSpiritLaneB (-->), aWaterLaneB (<-?->)
        //
        // Cross:
        //      aHeartLaneA (<--), aHeartLaneD (<--), aWindLaneB (<--), aFireLaneD (<-?->)
        //
        // Destination:
        //      aIceLaneB
        //
        for (;;) {
            //
            aIngress = aIceLaneA[aIndex] ^ aHeartLaneC[aIndex];
            aIngress ^= (aSpiritLaneB[aIndex] ^ aWaterLaneB[aIndex];
            //
            aCross = aHeartLaneA[aIndex] ^ aHeartLaneD[aIndex];
            aCross ^= aWindLaneB[aIndex] ^ aFireLaneD[aIndex];
            //
            aIceLaneB[aIndex] = aIngress;
        }
    
        //
        // grow_key_a loop 3
        //
        // Ingress:
        //      aIceLaneB (-->), aHeartLaneD (-->), aSpiritLaneD (-->), aWindLaneA (<-?->)
        //
        // Cross:
        //      aIceLaneA (<--), aHeartLaneB (<--), aWaterLaneA (<--), aPoisonLaneD (<-?->)
        //
        // Destination:
        //      aIceLaneC
        //
        for (;;) {
            //
            aIngress = aIceLaneB[aIndex] ^ aHeartLaneD[aIndex];
            aIngress ^= (aSpiritLaneD[aIndex] ^ aWindLaneA[aIndex];
            //
            aCross = aIceLaneA[aIndex] ^ aHeartLaneB[aIndex];
            aCross ^= aWaterLaneA[aIndex] ^ aPoisonLaneD[aIndex];
            //
            aIceLaneC[aIndex] = aIngress;
        }
    
        //
        // grow_key_a loop 4
        //
        // Ingress:
        //      aIceLaneC (-->), aIceLaneA (-->), aFireLaneC (-->), aSpiritLaneC (<-?->)
        //
        // Cross:
        //      aIceLaneB (<--), aHeartLaneC (<--), aEarthLaneD (<--), aPoisonLaneA (<-?->)
        //
        // Destination:
        //      aIceLaneD
        //
        for (;;) {
            //
            aIngress = aIceLaneC[aIndex] ^ aIceLaneA[aIndex];
            aIngress ^= (aFireLaneC[aIndex] ^ aSpiritLaneC[aIndex];
            //
            aCross = aIceLaneB[aIndex] ^ aHeartLaneC[aIndex];
            aCross ^= aEarthLaneD[aIndex] ^ aPoisonLaneA[aIndex];
            //
            aIceLaneD[aIndex] = aIngress;
        }
    }
    // GROW_A grow_key_a (end)

}

void TwistExpander_Vega_Arx::GROW_B() {


    // GROW_B grow_key_b (start)
    {
        //
        // grow_key_b loop 1
        //
        // Ingress:
        //      aIceLaneA (-->), aIceLaneB (-->), aWindLaneD (-->), aWoodLaneB (<-?->)
        //
        // Cross:
        //      aIceLaneC (<--), aIceLaneD (<--), aWindLaneC (<--), aWaterLaneC (<-?->)
        //
        // Destination:
        //      aSpiritLaneA
        //
        for (;;) {
            //
            aIngress = aIceLaneA[aIndex] ^ aIceLaneB[aIndex];
            aIngress ^= (aWindLaneD[aIndex] ^ aWoodLaneB[aIndex];
            //
            aCross = aIceLaneC[aIndex] ^ aIceLaneD[aIndex];
            aCross ^= aWindLaneC[aIndex] ^ aWaterLaneC[aIndex];
            //
            aSpiritLaneA[aIndex] = aIngress;
        }
    
        //
        // grow_key_b loop 2
        //
        // Ingress:
        //      aSpiritLaneA (-->), aIceLaneC (-->), aHeartLaneA (-->), aHeartLaneD (<-?->)
        //
        // Cross:
        //      aIceLaneA (<--), aIceLaneD (<--), aWoodLaneA (<--), aHeartLaneB (<-?->)
        //
        // Destination:
        //      aSpiritLaneB
        //
        for (;;) {
            //
            aIngress = aSpiritLaneA[aIndex] ^ aIceLaneC[aIndex];
            aIngress ^= (aHeartLaneA[aIndex] ^ aHeartLaneD[aIndex];
            //
            aCross = aIceLaneA[aIndex] ^ aIceLaneD[aIndex];
            aCross ^= aWoodLaneA[aIndex] ^ aHeartLaneB[aIndex];
            //
            aSpiritLaneB[aIndex] = aIngress;
        }
    
        //
        // grow_key_b loop 3
        //
        // Ingress:
        //      aSpiritLaneB (-->), aIceLaneD (-->), aKeyRowReadB (-->), aEarthLaneB (<-?->)
        //
        // Cross:
        //      aSpiritLaneA (<--), aIceLaneB (<--), aHeartLaneC (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aSpiritLaneC
        //
        for (;;) {
            //
            aIngress = aSpiritLaneB[aIndex] ^ aIceLaneD[aIndex];
            aIngress ^= (aKeyRowReadB[aIndex] ^ aEarthLaneB[aIndex];
            //
            aCross = aSpiritLaneA[aIndex] ^ aIceLaneB[aIndex];
            aCross ^= aHeartLaneC[aIndex] ^ aEarthLaneA[aIndex];
            //
            aSpiritLaneC[aIndex] = aIngress;
        }
    
        //
        // grow_key_b loop 4
        //
        // Ingress:
        //      aSpiritLaneC (-->), aSpiritLaneA (-->), aWaterLaneD (-->), aFireLaneB (<-?->)
        //
        // Cross:
        //      aSpiritLaneB (<--), aIceLaneC (<--), aFireLaneA (<--), aKeyRowReadA (<-?->)
        //
        // Destination:
        //      aSpiritLaneD
        //
        for (;;) {
            //
            aIngress = aSpiritLaneC[aIndex] ^ aSpiritLaneA[aIndex];
            aIngress ^= (aWaterLaneD[aIndex] ^ aFireLaneB[aIndex];
            //
            aCross = aSpiritLaneB[aIndex] ^ aIceLaneC[aIndex];
            aCross ^= aFireLaneA[aIndex] ^ aKeyRowReadA[aIndex];
            //
            aSpiritLaneD[aIndex] = aIngress;
        }
    }
    // GROW_B grow_key_b (end)

}
