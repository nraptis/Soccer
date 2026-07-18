#include "TwistExpander_Vega_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Vega_Arx::KDF_A_A() {
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = RotL64(aSource[((aIndex + 3687U)) & S_BLOCK1], 57U) ^ RotL64(pSnow[((aIndex + 4243U)) & S_BLOCK1], 42U);

            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 2997U)) & S_BLOCK1], 52U) ^ RotL64(aSource[((S_BLOCK1 - aIndex + 2643U)) & S_BLOCK1], 37U);

            aScrapLaneA[aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = RotL64(aScrapLaneA[((aIndex + 7439U)) & S_BLOCK1], 11U) ^ RotL64(aSource[((aIndex + 10089U)) & S_BLOCK1], 54U);

            //
            aCross = RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 8052U)) & S_BLOCK1], 30U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 6103U)) & S_BLOCK1], 13U);

            aScrapLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = RotL64(aScrapLaneB[((aIndex + 15912U)) & S_BLOCK1], 40U) ^ RotL64(aSource[((aIndex + 15124U)) & S_BLOCK1], 51U);

            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 12623U)) & S_BLOCK1], 28U) ^ RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 11754U)) & S_BLOCK1], 5U);

            aEarthLaneA[aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = RotL64(aEarthLaneA[((aIndex + 19199U)) & S_BLOCK1], 40U) ^ RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 20612U)) & S_BLOCK1], 21U);

            //
            aCross = RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 18091U)) & S_BLOCK1], 39U) ^ RotL64(aSource[((S_BLOCK1 - aIndex + 21223U)) & S_BLOCK1], 48U);

            aEarthLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = RotL64(aEarthLaneB[((aIndex + 23481U)) & S_BLOCK1], 11U) ^ RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 24611U)) & S_BLOCK1], 24U);

            //
            aCross = RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 22477U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((aIndex + 23244U)) & S_BLOCK1], 38U);

            aEarthLaneC[aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = RotL64(aEarthLaneC[((aIndex + 31101U)) & S_BLOCK1], 51U) ^ RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 31475U)) & S_BLOCK1], 34U);

            //
            aCross = RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 27337U)) & S_BLOCK1], 11U) ^ RotL64(aScrapLaneA[((aIndex + 32021U)) & S_BLOCK1], 42U);

            aEarthLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_A kdf_a_loop_a (end)
    
}

void TwistExpander_Vega_Arx::KDF_A_B() {
    // [kdf-a arx]
    // GSeedRunKDF_A_B kdf_a_loop_b (start)
    {
        //
        // kdf_a_loop_b loop 1
        //
        // Ingress:
        //      aEarthLaneA (-->), aEarthLaneB (-->), aSource (<-?->)
        //
        // Cross:
        //      aEarthLaneC (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aFireLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneA[((aIndex + 4177U)) & S_BLOCK1], 30U) ^ RotL64(aEarthLaneB[((aIndex + 2997U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aSource[((aIndex + 7555U)) & S_BLOCK1], 51U);

            //
            aCross = RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 2140U)) & S_BLOCK1], 58U) ^ RotL64(aEarthLaneD[((aIndex + 239U)) & S_BLOCK1], 47U);

            aFireLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_b loop 2
        //
        // Ingress:
        //      aFireLaneA (-->), aEarthLaneC (-->), aScrapLaneB (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aEarthLaneD (<--)
        //
        // Destination:
        //      aFireLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFireLaneA[((aIndex + 8436U)) & S_BLOCK1], 21U) ^ RotL64(aEarthLaneC[((aIndex + 9394U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aScrapLaneB[((aIndex + 14164U)) & S_BLOCK1], 5U);

            //
            aCross = RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 10870U)) & S_BLOCK1], 37U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 14542U)) & S_BLOCK1], 10U);

            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFireLaneB[((aIndex + 18346U)) & S_BLOCK1], 20U) ^ RotL64(aEarthLaneD[((aIndex + 19685U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 22073U)) & S_BLOCK1], 5U);

            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24247U)) & S_BLOCK1], 41U) ^ RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 23236U)) & S_BLOCK1], 13U);

            aFireLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_b loop 4
        //
        // Ingress:
        //      aFireLaneC (-->), aFireLaneA (-->), pSnow (<-?->)
        //
        // Cross:
        //      aFireLaneB (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aFireLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFireLaneC[((aIndex + 30033U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneA[((aIndex + 30518U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(pSnow[((aIndex + 31711U)) & S_BLOCK1], 11U);

            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29408U)) & S_BLOCK1], 3U) ^ RotL64(aEarthLaneC[((aIndex + 29443U)) & S_BLOCK1], 58U);

            aFireLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_B kdf_a_loop_b (end)
    
}

void TwistExpander_Vega_Arx::KDF_A_C() {
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
        //      aFireLaneC (<--), aFireLaneD (<--), aScrapLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFireLaneA[((aIndex + 1224U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneB[((aIndex + 2291U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 2555U)) & S_BLOCK1], 30U);

            //
            aCross = (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 686U)) & S_BLOCK1], 52U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 7652U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 3365U)) & S_BLOCK1], 21U);

            aOperationLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_c loop 2
        //
        // Ingress:
        //      aOperationLaneA (-->), aFireLaneC (-->), pSnow (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), aScrapLaneB (<-?->)
        //
        // Destination:
        //      aOperationLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8813U)) & S_BLOCK1], 54U) ^ RotL64(aFireLaneC[((aIndex + 13818U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(pSnow[((aIndex + 10231U)) & S_BLOCK1], 39U);

            //
            aCross = (RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13804U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 15891U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 12270U)) & S_BLOCK1], 23U);

            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_c loop 3
        //
        // Ingress:
        //      aOperationLaneB (-->), aFireLaneD (-->), aEarthLaneC (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aFireLaneB (<--), aSource (<-?->)
        //
        // Destination:
        //      aOperationLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 19863U)) & S_BLOCK1], 40U) ^ RotL64(aFireLaneD[((aIndex + 19984U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aEarthLaneC[((aIndex + 24260U)) & S_BLOCK1], 3U);

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17260U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 24004U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aSource[((aIndex + 19364U)) & S_BLOCK1], 29U);

            aOperationLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_c loop 4
        //
        // Ingress:
        //      aOperationLaneC (-->), aOperationLaneA (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aOperationLaneB (<--), aFireLaneC (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30206U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 28992U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 30711U)) & S_BLOCK1], 27U);

            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32705U)) & S_BLOCK1], 40U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26627U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aEarthLaneA[((aIndex + 28606U)) & S_BLOCK1], 29U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_C kdf_a_loop_c (end)
    
}

void TwistExpander_Vega_Arx::KDF_A_D() {
    // [kdf-a arx]
    // GSeedRunKDF_A_D kdf_a_loop_d (start)
    {
        //
        // kdf_a_loop_d loop 1
        //
        // Ingress:
        //      aOperationLaneA (-->), aOperationLaneB (-->), aScrapLaneB (-->), aFireLaneB (<-?->)
        //
        // Cross:
        //      aOperationLaneC (<--), aOperationLaneD (<--), pSnow (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5403U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((aIndex + 614U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aScrapLaneB[((aIndex + 2676U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((aIndex + 1808U)) & S_BLOCK1], 24U));

            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2968U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4006U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(pSnow[((aIndex + 7426U)) & S_BLOCK1], 5U);

            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_d loop 2
        //
        // Ingress:
        //      aFuseLaneA (-->), aOperationLaneC (-->), aScrapLaneA (-->), aEarthLaneC (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aOperationLaneD (<--), aFireLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneA[((aIndex + 15467U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 13905U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aScrapLaneA[((aIndex + 8743U)) & S_BLOCK1], 28U) ^ RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 11500U)) & S_BLOCK1], 3U));

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9471U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10547U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 9519U)) & S_BLOCK1], 3U);

            aFuseLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_d loop 3
        //
        // Ingress:
        //      aFuseLaneB (-->), aOperationLaneD (-->), aEarthLaneB (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aOperationLaneB (<--), aFireLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneB[((aIndex + 23920U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((aIndex + 23929U)) & S_BLOCK1], 4U));
            aIngress ^= (RotL64(aEarthLaneB[((aIndex + 19092U)) & S_BLOCK1], 57U) ^ RotL64(aEarthLaneD[((aIndex + 17468U)) & S_BLOCK1], 13U));

            //
            aCross = (RotL64(aFuseLaneA[((S_BLOCK1 - aIndex + 16780U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22463U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 18516U)) & S_BLOCK1], 23U);

            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_d loop 4
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aFireLaneA (-->), aSource (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aOperationLaneC (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 29901U)) & S_BLOCK1], 19U) ^ RotL64(aFuseLaneA[((aIndex + 32035U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 27499U)) & S_BLOCK1], 29U) ^ RotL64(aSource[((S_BLOCK1 - aIndex + 27444U)) & S_BLOCK1], 5U));

            //
            aCross = (RotL64(aFuseLaneB[((S_BLOCK1 - aIndex + 25269U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 25299U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 31183U)) & S_BLOCK1], 23U);

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_D kdf_a_loop_d (end)
    
}

void TwistExpander_Vega_Arx::KDF_A_E() {
    // [kdf-a arx]
    // GSeedRunKDF_A_E kdf_a_loop_e (start)
    {
        //
        // kdf_a_loop_e loop 1
        //
        // Ingress:
        //      aWindLaneA (-->), aWindLaneB (-->), aFireLaneB (-->), aOperationLaneB (<-?->)
        //
        // Cross:
        //      aWindLaneC (<--), aWindLaneD (<--), aEarthLaneA (<--), aFireLaneA (<-?->)
        //
        // Destination:
        //      aWaterLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWindLaneA[((aIndex + 902U)) & S_BLOCK1], 12U) ^ RotL64(aWindLaneB[((aIndex + 1336U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aFireLaneB[((aIndex + 7629U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2627U)) & S_BLOCK1], 21U));

            //
            aCross = (RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 3586U)) & S_BLOCK1], 27U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 2736U)) & S_BLOCK1], 40U));
            aCross ^= (RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 5808U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3582U)) & S_BLOCK1], 3U));

            aWaterLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_e loop 2
        //
        // Ingress:
        //      aWaterLaneA (-->), aWindLaneC (-->), pSnow (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aWindLaneD (<--), aEarthLaneC (<--), aSource (<-?->)
        //
        // Destination:
        //      aWaterLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneA[((aIndex + 11185U)) & S_BLOCK1], 38U) ^ RotL64(aWindLaneC[((aIndex + 13212U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(pSnow[((aIndex + 16278U)) & S_BLOCK1], 51U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 10025U)) & S_BLOCK1], 29U));

            //
            aCross = (RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 12830U)) & S_BLOCK1], 41U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 14468U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 9773U)) & S_BLOCK1], 13U) ^ RotL64(aSource[((aIndex + 8767U)) & S_BLOCK1], 28U));

            aWaterLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_e loop 3
        //
        // Ingress:
        //      aWaterLaneB (-->), aWindLaneD (-->), aOperationLaneC (-->), aFireLaneD (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWindLaneB (<--), aOperationLaneA (<-?->)
        //
        // Destination:
        //      aWaterLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneB[((aIndex + 17937U)) & S_BLOCK1], 27U) ^ RotL64(aWindLaneD[((aIndex + 16832U)) & S_BLOCK1], 12U));
            aIngress ^= (RotL64(aOperationLaneC[((aIndex + 22578U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 20691U)) & S_BLOCK1], 3U));

            //
            aCross = (RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 23052U)) & S_BLOCK1], 35U) ^ RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 21505U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24439U)) & S_BLOCK1], 21U);

            aWaterLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_e loop 4
        //
        // Ingress:
        //      aWaterLaneC (-->), aWaterLaneA (-->), aFireLaneC (-->), aEarthLaneB (<-?->)
        //
        // Cross:
        //      aWaterLaneB (<--), aWindLaneC (<--), aOperationLaneD (<-?->)
        //
        // Destination:
        //      aWaterLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneC[((aIndex + 27601U)) & S_BLOCK1], 29U) ^ RotL64(aWaterLaneA[((aIndex + 31936U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aFireLaneC[((aIndex + 31450U)) & S_BLOCK1], 53U) ^ RotL64(aEarthLaneB[((aIndex + 29537U)) & S_BLOCK1], 4U));

            //
            aCross = (RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 29424U)) & S_BLOCK1], 48U) ^ RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 25443U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27422U)) & S_BLOCK1], 11U);

            aWaterLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_E kdf_a_loop_e (end)
    
}

