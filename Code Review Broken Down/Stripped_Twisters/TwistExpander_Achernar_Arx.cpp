#include "TwistExpander_Achernar_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void Achernar_Arx::KDF_A_A() {
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

void TwistExpander_Achernar_Arx::KDF_A_B() {


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

void TwistExpander_Achernar_Arx::KDF_A_C() {


    // GSeedRunKDF_A_C kdf_a_loop_c (start)
    {
        //
        // kdf_a_loop_c loop 1
        //
        // Ingress:
        //      aFireLaneA (-->), aFireLaneB (-->), aEarthLaneD (-->), aEarthLaneA (<-?->)
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
            aIngress ^= aEarthLaneD[aIndex] ^ aEarthLaneA[aIndex];
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
        //      aFuseLaneA (-->), aFireLaneC (-->), pSnow (-->), aPoisonLaneA (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), aSource (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (;;) {
            //
            aIngress = aFuseLaneA[aIndex] ^ aFireLaneC[aIndex];
            aIngress ^= pSnow[aIndex] ^ aPoisonLaneA[aIndex];
            //
            aCross = aFireLaneA[aIndex] ^ aFireLaneD[aIndex];
            aCross ^= aSource[aIndex];
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
        //      aFuseLaneA (<--), aFireLaneB (<--), aPoisonLaneB (<-?->)
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
            aCross ^= aPoisonLaneB[aIndex];
            //
            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_c loop 4
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aEarthLaneC (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aFireLaneC (<--), aPoisonLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (;;) {
            //
            aIngress = aFuseLaneC[aIndex] ^ aFuseLaneA[aIndex];
            aIngress ^= aEarthLaneC[aIndex];
            //
            aCross = aFuseLaneB[aIndex] ^ aFireLaneC[aIndex];
            aCross ^= aPoisonLaneC[aIndex];
            //
            aFuseLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_C kdf_a_loop_c (end)

}

void TwistExpander_Achernar_Arx::KDF_A_D() {


    // GSeedRunKDF_A_D kdf_a_loop_d (start)
    {
        //
        // kdf_a_loop_d loop 1
        //
        // Ingress:
        //      aWindLaneA (-->), aWindLaneB (-->), aPoisonLaneB (-->), aPoisonLaneD (<-?->)
        //
        // Cross:
        //      aWindLaneC (<--), aWindLaneD (<--), aPoisonLaneA (<--), aPoisonLaneC (<-?->)
        //
        // Destination:
        //      aWaterLaneA
        //
        for (;;) {
            //
            aIngress = aWindLaneA[aIndex] ^ aWindLaneB[aIndex];
            aIngress ^= aPoisonLaneB[aIndex] ^ aPoisonLaneD[aIndex];
            //
            aCross = aWindLaneC[aIndex] ^ aWindLaneD[aIndex];
            aCross ^= aPoisonLaneA[aIndex] ^ aPoisonLaneC[aIndex];
            //
            aWaterLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_d loop 2
        //
        // Ingress:
        //      aWaterLaneA (-->), aWindLaneC (-->), aFireLaneD (-->), aEarthLaneB (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aWindLaneD (<--), aEarthLaneC (<--), aFireLaneA (<-?->)
        //
        // Destination:
        //      aWaterLaneB
        //
        for (;;) {
            //
            aIngress = aWaterLaneA[aIndex] ^ aWindLaneC[aIndex];
            aIngress ^= aFireLaneD[aIndex] ^ aEarthLaneB[aIndex];
            //
            aCross = aWindLaneA[aIndex] ^ aWindLaneD[aIndex];
            aCross ^= aEarthLaneC[aIndex] ^ aFireLaneA[aIndex];
            //
            aWaterLaneB[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_d loop 3
        //
        // Ingress:
        //      aWaterLaneB (-->), aWindLaneD (-->), aFireLaneC (-->), aFireLaneB (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWindLaneB (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aWaterLaneC
        //
        for (;;) {
            //
            aIngress = aWaterLaneB[aIndex] ^ aWindLaneD[aIndex];
            aIngress ^= aFireLaneC[aIndex] ^ aFireLaneB[aIndex];
            //
            aCross = aWaterLaneA[aIndex] ^ aWindLaneB[aIndex];
            aCross ^= aEarthLaneD[aIndex];
            //
            aWaterLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_d loop 4
        //
        // Ingress:
        //      aWaterLaneC (-->), aWaterLaneA (-->), pSnow (-->), aSource (<-?->)
        //
        // Cross:
        //      aWaterLaneB (<--), aWindLaneC (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aWaterLaneD
        //
        for (;;) {
            //
            aIngress = aWaterLaneC[aIndex] ^ aWaterLaneA[aIndex];
            aIngress ^= pSnow[aIndex] ^ aSource[aIndex];
            //
            aCross = aWaterLaneB[aIndex] ^ aWindLaneC[aIndex];
            aCross ^= aEarthLaneA[aIndex];
            //
            aWaterLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_D kdf_a_loop_d (end)

}

void TwistExpander_Achernar_Arx::KDF_B_A() {


    // GSeedRunKDF_B_A kdf_b_loop_a (start)
    {
        //
        // kdf_b_loop_a loop 1
        //
        // Ingress:
        //      aWaterLaneA (-->), aWaterLaneB (-->), aFireLaneA (-->), aPoisonLaneA (<-?->)
        //
        // Cross:
        //      aWaterLaneC (<--), aWaterLaneD (<--), aWindLaneD (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aWoodLaneA
        //
        for (;;) {
            //
            aIngress = aWaterLaneA[aIndex] ^ aWaterLaneB[aIndex];
            aIngress ^= aFireLaneA[aIndex] ^ aPoisonLaneA[aIndex];
            //
            aCross = aWaterLaneC[aIndex] ^ aWaterLaneD[aIndex];
            aCross ^= aWindLaneD[aIndex] ^ aEarthLaneD[aIndex];
            //
            aWoodLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_a loop 2
        //
        // Ingress:
        //      aWoodLaneA (-->), aWaterLaneC (-->), aWindLaneB (-->), aEarthLaneC (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWaterLaneD (<--), aWindLaneC (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aWoodLaneB
        //
        for (;;) {
            //
            aIngress = aWoodLaneA[aIndex] ^ aWaterLaneC[aIndex];
            aIngress ^= aWindLaneB[aIndex] ^ aEarthLaneC[aIndex];
            //
            aCross = aWaterLaneA[aIndex] ^ aWaterLaneD[aIndex];
            aCross ^= aWindLaneC[aIndex] ^ aWindLaneA[aIndex];
            //
            aWoodLaneB[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_a loop 3
        //
        // Ingress:
        //      aWoodLaneB (-->), aWaterLaneD (-->), aFireLaneB (-->), aFireLaneC (<-?->)
        //
        // Cross:
        //      aWoodLaneA (<--), aWaterLaneB (<--), aSource (<--), aPoisonLaneB (<-?->)
        //
        // Destination:
        //      aWoodLaneC
        //
        for (;;) {
            //
            aIngress = aWoodLaneB[aIndex] ^ aWaterLaneD[aIndex];
            aIngress ^= aFireLaneB[aIndex] ^ aFireLaneC[aIndex];
            //
            aCross = aWoodLaneA[aIndex] ^ aWaterLaneB[aIndex];
            aCross ^= aSource[aIndex] ^ aPoisonLaneB[aIndex];
            //
            aWoodLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_a loop 4
        //
        // Ingress:
        //      aWoodLaneC (-->), aWoodLaneA (-->), aPoisonLaneD (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aWoodLaneB (<--), aPoisonLaneC (<--), aFireLaneD (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aWoodLaneD
        //
        for (;;) {
            //
            aIngress = aWoodLaneC[aIndex] ^ aWoodLaneA[aIndex];
            aIngress ^= aPoisonLaneD[aIndex] ^ aEarthLaneA[aIndex];
            //
            aCross = aWoodLaneB[aIndex] ^ aPoisonLaneC[aIndex];
            aCross ^= aFireLaneD[aIndex] ^ aEarthLaneB[aIndex];
            //
            aWoodLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_A kdf_b_loop_a (end)

}

void TwistExpander_Achernar_Arx::KDF_B_B() {


    // GSeedRunKDF_B_B kdf_b_loop_b (start)
    {
        //
        // kdf_b_loop_b loop 1
        //
        // Ingress:
        //      aWoodLaneA (-->), aWoodLaneB (-->), aWindLaneB (-->), aWaterLaneC (<-?->)
        //
        // Cross:
        //      aWoodLaneC (<--), aWoodLaneD (<--), aFireLaneC (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aSpiritLaneA
        //
        for (;;) {
            //
            aIngress = aWoodLaneA[aIndex] ^ aWoodLaneB[aIndex];
            aIngress ^= aWindLaneB[aIndex] ^ aWaterLaneC[aIndex];
            //
            aCross = aWoodLaneC[aIndex] ^ aWoodLaneD[aIndex];
            aCross ^= aFireLaneC[aIndex] ^ aWindLaneC[aIndex];
            //
            aSpiritLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_b loop 2
        //
        // Ingress:
        //      aSpiritLaneA (-->), aWoodLaneC (-->), aWaterLaneB (-->), aFireLaneB (<-?->)
        //
        // Cross:
        //      aWoodLaneA (<--), aWoodLaneD (<--), aEarthLaneB (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aSpiritLaneB
        //
        for (;;) {
            //
            aIngress = aSpiritLaneA[aIndex] ^ aWoodLaneC[aIndex];
            aIngress ^= aWaterLaneB[aIndex] ^ aFireLaneB[aIndex];
            //
            aCross = aWoodLaneA[aIndex] ^ aWoodLaneD[aIndex];
            aCross ^= aEarthLaneB[aIndex] ^ aEarthLaneA[aIndex];
            //
            aSpiritLaneB[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_b loop 3
        //
        // Ingress:
        //      aSpiritLaneB (-->), aWoodLaneD (-->), aWindLaneD (-->), aSource (<-?->)
        //
        // Cross:
        //      aSpiritLaneA (<--), aWoodLaneB (<--), aFireLaneD (<--), aFireLaneA (<-?->)
        //
        // Destination:
        //      aSpiritLaneC
        //
        for (;;) {
            //
            aIngress = aSpiritLaneB[aIndex] ^ aWoodLaneD[aIndex];
            aIngress ^= aWindLaneD[aIndex] ^ aSource[aIndex];
            //
            aCross = aSpiritLaneA[aIndex] ^ aWoodLaneB[aIndex];
            aCross ^= aFireLaneD[aIndex] ^ aFireLaneA[aIndex];
            //
            aSpiritLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_b loop 4
        //
        // Ingress:
        //      aSpiritLaneC (-->), aSpiritLaneA (-->), aWaterLaneA (-->), aWaterLaneD (<-?->)
        //
        // Cross:
        //      aSpiritLaneB (<--), aWoodLaneC (<--), aWindLaneA (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aSpiritLaneD
        //
        for (;;) {
            //
            aIngress = aSpiritLaneC[aIndex] ^ aSpiritLaneA[aIndex];
            aIngress ^= aWaterLaneA[aIndex] ^ aWaterLaneD[aIndex];
            //
            aCross = aSpiritLaneB[aIndex] ^ aWoodLaneC[aIndex];
            aCross ^= aWindLaneA[aIndex] ^ aEarthLaneC[aIndex];
            //
            aSpiritLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_B kdf_b_loop_b (end)

}

void TwistExpander_Achernar_Arx::KDF_B_C() {


    // GSeedRunKDF_B_C kdf_b_loop_c (start)
    {
        //
        // kdf_b_loop_c loop 1
        //
        // Ingress:
        //      aSpiritLaneA (-->), aSpiritLaneB (-->), aSource (-->), aFireLaneD (<-?->)
        //
        // Cross:
        //      aSpiritLaneC (<--), aSpiritLaneD (<--), aWindLaneD (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (;;) {
            //
            aIngress = aSpiritLaneA[aIndex] ^ aSpiritLaneB[aIndex];
            aIngress ^= aSource[aIndex] ^ aFireLaneD[aIndex];
            //
            aCross = aSpiritLaneC[aIndex] ^ aSpiritLaneD[aIndex];
            aCross ^= aWindLaneD[aIndex] ^ aWindLaneC[aIndex];
            //
            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_c loop 2
        //
        // Ingress:
        //      aFuseLaneA (-->), aSpiritLaneC (-->), aWoodLaneB (-->), aWoodLaneD (<-?->)
        //
        // Cross:
        //      aSpiritLaneA (<--), aSpiritLaneD (<--), aWindLaneA (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (;;) {
            //
            aIngress = aFuseLaneA[aIndex] ^ aSpiritLaneC[aIndex];
            aIngress ^= aWoodLaneB[aIndex] ^ aWoodLaneD[aIndex];
            //
            aCross = aSpiritLaneA[aIndex] ^ aSpiritLaneD[aIndex];
            aCross ^= aWindLaneA[aIndex] ^ aEarthLaneD[aIndex];
            //
            aFuseLaneB[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_c loop 3
        //
        // Ingress:
        //      aFuseLaneB (-->), aSpiritLaneD (-->), aWoodLaneA (-->), aWaterLaneB (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aSpiritLaneB (<--), aWindLaneB (<--), aFireLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (;;) {
            //
            aIngress = aFuseLaneB[aIndex] ^ aSpiritLaneD[aIndex];
            aIngress ^= aWoodLaneA[aIndex] ^ aWaterLaneB[aIndex];
            //
            aCross = aFuseLaneA[aIndex] ^ aSpiritLaneB[aIndex];
            aCross ^= aWindLaneB[aIndex] ^ aFireLaneC[aIndex];
            //
            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_c loop 4
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aWaterLaneC (-->), aWaterLaneA (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aSpiritLaneC (<--), aWoodLaneC (<--), aWaterLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (;;) {
            //
            aIngress = aFuseLaneC[aIndex] ^ aFuseLaneA[aIndex];
            aIngress ^= aWaterLaneC[aIndex] ^ aWaterLaneA[aIndex];
            //
            aCross = aFuseLaneB[aIndex] ^ aSpiritLaneC[aIndex];
            aCross ^= aWoodLaneC[aIndex] ^ aWaterLaneD[aIndex];
            //
            aFuseLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_C kdf_b_loop_c (end)

}

void TwistExpander_Achernar_Arx::KDF_B_D() {


    // GSeedRunKDF_B_D kdf_b_loop_d (start)
    {
        //
        // kdf_b_loop_d loop 1
        //
        // Ingress:
        //      aPoisonLaneA (-->), aPoisonLaneB (-->), aWoodLaneD (-->), aWoodLaneC (<-?->)
        //
        // Cross:
        //      aPoisonLaneC (<--), aPoisonLaneD (<--), aSpiritLaneA (<--), aSpiritLaneD (<-?->)
        //
        // Destination:
        //      aHeartLaneA
        //
        for (;;) {
            //
            aIngress = aPoisonLaneA[aIndex] ^ aPoisonLaneB[aIndex];
            aIngress ^= aWoodLaneD[aIndex] ^ aWoodLaneC[aIndex];
            //
            aCross = aPoisonLaneC[aIndex] ^ aPoisonLaneD[aIndex];
            aCross ^= aSpiritLaneA[aIndex] ^ aSpiritLaneD[aIndex];
            //
            aHeartLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_d loop 2
        //
        // Ingress:
        //      aHeartLaneA (-->), aPoisonLaneC (-->), aWaterLaneB (-->), aSpiritLaneC (<-?->)
        //
        // Cross:
        //      aPoisonLaneA (<--), aPoisonLaneD (<--), aWindLaneC (<--), aFireLaneB (<-?->)
        //
        // Destination:
        //      aHeartLaneB
        //
        for (;;) {
            //
            aIngress = aHeartLaneA[aIndex] ^ aPoisonLaneC[aIndex];
            aIngress ^= aWaterLaneB[aIndex] ^ aSpiritLaneC[aIndex];
            //
            aCross = aPoisonLaneA[aIndex] ^ aPoisonLaneD[aIndex];
            aCross ^= aWindLaneC[aIndex] ^ aFireLaneB[aIndex];
            //
            aHeartLaneB[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_d loop 3
        //
        // Ingress:
        //      aHeartLaneB (-->), aPoisonLaneD (-->), aWaterLaneC (-->), aSpiritLaneB (<-?->)
        //
        // Cross:
        //      aHeartLaneA (<--), aPoisonLaneB (<--), aWoodLaneA (<--), aFireLaneA (<-?->)
        //
        // Destination:
        //      aHeartLaneC
        //
        for (;;) {
            //
            aIngress = aHeartLaneB[aIndex] ^ aPoisonLaneD[aIndex];
            aIngress ^= aWaterLaneC[aIndex] ^ aSpiritLaneB[aIndex];
            //
            aCross = aHeartLaneA[aIndex] ^ aPoisonLaneB[aIndex];
            aCross ^= aWoodLaneA[aIndex] ^ aFireLaneA[aIndex];
            //
            aHeartLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_d loop 4
        //
        // Ingress:
        //      aHeartLaneC (-->), aHeartLaneA (-->), aWoodLaneB (-->), aWaterLaneD (<-?->)
        //
        // Cross:
        //      aHeartLaneB (<--), aPoisonLaneC (<--), aWindLaneD (<--), aWaterLaneA (<-?->)
        //
        // Destination:
        //      aHeartLaneD
        //
        for (;;) {
            //
            aIngress = aHeartLaneC[aIndex] ^ aHeartLaneA[aIndex];
            aIngress ^= aWoodLaneB[aIndex] ^ aWaterLaneD[aIndex];
            //
            aCross = aHeartLaneB[aIndex] ^ aPoisonLaneC[aIndex];
            aCross ^= aWindLaneD[aIndex] ^ aWaterLaneA[aIndex];
            //
            aHeartLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_D kdf_b_loop_d (end)

}

void TwistExpander_Achernar_Arx::Seed_A() {


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
            aCross = aPoisonLaneB[aIndex] ^ aKeyRowReadB[W_KEY1 - aIndex];
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

void TwistExpander_Achernar_Arx::Seed_B() {


    // GSeedRunSeed_B seed_loop_b (start)
    {
        //
        // seed_loop_b loop 1
        //
        // Ingress:
        //      aEarthLaneA (-->), aEarthLaneB (-->), aKeyRowReadB (<-?->)
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
            aIngress ^= aKeyRowReadB[W_KEY1 - aIndex];
            //
            aCross = aEarthLaneC[aIndex] ^ aEarthLaneD[aIndex];
            //
            aPoisonLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_b loop 2
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
        // seed_loop_b loop 3
        //
        // Ingress:
        //      aPoisonLaneD (-->), aEarthLaneA (-->), aPoisonLaneA (<-?->)
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
            aIngress ^= aPoisonLaneA[aIndex];
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
            aIngress ^= aKeyRowReadA[W_KEY1 - aIndex];
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

void TwistExpander_Achernar_Arx::Seed_C() {


    // GSeedRunSeed_C seed_loop_c (start)
    {
        //
        // seed_loop_c loop 1
        //
        // Ingress:
        //      aFireLaneA (-->), aFireLaneB (-->), aSource (<-?->)
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
            aIngress ^= aSource[aIndex];
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
        //      aHeartLaneA (-->), aFireLaneC (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), aPoisonLaneC (<-?->)
        //
        // Destination:
        //      aHeartLaneB
        //
        for (;;) {
            //
            aIngress = aHeartLaneA[aIndex] ^ aFireLaneC[aIndex];
            aIngress ^= aKeyRowReadA[aIndex];
            //
            aCross = aFireLaneA[aIndex] ^ aFireLaneD[aIndex];
            aCross ^= aPoisonLaneC[aIndex];
            //
            aHeartLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 3
        //
        // Ingress:
        //      aHeartLaneB (-->), aFireLaneA (-->), aEarthLaneC (<-?->)
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
            aIngress ^= aEarthLaneC[aIndex];
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
        //      aFuseLaneA (-->), aFireLaneD (-->), aPoisonLaneB (<-?->)
        //
        // Cross:
        //      aHeartLaneB (<--), aFireLaneA (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (;;) {
            //
            aIngress = aFuseLaneA[aIndex] ^ aFireLaneD[aIndex];
            aIngress ^= aPoisonLaneB[aIndex];
            //
            aCross = aHeartLaneB[aIndex] ^ aFireLaneA[aIndex];
            aCross ^= aEarthLaneA[aIndex];
            //
            aFuseLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 5
        //
        // Ingress:
        //      aFuseLaneB (-->), aHeartLaneB (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aHeartLaneA (<--), aKeyRowReadB (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (;;) {
            //
            aIngress = aFuseLaneB[aIndex] ^ aHeartLaneB[aIndex];
            aIngress ^= aEarthLaneD[aIndex];
            //
            aCross = aFuseLaneA[aIndex] ^ aHeartLaneA[aIndex];
            aCross ^= aKeyRowReadB[aIndex];
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

void TwistExpander_Achernar_Arx::Seed_D() {


    // GSeedRunSeed_D seed_loop_d (start)
    {
        //
        // seed_loop_d loop 1
        //
        // Ingress:
        //      aWindLaneA (-->), aWindLaneB (-->), aEarthLaneC (-->), aPoisonLaneA (<-?->)
        //
        // Cross:
        //      aWindLaneC (<--), aWindLaneD (<--), aFireLaneB (<-?->)
        //
        // Destination:
        //      aHeartLaneC
        //
        for (;;) {
            //
            aIngress = aWindLaneA[aIndex] ^ aWindLaneB[aIndex];
            aIngress ^= aEarthLaneC[aIndex] ^ aPoisonLaneA[aIndex];
            //
            aCross = aWindLaneC[aIndex] ^ aWindLaneD[aIndex];
            aCross ^= aFireLaneB[aIndex];
            //
            aHeartLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 2
        //
        // Ingress:
        //      aHeartLaneC (-->), aWindLaneC (-->), aPoisonLaneB (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aWindLaneD (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aHeartLaneD
        //
        for (;;) {
            //
            aIngress = aHeartLaneC[aIndex] ^ aWindLaneC[aIndex];
            aIngress ^= aPoisonLaneB[aIndex] ^ aEarthLaneA[aIndex];
            //
            aCross = aWindLaneA[aIndex] ^ aWindLaneD[aIndex];
            aCross ^= aEarthLaneB[aIndex];
            //
            aHeartLaneD[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 3
        //
        // Ingress:
        //      aHeartLaneD (-->), aWindLaneA (-->), aSource (-->), aHeartLaneB (<-?->)
        //
        // Cross:
        //      aHeartLaneC (<--), aWindLaneC (<--), aKeyRowReadA (<-?->)
        //
        // Destination:
        //      aWaterLaneA
        //
        for (;;) {
            //
            aIngress = aHeartLaneD[aIndex] ^ aWindLaneA[aIndex];
            aIngress ^= aSource[aIndex] ^ aHeartLaneB[aIndex];
            //
            aCross = aHeartLaneC[aIndex] ^ aWindLaneC[aIndex];
            aCross ^= aKeyRowReadA[aIndex];
            //
            aWaterLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 4
        //
        // Ingress:
        //      aWaterLaneA (-->), aWindLaneD (-->), aPoisonLaneD (-->), aHeartLaneA (<-?->)
        //
        // Cross:
        //      aHeartLaneD (<--), aWindLaneA (<--), aFireLaneC (<-?->)
        //
        // Destination:
        //      aWaterLaneB
        //
        for (;;) {
            //
            aIngress = aWaterLaneA[aIndex] ^ aWindLaneD[aIndex];
            aIngress ^= aPoisonLaneD[aIndex] ^ aHeartLaneA[aIndex];
            //
            aCross = aHeartLaneD[aIndex] ^ aWindLaneA[aIndex];
            aCross ^= aFireLaneC[aIndex];
            //
            aWaterLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 5
        //
        // Ingress:
        //      aWaterLaneB (-->), aHeartLaneD (-->), aKeyRowReadB (-->), aFireLaneA (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aHeartLaneC (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aWaterLaneC
        //
        for (;;) {
            //
            aIngress = aWaterLaneB[aIndex] ^ aHeartLaneD[aIndex];
            aIngress ^= aKeyRowReadB[aIndex] ^ aFireLaneA[aIndex];
            //
            aCross = aWaterLaneA[aIndex] ^ aHeartLaneC[aIndex];
            aCross ^= aEarthLaneD[aIndex];
            //
            aWaterLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 6
        //
        // Ingress:
        //      aWaterLaneC (-->), aWaterLaneA (-->), aPoisonLaneC (<-?->)
        //
        // Cross:
        //      aWaterLaneB (<--), aWindLaneB (<--), aFireLaneD (<-?->)
        //
        // Destination:
        //      aWaterLaneD
        //
        for (;;) {
            //
            aIngress = aWaterLaneC[aIndex] ^ aWaterLaneA[aIndex];
            aIngress ^= aPoisonLaneC[aIndex];
            //
            aCross = aWaterLaneB[aIndex] ^ aWindLaneB[aIndex];
            aCross ^= aFireLaneD[aIndex];
            //
            aWaterLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_D seed_loop_d (end)

}

void TwistExpander_Achernar_Arx::Seed_E() {


    // GSeedRunSeed_E seed_loop_e (start)
    {
        //
        // seed_loop_e loop 1
        //
        // Ingress:
        //      aWaterLaneA (-->), aWaterLaneB (-->), aWindLaneA (-->), aPoisonLaneC (<-?->)
        //
        // Cross:
        //      aWaterLaneC (<--), aWaterLaneD (<--), aFireLaneB (<--), aKeyRowReadA (<-?->)
        //
        // Destination:
        //      aWoodLaneA
        //
        for (;;) {
            //
            aIngress = aWaterLaneA[aIndex] ^ aWaterLaneB[aIndex];
            aIngress ^= aWindLaneA[aIndex] ^ aPoisonLaneC[aIndex];
            //
            aCross = aWaterLaneC[aIndex] ^ aWaterLaneD[aIndex];
            aCross ^= aFireLaneB[aIndex] ^ aKeyRowReadA[aIndex];
            //
            aWoodLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 2
        //
        // Ingress:
        //      aWoodLaneA (-->), aWaterLaneC (-->), aPoisonLaneB (-->), aHeartLaneB (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWaterLaneD (<--), aHeartLaneA (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aWoodLaneB
        //
        for (;;) {
            //
            aIngress = aWoodLaneA[aIndex] ^ aWaterLaneC[aIndex];
            aIngress ^= aPoisonLaneB[aIndex] ^ aHeartLaneB[aIndex];
            //
            aCross = aWaterLaneA[aIndex] ^ aWaterLaneD[aIndex];
            aCross ^= aHeartLaneA[aIndex] ^ aEarthLaneA[aIndex];
            //
            aWoodLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 3
        //
        // Ingress:
        //      aWoodLaneB (-->), aWaterLaneA (-->), aHeartLaneC (-->), aFireLaneC (<-?->)
        //
        // Cross:
        //      aWoodLaneA (<--), aWaterLaneC (<--), aHeartLaneD (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aIceLaneA
        //
        for (;;) {
            //
            aIngress = aWoodLaneB[aIndex] ^ aWaterLaneA[aIndex];
            aIngress ^= aHeartLaneC[aIndex] ^ aFireLaneC[aIndex];
            //
            aCross = aWoodLaneA[aIndex] ^ aWaterLaneC[aIndex];
            aCross ^= aHeartLaneD[aIndex] ^ aEarthLaneC[aIndex];
            //
            aIceLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 4
        //
        // Ingress:
        //      aIceLaneA (-->), aWaterLaneD (-->), aPoisonLaneD (-->), aWindLaneD (<-?->)
        //
        // Cross:
        //      aWoodLaneB (<--), aWaterLaneA (<--), aWindLaneC (<--), aWindLaneB (<-?->)
        //
        // Destination:
        //      aIceLaneB
        //
        for (;;) {
            //
            aIngress = aIceLaneA[aIndex] ^ aWaterLaneD[aIndex];
            aIngress ^= aPoisonLaneD[aIndex] ^ aWindLaneD[aIndex];
            //
            aCross = aWoodLaneB[aIndex] ^ aWaterLaneA[aIndex];
            aCross ^= aWindLaneC[aIndex] ^ aWindLaneB[aIndex];
            //
            aIceLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 5
        //
        // Ingress:
        //      aIceLaneB (-->), aWoodLaneB (-->), aKeyRowReadB (-->), aEarthLaneB (<-?->)
        //
        // Cross:
        //      aIceLaneA (<--), aWoodLaneA (<--), aFireLaneA (<--), aFireLaneD (<-?->)
        //
        // Destination:
        //      aIceLaneC
        //
        for (;;) {
            //
            aIngress = aIceLaneB[aIndex] ^ aWoodLaneB[aIndex];
            aIngress ^= aKeyRowReadB[aIndex] ^ aEarthLaneB[aIndex];
            //
            aCross = aIceLaneA[aIndex] ^ aWoodLaneA[aIndex];
            aCross ^= aFireLaneA[aIndex] ^ aFireLaneD[aIndex];
            //
            aIceLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 6
        //
        // Ingress:
        //      aIceLaneC (-->), aIceLaneA (-->), aSource (-->), aPoisonLaneA (<-?->)
        //
        // Cross:
        //      aIceLaneB (<--), aWaterLaneB (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aIceLaneD
        //
        for (;;) {
            //
            aIngress = aIceLaneC[aIndex] ^ aIceLaneA[aIndex];
            aIngress ^= aSource[aIndex] ^ aPoisonLaneA[aIndex];
            //
            aCross = aIceLaneB[aIndex] ^ aWaterLaneB[aIndex];
            aCross ^= aEarthLaneD[aIndex];
            //
            aIceLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_E seed_loop_e (end)

}

void TwistExpander_Achernar_Arx::Seed_F() {


    // GSeedRunSeed_F seed_loop_f (start)
    {
        //
        // seed_loop_f loop 1
        //
        // Ingress:
        //      aIceLaneA (-->), aIceLaneB (-->), aWoodLaneA (-->), aFireLaneD (<-?->)
        //
        // Cross:
        //      aIceLaneC (<--), aIceLaneD (<--), aHeartLaneD (<--), aWaterLaneB (<-?->)
        //
        // Destination:
        //      aWoodLaneC
        //
        for (;;) {
            //
            aIngress = aIceLaneA[aIndex] ^ aIceLaneB[aIndex];
            aIngress ^= aWoodLaneA[aIndex] ^ aFireLaneD[aIndex];
            //
            aCross = aIceLaneC[aIndex] ^ aIceLaneD[aIndex];
            aCross ^= aHeartLaneD[aIndex] ^ aWaterLaneB[aIndex];
            //
            aWoodLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 2
        //
        // Ingress:
        //      aWoodLaneC (-->), aIceLaneC (-->), aWaterLaneC (-->), aFireLaneA (<-?->)
        //
        // Cross:
        //      aIceLaneA (<--), aIceLaneD (<--), aFireLaneC (<--), aHeartLaneC (<-?->)
        //
        // Destination:
        //      aWoodLaneD
        //
        for (;;) {
            //
            aIngress = aWoodLaneC[aIndex] ^ aIceLaneC[aIndex];
            aIngress ^= aWaterLaneC[aIndex] ^ aFireLaneA[aIndex];
            //
            aCross = aIceLaneA[aIndex] ^ aIceLaneD[aIndex];
            aCross ^= aFireLaneC[aIndex] ^ aHeartLaneC[aIndex];
            //
            aWoodLaneD[aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 3
        //
        // Ingress:
        //      aWoodLaneD (-->), aIceLaneA (-->), aWaterLaneD (-->), aKeyRowReadB (<-?->)
        //
        // Cross:
        //      aWoodLaneC (<--), aIceLaneC (<--), aFireLaneB (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (;;) {
            //
            aIngress = aWoodLaneD[aIndex] ^ aIceLaneA[aIndex];
            aIngress ^= aWaterLaneD[aIndex] ^ aKeyRowReadB[aIndex];
            //
            aCross = aWoodLaneC[aIndex] ^ aIceLaneC[aIndex];
            aCross ^= aFireLaneB[aIndex] ^ aWindLaneC[aIndex];
            //
            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 4
        //
        // Ingress:
        //      aFuseLaneA (-->), aIceLaneD (-->), aSource (-->), aEarthLaneB (<-?->)
        //
        // Cross:
        //      aWoodLaneD (<--), aIceLaneA (<--), aHeartLaneA (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (;;) {
            //
            aIngress = aFuseLaneA[aIndex] ^ aIceLaneD[aIndex];
            aIngress ^= aSource[aIndex] ^ aEarthLaneB[aIndex];
            //
            aCross = aWoodLaneD[aIndex] ^ aIceLaneA[aIndex];
            aCross ^= aHeartLaneA[aIndex] ^ aEarthLaneC[aIndex];
            //
            aFuseLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 5
        //
        // Ingress:
        //      aFuseLaneB (-->), aWoodLaneD (-->), aWindLaneB (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aWoodLaneC (<--), aWindLaneD (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (;;) {
            //
            aIngress = aFuseLaneB[aIndex] ^ aWoodLaneD[aIndex];
            aIngress ^= aWindLaneB[aIndex] ^ aEarthLaneD[aIndex];
            //
            aCross = aFuseLaneA[aIndex] ^ aWoodLaneC[aIndex];
            aCross ^= aWindLaneD[aIndex] ^ aWindLaneA[aIndex];
            //
            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 6
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aHeartLaneB (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aIceLaneB (<--), aWoodLaneB (<--), aWaterLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (;;) {
            //
            aIngress = aFuseLaneC[aIndex] ^ aFuseLaneA[aIndex];
            aIngress ^= aHeartLaneB[aIndex] ^ aKeyRowReadA[W_KEY1 - aIndex];
            //
            aCross = aFuseLaneB[aIndex] ^ aIceLaneB[aIndex];
            aCross ^= aWoodLaneB[aIndex] ^ aWaterLaneA[aIndex];
            //
            aFuseLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_F seed_loop_f (end)

}

void TwistExpander_Achernar_Arx::Seed_G() {


    // GSeedRunSeed_G seed_loop_g (start)
    {
        //
        // seed_loop_g loop 1
        //
        // Ingress:
        //      aSpiritLaneA (-->), aSpiritLaneB (-->), aKeyRowReadA (-->), aHeartLaneC (<-?->)
        //
        // Cross:
        //      aSpiritLaneC (<--), aSpiritLaneD (<--), aIceLaneC (<--), aWaterLaneC (<-?->)
        //
        // Destination:
        //      aEarthLaneC
        //
        for (;;) {
            //
            aIngress = aSpiritLaneA[aIndex] ^ aSpiritLaneB[aIndex];
            aIngress ^= aKeyRowReadA[aIndex] ^ aHeartLaneC[aIndex];
            //
            aCross = aSpiritLaneC[aIndex] ^ aSpiritLaneD[aIndex];
            aCross ^= aIceLaneC[aIndex] ^ aWaterLaneC[aIndex];
            //
            aEarthLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_g loop 2
        //
        // Ingress:
        //      aEarthLaneC (-->), aSpiritLaneC (-->), aKeyRowReadB (-->), aWoodLaneA (<-?->)
        //
        // Cross:
        //      aSpiritLaneA (<--), aSpiritLaneD (<--), aWindLaneB (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aEarthLaneD
        //
        for (;;) {
            //
            aIngress = aEarthLaneC[aIndex] ^ aSpiritLaneC[aIndex];
            aIngress ^= aKeyRowReadB[aIndex] ^ aWoodLaneA[aIndex];
            //
            aCross = aSpiritLaneA[aIndex] ^ aSpiritLaneD[aIndex];
            aCross ^= aWindLaneB[aIndex] ^ aWindLaneA[aIndex];
            //
            aEarthLaneD[aIndex] = aIngress;
        }
    
        //
        // seed_loop_g loop 3
        //
        // Ingress:
        //      aEarthLaneD (-->), aSpiritLaneA (-->), aWoodLaneC (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aEarthLaneC (<--), aSpiritLaneC (<--), aIceLaneB (<--), aWaterLaneD (<-?->)
        //
        // Destination:
        //      aFireLaneA
        //
        for (;;) {
            //
            aIngress = aEarthLaneD[aIndex] ^ aSpiritLaneA[aIndex];
            aIngress ^= aWoodLaneC[aIndex] ^ aEarthLaneA[aIndex];
            //
            aCross = aEarthLaneC[aIndex] ^ aSpiritLaneC[aIndex];
            aCross ^= aIceLaneB[aIndex] ^ aWaterLaneD[aIndex];
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_g loop 4
        //
        // Ingress:
        //      aFireLaneA (-->), aSpiritLaneD (-->), aHeartLaneB (-->), aIceLaneD (<-?->)
        //
        // Cross:
        //      aEarthLaneD (<--), aSpiritLaneA (<--), aHeartLaneD (<--), aWoodLaneD (<-?->)
        //
        // Destination:
        //      aFireLaneB
        //
        for (;;) {
            //
            aIngress = aFireLaneA[aIndex] ^ aSpiritLaneD[aIndex];
            aIngress ^= aHeartLaneB[aIndex] ^ aIceLaneD[aIndex];
            //
            aCross = aEarthLaneD[aIndex] ^ aSpiritLaneA[aIndex];
            aCross ^= aHeartLaneD[aIndex] ^ aWoodLaneD[aIndex];
            //
            aFireLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_g loop 5
        //
        // Ingress:
        //      aFireLaneB (-->), aEarthLaneD (-->), aWaterLaneB (-->), aWindLaneC (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aEarthLaneC (<--), aHeartLaneA (<--), aWindLaneD (<-?->)
        //
        // Destination:
        //      aFireLaneC
        //
        for (;;) {
            //
            aIngress = aFireLaneB[aIndex] ^ aEarthLaneD[aIndex];
            aIngress ^= aWaterLaneB[aIndex] ^ aWindLaneC[aIndex];
            //
            aCross = aFireLaneA[aIndex] ^ aEarthLaneC[aIndex];
            aCross ^= aHeartLaneA[aIndex] ^ aWindLaneD[aIndex];
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_g loop 6
        //
        // Ingress:
        //      aFireLaneC (-->), aFireLaneA (-->), aIceLaneA (-->), aWoodLaneB (<-?->)
        //
        // Cross:
        //      aFireLaneB (<--), aSpiritLaneB (<--), aSource (<--), aWaterLaneA (<-?->)
        //
        // Destination:
        //      aFireLaneD
        //
        for (;;) {
            //
            aIngress = aFireLaneC[aIndex] ^ aFireLaneA[aIndex];
            aIngress ^= aIceLaneA[aIndex] ^ aWoodLaneB[aIndex];
            //
            aCross = aFireLaneB[aIndex] ^ aSpiritLaneB[aIndex];
            aCross ^= aSource[aIndex] ^ aWaterLaneA[aIndex];
            //
            aFireLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_G seed_loop_g (end)

}

void TwistExpander_Achernar_Arx::Seed_H() {


    // GSeedRunSeed_H seed_loop_h (start)
    {
        //
        // seed_loop_h loop 1
        //
        // Ingress:
        //      aFireLaneA (-->), aFireLaneB (-->), aWindLaneA (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aFireLaneC (<--), aFireLaneD (<--), aPoisonLaneD (<--), aWaterLaneD (<-?->)
        //
        // Destination:
        //      aEarthLaneC
        //
        for (;;) {
            //
            aIngress = aFireLaneA[aIndex] ^ aFireLaneB[aIndex];
            aIngress ^= aWindLaneA[aIndex] ^ aKeyRowReadA[W_KEY1 - aIndex];
            //
            aCross = aFireLaneC[aIndex] ^ aFireLaneD[aIndex];
            aCross ^= aPoisonLaneD[aIndex] ^ aWaterLaneD[aIndex];
            //
            aEarthLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_h loop 2
        //
        // Ingress:
        //      aEarthLaneC (-->), aFireLaneC (-->), aIceLaneD (-->), aWindLaneB (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), aIceLaneB (<--), aKeyRowReadB (<-?->)
        //
        // Destination:
        //      aEarthLaneD
        //
        for (;;) {
            //
            aIngress = aEarthLaneC[aIndex] ^ aFireLaneC[aIndex];
            aIngress ^= aIceLaneD[aIndex] ^ aWindLaneB[aIndex];
            //
            aCross = aFireLaneA[aIndex] ^ aFireLaneD[aIndex];
            aCross ^= aIceLaneB[aIndex] ^ aKeyRowReadB[W_KEY1 - aIndex];
            //
            aEarthLaneD[aIndex] = aIngress;
        }
    
        //
        // seed_loop_h loop 3
        //
        // Ingress:
        //      aEarthLaneD (-->), aFireLaneA (-->), aPoisonLaneC (-->), aWaterLaneA (<-?->)
        //
        // Cross:
        //      aEarthLaneC (<--), aFireLaneC (<--), aWoodLaneA (<--), aWoodLaneD (<-?->)
        //
        // Destination:
        //      aHeartLaneA
        //
        for (;;) {
            //
            aIngress = aEarthLaneD[aIndex] ^ aFireLaneA[aIndex];
            aIngress ^= aPoisonLaneC[aIndex] ^ aWaterLaneA[aIndex];
            //
            aCross = aEarthLaneC[aIndex] ^ aFireLaneC[aIndex];
            aCross ^= aWoodLaneA[aIndex] ^ aWoodLaneD[aIndex];
            //
            aHeartLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_h loop 4
        //
        // Ingress:
        //      aHeartLaneA (-->), aFireLaneD (-->), aSpiritLaneA (-->), aSpiritLaneB (<-?->)
        //
        // Cross:
        //      aEarthLaneD (<--), aFireLaneA (<--), aWaterLaneB (<--), aIceLaneA (<-?->)
        //
        // Destination:
        //      aHeartLaneB
        //
        for (;;) {
            //
            aIngress = aHeartLaneA[aIndex] ^ aFireLaneD[aIndex];
            aIngress ^= aSpiritLaneA[aIndex] ^ aSpiritLaneB[aIndex];
            //
            aCross = aEarthLaneD[aIndex] ^ aFireLaneA[aIndex];
            aCross ^= aWaterLaneB[aIndex] ^ aIceLaneA[aIndex];
            //
            aHeartLaneB[aIndex] = aIngress;
        }
    
        //
        // seed_loop_h loop 5
        //
        // Ingress:
        //      aHeartLaneB (-->), aEarthLaneD (-->), aWaterLaneC (-->), aSpiritLaneD (<-?->)
        //
        // Cross:
        //      aHeartLaneA (<--), aEarthLaneC (<--), aWoodLaneC (<--), aWindLaneD (<-?->)
        //
        // Destination:
        //      aHeartLaneC
        //
        for (;;) {
            //
            aIngress = aHeartLaneB[aIndex] ^ aEarthLaneD[aIndex];
            aIngress ^= aWaterLaneC[aIndex] ^ aSpiritLaneD[aIndex];
            //
            aCross = aHeartLaneA[aIndex] ^ aEarthLaneC[aIndex];
            aCross ^= aWoodLaneC[aIndex] ^ aWindLaneD[aIndex];
            //
            aHeartLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_h loop 6
        //
        // Ingress:
        //      aHeartLaneC (-->), aHeartLaneA (-->), aWoodLaneB (-->), aIceLaneC (<-?->)
        //
        // Cross:
        //      aHeartLaneB (<--), aFireLaneB (<--), aWindLaneC (<--), aSpiritLaneC (<-?->)
        //
        // Destination:
        //      aHeartLaneD
        //
        for (;;) {
            //
            aIngress = aHeartLaneC[aIndex] ^ aHeartLaneA[aIndex];
            aIngress ^= aWoodLaneB[aIndex] ^ aIceLaneC[aIndex];
            //
            aCross = aHeartLaneB[aIndex] ^ aFireLaneB[aIndex];
            aCross ^= aWindLaneC[aIndex] ^ aSpiritLaneC[aIndex];
            //
            aHeartLaneD[aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_H seed_loop_h (end)

}

void TwistExpander_Achernar_Arx::Twist_A() {


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

void TwistExpander_Achernar_Arx::Twist_B() {


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
        // twist_loop_b loop 3
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
            aIngress ^= aKeyRowReadB[W_KEY1 - aIndex];
            //
            aCross = aPoisonLaneD[aIndex] ^ aEarthLaneA[aIndex];
            //
            aFireLaneB[aIndex] = aIngress;
        }
    
        //
        // twist_loop_b loop 5
        //
        // Ingress:
        //      aFireLaneB (-->), aPoisonLaneD (-->), aPoisonLaneA (<-?->)
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
            aIngress ^= aPoisonLaneA[aIndex];
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

void TwistExpander_Achernar_Arx::Twist_C() {


    // GTwistRunTwist_C twist_loop_c (start)
    {
        //
        // twist_loop_c loop 1
        //
        // Ingress:
        //      aFireLaneA (-->), aFireLaneB (-->), aPoisonLaneB (<-?->)
        //
        // Cross:
        //      aFireLaneC (<--), aFireLaneD (<--), aPoisonLaneD (<-?->)
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
            aCross ^= aPoisonLaneD[aIndex];
            //
            aWoodLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_c loop 2
        //
        // Ingress:
        //      aWoodLaneA (-->), aFireLaneC (-->), aSource (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), aPoisonLaneC (<-?->)
        //
        // Destination:
        //      aWoodLaneB
        //
        for (;;) {
            //
            aIngress = aWoodLaneA[aIndex] ^ aFireLaneC[aIndex];
            aIngress ^= aSource[aIndex];
            //
            aCross = aFireLaneA[aIndex] ^ aFireLaneD[aIndex];
            aCross ^= aPoisonLaneC[aIndex];
            //
            aWoodLaneB[aIndex] = aIngress;
        }
    
        //
        // twist_loop_c loop 3
        //
        // Ingress:
        //      aWoodLaneB (-->), aFireLaneA (-->), aKeyRowReadB (<-?->)
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
            aIngress ^= aKeyRowReadB[aIndex];
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
        //      aWoodLaneB (<--), aFireLaneA (<--), aEarthLaneD (<-?->)
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
            aCross ^= aEarthLaneD[aIndex];
            //
            aFuseLaneB[aIndex] = aIngress;
        }
    
        //
        // twist_loop_c loop 5
        //
        // Ingress:
        //      aFuseLaneB (-->), aWoodLaneB (-->), aEarthLaneB (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aWoodLaneA (<--), aKeyRowReadA (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (;;) {
            //
            aIngress = aFuseLaneB[aIndex] ^ aWoodLaneB[aIndex];
            aIngress ^= aEarthLaneB[aIndex];
            //
            aCross = aFuseLaneA[aIndex] ^ aWoodLaneA[aIndex];
            aCross ^= aKeyRowReadA[W_KEY1 - aIndex];
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

void TwistExpander_Achernar_Arx::Twist_D() {


    // GTwistRunTwist_D twist_loop_d (start)
    {
        //
        // twist_loop_d loop 1
        //
        // Ingress:
        //      aWindLaneA (-->), aWindLaneB (-->), aFireLaneA (-->), aPoisonLaneA (<-?->)
        //
        // Cross:
        //      aWindLaneC (<--), aWindLaneD (<--), aWoodLaneB (<-?->)
        //
        // Destination:
        //      aSpiritLaneA
        //
        for (;;) {
            //
            aIngress = aWindLaneA[aIndex] ^ aWindLaneB[aIndex];
            aIngress ^= aFireLaneA[aIndex] ^ aPoisonLaneA[aIndex];
            //
            aCross = aWindLaneC[aIndex] ^ aWindLaneD[aIndex];
            aCross ^= aWoodLaneB[aIndex];
            //
            aSpiritLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 2
        //
        // Ingress:
        //      aSpiritLaneA (-->), aWindLaneC (-->), aFireLaneC (-->), aEarthLaneC (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aWindLaneD (<--), aKeyRowReadA (<-?->)
        //
        // Destination:
        //      aSpiritLaneB
        //
        for (;;) {
            //
            aIngress = aSpiritLaneA[aIndex] ^ aWindLaneC[aIndex];
            aIngress ^= aFireLaneC[aIndex] ^ aEarthLaneC[aIndex];
            //
            aCross = aWindLaneA[aIndex] ^ aWindLaneD[aIndex];
            aCross ^= aKeyRowReadA[W_KEY1 - aIndex];
            //
            aSpiritLaneB[aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 3
        //
        // Ingress:
        //      aSpiritLaneB (-->), aWindLaneA (-->), aPoisonLaneC (-->), aSource (<-?->)
        //
        // Cross:
        //      aSpiritLaneA (<--), aWindLaneC (<--), aKeyRowReadB (<-?->)
        //
        // Destination:
        //      aWaterLaneA
        //
        for (;;) {
            //
            aIngress = aSpiritLaneB[aIndex] ^ aWindLaneA[aIndex];
            aIngress ^= aPoisonLaneC[aIndex] ^ aSource[aIndex];
            //
            aCross = aSpiritLaneA[aIndex] ^ aWindLaneC[aIndex];
            aCross ^= aKeyRowReadB[aIndex];
            //
            aWaterLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 4
        //
        // Ingress:
        //      aWaterLaneA (-->), aWindLaneD (-->), aPoisonLaneB (-->), aFireLaneD (<-?->)
        //
        // Cross:
        //      aSpiritLaneB (<--), aWindLaneA (<--), aWoodLaneA (<-?->)
        //
        // Destination:
        //      aWaterLaneB
        //
        for (;;) {
            //
            aIngress = aWaterLaneA[aIndex] ^ aWindLaneD[aIndex];
            aIngress ^= aPoisonLaneB[aIndex] ^ aFireLaneD[aIndex];
            //
            aCross = aSpiritLaneB[aIndex] ^ aWindLaneA[aIndex];
            aCross ^= aWoodLaneA[aIndex];
            //
            aWaterLaneB[aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 5
        //
        // Ingress:
        //      aWaterLaneB (-->), aSpiritLaneB (-->), aEarthLaneB (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aSpiritLaneA (<--), aPoisonLaneD (<-?->)
        //
        // Destination:
        //      aWaterLaneC
        //
        for (;;) {
            //
            aIngress = aWaterLaneB[aIndex] ^ aSpiritLaneB[aIndex];
            aIngress ^= aEarthLaneB[aIndex] ^ aEarthLaneA[aIndex];
            //
            aCross = aWaterLaneA[aIndex] ^ aSpiritLaneA[aIndex];
            aCross ^= aPoisonLaneD[aIndex];
            //
            aWaterLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 6
        //
        // Ingress:
        //      aWaterLaneC (-->), aWaterLaneA (-->), aEarthLaneD (<-?->)
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
            aIngress ^= aEarthLaneD[aIndex];
            //
            aCross = aWaterLaneB[aIndex] ^ aWindLaneB[aIndex];
            aCross ^= aFireLaneB[aIndex];
            //
            aWaterLaneD[aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_D twist_loop_d (end)

}

void TwistExpander_Achernar_Arx::Twist_E() {


    // GTwistRunTwist_E twist_loop_e (start)
    {
        //
        // twist_loop_e loop 1
        //
        // Ingress:
        //      aWaterLaneA (-->), aWaterLaneB (-->), aEarthLaneC (-->), aPoisonLaneC (<-?->)
        //
        // Cross:
        //      aWaterLaneC (<--), aWaterLaneD (<--), aWindLaneD (<--), aKeyRowReadA (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (;;) {
            //
            aIngress = aWaterLaneA[aIndex] ^ aWaterLaneB[aIndex];
            aIngress ^= aEarthLaneC[aIndex] ^ aPoisonLaneC[aIndex];
            //
            aCross = aWaterLaneC[aIndex] ^ aWaterLaneD[aIndex];
            aCross ^= aWindLaneD[aIndex] ^ aKeyRowReadA[W_KEY1 - aIndex];
            //
            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 2
        //
        // Ingress:
        //      aFuseLaneA (-->), aWaterLaneC (-->), aEarthLaneA (-->), aEarthLaneD (<-?->)
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
            aIngress ^= aEarthLaneA[aIndex] ^ aEarthLaneD[aIndex];
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
        //      aFuseLaneB (-->), aWaterLaneA (-->), aFireLaneD (-->), aSource (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aWaterLaneC (<--), aFireLaneA (<-?->)
        //
        // Destination:
        //      aHeartLaneA
        //
        for (;;) {
            //
            aIngress = aFuseLaneB[aIndex] ^ aWaterLaneA[aIndex];
            aIngress ^= aFireLaneD[aIndex] ^ aSource[aIndex];
            //
            aCross = aFuseLaneA[aIndex] ^ aWaterLaneC[aIndex];
            aCross ^= aFireLaneA[aIndex];
            //
            aHeartLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 4
        //
        // Ingress:
        //      aHeartLaneA (-->), aWaterLaneD (-->), aKeyRowReadB (-->), aFireLaneB (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aWaterLaneA (<--), aWoodLaneA (<-?->)
        //
        // Destination:
        //      aHeartLaneB
        //
        for (;;) {
            //
            aIngress = aHeartLaneA[aIndex] ^ aWaterLaneD[aIndex];
            aIngress ^= aKeyRowReadB[aIndex] ^ aFireLaneB[aIndex];
            //
            aCross = aFuseLaneB[aIndex] ^ aWaterLaneA[aIndex];
            aCross ^= aWoodLaneA[aIndex];
            //
            aHeartLaneB[aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 5
        //
        // Ingress:
        //      aHeartLaneB (-->), aFuseLaneB (-->), aPoisonLaneD (-->), aWindLaneC (<-?->)
        //
        // Cross:
        //      aHeartLaneA (<--), aFuseLaneA (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aHeartLaneC
        //
        for (;;) {
            //
            aIngress = aHeartLaneB[aIndex] ^ aFuseLaneB[aIndex];
            aIngress ^= aPoisonLaneD[aIndex] ^ aWindLaneC[aIndex];
            //
            aCross = aHeartLaneA[aIndex] ^ aFuseLaneA[aIndex];
            aCross ^= aEarthLaneB[aIndex];
            //
            aHeartLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 6
        //
        // Ingress:
        //      aHeartLaneC (-->), aHeartLaneA (-->), aWoodLaneB (-->), aWindLaneB (<-?->)
        //
        // Cross:
        //      aHeartLaneB (<--), aWaterLaneB (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aHeartLaneD
        //
        for (;;) {
            //
            aIngress = aHeartLaneC[aIndex] ^ aHeartLaneA[aIndex];
            aIngress ^= aWoodLaneB[aIndex] ^ aWindLaneB[aIndex];
            //
            aCross = aHeartLaneB[aIndex] ^ aWaterLaneB[aIndex];
            aCross ^= aWindLaneA[aIndex];
            //
            aHeartLaneD[aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_E twist_loop_e (end)

}

void TwistExpander_Achernar_Arx::GROW_A() {


    // GROW_A grow_key_a (start)
    {
        //
        // grow_key_a loop 1
        //
        // Ingress:
        //      aHeartLaneA (-->), aHeartLaneB (-->), aFireLaneD (-->), aWindLaneA (<-?->)
        //
        // Cross:
        //      aHeartLaneC (<--), aHeartLaneD (<--), aSpiritLaneB (<--), aFireLaneC (<-?->)
        //
        // Destination:
        //      aIceLaneA
        //
        for (;;) {
            //
            aIngress = aHeartLaneA[aIndex] ^ aHeartLaneB[aIndex];
            aIngress ^= aFireLaneD[aIndex] ^ aWindLaneA[aIndex];
            //
            aCross = aHeartLaneC[aIndex] ^ aHeartLaneD[aIndex];
            aCross ^= aSpiritLaneB[aIndex] ^ aFireLaneC[aIndex];
            //
            aIceLaneA[aIndex] = aIngress;
        }
    
        //
        // grow_key_a loop 2
        //
        // Ingress:
        //      aIceLaneA (-->), aHeartLaneC (-->), aEarthLaneD (-->), aSpiritLaneA (<-?->)
        //
        // Cross:
        //      aHeartLaneA (<--), aHeartLaneD (<--), aPoisonLaneA (<--), aWindLaneB (<-?->)
        //
        // Destination:
        //      aIceLaneB
        //
        for (;;) {
            //
            aIngress = aIceLaneA[aIndex] ^ aHeartLaneC[aIndex];
            aIngress ^= aEarthLaneD[aIndex] ^ aSpiritLaneA[aIndex];
            //
            aCross = aHeartLaneA[aIndex] ^ aHeartLaneD[aIndex];
            aCross ^= aPoisonLaneA[aIndex] ^ aWindLaneB[aIndex];
            //
            aIceLaneB[aIndex] = aIngress;
        }
    
        //
        // grow_key_a loop 3
        //
        // Ingress:
        //      aIceLaneB (-->), aHeartLaneD (-->), aSpiritLaneC (-->), aPoisonLaneB (<-?->)
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
            aIngress ^= aSpiritLaneC[aIndex] ^ aPoisonLaneB[aIndex];
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
        //      aIceLaneC (-->), aIceLaneA (-->), aPoisonLaneC (-->), aWaterLaneB (<-?->)
        //
        // Cross:
        //      aIceLaneB (<--), aHeartLaneC (<--), aEarthLaneC (<--), aSpiritLaneD (<-?->)
        //
        // Destination:
        //      aIceLaneD
        //
        for (;;) {
            //
            aIngress = aIceLaneC[aIndex] ^ aIceLaneA[aIndex];
            aIngress ^= aPoisonLaneC[aIndex] ^ aWaterLaneB[aIndex];
            //
            aCross = aIceLaneB[aIndex] ^ aHeartLaneC[aIndex];
            aCross ^= aEarthLaneC[aIndex] ^ aSpiritLaneD[aIndex];
            //
            aIceLaneD[aIndex] = aIngress;
        }
    }
    // GROW_A grow_key_a (end)

}

void TwistExpander_Achernar_Arx::GROW_B() {


    // GROW_B grow_key_b (start)
    {
        //
        // grow_key_b loop 1
        //
        // Ingress:
        //      aIceLaneA (-->), aIceLaneB (-->), aHeartLaneD (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aIceLaneC (<--), aIceLaneD (<--), aWaterLaneC (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aSpiritLaneA
        //
        for (;;) {
            //
            aIngress = aIceLaneA[aIndex] ^ aIceLaneB[aIndex];
            aIngress ^= aHeartLaneD[aIndex] ^ aEarthLaneA[aIndex];
            //
            aCross = aIceLaneC[aIndex] ^ aIceLaneD[aIndex];
            aCross ^= aWaterLaneC[aIndex] ^ aEarthLaneB[aIndex];
            //
            aSpiritLaneA[aIndex] = aIngress;
        }
    
        //
        // grow_key_b loop 2
        //
        // Ingress:
        //      aSpiritLaneA (-->), aIceLaneC (-->), aWoodLaneA (-->), aHeartLaneB (<-?->)
        //
        // Cross:
        //      aIceLaneA (<--), aIceLaneD (<--), aKeyRowReadB (<--), aWindLaneD (<-?->)
        //
        // Destination:
        //      aSpiritLaneB
        //
        for (;;) {
            //
            aIngress = aSpiritLaneA[aIndex] ^ aIceLaneC[aIndex];
            aIngress ^= aWoodLaneA[aIndex] ^ aHeartLaneB[aIndex];
            //
            aCross = aIceLaneA[aIndex] ^ aIceLaneD[aIndex];
            aCross ^= aKeyRowReadB[W_KEY1 - aIndex] ^ aWindLaneD[aIndex];
            //
            aSpiritLaneB[aIndex] = aIngress;
        }
    
        //
        // grow_key_b loop 3
        //
        // Ingress:
        //      aSpiritLaneB (-->), aIceLaneD (-->), aWoodLaneB (-->), aWaterLaneD (<-?->)
        //
        // Cross:
        //      aSpiritLaneA (<--), aIceLaneB (<--), aFireLaneB (<--), aKeyRowReadA (<-?->)
        //
        // Destination:
        //      aSpiritLaneC
        //
        for (;;) {
            //
            aIngress = aSpiritLaneB[aIndex] ^ aIceLaneD[aIndex];
            aIngress ^= aWoodLaneB[aIndex] ^ aWaterLaneD[aIndex];
            //
            aCross = aSpiritLaneA[aIndex] ^ aIceLaneB[aIndex];
            aCross ^= aFireLaneB[aIndex] ^ aKeyRowReadA[aIndex];
            //
            aSpiritLaneC[aIndex] = aIngress;
        }
    
        //
        // grow_key_b loop 4
        //
        // Ingress:
        //      aSpiritLaneC (-->), aSpiritLaneA (-->), aWindLaneC (-->), aFireLaneA (<-?->)
        //
        // Cross:
        //      aSpiritLaneB (<--), aIceLaneC (<--), aHeartLaneA (<--), aHeartLaneC (<-?->)
        //
        // Destination:
        //      aSpiritLaneD
        //
        for (;;) {
            //
            aIngress = aSpiritLaneC[aIndex] ^ aSpiritLaneA[aIndex];
            aIngress ^= aWindLaneC[aIndex] ^ aFireLaneA[aIndex];
            //
            aCross = aSpiritLaneB[aIndex] ^ aIceLaneC[aIndex];
            aCross ^= aHeartLaneA[aIndex] ^ aHeartLaneC[aIndex];
            //
            aSpiritLaneD[aIndex] = aIngress;
        }
    }
    // GROW_B grow_key_b (end)

}
