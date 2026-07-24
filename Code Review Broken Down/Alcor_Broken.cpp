#include "TwistExpander_Alcor_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Alcor_Arx::KDF_A_A() {


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

void TwistExpander_Alcor_Arx::KDF_A_B() {


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
        //      aPoisonLaneC (-->), aEarthLaneC (-->), pSnow (<-?->)
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
            aIngress ^= pSnow[aIndex];
            //
            aCross = aEarthLaneA[aIndex] ^ aEarthLaneD[aIndex];
            //
            aPoisonLaneD[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_b loop 3
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
        // kdf_a_loop_b loop 4
        //
        // Ingress:
        //      aFireLaneA (-->), aEarthLaneD (-->), aPoisonLaneB (<-?->)
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
            aIngress ^= aPoisonLaneB[aIndex];
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

void TwistExpander_Alcor_Arx::KDF_A_C() {


    // GSeedRunKDF_A_C kdf_a_loop_c (start)
    {
        //
        // kdf_a_loop_c loop 1
        //
        // Ingress:
        //      aFireLaneA (-->), aFireLaneB (-->), aPoisonLaneD (-->), aEarthLaneC (<-?->)
        //
        // Cross:
        //      aFireLaneC (<--), aFireLaneD (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (;;) {
            //
            aIngress = aFireLaneA[aIndex] ^ aFireLaneB[aIndex];
            aIngress ^= (aPoisonLaneD[aIndex] ^ aEarthLaneC[aIndex];
            //
            aCross = aFireLaneC[aIndex] ^ aFireLaneD[aIndex];
            aCross ^= aEarthLaneB[aIndex];
            //
            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_c loop 2
        //
        // Ingress:
        //      aFuseLaneA (-->), aFireLaneC (-->), aPoisonLaneA (-->), aSource (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), aPoisonLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (;;) {
            //
            aIngress = aFuseLaneA[aIndex] ^ aFireLaneC[aIndex];
            aIngress ^= (aPoisonLaneA[aIndex] ^ aSource[aIndex];
            //
            aCross = aFireLaneA[aIndex] ^ aFireLaneD[aIndex];
            aCross ^= aPoisonLaneC[aIndex];
            //
            aFuseLaneB[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_c loop 3
        //
        // Ingress:
        //      aFuseLaneB (-->), aFireLaneD (-->), pSnow (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aFireLaneB (<--), aPoisonLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (;;) {
            //
            aIngress = aFuseLaneB[aIndex] ^ aFireLaneD[aIndex];
            aIngress ^= pSnow[aIndex];
            //
            aCross = aFuseLaneA[aIndex] ^ aFireLaneB[aIndex];
            aCross ^= aPoisonLaneB[aIndex];
            //
            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_c loop 4
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aEarthLaneD (<-?->)
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
            aIngress ^= aEarthLaneD[aIndex];
            //
            aCross = aFuseLaneB[aIndex] ^ aFireLaneC[aIndex];
            aCross ^= aEarthLaneA[aIndex];
            //
            aFuseLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_C kdf_a_loop_c (end)

}

void TwistExpander_Alcor_Arx::KDF_A_D() {


    // GSeedRunKDF_A_D kdf_a_loop_d (start)
    {
        //
        // kdf_a_loop_d loop 1
        //
        // Ingress:
        //      aWindLaneA (-->), aWindLaneB (-->), aPoisonLaneC (-->), aPoisonLaneB (<-?->)
        //
        // Cross:
        //      aWindLaneC (<--), aWindLaneD (<--), aEarthLaneC (<--), aFireLaneB (<-?->)
        //
        // Destination:
        //      aWaterLaneA
        //
        for (;;) {
            //
            aIngress = aWindLaneA[aIndex] ^ aWindLaneB[aIndex];
            aIngress ^= (aPoisonLaneC[aIndex] ^ aPoisonLaneB[aIndex];
            //
            aCross = aWindLaneC[aIndex] ^ aWindLaneD[aIndex];
            aCross ^= aEarthLaneC[aIndex] ^ aFireLaneB[aIndex];
            //
            aWaterLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_d loop 2
        //
        // Ingress:
        //      aWaterLaneA (-->), aWindLaneC (-->), aFireLaneC (-->), aSource (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aWindLaneD (<--), pSnow (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aWaterLaneB
        //
        for (;;) {
            //
            aIngress = aWaterLaneA[aIndex] ^ aWindLaneC[aIndex];
            aIngress ^= (aFireLaneC[aIndex] ^ aSource[aIndex];
            //
            aCross = aWindLaneA[aIndex] ^ aWindLaneD[aIndex];
            aCross ^= pSnow[aIndex] ^ aEarthLaneB[aIndex];
            //
            aWaterLaneB[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_d loop 3
        //
        // Ingress:
        //      aWaterLaneB (-->), aWindLaneD (-->), aFireLaneD (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWindLaneB (<--), aPoisonLaneA (<-?->)
        //
        // Destination:
        //      aWaterLaneC
        //
        for (;;) {
            //
            aIngress = aWaterLaneB[aIndex] ^ aWindLaneD[aIndex];
            aIngress ^= (aFireLaneD[aIndex] ^ aEarthLaneD[aIndex];
            //
            aCross = aWaterLaneA[aIndex] ^ aWindLaneB[aIndex];
            aCross ^= aPoisonLaneA[aIndex];
            //
            aWaterLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_d loop 4
        //
        // Ingress:
        //      aWaterLaneC (-->), aWaterLaneA (-->), aFireLaneA (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aWaterLaneB (<--), aWindLaneC (<--), aPoisonLaneD (<-?->)
        //
        // Destination:
        //      aWaterLaneD
        //
        for (;;) {
            //
            aIngress = aWaterLaneC[aIndex] ^ aWaterLaneA[aIndex];
            aIngress ^= (aFireLaneA[aIndex] ^ aEarthLaneA[aIndex];
            //
            aCross = aWaterLaneB[aIndex] ^ aWindLaneC[aIndex];
            aCross ^= aPoisonLaneD[aIndex];
            //
            aWaterLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_D kdf_a_loop_d (end)

}

void TwistExpander_Alcor_Arx::KDF_B_A() {


    // GSeedRunKDF_B_A kdf_b_loop_a (start)
    {
        //
        // kdf_b_loop_a loop 1
        //
        // Ingress:
        //      aWaterLaneA (-->), aWaterLaneB (-->), aFireLaneC (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aWaterLaneC (<--), aWaterLaneD (<--), aFireLaneD (<--), aWindLaneD (<-?->)
        //
        // Destination:
        //      aWoodLaneA
        //
        for (;;) {
            //
            aIngress = aWaterLaneA[aIndex] ^ aWaterLaneB[aIndex];
            aIngress ^= (aFireLaneC[aIndex] ^ aEarthLaneD[aIndex];
            //
            aCross = aWaterLaneC[aIndex] ^ aWaterLaneD[aIndex];
            aCross ^= aFireLaneD[aIndex] ^ aWindLaneD[aIndex];
            //
            aWoodLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_a loop 2
        //
        // Ingress:
        //      aWoodLaneA (-->), aWaterLaneC (-->), aPoisonLaneD (-->), aFireLaneB (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWaterLaneD (<--), aEarthLaneA (<--), aPoisonLaneB (<-?->)
        //
        // Destination:
        //      aWoodLaneB
        //
        for (;;) {
            //
            aIngress = aWoodLaneA[aIndex] ^ aWaterLaneC[aIndex];
            aIngress ^= (aPoisonLaneD[aIndex] ^ aFireLaneB[aIndex];
            //
            aCross = aWaterLaneA[aIndex] ^ aWaterLaneD[aIndex];
            aCross ^= aEarthLaneA[aIndex] ^ aPoisonLaneB[aIndex];
            //
            aWoodLaneB[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_a loop 3
        //
        // Ingress:
        //      aWoodLaneB (-->), aWaterLaneD (-->), aPoisonLaneC (-->), aWindLaneC (<-?->)
        //
        // Cross:
        //      aWoodLaneA (<--), aWaterLaneB (<--), aEarthLaneB (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aWoodLaneC
        //
        for (;;) {
            //
            aIngress = aWoodLaneB[aIndex] ^ aWaterLaneD[aIndex];
            aIngress ^= (aPoisonLaneC[aIndex] ^ aWindLaneC[aIndex];
            //
            aCross = aWoodLaneA[aIndex] ^ aWaterLaneB[aIndex];
            aCross ^= aEarthLaneB[aIndex] ^ aEarthLaneC[aIndex];
            //
            aWoodLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_a loop 4
        //
        // Ingress:
        //      aWoodLaneC (-->), aWoodLaneA (-->), aWindLaneA (-->), aPoisonLaneA (<-?->)
        //
        // Cross:
        //      aWoodLaneB (<--), aSource (<--), aFireLaneA (<--), aWindLaneB (<-?->)
        //
        // Destination:
        //      aWoodLaneD
        //
        for (;;) {
            //
            aIngress = aWoodLaneC[aIndex] ^ aWoodLaneA[aIndex];
            aIngress ^= (aWindLaneA[aIndex] ^ aPoisonLaneA[aIndex];
            //
            aCross = aWoodLaneB[aIndex] ^ aSource[aIndex];
            aCross ^= aFireLaneA[aIndex] ^ aWindLaneB[aIndex];
            //
            aWoodLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_A kdf_b_loop_a (end)

}

void TwistExpander_Alcor_Arx::KDF_B_B() {


    // GSeedRunKDF_B_B kdf_b_loop_b (start)
    {
        //
        // kdf_b_loop_b loop 1
        //
        // Ingress:
        //      aWoodLaneA (-->), aWoodLaneB (-->), aWindLaneD (-->), aWaterLaneD (<-?->)
        //
        // Cross:
        //      aWoodLaneC (<--), aWoodLaneD (<--), aFireLaneA (<--), aWaterLaneC (<-?->)
        //
        // Destination:
        //      aSpiritLaneA
        //
        for (;;) {
            //
            aIngress = aWoodLaneA[aIndex] ^ aWoodLaneB[aIndex];
            aIngress ^= (aWindLaneD[aIndex] ^ aWaterLaneD[aIndex];
            //
            aCross = aWoodLaneC[aIndex] ^ aWoodLaneD[aIndex];
            aCross ^= aFireLaneA[aIndex] ^ aWaterLaneC[aIndex];
            //
            aSpiritLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_b loop 2
        //
        // Ingress:
        //      aSpiritLaneA (-->), aWoodLaneC (-->), aEarthLaneB (-->), aFireLaneC (<-?->)
        //
        // Cross:
        //      aWoodLaneA (<--), aWoodLaneD (<--), aFireLaneB (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aSpiritLaneB
        //
        for (;;) {
            //
            aIngress = aSpiritLaneA[aIndex] ^ aWoodLaneC[aIndex];
            aIngress ^= (aEarthLaneB[aIndex] ^ aFireLaneC[aIndex];
            //
            aCross = aWoodLaneA[aIndex] ^ aWoodLaneD[aIndex];
            aCross ^= aFireLaneB[aIndex] ^ aEarthLaneC[aIndex];
            //
            aSpiritLaneB[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_b loop 3
        //
        // Ingress:
        //      aSpiritLaneB (-->), aWoodLaneD (-->), aEarthLaneA (-->), aWindLaneC (<-?->)
        //
        // Cross:
        //      aSpiritLaneA (<--), aWoodLaneB (<--), aWaterLaneA (<--), aWaterLaneB (<-?->)
        //
        // Destination:
        //      aSpiritLaneC
        //
        for (;;) {
            //
            aIngress = aSpiritLaneB[aIndex] ^ aWoodLaneD[aIndex];
            aIngress ^= (aEarthLaneA[aIndex] ^ aWindLaneC[aIndex];
            //
            aCross = aSpiritLaneA[aIndex] ^ aWoodLaneB[aIndex];
            aCross ^= aWaterLaneA[aIndex] ^ aWaterLaneB[aIndex];
            //
            aSpiritLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_b loop 4
        //
        // Ingress:
        //      aSpiritLaneC (-->), aSpiritLaneA (-->), aWindLaneB (-->), aFireLaneD (<-?->)
        //
        // Cross:
        //      aSpiritLaneB (<--), aWoodLaneC (<--), aWindLaneA (<--), aSource (<-?->)
        //
        // Destination:
        //      aSpiritLaneD
        //
        for (;;) {
            //
            aIngress = aSpiritLaneC[aIndex] ^ aSpiritLaneA[aIndex];
            aIngress ^= (aWindLaneB[aIndex] ^ aFireLaneD[aIndex];
            //
            aCross = aSpiritLaneB[aIndex] ^ aWoodLaneC[aIndex];
            aCross ^= aWindLaneA[aIndex] ^ aSource[aIndex];
            //
            aSpiritLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_B kdf_b_loop_b (end)

}

void TwistExpander_Alcor_Arx::KDF_B_C() {


    // GSeedRunKDF_B_C kdf_b_loop_c (start)
    {
        //
        // kdf_b_loop_c loop 1
        //
        // Ingress:
        //      aSpiritLaneA (-->), aSpiritLaneB (-->), aWaterLaneC (-->), aWoodLaneB (<-?->)
        //
        // Cross:
        //      aSpiritLaneC (<--), aSpiritLaneD (<--), aWoodLaneD (<--), aFireLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (;;) {
            //
            aIngress = aSpiritLaneA[aIndex] ^ aSpiritLaneB[aIndex];
            aIngress ^= (aWaterLaneC[aIndex] ^ aWoodLaneB[aIndex];
            //
            aCross = aSpiritLaneC[aIndex] ^ aSpiritLaneD[aIndex];
            aCross ^= aWoodLaneD[aIndex] ^ aFireLaneC[aIndex];
            //
            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_c loop 2
        //
        // Ingress:
        //      aFuseLaneA (-->), aSpiritLaneC (-->), aWaterLaneD (-->), aWindLaneC (<-?->)
        //
        // Cross:
        //      aSpiritLaneA (<--), aSpiritLaneD (<--), aWoodLaneC (<--), aWaterLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (;;) {
            //
            aIngress = aFuseLaneA[aIndex] ^ aSpiritLaneC[aIndex];
            aIngress ^= (aWaterLaneD[aIndex] ^ aWindLaneC[aIndex];
            //
            aCross = aSpiritLaneA[aIndex] ^ aSpiritLaneD[aIndex];
            aCross ^= aWoodLaneC[aIndex] ^ aWaterLaneB[aIndex];
            //
            aFuseLaneB[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_c loop 3
        //
        // Ingress:
        //      aFuseLaneB (-->), aSpiritLaneD (-->), aWindLaneB (-->), aWaterLaneA (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aSpiritLaneB (<--), aWoodLaneA (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (;;) {
            //
            aIngress = aFuseLaneB[aIndex] ^ aSpiritLaneD[aIndex];
            aIngress ^= (aWindLaneB[aIndex] ^ aWaterLaneA[aIndex];
            //
            aCross = aFuseLaneA[aIndex] ^ aSpiritLaneB[aIndex];
            aCross ^= aWoodLaneA[aIndex] ^ aEarthLaneD[aIndex];
            //
            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_c loop 4
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aWindLaneD (-->), aFireLaneD (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aSpiritLaneC (<--), aSource (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (;;) {
            //
            aIngress = aFuseLaneC[aIndex] ^ aFuseLaneA[aIndex];
            aIngress ^= (aWindLaneD[aIndex] ^ aFireLaneD[aIndex];
            //
            aCross = aFuseLaneB[aIndex] ^ aSpiritLaneC[aIndex];
            aCross ^= aSource[aIndex] ^ aWindLaneA[aIndex];
            //
            aFuseLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_C kdf_b_loop_c (end)

}

void TwistExpander_Alcor_Arx::KDF_B_D() {


    // GSeedRunKDF_B_D kdf_b_loop_d (start)
    {
        //
        // kdf_b_loop_d loop 1
        //
        // Ingress:
        //      aPoisonLaneA (-->), aPoisonLaneB (-->), aFireLaneB (-->), aWindLaneD (<-?->)
        //
        // Cross:
        //      aPoisonLaneC (<--), aPoisonLaneD (<--), aSpiritLaneA (<--), aWoodLaneD (<-?->)
        //
        // Destination:
        //      aHeartLaneA
        //
        for (;;) {
            //
            aIngress = aPoisonLaneA[aIndex] ^ aPoisonLaneB[aIndex];
            aIngress ^= (aFireLaneB[aIndex] ^ aWindLaneD[aIndex];
            //
            aCross = aPoisonLaneC[aIndex] ^ aPoisonLaneD[aIndex];
            aCross ^= aSpiritLaneA[aIndex] ^ aWoodLaneD[aIndex];
            //
            aHeartLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_d loop 2
        //
        // Ingress:
        //      aHeartLaneA (-->), aPoisonLaneC (-->), aSpiritLaneD (-->), aFireLaneA (<-?->)
        //
        // Cross:
        //      aPoisonLaneA (<--), aPoisonLaneD (<--), aSpiritLaneB (<--), aWaterLaneD (<-?->)
        //
        // Destination:
        //      aHeartLaneB
        //
        for (;;) {
            //
            aIngress = aHeartLaneA[aIndex] ^ aPoisonLaneC[aIndex];
            aIngress ^= (aSpiritLaneD[aIndex] ^ aFireLaneA[aIndex];
            //
            aCross = aPoisonLaneA[aIndex] ^ aPoisonLaneD[aIndex];
            aCross ^= aSpiritLaneB[aIndex] ^ aWaterLaneD[aIndex];
            //
            aHeartLaneB[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_d loop 3
        //
        // Ingress:
        //      aHeartLaneB (-->), aPoisonLaneD (-->), aWaterLaneB (-->), aSpiritLaneC (<-?->)
        //
        // Cross:
        //      aHeartLaneA (<--), aPoisonLaneB (<--), aWaterLaneA (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aHeartLaneC
        //
        for (;;) {
            //
            aIngress = aHeartLaneB[aIndex] ^ aPoisonLaneD[aIndex];
            aIngress ^= (aWaterLaneB[aIndex] ^ aSpiritLaneC[aIndex];
            //
            aCross = aHeartLaneA[aIndex] ^ aPoisonLaneB[aIndex];
            aCross ^= aWaterLaneA[aIndex] ^ aWindLaneC[aIndex];
            //
            aHeartLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_d loop 4
        //
        // Ingress:
        //      aHeartLaneC (-->), aHeartLaneA (-->), aWoodLaneB (-->), aWoodLaneC (<-?->)
        //
        // Cross:
        //      aHeartLaneB (<--), aPoisonLaneC (<--), aWoodLaneA (<--), aWaterLaneC (<-?->)
        //
        // Destination:
        //      aHeartLaneD
        //
        for (;;) {
            //
            aIngress = aHeartLaneC[aIndex] ^ aHeartLaneA[aIndex];
            aIngress ^= (aWoodLaneB[aIndex] ^ aWoodLaneC[aIndex];
            //
            aCross = aHeartLaneB[aIndex] ^ aPoisonLaneC[aIndex];
            aCross ^= aWoodLaneA[aIndex] ^ aWaterLaneC[aIndex];
            //
            aHeartLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_D kdf_b_loop_d (end)

}

void TwistExpander_Alcor_Arx::Seed_A() {


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

void TwistExpander_Alcor_Arx::Seed_B() {


    // GSeedRunSeed_B seed_loop_b (start)
    {
        //
        // seed_loop_b loop 1
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
        // seed_loop_b loop 2
        //
        // Ingress:
        //      aPoisonLaneC (-->), aEarthLaneC (-->), aKeyRowReadA (<-?->)
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
            aIngress ^= aKeyRowReadA[W_KEY1 - aIndex];
            //
            aCross = aEarthLaneA[aIndex] ^ aEarthLaneD[aIndex];
            //
            aPoisonLaneD[aIndex] = aIngress;
        }
    
        //
        // seed_loop_b loop 3
        //
        // Ingress:
        //      aPoisonLaneD (-->), aEarthLaneA (-->), aKeyRowReadB (<-?->)
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
            aIngress ^= aKeyRowReadB[aIndex];
            //
            aCross = aPoisonLaneC[aIndex] ^ aEarthLaneC[aIndex];
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_b loop 4
        //
        // Ingress:
        //      aFireLaneA (-->), aEarthLaneD (-->), aSource (<-?->)
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
            aIngress ^= aSource[aIndex];
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

void TwistExpander_Alcor_Arx::Seed_C() {


    // GSeedRunSeed_C seed_loop_c (start)
    {
        //
        // seed_loop_c loop 1
        //
        // Ingress:
        //      aFireLaneA (-->), aFireLaneB (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aFireLaneC (<--), aFireLaneD (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aHeartLaneA
        //
        for (;;) {
            //
            aIngress = aFireLaneA[aIndex] ^ aFireLaneB[aIndex];
            aIngress ^= aKeyRowReadA[W_KEY1 - aIndex];
            //
            aCross = aFireLaneC[aIndex] ^ aFireLaneD[aIndex];
            aCross ^= aEarthLaneB[aIndex];
            //
            aHeartLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 2
        //
        // Ingress:
        //      aHeartLaneA (-->), aFireLaneC (-->), aEarthLaneC (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aHeartLaneB
        //
        for (;;) {
            //
            aIngress = aHeartLaneA[aIndex] ^ aFireLaneC[aIndex];
            aIngress ^= aEarthLaneC[aIndex];
            //
            aCross = aFireLaneA[aIndex] ^ aFireLaneD[aIndex];
            aCross ^= aEarthLaneA[aIndex];
            //
            aHeartLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 3
        //
        // Ingress:
        //      aHeartLaneB (-->), aFireLaneA (-->), aKeyRowReadB (<-?->)
        //
        // Cross:
        //      aHeartLaneA (<--), aFireLaneC (<--), aPoisonLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (;;) {
            //
            aIngress = aHeartLaneB[aIndex] ^ aFireLaneA[aIndex];
            aIngress ^= aKeyRowReadB[W_KEY1 - aIndex];
            //
            aCross = aHeartLaneA[aIndex] ^ aFireLaneC[aIndex];
            aCross ^= aPoisonLaneC[aIndex];
            //
            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 4
        //
        // Ingress:
        //      aFuseLaneA (-->), aFireLaneD (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aHeartLaneB (<--), aFireLaneA (<--), aPoisonLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (;;) {
            //
            aIngress = aFuseLaneA[aIndex] ^ aFireLaneD[aIndex];
            aIngress ^= aEarthLaneD[aIndex];
            //
            aCross = aHeartLaneB[aIndex] ^ aFireLaneA[aIndex];
            aCross ^= aPoisonLaneA[aIndex];
            //
            aFuseLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 5
        //
        // Ingress:
        //      aFuseLaneB (-->), aHeartLaneB (-->), aPoisonLaneB (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aHeartLaneA (<--), aPoisonLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (;;) {
            //
            aIngress = aFuseLaneB[aIndex] ^ aHeartLaneB[aIndex];
            aIngress ^= aPoisonLaneB[aIndex];
            //
            aCross = aFuseLaneA[aIndex] ^ aHeartLaneA[aIndex];
            aCross ^= aPoisonLaneD[aIndex];
            //
            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 6
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aSource (<-?->)
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
            aIngress ^= aSource[aIndex];
            //
            aCross = aFuseLaneB[aIndex] ^ aFireLaneB[aIndex];
            //
            aFuseLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_C seed_loop_c (end)

}

void TwistExpander_Alcor_Arx::Seed_D() {


    // GSeedRunSeed_D seed_loop_d (start)
    {
        //
        // seed_loop_d loop 1
        //
        // Ingress:
        //      aWindLaneA (-->), aWindLaneB (-->), aKeyRowReadA (-->), aHeartLaneB (<-?->)
        //
        // Cross:
        //      aWindLaneC (<--), aWindLaneD (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aHeartLaneC
        //
        for (;;) {
            //
            aIngress = aWindLaneA[aIndex] ^ aWindLaneB[aIndex];
            aIngress ^= (aKeyRowReadA[aIndex] ^ aHeartLaneB[aIndex];
            //
            aCross = aWindLaneC[aIndex] ^ aWindLaneD[aIndex];
            aCross ^= aEarthLaneC[aIndex];
            //
            aHeartLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 2
        //
        // Ingress:
        //      aHeartLaneC (-->), aWindLaneC (-->), aPoisonLaneA (-->), aFireLaneA (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aWindLaneD (<--), aHeartLaneA (<-?->)
        //
        // Destination:
        //      aHeartLaneD
        //
        for (;;) {
            //
            aIngress = aHeartLaneC[aIndex] ^ aWindLaneC[aIndex];
            aIngress ^= (aPoisonLaneA[aIndex] ^ aFireLaneA[aIndex];
            //
            aCross = aWindLaneA[aIndex] ^ aWindLaneD[aIndex];
            aCross ^= aHeartLaneA[aIndex];
            //
            aHeartLaneD[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 3
        //
        // Ingress:
        //      aHeartLaneD (-->), aWindLaneA (-->), aFireLaneC (-->), aPoisonLaneC (<-?->)
        //
        // Cross:
        //      aHeartLaneC (<--), aWindLaneC (<--), aPoisonLaneD (<-?->)
        //
        // Destination:
        //      aWaterLaneA
        //
        for (;;) {
            //
            aIngress = aHeartLaneD[aIndex] ^ aWindLaneA[aIndex];
            aIngress ^= (aFireLaneC[aIndex] ^ aPoisonLaneC[aIndex];
            //
            aCross = aHeartLaneC[aIndex] ^ aWindLaneC[aIndex];
            aCross ^= aPoisonLaneD[aIndex];
            //
            aWaterLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 4
        //
        // Ingress:
        //      aWaterLaneA (-->), aWindLaneD (-->), aKeyRowReadB (-->), aPoisonLaneB (<-?->)
        //
        // Cross:
        //      aHeartLaneD (<--), aWindLaneA (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aWaterLaneB
        //
        for (;;) {
            //
            aIngress = aWaterLaneA[aIndex] ^ aWindLaneD[aIndex];
            aIngress ^= (aKeyRowReadB[aIndex] ^ aPoisonLaneB[aIndex];
            //
            aCross = aHeartLaneD[aIndex] ^ aWindLaneA[aIndex];
            aCross ^= aEarthLaneA[aIndex];
            //
            aWaterLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 5
        //
        // Ingress:
        //      aWaterLaneB (-->), aHeartLaneD (-->), aFireLaneD (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aHeartLaneC (<--), aSource (<-?->)
        //
        // Destination:
        //      aWaterLaneC
        //
        for (;;) {
            //
            aIngress = aWaterLaneB[aIndex] ^ aHeartLaneD[aIndex];
            aIngress ^= (aFireLaneD[aIndex] ^ aEarthLaneD[aIndex];
            //
            aCross = aWaterLaneA[aIndex] ^ aHeartLaneC[aIndex];
            aCross ^= aSource[aIndex];
            //
            aWaterLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 6
        //
        // Ingress:
        //      aWaterLaneC (-->), aWaterLaneA (-->), aEarthLaneB (<-?->)
        //
        // Cross:
        //      aWaterLaneB (<--), aWindLaneB (<--), aFireLaneB (<-?->)
        //
        // Destination:
        //      aWaterLaneD
        //
        for (;;) {
            //
            aIngress = aWaterLaneC[aIndex] ^ aWaterLaneA[aIndex];
            aIngress ^= aEarthLaneB[aIndex];
            //
            aCross = aWaterLaneB[aIndex] ^ aWindLaneB[aIndex];
            aCross ^= aFireLaneB[aIndex];
            //
            aWaterLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_D seed_loop_d (end)

}

void TwistExpander_Alcor_Arx::Seed_E() {


    // GSeedRunSeed_E seed_loop_e (start)
    {
        //
        // seed_loop_e loop 1
        //
        // Ingress:
        //      aWaterLaneA (-->), aWaterLaneB (-->), aPoisonLaneD (-->), aWindLaneC (<-?->)
        //
        // Cross:
        //      aWaterLaneC (<--), aWaterLaneD (<--), aKeyRowReadB (<--), aHeartLaneC (<-?->)
        //
        // Destination:
        //      aWoodLaneA
        //
        for (;;) {
            //
            aIngress = aWaterLaneA[aIndex] ^ aWaterLaneB[aIndex];
            aIngress ^= (aPoisonLaneD[aIndex] ^ aWindLaneC[aIndex];
            //
            aCross = aWaterLaneC[aIndex] ^ aWaterLaneD[aIndex];
            aCross ^= aKeyRowReadB[W_KEY1 - aIndex] ^ aHeartLaneC[aIndex];
            //
            aWoodLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 2
        //
        // Ingress:
        //      aWoodLaneA (-->), aWaterLaneC (-->), aEarthLaneC (-->), aWindLaneD (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWaterLaneD (<--), aHeartLaneA (<--), aKeyRowReadA (<-?->)
        //
        // Destination:
        //      aWoodLaneB
        //
        for (;;) {
            //
            aIngress = aWoodLaneA[aIndex] ^ aWaterLaneC[aIndex];
            aIngress ^= (aEarthLaneC[aIndex] ^ aWindLaneD[aIndex];
            //
            aCross = aWaterLaneA[aIndex] ^ aWaterLaneD[aIndex];
            aCross ^= aHeartLaneA[aIndex] ^ aKeyRowReadA[W_KEY1 - aIndex];
            //
            aWoodLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 3
        //
        // Ingress:
        //      aWoodLaneB (-->), aWaterLaneA (-->), aEarthLaneB (-->), aWindLaneA (<-?->)
        //
        // Cross:
        //      aWoodLaneA (<--), aWaterLaneC (<--), aEarthLaneA (<--), aPoisonLaneB (<-?->)
        //
        // Destination:
        //      aIceLaneA
        //
        for (;;) {
            //
            aIngress = aWoodLaneB[aIndex] ^ aWaterLaneA[aIndex];
            aIngress ^= (aEarthLaneB[aIndex] ^ aWindLaneA[aIndex];
            //
            aCross = aWoodLaneA[aIndex] ^ aWaterLaneC[aIndex];
            aCross ^= aEarthLaneA[aIndex] ^ aPoisonLaneB[aIndex];
            //
            aIceLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 4
        //
        // Ingress:
        //      aIceLaneA (-->), aWaterLaneD (-->), aPoisonLaneA (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aWoodLaneB (<--), aWaterLaneA (<--), aFireLaneB (<--), aFireLaneD (<-?->)
        //
        // Destination:
        //      aIceLaneB
        //
        for (;;) {
            //
            aIngress = aIceLaneA[aIndex] ^ aWaterLaneD[aIndex];
            aIngress ^= (aPoisonLaneA[aIndex] ^ aEarthLaneD[aIndex];
            //
            aCross = aWoodLaneB[aIndex] ^ aWaterLaneA[aIndex];
            aCross ^= aFireLaneB[aIndex] ^ aFireLaneD[aIndex];
            //
            aIceLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 5
        //
        // Ingress:
        //      aIceLaneB (-->), aWoodLaneB (-->), aHeartLaneB (-->), aHeartLaneD (<-?->)
        //
        // Cross:
        //      aIceLaneA (<--), aWoodLaneA (<--), aPoisonLaneC (<--), aFireLaneA (<-?->)
        //
        // Destination:
        //      aIceLaneC
        //
        for (;;) {
            //
            aIngress = aIceLaneB[aIndex] ^ aWoodLaneB[aIndex];
            aIngress ^= (aHeartLaneB[aIndex] ^ aHeartLaneD[aIndex];
            //
            aCross = aIceLaneA[aIndex] ^ aWoodLaneA[aIndex];
            aCross ^= aPoisonLaneC[aIndex] ^ aFireLaneA[aIndex];
            //
            aIceLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 6
        //
        // Ingress:
        //      aIceLaneC (-->), aIceLaneA (-->), aFireLaneC (-->), aSource (<-?->)
        //
        // Cross:
        //      aIceLaneB (<--), aWaterLaneB (<--), aWindLaneB (<-?->)
        //
        // Destination:
        //      aIceLaneD
        //
        for (;;) {
            //
            aIngress = aIceLaneC[aIndex] ^ aIceLaneA[aIndex];
            aIngress ^= (aFireLaneC[aIndex] ^ aSource[aIndex];
            //
            aCross = aIceLaneB[aIndex] ^ aWaterLaneB[aIndex];
            aCross ^= aWindLaneB[aIndex];
            //
            aIceLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_E seed_loop_e (end)

}

void TwistExpander_Alcor_Arx::Seed_F() {


    // GSeedRunSeed_F seed_loop_f (start)
    {
        //
        // seed_loop_f loop 1
        //
        // Ingress:
        //      aIceLaneA (-->), aIceLaneB (-->), aHeartLaneA (-->), aWindLaneA (<-?->)
        //
        // Cross:
        //      aIceLaneC (<--), aIceLaneD (<--), aWoodLaneB (<--), aFireLaneC (<-?->)
        //
        // Destination:
        //      aWoodLaneC
        //
        for (;;) {
            //
            aIngress = aIceLaneA[aIndex] ^ aIceLaneB[aIndex];
            aIngress ^= (aHeartLaneA[aIndex] ^ aWindLaneA[aIndex];
            //
            aCross = aIceLaneC[aIndex] ^ aIceLaneD[aIndex];
            aCross ^= aWoodLaneB[aIndex] ^ aFireLaneC[aIndex];
            //
            aWoodLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 2
        //
        // Ingress:
        //      aWoodLaneC (-->), aIceLaneC (-->), aHeartLaneB (-->), aWaterLaneC (<-?->)
        //
        // Cross:
        //      aIceLaneA (<--), aIceLaneD (<--), aWaterLaneA (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aWoodLaneD
        //
        for (;;) {
            //
            aIngress = aWoodLaneC[aIndex] ^ aIceLaneC[aIndex];
            aIngress ^= (aHeartLaneB[aIndex] ^ aWaterLaneC[aIndex];
            //
            aCross = aIceLaneA[aIndex] ^ aIceLaneD[aIndex];
            aCross ^= aWaterLaneA[aIndex] ^ aEarthLaneD[aIndex];
            //
            aWoodLaneD[aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 3
        //
        // Ingress:
        //      aWoodLaneD (-->), aIceLaneA (-->), aWindLaneB (-->), aFireLaneB (<-?->)
        //
        // Cross:
        //      aWoodLaneC (<--), aIceLaneC (<--), aHeartLaneD (<--), aKeyRowReadB (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (;;) {
            //
            aIngress = aWoodLaneD[aIndex] ^ aIceLaneA[aIndex];
            aIngress ^= (aWindLaneB[aIndex] ^ aFireLaneB[aIndex];
            //
            aCross = aWoodLaneC[aIndex] ^ aIceLaneC[aIndex];
            aCross ^= aHeartLaneD[aIndex] ^ aKeyRowReadB[W_KEY1 - aIndex];
            //
            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 4
        //
        // Ingress:
        //      aFuseLaneA (-->), aIceLaneD (-->), aWaterLaneD (-->), aWindLaneC (<-?->)
        //
        // Cross:
        //      aWoodLaneD (<--), aIceLaneA (<--), aFireLaneD (<--), aWoodLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (;;) {
            //
            aIngress = aFuseLaneA[aIndex] ^ aIceLaneD[aIndex];
            aIngress ^= (aWaterLaneD[aIndex] ^ aWindLaneC[aIndex];
            //
            aCross = aWoodLaneD[aIndex] ^ aIceLaneA[aIndex];
            aCross ^= aFireLaneD[aIndex] ^ aWoodLaneA[aIndex];
            //
            aFuseLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 5
        //
        // Ingress:
        //      aFuseLaneB (-->), aWoodLaneD (-->), aKeyRowReadA (-->), aWaterLaneB (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aWoodLaneC (<--), aFireLaneA (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (;;) {
            //
            aIngress = aFuseLaneB[aIndex] ^ aWoodLaneD[aIndex];
            aIngress ^= (aKeyRowReadA[aIndex] ^ aWaterLaneB[aIndex];
            //
            aCross = aFuseLaneA[aIndex] ^ aWoodLaneC[aIndex];
            aCross ^= aFireLaneA[aIndex] ^ aEarthLaneB[aIndex];
            //
            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 6
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aSource (-->), aHeartLaneC (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aIceLaneB (<--), aWindLaneD (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (;;) {
            //
            aIngress = aFuseLaneC[aIndex] ^ aFuseLaneA[aIndex];
            aIngress ^= (aSource[aIndex] ^ aHeartLaneC[aIndex];
            //
            aCross = aFuseLaneB[aIndex] ^ aIceLaneB[aIndex];
            aCross ^= aWindLaneD[aIndex] ^ aEarthLaneC[aIndex];
            //
            aFuseLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_F seed_loop_f (end)

}

void TwistExpander_Alcor_Arx::Seed_G() {


    // GSeedRunSeed_G seed_loop_g (start)
    {
        //
        // seed_loop_g loop 1
        //
        // Ingress:
        //      aSpiritLaneA (-->), aSpiritLaneB (-->), aWaterLaneB (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aSpiritLaneC (<--), aSpiritLaneD (<--), aWoodLaneC (<--), aIceLaneB (<-?->)
        //
        // Destination:
        //      aEarthLaneC
        //
        for (;;) {
            //
            aIngress = aSpiritLaneA[aIndex] ^ aSpiritLaneB[aIndex];
            aIngress ^= (aWaterLaneB[aIndex] ^ aKeyRowReadA[aIndex];
            //
            aCross = aSpiritLaneC[aIndex] ^ aSpiritLaneD[aIndex];
            aCross ^= aWoodLaneC[aIndex] ^ aIceLaneB[aIndex];
            //
            aEarthLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_g loop 2
        //
        // Ingress:
        //      aEarthLaneC (-->), aSpiritLaneC (-->), aWaterLaneD (-->), aWoodLaneB (<-?->)
        //
        // Cross:
        //      aSpiritLaneA (<--), aSpiritLaneD (<--), aWindLaneC (<--), aHeartLaneC (<-?->)
        //
        // Destination:
        //      aEarthLaneD
        //
        for (;;) {
            //
            aIngress = aEarthLaneC[aIndex] ^ aSpiritLaneC[aIndex];
            aIngress ^= (aWaterLaneD[aIndex] ^ aWoodLaneB[aIndex];
            //
            aCross = aSpiritLaneA[aIndex] ^ aSpiritLaneD[aIndex];
            aCross ^= aWindLaneC[aIndex] ^ aHeartLaneC[aIndex];
            //
            aEarthLaneD[aIndex] = aIngress;
        }
    
        //
        // seed_loop_g loop 3
        //
        // Ingress:
        //      aEarthLaneD (-->), aSpiritLaneA (-->), aHeartLaneB (-->), aIceLaneC (<-?->)
        //
        // Cross:
        //      aEarthLaneC (<--), aSpiritLaneC (<--), aIceLaneD (<--), aWoodLaneA (<-?->)
        //
        // Destination:
        //      aFireLaneA
        //
        for (;;) {
            //
            aIngress = aEarthLaneD[aIndex] ^ aSpiritLaneA[aIndex];
            aIngress ^= (aHeartLaneB[aIndex] ^ aIceLaneC[aIndex];
            //
            aCross = aEarthLaneC[aIndex] ^ aSpiritLaneC[aIndex];
            aCross ^= aIceLaneD[aIndex] ^ aWoodLaneA[aIndex];
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_g loop 4
        //
        // Ingress:
        //      aFireLaneA (-->), aSpiritLaneD (-->), aWindLaneB (-->), aSource (<-?->)
        //
        // Cross:
        //      aEarthLaneD (<--), aSpiritLaneA (<--), aWaterLaneA (<--), aHeartLaneA (<-?->)
        //
        // Destination:
        //      aFireLaneB
        //
        for (;;) {
            //
            aIngress = aFireLaneA[aIndex] ^ aSpiritLaneD[aIndex];
            aIngress ^= (aWindLaneB[aIndex] ^ aSource[aIndex];
            //
            aCross = aEarthLaneD[aIndex] ^ aSpiritLaneA[aIndex];
            aCross ^= aWaterLaneA[aIndex] ^ aHeartLaneA[aIndex];
            //
            aFireLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_g loop 5
        //
        // Ingress:
        //      aFireLaneB (-->), aEarthLaneD (-->), aWindLaneA (-->), aIceLaneA (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aEarthLaneC (<--), aHeartLaneD (<--), aWindLaneD (<-?->)
        //
        // Destination:
        //      aFireLaneC
        //
        for (;;) {
            //
            aIngress = aFireLaneB[aIndex] ^ aEarthLaneD[aIndex];
            aIngress ^= (aWindLaneA[aIndex] ^ aIceLaneA[aIndex];
            //
            aCross = aFireLaneA[aIndex] ^ aEarthLaneC[aIndex];
            aCross ^= aHeartLaneD[aIndex] ^ aWindLaneD[aIndex];
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_g loop 6
        //
        // Ingress:
        //      aFireLaneC (-->), aFireLaneA (-->), aKeyRowReadB (-->), aWaterLaneC (<-?->)
        //
        // Cross:
        //      aFireLaneB (<--), aSpiritLaneB (<--), aEarthLaneA (<--), aWoodLaneD (<-?->)
        //
        // Destination:
        //      aFireLaneD
        //
        for (;;) {
            //
            aIngress = aFireLaneC[aIndex] ^ aFireLaneA[aIndex];
            aIngress ^= (aKeyRowReadB[aIndex] ^ aWaterLaneC[aIndex];
            //
            aCross = aFireLaneB[aIndex] ^ aSpiritLaneB[aIndex];
            aCross ^= aEarthLaneA[aIndex] ^ aWoodLaneD[aIndex];
            //
            aFireLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_G seed_loop_g (end)

}

void TwistExpander_Alcor_Arx::Seed_H() {


    // GSeedRunSeed_H seed_loop_h (start)
    {
        //
        // seed_loop_h loop 1
        //
        // Ingress:
        //      aFireLaneA (-->), aFireLaneB (-->), aIceLaneC (-->), aWindLaneA (<-?->)
        //
        // Cross:
        //      aFireLaneC (<--), aFireLaneD (<--), aWaterLaneA (<--), aWindLaneB (<-?->)
        //
        // Destination:
        //      aEarthLaneC
        //
        for (;;) {
            //
            aIngress = aFireLaneA[aIndex] ^ aFireLaneB[aIndex];
            aIngress ^= (aIceLaneC[aIndex] ^ aWindLaneA[aIndex];
            //
            aCross = aFireLaneC[aIndex] ^ aFireLaneD[aIndex];
            aCross ^= aWaterLaneA[aIndex] ^ aWindLaneB[aIndex];
            //
            aEarthLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_h loop 2
        //
        // Ingress:
        //      aEarthLaneC (-->), aFireLaneC (-->), aPoisonLaneD (-->), aWaterLaneB (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), aSpiritLaneC (<--), aWoodLaneD (<-?->)
        //
        // Destination:
        //      aEarthLaneD
        //
        for (;;) {
            //
            aIngress = aEarthLaneC[aIndex] ^ aFireLaneC[aIndex];
            aIngress ^= (aPoisonLaneD[aIndex] ^ aWaterLaneB[aIndex];
            //
            aCross = aFireLaneA[aIndex] ^ aFireLaneD[aIndex];
            aCross ^= aSpiritLaneC[aIndex] ^ aWoodLaneD[aIndex];
            //
            aEarthLaneD[aIndex] = aIngress;
        }
    
        //
        // seed_loop_h loop 3
        //
        // Ingress:
        //      aEarthLaneD (-->), aFireLaneA (-->), aWindLaneC (-->), aIceLaneD (<-?->)
        //
        // Cross:
        //      aEarthLaneC (<--), aFireLaneC (<--), aPoisonLaneC (<--), aWindLaneD (<-?->)
        //
        // Destination:
        //      aHeartLaneA
        //
        for (;;) {
            //
            aIngress = aEarthLaneD[aIndex] ^ aFireLaneA[aIndex];
            aIngress ^= (aWindLaneC[aIndex] ^ aIceLaneD[aIndex];
            //
            aCross = aEarthLaneC[aIndex] ^ aFireLaneC[aIndex];
            aCross ^= aPoisonLaneC[aIndex] ^ aWindLaneD[aIndex];
            //
            aHeartLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_h loop 4
        //
        // Ingress:
        //      aHeartLaneA (-->), aFireLaneD (-->), aSpiritLaneB (-->), aWoodLaneA (<-?->)
        //
        // Cross:
        //      aEarthLaneD (<--), aFireLaneA (<--), aIceLaneA (<--), aSpiritLaneD (<-?->)
        //
        // Destination:
        //      aHeartLaneB
        //
        for (;;) {
            //
            aIngress = aHeartLaneA[aIndex] ^ aFireLaneD[aIndex];
            aIngress ^= (aSpiritLaneB[aIndex] ^ aWoodLaneA[aIndex];
            //
            aCross = aEarthLaneD[aIndex] ^ aFireLaneA[aIndex];
            aCross ^= aIceLaneA[aIndex] ^ aSpiritLaneD[aIndex];
            //
            aHeartLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_h loop 5
        //
        // Ingress:
        //      aHeartLaneB (-->), aEarthLaneD (-->), aSpiritLaneA (-->), aIceLaneB (<-?->)
        //
        // Cross:
        //      aHeartLaneA (<--), aEarthLaneC (<--), aWaterLaneC (<--), aWaterLaneD (<-?->)
        //
        // Destination:
        //      aHeartLaneC
        //
        for (;;) {
            //
            aIngress = aHeartLaneB[aIndex] ^ aEarthLaneD[aIndex];
            aIngress ^= (aSpiritLaneA[aIndex] ^ aIceLaneB[aIndex];
            //
            aCross = aHeartLaneA[aIndex] ^ aEarthLaneC[aIndex];
            aCross ^= aWaterLaneC[aIndex] ^ aWaterLaneD[aIndex];
            //
            aHeartLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_h loop 6
        //
        // Ingress:
        //      aHeartLaneC (-->), aHeartLaneA (-->), aWoodLaneB (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aHeartLaneB (<--), aFireLaneB (<--), aWoodLaneC (<--), aKeyRowReadB (<-?->)
        //
        // Destination:
        //      aHeartLaneD
        //
        for (;;) {
            //
            aIngress = aHeartLaneC[aIndex] ^ aHeartLaneA[aIndex];
            aIngress ^= (aWoodLaneB[aIndex] ^ aKeyRowReadA[W_KEY1 - aIndex];
            //
            aCross = aHeartLaneB[aIndex] ^ aFireLaneB[aIndex];
            aCross ^= aWoodLaneC[aIndex] ^ aKeyRowReadB[W_KEY1 - aIndex];
            //
            aHeartLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_H seed_loop_h (end)

}

void TwistExpander_Alcor_Arx::Twist_A() {


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

void TwistExpander_Alcor_Arx::Twist_B() {


    // GTwistRunTwist_B twist_loop_b (start)
    {
        //
        // twist_loop_b loop 1
        //
        // Ingress:
        //      aEarthLaneA (-->), aEarthLaneB (-->), aSource (<-?->)
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
            aIngress ^= aSource[aIndex];
            //
            aCross = aEarthLaneC[aIndex] ^ aEarthLaneD[aIndex];
            //
            aPoisonLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_b loop 2
        //
        // Ingress:
        //      aPoisonLaneC (-->), aEarthLaneC (-->), aKeyRowReadB (<-?->)
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
            aIngress ^= aKeyRowReadB[aIndex];
            //
            aCross = aEarthLaneA[aIndex] ^ aEarthLaneD[aIndex];
            //
            aPoisonLaneD[aIndex] = aIngress;
        }
    
        //
        // twist_loop_b loop 3
        //
        // Ingress:
        //      aPoisonLaneD (-->), aEarthLaneA (-->), aKeyRowReadA (<-?->)
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
            aIngress ^= aKeyRowReadA[W_KEY1 - aIndex];
            //
            aCross = aPoisonLaneC[aIndex] ^ aEarthLaneC[aIndex];
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_b loop 4
        //
        // Ingress:
        //      aFireLaneA (-->), aEarthLaneD (-->), aPoisonLaneA (<-?->)
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
            aIngress ^= aPoisonLaneA[aIndex];
            //
            aCross = aPoisonLaneD[aIndex] ^ aEarthLaneA[aIndex];
            //
            aFireLaneB[aIndex] = aIngress;
        }
    
        //
        // twist_loop_b loop 5
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

void TwistExpander_Alcor_Arx::Twist_C() {


    // GTwistRunTwist_C twist_loop_c (start)
    {
        //
        // twist_loop_c loop 1
        //
        // Ingress:
        //      aFireLaneA (-->), aFireLaneB (-->), aPoisonLaneB (<-?->)
        //
        // Cross:
        //      aFireLaneC (<--), aFireLaneD (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aWoodLaneA
        //
        for (;;) {
            //
            aIngress = aFireLaneA[aIndex] ^ aFireLaneB[aIndex];
            aIngress ^= aPoisonLaneB[aIndex];
            //
            aCross = aFireLaneC[aIndex] ^ aFireLaneD[aIndex];
            aCross ^= aEarthLaneD[aIndex];
            //
            aWoodLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_c loop 2
        //
        // Ingress:
        //      aWoodLaneA (-->), aFireLaneC (-->), aKeyRowReadB (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), aSource (<-?->)
        //
        // Destination:
        //      aWoodLaneB
        //
        for (;;) {
            //
            aIngress = aWoodLaneA[aIndex] ^ aFireLaneC[aIndex];
            aIngress ^= aKeyRowReadB[aIndex];
            //
            aCross = aFireLaneA[aIndex] ^ aFireLaneD[aIndex];
            aCross ^= aSource[aIndex];
            //
            aWoodLaneB[aIndex] = aIngress;
        }
    
        //
        // twist_loop_c loop 3
        //
        // Ingress:
        //      aWoodLaneB (-->), aFireLaneA (-->), aEarthLaneB (<-?->)
        //
        // Cross:
        //      aWoodLaneA (<--), aFireLaneC (<--), aPoisonLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (;;) {
            //
            aIngress = aWoodLaneB[aIndex] ^ aFireLaneA[aIndex];
            aIngress ^= aEarthLaneB[aIndex];
            //
            aCross = aWoodLaneA[aIndex] ^ aFireLaneC[aIndex];
            aCross ^= aPoisonLaneD[aIndex];
            //
            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_c loop 4
        //
        // Ingress:
        //      aFuseLaneA (-->), aFireLaneD (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aWoodLaneB (<--), aFireLaneA (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (;;) {
            //
            aIngress = aFuseLaneA[aIndex] ^ aFireLaneD[aIndex];
            aIngress ^= aKeyRowReadA[aIndex];
            //
            aCross = aWoodLaneB[aIndex] ^ aFireLaneA[aIndex];
            aCross ^= aEarthLaneC[aIndex];
            //
            aFuseLaneB[aIndex] = aIngress;
        }
    
        //
        // twist_loop_c loop 5
        //
        // Ingress:
        //      aFuseLaneB (-->), aWoodLaneB (-->), aPoisonLaneC (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aWoodLaneA (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (;;) {
            //
            aIngress = aFuseLaneB[aIndex] ^ aWoodLaneB[aIndex];
            aIngress ^= aPoisonLaneC[aIndex];
            //
            aCross = aFuseLaneA[aIndex] ^ aWoodLaneA[aIndex];
            aCross ^= aEarthLaneA[aIndex];
            //
            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_c loop 6
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aPoisonLaneA (<-?->)
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
            aIngress ^= aPoisonLaneA[aIndex];
            //
            aCross = aFuseLaneB[aIndex] ^ aFireLaneB[aIndex];
            //
            aFuseLaneD[aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_C twist_loop_c (end)

}

void TwistExpander_Alcor_Arx::Twist_D() {


    // GTwistRunTwist_D twist_loop_d (start)
    {
        //
        // twist_loop_d loop 1
        //
        // Ingress:
        //      aWindLaneA (-->), aWindLaneB (-->), aPoisonLaneA (-->), aPoisonLaneB (<-?->)
        //
        // Cross:
        //      aWindLaneC (<--), aWindLaneD (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aSpiritLaneA
        //
        for (;;) {
            //
            aIngress = aWindLaneA[aIndex] ^ aWindLaneB[aIndex];
            aIngress ^= (aPoisonLaneA[aIndex] ^ aPoisonLaneB[aIndex];
            //
            aCross = aWindLaneC[aIndex] ^ aWindLaneD[aIndex];
            aCross ^= aEarthLaneD[aIndex];
            //
            aSpiritLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 2
        //
        // Ingress:
        //      aSpiritLaneA (-->), aWindLaneC (-->), aFireLaneD (-->), aEarthLaneB (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aWindLaneD (<--), aFireLaneA (<-?->)
        //
        // Destination:
        //      aSpiritLaneB
        //
        for (;;) {
            //
            aIngress = aSpiritLaneA[aIndex] ^ aWindLaneC[aIndex];
            aIngress ^= (aFireLaneD[aIndex] ^ aEarthLaneB[aIndex];
            //
            aCross = aWindLaneA[aIndex] ^ aWindLaneD[aIndex];
            aCross ^= aFireLaneA[aIndex];
            //
            aSpiritLaneB[aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 3
        //
        // Ingress:
        //      aSpiritLaneB (-->), aWindLaneA (-->), aEarthLaneC (-->), aPoisonLaneC (<-?->)
        //
        // Cross:
        //      aSpiritLaneA (<--), aWindLaneC (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aWaterLaneA
        //
        for (;;) {
            //
            aIngress = aSpiritLaneB[aIndex] ^ aWindLaneA[aIndex];
            aIngress ^= (aEarthLaneC[aIndex] ^ aPoisonLaneC[aIndex];
            //
            aCross = aSpiritLaneA[aIndex] ^ aWindLaneC[aIndex];
            aCross ^= aEarthLaneA[aIndex];
            //
            aWaterLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 4
        //
        // Ingress:
        //      aWaterLaneA (-->), aWindLaneD (-->), aKeyRowReadB (-->), aWoodLaneB (<-?->)
        //
        // Cross:
        //      aSpiritLaneB (<--), aWindLaneA (<--), aFireLaneB (<-?->)
        //
        // Destination:
        //      aWaterLaneB
        //
        for (;;) {
            //
            aIngress = aWaterLaneA[aIndex] ^ aWindLaneD[aIndex];
            aIngress ^= (aKeyRowReadB[aIndex] ^ aWoodLaneB[aIndex];
            //
            aCross = aSpiritLaneB[aIndex] ^ aWindLaneA[aIndex];
            aCross ^= aFireLaneB[aIndex];
            //
            aWaterLaneB[aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 5
        //
        // Ingress:
        //      aWaterLaneB (-->), aSpiritLaneB (-->), aPoisonLaneD (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aSpiritLaneA (<--), aFireLaneC (<-?->)
        //
        // Destination:
        //      aWaterLaneC
        //
        for (;;) {
            //
            aIngress = aWaterLaneB[aIndex] ^ aSpiritLaneB[aIndex];
            aIngress ^= (aPoisonLaneD[aIndex] ^ aKeyRowReadA[W_KEY1 - aIndex];
            //
            aCross = aWaterLaneA[aIndex] ^ aSpiritLaneA[aIndex];
            aCross ^= aFireLaneC[aIndex];
            //
            aWaterLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 6
        //
        // Ingress:
        //      aWaterLaneC (-->), aWaterLaneA (-->), aSource (<-?->)
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
            aIngress ^= aSource[aIndex];
            //
            aCross = aWaterLaneB[aIndex] ^ aWindLaneB[aIndex];
            aCross ^= aWoodLaneA[aIndex];
            //
            aWaterLaneD[aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_D twist_loop_d (end)

}

void TwistExpander_Alcor_Arx::Twist_E() {


    // GTwistRunTwist_E twist_loop_e (start)
    {
        //
        // twist_loop_e loop 1
        //
        // Ingress:
        //      aWaterLaneA (-->), aWaterLaneB (-->), aWindLaneA (-->), aKeyRowReadB (<-?->)
        //
        // Cross:
        //      aWaterLaneC (<--), aWaterLaneD (<--), aFireLaneD (<--), aPoisonLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (;;) {
            //
            aIngress = aWaterLaneA[aIndex] ^ aWaterLaneB[aIndex];
            aIngress ^= (aWindLaneA[aIndex] ^ aKeyRowReadB[aIndex];
            //
            aCross = aWaterLaneC[aIndex] ^ aWaterLaneD[aIndex];
            aCross ^= aFireLaneD[aIndex] ^ aPoisonLaneD[aIndex];
            //
            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 2
        //
        // Ingress:
        //      aFuseLaneA (-->), aWaterLaneC (-->), aWoodLaneB (-->), aFireLaneB (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWaterLaneD (<--), aFireLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (;;) {
            //
            aIngress = aFuseLaneA[aIndex] ^ aWaterLaneC[aIndex];
            aIngress ^= (aWoodLaneB[aIndex] ^ aFireLaneB[aIndex];
            //
            aCross = aWaterLaneA[aIndex] ^ aWaterLaneD[aIndex];
            aCross ^= aFireLaneC[aIndex];
            //
            aFuseLaneB[aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 3
        //
        // Ingress:
        //      aFuseLaneB (-->), aWaterLaneA (-->), aSource (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aWaterLaneC (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aHeartLaneA
        //
        for (;;) {
            //
            aIngress = aFuseLaneB[aIndex] ^ aWaterLaneA[aIndex];
            aIngress ^= (aSource[aIndex] ^ aEarthLaneA[aIndex];
            //
            aCross = aFuseLaneA[aIndex] ^ aWaterLaneC[aIndex];
            aCross ^= aEarthLaneB[aIndex];
            //
            aHeartLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 4
        //
        // Ingress:
        //      aHeartLaneA (-->), aWaterLaneD (-->), aWindLaneD (-->), aWoodLaneA (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aWaterLaneA (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aHeartLaneB
        //
        for (;;) {
            //
            aIngress = aHeartLaneA[aIndex] ^ aWaterLaneD[aIndex];
            aIngress ^= (aWindLaneD[aIndex] ^ aWoodLaneA[aIndex];
            //
            aCross = aFuseLaneB[aIndex] ^ aWaterLaneA[aIndex];
            aCross ^= aWindLaneC[aIndex];
            //
            aHeartLaneB[aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 5
        //
        // Ingress:
        //      aHeartLaneB (-->), aFuseLaneB (-->), aFireLaneA (-->), aWindLaneB (<-?->)
        //
        // Cross:
        //      aHeartLaneA (<--), aFuseLaneA (<--), aKeyRowReadA (<-?->)
        //
        // Destination:
        //      aHeartLaneC
        //
        for (;;) {
            //
            aIngress = aHeartLaneB[aIndex] ^ aFuseLaneB[aIndex];
            aIngress ^= (aFireLaneA[aIndex] ^ aWindLaneB[aIndex];
            //
            aCross = aHeartLaneA[aIndex] ^ aFuseLaneA[aIndex];
            aCross ^= aKeyRowReadA[aIndex];
            //
            aHeartLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 6
        //
        // Ingress:
        //      aHeartLaneC (-->), aHeartLaneA (-->), aEarthLaneD (-->), aPoisonLaneC (<-?->)
        //
        // Cross:
        //      aHeartLaneB (<--), aWaterLaneB (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aHeartLaneD
        //
        for (;;) {
            //
            aIngress = aHeartLaneC[aIndex] ^ aHeartLaneA[aIndex];
            aIngress ^= (aEarthLaneD[aIndex] ^ aPoisonLaneC[aIndex];
            //
            aCross = aHeartLaneB[aIndex] ^ aWaterLaneB[aIndex];
            aCross ^= aEarthLaneC[aIndex];
            //
            aHeartLaneD[aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_E twist_loop_e (end)

}

void TwistExpander_Alcor_Arx::GROW_A() {


    // GROW_A grow_key_a (start)
    {
        //
        // grow_key_a loop 1
        //
        // Ingress:
        //      aHeartLaneA (-->), aHeartLaneB (-->), aEarthLaneD (-->), aWindLaneB (<-?->)
        //
        // Cross:
        //      aHeartLaneC (<--), aHeartLaneD (<--), aSpiritLaneC (<--), aSpiritLaneA (<-?->)
        //
        // Destination:
        //      aIceLaneA
        //
        for (;;) {
            //
            aIngress = aHeartLaneA[aIndex] ^ aHeartLaneB[aIndex];
            aIngress ^= (aEarthLaneD[aIndex] ^ aWindLaneB[aIndex];
            //
            aCross = aHeartLaneC[aIndex] ^ aHeartLaneD[aIndex];
            aCross ^= aSpiritLaneC[aIndex] ^ aSpiritLaneA[aIndex];
            //
            aIceLaneA[aIndex] = aIngress;
        }
    
        //
        // grow_key_a loop 2
        //
        // Ingress:
        //      aIceLaneA (-->), aHeartLaneC (-->), aPoisonLaneB (-->), aPoisonLaneA (<-?->)
        //
        // Cross:
        //      aHeartLaneA (<--), aHeartLaneD (<--), aPoisonLaneD (<--), aFireLaneD (<-?->)
        //
        // Destination:
        //      aIceLaneB
        //
        for (;;) {
            //
            aIngress = aIceLaneA[aIndex] ^ aHeartLaneC[aIndex];
            aIngress ^= (aPoisonLaneB[aIndex] ^ aPoisonLaneA[aIndex];
            //
            aCross = aHeartLaneA[aIndex] ^ aHeartLaneD[aIndex];
            aCross ^= aPoisonLaneD[aIndex] ^ aFireLaneD[aIndex];
            //
            aIceLaneB[aIndex] = aIngress;
        }
    
        //
        // grow_key_a loop 3
        //
        // Ingress:
        //      aIceLaneB (-->), aHeartLaneD (-->), aSpiritLaneB (-->), aWaterLaneA (<-?->)
        //
        // Cross:
        //      aIceLaneA (<--), aHeartLaneB (<--), aFireLaneC (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aIceLaneC
        //
        for (;;) {
            //
            aIngress = aIceLaneB[aIndex] ^ aHeartLaneD[aIndex];
            aIngress ^= (aSpiritLaneB[aIndex] ^ aWaterLaneA[aIndex];
            //
            aCross = aIceLaneA[aIndex] ^ aHeartLaneB[aIndex];
            aCross ^= aFireLaneC[aIndex] ^ aWindLaneA[aIndex];
            //
            aIceLaneC[aIndex] = aIngress;
        }
    
        //
        // grow_key_a loop 4
        //
        // Ingress:
        //      aIceLaneC (-->), aIceLaneA (-->), aPoisonLaneC (-->), aSpiritLaneD (<-?->)
        //
        // Cross:
        //      aIceLaneB (<--), aHeartLaneC (<--), aEarthLaneC (<--), aWaterLaneB (<-?->)
        //
        // Destination:
        //      aIceLaneD
        //
        for (;;) {
            //
            aIngress = aIceLaneC[aIndex] ^ aIceLaneA[aIndex];
            aIngress ^= (aPoisonLaneC[aIndex] ^ aSpiritLaneD[aIndex];
            //
            aCross = aIceLaneB[aIndex] ^ aHeartLaneC[aIndex];
            aCross ^= aEarthLaneC[aIndex] ^ aWaterLaneB[aIndex];
            //
            aIceLaneD[aIndex] = aIngress;
        }
    }
    // GROW_A grow_key_a (end)

}

void TwistExpander_Alcor_Arx::GROW_B() {


    // GROW_B grow_key_b (start)
    {
        //
        // grow_key_b loop 1
        //
        // Ingress:
        //      aIceLaneA (-->), aIceLaneB (-->), aEarthLaneA (-->), aFireLaneB (<-?->)
        //
        // Cross:
        //      aIceLaneC (<--), aIceLaneD (<--), aWindLaneD (<--), aKeyRowReadB (<-?->)
        //
        // Destination:
        //      aSpiritLaneA
        //
        for (;;) {
            //
            aIngress = aIceLaneA[aIndex] ^ aIceLaneB[aIndex];
            aIngress ^= (aEarthLaneA[aIndex] ^ aFireLaneB[aIndex];
            //
            aCross = aIceLaneC[aIndex] ^ aIceLaneD[aIndex];
            aCross ^= aWindLaneD[aIndex] ^ aKeyRowReadB[W_KEY1 - aIndex];
            //
            aSpiritLaneA[aIndex] = aIngress;
        }
    
        //
        // grow_key_b loop 2
        //
        // Ingress:
        //      aSpiritLaneA (-->), aIceLaneC (-->), aEarthLaneB (-->), aHeartLaneB (<-?->)
        //
        // Cross:
        //      aIceLaneA (<--), aIceLaneD (<--), aWaterLaneD (<--), aHeartLaneC (<-?->)
        //
        // Destination:
        //      aSpiritLaneB
        //
        for (;;) {
            //
            aIngress = aSpiritLaneA[aIndex] ^ aIceLaneC[aIndex];
            aIngress ^= (aEarthLaneB[aIndex] ^ aHeartLaneB[aIndex];
            //
            aCross = aIceLaneA[aIndex] ^ aIceLaneD[aIndex];
            aCross ^= aWaterLaneD[aIndex] ^ aHeartLaneC[aIndex];
            //
            aSpiritLaneB[aIndex] = aIngress;
        }
    
        //
        // grow_key_b loop 3
        //
        // Ingress:
        //      aSpiritLaneB (-->), aIceLaneD (-->), aKeyRowReadA (-->), aWoodLaneB (<-?->)
        //
        // Cross:
        //      aSpiritLaneA (<--), aIceLaneB (<--), aHeartLaneD (<--), aFireLaneA (<-?->)
        //
        // Destination:
        //      aSpiritLaneC
        //
        for (;;) {
            //
            aIngress = aSpiritLaneB[aIndex] ^ aIceLaneD[aIndex];
            aIngress ^= (aKeyRowReadA[aIndex] ^ aWoodLaneB[aIndex];
            //
            aCross = aSpiritLaneA[aIndex] ^ aIceLaneB[aIndex];
            aCross ^= aHeartLaneD[aIndex] ^ aFireLaneA[aIndex];
            //
            aSpiritLaneC[aIndex] = aIngress;
        }
    
        //
        // grow_key_b loop 4
        //
        // Ingress:
        //      aSpiritLaneC (-->), aSpiritLaneA (-->), aWindLaneC (-->), aWaterLaneC (<-?->)
        //
        // Cross:
        //      aSpiritLaneB (<--), aIceLaneC (<--), aWoodLaneA (<--), aHeartLaneA (<-?->)
        //
        // Destination:
        //      aSpiritLaneD
        //
        for (;;) {
            //
            aIngress = aSpiritLaneC[aIndex] ^ aSpiritLaneA[aIndex];
            aIngress ^= (aWindLaneC[aIndex] ^ aWaterLaneC[aIndex];
            //
            aCross = aSpiritLaneB[aIndex] ^ aIceLaneC[aIndex];
            aCross ^= aWoodLaneA[aIndex] ^ aHeartLaneA[aIndex];
            //
            aSpiritLaneD[aIndex] = aIngress;
        }
    }
    // GROW_B grow_key_b (end)

}