void TwistExpander_Vega_Arx::KDF_B_A() {
    // [kdf-a arx]
    // GSeedRunKDF_B_A kdf_b_loop_a (start)
    {
        //
        // kdf_b_loop_a loop 1
        //
        // Ingress:
        //      aWaterLaneA (-->), aWaterLaneB (-->), aOperationLaneA (-->), aOperationLaneD (<-?->)
        //
        // Cross:
        //      aWaterLaneC (<--), aWaterLaneD (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aScrapLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneA[((aIndex + 4628U)) & S_BLOCK1], 13U) ^ RotL64(aWaterLaneB[((aIndex + 5961U)) & S_BLOCK1], 50U));
            aIngress ^= (RotL64(aOperationLaneA[((aIndex + 7921U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((aIndex + 2834U)) & S_BLOCK1], 5U));

            //
            aCross = (RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 2878U)) & S_BLOCK1], 44U) ^ RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 3834U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWindLaneA[((aIndex + 2306U)) & S_BLOCK1], 27U);

            aScrapLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_a loop 2
        //
        // Ingress:
        //      aScrapLaneA (-->), aWaterLaneC (-->), aOperationLaneB (-->), aWindLaneD (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWaterLaneD (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aScrapLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneA[((aIndex + 10388U)) & S_BLOCK1], 3U) ^ RotL64(aWaterLaneC[((aIndex + 12640U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 11103U)) & S_BLOCK1], 23U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 13711U)) & S_BLOCK1], 36U));

            //
            aCross = (RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 15604U)) & S_BLOCK1], 37U) ^ RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 10995U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 15797U)) & S_BLOCK1], 11U);

            aScrapLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_a loop 3
        //
        // Ingress:
        //      aScrapLaneB (-->), aWaterLaneD (-->), aFireLaneD (-->), aFireLaneB (<-?->)
        //
        // Cross:
        //      aScrapLaneA (<--), aWaterLaneB (<--), aSource (<-?->)
        //
        // Destination:
        //      aScrapLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneB[((aIndex + 22548U)) & S_BLOCK1], 37U) ^ RotL64(aWaterLaneD[((aIndex + 18213U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 22270U)) & S_BLOCK1], 46U) ^ RotL64(aFireLaneB[((aIndex + 22133U)) & S_BLOCK1], 19U));

            //
            aCross = (RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 18229U)) & S_BLOCK1], 39U) ^ RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 17434U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aSource[((S_BLOCK1 - aIndex + 21380U)) & S_BLOCK1], 48U);

            aScrapLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_a loop 4
        //
        // Ingress:
        //      aScrapLaneC (-->), aScrapLaneA (-->), aWindLaneB (-->), aOperationLaneC (<-?->)
        //
        // Cross:
        //      aScrapLaneB (<--), aWaterLaneC (<--), aFireLaneC (<-?->)
        //
        // Destination:
        //      aScrapLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneC[((aIndex + 25751U)) & S_BLOCK1], 35U) ^ RotL64(aScrapLaneA[((aIndex + 25977U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aWindLaneB[((aIndex + 28462U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 25357U)) & S_BLOCK1], 51U));

            //
            aCross = (RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 28602U)) & S_BLOCK1], 29U) ^ RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 26592U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 31780U)) & S_BLOCK1], 3U);

            aScrapLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_A kdf_b_loop_a (end)
    
}

void TwistExpander_Vega_Arx::KDF_B_B() {
    // [kdf-a arx]
    // GSeedRunKDF_B_B kdf_b_loop_b (start)
    {
        //
        // kdf_b_loop_b loop 1
        //
        // Ingress:
        //      aScrapLaneA (-->), aScrapLaneB (-->), aEarthLaneC (-->), aEarthLaneB (<-?->)
        //
        // Cross:
        //      aScrapLaneC (<--), aScrapLaneD (<--), aSource (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aOperationLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneA[((aIndex + 2629U)) & S_BLOCK1], 27U) ^ RotL64(aScrapLaneB[((aIndex + 1683U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aEarthLaneC[((aIndex + 3832U)) & S_BLOCK1], 39U) ^ RotL64(aEarthLaneB[((aIndex + 5752U)) & S_BLOCK1], 3U));

            //
            aCross = (RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 2757U)) & S_BLOCK1], 58U) ^ RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 4582U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aSource[((S_BLOCK1 - aIndex + 1288U)) & S_BLOCK1], 35U) ^ RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 4662U)) & S_BLOCK1], 5U));

            aOperationLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_b loop 2
        //
        // Ingress:
        //      aOperationLaneA (-->), aScrapLaneC (-->), aWaterLaneA (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aScrapLaneA (<--), aScrapLaneD (<--), aWindLaneA (<--), aWindLaneB (<-?->)
        //
        // Destination:
        //      aOperationLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 14782U)) & S_BLOCK1], 52U) ^ RotL64(aScrapLaneC[((aIndex + 11235U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aWaterLaneA[((aIndex + 14031U)) & S_BLOCK1], 35U) ^ RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 10901U)) & S_BLOCK1], 19U));

            //
            aCross = (RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 14114U)) & S_BLOCK1], 39U) ^ RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 11265U)) & S_BLOCK1], 51U));
            aCross ^= (RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 10833U)) & S_BLOCK1], 3U) ^ RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 12457U)) & S_BLOCK1], 12U));

            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_b loop 3
        //
        // Ingress:
        //      aOperationLaneB (-->), aScrapLaneD (-->), aEarthLaneD (-->), aFireLaneA (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aScrapLaneB (<--), aWaterLaneB (<-?->)
        //
        // Destination:
        //      aOperationLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 21148U)) & S_BLOCK1], 57U) ^ RotL64(aScrapLaneD[((aIndex + 19197U)) & S_BLOCK1], 40U));
            aIngress ^= (RotL64(aEarthLaneD[((aIndex + 17508U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneA[((aIndex + 21788U)) & S_BLOCK1], 29U));

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24233U)) & S_BLOCK1], 3U) ^ RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 20578U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 16734U)) & S_BLOCK1], 43U);

            aOperationLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_b loop 4
        //
        // Ingress:
        //      aOperationLaneC (-->), aOperationLaneA (-->), aWindLaneD (-->), aWaterLaneC (<-?->)
        //
        // Cross:
        //      aOperationLaneB (<--), aScrapLaneC (<--), aWaterLaneD (<-?->)
        //
        // Destination:
        //      aOperationLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29261U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 29707U)) & S_BLOCK1], 4U));
            aIngress ^= (RotL64(aWindLaneD[((aIndex + 27309U)) & S_BLOCK1], 39U) ^ RotL64(aWaterLaneC[((aIndex + 32710U)) & S_BLOCK1], 29U));

            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29747U)) & S_BLOCK1], 19U) ^ RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 30961U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWaterLaneD[((aIndex + 32132U)) & S_BLOCK1], 39U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_B kdf_b_loop_b (end)
    
}

void TwistExpander_Vega_Arx::KDF_B_C() {
    // [kdf-a arx]
    // GSeedRunKDF_B_C kdf_b_loop_c (start)
    {
        //
        // kdf_b_loop_c loop 1
        //
        // Ingress:
        //      aOperationLaneA (-->), aOperationLaneB (-->), aWaterLaneD (-->), aScrapLaneB (<-?->)
        //
        // Cross:
        //      aOperationLaneC (<--), aOperationLaneD (<--), aScrapLaneA (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5523U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 1367U)) & S_BLOCK1], 54U));
            aIngress ^= (RotL64(aWaterLaneD[((aIndex + 4758U)) & S_BLOCK1], 21U) ^ RotL64(aScrapLaneB[((aIndex + 4044U)) & S_BLOCK1], 13U));

            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1555U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7766U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 762U)) & S_BLOCK1], 57U) ^ RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 7296U)) & S_BLOCK1], 21U));

            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_c loop 2
        //
        // Ingress:
        //      aFuseLaneA (-->), aOperationLaneC (-->), aWindLaneC (-->), aWaterLaneB (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aOperationLaneD (<--), aScrapLaneC (<--), aScrapLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneA[((aIndex + 14245U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 12402U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aWindLaneC[((aIndex + 15848U)) & S_BLOCK1], 48U) ^ RotL64(aWaterLaneB[((aIndex + 9147U)) & S_BLOCK1], 11U));

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14940U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14513U)) & S_BLOCK1], 58U));
            aCross ^= (RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 9283U)) & S_BLOCK1], 19U) ^ RotL64(aScrapLaneD[((aIndex + 11160U)) & S_BLOCK1], 39U));

            aFuseLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_c loop 3
        //
        // Ingress:
        //      aFuseLaneB (-->), aOperationLaneD (-->), aFireLaneA (-->), aWindLaneD (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aOperationLaneB (<--), aFireLaneC (<--), aWaterLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneB[((aIndex + 20477U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((aIndex + 20544U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 24072U)) & S_BLOCK1], 41U) ^ RotL64(aWindLaneD[((aIndex + 22330U)) & S_BLOCK1], 30U));

            //
            aCross = (RotL64(aFuseLaneA[((S_BLOCK1 - aIndex + 18578U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22148U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 18716U)) & S_BLOCK1], 48U) ^ RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 21664U)) & S_BLOCK1], 37U));

            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_c loop 4
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aFireLaneB (-->), aWaterLaneA (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aOperationLaneC (<--), aWindLaneB (<--), aFireLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 29384U)) & S_BLOCK1], 3U) ^ RotL64(aFuseLaneA[((aIndex + 26593U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aFireLaneB[((aIndex + 24698U)) & S_BLOCK1], 58U) ^ RotL64(aWaterLaneA[((aIndex + 31768U)) & S_BLOCK1], 13U));

            //
            aCross = (RotL64(aFuseLaneB[((S_BLOCK1 - aIndex + 26788U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 25825U)) & S_BLOCK1], 26U));
            aCross ^= (RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 26341U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((aIndex + 25610U)) & S_BLOCK1], 39U));

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_C kdf_b_loop_c (end)
    
}

void TwistExpander_Vega_Arx::KDF_B_D() {
    // [kdf-a arx]
    // GSeedRunKDF_B_D kdf_b_loop_d (start)
    {
        //
        // kdf_b_loop_d loop 1
        //
        // Ingress:
        //      aWorkLaneA (-->), aWorkLaneB (-->), aWindLaneB (-->), aScrapLaneA (<-?->)
        //
        // Cross:
        //      aWorkLaneC (<--), aWorkLaneD (<--), aOperationLaneB (<--), aWindLaneD (<-?->)
        //
        // Destination:
        //      aExpandLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1881U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 5756U)) & S_BLOCK1], 22U));
            aIngress ^= (RotL64(aWindLaneB[((aIndex + 345U)) & S_BLOCK1], 47U) ^ RotL64(aScrapLaneA[((aIndex + 4484U)) & S_BLOCK1], 13U));

            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4417U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 58U)) & S_BLOCK1], 23U));
            aCross ^= (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2433U)) & S_BLOCK1], 38U) ^ RotL64(aWindLaneD[((aIndex + 376U)) & S_BLOCK1], 13U));

            aExpandLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_d loop 2
        //
        // Ingress:
        //      aExpandLaneA (-->), aWorkLaneC (-->), aOperationLaneD (-->), aWaterLaneB (<-?->)
        //
        // Cross:
        //      aWorkLaneA (<--), aWorkLaneD (<--), aOperationLaneA (<--), aScrapLaneC (<-?->)
        //
        // Destination:
        //      aExpandLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 14607U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((aIndex + 14827U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 13634U)) & S_BLOCK1], 41U) ^ RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 14731U)) & S_BLOCK1], 18U));

            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13796U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8820U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12736U)) & S_BLOCK1], 27U) ^ RotL64(aScrapLaneC[((aIndex + 15719U)) & S_BLOCK1], 53U));

            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_d loop 3
        //
        // Ingress:
        //      aExpandLaneB (-->), aWorkLaneD (-->), aWaterLaneA (-->), aWaterLaneD (<-?->)
        //
        // Cross:
        //      aExpandLaneA (<--), aWorkLaneB (<--), aWaterLaneC (<--), aOperationLaneC (<-?->)
        //
        // Destination:
        //      aExpandLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21577U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((aIndex + 24203U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aWaterLaneA[((aIndex + 19570U)) & S_BLOCK1], 35U) ^ RotL64(aWaterLaneD[((aIndex + 22866U)) & S_BLOCK1], 18U));

            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22747U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23711U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 16594U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24427U)) & S_BLOCK1], 13U));

            aExpandLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_d loop 4
        //
        // Ingress:
        //      aExpandLaneC (-->), aExpandLaneA (-->), aWindLaneC (-->), aScrapLaneD (<-?->)
        //
        // Cross:
        //      aExpandLaneB (<--), aWorkLaneC (<--), aScrapLaneB (<--), aSource (<-?->)
        //
        // Destination:
        //      aExpandLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30756U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 25704U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aWindLaneC[((aIndex + 29762U)) & S_BLOCK1], 21U) ^ RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 27443U)) & S_BLOCK1], 34U));

            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25347U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27129U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 29312U)) & S_BLOCK1], 27U) ^ RotL64(aSource[((aIndex + 31359U)) & S_BLOCK1], 52U));

            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_D kdf_b_loop_d (end)
    
}

