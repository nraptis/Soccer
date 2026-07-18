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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = RotL64(aSource[((aIndex + 2435U)) & S_BLOCK1], 12U) ^ RotL64(pSnow[((aIndex + 4308U)) & S_BLOCK1], 53U);

            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 1438U)) & S_BLOCK1], 27U) ^ RotL64(aSource[((S_BLOCK1 - aIndex + 2646U)) & S_BLOCK1], 48U);

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
            aIngress = RotL64(aScrapLaneA[((aIndex + 8341U)) & S_BLOCK1], 4U) ^ RotL64(aSource[((aIndex + 6217U)) & S_BLOCK1], 13U);

            //
            aCross = RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 10699U)) & S_BLOCK1], 19U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 6731U)) & S_BLOCK1], 41U);

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
            aIngress = RotL64(aScrapLaneB[((aIndex + 13117U)) & S_BLOCK1], 41U) ^ RotL64(aSource[((S_BLOCK1 - aIndex + 16196U)) & S_BLOCK1], 28U);

            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 14392U)) & S_BLOCK1], 53U) ^ RotL64(aScrapLaneA[((aIndex + 11126U)) & S_BLOCK1], 14U);

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
            aIngress = RotL64(aEarthLaneA[((aIndex + 20118U)) & S_BLOCK1], 11U) ^ RotL64(aScrapLaneB[((aIndex + 17231U)) & S_BLOCK1], 36U);

            //
            aCross = RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 20914U)) & S_BLOCK1], 3U) ^ RotL64(aSource[((aIndex + 16624U)) & S_BLOCK1], 19U);

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
            aIngress = RotL64(aEarthLaneB[((aIndex + 26340U)) & S_BLOCK1], 20U) ^ RotL64(aScrapLaneB[((aIndex + 25485U)) & S_BLOCK1], 29U);

            //
            aCross = RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 25779U)) & S_BLOCK1], 57U) ^ RotL64(pSnow[((aIndex + 23509U)) & S_BLOCK1], 27U);

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
            aIngress = RotL64(aEarthLaneC[((aIndex + 28038U)) & S_BLOCK1], 19U) ^ RotL64(aEarthLaneA[((aIndex + 29721U)) & S_BLOCK1], 42U);

            //
            aCross = RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 32177U)) & S_BLOCK1], 23U) ^ RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 32659U)) & S_BLOCK1], 4U);

            aEarthLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_A kdf_a_loop_a (end)

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneA[((aIndex + 6825U)) & S_BLOCK1], 13U) ^ RotL64(aEarthLaneB[((aIndex + 3318U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(pSnow[((S_BLOCK1 - aIndex + 4092U)) & S_BLOCK1], 3U);

            //
            aCross = RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 1643U)) & S_BLOCK1], 30U) ^ RotL64(aEarthLaneD[((aIndex + 2557U)) & S_BLOCK1], 39U);

            aFireLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFireLaneA[((aIndex + 9357U)) & S_BLOCK1], 57U) ^ RotL64(aEarthLaneC[((aIndex + 16138U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aSource[((aIndex + 10060U)) & S_BLOCK1], 43U);

            //
            aCross = RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 9041U)) & S_BLOCK1], 28U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 9782U)) & S_BLOCK1], 41U);

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
            aIngress = (RotL64(aFireLaneB[((aIndex + 20047U)) & S_BLOCK1], 39U) ^ RotL64(aEarthLaneD[((aIndex + 16644U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 19821U)) & S_BLOCK1], 51U);

            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18191U)) & S_BLOCK1], 29U) ^ RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 16472U)) & S_BLOCK1], 53U);

            aFireLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFireLaneC[((aIndex + 26285U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneA[((aIndex + 27023U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 26679U)) & S_BLOCK1], 13U);

            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 24803U)) & S_BLOCK1], 21U) ^ RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 32023U)) & S_BLOCK1], 29U);

            aFireLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_B kdf_a_loop_b (end)

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFireLaneA[((aIndex + 4486U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneB[((aIndex + 1172U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 6753U)) & S_BLOCK1], 35U);

            //
            aCross = (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 3694U)) & S_BLOCK1], 40U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 5766U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 6081U)) & S_BLOCK1], 21U);

            aOperationLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 14992U)) & S_BLOCK1], 14U) ^ RotL64(aFireLaneC[((aIndex + 15134U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aSource[((S_BLOCK1 - aIndex + 10242U)) & S_BLOCK1], 41U);

            //
            aCross = (RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11782U)) & S_BLOCK1], 52U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 14100U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 9539U)) & S_BLOCK1], 19U);

            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 19331U)) & S_BLOCK1], 10U) ^ RotL64(aFireLaneD[((aIndex + 22822U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 18747U)) & S_BLOCK1], 57U);

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24034U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 22275U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 19637U)) & S_BLOCK1], 29U);

            aOperationLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28114U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 25353U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 29896U)) & S_BLOCK1], 5U);

            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25556U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 27450U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(pSnow[((aIndex + 27116U)) & S_BLOCK1], 47U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_C kdf_a_loop_c (end)

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5765U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 8129U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 5193U)) & S_BLOCK1], 23U) ^ RotL64(aEarthLaneB[((aIndex + 8021U)) & S_BLOCK1], 4U));

            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 983U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6003U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 2641U)) & S_BLOCK1], 4U);

            aFuseLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneA[((aIndex + 11783U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 14963U)) & S_BLOCK1], 18U));
            aIngress ^= (RotL64(aFireLaneC[((aIndex + 15450U)) & S_BLOCK1], 47U) ^ RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 11196U)) & S_BLOCK1], 37U));

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11439U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9075U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 8218U)) & S_BLOCK1], 54U);

            aFuseLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneB[((aIndex + 17431U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((aIndex + 19509U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(pSnow[((aIndex + 20098U)) & S_BLOCK1], 21U) ^ RotL64(aSource[((S_BLOCK1 - aIndex + 21809U)) & S_BLOCK1], 47U));

            //
            aCross = (RotL64(aFuseLaneA[((S_BLOCK1 - aIndex + 23224U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23817U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 18790U)) & S_BLOCK1], 23U);

            aFuseLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 26635U)) & S_BLOCK1], 39U) ^ RotL64(aFuseLaneA[((aIndex + 32272U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aEarthLaneD[((aIndex + 28812U)) & S_BLOCK1], 57U) ^ RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 30700U)) & S_BLOCK1], 19U));

            //
            aCross = (RotL64(aFuseLaneB[((S_BLOCK1 - aIndex + 27921U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 28790U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 31686U)) & S_BLOCK1], 51U);

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_D kdf_a_loop_d (end)

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWindLaneA[((aIndex + 7503U)) & S_BLOCK1], 29U) ^ RotL64(aWindLaneB[((aIndex + 608U)) & S_BLOCK1], 42U));
            aIngress ^= (RotL64(aEarthLaneA[((aIndex + 3432U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 6498U)) & S_BLOCK1], 13U));

            //
            aCross = (RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 5433U)) & S_BLOCK1], 11U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 6631U)) & S_BLOCK1], 30U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7393U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneD[((aIndex + 2805U)) & S_BLOCK1], 47U));

            aWaterLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneA[((aIndex + 15724U)) & S_BLOCK1], 29U) ^ RotL64(aWindLaneC[((aIndex + 8577U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 10958U)) & S_BLOCK1], 21U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 11052U)) & S_BLOCK1], 42U));

            //
            aCross = (RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 15154U)) & S_BLOCK1], 57U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 12691U)) & S_BLOCK1], 39U));
            aCross ^= (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8604U)) & S_BLOCK1], 11U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 15953U)) & S_BLOCK1], 3U));

            aWaterLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneB[((aIndex + 20215U)) & S_BLOCK1], 23U) ^ RotL64(aWindLaneD[((aIndex + 19252U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aFireLaneC[((aIndex + 18523U)) & S_BLOCK1], 46U) ^ RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 23185U)) & S_BLOCK1], 13U));

            //
            aCross = (RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 20218U)) & S_BLOCK1], 39U) ^ RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 21778U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 21668U)) & S_BLOCK1], 51U);

            aWaterLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneC[((aIndex + 30924U)) & S_BLOCK1], 11U) ^ RotL64(aWaterLaneA[((aIndex + 26256U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aSource[((aIndex + 25072U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 24926U)) & S_BLOCK1], 57U));

            //
            aCross = (RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 29371U)) & S_BLOCK1], 39U) ^ RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 25059U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 30052U)) & S_BLOCK1], 13U);

            aWaterLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_E kdf_a_loop_e (end)

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneA[((aIndex + 4452U)) & S_BLOCK1], 11U) ^ RotL64(aWaterLaneB[((aIndex + 406U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aWindLaneD[((aIndex + 4524U)) & S_BLOCK1], 37U) ^ RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 2018U)) & S_BLOCK1], 57U));

            //
            aCross = (RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 1916U)) & S_BLOCK1], 57U) ^ RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 2688U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 6214U)) & S_BLOCK1], 13U);

            aScrapLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneA[((aIndex + 16228U)) & S_BLOCK1], 51U) ^ RotL64(aWaterLaneC[((aIndex + 12655U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 12905U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11381U)) & S_BLOCK1], 5U));

            //
            aCross = (RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 11329U)) & S_BLOCK1], 27U) ^ RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 13123U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aSource[((aIndex + 14694U)) & S_BLOCK1], 19U);

            aScrapLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneB[((aIndex + 22473U)) & S_BLOCK1], 21U) ^ RotL64(aWaterLaneD[((aIndex + 22173U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aWindLaneA[((aIndex + 21940U)) & S_BLOCK1], 44U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 16586U)) & S_BLOCK1], 57U));

            //
            aCross = (RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 23089U)) & S_BLOCK1], 37U) ^ RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 20722U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16870U)) & S_BLOCK1], 5U);

            aScrapLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneC[((aIndex + 30599U)) & S_BLOCK1], 57U) ^ RotL64(aScrapLaneA[((aIndex + 31736U)) & S_BLOCK1], 4U));
            aIngress ^= (RotL64(aWindLaneC[((aIndex + 31859U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25334U)) & S_BLOCK1], 35U));

            //
            aCross = (RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 31373U)) & S_BLOCK1], 43U) ^ RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 31184U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 25130U)) & S_BLOCK1], 3U);

            aScrapLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_A kdf_b_loop_a (end)

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneA[((aIndex + 6387U)) & S_BLOCK1], 35U) ^ RotL64(aScrapLaneB[((aIndex + 1151U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aSource[((aIndex + 6447U)) & S_BLOCK1], 53U) ^ RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 7188U)) & S_BLOCK1], 26U));

            //
            aCross = (RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 6479U)) & S_BLOCK1], 13U) ^ RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 120U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 6910U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1171U)) & S_BLOCK1], 39U));

            aOperationLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 12879U)) & S_BLOCK1], 57U) ^ RotL64(aScrapLaneC[((aIndex + 13288U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aWindLaneC[((aIndex + 16089U)) & S_BLOCK1], 43U) ^ RotL64(aWaterLaneA[((aIndex + 8501U)) & S_BLOCK1], 5U));

            //
            aCross = (RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 8536U)) & S_BLOCK1], 43U) ^ RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 10505U)) & S_BLOCK1], 56U));
            aCross ^= (RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 9784U)) & S_BLOCK1], 21U) ^ RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 15565U)) & S_BLOCK1], 5U));

            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24047U)) & S_BLOCK1], 43U) ^ RotL64(aScrapLaneD[((aIndex + 20688U)) & S_BLOCK1], 4U));
            aIngress ^= (RotL64(aEarthLaneA[((aIndex + 22905U)) & S_BLOCK1], 29U) ^ RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 17845U)) & S_BLOCK1], 19U));

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17775U)) & S_BLOCK1], 47U) ^ RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 23677U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWindLaneA[((aIndex + 19204U)) & S_BLOCK1], 56U);

            aOperationLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27860U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneA[((aIndex + 30729U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aWaterLaneD[((aIndex + 31767U)) & S_BLOCK1], 5U) ^ RotL64(aEarthLaneB[((aIndex + 30756U)) & S_BLOCK1], 43U));

            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32081U)) & S_BLOCK1], 5U) ^ RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 31815U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 29915U)) & S_BLOCK1], 30U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_B kdf_b_loop_b (end)

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1202U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 2823U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 6882U)) & S_BLOCK1], 22U) ^ RotL64(aWindLaneC[((aIndex + 5264U)) & S_BLOCK1], 53U));

            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2148U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8106U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 1920U)) & S_BLOCK1], 35U) ^ RotL64(aScrapLaneB[((aIndex + 3083U)) & S_BLOCK1], 4U));

            aFuseLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneA[((aIndex + 13024U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 15690U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aScrapLaneA[((aIndex + 14690U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneB[((aIndex + 8694U)) & S_BLOCK1], 3U));

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16059U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15646U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 16341U)) & S_BLOCK1], 13U) ^ RotL64(aScrapLaneD[((aIndex + 10463U)) & S_BLOCK1], 23U));

            aFuseLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneB[((aIndex + 17760U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneD[((aIndex + 23970U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aWaterLaneB[((aIndex + 18623U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 19549U)) & S_BLOCK1], 57U));

            //
            aCross = (RotL64(aFuseLaneA[((S_BLOCK1 - aIndex + 20381U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22119U)) & S_BLOCK1], 53U));
            aCross ^= (RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 22110U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23146U)) & S_BLOCK1], 35U));

            aFuseLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 28179U)) & S_BLOCK1], 43U) ^ RotL64(aFuseLaneA[((aIndex + 29698U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aWindLaneD[((aIndex + 28459U)) & S_BLOCK1], 26U) ^ RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 32438U)) & S_BLOCK1], 35U));

            //
            aCross = (RotL64(aFuseLaneB[((S_BLOCK1 - aIndex + 25131U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 27330U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 25430U)) & S_BLOCK1], 13U) ^ RotL64(aWindLaneB[((aIndex + 25046U)) & S_BLOCK1], 38U));

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_C kdf_b_loop_c (end)

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2846U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 4937U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aScrapLaneA[((aIndex + 2179U)) & S_BLOCK1], 40U) ^ RotL64(aWaterLaneA[((aIndex + 6478U)) & S_BLOCK1], 53U));

            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3259U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5646U)) & S_BLOCK1], 21U));
            aCross ^= (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3092U)) & S_BLOCK1], 41U) ^ RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 1975U)) & S_BLOCK1], 29U));

            aExpandLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10906U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneC[((aIndex + 13046U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aWindLaneC[((aIndex + 10325U)) & S_BLOCK1], 5U) ^ RotL64(aWaterLaneD[((aIndex + 15010U)) & S_BLOCK1], 19U));

            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14408U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8365U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8586U)) & S_BLOCK1], 14U) ^ RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 11563U)) & S_BLOCK1], 37U));

            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17832U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneD[((aIndex + 23759U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aScrapLaneD[((aIndex + 16645U)) & S_BLOCK1], 27U) ^ RotL64(aSource[((S_BLOCK1 - aIndex + 22853U)) & S_BLOCK1], 35U));

            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20805U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19539U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 19999U)) & S_BLOCK1], 37U) ^ RotL64(aWaterLaneB[((aIndex + 23742U)) & S_BLOCK1], 3U));

            aExpandLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29059U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneA[((aIndex + 27158U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aWaterLaneC[((aIndex + 30542U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 26118U)) & S_BLOCK1], 35U));

            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25178U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25801U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 31213U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31803U)) & S_BLOCK1], 13U));

            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_D kdf_b_loop_d (end)

}