void TwistExpander_Vega_Arx::Seed_A() {
    const std::uint64_t &aPhaseADomainWordIngress = pWorkSpace->mDomainBundle.mPhaseAConstants.mIngress;
    const std::uint64_t &aPhaseADomainWordScatter = pWorkSpace->mDomainBundle.mPhaseAConstants.mScatter;
    const std::uint64_t &aPhaseADomainWordCross = pWorkSpace->mDomainBundle.mPhaseAConstants.mCross;
    const std::uint64_t &aPhaseCDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseCConstants.mIngress;
    const std::uint64_t &aPhaseCDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseCConstants.mScatter;
    const std::uint64_t &aPhaseCDomainWordCross = pWorkSpace->mDomainBundle.mPhaseCConstants.mCross;
    const std::uint64_t &aPhaseDDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseDConstants.mIngress;
    const std::uint64_t &aPhaseDDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseDConstants.mScatter;
    const std::uint64_t &aPhaseDDomainWordCross = pWorkSpace->mDomainBundle.mPhaseDConstants.mCross;
    const std::uint64_t &aPhaseFDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseFConstants.mIngress;
    const std::uint64_t &aPhaseFDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseFConstants.mScatter;
    const std::uint64_t &aPhaseFDomainWordCross = pWorkSpace->mDomainBundle.mPhaseFConstants.mCross;
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = RotL64(aSource[((aIndex + 4404U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 2672U)) & W_KEY1], 56U);

            //
            aCross = RotL64(aSource[((S_BLOCK1 - aIndex + 2960U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 3969U)) & W_KEY1], 27U);

            aWorkLaneA[aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = RotL64(aWorkLaneA[((aIndex + 7250U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadB[((aIndex + 6585U)) & W_KEY1], 36U);

            //
            aCross = RotL64(aSource[((S_BLOCK1 - aIndex + 8548U)) & S_BLOCK1], 54U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 8256U)) & W_KEY1], 11U);

            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 11268U)) & S_BLOCK1], 3U) ^ RotL64(aSource[((aIndex + 11384U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aKeyRowReadB[((aIndex + 14902U)) & W_KEY1], 46U);

            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 14805U)) & W_KEY1], 20U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13788U)) & S_BLOCK1], 41U);

            aExpandLaneA[aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = RotL64(aExpandLaneA[((aIndex + 20624U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 20555U)) & S_BLOCK1], 27U);

            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19717U)) & S_BLOCK1], 24U) ^ RotL64(aKeyRowReadB[((aIndex + 20749U)) & W_KEY1], 13U);

            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = RotL64(aExpandLaneB[((aIndex + 23978U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 23271U)) & S_BLOCK1], 52U);

            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26881U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[((aIndex + 25689U)) & W_KEY1], 4U);

            aExpandLaneC[aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = RotL64(aExpandLaneC[((aIndex + 28393U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((aIndex + 31819U)) & S_BLOCK1], 37U);

            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28797U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((aIndex + 31691U)) & S_BLOCK1], 37U);

            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_A seed_loop_a (end)
    
}

void TwistExpander_Vega_Arx::Seed_B() {
    const std::uint64_t &aPhaseADomainWordIngress = pWorkSpace->mDomainBundle.mPhaseAConstants.mIngress;
    const std::uint64_t &aPhaseADomainWordScatter = pWorkSpace->mDomainBundle.mPhaseAConstants.mScatter;
    const std::uint64_t &aPhaseADomainWordCross = pWorkSpace->mDomainBundle.mPhaseAConstants.mCross;
    const std::uint64_t &aPhaseBDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseBConstants.mIngress;
    const std::uint64_t &aPhaseBDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseBConstants.mScatter;
    const std::uint64_t &aPhaseBDomainWordCross = pWorkSpace->mDomainBundle.mPhaseBConstants.mCross;
    const std::uint64_t &aPhaseDDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseDConstants.mIngress;
    const std::uint64_t &aPhaseDDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseDConstants.mScatter;
    const std::uint64_t &aPhaseDDomainWordCross = pWorkSpace->mDomainBundle.mPhaseDConstants.mCross;
    const std::uint64_t &aPhaseEDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseEConstants.mIngress;
    const std::uint64_t &aPhaseEDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseEConstants.mScatter;
    const std::uint64_t &aPhaseEDomainWordCross = pWorkSpace->mDomainBundle.mPhaseEConstants.mCross;
    // [seed arx]
    // GSeedRunSeed_B seed_loop_e (start)
    {
        //
        // seed_loop_e loop 1
        //
        // Ingress:
        //      aExpandLaneA (-->), aExpandLaneB (-->), aSource (<-?->)
        //
        // Cross:
        //      aExpandLaneC (<--), aExpandLaneD (<-?->)
        //
        // Destination:
        //      aWorkLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1093U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 564U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aSource[((aIndex + 4852U)) & S_BLOCK1], 23U);

            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 567U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((aIndex + 3701U)) & S_BLOCK1], 11U);

            aWorkLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 2
        //
        // Ingress:
        //      aWorkLaneC (-->), aExpandLaneC (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aExpandLaneA (<--), aExpandLaneD (<--)
        //
        // Destination:
        //      aWorkLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 6118U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 6790U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aKeyRowReadA[((aIndex + 7436U)) & W_KEY1], 23U);

            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10431U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7180U)) & S_BLOCK1], 3U);

            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 3
        //
        // Ingress:
        //      aWorkLaneD (-->), aExpandLaneA (-->), aKeyRowReadB (<-?->)
        //
        // Cross:
        //      aWorkLaneC (<--), aExpandLaneC (<-?->)
        //
        // Destination:
        //      aEarthLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneD[((aIndex + 14246U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 14680U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aKeyRowReadB[((aIndex + 15176U)) & W_KEY1], 40U);

            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14200U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11601U)) & S_BLOCK1], 37U);

            aEarthLaneA[aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneA[((aIndex + 20656U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 18878U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 20845U)) & S_BLOCK1], 19U);

            //
            aCross = RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21152U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20465U)) & S_BLOCK1], 51U);

            aEarthLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 5
        //
        // Ingress:
        //      aEarthLaneB (-->), aWorkLaneD (-->), aWorkLaneA (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aWorkLaneC (<-?->)
        //
        // Destination:
        //      aEarthLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneB[((aIndex + 27102U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneD[((aIndex + 25146U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25289U)) & S_BLOCK1], 57U);

            //
            aCross = RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 26083U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((aIndex + 25331U)) & S_BLOCK1], 11U);

            aEarthLaneC[aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = RotL64(aEarthLaneC[((aIndex + 30312U)) & S_BLOCK1], 21U) ^ RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 28913U)) & S_BLOCK1], 38U);

            //
            aCross = RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 32247U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30744U)) & S_BLOCK1], 57U);

            aEarthLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_B seed_loop_e (end)
    
}

void TwistExpander_Vega_Arx::Seed_C() {
    const std::uint64_t &aPhaseBDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseBConstants.mIngress;
    const std::uint64_t &aPhaseBDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseBConstants.mScatter;
    const std::uint64_t &aPhaseBDomainWordCross = pWorkSpace->mDomainBundle.mPhaseBConstants.mCross;
    const std::uint64_t &aPhaseCDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseCConstants.mIngress;
    const std::uint64_t &aPhaseCDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseCConstants.mScatter;
    const std::uint64_t &aPhaseCDomainWordCross = pWorkSpace->mDomainBundle.mPhaseCConstants.mCross;
    const std::uint64_t &aPhaseDDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseDConstants.mIngress;
    const std::uint64_t &aPhaseDDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseDConstants.mScatter;
    const std::uint64_t &aPhaseDDomainWordCross = pWorkSpace->mDomainBundle.mPhaseDConstants.mCross;
    const std::uint64_t &aPhaseFDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseFConstants.mIngress;
    const std::uint64_t &aPhaseFDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseFConstants.mScatter;
    const std::uint64_t &aPhaseFDomainWordCross = pWorkSpace->mDomainBundle.mPhaseFConstants.mCross;
    // [seed arx]
    // GSeedRunSeed_C seed_loop_d (start)
    {
        //
        // seed_loop_d loop 1
        //
        // Ingress:
        //      aEarthLaneA (-->), aEarthLaneB (-->), aWorkLaneB (<-?->)
        //
        // Cross:
        //      aEarthLaneC (<--), aEarthLaneD (<--), aExpandLaneA (<-?->)
        //
        // Destination:
        //      aScrapLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneA[((aIndex + 3742U)) & S_BLOCK1], 43U) ^ RotL64(aEarthLaneB[((aIndex + 4611U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 3014U)) & S_BLOCK1], 13U);

            //
            aCross = (RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 355U)) & S_BLOCK1], 35U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 1956U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5426U)) & S_BLOCK1], 51U);

            aScrapLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 2
        //
        // Ingress:
        //      aScrapLaneA (-->), aEarthLaneC (-->), aWorkLaneC (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aEarthLaneD (<--), aExpandLaneC (<-?->)
        //
        // Destination:
        //      aScrapLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneA[((aIndex + 9542U)) & S_BLOCK1], 37U) ^ RotL64(aEarthLaneC[((aIndex + 9951U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8261U)) & S_BLOCK1], 48U);

            //
            aCross = (RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 6347U)) & S_BLOCK1], 19U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 6358U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9010U)) & S_BLOCK1], 6U);

            aScrapLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneB[((aIndex + 15108U)) & S_BLOCK1], 26U) ^ RotL64(aEarthLaneA[((aIndex + 14616U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aSource[((S_BLOCK1 - aIndex + 11014U)) & S_BLOCK1], 43U);

            //
            aCross = (RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 16012U)) & S_BLOCK1], 3U) ^ RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 13115U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 11880U)) & S_BLOCK1], 43U);

            aOperationLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 4
        //
        // Ingress:
        //      aOperationLaneA (-->), aEarthLaneD (-->), aExpandLaneD (<-?->)
        //
        // Cross:
        //      aScrapLaneB (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20450U)) & S_BLOCK1], 47U) ^ RotL64(aEarthLaneD[((aIndex + 20809U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19947U)) & S_BLOCK1], 14U);

            //
            aCross = RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 18532U)) & S_BLOCK1], 60U) ^ RotL64(aEarthLaneA[((aIndex + 16531U)) & S_BLOCK1], 47U);

            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 5
        //
        // Ingress:
        //      aOperationLaneB (-->), aScrapLaneB (-->), aWorkLaneD (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aScrapLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24216U)) & S_BLOCK1], 6U) ^ RotL64(aScrapLaneB[((aIndex + 26470U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23660U)) & S_BLOCK1], 57U);

            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25206U)) & S_BLOCK1], 19U) ^ RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 27271U)) & S_BLOCK1], 4U);

            aOperationLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 6
        //
        // Ingress:
        //      aOperationLaneC (-->), aOperationLaneA (-->), aWorkLaneA (<-?->)
        //
        // Cross:
        //      aOperationLaneB (<--), aEarthLaneB (<--)
        //
        // Destination:
        //      aOperationLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28422U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 30899U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27851U)) & S_BLOCK1], 13U);

            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28899U)) & S_BLOCK1], 13U) ^ RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 31394U)) & S_BLOCK1], 46U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_C seed_loop_d (end)
    
}

void TwistExpander_Vega_Arx::Seed_D() {
    const std::uint64_t &aPhaseBDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseBConstants.mIngress;
    const std::uint64_t &aPhaseBDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseBConstants.mScatter;
    const std::uint64_t &aPhaseBDomainWordCross = pWorkSpace->mDomainBundle.mPhaseBConstants.mCross;
    const std::uint64_t &aPhaseDDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseDConstants.mIngress;
    const std::uint64_t &aPhaseDDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseDConstants.mScatter;
    const std::uint64_t &aPhaseDDomainWordCross = pWorkSpace->mDomainBundle.mPhaseDConstants.mCross;
    const std::uint64_t &aPhaseEDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseEConstants.mIngress;
    const std::uint64_t &aPhaseEDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseEConstants.mScatter;
    const std::uint64_t &aPhaseEDomainWordCross = pWorkSpace->mDomainBundle.mPhaseEConstants.mCross;
    // [seed arx]
    // GSeedRunSeed_D seed_loop_c (start)
    {
        //
        // seed_loop_c loop 1
        //
        // Ingress:
        //      aOperationLaneA (-->), aOperationLaneB (-->), aExpandLaneA (<-?->)
        //
        // Cross:
        //      aOperationLaneC (<--), aOperationLaneD (<--), aExpandLaneC (<-?->)
        //
        // Destination:
        //      aScrapLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3118U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 1572U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1933U)) & S_BLOCK1], 39U);

            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4362U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3051U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 1366U)) & S_BLOCK1], 58U);

            aScrapLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 2
        //
        // Ingress:
        //      aScrapLaneC (-->), aOperationLaneC (-->), aExpandLaneB (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aOperationLaneD (<--), aWorkLaneD (<-?->)
        //
        // Destination:
        //      aScrapLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneC[((aIndex + 10150U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 5811U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 6741U)) & S_BLOCK1], 11U);

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7740U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10545U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 8702U)) & S_BLOCK1], 51U);

            aScrapLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 3
        //
        // Ingress:
        //      aScrapLaneD (-->), aOperationLaneA (-->), aEarthLaneC (<-?->)
        //
        // Cross:
        //      aScrapLaneC (<--), aOperationLaneC (<--), aScrapLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneD[((aIndex + 13598U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 11833U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aEarthLaneC[((aIndex + 14376U)) & S_BLOCK1], 39U);

            //
            aCross = (RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 13941U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12858U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aScrapLaneB[((aIndex + 15943U)) & S_BLOCK1], 3U);

            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 4
        //
        // Ingress:
        //      aFuseLaneA (-->), aOperationLaneD (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aScrapLaneD (<--), aOperationLaneA (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneA[((aIndex + 17706U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((aIndex + 20638U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 21537U)) & S_BLOCK1], 19U);

            //
            aCross = (RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 17799U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17488U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 18408U)) & S_BLOCK1], 35U);

            aFuseLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 5
        //
        // Ingress:
        //      aFuseLaneB (-->), aScrapLaneD (-->), aEarthLaneB (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aScrapLaneC (<--), aKeyRowReadA (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneB[((aIndex + 25949U)) & S_BLOCK1], 14U) ^ RotL64(aScrapLaneD[((aIndex + 25557U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 25498U)) & S_BLOCK1], 57U);

            //
            aCross = (RotL64(aFuseLaneA[((S_BLOCK1 - aIndex + 24664U)) & S_BLOCK1], 27U) ^ RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 25922U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aKeyRowReadA[(((2047U - aIndex) + 22110U)) & W_KEY1], 60U);

            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 6
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aScrapLaneA (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aOperationLaneB (<--), aExpandLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 27515U)) & S_BLOCK1], 13U) ^ RotL64(aFuseLaneA[((aIndex + 30358U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aScrapLaneA[((aIndex + 27715U)) & S_BLOCK1], 47U);

            //
            aCross = (RotL64(aFuseLaneB[((S_BLOCK1 - aIndex + 31464U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30826U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29321U)) & S_BLOCK1], 27U);

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_D seed_loop_c (end)
    
}

void TwistExpander_Vega_Arx::Seed_E() {
    const std::uint64_t &aPhaseADomainWordIngress = pWorkSpace->mDomainBundle.mPhaseAConstants.mIngress;
    const std::uint64_t &aPhaseADomainWordScatter = pWorkSpace->mDomainBundle.mPhaseAConstants.mScatter;
    const std::uint64_t &aPhaseADomainWordCross = pWorkSpace->mDomainBundle.mPhaseAConstants.mCross;
    const std::uint64_t &aPhaseCDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseCConstants.mIngress;
    const std::uint64_t &aPhaseCDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseCConstants.mScatter;
    const std::uint64_t &aPhaseCDomainWordCross = pWorkSpace->mDomainBundle.mPhaseCConstants.mCross;
    const std::uint64_t &aPhaseFDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseFConstants.mIngress;
    const std::uint64_t &aPhaseFDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseFConstants.mScatter;
    const std::uint64_t &aPhaseFDomainWordCross = pWorkSpace->mDomainBundle.mPhaseFConstants.mCross;
    // [seed arx]
    // GSeedRunSeed_E seed_loop_b (start)
    {
        //
        // seed_loop_b loop 1
        //
        // Ingress:
        //      aFireLaneA (-->), aFireLaneB (-->), aEarthLaneB (-->), aOperationLaneB (<-?->)
        //
        // Cross:
        //      aFireLaneC (<--), aFireLaneD (<--), aOperationLaneC (<-?->)
        //
        // Destination:
        //      aWaterLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFireLaneA[((aIndex + 1100U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((aIndex + 106U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aEarthLaneB[((aIndex + 112U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 2345U)) & S_BLOCK1], 43U));

            //
            aCross = (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 3820U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 1782U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4109U)) & S_BLOCK1], 5U);

            aWaterLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_b loop 2
        //
        // Ingress:
        //      aWaterLaneC (-->), aFireLaneC (-->), aWorkLaneC (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), aScrapLaneA (<-?->)
        //
        // Destination:
        //      aWaterLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneC[((aIndex + 9697U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneC[((aIndex + 6805U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aWorkLaneC[((aIndex + 7242U)) & S_BLOCK1], 35U) ^ RotL64(aEarthLaneD[((aIndex + 7184U)) & S_BLOCK1], 47U));

            //
            aCross = (RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 9011U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6771U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 6950U)) & S_BLOCK1], 21U);

            aWaterLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_b loop 3
        //
        // Ingress:
        //      aWaterLaneD (-->), aFireLaneA (-->), aKeyRowReadB (<-?->)
        //
        // Cross:
        //      aWaterLaneC (<--), aFireLaneC (<--), aScrapLaneD (<-?->)
        //
        // Destination:
        //      aInvestLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneD[((aIndex + 11898U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneA[((aIndex + 12918U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aKeyRowReadB[(((2047U - aIndex) + 11683U)) & W_KEY1], 5U);

            //
            aCross = (RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 11898U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11013U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 11196U)) & S_BLOCK1], 29U);

            aInvestLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_b loop 4
        //
        // Ingress:
        //      aInvestLaneA (-->), aFireLaneD (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aWaterLaneD (<--), aFireLaneA (<--), aScrapLaneC (<-?->)
        //
        // Destination:
        //      aInvestLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 16948U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneD[((aIndex + 19572U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aEarthLaneA[((aIndex + 17707U)) & S_BLOCK1], 10U);

            //
            aCross = (RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 19061U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 20680U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aScrapLaneC[((aIndex + 20627U)) & S_BLOCK1], 6U);

            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_b loop 5
        //
        // Ingress:
        //      aInvestLaneB (-->), aWaterLaneD (-->), aScrapLaneB (<-?->)
        //
        // Cross:
        //      aInvestLaneA (<--), aWaterLaneC (<--), aOperationLaneD (<-?->)
        //
        // Destination:
        //      aInvestLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 23164U)) & S_BLOCK1], 5U) ^ RotL64(aWaterLaneD[((aIndex + 25518U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aScrapLaneB[((aIndex + 22364U)) & S_BLOCK1], 53U);

            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 27094U)) & S_BLOCK1], 34U) ^ RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 22239U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 23830U)) & S_BLOCK1], 51U);

            aInvestLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_b loop 6
        //
        // Ingress:
        //      aInvestLaneC (-->), aInvestLaneA (-->), aEarthLaneC (<-?->)
        //
        // Cross:
        //      aInvestLaneB (<--), aFireLaneB (<--), aOperationLaneA (<-?->)
        //
        // Destination:
        //      aInvestLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 30314U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneA[((aIndex + 29805U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aEarthLaneC[((aIndex + 30822U)) & S_BLOCK1], 11U);

            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29187U)) & S_BLOCK1], 58U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 30639U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 29397U)) & S_BLOCK1], 5U);

            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_E seed_loop_b (end)
    
}

void TwistExpander_Vega_Arx::Seed_F() {
    const std::uint64_t &aPhaseADomainWordIngress = pWorkSpace->mDomainBundle.mPhaseAConstants.mIngress;
    const std::uint64_t &aPhaseADomainWordScatter = pWorkSpace->mDomainBundle.mPhaseAConstants.mScatter;
    const std::uint64_t &aPhaseADomainWordCross = pWorkSpace->mDomainBundle.mPhaseAConstants.mCross;
    const std::uint64_t &aPhaseCDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseCConstants.mIngress;
    const std::uint64_t &aPhaseCDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseCConstants.mScatter;
    const std::uint64_t &aPhaseCDomainWordCross = pWorkSpace->mDomainBundle.mPhaseCConstants.mCross;
    const std::uint64_t &aPhaseEDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseEConstants.mIngress;
    const std::uint64_t &aPhaseEDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseEConstants.mScatter;
    const std::uint64_t &aPhaseEDomainWordCross = pWorkSpace->mDomainBundle.mPhaseEConstants.mCross;
    const std::uint64_t &aPhaseFDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseFConstants.mIngress;
    const std::uint64_t &aPhaseFDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseFConstants.mScatter;
    const std::uint64_t &aPhaseFDomainWordCross = pWorkSpace->mDomainBundle.mPhaseFConstants.mCross;
    // [seed arx]
    // GSeedRunSeed_F seed_loop_c (start)
    {
        //
        // seed_loop_c loop 1
        //
        // Ingress:
        //      aInvestLaneA (-->), aInvestLaneB (-->), aFireLaneB (-->), aOperationLaneD (<-?->)
        //
        // Cross:
        //      aInvestLaneC (<--), aInvestLaneD (<--), aWaterLaneD (<-?->)
        //
        // Destination:
        //      aSnowLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 5358U)) & S_BLOCK1], 10U) ^ RotL64(aInvestLaneB[((aIndex + 2072U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aFireLaneB[((aIndex + 2494U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((aIndex + 1676U)) & S_BLOCK1], 23U));

            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 3148U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 2862U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWaterLaneD[((aIndex + 984U)) & S_BLOCK1], 28U);

            aSnowLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 2
        //
        // Ingress:
        //      aSnowLaneC (-->), aInvestLaneC (-->), aWaterLaneC (-->), aSource (<-?->)
        //
        // Cross:
        //      aInvestLaneA (<--), aInvestLaneD (<--), aFireLaneA (<-?->)
        //
        // Destination:
        //      aSnowLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 6315U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneC[((aIndex + 6780U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aWaterLaneC[((aIndex + 10694U)) & S_BLOCK1], 46U) ^ RotL64(aSource[((aIndex + 7752U)) & S_BLOCK1], 57U));

            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 9968U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 9875U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 8449U)) & S_BLOCK1], 53U);

            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 3
        //
        // Ingress:
        //      aSnowLaneD (-->), aInvestLaneA (-->), aScrapLaneB (-->), aFireLaneD (<-?->)
        //
        // Cross:
        //      aSnowLaneC (<--), aInvestLaneC (<--), aScrapLaneC (<-?->)
        //
        // Destination:
        //      aWindLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 11310U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneA[((aIndex + 15833U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aScrapLaneB[((aIndex + 15650U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12168U)) & S_BLOCK1], 5U));

            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 15357U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12978U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aScrapLaneC[((aIndex + 12033U)) & S_BLOCK1], 19U);

            aWindLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 4
        //
        // Ingress:
        //      aWindLaneA (-->), aInvestLaneD (-->), aFireLaneC (-->), aOperationLaneA (<-?->)
        //
        // Cross:
        //      aSnowLaneD (<--), aInvestLaneA (<--), aOperationLaneB (<-?->)
        //
        // Destination:
        //      aWindLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWindLaneA[((aIndex + 16430U)) & S_BLOCK1], 48U) ^ RotL64(aInvestLaneD[((aIndex + 21447U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aFireLaneC[((aIndex + 18694U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 18528U)) & S_BLOCK1], 29U));

            //
            aCross = (RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 19066U)) & S_BLOCK1], 6U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 19412U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 16883U)) & S_BLOCK1], 21U);

            aWindLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 5
        //
        // Ingress:
        //      aWindLaneB (-->), aSnowLaneD (-->), aOperationLaneC (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aSnowLaneC (<--), aScrapLaneD (<-?->)
        //
        // Destination:
        //      aWindLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWindLaneB[((aIndex + 25422U)) & S_BLOCK1], 60U) ^ RotL64(aSnowLaneD[((aIndex + 22059U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22537U)) & S_BLOCK1], 27U);

            //
            aCross = (RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 27164U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 25519U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 25615U)) & S_BLOCK1], 4U);

            aWindLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 6
        //
        // Ingress:
        //      aWindLaneC (-->), aWindLaneA (-->), aScrapLaneA (<-?->)
        //
        // Cross:
        //      aWindLaneB (<--), aInvestLaneB (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aWindLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWindLaneC[((aIndex + 30649U)) & S_BLOCK1], 39U) ^ RotL64(aWindLaneA[((aIndex + 27652U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 29658U)) & S_BLOCK1], 3U);

            //
            aCross = (RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 31545U)) & S_BLOCK1], 52U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29645U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aEarthLaneD[((aIndex + 29201U)) & S_BLOCK1], 39U);

            aWindLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_F seed_loop_c (end)
    
}