void TwistExpander_Antares_Arx::Seed_A() {
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
            aIngress = RotL64(aSource[((aIndex + 2238U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 3933U)) & W_KEY1], 47U);

            //
            aCross = RotL64(aSource[((S_BLOCK1 - aIndex + 3791U)) & S_BLOCK1], 56U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 1464U)) & W_KEY1], 29U);

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
            aIngress = RotL64(aWorkLaneA[((aIndex + 9217U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadB[((aIndex + 6086U)) & W_KEY1], 20U);

            //
            aCross = RotL64(aSource[((S_BLOCK1 - aIndex + 5848U)) & S_BLOCK1], 28U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 9412U)) & W_KEY1], 13U);

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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 13149U)) & S_BLOCK1], 27U) ^ RotL64(aSource[((aIndex + 12886U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aKeyRowReadB[((aIndex + 14630U)) & W_KEY1], 19U);

            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 13188U)) & W_KEY1], 38U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14965U)) & S_BLOCK1], 3U);

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
            aIngress = RotL64(aExpandLaneA[((aIndex + 21829U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18364U)) & S_BLOCK1], 51U);

            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21457U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21844U)) & W_KEY1], 23U);

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
            aIngress = RotL64(aExpandLaneB[((aIndex + 26629U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((aIndex + 23338U)) & S_BLOCK1], 57U);

            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26918U)) & S_BLOCK1], 28U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 25519U)) & W_KEY1], 5U);

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
            aIngress = RotL64(aExpandLaneC[((aIndex + 28318U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28875U)) & S_BLOCK1], 19U);

            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31259U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29375U)) & S_BLOCK1], 13U);

            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_A seed_loop_a (end)

}