void TwistExpander_Vega_Arx::Seed_G() {
    const std::uint64_t &aPhaseADomainWordIngress = pWorkSpace->mDomainBundle.mPhaseAConstants.mIngress;
    const std::uint64_t &aPhaseADomainWordScatter = pWorkSpace->mDomainBundle.mPhaseAConstants.mScatter;
    const std::uint64_t &aPhaseADomainWordCross = pWorkSpace->mDomainBundle.mPhaseAConstants.mCross;
    const std::uint64_t &aPhaseBDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseBConstants.mIngress;
    const std::uint64_t &aPhaseBDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseBConstants.mScatter;
    const std::uint64_t &aPhaseBDomainWordCross = pWorkSpace->mDomainBundle.mPhaseBConstants.mCross;
    const std::uint64_t &aPhaseEDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseEConstants.mIngress;
    const std::uint64_t &aPhaseEDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseEConstants.mScatter;
    const std::uint64_t &aPhaseEDomainWordCross = pWorkSpace->mDomainBundle.mPhaseEConstants.mCross;
    const std::uint64_t &aPhaseFDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseFConstants.mIngress;
    const std::uint64_t &aPhaseFDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseFConstants.mScatter;
    const std::uint64_t &aPhaseFDomainWordCross = pWorkSpace->mDomainBundle.mPhaseFConstants.mCross;
    // [seed arx]
    // GSeedRunSeed_G seed_loop_d (start)
    {
        //
        // seed_loop_d loop 1
        //
        // Ingress:
        //      aWindLaneA (-->), aWindLaneB (-->), aFireLaneB (-->), aFireLaneD (<-?->)
        //
        // Cross:
        //      aWindLaneC (<--), aWindLaneD (<--), aWaterLaneC (<-?->)
        //
        // Destination:
        //      aWaterLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWindLaneA[((aIndex + 773U)) & S_BLOCK1], 60U) ^ RotL64(aWindLaneB[((aIndex + 3550U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aFireLaneB[((aIndex + 4995U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 380U)) & S_BLOCK1], 39U));

            //
            aCross = (RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 4846U)) & S_BLOCK1], 53U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 1876U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 2145U)) & S_BLOCK1], 35U);

            aWaterLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 2
        //
        // Ingress:
        //      aWaterLaneA (-->), aWindLaneC (-->), aSnowLaneC (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aWindLaneD (<--), aInvestLaneC (<-?->)
        //
        // Destination:
        //      aWaterLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneA[((aIndex + 6597U)) & S_BLOCK1], 19U) ^ RotL64(aWindLaneC[((aIndex + 7018U)) & S_BLOCK1], 28U));
            aIngress ^= (RotL64(aSnowLaneC[((aIndex + 6847U)) & S_BLOCK1], 37U) ^ RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 8619U)) & S_BLOCK1], 53U));

            //
            aCross = (RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 8851U)) & S_BLOCK1], 48U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 8312U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 9959U)) & S_BLOCK1], 35U);

            aWaterLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 3
        //
        // Ingress:
        //      aWaterLaneB (-->), aWindLaneA (-->), aFireLaneA (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWindLaneC (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aOperationLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneB[((aIndex + 13803U)) & S_BLOCK1], 21U) ^ RotL64(aWindLaneA[((aIndex + 13273U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 12647U)) & S_BLOCK1], 30U) ^ RotL64(aKeyRowReadA[((aIndex + 12783U)) & W_KEY1], 43U));

            //
            aCross = (RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 14788U)) & S_BLOCK1], 27U) ^ RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 15583U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 14177U)) & S_BLOCK1], 38U);

            aOperationLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 4
        //
        // Ingress:
        //      aOperationLaneA (-->), aWindLaneD (-->), aInvestLaneA (-->), aScrapLaneC (<-?->)
        //
        // Cross:
        //      aWaterLaneB (<--), aWindLaneA (<--), aFireLaneC (<-?->)
        //
        // Destination:
        //      aOperationLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17440U)) & S_BLOCK1], 11U) ^ RotL64(aWindLaneD[((aIndex + 16490U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aInvestLaneA[((aIndex + 19738U)) & S_BLOCK1], 44U) ^ RotL64(aScrapLaneC[((aIndex + 18359U)) & S_BLOCK1], 3U));

            //
            aCross = (RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 19381U)) & S_BLOCK1], 13U) ^ RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 21093U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 17291U)) & S_BLOCK1], 53U);

            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 5
        //
        // Ingress:
        //      aOperationLaneB (-->), aWaterLaneB (-->), aInvestLaneB (-->), aScrapLaneD (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aWaterLaneA (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aOperationLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 27133U)) & S_BLOCK1], 41U) ^ RotL64(aWaterLaneB[((aIndex + 22026U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aInvestLaneB[((aIndex + 22686U)) & S_BLOCK1], 18U) ^ RotL64(aScrapLaneD[((aIndex + 23262U)) & S_BLOCK1], 27U));

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25620U)) & S_BLOCK1], 39U) ^ RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 24563U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 25346U)) & S_BLOCK1], 57U);

            aOperationLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 6
        //
        // Ingress:
        //      aOperationLaneC (-->), aOperationLaneA (-->), aInvestLaneD (-->), aWaterLaneD (<-?->)
        //
        // Cross:
        //      aOperationLaneB (<--), aWindLaneB (<--), aSnowLaneD (<-?->)
        //
        // Destination:
        //      aOperationLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27764U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneA[((aIndex + 31751U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 27541U)) & S_BLOCK1], 29U) ^ RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 28728U)) & S_BLOCK1], 51U));

            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30232U)) & S_BLOCK1], 19U) ^ RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 27511U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 30735U)) & S_BLOCK1], 28U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_G seed_loop_d (end)
    
}

void TwistExpander_Vega_Arx::Seed_H() {
    const std::uint64_t &aPhaseBDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseBConstants.mIngress;
    const std::uint64_t &aPhaseBDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseBConstants.mScatter;
    const std::uint64_t &aPhaseBDomainWordCross = pWorkSpace->mDomainBundle.mPhaseBConstants.mCross;
    const std::uint64_t &aPhaseCDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseCConstants.mIngress;
    const std::uint64_t &aPhaseCDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseCConstants.mScatter;
    const std::uint64_t &aPhaseCDomainWordCross = pWorkSpace->mDomainBundle.mPhaseCConstants.mCross;
    const std::uint64_t &aPhaseDDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseDConstants.mIngress;
    const std::uint64_t &aPhaseDDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseDConstants.mScatter;
    const std::uint64_t &aPhaseDDomainWordCross = pWorkSpace->mDomainBundle.mPhaseDConstants.mCross;
    const std::uint64_t &aPhaseFDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseFConstants.mIngress;
    const std::uint64_t &aPhaseFDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseFConstants.mScatter;
    const std::uint64_t &aPhaseFDomainWordCross = pWorkSpace->mDomainBundle.mPhaseFConstants.mCross;
    // [seed arx]
    // GSeedRunSeed_H seed_loop_e (start)
    {
        //
        // seed_loop_e loop 1
        //
        // Ingress:
        //      aOperationLaneA (-->), aOperationLaneB (-->), aFireLaneB (-->), aKeyRowReadB (<-?->)
        //
        // Cross:
        //      aOperationLaneC (<--), aOperationLaneD (<--), aInvestLaneB (<-?->)
        //
        // Destination:
        //      aSnowLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4250U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 2782U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aFireLaneB[((aIndex + 5412U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 1952U)) & W_KEY1], 51U));

            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4632U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1761U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 1459U)) & S_BLOCK1], 29U);

            aSnowLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 2
        //
        // Ingress:
        //      aSnowLaneA (-->), aOperationLaneC (-->), aWindLaneA (-->), aInvestLaneD (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aOperationLaneD (<--), aInvestLaneC (<-?->)
        //
        // Destination:
        //      aSnowLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8475U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneC[((aIndex + 7057U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aWindLaneA[((aIndex + 8280U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 6601U)) & S_BLOCK1], 35U));

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9286U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5690U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 7307U)) & S_BLOCK1], 4U);

            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 3
        //
        // Ingress:
        //      aSnowLaneB (-->), aOperationLaneA (-->), aWindLaneC (-->), aInvestLaneA (<-?->)
        //
        // Cross:
        //      aSnowLaneA (<--), aOperationLaneC (<--), aWaterLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 11089U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 12444U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aWindLaneC[((aIndex + 11855U)) & S_BLOCK1], 56U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 16063U)) & S_BLOCK1], 23U));

            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11817U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11741U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 13515U)) & S_BLOCK1], 13U);

            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 4
        //
        // Ingress:
        //      aFuseLaneA (-->), aOperationLaneD (-->), aSnowLaneD (-->), aWindLaneB (<-?->)
        //
        // Cross:
        //      aSnowLaneB (<--), aOperationLaneA (<--), aExpandLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneA[((aIndex + 20660U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((aIndex + 16993U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 18647U)) & S_BLOCK1], 21U) ^ RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 20320U)) & S_BLOCK1], 43U));

            //
            aCross = (RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19916U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19106U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21490U)) & S_BLOCK1], 52U);

            aFuseLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 5
        //
        // Ingress:
        //      aFuseLaneB (-->), aSnowLaneB (-->), aWaterLaneA (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aSnowLaneA (<--), aWindLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneB[((aIndex + 22043U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneB[((aIndex + 24735U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 25761U)) & S_BLOCK1], 29U);

            //
            aCross = (RotL64(aFuseLaneA[((S_BLOCK1 - aIndex + 26523U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 25414U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWindLaneD[((aIndex + 21996U)) & S_BLOCK1], 60U);

            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 6
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aFireLaneA (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aOperationLaneB (<--), aSnowLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 30057U)) & S_BLOCK1], 54U) ^ RotL64(aFuseLaneA[((aIndex + 32210U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 30460U)) & S_BLOCK1], 3U);

            //
            aCross = (RotL64(aFuseLaneB[((S_BLOCK1 - aIndex + 31288U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28984U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 28623U)) & S_BLOCK1], 3U);

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_H seed_loop_e (end)
    
}

void TwistExpander_Vega_Arx::Seed_I() {
    const std::uint64_t &aPhaseADomainWordIngress = pWorkSpace->mDomainBundle.mPhaseAConstants.mIngress;
    const std::uint64_t &aPhaseADomainWordScatter = pWorkSpace->mDomainBundle.mPhaseAConstants.mScatter;
    const std::uint64_t &aPhaseADomainWordCross = pWorkSpace->mDomainBundle.mPhaseAConstants.mCross;
    const std::uint64_t &aPhaseCDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseCConstants.mIngress;
    const std::uint64_t &aPhaseCDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseCConstants.mScatter;
    const std::uint64_t &aPhaseCDomainWordCross = pWorkSpace->mDomainBundle.mPhaseCConstants.mCross;
    const std::uint64_t &aPhaseDDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseDConstants.mIngress;
    const std::uint64_t &aPhaseDDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseDConstants.mScatter;
    const std::uint64_t &aPhaseDDomainWordCross = pWorkSpace->mDomainBundle.mPhaseDConstants.mCross;
    const std::uint64_t &aPhaseEDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseEConstants.mIngress;
    const std::uint64_t &aPhaseEDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseEConstants.mScatter;
    const std::uint64_t &aPhaseEDomainWordCross = pWorkSpace->mDomainBundle.mPhaseEConstants.mCross;
    // [seed arx]
    // GSeedRunSeed_I seed_loop_f (start)
    {
        //
        // seed_loop_f loop 1
        //
        // Ingress:
        //      aInvestLaneE (-->), aInvestLaneF (-->), aWaterLaneA (-->), aSnowLaneB (<-?->)
        //
        // Cross:
        //      aInvestLaneG (<--), aInvestLaneH (<--), aOperationLaneD (<-?->)
        //
        // Destination:
        //      aSnowLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneE[((aIndex + 2379U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneF[((aIndex + 2026U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aWaterLaneA[((aIndex + 3263U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 1627U)) & S_BLOCK1], 3U));

            //
            aCross = (RotL64(aInvestLaneG[((S_BLOCK1 - aIndex + 252U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneH[((S_BLOCK1 - aIndex + 5294U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1501U)) & S_BLOCK1], 41U);

            aSnowLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 2
        //
        // Ingress:
        //      aSnowLaneC (-->), aInvestLaneG (-->), aWindLaneC (-->), aOperationLaneB (<-?->)
        //
        // Cross:
        //      aInvestLaneE (<--), aInvestLaneH (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aSnowLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 8584U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneG[((aIndex + 7551U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aWindLaneC[((aIndex + 8177U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10826U)) & S_BLOCK1], 47U));

            //
            aCross = (RotL64(aInvestLaneE[((S_BLOCK1 - aIndex + 6098U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneH[((S_BLOCK1 - aIndex + 9401U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 10332U)) & S_BLOCK1], 13U);

            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 3
        //
        // Ingress:
        //      aSnowLaneD (-->), aInvestLaneE (-->), aWindLaneB (-->), aOperationLaneA (<-?->)
        //
        // Cross:
        //      aSnowLaneC (<--), aInvestLaneG (<--), aExpandLaneA (<-?->)
        //
        // Destination:
        //      aWorkLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 11368U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneE[((aIndex + 16027U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aWindLaneB[((aIndex + 11939U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13826U)) & S_BLOCK1], 13U));

            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 15750U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneG[((S_BLOCK1 - aIndex + 11482U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 14764U)) & S_BLOCK1], 19U);

            aWorkLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 4
        //
        // Ingress:
        //      aWorkLaneA (-->), aInvestLaneH (-->), aOperationLaneC (-->), aExpandLaneB (<-?->)
        //
        // Cross:
        //      aSnowLaneD (<--), aInvestLaneE (<--), aSnowLaneA (<-?->)
        //
        // Destination:
        //      aWorkLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 17404U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneH[((aIndex + 17315U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aOperationLaneC[((aIndex + 19120U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 18802U)) & S_BLOCK1], 35U));

            //
            aCross = (RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 21248U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneE[((S_BLOCK1 - aIndex + 21388U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 17426U)) & S_BLOCK1], 34U);

            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 5
        //
        // Ingress:
        //      aWorkLaneB (-->), aSnowLaneD (-->), aWindLaneD (<-?->)
        //
        // Cross:
        //      aWorkLaneA (<--), aSnowLaneC (<--), aFireLaneC (<-?->)
        //
        // Destination:
        //      aWorkLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 25280U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneD[((aIndex + 26188U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aWindLaneD[((aIndex + 23170U)) & S_BLOCK1], 13U);

            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26021U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 26818U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 26331U)) & S_BLOCK1], 5U);

            aWorkLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 6
        //
        // Ingress:
        //      aWorkLaneC (-->), aWorkLaneA (-->), aWaterLaneB (<-?->)
        //
        // Cross:
        //      aWorkLaneB (<--), aInvestLaneF (<--), aFireLaneD (<-?->)
        //
        // Destination:
        //      aWorkLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32665U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 27335U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWaterLaneB[((aIndex + 31405U)) & S_BLOCK1], 34U);

            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32161U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneF[((S_BLOCK1 - aIndex + 32132U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 30828U)) & S_BLOCK1], 5U);

            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_I seed_loop_f (end)
    
}

void TwistExpander_Vega_Arx::Twist_A() {
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = RotL64(aSource[((aIndex + 4705U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 1933U)) & W_KEY1], 36U);

            //
            aCross = RotL64(aSource[((S_BLOCK1 - aIndex + 192U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 1191U)) & W_KEY1], 44U);

            aScrapLaneA[aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = RotL64(aScrapLaneA[((aIndex + 8915U)) & S_BLOCK1], 28U) ^ RotL64(aKeyRowReadB[((aIndex + 8173U)) & W_KEY1], 19U);

            //
            aCross = RotL64(aSource[((S_BLOCK1 - aIndex + 8212U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 9651U)) & W_KEY1], 4U);

            aScrapLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneB[((aIndex + 14495U)) & S_BLOCK1], 28U) ^ RotL64(aSource[((aIndex + 14322U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aKeyRowReadB[((aIndex + 11914U)) & W_KEY1], 37U);

            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 11674U)) & W_KEY1], 27U) ^ RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 15974U)) & S_BLOCK1], 52U);

            aWindLaneA[aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = RotL64(aWindLaneA[((aIndex + 20025U)) & S_BLOCK1], 48U) ^ RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 18013U)) & S_BLOCK1], 57U);

            //
            aCross = RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 17120U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadB[((aIndex + 18411U)) & W_KEY1], 24U);

            aWindLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = RotL64(aWindLaneB[((aIndex + 26636U)) & S_BLOCK1], 54U) ^ RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 24050U)) & S_BLOCK1], 43U);

            //
            aCross = RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 26422U)) & S_BLOCK1], 42U) ^ RotL64(aKeyRowReadA[((aIndex + 23441U)) & W_KEY1], 53U);

            aWindLaneC[aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = RotL64(aWindLaneC[((aIndex + 28555U)) & S_BLOCK1], 23U) ^ RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 31706U)) & S_BLOCK1], 50U);

            //
            aCross = RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 31676U)) & S_BLOCK1], 52U) ^ RotL64(aScrapLaneB[((aIndex + 32056U)) & S_BLOCK1], 21U);

            aWindLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_A twist_loop_a (end)
    
}

void TwistExpander_Vega_Arx::Twist_B() {
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWindLaneA[((aIndex + 2722U)) & S_BLOCK1], 47U) ^ RotL64(aWindLaneB[((aIndex + 4823U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aKeyRowReadB[(((2047U - aIndex) + 1444U)) & W_KEY1], 18U);

            //
            aCross = RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 5271U)) & S_BLOCK1], 11U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 426U)) & S_BLOCK1], 54U);

            aWorkLaneA[aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6648U)) & S_BLOCK1], 53U) ^ RotL64(aWindLaneC[((aIndex + 8736U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aScrapLaneA[((aIndex + 8580U)) & S_BLOCK1], 4U);

            //
            aCross = RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 6093U)) & S_BLOCK1], 56U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 10511U)) & S_BLOCK1], 39U);

            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 14548U)) & S_BLOCK1], 43U) ^ RotL64(aWindLaneA[((aIndex + 13101U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aKeyRowReadA[((aIndex + 11148U)) & W_KEY1], 27U);

            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12841U)) & S_BLOCK1], 13U) ^ RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 14410U)) & S_BLOCK1], 40U);

            aSnowLaneA[aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 19277U)) & S_BLOCK1], 10U) ^ RotL64(aWindLaneD[((aIndex + 17435U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aScrapLaneB[((aIndex + 17516U)) & S_BLOCK1], 39U);

            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19294U)) & S_BLOCK1], 3U) ^ RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 16518U)) & S_BLOCK1], 58U);

            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 21908U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 27154U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aSource[((aIndex + 22262U)) & S_BLOCK1], 37U);

            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 27302U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 23448U)) & S_BLOCK1], 50U);

            aSnowLaneC[aIndex] = aIngress;
        }
    
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = RotL64(aSnowLaneC[((aIndex + 28856U)) & S_BLOCK1], 42U) ^ RotL64(aSnowLaneA[((aIndex + 31450U)) & S_BLOCK1], 3U);

            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 32205U)) & S_BLOCK1], 20U) ^ RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 30655U)) & S_BLOCK1], 3U);

            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_B twist_loop_b (end)
    
}

void TwistExpander_Vega_Arx::Twist_C() {
    // [twist arx]
    // GTwistRunTwist_C twist_loop_c (start)
    {
        //
        // twist_loop_c loop 1
        //
        // Ingress:
        //      aSnowLaneA (-->), aSnowLaneB (-->), aWindLaneD (<-?->)
        //
        // Cross:
        //      aSnowLaneC (<--), aSnowLaneD (<--), aWorkLaneB (<-?->)
        //
        // Destination:
        //      aInvestLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 1926U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneB[((aIndex + 808U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWindLaneD[((aIndex + 1510U)) & S_BLOCK1], 60U);

            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 569U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 3583U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5245U)) & S_BLOCK1], 35U);

            aInvestLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_c loop 2
        //
        // Ingress:
        //      aInvestLaneA (-->), aSnowLaneC (-->), aScrapLaneA (<-?->)
        //
        // Cross:
        //      aSnowLaneA (<--), aSnowLaneD (<--), aWindLaneB (<-?->)
        //
        // Destination:
        //      aInvestLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 6817U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneC[((aIndex + 7283U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 10154U)) & S_BLOCK1], 56U);

            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 9531U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 9995U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 7962U)) & S_BLOCK1], 54U);

            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // twist_loop_c loop 3
        //
        // Ingress:
        //      aInvestLaneB (-->), aSnowLaneA (-->), aWindLaneC (<-?->)
        //
        // Cross:
        //      aInvestLaneA (<--), aSnowLaneC (<--), aWorkLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 11724U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneA[((aIndex + 12404U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 13045U)) & S_BLOCK1], 44U);

            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15239U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 11842U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14342U)) & S_BLOCK1], 20U);

            aOperationLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_c loop 4
        //
        // Ingress:
        //      aOperationLaneA (-->), aSnowLaneD (-->), aScrapLaneB (<-?->)
        //
        // Cross:
        //      aInvestLaneB (<--), aSnowLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18464U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneD[((aIndex + 20329U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 18113U)) & S_BLOCK1], 40U);

            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17983U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneA[((aIndex + 18752U)) & S_BLOCK1], 60U);

            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // twist_loop_c loop 5
        //
        // Ingress:
        //      aOperationLaneB (-->), aInvestLaneB (-->), aSource (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aInvestLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25982U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneB[((aIndex + 22601U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aSource[((aIndex + 22236U)) & S_BLOCK1], 48U);

            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24943U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneA[((aIndex + 23257U)) & S_BLOCK1], 38U);

            aOperationLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_c loop 6
        //
        // Ingress:
        //      aOperationLaneC (-->), aOperationLaneA (-->), aWindLaneA (<-?->)
        //
        // Cross:
        //      aOperationLaneB (<--), aSnowLaneB (<--)
        //
        // Destination:
        //      aOperationLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28763U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 28549U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWindLaneA[((aIndex + 31639U)) & S_BLOCK1], 24U);

            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30830U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 27655U)) & S_BLOCK1], 22U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_C twist_loop_c (end)
    
}