void TwistExpander_Antares_Arx::Seed_B() {
    const std::uint64_t &aPhaseADomainWordIngress = pWorkSpace->mDomainBundle.mPhaseAConstants.mIngress;
    const std::uint64_t &aPhaseADomainWordScatter = pWorkSpace->mDomainBundle.mPhaseAConstants.mScatter;
    const std::uint64_t &aPhaseADomainWordCross = pWorkSpace->mDomainBundle.mPhaseAConstants.mCross;
    const std::uint64_t &aPhaseBDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseBConstants.mIngress;
    const std::uint64_t &aPhaseBDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseBConstants.mScatter;
    const std::uint64_t &aPhaseBDomainWordCross = pWorkSpace->mDomainBundle.mPhaseBConstants.mCross;
    const std::uint64_t &aPhaseCDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseCConstants.mIngress;
    const std::uint64_t &aPhaseCDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseCConstants.mScatter;
    const std::uint64_t &aPhaseCDomainWordCross = pWorkSpace->mDomainBundle.mPhaseCConstants.mCross;
    const std::uint64_t &aPhaseFDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseFConstants.mIngress;
    const std::uint64_t &aPhaseFDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseFConstants.mScatter;
    const std::uint64_t &aPhaseFDomainWordCross = pWorkSpace->mDomainBundle.mPhaseFConstants.mCross;
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5009U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 4716U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aKeyRowReadB[((aIndex + 3474U)) & W_KEY1], 39U);

            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2749U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 1484U)) & S_BLOCK1], 13U);

            aWorkLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 9569U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 6473U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9076U)) & S_BLOCK1], 41U);

            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10445U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7111U)) & S_BLOCK1], 3U);

            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneD[((aIndex + 15892U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 11366U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aKeyRowReadA[((aIndex + 11949U)) & W_KEY1], 51U);

            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15165U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 11157U)) & S_BLOCK1], 52U);

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
            aIngress = (RotL64(aEarthLaneA[((aIndex + 16646U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((aIndex + 16495U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17802U)) & S_BLOCK1], 19U);

            //
            aCross = RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20745U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 19892U)) & S_BLOCK1], 48U);

            aEarthLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneB[((aIndex + 26454U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((aIndex + 25698U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aSource[((S_BLOCK1 - aIndex + 25129U)) & S_BLOCK1], 23U);

            //
            aCross = RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 22334U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 21909U)) & S_BLOCK1], 30U);

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
            aIngress = RotL64(aEarthLaneC[((aIndex + 30363U)) & S_BLOCK1], 5U) ^ RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 29158U)) & S_BLOCK1], 36U);

            //
            aCross = RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 30089U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32136U)) & S_BLOCK1], 41U);

            aEarthLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_B seed_loop_e (end)

}

void TwistExpander_Antares_Arx::Seed_C() {
    const std::uint64_t &aPhaseBDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseBConstants.mIngress;
    const std::uint64_t &aPhaseBDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseBConstants.mScatter;
    const std::uint64_t &aPhaseBDomainWordCross = pWorkSpace->mDomainBundle.mPhaseBConstants.mCross;
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneA[((aIndex + 1671U)) & S_BLOCK1], 35U) ^ RotL64(aEarthLaneB[((aIndex + 3994U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 2701U)) & S_BLOCK1], 47U);

            //
            aCross = (RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 3842U)) & S_BLOCK1], 5U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 4318U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 5095U)) & S_BLOCK1], 27U);

            aScrapLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneA[((aIndex + 6562U)) & S_BLOCK1], 37U) ^ RotL64(aEarthLaneC[((aIndex + 7104U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 6357U)) & S_BLOCK1], 29U);

            //
            aCross = (RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 6131U)) & S_BLOCK1], 13U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 7954U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9678U)) & S_BLOCK1], 58U);

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
            aIngress = (RotL64(aScrapLaneB[((aIndex + 13007U)) & S_BLOCK1], 53U) ^ RotL64(aEarthLaneA[((aIndex + 15290U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aSource[((aIndex + 16040U)) & S_BLOCK1], 11U);

            //
            aCross = (RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 12521U)) & S_BLOCK1], 51U) ^ RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 14787U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14531U)) & S_BLOCK1], 14U);

            aOperationLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21370U)) & S_BLOCK1], 6U) ^ RotL64(aEarthLaneD[((aIndex + 21461U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18497U)) & S_BLOCK1], 39U);

            //
            aCross = RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 18373U)) & S_BLOCK1], 39U) ^ RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 19596U)) & S_BLOCK1], 29U);

            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25423U)) & S_BLOCK1], 3U) ^ RotL64(aScrapLaneB[((aIndex + 24385U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 26558U)) & S_BLOCK1], 53U);

            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25672U)) & S_BLOCK1], 35U) ^ RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 27121U)) & S_BLOCK1], 19U);

            aOperationLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27519U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 31606U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27585U)) & S_BLOCK1], 18U);

            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28153U)) & S_BLOCK1], 54U) ^ RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 30666U)) & S_BLOCK1], 43U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_C seed_loop_d (end)

}