void TwistExpander_Vega_Arx::Twist_D() {
    // [twist arx]
    // GTwistRunTwist_D twist_loop_d (start)
    {
        //
        // twist_loop_d loop 1
        //
        // Ingress:
        //      aOperationLaneA (-->), aOperationLaneB (-->), aSnowLaneC (<-?->)
        //
        // Cross:
        //      aOperationLaneC (<--), aOperationLaneD (<--), aWindLaneB (<-?->)
        //
        // Destination:
        //      aScrapLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1356U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((aIndex + 3550U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aSnowLaneC[((aIndex + 491U)) & S_BLOCK1], 53U);

            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3965U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 460U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 2664U)) & S_BLOCK1], 10U);

            aScrapLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 2
        //
        // Ingress:
        //      aScrapLaneC (-->), aOperationLaneC (-->), aWindLaneC (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aOperationLaneD (<--), aWindLaneD (<-?->)
        //
        // Destination:
        //      aScrapLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneC[((aIndex + 6596U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((aIndex + 10138U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 5611U)) & S_BLOCK1], 37U);

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9133U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6587U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWindLaneD[((aIndex + 8647U)) & S_BLOCK1], 48U);

            aScrapLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 3
        //
        // Ingress:
        //      aScrapLaneD (-->), aOperationLaneA (-->), aWindLaneA (<-?->)
        //
        // Cross:
        //      aScrapLaneC (<--), aOperationLaneC (<--), aSnowLaneB (<-?->)
        //
        // Destination:
        //      aWaterLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneD[((aIndex + 13334U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((aIndex + 11290U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWindLaneA[((aIndex + 13480U)) & S_BLOCK1], 23U);

            //
            aCross = (RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 11075U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16013U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aSnowLaneB[((aIndex + 15229U)) & S_BLOCK1], 43U);

            aWaterLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 4
        //
        // Ingress:
        //      aWaterLaneA (-->), aOperationLaneD (-->), aInvestLaneA (<-?->)
        //
        // Cross:
        //      aScrapLaneD (<--), aOperationLaneA (<--), aSnowLaneD (<-?->)
        //
        // Destination:
        //      aWaterLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneA[((aIndex + 18393U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((aIndex + 18650U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 19017U)) & S_BLOCK1], 18U);

            //
            aCross = (RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 20260U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18764U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aSnowLaneD[((aIndex + 18933U)) & S_BLOCK1], 27U);

            aWaterLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 5
        //
        // Ingress:
        //      aWaterLaneB (-->), aScrapLaneD (-->), aSnowLaneA (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aScrapLaneC (<--), aInvestLaneB (<-?->)
        //
        // Destination:
        //      aWaterLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneB[((aIndex + 23022U)) & S_BLOCK1], 48U) ^ RotL64(aScrapLaneD[((aIndex + 24445U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 22482U)) & S_BLOCK1], 39U);

            //
            aCross = (RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 22934U)) & S_BLOCK1], 51U) ^ RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 27005U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 25884U)) & S_BLOCK1], 3U);

            aWaterLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 6
        //
        // Ingress:
        //      aWaterLaneC (-->), aWaterLaneA (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aWaterLaneB (<--), aOperationLaneB (<--)
        //
        // Destination:
        //      aWaterLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneC[((aIndex + 29270U)) & S_BLOCK1], 53U) ^ RotL64(aWaterLaneA[((aIndex + 30511U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aKeyRowReadA[(((2047U - aIndex) + 27651U)) & W_KEY1], 41U);

            //
            aCross = RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 32116U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32386U)) & S_BLOCK1], 14U);

            aWaterLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_D twist_loop_d (end)
    
}

void TwistExpander_Vega_Arx::Twist_E() {
    // [twist arx]
    // GTwistRunTwist_E twist_loop_e (start)
    {
        //
        // twist_loop_e loop 1
        //
        // Ingress:
        //      aWaterLaneA (-->), aWaterLaneB (-->), aKeyRowReadB (<-?->)
        //
        // Cross:
        //      aWaterLaneC (<--), aWaterLaneD (<--), aInvestLaneA (<-?->)
        //
        // Destination:
        //      aInvestLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneA[((aIndex + 802U)) & S_BLOCK1], 34U) ^ RotL64(aWaterLaneB[((aIndex + 2U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aKeyRowReadB[(((2047U - aIndex) + 704U)) & W_KEY1], 11U);

            //
            aCross = (RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 4626U)) & S_BLOCK1], 57U) ^ RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 3489U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 4302U)) & S_BLOCK1], 37U);

            aInvestLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 2
        //
        // Ingress:
        //      aInvestLaneC (-->), aWaterLaneC (-->), aOperationLaneD (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWaterLaneD (<--), aSnowLaneB (<-?->)
        //
        // Destination:
        //      aInvestLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 6896U)) & S_BLOCK1], 21U) ^ RotL64(aWaterLaneC[((aIndex + 10212U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 7182U)) & S_BLOCK1], 42U);

            //
            aCross = (RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 9892U)) & S_BLOCK1], 47U) ^ RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 9094U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aSnowLaneB[((aIndex + 7170U)) & S_BLOCK1], 56U);

            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 3
        //
        // Ingress:
        //      aInvestLaneD (-->), aWaterLaneA (-->), aSnowLaneA (<-?->)
        //
        // Cross:
        //      aInvestLaneC (<--), aWaterLaneC (<--), aScrapLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 11901U)) & S_BLOCK1], 11U) ^ RotL64(aWaterLaneA[((aIndex + 14926U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aSnowLaneA[((aIndex + 14656U)) & S_BLOCK1], 50U);

            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12874U)) & S_BLOCK1], 36U) ^ RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 11797U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aScrapLaneC[((aIndex + 15672U)) & S_BLOCK1], 27U);

            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 4
        //
        // Ingress:
        //      aFuseLaneA (-->), aWaterLaneD (-->), aOperationLaneB (<-?->)
        //
        // Cross:
        //      aInvestLaneD (<--), aWaterLaneA (<--), aOperationLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneA[((aIndex + 21519U)) & S_BLOCK1], 24U) ^ RotL64(aWaterLaneD[((aIndex + 18479U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 16730U)) & S_BLOCK1], 3U);

            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 21441U)) & S_BLOCK1], 19U) ^ RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 20408U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 20695U)) & S_BLOCK1], 46U);

            aFuseLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 5
        //
        // Ingress:
        //      aFuseLaneB (-->), aInvestLaneD (-->), aSnowLaneD (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aInvestLaneC (<--), aSnowLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneB[((aIndex + 24624U)) & S_BLOCK1], 48U) ^ RotL64(aInvestLaneD[((aIndex + 25119U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 26617U)) & S_BLOCK1], 35U);

            //
            aCross = (RotL64(aFuseLaneA[((S_BLOCK1 - aIndex + 24531U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 26832U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aSnowLaneC[((aIndex + 23689U)) & S_BLOCK1], 29U);

            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 6
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aOperationLaneA (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aWaterLaneB (<--), aScrapLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 29411U)) & S_BLOCK1], 37U) ^ RotL64(aFuseLaneA[((aIndex + 27365U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32580U)) & S_BLOCK1], 13U);

            //
            aCross = (RotL64(aFuseLaneB[((S_BLOCK1 - aIndex + 31529U)) & S_BLOCK1], 47U) ^ RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 27975U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aScrapLaneD[((aIndex + 31639U)) & S_BLOCK1], 23U);

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_E twist_loop_e (end)
    
}

void TwistExpander_Vega_Arx::Twist_F() {
    // [twist arx]
    // GTwistRunTwist_F twist_loop_f (start)
    {
        //
        // twist_loop_f loop 1
        //
        // Ingress:
        //      aFireLaneA (-->), aFireLaneB (-->), aWaterLaneD (-->), aSnowLaneA (<-?->)
        //
        // Cross:
        //      aFireLaneC (<--), aFireLaneD (<--), aWaterLaneA (<-?->)
        //
        // Destination:
        //      aInvestLaneE
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFireLaneA[((aIndex + 5198U)) & S_BLOCK1], 52U) ^ RotL64(aFireLaneB[((aIndex + 2425U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aWaterLaneD[((aIndex + 4313U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneA[((aIndex + 221U)) & S_BLOCK1], 19U));

            //
            aCross = (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 675U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 130U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 3739U)) & S_BLOCK1], 56U);

            aInvestLaneE[aIndex] = aIngress;
        }
    
        //
        // twist_loop_f loop 2
        //
        // Ingress:
        //      aInvestLaneE (-->), aFireLaneC (-->), aOperationLaneB (-->), aInvestLaneB (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), aScrapLaneB (<-?->)
        //
        // Destination:
        //      aInvestLaneF
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneE[((aIndex + 7371U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneC[((aIndex + 8223U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 8928U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneB[((aIndex + 10061U)) & S_BLOCK1], 5U));

            //
            aCross = (RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 8223U)) & S_BLOCK1], 10U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10741U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 7081U)) & S_BLOCK1], 21U);

            aInvestLaneF[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // twist_loop_f loop 3
        //
        // Ingress:
        //      aInvestLaneF (-->), aFireLaneA (-->), aScrapLaneD (-->), aInvestLaneD (<-?->)
        //
        // Cross:
        //      aInvestLaneE (<--), aFireLaneC (<--), aWaterLaneB (<-?->)
        //
        // Destination:
        //      aEarthLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneF[((aIndex + 14902U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneA[((aIndex + 14965U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aScrapLaneD[((aIndex + 14760U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneD[((aIndex + 13531U)) & S_BLOCK1], 56U));

            //
            aCross = (RotL64(aInvestLaneE[((S_BLOCK1 - aIndex + 13244U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15089U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 15727U)) & S_BLOCK1], 12U);

            aEarthLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_f loop 4
        //
        // Ingress:
        //      aEarthLaneA (-->), aFireLaneD (-->), aSnowLaneB (-->), aSource (<-?->)
        //
        // Cross:
        //      aInvestLaneF (<--), aFireLaneA (<--), aScrapLaneA (<-?->)
        //
        // Destination:
        //      aEarthLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneA[((aIndex + 20147U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneD[((aIndex + 16729U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aSnowLaneB[((aIndex + 16728U)) & S_BLOCK1], 3U) ^ RotL64(aSource[((aIndex + 18629U)) & S_BLOCK1], 56U));

            //
            aCross = (RotL64(aInvestLaneF[((S_BLOCK1 - aIndex + 20741U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 21068U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 16703U)) & S_BLOCK1], 42U);

            aEarthLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // twist_loop_f loop 5
        //
        // Ingress:
        //      aEarthLaneB (-->), aInvestLaneF (-->), aWaterLaneC (-->), aOperationLaneA (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aInvestLaneE (<--), aOperationLaneD (<-?->)
        //
        // Destination:
        //      aEarthLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneB[((aIndex + 26394U)) & S_BLOCK1], 34U) ^ RotL64(aInvestLaneF[((aIndex + 24697U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aWaterLaneC[((aIndex + 23052U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 25108U)) & S_BLOCK1], 43U));

            //
            aCross = (RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 26983U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneE[((S_BLOCK1 - aIndex + 27158U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 22966U)) & S_BLOCK1], 41U);

            aEarthLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_f loop 6
        //
        // Ingress:
        //      aEarthLaneC (-->), aEarthLaneA (-->), aScrapLaneC (-->), aInvestLaneC (<-?->)
        //
        // Cross:
        //      aEarthLaneB (<--), aFireLaneB (<--), aOperationLaneC (<-?->)
        //
        // Destination:
        //      aEarthLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneC[((aIndex + 28133U)) & S_BLOCK1], 19U) ^ RotL64(aEarthLaneA[((aIndex + 30356U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aScrapLaneC[((aIndex + 28594U)) & S_BLOCK1], 34U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 28654U)) & S_BLOCK1], 53U));

            //
            aCross = (RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 28065U)) & S_BLOCK1], 12U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 31535U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 30294U)) & S_BLOCK1], 53U);

            aEarthLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_F twist_loop_f (end)
    
}

void TwistExpander_Vega_Arx::Twist_G() {
    // [twist arx]
    // GTwistRunTwist_G twist_loop_g (start)
    {
        //
        // twist_loop_g loop 1
        //
        // Ingress:
        //      aEarthLaneA (-->), aEarthLaneB (-->), aSnowLaneD (-->), aInvestLaneC (<-?->)
        //
        // Cross:
        //      aEarthLaneC (<--), aEarthLaneD (<--), aKeyRowReadB (<-?->)
        //
        // Destination:
        //      aInvestLaneG
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneA[((aIndex + 2837U)) & S_BLOCK1], 26U) ^ RotL64(aEarthLaneB[((aIndex + 5158U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 2343U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 2388U)) & S_BLOCK1], 57U));

            //
            aCross = (RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 1536U)) & S_BLOCK1], 12U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 2871U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aKeyRowReadB[(((2047U - aIndex) + 73U)) & W_KEY1], 29U);

            aInvestLaneG[aIndex] = aIngress;
        }
    
        //
        // twist_loop_g loop 2
        //
        // Ingress:
        //      aInvestLaneG (-->), aEarthLaneC (-->), aInvestLaneF (-->), aInvestLaneE (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aEarthLaneD (<--), aWaterLaneD (<-?->)
        //
        // Destination:
        //      aInvestLaneH
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneG[((aIndex + 6813U)) & S_BLOCK1], 29U) ^ RotL64(aEarthLaneC[((aIndex + 8125U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aInvestLaneF[((aIndex + 10438U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneE[((S_BLOCK1 - aIndex + 7014U)) & S_BLOCK1], 13U));

            //
            aCross = (RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 8401U)) & S_BLOCK1], 56U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 10736U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 9571U)) & S_BLOCK1], 13U);

            aInvestLaneH[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // twist_loop_g loop 3
        //
        // Ingress:
        //      aInvestLaneH (-->), aEarthLaneA (-->), aFireLaneD (-->), aWaterLaneC (<-?->)
        //
        // Cross:
        //      aInvestLaneG (<--), aEarthLaneC (<--), aFireLaneA (<-?->)
        //
        // Destination:
        //      aWorkLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneH[((aIndex + 15237U)) & S_BLOCK1], 35U) ^ RotL64(aEarthLaneA[((aIndex + 11380U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 14358U)) & S_BLOCK1], 54U) ^ RotL64(aWaterLaneC[((aIndex + 14881U)) & S_BLOCK1], 11U));

            //
            aCross = (RotL64(aInvestLaneG[((S_BLOCK1 - aIndex + 13652U)) & S_BLOCK1], 44U) ^ RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 14276U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16281U)) & S_BLOCK1], 5U);

            aWorkLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_g loop 4
        //
        // Ingress:
        //      aWorkLaneA (-->), aEarthLaneD (-->), aInvestLaneB (-->), aWaterLaneA (<-?->)
        //
        // Cross:
        //      aInvestLaneH (<--), aEarthLaneA (<--), aFireLaneB (<-?->)
        //
        // Destination:
        //      aWorkLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 18061U)) & S_BLOCK1], 11U) ^ RotL64(aEarthLaneD[((aIndex + 17579U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aInvestLaneB[((aIndex + 19229U)) & S_BLOCK1], 39U) ^ RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 17027U)) & S_BLOCK1], 30U));

            //
            aCross = (RotL64(aInvestLaneH[((S_BLOCK1 - aIndex + 19301U)) & S_BLOCK1], 3U) ^ RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 19016U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 21748U)) & S_BLOCK1], 14U);

            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // twist_loop_g loop 5
        //
        // Ingress:
        //      aWorkLaneB (-->), aInvestLaneH (-->), aSnowLaneC (-->), aFireLaneC (<-?->)
        //
        // Cross:
        //      aWorkLaneA (<--), aInvestLaneG (<--), aWaterLaneB (<-?->)
        //
        // Destination:
        //      aWorkLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 25601U)) & S_BLOCK1], 56U) ^ RotL64(aInvestLaneH[((aIndex + 25233U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aSnowLaneC[((aIndex + 23693U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneC[((aIndex + 23465U)) & S_BLOCK1], 37U));

            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23039U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneG[((S_BLOCK1 - aIndex + 25735U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 25751U)) & S_BLOCK1], 3U);

            aWorkLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_g loop 6
        //
        // Ingress:
        //      aWorkLaneC (-->), aWorkLaneA (-->), aInvestLaneA (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aWorkLaneB (<--), aEarthLaneB (<--), aInvestLaneD (<-?->)
        //
        // Destination:
        //      aWorkLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32497U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 31728U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aInvestLaneA[((aIndex + 28380U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[((aIndex + 31184U)) & W_KEY1], 26U));

            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30533U)) & S_BLOCK1], 11U) ^ RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 28026U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 27355U)) & S_BLOCK1], 60U);

            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_G twist_loop_g (end)
    
}

void TwistExpander_Vega_Arx::GROW_A() {
    // [grow arx]
    // GROW_A grow_key_a (start)
    {
        //
        // grow_key_a loop 1
        //
        // Ingress:
        //      aWorkLaneA (-->), aWorkLaneB (-->), aFireLaneD (-->), aScrapLaneB (<-?->)
        //
        // Cross:
        //      aWorkLaneC (<--), aWorkLaneD (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aOperationLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1088U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 123U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 687U)) & S_BLOCK1], 5U) ^ RotL64(aScrapLaneB[((aIndex + 4613U)) & S_BLOCK1], 34U));

            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4243U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3160U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aEarthLaneB[((aIndex + 4058U)) & S_BLOCK1], 50U);

            aOperationLaneB[aIndex] = aIngress;
        }
    
        //
        // grow_key_a loop 2
        //
        // Ingress:
        //      aOperationLaneB (-->), aWorkLaneC (-->), aEarthLaneD (-->), aInvestLaneA (<-?->)
        //
        // Cross:
        //      aWorkLaneA (<--), aWorkLaneD (<--), aOperationLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 8485U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 6364U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aEarthLaneD[((aIndex + 10856U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 9622U)) & S_BLOCK1], 54U));

            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9899U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6065U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10763U)) & S_BLOCK1], 27U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // grow_key_a loop 3
        //
        // Ingress:
        //      aOperationLaneD (-->), aWorkLaneA (-->), aInvestLaneB (-->), aWaterLaneC (<-?->)
        //
        // Cross:
        //      aOperationLaneB (<--), aWorkLaneC (<--), aScrapLaneD (<-?->)
        //
        // Destination:
        //      aExpandLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneD[((aIndex + 14022U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 13472U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aInvestLaneB[((aIndex + 15963U)) & S_BLOCK1], 53U) ^ RotL64(aWaterLaneC[((aIndex + 16128U)) & S_BLOCK1], 26U));

            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14686U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15394U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 13911U)) & S_BLOCK1], 11U);

            aExpandLaneA[aIndex] = aIngress;
        }
    
        //
        // grow_key_a loop 4
        //
        // Ingress:
        //      aExpandLaneA (-->), aWorkLaneD (-->), aSnowLaneD (-->), aInvestLaneF (<-?->)
        //
        // Cross:
        //      aOperationLaneD (<--), aWorkLaneA (<--), aWaterLaneA (<-?->)
        //
        // Destination:
        //      aExpandLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19737U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneD[((aIndex + 16469U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 18107U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneF[((S_BLOCK1 - aIndex + 17631U)) & S_BLOCK1], 3U));

            //
            aCross = (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20301U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18034U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 18425U)) & S_BLOCK1], 37U);

            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // grow_key_a loop 5
        //
        // Ingress:
        //      aExpandLaneB (-->), aOperationLaneD (-->), aScrapLaneA (-->), aInvestLaneE (<-?->)
        //
        // Cross:
        //      aExpandLaneA (<--), aOperationLaneB (<--), aScrapLaneC (<-?->)
        //
        // Destination:
        //      aExpandLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26044U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((aIndex + 22784U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aScrapLaneA[((aIndex + 22152U)) & S_BLOCK1], 30U) ^ RotL64(aInvestLaneE[((S_BLOCK1 - aIndex + 24703U)) & S_BLOCK1], 53U));

            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24154U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24432U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aScrapLaneC[((aIndex + 23599U)) & S_BLOCK1], 52U);

            aExpandLaneC[aIndex] = aIngress;
        }
    
        //
        // grow_key_a loop 6
        //
        // Ingress:
        //      aExpandLaneC (-->), aExpandLaneA (-->), aSnowLaneB (-->), aFireLaneB (<-?->)
        //
        // Cross:
        //      aExpandLaneB (<--), aWorkLaneB (<--), aOperationLaneC (<-?->)
        //
        // Destination:
        //      aExpandLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30398U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 27759U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aSnowLaneB[((aIndex + 30946U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 31524U)) & S_BLOCK1], 39U));

            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30552U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29881U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 31217U)) & S_BLOCK1], 11U);

            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GROW_A grow_key_a (end)
    
}

void TwistExpander_Vega_Arx::GROW_B() {
    // [grow arx]
    // GROW_B grow_key_b (start)
    {
        //
        // grow_key_b loop 1
        //
        // Ingress:
        //      aExpandLaneA (-->), aExpandLaneB (-->), aWindLaneB (-->), aOperationLaneB (<-?->)
        //
        // Cross:
        //      aExpandLaneC (<--), aExpandLaneD (<--), aWaterLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3193U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 3577U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aWindLaneB[((aIndex + 355U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 3527U)) & S_BLOCK1], 40U));

            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1124U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3649U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWaterLaneD[((aIndex + 4646U)) & S_BLOCK1], 30U);

            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // grow_key_b loop 2
        //
        // Ingress:
        //      aFuseLaneC (-->), aExpandLaneC (-->), aFireLaneA (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aExpandLaneA (<--), aExpandLaneD (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 8720U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 6843U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 6948U)) & S_BLOCK1], 13U) ^ RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 6293U)) & S_BLOCK1], 26U));

            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7201U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7374U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 7598U)) & S_BLOCK1], 27U);

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // grow_key_b loop 3
        //
        // Ingress:
        //      aFuseLaneD (-->), aExpandLaneA (-->), aFireLaneC (-->), aSnowLaneA (<-?->)
        //
        // Cross:
        //      aFuseLaneC (<--), aExpandLaneC (<--), aSnowLaneC (<-?->)
        //
        // Destination:
        //      aWorkLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneD[((aIndex + 12933U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 11159U)) & S_BLOCK1], 30U));
            aIngress ^= (RotL64(aFireLaneC[((aIndex + 14076U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneA[((aIndex + 13202U)) & S_BLOCK1], 11U));

            //
            aCross = (RotL64(aFuseLaneC[((S_BLOCK1 - aIndex + 13241U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11457U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aSnowLaneC[((aIndex + 15519U)) & S_BLOCK1], 56U);

            aWorkLaneA[aIndex] = aIngress;
        }
    
        //
        // grow_key_b loop 4
        //
        // Ingress:
        //      aWorkLaneA (-->), aExpandLaneD (-->), aWaterLaneB (-->), aOperationLaneD (<-?->)
        //
        // Cross:
        //      aFuseLaneD (<--), aExpandLaneA (<--), aInvestLaneD (<-?->)
        //
        // Destination:
        //      aWorkLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 17531U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((aIndex + 19127U)) & S_BLOCK1], 20U));
            aIngress ^= (RotL64(aWaterLaneB[((aIndex + 16566U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((aIndex + 19423U)) & S_BLOCK1], 51U));

            //
            aCross = (RotL64(aFuseLaneD[((S_BLOCK1 - aIndex + 20218U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18150U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 20300U)) & S_BLOCK1], 48U);

            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // grow_key_b loop 5
        //
        // Ingress:
        //      aWorkLaneB (-->), aFuseLaneD (-->), aWindLaneC (-->), aInvestLaneH (<-?->)
        //
        // Cross:
        //      aWorkLaneA (<--), aFuseLaneC (<--), aWindLaneD (<-?->)
        //
        // Destination:
        //      aWorkLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 25579U)) & S_BLOCK1], 19U) ^ RotL64(aFuseLaneD[((aIndex + 27237U)) & S_BLOCK1], 30U));
            aIngress ^= (RotL64(aWindLaneC[((aIndex + 26689U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneH[((S_BLOCK1 - aIndex + 25115U)) & S_BLOCK1], 57U));

            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22519U)) & S_BLOCK1], 60U) ^ RotL64(aFuseLaneC[((S_BLOCK1 - aIndex + 23932U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 24419U)) & S_BLOCK1], 5U);

            aWorkLaneC[aIndex] = aIngress;
        }
    
        //
        // grow_key_b loop 6
        //
        // Ingress:
        //      aWorkLaneC (-->), aWorkLaneA (-->), aInvestLaneG (-->), aInvestLaneC (<-?->)
        //
        // Cross:
        //      aWorkLaneB (<--), aExpandLaneB (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aWorkLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30754U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((aIndex + 28071U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aInvestLaneG[((aIndex + 30957U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((aIndex + 32051U)) & S_BLOCK1], 11U));

            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27640U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30946U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aEarthLaneC[((aIndex + 27882U)) & S_BLOCK1], 40U);

            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GROW_B grow_key_b (end)
    
}