void TwistExpander_Antares_Arx::Seed_D() {
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4720U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneB[((aIndex + 4207U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 5267U)) & S_BLOCK1], 11U);

            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3144U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1197U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 4526U)) & S_BLOCK1], 51U);

            aScrapLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneC[((aIndex + 8012U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 10111U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 6299U)) & S_BLOCK1], 39U);

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9461U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6417U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aScrapLaneB[((aIndex + 5796U)) & S_BLOCK1], 51U);

            aScrapLaneD[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneD[((aIndex + 14020U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 11932U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aEarthLaneA[((aIndex + 14514U)) & S_BLOCK1], 39U);

            //
            aCross = (RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 15256U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15090U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aKeyRowReadA[(((2047U - aIndex) + 11552U)) & W_KEY1], 53U);

            aFuseLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneA[((aIndex + 18029U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((aIndex + 19820U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20959U)) & S_BLOCK1], 39U);

            //
            aCross = (RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 16520U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18017U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21060U)) & S_BLOCK1], 13U);

            aFuseLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneB[((aIndex + 24461U)) & S_BLOCK1], 56U) ^ RotL64(aScrapLaneD[((aIndex + 23768U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aEarthLaneD[((aIndex + 24526U)) & S_BLOCK1], 35U);

            //
            aCross = (RotL64(aFuseLaneA[((S_BLOCK1 - aIndex + 22365U)) & S_BLOCK1], 26U) ^ RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 23029U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aEarthLaneB[((aIndex + 26745U)) & S_BLOCK1], 47U);

            aFuseLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 30423U)) & S_BLOCK1], 3U) ^ RotL64(aFuseLaneA[((aIndex + 28955U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 32243U)) & S_BLOCK1], 47U);

            //
            aCross = (RotL64(aFuseLaneB[((S_BLOCK1 - aIndex + 31191U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27889U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 27429U)) & S_BLOCK1], 41U);

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_D seed_loop_c (end)

}

void TwistExpander_Antares_Arx::Seed_E() {
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
        //      aFireLaneA (-->), aFireLaneB (-->), aEarthLaneC (-->), aKeyRowReadB (<-?->)
        //
        // Cross:
        //      aFireLaneC (<--), aFireLaneD (<--), aScrapLaneC (<-?->)
        //
        // Destination:
        //      aWaterLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFireLaneA[((aIndex + 1231U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneB[((aIndex + 4125U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aEarthLaneC[((aIndex + 2626U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 2352U)) & W_KEY1], 26U));

            //
            aCross = (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 4437U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 3039U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 4869U)) & S_BLOCK1], 5U);

            aWaterLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneC[((aIndex + 5521U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 10597U)) & S_BLOCK1], 40U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 8320U)) & S_BLOCK1], 3U) ^ RotL64(aScrapLaneD[((aIndex + 5973U)) & S_BLOCK1], 57U));

            //
            aCross = (RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7130U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10794U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 7279U)) & S_BLOCK1], 41U);

            aWaterLaneD[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneD[((aIndex + 13802U)) & S_BLOCK1], 40U) ^ RotL64(aFireLaneA[((aIndex + 15422U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11249U)) & S_BLOCK1], 27U);

            //
            aCross = (RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 12858U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15130U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12397U)) & S_BLOCK1], 21U);

            aInvestLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 19661U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneD[((aIndex + 16668U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 19722U)) & S_BLOCK1], 11U);

            //
            aCross = (RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 19429U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16756U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 16634U)) & S_BLOCK1], 3U);

            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 25344U)) & S_BLOCK1], 5U) ^ RotL64(aWaterLaneD[((aIndex + 24317U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24798U)) & S_BLOCK1], 27U);

            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22180U)) & S_BLOCK1], 13U) ^ RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 25434U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 22866U)) & S_BLOCK1], 51U);

            aInvestLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 29219U)) & S_BLOCK1], 14U) ^ RotL64(aInvestLaneA[((aIndex + 27994U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aEarthLaneB[((aIndex + 28569U)) & S_BLOCK1], 3U);

            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29235U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 30396U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 32251U)) & S_BLOCK1], 11U);

            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_E seed_loop_b (end)

}

void TwistExpander_Antares_Arx::Seed_F() {
    const std::uint64_t &aPhaseADomainWordIngress = pWorkSpace->mDomainBundle.mPhaseAConstants.mIngress;
    const std::uint64_t &aPhaseADomainWordScatter = pWorkSpace->mDomainBundle.mPhaseAConstants.mScatter;
    const std::uint64_t &aPhaseADomainWordCross = pWorkSpace->mDomainBundle.mPhaseAConstants.mCross;
    const std::uint64_t &aPhaseCDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseCConstants.mIngress;
    const std::uint64_t &aPhaseCDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseCConstants.mScatter;
    const std::uint64_t &aPhaseCDomainWordCross = pWorkSpace->mDomainBundle.mPhaseCConstants.mCross;
    const std::uint64_t &aPhaseDDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseDConstants.mIngress;
    const std::uint64_t &aPhaseDDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseDConstants.mScatter;
    const std::uint64_t &aPhaseDDomainWordCross = pWorkSpace->mDomainBundle.mPhaseDConstants.mCross;
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 2557U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneB[((aIndex + 4107U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 5060U)) & S_BLOCK1], 13U) ^ RotL64(aEarthLaneD[((aIndex + 2969U)) & S_BLOCK1], 43U));

            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 3792U)) & S_BLOCK1], 54U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 933U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 3724U)) & S_BLOCK1], 43U);

            aSnowLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 5937U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneC[((aIndex + 8810U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 7076U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneA[((aIndex + 7975U)) & S_BLOCK1], 13U));

            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 6763U)) & S_BLOCK1], 44U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 6931U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aScrapLaneA[((aIndex + 7889U)) & S_BLOCK1], 19U);

            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 16357U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneA[((aIndex + 12941U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aScrapLaneD[((aIndex + 13831U)) & S_BLOCK1], 39U) ^ RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 16147U)) & S_BLOCK1], 58U));

            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 11785U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11897U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 16116U)) & S_BLOCK1], 44U);

            aWindLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWindLaneA[((aIndex + 17856U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneD[((aIndex + 16497U)) & S_BLOCK1], 14U));
            aIngress ^= (RotL64(aScrapLaneC[((aIndex + 18083U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20637U)) & S_BLOCK1], 29U));

            //
            aCross = (RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 18398U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 21105U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21000U)) & S_BLOCK1], 47U);

            aWindLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWindLaneB[((aIndex + 24095U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneD[((aIndex + 22448U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aSource[((aIndex + 26914U)) & S_BLOCK1], 24U);

            //
            aCross = (RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 26384U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 22237U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25476U)) & S_BLOCK1], 43U);

            aWindLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWindLaneC[((aIndex + 32394U)) & S_BLOCK1], 53U) ^ RotL64(aWindLaneA[((aIndex + 27862U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 27634U)) & S_BLOCK1], 23U);

            //
            aCross = (RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 28012U)) & S_BLOCK1], 56U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 32329U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 32021U)) & S_BLOCK1], 39U);

            aWindLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_F seed_loop_c (end)

}

void TwistExpander_Antares_Arx::Seed_G() {
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWindLaneA[((aIndex + 2831U)) & S_BLOCK1], 12U) ^ RotL64(aWindLaneB[((aIndex + 76U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aWaterLaneC[((aIndex + 1245U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1849U)) & S_BLOCK1], 57U));

            //
            aCross = (RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 1107U)) & S_BLOCK1], 39U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 2815U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 1657U)) & S_BLOCK1], 5U);

            aWaterLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneA[((aIndex + 5602U)) & S_BLOCK1], 6U) ^ RotL64(aWindLaneC[((aIndex + 9520U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aEarthLaneB[((aIndex + 10225U)) & S_BLOCK1], 35U) ^ RotL64(aWaterLaneD[((aIndex + 10616U)) & S_BLOCK1], 19U));

            //
            aCross = (RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 6590U)) & S_BLOCK1], 13U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 8494U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 6284U)) & S_BLOCK1], 3U);

            aWaterLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneB[((aIndex + 13307U)) & S_BLOCK1], 4U) ^ RotL64(aWindLaneA[((aIndex + 11079U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aInvestLaneA[((aIndex + 15715U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneD[((aIndex + 11384U)) & S_BLOCK1], 39U));

            //
            aCross = (RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 11251U)) & S_BLOCK1], 42U) ^ RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 13996U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 15304U)) & S_BLOCK1], 19U);

            aOperationLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16661U)) & S_BLOCK1], 50U) ^ RotL64(aWindLaneD[((aIndex + 19544U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aEarthLaneA[((aIndex + 17083U)) & S_BLOCK1], 39U) ^ RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 21818U)) & S_BLOCK1], 3U));

            //
            aCross = (RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 21004U)) & S_BLOCK1], 19U) ^ RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 16747U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 21148U)) & S_BLOCK1], 5U);

            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25307U)) & S_BLOCK1], 14U) ^ RotL64(aWaterLaneB[((aIndex + 22321U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aFireLaneB[((aIndex + 24156U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 25347U)) & W_KEY1], 5U));

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26861U)) & S_BLOCK1], 3U) ^ RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 25947U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 25431U)) & S_BLOCK1], 51U);

            aOperationLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29184U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 31583U)) & S_BLOCK1], 38U));
            aIngress ^= (RotL64(aEarthLaneC[((aIndex + 31110U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30996U)) & S_BLOCK1], 53U));

            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28069U)) & S_BLOCK1], 37U) ^ RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 30121U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 30321U)) & S_BLOCK1], 10U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_G seed_loop_d (end)

}

void TwistExpander_Antares_Arx::Seed_H() {
    const std::uint64_t &aPhaseCDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseCConstants.mIngress;
    const std::uint64_t &aPhaseCDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseCConstants.mScatter;
    const std::uint64_t &aPhaseCDomainWordCross = pWorkSpace->mDomainBundle.mPhaseCConstants.mCross;
    const std::uint64_t &aPhaseDDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseDConstants.mIngress;
    const std::uint64_t &aPhaseDDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseDConstants.mScatter;
    const std::uint64_t &aPhaseDDomainWordCross = pWorkSpace->mDomainBundle.mPhaseDConstants.mCross;
    const std::uint64_t &aPhaseEDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseEConstants.mIngress;
    const std::uint64_t &aPhaseEDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseEConstants.mScatter;
    const std::uint64_t &aPhaseEDomainWordCross = pWorkSpace->mDomainBundle.mPhaseEConstants.mCross;
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
        //      aOperationLaneA (-->), aOperationLaneB (-->), aFireLaneB (-->), aWindLaneD (<-?->)
        //
        // Cross:
        //      aOperationLaneC (<--), aOperationLaneD (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aSnowLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3359U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 4732U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aFireLaneB[((aIndex + 2775U)) & S_BLOCK1], 5U) ^ RotL64(aWindLaneD[((aIndex + 5053U)) & S_BLOCK1], 43U));

            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2371U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2665U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 2470U)) & S_BLOCK1], 11U);

            aSnowLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6283U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 9936U)) & S_BLOCK1], 18U));
            aIngress ^= (RotL64(aWaterLaneB[((aIndex + 8355U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 8210U)) & S_BLOCK1], 41U));

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9994U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6786U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 10100U)) & S_BLOCK1], 35U);

            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 13272U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 15005U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 14798U)) & W_KEY1], 36U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 11307U)) & S_BLOCK1], 23U));

            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 15289U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13150U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12904U)) & S_BLOCK1], 13U);

            aFuseLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneA[((aIndex + 17485U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((aIndex + 16566U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aWaterLaneA[((aIndex + 18912U)) & S_BLOCK1], 13U) ^ RotL64(aWindLaneA[((aIndex + 20567U)) & S_BLOCK1], 22U));

            //
            aCross = (RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 21204U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19986U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aInvestLaneC[((aIndex + 21510U)) & S_BLOCK1], 3U);

            aFuseLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneB[((aIndex + 25080U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneB[((aIndex + 23146U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWindLaneB[((aIndex + 24986U)) & S_BLOCK1], 20U);

            //
            aCross = (RotL64(aFuseLaneA[((S_BLOCK1 - aIndex + 27189U)) & S_BLOCK1], 24U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 24683U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 25475U)) & S_BLOCK1], 51U);

            aFuseLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 30867U)) & S_BLOCK1], 21U) ^ RotL64(aFuseLaneA[((aIndex + 28735U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aSnowLaneD[((aIndex + 32293U)) & S_BLOCK1], 29U);

            //
            aCross = (RotL64(aFuseLaneB[((S_BLOCK1 - aIndex + 32651U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31763U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 31327U)) & S_BLOCK1], 51U);

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_H seed_loop_e (end)

}

void TwistExpander_Antares_Arx::Seed_I() {
    const std::uint64_t &aPhaseADomainWordIngress = pWorkSpace->mDomainBundle.mPhaseAConstants.mIngress;
    const std::uint64_t &aPhaseADomainWordScatter = pWorkSpace->mDomainBundle.mPhaseAConstants.mScatter;
    const std::uint64_t &aPhaseADomainWordCross = pWorkSpace->mDomainBundle.mPhaseAConstants.mCross;
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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneE[((aIndex + 3749U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneF[((aIndex + 5071U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aWaterLaneB[((aIndex + 828U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 3483U)) & S_BLOCK1], 29U));

            //
            aCross = (RotL64(aInvestLaneG[((S_BLOCK1 - aIndex + 4515U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneH[((S_BLOCK1 - aIndex + 2796U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 599U)) & S_BLOCK1], 27U);

            aSnowLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 10161U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneG[((aIndex + 8696U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aWindLaneD[((aIndex + 10802U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10391U)) & S_BLOCK1], 60U));

            //
            aCross = (RotL64(aInvestLaneE[((S_BLOCK1 - aIndex + 9391U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneH[((S_BLOCK1 - aIndex + 6147U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 6930U)) & S_BLOCK1], 56U);

            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 15677U)) & S_BLOCK1], 56U) ^ RotL64(aInvestLaneE[((aIndex + 14571U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aFireLaneC[((aIndex + 11785U)) & S_BLOCK1], 3U) ^ RotL64(aWindLaneC[((aIndex + 15368U)) & S_BLOCK1], 35U));

            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 15911U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneG[((S_BLOCK1 - aIndex + 15653U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWaterLaneA[((aIndex + 13280U)) & S_BLOCK1], 6U);

            aWorkLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 18325U)) & S_BLOCK1], 50U) ^ RotL64(aInvestLaneH[((aIndex + 20047U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aSnowLaneA[((aIndex + 18729U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 21080U)) & S_BLOCK1], 27U));

            //
            aCross = (RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 17481U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneE[((S_BLOCK1 - aIndex + 16808U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 18706U)) & S_BLOCK1], 50U);

            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22134U)) & S_BLOCK1], 60U) ^ RotL64(aSnowLaneD[((aIndex + 22184U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 27245U)) & S_BLOCK1], 37U);

            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23973U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 25186U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 25372U)) & S_BLOCK1], 11U);

            aWorkLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31688U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 32052U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 30973U)) & S_BLOCK1], 3U);

            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29968U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneF[((S_BLOCK1 - aIndex + 31566U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30012U)) & S_BLOCK1], 3U);

            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_I seed_loop_f (end)

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = RotL64(aSource[((aIndex + 3834U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[((aIndex + 1665U)) & W_KEY1], 12U);

            //
            aCross = RotL64(aSource[((S_BLOCK1 - aIndex + 4699U)) & S_BLOCK1], 42U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 3938U)) & W_KEY1], 19U);

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
            aIngress = RotL64(aScrapLaneA[((aIndex + 9067U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadB[((aIndex + 8719U)) & W_KEY1], 12U);

            //
            aCross = RotL64(aSource[((S_BLOCK1 - aIndex + 6077U)) & S_BLOCK1], 56U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 10296U)) & W_KEY1], 41U);

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
            aIngress = (RotL64(aScrapLaneB[((aIndex + 12670U)) & S_BLOCK1], 35U) ^ RotL64(aSource[((aIndex + 15391U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aKeyRowReadB[((aIndex + 13737U)) & W_KEY1], 19U);

            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 15196U)) & W_KEY1], 36U) ^ RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 13561U)) & S_BLOCK1], 11U);

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
            aIngress = RotL64(aWindLaneA[((aIndex + 16880U)) & S_BLOCK1], 27U) ^ RotL64(aScrapLaneA[((aIndex + 18455U)) & S_BLOCK1], 10U);

            //
            aCross = RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 20302U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20282U)) & W_KEY1], 4U);

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
            aIngress = RotL64(aWindLaneB[((aIndex + 22416U)) & S_BLOCK1], 39U) ^ RotL64(aScrapLaneB[((aIndex + 25092U)) & S_BLOCK1], 48U);

            //
            aCross = RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 23571U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadA[((aIndex + 26327U)) & W_KEY1], 24U);

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
            aIngress = RotL64(aWindLaneC[((aIndex + 30276U)) & S_BLOCK1], 40U) ^ RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 28062U)) & S_BLOCK1], 27U);

            //
            aCross = RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 29756U)) & S_BLOCK1], 40U) ^ RotL64(aScrapLaneB[((aIndex + 31810U)) & S_BLOCK1], 11U);

            aWindLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_A twist_loop_a (end)

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWindLaneA[((aIndex + 4574U)) & S_BLOCK1], 6U) ^ RotL64(aWindLaneB[((aIndex + 1919U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aKeyRowReadB[((aIndex + 2253U)) & W_KEY1], 57U);

            //
            aCross = RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 3832U)) & S_BLOCK1], 18U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 287U)) & S_BLOCK1], 53U);

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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8186U)) & S_BLOCK1], 37U) ^ RotL64(aWindLaneC[((aIndex + 8112U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aScrapLaneA[((aIndex + 8874U)) & S_BLOCK1], 50U);

            //
            aCross = RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 10146U)) & S_BLOCK1], 57U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 9364U)) & S_BLOCK1], 6U);

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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16178U)) & S_BLOCK1], 35U) ^ RotL64(aWindLaneA[((aIndex + 15295U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aKeyRowReadA[(((2047U - aIndex) + 10970U)) & W_KEY1], 13U);

            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12676U)) & S_BLOCK1], 30U) ^ RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 11671U)) & S_BLOCK1], 51U);

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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 18737U)) & S_BLOCK1], 39U) ^ RotL64(aWindLaneD[((aIndex + 19730U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 18544U)) & S_BLOCK1], 57U);

            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20921U)) & S_BLOCK1], 50U) ^ RotL64(aWindLaneA[((aIndex + 17562U)) & S_BLOCK1], 35U);

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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 25438U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 26162U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aSource[((aIndex + 23750U)) & S_BLOCK1], 6U);

            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 24127U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24369U)) & S_BLOCK1], 47U);

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
            aIngress = RotL64(aSnowLaneC[((aIndex + 31108U)) & S_BLOCK1], 26U) ^ RotL64(aSnowLaneA[((aIndex + 32021U)) & S_BLOCK1], 3U);

            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 31198U)) & S_BLOCK1], 21U) ^ RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 31884U)) & S_BLOCK1], 12U);

            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_B twist_loop_b (end)

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 3512U)) & S_BLOCK1], 42U) ^ RotL64(aSnowLaneB[((aIndex + 1977U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 3420U)) & S_BLOCK1], 19U);

            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 438U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 131U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aScrapLaneB[((aIndex + 1226U)) & S_BLOCK1], 10U);

            aInvestLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 7641U)) & S_BLOCK1], 22U) ^ RotL64(aSnowLaneC[((aIndex + 6815U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aSource[((aIndex + 8618U)) & S_BLOCK1], 51U);

            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 7976U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 6762U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWindLaneA[((aIndex + 9270U)) & S_BLOCK1], 30U);

            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 16251U)) & S_BLOCK1], 38U) ^ RotL64(aSnowLaneA[((aIndex + 14433U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWindLaneD[((aIndex + 12202U)) & S_BLOCK1], 13U);

            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 16006U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 14813U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12214U)) & S_BLOCK1], 54U);

            aOperationLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19135U)) & S_BLOCK1], 36U) ^ RotL64(aSnowLaneD[((aIndex + 19168U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 20049U)) & S_BLOCK1], 3U);

            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 20366U)) & S_BLOCK1], 58U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 17970U)) & S_BLOCK1], 39U);

            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24451U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneB[((aIndex + 26831U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26557U)) & S_BLOCK1], 18U);

            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26232U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneA[((aIndex + 25495U)) & S_BLOCK1], 4U);

            aOperationLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30876U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 28132U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 31961U)) & S_BLOCK1], 39U);

            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31273U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 28122U)) & S_BLOCK1], 40U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_C twist_loop_c (end)

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1419U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 4834U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aSnowLaneB[((aIndex + 4856U)) & S_BLOCK1], 29U);

            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3051U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1709U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 1594U)) & S_BLOCK1], 47U);

            aScrapLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneC[((aIndex + 8982U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 5784U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aKeyRowReadA[(((2047U - aIndex) + 10405U)) & W_KEY1], 11U);

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9386U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6662U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWindLaneA[((aIndex + 9861U)) & S_BLOCK1], 14U);

            aScrapLaneD[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneD[((aIndex + 15246U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 11380U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 11511U)) & S_BLOCK1], 23U);

            //
            aCross = (RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 14678U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12979U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 11109U)) & S_BLOCK1], 23U);

            aWaterLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneA[((aIndex + 20245U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneD[((aIndex + 19050U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aSnowLaneD[((aIndex + 18615U)) & S_BLOCK1], 57U);

            //
            aCross = (RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 17541U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19145U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aSnowLaneC[((aIndex + 18829U)) & S_BLOCK1], 5U);

            aWaterLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneB[((aIndex + 27018U)) & S_BLOCK1], 28U) ^ RotL64(aScrapLaneD[((aIndex + 24268U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aSnowLaneA[((aIndex + 24229U)) & S_BLOCK1], 43U);

            //
            aCross = (RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 23976U)) & S_BLOCK1], 53U) ^ RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 23081U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWindLaneC[((aIndex + 23319U)) & S_BLOCK1], 40U);

            aWaterLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneC[((aIndex + 30374U)) & S_BLOCK1], 21U) ^ RotL64(aWaterLaneA[((aIndex + 29047U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 31336U)) & S_BLOCK1], 4U);

            //
            aCross = RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 30818U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30787U)) & S_BLOCK1], 5U);

            aWaterLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_D twist_loop_d (end)

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneA[((aIndex + 4692U)) & S_BLOCK1], 51U) ^ RotL64(aWaterLaneB[((aIndex + 1274U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 4342U)) & S_BLOCK1], 43U);

            //
            aCross = (RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 3227U)) & S_BLOCK1], 57U) ^ RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 269U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 4871U)) & S_BLOCK1], 42U);

            aInvestLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 10591U)) & S_BLOCK1], 23U) ^ RotL64(aWaterLaneC[((aIndex + 10253U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aSnowLaneD[((aIndex + 7813U)) & S_BLOCK1], 51U);

            //
            aCross = (RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 8023U)) & S_BLOCK1], 6U) ^ RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 7269U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 8312U)) & S_BLOCK1], 27U);

            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 14130U)) & S_BLOCK1], 37U) ^ RotL64(aWaterLaneA[((aIndex + 11808U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aSnowLaneA[((aIndex + 12190U)) & S_BLOCK1], 27U);

            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13618U)) & S_BLOCK1], 37U) ^ RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 12000U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 12235U)) & S_BLOCK1], 11U);

            aFuseLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneA[((aIndex + 19339U)) & S_BLOCK1], 57U) ^ RotL64(aWaterLaneD[((aIndex + 17687U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 21323U)) & S_BLOCK1], 29U);

            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 17598U)) & S_BLOCK1], 39U) ^ RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 19554U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17809U)) & S_BLOCK1], 19U);

            aFuseLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneB[((aIndex + 22040U)) & S_BLOCK1], 60U) ^ RotL64(aInvestLaneD[((aIndex + 24923U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aKeyRowReadB[((aIndex + 25707U)) & W_KEY1], 39U);

            //
            aCross = (RotL64(aFuseLaneA[((S_BLOCK1 - aIndex + 26552U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 21876U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 24827U)) & S_BLOCK1], 35U);

            aFuseLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 30438U)) & S_BLOCK1], 43U) ^ RotL64(aFuseLaneA[((aIndex + 31513U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27916U)) & S_BLOCK1], 22U);

            //
            aCross = (RotL64(aFuseLaneB[((S_BLOCK1 - aIndex + 27321U)) & S_BLOCK1], 12U) ^ RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 30505U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 29908U)) & S_BLOCK1], 57U);

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_E twist_loop_e (end)

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFireLaneA[((aIndex + 687U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneB[((aIndex + 1270U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aScrapLaneD[((aIndex + 1108U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5148U)) & S_BLOCK1], 47U));

            //
            aCross = (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 4886U)) & S_BLOCK1], 20U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 2503U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aScrapLaneC[((aIndex + 1878U)) & S_BLOCK1], 35U);

            aInvestLaneE[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneE[((aIndex + 9408U)) & S_BLOCK1], 54U) ^ RotL64(aFireLaneC[((aIndex + 6965U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aWaterLaneD[((aIndex + 6839U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7723U)) & S_BLOCK1], 3U));

            //
            aCross = (RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 8413U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6066U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 9161U)) & S_BLOCK1], 27U);

            aInvestLaneF[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneF[((aIndex + 13142U)) & S_BLOCK1], 48U) ^ RotL64(aFireLaneA[((aIndex + 11626U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aSnowLaneB[((aIndex + 14191U)) & S_BLOCK1], 19U) ^ RotL64(aSource[((aIndex + 11859U)) & S_BLOCK1], 39U));

            //
            aCross = (RotL64(aInvestLaneE[((S_BLOCK1 - aIndex + 15977U)) & S_BLOCK1], 12U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12222U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 15235U)) & S_BLOCK1], 35U);

            aEarthLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneA[((aIndex + 21353U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneD[((aIndex + 18412U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aInvestLaneC[((aIndex + 17864U)) & S_BLOCK1], 11U) ^ RotL64(aWaterLaneC[((aIndex + 17745U)) & S_BLOCK1], 34U));

            //
            aCross = (RotL64(aInvestLaneF[((S_BLOCK1 - aIndex + 19618U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 19152U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aSnowLaneA[((aIndex + 19998U)) & S_BLOCK1], 11U);

            aEarthLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneB[((aIndex + 24986U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneF[((aIndex + 22869U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aScrapLaneA[((aIndex + 26544U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22141U)) & S_BLOCK1], 60U));

            //
            aCross = (RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 21972U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneE[((S_BLOCK1 - aIndex + 26741U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 22255U)) & S_BLOCK1], 39U);

            aEarthLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneC[((aIndex + 28026U)) & S_BLOCK1], 5U) ^ RotL64(aEarthLaneA[((aIndex + 28997U)) & S_BLOCK1], 28U));
            aIngress ^= (RotL64(aScrapLaneB[((aIndex + 28245U)) & S_BLOCK1], 39U) ^ RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 29241U)) & S_BLOCK1], 51U));

            //
            aCross = (RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 31519U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 31191U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 28516U)) & S_BLOCK1], 24U);

            aEarthLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_F twist_loop_f (end)

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneA[((aIndex + 1466U)) & S_BLOCK1], 21U) ^ RotL64(aEarthLaneB[((aIndex + 3943U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 1898U)) & S_BLOCK1], 5U) ^ RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 4169U)) & S_BLOCK1], 42U));

            //
            aCross = (RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 1921U)) & S_BLOCK1], 23U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 4444U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aInvestLaneC[((aIndex + 2500U)) & S_BLOCK1], 37U);

            aInvestLaneG[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneG[((aIndex + 9263U)) & S_BLOCK1], 29U) ^ RotL64(aEarthLaneC[((aIndex + 7529U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aWaterLaneA[((aIndex + 6752U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneE[((aIndex + 5646U)) & S_BLOCK1], 37U));

            //
            aCross = (RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 5909U)) & S_BLOCK1], 52U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 10169U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 8289U)) & S_BLOCK1], 11U);

            aInvestLaneH[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneH[((aIndex + 15738U)) & S_BLOCK1], 29U) ^ RotL64(aEarthLaneA[((aIndex + 13478U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aInvestLaneF[((aIndex + 14567U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14333U)) & S_BLOCK1], 19U));

            //
            aCross = (RotL64(aInvestLaneG[((S_BLOCK1 - aIndex + 11749U)) & S_BLOCK1], 13U) ^ RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 13182U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWaterLaneB[((aIndex + 12544U)) & S_BLOCK1], 28U);

            aWorkLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 17052U)) & S_BLOCK1], 3U) ^ RotL64(aEarthLaneD[((aIndex + 20385U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aInvestLaneA[((aIndex + 18288U)) & S_BLOCK1], 46U) ^ RotL64(aFireLaneD[((aIndex + 21017U)) & S_BLOCK1], 23U));

            //
            aCross = (RotL64(aInvestLaneH[((S_BLOCK1 - aIndex + 21667U)) & S_BLOCK1], 21U) ^ RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 17256U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 18840U)) & S_BLOCK1], 36U);

            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22132U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneH[((aIndex + 22010U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 24333U)) & S_BLOCK1], 5U) ^ RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 25330U)) & S_BLOCK1], 21U));

            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26901U)) & S_BLOCK1], 38U) ^ RotL64(aInvestLaneG[((S_BLOCK1 - aIndex + 25686U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aKeyRowReadB[((aIndex + 25205U)) & W_KEY1], 27U);

            aWorkLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31266U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((aIndex + 29268U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aFireLaneB[((aIndex + 32063U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneB[((aIndex + 30976U)) & S_BLOCK1], 39U));

            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30877U)) & S_BLOCK1], 57U) ^ RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 28669U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aKeyRowReadA[(((2047U - aIndex) + 32301U)) & W_KEY1], 48U);

            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_G twist_loop_g (end)

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 18U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 329U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aFireLaneB[((aIndex + 4205U)) & S_BLOCK1], 19U) ^ RotL64(aWaterLaneA[((aIndex + 1716U)) & S_BLOCK1], 34U));

            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3980U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3169U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 2071U)) & S_BLOCK1], 47U);

            aOperationLaneB[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 8121U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneC[((aIndex + 10197U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aInvestLaneE[((aIndex + 9290U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((aIndex + 10418U)) & S_BLOCK1], 51U));

            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8623U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6464U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7687U)) & S_BLOCK1], 60U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneD[((aIndex + 11021U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 16002U)) & S_BLOCK1], 34U));
            aIngress ^= (RotL64(aEarthLaneB[((aIndex + 14210U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneB[((aIndex + 11573U)) & S_BLOCK1], 21U));

            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15172U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14846U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aEarthLaneD[((aIndex + 14813U)) & S_BLOCK1], 47U);

            aExpandLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20408U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((aIndex + 19497U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aScrapLaneD[((aIndex + 19771U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneB[((aIndex + 21384U)) & S_BLOCK1], 58U));

            //
            aCross = (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20283U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18857U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 20626U)) & S_BLOCK1], 11U);

            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 25651U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 22035U)) & S_BLOCK1], 14U));
            aIngress ^= (RotL64(aWaterLaneC[((aIndex + 24259U)) & S_BLOCK1], 5U) ^ RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 22897U)) & S_BLOCK1], 57U));

            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27292U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27002U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aScrapLaneB[((aIndex + 23679U)) & S_BLOCK1], 13U);

            aExpandLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31551U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 30155U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 29931U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27820U)) & S_BLOCK1], 29U));

            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27593U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31220U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneF[((aIndex + 29147U)) & S_BLOCK1], 19U);

            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GROW_A grow_key_a (end)

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2767U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 3436U)) & S_BLOCK1], 48U));
            aIngress ^= (RotL64(aFireLaneC[((aIndex + 917U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneC[((aIndex + 1579U)) & S_BLOCK1], 39U));

            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4840U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3386U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aInvestLaneG[((S_BLOCK1 - aIndex + 2692U)) & S_BLOCK1], 26U);

            aFuseLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 5707U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 7937U)) & S_BLOCK1], 14U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 8295U)) & S_BLOCK1], 47U) ^ RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 8269U)) & S_BLOCK1], 27U));

            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8144U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6313U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 7980U)) & S_BLOCK1], 44U);

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneD[((aIndex + 13397U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 14694U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aInvestLaneH[((aIndex + 16284U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11229U)) & S_BLOCK1], 27U));

            //
            aCross = (RotL64(aFuseLaneC[((S_BLOCK1 - aIndex + 13136U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12025U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aWindLaneB[((aIndex + 16322U)) & S_BLOCK1], 3U);

            aWorkLaneA[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 21628U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 18150U)) & S_BLOCK1], 44U));
            aIngress ^= (RotL64(aWindLaneD[((aIndex + 20572U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19423U)) & S_BLOCK1], 57U));

            //
            aCross = (RotL64(aFuseLaneD[((S_BLOCK1 - aIndex + 17723U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20567U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aEarthLaneA[((aIndex + 21191U)) & S_BLOCK1], 53U);

            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 26004U)) & S_BLOCK1], 12U) ^ RotL64(aFuseLaneD[((aIndex + 24623U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aSnowLaneA[((aIndex + 24940U)) & S_BLOCK1], 3U) ^ RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 27113U)) & S_BLOCK1], 35U));

            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25409U)) & S_BLOCK1], 58U) ^ RotL64(aFuseLaneC[((S_BLOCK1 - aIndex + 26618U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 26200U)) & S_BLOCK1], 35U);

            aWorkLaneC[aIndex] = aIngress;
        }

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
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29177U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((aIndex + 28180U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aSnowLaneC[((aIndex + 30643U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 31147U)) & S_BLOCK1], 3U));

            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28746U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28523U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 28272U)) & S_BLOCK1], 35U);

            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GROW_B grow_key_b (end)

}
