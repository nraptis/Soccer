#include "TwistExpander_Regulus_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Regulus_Arx::KDF_A_A() {
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
            aIngress = RotL64(aSource[((aIndex + 5212U)) & S_BLOCK1], 43U) ^ RotL64(pSnow[((aIndex + 2918U)) & S_BLOCK1], 60U);

            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 19U)) & S_BLOCK1], 11U) ^ RotL64(aSource[((S_BLOCK1 - aIndex + 4924U)) & S_BLOCK1], 43U);

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
            aIngress = RotL64(aScrapLaneA[((aIndex + 6647U)) & S_BLOCK1], 3U) ^ RotL64(aSource[((aIndex + 5723U)) & S_BLOCK1], 28U);

            //
            aCross = RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 7611U)) & S_BLOCK1], 52U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 6720U)) & S_BLOCK1], 41U);

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
            aIngress = RotL64(aScrapLaneB[((aIndex + 15811U)) & S_BLOCK1], 29U) ^ RotL64(aSource[((S_BLOCK1 - aIndex + 11756U)) & S_BLOCK1], 44U);

            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 15250U)) & S_BLOCK1], 39U) ^ RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 11164U)) & S_BLOCK1], 54U);

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
            aIngress = RotL64(aEarthLaneA[((aIndex + 19239U)) & S_BLOCK1], 5U) ^ RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 19813U)) & S_BLOCK1], 42U);

            //
            aCross = RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 21728U)) & S_BLOCK1], 4U) ^ RotL64(aSource[((S_BLOCK1 - aIndex + 17030U)) & S_BLOCK1], 57U);

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
            aIngress = RotL64(aEarthLaneB[((aIndex + 22661U)) & S_BLOCK1], 13U) ^ RotL64(aScrapLaneB[((aIndex + 22714U)) & S_BLOCK1], 34U);

            //
            aCross = RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 25992U)) & S_BLOCK1], 57U) ^ RotL64(pSnow[((aIndex + 25520U)) & S_BLOCK1], 42U);

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
            aIngress = RotL64(aEarthLaneC[((aIndex + 27919U)) & S_BLOCK1], 23U) ^ RotL64(aEarthLaneA[((aIndex + 31601U)) & S_BLOCK1], 58U);

            //
            aCross = RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 27546U)) & S_BLOCK1], 23U) ^ RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 30604U)) & S_BLOCK1], 58U);

            aEarthLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_A kdf_a_loop_a (end)

}

void TwistExpander_Regulus_Arx::KDF_A_B() {
    // [kdf-a arx]
    // GSeedRunKDF_A_B kdf_a_loop_b (start)
    {
        //
        // kdf_a_loop_b loop 1
        //
        // Ingress:
        //      aEarthLaneA (-->), aEarthLaneB (-->), aScrapLaneB (<-?->)
        //
        // Cross:
        //      aEarthLaneC (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aFireLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneA[((aIndex + 4803U)) & S_BLOCK1], 43U) ^ RotL64(aEarthLaneB[((aIndex + 2837U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 3729U)) & S_BLOCK1], 51U);

            //
            aCross = RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 2447U)) & S_BLOCK1], 51U) ^ RotL64(aEarthLaneD[((aIndex + 6137U)) & S_BLOCK1], 40U);

            aFireLaneA[aIndex] = aIngress;
        }

        //
        // kdf_a_loop_b loop 2
        //
        // Ingress:
        //      aFireLaneA (-->), aEarthLaneC (-->), pSnow (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aEarthLaneD (<--)
        //
        // Destination:
        //      aFireLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFireLaneA[((aIndex + 11387U)) & S_BLOCK1], 57U) ^ RotL64(aEarthLaneC[((aIndex + 8349U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(pSnow[((aIndex + 11754U)) & S_BLOCK1], 35U);

            //
            aCross = RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 8664U)) & S_BLOCK1], 57U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 12614U)) & S_BLOCK1], 47U);

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
            aIngress = (RotL64(aFireLaneB[((aIndex + 23430U)) & S_BLOCK1], 41U) ^ RotL64(aEarthLaneD[((aIndex + 21520U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aScrapLaneA[((aIndex + 23575U)) & S_BLOCK1], 3U);

            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 20440U)) & S_BLOCK1], 3U) ^ RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 19125U)) & S_BLOCK1], 29U);

            aFireLaneC[aIndex] = aIngress;
        }

        //
        // kdf_a_loop_b loop 4
        //
        // Ingress:
        //      aFireLaneC (-->), aFireLaneA (-->), aSource (<-?->)
        //
        // Cross:
        //      aFireLaneB (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aFireLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFireLaneC[((aIndex + 30342U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneA[((aIndex + 30432U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aSource[((S_BLOCK1 - aIndex + 28466U)) & S_BLOCK1], 6U);

            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29119U)) & S_BLOCK1], 38U) ^ RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 28040U)) & S_BLOCK1], 19U);

            aFireLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_B kdf_a_loop_b (end)

}

void TwistExpander_Regulus_Arx::KDF_A_C() {
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
        //      aFireLaneC (<--), aFireLaneD (<--), aSource (<-?->)
        //
        // Destination:
        //      aOperationLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFireLaneA[((aIndex + 707U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((aIndex + 5849U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 630U)) & S_BLOCK1], 57U);

            //
            aCross = (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 5039U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6721U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aSource[((aIndex + 7890U)) & S_BLOCK1], 3U);

            aOperationLaneA[aIndex] = aIngress;
        }

        //
        // kdf_a_loop_c loop 2
        //
        // Ingress:
        //      aOperationLaneA (-->), aFireLaneC (-->), aEarthLaneC (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 9680U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneC[((aIndex + 15290U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aEarthLaneC[((aIndex + 13192U)) & S_BLOCK1], 57U);

            //
            aCross = (RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10467U)) & S_BLOCK1], 6U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12987U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 9749U)) & S_BLOCK1], 41U);

            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // kdf_a_loop_c loop 3
        //
        // Ingress:
        //      aOperationLaneB (-->), aFireLaneD (-->), pSnow (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aFireLaneB (<--), aScrapLaneB (<-?->)
        //
        // Destination:
        //      aOperationLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 16815U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneD[((aIndex + 17776U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(pSnow[((S_BLOCK1 - aIndex + 20487U)) & S_BLOCK1], 58U);

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20465U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 23870U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aScrapLaneB[((aIndex + 24216U)) & S_BLOCK1], 20U);

            aOperationLaneC[aIndex] = aIngress;
        }

        //
        // kdf_a_loop_c loop 4
        //
        // Ingress:
        //      aOperationLaneC (-->), aOperationLaneA (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aOperationLaneB (<--), aFireLaneC (<--), aScrapLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31671U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 32327U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aEarthLaneD[((aIndex + 29243U)) & S_BLOCK1], 4U);

            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27760U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 29962U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aScrapLaneA[((aIndex + 27299U)) & S_BLOCK1], 58U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_C kdf_a_loop_c (end)

}

void TwistExpander_Regulus_Arx::KDF_A_D() {
    // [kdf-a arx]
    // GSeedRunKDF_A_D kdf_a_loop_d (start)
    {
        //
        // kdf_a_loop_d loop 1
        //
        // Ingress:
        //      aOperationLaneA (-->), aOperationLaneB (-->), pSnow (-->), aFireLaneB (<-?->)
        //
        // Cross:
        //      aOperationLaneC (<--), aOperationLaneD (<--), aSource (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 6880U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 6511U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(pSnow[((aIndex + 2957U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1793U)) & S_BLOCK1], 28U));

            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5910U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6495U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aSource[((aIndex + 7659U)) & S_BLOCK1], 3U);

            aFuseLaneA[aIndex] = aIngress;
        }

        //
        // kdf_a_loop_d loop 2
        //
        // Ingress:
        //      aFuseLaneA (-->), aOperationLaneC (-->), aEarthLaneC (-->), aScrapLaneB (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aOperationLaneD (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneA[((aIndex + 15053U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 13681U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aEarthLaneC[((aIndex + 15870U)) & S_BLOCK1], 58U) ^ RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 11597U)) & S_BLOCK1], 41U));

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13871U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13589U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 12687U)) & S_BLOCK1], 39U);

            aFuseLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // kdf_a_loop_d loop 3
        //
        // Ingress:
        //      aFuseLaneB (-->), aOperationLaneD (-->), aFireLaneC (-->), aEarthLaneB (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aOperationLaneB (<--), aFireLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneB[((aIndex + 19258U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneD[((aIndex + 22941U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aFireLaneC[((aIndex + 16672U)) & S_BLOCK1], 5U) ^ RotL64(aEarthLaneB[((aIndex + 18491U)) & S_BLOCK1], 13U));

            //
            aCross = (RotL64(aFuseLaneA[((S_BLOCK1 - aIndex + 23986U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17098U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 21992U)) & S_BLOCK1], 13U);

            aFuseLaneC[aIndex] = aIngress;
        }

        //
        // kdf_a_loop_d loop 4
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aFireLaneD (-->), aScrapLaneA (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aOperationLaneC (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 27397U)) & S_BLOCK1], 41U) ^ RotL64(aFuseLaneA[((aIndex + 31099U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 32729U)) & S_BLOCK1], 21U) ^ RotL64(aScrapLaneA[((aIndex + 30489U)) & S_BLOCK1], 11U));

            //
            aCross = (RotL64(aFuseLaneB[((S_BLOCK1 - aIndex + 31996U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 28631U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aEarthLaneD[((aIndex + 27830U)) & S_BLOCK1], 13U);

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_D kdf_a_loop_d (end)

}

void TwistExpander_Regulus_Arx::KDF_A_E() {
    // [kdf-a arx]
    // GSeedRunKDF_A_E kdf_a_loop_e (start)
    {
        //
        // kdf_a_loop_e loop 1
        //
        // Ingress:
        //      aWindLaneA (-->), aWindLaneB (-->), aEarthLaneA (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aWindLaneC (<--), aWindLaneD (<--), aOperationLaneC (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aWaterLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWindLaneA[((aIndex + 7080U)) & S_BLOCK1], 39U) ^ RotL64(aWindLaneB[((aIndex + 4401U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aEarthLaneA[((aIndex + 1619U)) & S_BLOCK1], 13U) ^ RotL64(aEarthLaneD[((aIndex + 3415U)) & S_BLOCK1], 21U));

            //
            aCross = (RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 3060U)) & S_BLOCK1], 53U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 6150U)) & S_BLOCK1], 11U));
            aCross ^= (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6455U)) & S_BLOCK1], 3U) ^ RotL64(aEarthLaneC[((aIndex + 6298U)) & S_BLOCK1], 26U));

            aWaterLaneA[aIndex] = aIngress;
        }

        //
        // kdf_a_loop_e loop 2
        //
        // Ingress:
        //      aWaterLaneA (-->), aWindLaneC (-->), aEarthLaneB (-->), aFireLaneB (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aWindLaneD (<--), aFireLaneC (<--), aFireLaneD (<-?->)
        //
        // Destination:
        //      aWaterLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneA[((aIndex + 13798U)) & S_BLOCK1], 54U) ^ RotL64(aWindLaneC[((aIndex + 11192U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aEarthLaneB[((aIndex + 11712U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneB[((aIndex + 10359U)) & S_BLOCK1], 43U));

            //
            aCross = (RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 15936U)) & S_BLOCK1], 57U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 8730U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14555U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((aIndex + 15205U)) & S_BLOCK1], 23U));

            aWaterLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // kdf_a_loop_e loop 3
        //
        // Ingress:
        //      aWaterLaneB (-->), aWindLaneD (-->), pSnow (-->), aOperationLaneD (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWindLaneB (<--), aFireLaneA (<-?->)
        //
        // Destination:
        //      aWaterLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneB[((aIndex + 20813U)) & S_BLOCK1], 13U) ^ RotL64(aWindLaneD[((aIndex + 23308U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(pSnow[((aIndex + 24251U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((aIndex + 18258U)) & S_BLOCK1], 46U));

            //
            aCross = (RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 22417U)) & S_BLOCK1], 40U) ^ RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 21874U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 21686U)) & S_BLOCK1], 3U);

            aWaterLaneC[aIndex] = aIngress;
        }

        //
        // kdf_a_loop_e loop 4
        //
        // Ingress:
        //      aWaterLaneC (-->), aWaterLaneA (-->), aOperationLaneB (-->), aOperationLaneA (<-?->)
        //
        // Cross:
        //      aWaterLaneB (<--), aWindLaneC (<--), aSource (<-?->)
        //
        // Destination:
        //      aWaterLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneC[((aIndex + 27467U)) & S_BLOCK1], 39U) ^ RotL64(aWaterLaneA[((aIndex + 29473U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 26857U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30050U)) & S_BLOCK1], 3U));

            //
            aCross = (RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 29991U)) & S_BLOCK1], 21U) ^ RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 29767U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aSource[((aIndex + 26262U)) & S_BLOCK1], 51U);

            aWaterLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_E kdf_a_loop_e (end)

}

void TwistExpander_Regulus_Arx::KDF_B_A() {
    // [kdf-a arx]
    // GSeedRunKDF_B_A kdf_b_loop_a (start)
    {
        //
        // kdf_b_loop_a loop 1
        //
        // Ingress:
        //      aWaterLaneA (-->), aWaterLaneB (-->), aWindLaneC (-->), aFireLaneC (<-?->)
        //
        // Cross:
        //      aWaterLaneC (<--), aWaterLaneD (<--), aOperationLaneD (<-?->)
        //
        // Destination:
        //      aScrapLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneA[((aIndex + 3606U)) & S_BLOCK1], 47U) ^ RotL64(aWaterLaneB[((aIndex + 6512U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aWindLaneC[((aIndex + 6825U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((aIndex + 8095U)) & S_BLOCK1], 58U));

            //
            aCross = (RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 2519U)) & S_BLOCK1], 13U) ^ RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 4612U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8146U)) & S_BLOCK1], 26U);

            aScrapLaneA[aIndex] = aIngress;
        }

        //
        // kdf_b_loop_a loop 2
        //
        // Ingress:
        //      aScrapLaneA (-->), aWaterLaneC (-->), aFireLaneD (-->), aSource (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWaterLaneD (<--), aWindLaneB (<-?->)
        //
        // Destination:
        //      aScrapLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneA[((aIndex + 15057U)) & S_BLOCK1], 3U) ^ RotL64(aWaterLaneC[((aIndex + 14900U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 9983U)) & S_BLOCK1], 19U) ^ RotL64(aSource[((S_BLOCK1 - aIndex + 15210U)) & S_BLOCK1], 53U));

            //
            aCross = (RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 15502U)) & S_BLOCK1], 36U) ^ RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 12249U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWindLaneB[((aIndex + 16099U)) & S_BLOCK1], 21U);

            aScrapLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // kdf_b_loop_a loop 3
        //
        // Ingress:
        //      aScrapLaneB (-->), aWaterLaneD (-->), aOperationLaneA (-->), aOperationLaneC (<-?->)
        //
        // Cross:
        //      aScrapLaneA (<--), aWaterLaneB (<--), aFireLaneB (<-?->)
        //
        // Destination:
        //      aScrapLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneB[((aIndex + 20472U)) & S_BLOCK1], 13U) ^ RotL64(aWaterLaneD[((aIndex + 19214U)) & S_BLOCK1], 46U));
            aIngress ^= (RotL64(aOperationLaneA[((aIndex + 18663U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16449U)) & S_BLOCK1], 3U));

            //
            aCross = (RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 16859U)) & S_BLOCK1], 41U) ^ RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 21370U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16887U)) & S_BLOCK1], 6U);

            aScrapLaneC[aIndex] = aIngress;
        }

        //
        // kdf_b_loop_a loop 4
        //
        // Ingress:
        //      aScrapLaneC (-->), aScrapLaneA (-->), aWindLaneD (-->), aWindLaneA (<-?->)
        //
        // Cross:
        //      aScrapLaneB (<--), aWaterLaneC (<--), aOperationLaneB (<-?->)
        //
        // Destination:
        //      aScrapLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneC[((aIndex + 25580U)) & S_BLOCK1], 43U) ^ RotL64(aScrapLaneA[((aIndex + 28565U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aWindLaneD[((aIndex + 32412U)) & S_BLOCK1], 19U) ^ RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 25638U)) & S_BLOCK1], 6U));

            //
            aCross = (RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 24778U)) & S_BLOCK1], 53U) ^ RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 29671U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 25036U)) & S_BLOCK1], 13U);

            aScrapLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_A kdf_b_loop_a (end)

}

void TwistExpander_Regulus_Arx::KDF_B_B() {
    // [kdf-a arx]
    // GSeedRunKDF_B_B kdf_b_loop_b (start)
    {
        //
        // kdf_b_loop_b loop 1
        //
        // Ingress:
        //      aScrapLaneA (-->), aScrapLaneB (-->), aFireLaneA (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aScrapLaneC (<--), aScrapLaneD (<--), aWaterLaneC (<--), aWindLaneD (<-?->)
        //
        // Destination:
        //      aOperationLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneA[((aIndex + 2113U)) & S_BLOCK1], 11U) ^ RotL64(aScrapLaneB[((aIndex + 5875U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 8042U)) & S_BLOCK1], 54U) ^ RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 3257U)) & S_BLOCK1], 29U));

            //
            aCross = (RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 2552U)) & S_BLOCK1], 52U) ^ RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 7145U)) & S_BLOCK1], 21U));
            aCross ^= (RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 4756U)) & S_BLOCK1], 13U) ^ RotL64(aWindLaneD[((aIndex + 6468U)) & S_BLOCK1], 29U));

            aOperationLaneA[aIndex] = aIngress;
        }

        //
        // kdf_b_loop_b loop 2
        //
        // Ingress:
        //      aOperationLaneA (-->), aScrapLaneC (-->), aEarthLaneD (-->), aWindLaneB (<-?->)
        //
        // Cross:
        //      aScrapLaneA (<--), aScrapLaneD (<--), aWaterLaneB (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8224U)) & S_BLOCK1], 41U) ^ RotL64(aScrapLaneC[((aIndex + 14871U)) & S_BLOCK1], 14U));
            aIngress ^= (RotL64(aEarthLaneD[((aIndex + 15337U)) & S_BLOCK1], 5U) ^ RotL64(aWindLaneB[((aIndex + 12410U)) & S_BLOCK1], 23U));

            //
            aCross = (RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 9533U)) & S_BLOCK1], 24U) ^ RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 14113U)) & S_BLOCK1], 39U));
            aCross ^= (RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 9250U)) & S_BLOCK1], 5U) ^ RotL64(aWindLaneA[((aIndex + 14249U)) & S_BLOCK1], 13U));

            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // kdf_b_loop_b loop 3
        //
        // Ingress:
        //      aOperationLaneB (-->), aScrapLaneD (-->), aWindLaneC (-->), aWaterLaneA (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aScrapLaneB (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aOperationLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 21676U)) & S_BLOCK1], 35U) ^ RotL64(aScrapLaneD[((aIndex + 17690U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aWindLaneC[((aIndex + 23371U)) & S_BLOCK1], 22U) ^ RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 19368U)) & S_BLOCK1], 3U));

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17821U)) & S_BLOCK1], 5U) ^ RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 18067U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 20080U)) & S_BLOCK1], 44U);

            aOperationLaneC[aIndex] = aIngress;
        }

        //
        // kdf_b_loop_b loop 4
        //
        // Ingress:
        //      aOperationLaneC (-->), aOperationLaneA (-->), aSource (-->), aWaterLaneD (<-?->)
        //
        // Cross:
        //      aOperationLaneB (<--), aScrapLaneC (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aOperationLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26006U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 25931U)) & S_BLOCK1], 60U));
            aIngress ^= (RotL64(aSource[((aIndex + 25284U)) & S_BLOCK1], 47U) ^ RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 24901U)) & S_BLOCK1], 27U));

            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26048U)) & S_BLOCK1], 12U) ^ RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 30483U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 29776U)) & S_BLOCK1], 57U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_B kdf_b_loop_b (end)

}

void TwistExpander_Regulus_Arx::KDF_B_C() {
    // [kdf-a arx]
    // GSeedRunKDF_B_C kdf_b_loop_c (start)
    {
        //
        // kdf_b_loop_c loop 1
        //
        // Ingress:
        //      aOperationLaneA (-->), aOperationLaneB (-->), aWindLaneC (-->), aScrapLaneD (<-?->)
        //
        // Cross:
        //      aOperationLaneC (<--), aOperationLaneD (<--), aFireLaneA (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7421U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 3279U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aWindLaneC[((aIndex + 541U)) & S_BLOCK1], 27U) ^ RotL64(aScrapLaneD[((aIndex + 4484U)) & S_BLOCK1], 5U));

            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 739U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7067U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 8127U)) & S_BLOCK1], 27U) ^ RotL64(aWindLaneA[((aIndex + 2213U)) & S_BLOCK1], 51U));

            aFuseLaneA[aIndex] = aIngress;
        }

        //
        // kdf_b_loop_c loop 2
        //
        // Ingress:
        //      aFuseLaneA (-->), aOperationLaneC (-->), aWaterLaneD (-->), aFireLaneC (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aOperationLaneD (<--), aFireLaneD (<--), aWaterLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneA[((aIndex + 8408U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 11332U)) & S_BLOCK1], 20U));
            aIngress ^= (RotL64(aWaterLaneD[((aIndex + 15196U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8712U)) & S_BLOCK1], 29U));

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14986U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13846U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 9618U)) & S_BLOCK1], 48U) ^ RotL64(aWaterLaneC[((aIndex + 15138U)) & S_BLOCK1], 11U));

            aFuseLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // kdf_b_loop_c loop 3
        //
        // Ingress:
        //      aFuseLaneB (-->), aOperationLaneD (-->), aWaterLaneB (-->), aFireLaneB (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aOperationLaneB (<--), aScrapLaneB (<--), aWindLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneB[((aIndex + 19482U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((aIndex + 18379U)) & S_BLOCK1], 28U));
            aIngress ^= (RotL64(aWaterLaneB[((aIndex + 22221U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21413U)) & S_BLOCK1], 19U));

            //
            aCross = (RotL64(aFuseLaneA[((S_BLOCK1 - aIndex + 24517U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18586U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 18111U)) & S_BLOCK1], 41U) ^ RotL64(aWindLaneB[((aIndex + 19563U)) & S_BLOCK1], 28U));

            aFuseLaneC[aIndex] = aIngress;
        }

        //
        // kdf_b_loop_c loop 4
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aWaterLaneA (-->), aScrapLaneA (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aOperationLaneC (<--), aWindLaneD (<--), aScrapLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 32482U)) & S_BLOCK1], 5U) ^ RotL64(aFuseLaneA[((aIndex + 24718U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aWaterLaneA[((aIndex + 28167U)) & S_BLOCK1], 26U) ^ RotL64(aScrapLaneA[((aIndex + 29594U)) & S_BLOCK1], 47U));

            //
            aCross = (RotL64(aFuseLaneB[((S_BLOCK1 - aIndex + 30122U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 26357U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 31371U)) & S_BLOCK1], 24U) ^ RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 25278U)) & S_BLOCK1], 47U));

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_C kdf_b_loop_c (end)

}

void TwistExpander_Regulus_Arx::KDF_B_D() {
    // [kdf-a arx]
    // GSeedRunKDF_B_D kdf_b_loop_d (start)
    {
        //
        // kdf_b_loop_d loop 1
        //
        // Ingress:
        //      aWorkLaneA (-->), aWorkLaneB (-->), aWaterLaneB (-->), aScrapLaneD (<-?->)
        //
        // Cross:
        //      aWorkLaneC (<--), aWorkLaneD (<--), aWaterLaneA (<--), aWaterLaneC (<-?->)
        //
        // Destination:
        //      aExpandLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5056U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 548U)) & S_BLOCK1], 52U));
            aIngress ^= (RotL64(aWaterLaneB[((aIndex + 7144U)) & S_BLOCK1], 19U) ^ RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 1595U)) & S_BLOCK1], 3U));

            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1878U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5595U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 75U)) & S_BLOCK1], 11U) ^ RotL64(aWaterLaneC[((aIndex + 6542U)) & S_BLOCK1], 47U));

            aExpandLaneA[aIndex] = aIngress;
        }

        //
        // kdf_b_loop_d loop 2
        //
        // Ingress:
        //      aExpandLaneA (-->), aWorkLaneC (-->), aScrapLaneB (-->), aWindLaneD (<-?->)
        //
        // Cross:
        //      aWorkLaneA (<--), aWorkLaneD (<--), aOperationLaneD (<--), aSource (<-?->)
        //
        // Destination:
        //      aExpandLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9367U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((aIndex + 14286U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aScrapLaneB[((aIndex + 12718U)) & S_BLOCK1], 37U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 15254U)) & S_BLOCK1], 21U));

            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11012U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10220U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16188U)) & S_BLOCK1], 3U) ^ RotL64(aSource[((aIndex + 13599U)) & S_BLOCK1], 41U));

            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // kdf_b_loop_d loop 3
        //
        // Ingress:
        //      aExpandLaneB (-->), aWorkLaneD (-->), aWindLaneC (-->), aWaterLaneD (<-?->)
        //
        // Cross:
        //      aExpandLaneA (<--), aWorkLaneB (<--), aScrapLaneC (<--), aOperationLaneA (<-?->)
        //
        // Destination:
        //      aExpandLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21054U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((aIndex + 16621U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aWindLaneC[((aIndex + 17626U)) & S_BLOCK1], 58U) ^ RotL64(aWaterLaneD[((aIndex + 19239U)) & S_BLOCK1], 3U));

            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24457U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16812U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 19190U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23071U)) & S_BLOCK1], 23U));

            aExpandLaneC[aIndex] = aIngress;
        }

        //
        // kdf_b_loop_d loop 4
        //
        // Ingress:
        //      aExpandLaneC (-->), aExpandLaneA (-->), aOperationLaneC (-->), aWindLaneB (<-?->)
        //
        // Cross:
        //      aExpandLaneB (<--), aWorkLaneC (<--), aScrapLaneA (<--), aOperationLaneB (<-?->)
        //
        // Destination:
        //      aExpandLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32382U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 31928U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aOperationLaneC[((aIndex + 31611U)) & S_BLOCK1], 19U) ^ RotL64(aWindLaneB[((aIndex + 26702U)) & S_BLOCK1], 44U));

            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28683U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28631U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 26787U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30957U)) & S_BLOCK1], 20U));

            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_D kdf_b_loop_d (end)

}

void TwistExpander_Regulus_Arx::Seed_A() {
    const std::uint64_t &aPhaseDDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseDConstants.mIngress;
    const std::uint64_t &aPhaseDDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseDConstants.mScatter;
    const std::uint64_t &aPhaseDDomainWordCross = pWorkSpace->mDomainBundle.mPhaseDConstants.mCross;
    const std::uint64_t &aPhaseEDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseEConstants.mIngress;
    const std::uint64_t &aPhaseEDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseEConstants.mScatter;
    const std::uint64_t &aPhaseEDomainWordCross = pWorkSpace->mDomainBundle.mPhaseEConstants.mCross;
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
            aIngress = RotL64(aSource[((aIndex + 2845U)) & S_BLOCK1], 14U) ^ RotL64(aKeyRowReadA[((aIndex + 5181U)) & W_KEY1], 39U);

            //
            aCross = RotL64(aSource[((S_BLOCK1 - aIndex + 2474U)) & S_BLOCK1], 36U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 2514U)) & W_KEY1], 23U);

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
            aIngress = RotL64(aWorkLaneA[((aIndex + 8321U)) & S_BLOCK1], 18U) ^ RotL64(aKeyRowReadB[((aIndex + 7404U)) & W_KEY1], 37U);

            //
            aCross = RotL64(aSource[((S_BLOCK1 - aIndex + 10273U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 6115U)) & W_KEY1], 53U);

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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 15343U)) & S_BLOCK1], 37U) ^ RotL64(aSource[((aIndex + 14089U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aKeyRowReadB[((aIndex + 14015U)) & W_KEY1], 22U);

            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 14195U)) & W_KEY1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15563U)) & S_BLOCK1], 10U);

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
            aIngress = RotL64(aExpandLaneA[((aIndex + 20974U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19046U)) & S_BLOCK1], 56U);

            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17760U)) & S_BLOCK1], 48U) ^ RotL64(aKeyRowReadB[((aIndex + 17257U)) & W_KEY1], 19U);

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
            aIngress = RotL64(aExpandLaneB[((aIndex + 24605U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23247U)) & S_BLOCK1], 12U);

            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26935U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 24019U)) & W_KEY1], 54U);

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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30358U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 31145U)) & S_BLOCK1], 18U);

            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28540U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32746U)) & S_BLOCK1], 21U);

            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_A seed_loop_a (end)

}

void TwistExpander_Regulus_Arx::Seed_B() {
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
        //      aExpandLaneA (-->), aExpandLaneB (-->), aWorkLaneA (<-?->)
        //
        // Cross:
        //      aExpandLaneC (<--), aExpandLaneD (<-?->)
        //
        // Destination:
        //      aWorkLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4217U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((aIndex + 4372U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 4789U)) & S_BLOCK1], 35U);

            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4206U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((aIndex + 2562U)) & S_BLOCK1], 37U);

            aWorkLaneC[aIndex] = aIngress;
        }

        //
        // seed_loop_e loop 2
        //
        // Ingress:
        //      aWorkLaneC (-->), aExpandLaneC (-->), aSource (<-?->)
        //
        // Cross:
        //      aExpandLaneA (<--), aExpandLaneD (<--)
        //
        // Destination:
        //      aWorkLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 9947U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 8878U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aSource[((aIndex + 6984U)) & S_BLOCK1], 6U);

            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9003U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10806U)) & S_BLOCK1], 23U);

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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 14310U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 13984U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aKeyRowReadB[(((2047U - aIndex) + 13332U)) & W_KEY1], 43U);

            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13983U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14492U)) & S_BLOCK1], 39U);

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
            aIngress = (RotL64(aEarthLaneA[((aIndex + 21345U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((aIndex + 18779U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16903U)) & S_BLOCK1], 29U);

            //
            aCross = RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18044U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 20247U)) & S_BLOCK1], 51U);

            aEarthLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // seed_loop_e loop 5
        //
        // Ingress:
        //      aEarthLaneB (-->), aWorkLaneD (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aWorkLaneC (<-?->)
        //
        // Destination:
        //      aEarthLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneB[((aIndex + 26721U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((aIndex + 21891U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aKeyRowReadA[(((2047U - aIndex) + 25881U)) & W_KEY1], 60U);

            //
            aCross = RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 26013U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((aIndex + 22331U)) & S_BLOCK1], 54U);

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
            aIngress = RotL64(aEarthLaneC[((aIndex + 27768U)) & S_BLOCK1], 29U) ^ RotL64(aEarthLaneA[((aIndex + 31255U)) & S_BLOCK1], 19U);

            //
            aCross = RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 30164U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32094U)) & S_BLOCK1], 37U);

            aEarthLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_B seed_loop_e (end)

}

void TwistExpander_Regulus_Arx::Seed_C() {
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
    // GSeedRunSeed_C seed_loop_d (start)
    {
        //
        // seed_loop_d loop 1
        //
        // Ingress:
        //      aEarthLaneA (-->), aEarthLaneB (-->), aWorkLaneD (<-?->)
        //
        // Cross:
        //      aEarthLaneC (<--), aEarthLaneD (<--), aExpandLaneC (<-?->)
        //
        // Destination:
        //      aScrapLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneA[((aIndex + 1791U)) & S_BLOCK1], 21U) ^ RotL64(aEarthLaneB[((aIndex + 5291U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 187U)) & S_BLOCK1], 47U);

            //
            aCross = (RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 3236U)) & S_BLOCK1], 37U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 2645U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 813U)) & S_BLOCK1], 47U);

            aScrapLaneA[aIndex] = aIngress;
        }

        //
        // seed_loop_d loop 2
        //
        // Ingress:
        //      aScrapLaneA (-->), aEarthLaneC (-->), aWorkLaneA (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aEarthLaneD (<--), aWorkLaneB (<-?->)
        //
        // Destination:
        //      aScrapLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneA[((aIndex + 6667U)) & S_BLOCK1], 13U) ^ RotL64(aEarthLaneC[((aIndex + 10520U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8339U)) & S_BLOCK1], 21U);

            //
            aCross = (RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 8860U)) & S_BLOCK1], 6U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 8374U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 10457U)) & S_BLOCK1], 41U);

            aScrapLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // seed_loop_d loop 3
        //
        // Ingress:
        //      aScrapLaneB (-->), aEarthLaneA (-->), aExpandLaneA (<-?->)
        //
        // Cross:
        //      aScrapLaneA (<--), aEarthLaneC (<--), aExpandLaneB (<-?->)
        //
        // Destination:
        //      aOperationLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneB[((aIndex + 14653U)) & S_BLOCK1], 43U) ^ RotL64(aEarthLaneA[((aIndex + 12974U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14276U)) & S_BLOCK1], 35U);

            //
            aCross = (RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 14482U)) & S_BLOCK1], 3U) ^ RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 15309U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13752U)) & S_BLOCK1], 47U);

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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17854U)) & S_BLOCK1], 53U) ^ RotL64(aEarthLaneD[((aIndex + 18153U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 17351U)) & S_BLOCK1], 41U);

            //
            aCross = RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 21711U)) & S_BLOCK1], 5U) ^ RotL64(aEarthLaneA[((aIndex + 17189U)) & S_BLOCK1], 37U);

            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // seed_loop_d loop 5
        //
        // Ingress:
        //      aOperationLaneB (-->), aScrapLaneB (-->), aSource (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aScrapLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24798U)) & S_BLOCK1], 3U) ^ RotL64(aScrapLaneB[((aIndex + 26376U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aSource[((S_BLOCK1 - aIndex + 23511U)) & S_BLOCK1], 12U);

            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22096U)) & S_BLOCK1], 52U) ^ RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 24247U)) & S_BLOCK1], 41U);

            aOperationLaneC[aIndex] = aIngress;
        }

        //
        // seed_loop_d loop 6
        //
        // Ingress:
        //      aOperationLaneC (-->), aOperationLaneA (-->), aWorkLaneC (<-?->)
        //
        // Cross:
        //      aOperationLaneB (<--), aEarthLaneB (<--)
        //
        // Destination:
        //      aOperationLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27812U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 29514U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 28240U)) & S_BLOCK1], 48U);

            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32255U)) & S_BLOCK1], 35U) ^ RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 31315U)) & S_BLOCK1], 47U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_C seed_loop_d (end)

}

void TwistExpander_Regulus_Arx::Seed_D() {
    const std::uint64_t &aPhaseADomainWordIngress = pWorkSpace->mDomainBundle.mPhaseAConstants.mIngress;
    const std::uint64_t &aPhaseADomainWordScatter = pWorkSpace->mDomainBundle.mPhaseAConstants.mScatter;
    const std::uint64_t &aPhaseADomainWordCross = pWorkSpace->mDomainBundle.mPhaseAConstants.mCross;
    const std::uint64_t &aPhaseBDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseBConstants.mIngress;
    const std::uint64_t &aPhaseBDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseBConstants.mScatter;
    const std::uint64_t &aPhaseBDomainWordCross = pWorkSpace->mDomainBundle.mPhaseBConstants.mCross;
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
    // GSeedRunSeed_D seed_loop_c (start)
    {
        //
        // seed_loop_c loop 1
        //
        // Ingress:
        //      aOperationLaneA (-->), aOperationLaneB (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aOperationLaneC (<--), aOperationLaneD (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aScrapLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1898U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneB[((aIndex + 2887U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 2565U)) & S_BLOCK1], 11U);

            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4771U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1884U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 765U)) & S_BLOCK1], 57U);

            aScrapLaneC[aIndex] = aIngress;
        }

        //
        // seed_loop_c loop 2
        //
        // Ingress:
        //      aScrapLaneC (-->), aOperationLaneC (-->), aScrapLaneA (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aOperationLaneD (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aScrapLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneC[((aIndex + 5908U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 10065U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 5863U)) & S_BLOCK1], 56U);

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8619U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7934U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 7205U)) & S_BLOCK1], 57U);

            aScrapLaneD[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // seed_loop_c loop 3
        //
        // Ingress:
        //      aScrapLaneD (-->), aOperationLaneA (-->), aExpandLaneB (<-?->)
        //
        // Cross:
        //      aScrapLaneC (<--), aOperationLaneC (<--), aExpandLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneD[((aIndex + 12774U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 15955U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 10990U)) & S_BLOCK1], 53U);

            //
            aCross = (RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 11250U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14222U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 15665U)) & S_BLOCK1], 38U);

            aFuseLaneA[aIndex] = aIngress;
        }

        //
        // seed_loop_c loop 4
        //
        // Ingress:
        //      aFuseLaneA (-->), aOperationLaneD (-->), aEarthLaneB (<-?->)
        //
        // Cross:
        //      aScrapLaneD (<--), aOperationLaneA (<--), aScrapLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneA[((aIndex + 18005U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneD[((aIndex + 19929U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aEarthLaneB[((aIndex + 18698U)) & S_BLOCK1], 43U);

            //
            aCross = (RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 17530U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19256U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aScrapLaneB[((aIndex + 19681U)) & S_BLOCK1], 19U);

            aFuseLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // seed_loop_c loop 5
        //
        // Ingress:
        //      aFuseLaneB (-->), aScrapLaneD (-->), aExpandLaneC (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aScrapLaneC (<--), aWorkLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneB[((aIndex + 22189U)) & S_BLOCK1], 4U) ^ RotL64(aScrapLaneD[((aIndex + 24877U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 25222U)) & S_BLOCK1], 53U);

            //
            aCross = (RotL64(aFuseLaneA[((S_BLOCK1 - aIndex + 26634U)) & S_BLOCK1], 57U) ^ RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 22856U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 23288U)) & S_BLOCK1], 21U);

            aFuseLaneC[aIndex] = aIngress;
        }

        //
        // seed_loop_c loop 6
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aOperationLaneB (<--), aExpandLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 29042U)) & S_BLOCK1], 53U) ^ RotL64(aFuseLaneA[((aIndex + 29364U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aKeyRowReadA[(((2047U - aIndex) + 29457U)) & W_KEY1], 3U);

            //
            aCross = (RotL64(aFuseLaneB[((S_BLOCK1 - aIndex + 31066U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30986U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29459U)) & S_BLOCK1], 13U);

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_D seed_loop_c (end)

}

void TwistExpander_Regulus_Arx::Seed_E() {
    const std::uint64_t &aPhaseADomainWordIngress = pWorkSpace->mDomainBundle.mPhaseAConstants.mIngress;
    const std::uint64_t &aPhaseADomainWordScatter = pWorkSpace->mDomainBundle.mPhaseAConstants.mScatter;
    const std::uint64_t &aPhaseADomainWordCross = pWorkSpace->mDomainBundle.mPhaseAConstants.mCross;
    const std::uint64_t &aPhaseBDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseBConstants.mIngress;
    const std::uint64_t &aPhaseBDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseBConstants.mScatter;
    const std::uint64_t &aPhaseBDomainWordCross = pWorkSpace->mDomainBundle.mPhaseBConstants.mCross;
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
        //      aFireLaneA (-->), aFireLaneB (-->), aWorkLaneC (-->), aOperationLaneC (<-?->)
        //
        // Cross:
        //      aFireLaneC (<--), aFireLaneD (<--), aScrapLaneA (<-?->)
        //
        // Destination:
        //      aWaterLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFireLaneA[((aIndex + 4667U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((aIndex + 1068U)) & S_BLOCK1], 14U));
            aIngress ^= (RotL64(aWorkLaneC[((aIndex + 2669U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 3750U)) & S_BLOCK1], 23U));

            //
            aCross = (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 2228U)) & S_BLOCK1], 42U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 3879U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aScrapLaneA[((aIndex + 5290U)) & S_BLOCK1], 19U);

            aWaterLaneC[aIndex] = aIngress;
        }

        //
        // seed_loop_b loop 2
        //
        // Ingress:
        //      aWaterLaneC (-->), aFireLaneC (-->), aEarthLaneD (-->), aScrapLaneD (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), aScrapLaneB (<-?->)
        //
        // Destination:
        //      aWaterLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneC[((aIndex + 8799U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((aIndex + 6012U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aEarthLaneD[((aIndex + 10033U)) & S_BLOCK1], 21U) ^ RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 8542U)) & S_BLOCK1], 36U));

            //
            aCross = (RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6443U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6716U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 9421U)) & S_BLOCK1], 37U);

            aWaterLaneD[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // seed_loop_b loop 3
        //
        // Ingress:
        //      aWaterLaneD (-->), aFireLaneA (-->), aEarthLaneB (<-?->)
        //
        // Cross:
        //      aWaterLaneC (<--), aFireLaneC (<--), aKeyRowReadB (<-?->)
        //
        // Destination:
        //      aInvestLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneD[((aIndex + 13533U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneA[((aIndex + 15055U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 15630U)) & S_BLOCK1], 24U);

            //
            aCross = (RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 14422U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14431U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aKeyRowReadB[((aIndex + 11437U)) & W_KEY1], 57U);

            aInvestLaneA[aIndex] = aIngress;
        }

        //
        // seed_loop_b loop 4
        //
        // Ingress:
        //      aInvestLaneA (-->), aFireLaneD (-->), aEarthLaneC (<-?->)
        //
        // Cross:
        //      aWaterLaneD (<--), aFireLaneA (<--), aOperationLaneB (<-?->)
        //
        // Destination:
        //      aInvestLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 19438U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneD[((aIndex + 19107U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aEarthLaneC[((aIndex + 21348U)) & S_BLOCK1], 36U);

            //
            aCross = (RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 19244U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 19872U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 18750U)) & S_BLOCK1], 29U);

            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // seed_loop_b loop 5
        //
        // Ingress:
        //      aInvestLaneB (-->), aWaterLaneD (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aInvestLaneA (<--), aWaterLaneC (<--), aOperationLaneD (<-?->)
        //
        // Destination:
        //      aInvestLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 21944U)) & S_BLOCK1], 3U) ^ RotL64(aWaterLaneD[((aIndex + 26127U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 26322U)) & S_BLOCK1], 41U);

            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22916U)) & S_BLOCK1], 3U) ^ RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 26079U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 23768U)) & S_BLOCK1], 27U);

            aInvestLaneC[aIndex] = aIngress;
        }

        //
        // seed_loop_b loop 6
        //
        // Ingress:
        //      aInvestLaneC (-->), aInvestLaneA (-->), aScrapLaneC (<-?->)
        //
        // Cross:
        //      aInvestLaneB (<--), aFireLaneB (<--), aOperationLaneA (<-?->)
        //
        // Destination:
        //      aInvestLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 29676U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneA[((aIndex + 31694U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aScrapLaneC[((aIndex + 31546U)) & S_BLOCK1], 58U);

            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 32759U)) & S_BLOCK1], 14U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29704U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30898U)) & S_BLOCK1], 27U);

            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_E seed_loop_b (end)

}

void TwistExpander_Regulus_Arx::Seed_F() {
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
    // GSeedRunSeed_F seed_loop_c (start)
    {
        //
        // seed_loop_c loop 1
        //
        // Ingress:
        //      aInvestLaneA (-->), aInvestLaneB (-->), aEarthLaneD (-->), aSource (<-?->)
        //
        // Cross:
        //      aInvestLaneC (<--), aInvestLaneD (<--), aOperationLaneB (<-?->)
        //
        // Destination:
        //      aSnowLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 1754U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneB[((aIndex + 2326U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aEarthLaneD[((aIndex + 1274U)) & S_BLOCK1], 37U) ^ RotL64(aSource[((S_BLOCK1 - aIndex + 1244U)) & S_BLOCK1], 54U));

            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 3126U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 401U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2558U)) & S_BLOCK1], 43U);

            aSnowLaneC[aIndex] = aIngress;
        }

        //
        // seed_loop_c loop 2
        //
        // Ingress:
        //      aSnowLaneC (-->), aInvestLaneC (-->), aScrapLaneC (-->), aOperationLaneA (<-?->)
        //
        // Cross:
        //      aInvestLaneA (<--), aInvestLaneD (<--), aScrapLaneA (<-?->)
        //
        // Destination:
        //      aSnowLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 7347U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneC[((aIndex + 10020U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aScrapLaneC[((aIndex + 6812U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((aIndex + 5752U)) & S_BLOCK1], 57U));

            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 6735U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 6520U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 6348U)) & S_BLOCK1], 26U);

            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // seed_loop_c loop 3
        //
        // Ingress:
        //      aSnowLaneD (-->), aInvestLaneA (-->), aFireLaneD (-->), aOperationLaneD (<-?->)
        //
        // Cross:
        //      aSnowLaneC (<--), aInvestLaneC (<--), aWaterLaneC (<-?->)
        //
        // Destination:
        //      aWindLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 15054U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneA[((aIndex + 15667U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 11223U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12031U)) & S_BLOCK1], 19U));

            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 12746U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 16184U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 11284U)) & S_BLOCK1], 41U);

            aWindLaneA[aIndex] = aIngress;
        }

        //
        // seed_loop_c loop 4
        //
        // Ingress:
        //      aWindLaneA (-->), aInvestLaneD (-->), aScrapLaneD (-->), aOperationLaneC (<-?->)
        //
        // Cross:
        //      aSnowLaneD (<--), aInvestLaneA (<--), aScrapLaneB (<-?->)
        //
        // Destination:
        //      aWindLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWindLaneA[((aIndex + 18488U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneD[((aIndex + 18348U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aScrapLaneD[((aIndex + 18439U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 21096U)) & S_BLOCK1], 19U));

            //
            aCross = (RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 17366U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 20203U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aScrapLaneB[((aIndex + 20420U)) & S_BLOCK1], 58U);

            aWindLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // seed_loop_c loop 5
        //
        // Ingress:
        //      aWindLaneB (-->), aSnowLaneD (-->), aFireLaneA (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aSnowLaneC (<--), aFireLaneB (<-?->)
        //
        // Destination:
        //      aWindLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWindLaneB[((aIndex + 23499U)) & S_BLOCK1], 36U) ^ RotL64(aSnowLaneD[((aIndex + 22564U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24233U)) & S_BLOCK1], 11U);

            //
            aCross = (RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 24436U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 22310U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 27262U)) & S_BLOCK1], 41U);

            aWindLaneC[aIndex] = aIngress;
        }

        //
        // seed_loop_c loop 6
        //
        // Ingress:
        //      aWindLaneC (-->), aWindLaneA (-->), aWaterLaneD (<-?->)
        //
        // Cross:
        //      aWindLaneB (<--), aInvestLaneB (<--), aFireLaneC (<-?->)
        //
        // Destination:
        //      aWindLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWindLaneC[((aIndex + 32678U)) & S_BLOCK1], 13U) ^ RotL64(aWindLaneA[((aIndex + 29241U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWaterLaneD[((aIndex + 32768U)) & S_BLOCK1], 27U);

            //
            aCross = (RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 29662U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29561U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 29217U)) & S_BLOCK1], 57U);

            aWindLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_F seed_loop_c (end)

}

void TwistExpander_Regulus_Arx::Seed_G() {
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
    // GSeedRunSeed_G seed_loop_d (start)
    {
        //
        // seed_loop_d loop 1
        //
        // Ingress:
        //      aWindLaneA (-->), aWindLaneB (-->), aSnowLaneC (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aWindLaneC (<--), aWindLaneD (<--), aInvestLaneD (<-?->)
        //
        // Destination:
        //      aWaterLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWindLaneA[((aIndex + 4012U)) & S_BLOCK1], 37U) ^ RotL64(aWindLaneB[((aIndex + 296U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aSnowLaneC[((aIndex + 677U)) & S_BLOCK1], 20U) ^ RotL64(aKeyRowReadA[((aIndex + 3951U)) & W_KEY1], 11U));

            //
            aCross = (RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 5398U)) & S_BLOCK1], 29U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 993U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 43U)) & S_BLOCK1], 21U);

            aWaterLaneA[aIndex] = aIngress;
        }

        //
        // seed_loop_d loop 2
        //
        // Ingress:
        //      aWaterLaneA (-->), aWindLaneC (-->), aEarthLaneA (-->), aSnowLaneD (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aWindLaneD (<--), aWaterLaneC (<-?->)
        //
        // Destination:
        //      aWaterLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneA[((aIndex + 8820U)) & S_BLOCK1], 35U) ^ RotL64(aWindLaneC[((aIndex + 6299U)) & S_BLOCK1], 14U));
            aIngress ^= (RotL64(aEarthLaneA[((aIndex + 6076U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneD[((aIndex + 6949U)) & S_BLOCK1], 3U));

            //
            aCross = (RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 8680U)) & S_BLOCK1], 13U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 10914U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 7208U)) & S_BLOCK1], 52U);

            aWaterLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // seed_loop_d loop 3
        //
        // Ingress:
        //      aWaterLaneB (-->), aWindLaneA (-->), aFireLaneC (-->), aEarthLaneB (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWindLaneC (<--), aFireLaneD (<-?->)
        //
        // Destination:
        //      aOperationLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneB[((aIndex + 12749U)) & S_BLOCK1], 39U) ^ RotL64(aWindLaneA[((aIndex + 12651U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aFireLaneC[((aIndex + 11550U)) & S_BLOCK1], 47U) ^ RotL64(aEarthLaneB[((aIndex + 12266U)) & S_BLOCK1], 29U));

            //
            aCross = (RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 11768U)) & S_BLOCK1], 14U) ^ RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 13261U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 15539U)) & S_BLOCK1], 37U);

            aOperationLaneA[aIndex] = aIngress;
        }

        //
        // seed_loop_d loop 4
        //
        // Ingress:
        //      aOperationLaneA (-->), aWindLaneD (-->), aScrapLaneD (-->), aScrapLaneC (<-?->)
        //
        // Cross:
        //      aWaterLaneB (<--), aWindLaneA (<--), aFireLaneB (<-?->)
        //
        // Destination:
        //      aOperationLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16515U)) & S_BLOCK1], 23U) ^ RotL64(aWindLaneD[((aIndex + 16558U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aScrapLaneD[((aIndex + 19547U)) & S_BLOCK1], 43U) ^ RotL64(aScrapLaneC[((aIndex + 17533U)) & S_BLOCK1], 60U));

            //
            aCross = (RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 20887U)) & S_BLOCK1], 43U) ^ RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 18242U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 19151U)) & S_BLOCK1], 35U);

            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // seed_loop_d loop 5
        //
        // Ingress:
        //      aOperationLaneB (-->), aWaterLaneB (-->), aInvestLaneC (-->), aEarthLaneC (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aWaterLaneA (<--), aInvestLaneB (<-?->)
        //
        // Destination:
        //      aOperationLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26382U)) & S_BLOCK1], 19U) ^ RotL64(aWaterLaneB[((aIndex + 26723U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aInvestLaneC[((aIndex + 24294U)) & S_BLOCK1], 4U) ^ RotL64(aEarthLaneC[((aIndex + 25503U)) & S_BLOCK1], 35U));

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23173U)) & S_BLOCK1], 34U) ^ RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 23421U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 25816U)) & S_BLOCK1], 11U);

            aOperationLaneC[aIndex] = aIngress;
        }

        //
        // seed_loop_d loop 6
        //
        // Ingress:
        //      aOperationLaneC (-->), aOperationLaneA (-->), aWaterLaneD (-->), aInvestLaneA (<-?->)
        //
        // Cross:
        //      aOperationLaneB (<--), aWindLaneB (<--), aFireLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30576U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneA[((aIndex + 29081U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aWaterLaneD[((aIndex + 32405U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 29262U)) & S_BLOCK1], 21U));

            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29735U)) & S_BLOCK1], 11U) ^ RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 30335U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 30147U)) & S_BLOCK1], 57U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_G seed_loop_d (end)

}

void TwistExpander_Regulus_Arx::Seed_H() {
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
    // GSeedRunSeed_H seed_loop_e (start)
    {
        //
        // seed_loop_e loop 1
        //
        // Ingress:
        //      aOperationLaneA (-->), aOperationLaneB (-->), aSnowLaneC (-->), aWindLaneB (<-?->)
        //
        // Cross:
        //      aOperationLaneC (<--), aOperationLaneD (<--), aSnowLaneD (<-?->)
        //
        // Destination:
        //      aSnowLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2976U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneB[((aIndex + 4969U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aSnowLaneC[((aIndex + 127U)) & S_BLOCK1], 47U) ^ RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 3539U)) & S_BLOCK1], 23U));

            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2797U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4153U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 2765U)) & S_BLOCK1], 21U);

            aSnowLaneA[aIndex] = aIngress;
        }

        //
        // seed_loop_e loop 2
        //
        // Ingress:
        //      aSnowLaneA (-->), aOperationLaneC (-->), aInvestLaneC (-->), aWaterLaneB (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aOperationLaneD (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aSnowLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9132U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneC[((aIndex + 7086U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aInvestLaneC[((aIndex + 8371U)) & S_BLOCK1], 27U) ^ RotL64(aWaterLaneB[((aIndex + 9904U)) & S_BLOCK1], 19U));

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7585U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10293U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 10394U)) & S_BLOCK1], 40U);

            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // seed_loop_e loop 3
        //
        // Ingress:
        //      aSnowLaneB (-->), aOperationLaneA (-->), aWindLaneA (-->), aWindLaneD (<-?->)
        //
        // Cross:
        //      aSnowLaneA (<--), aOperationLaneC (<--), aFireLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15403U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 14558U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aWindLaneA[((aIndex + 15256U)) & S_BLOCK1], 23U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 15145U)) & S_BLOCK1], 38U));

            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 14882U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15853U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 12590U)) & S_BLOCK1], 22U);

            aFuseLaneA[aIndex] = aIngress;
        }

        //
        // seed_loop_e loop 4
        //
        // Ingress:
        //      aFuseLaneA (-->), aOperationLaneD (-->), aFireLaneB (-->), aInvestLaneB (<-?->)
        //
        // Cross:
        //      aSnowLaneB (<--), aOperationLaneA (<--), aInvestLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneA[((aIndex + 16540U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 20122U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aFireLaneB[((aIndex + 20777U)) & S_BLOCK1], 18U) ^ RotL64(aInvestLaneB[((aIndex + 16664U)) & S_BLOCK1], 53U));

            //
            aCross = (RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 21010U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21107U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 21503U)) & S_BLOCK1], 3U);

            aFuseLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // seed_loop_e loop 5
        //
        // Ingress:
        //      aFuseLaneB (-->), aSnowLaneB (-->), aExpandLaneD (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aSnowLaneA (<--), aKeyRowReadB (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneB[((aIndex + 26182U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneB[((aIndex + 23233U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26373U)) & S_BLOCK1], 54U);

            //
            aCross = (RotL64(aFuseLaneA[((S_BLOCK1 - aIndex + 26751U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 26806U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aKeyRowReadB[(((2047U - aIndex) + 23660U)) & W_KEY1], 38U);

            aFuseLaneC[aIndex] = aIngress;
        }

        //
        // seed_loop_e loop 6
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aWaterLaneA (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aOperationLaneB (<--), aInvestLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 29957U)) & S_BLOCK1], 21U) ^ RotL64(aFuseLaneA[((aIndex + 29782U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aWaterLaneA[((aIndex + 29542U)) & S_BLOCK1], 57U);

            //
            aCross = (RotL64(aFuseLaneB[((S_BLOCK1 - aIndex + 31977U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32069U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 27892U)) & S_BLOCK1], 30U);

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_H seed_loop_e (end)

}

void TwistExpander_Regulus_Arx::Seed_I() {
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
    // GSeedRunSeed_I seed_loop_f (start)
    {
        //
        // seed_loop_f loop 1
        //
        // Ingress:
        //      aInvestLaneE (-->), aInvestLaneF (-->), aExpandLaneA (-->), aWaterLaneB (<-?->)
        //
        // Cross:
        //      aInvestLaneG (<--), aInvestLaneH (<--), aFireLaneD (<-?->)
        //
        // Destination:
        //      aSnowLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneE[((aIndex + 5412U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneF[((aIndex + 1979U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aExpandLaneA[((aIndex + 4184U)) & S_BLOCK1], 13U) ^ RotL64(aWaterLaneB[((aIndex + 3292U)) & S_BLOCK1], 29U));

            //
            aCross = (RotL64(aInvestLaneG[((S_BLOCK1 - aIndex + 2026U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneH[((S_BLOCK1 - aIndex + 5459U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 1407U)) & S_BLOCK1], 19U);

            aSnowLaneC[aIndex] = aIngress;
        }

        //
        // seed_loop_f loop 2
        //
        // Ingress:
        //      aSnowLaneC (-->), aInvestLaneG (-->), aOperationLaneC (-->), aWindLaneA (<-?->)
        //
        // Cross:
        //      aInvestLaneE (<--), aInvestLaneH (<--), aOperationLaneD (<-?->)
        //
        // Destination:
        //      aSnowLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 10432U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneG[((aIndex + 10772U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aOperationLaneC[((aIndex + 8860U)) & S_BLOCK1], 13U) ^ RotL64(aWindLaneA[((aIndex + 8563U)) & S_BLOCK1], 37U));

            //
            aCross = (RotL64(aInvestLaneE[((S_BLOCK1 - aIndex + 8176U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneH[((S_BLOCK1 - aIndex + 8930U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8025U)) & S_BLOCK1], 22U);

            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // seed_loop_f loop 3
        //
        // Ingress:
        //      aSnowLaneD (-->), aInvestLaneE (-->), aWindLaneD (-->), aOperationLaneB (<-?->)
        //
        // Cross:
        //      aSnowLaneC (<--), aInvestLaneG (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aWorkLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 13033U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneE[((aIndex + 12962U)) & S_BLOCK1], 28U));
            aIngress ^= (RotL64(aWindLaneD[((aIndex + 15357U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 10982U)) & S_BLOCK1], 13U));

            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 16146U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneG[((S_BLOCK1 - aIndex + 12247U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 13990U)) & S_BLOCK1], 5U);

            aWorkLaneA[aIndex] = aIngress;
        }

        //
        // seed_loop_f loop 4
        //
        // Ingress:
        //      aWorkLaneA (-->), aInvestLaneH (-->), aWaterLaneA (-->), aExpandLaneB (<-?->)
        //
        // Cross:
        //      aSnowLaneD (<--), aInvestLaneE (<--), aFireLaneC (<-?->)
        //
        // Destination:
        //      aWorkLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 20510U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneH[((aIndex + 20127U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aWaterLaneA[((aIndex + 16888U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19138U)) & S_BLOCK1], 13U));

            //
            aCross = (RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 17675U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneE[((S_BLOCK1 - aIndex + 19106U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 17245U)) & S_BLOCK1], 41U);

            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // seed_loop_f loop 5
        //
        // Ingress:
        //      aWorkLaneB (-->), aSnowLaneD (-->), aSnowLaneB (<-?->)
        //
        // Cross:
        //      aWorkLaneA (<--), aSnowLaneC (<--), aSnowLaneA (<-?->)
        //
        // Destination:
        //      aWorkLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23513U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneD[((aIndex + 23678U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aSnowLaneB[((aIndex + 24674U)) & S_BLOCK1], 29U);

            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25912U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 22699U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aSnowLaneA[((aIndex + 24379U)) & S_BLOCK1], 35U);

            aWorkLaneC[aIndex] = aIngress;
        }

        //
        // seed_loop_f loop 6
        //
        // Ingress:
        //      aWorkLaneC (-->), aWorkLaneA (-->), aWindLaneB (<-?->)
        //
        // Cross:
        //      aWorkLaneB (<--), aInvestLaneF (<--), aOperationLaneA (<-?->)
        //
        // Destination:
        //      aWorkLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31507U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneA[((aIndex + 28875U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWindLaneB[((aIndex + 29186U)) & S_BLOCK1], 27U);

            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29477U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneF[((S_BLOCK1 - aIndex + 28510U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 28167U)) & S_BLOCK1], 43U);

            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_I seed_loop_f (end)

}

void TwistExpander_Regulus_Arx::Twist_A() {
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
            aIngress = RotL64(aSource[((aIndex + 421U)) & S_BLOCK1], 46U) ^ RotL64(aKeyRowReadA[((aIndex + 4966U)) & W_KEY1], 21U);

            //
            aCross = RotL64(aSource[((S_BLOCK1 - aIndex + 3319U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 2640U)) & W_KEY1], 6U);

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
            aIngress = RotL64(aScrapLaneA[((aIndex + 8822U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadB[((aIndex + 7289U)) & W_KEY1], 14U);

            //
            aCross = RotL64(aSource[((S_BLOCK1 - aIndex + 7169U)) & S_BLOCK1], 46U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 9756U)) & W_KEY1], 27U);

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
            aIngress = (RotL64(aScrapLaneB[((aIndex + 13700U)) & S_BLOCK1], 35U) ^ RotL64(aSource[((aIndex + 11578U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aKeyRowReadB[((aIndex + 15107U)) & W_KEY1], 24U);

            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 15606U)) & W_KEY1], 29U) ^ RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 15972U)) & S_BLOCK1], 20U);

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
            aIngress = RotL64(aWindLaneA[((aIndex + 18805U)) & S_BLOCK1], 56U) ^ RotL64(aScrapLaneA[((aIndex + 17534U)) & S_BLOCK1], 21U);

            //
            aCross = RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 18960U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadB[((aIndex + 20585U)) & W_KEY1], 18U);

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
            aIngress = RotL64(aWindLaneB[((aIndex + 25042U)) & S_BLOCK1], 13U) ^ RotL64(aScrapLaneB[((aIndex + 22803U)) & S_BLOCK1], 42U);

            //
            aCross = RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 24304U)) & S_BLOCK1], 58U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 21974U)) & W_KEY1], 3U);

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
            aIngress = RotL64(aWindLaneC[((aIndex + 27945U)) & S_BLOCK1], 50U) ^ RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 28857U)) & S_BLOCK1], 13U);

            //
            aCross = RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 29701U)) & S_BLOCK1], 10U) ^ RotL64(aScrapLaneB[((aIndex + 31108U)) & S_BLOCK1], 43U);

            aWindLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_A twist_loop_a (end)

}

void TwistExpander_Regulus_Arx::Twist_B() {
    // [twist arx]
    // GTwistRunTwist_B twist_loop_b (start)
    {
        //
        // twist_loop_b loop 1
        //
        // Ingress:
        //      aWindLaneA (-->), aWindLaneB (-->), aScrapLaneA (<-?->)
        //
        // Cross:
        //      aWindLaneC (<--), aWindLaneD (<-?->)
        //
        // Destination:
        //      aWorkLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWindLaneA[((aIndex + 3468U)) & S_BLOCK1], 5U) ^ RotL64(aWindLaneB[((aIndex + 3477U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aScrapLaneA[((aIndex + 3414U)) & S_BLOCK1], 60U);

            //
            aCross = RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 584U)) & S_BLOCK1], 38U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 3717U)) & S_BLOCK1], 29U);

            aWorkLaneA[aIndex] = aIngress;
        }

        //
        // twist_loop_b loop 2
        //
        // Ingress:
        //      aWorkLaneA (-->), aWindLaneC (-->), aScrapLaneB (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aWindLaneD (<--)
        //
        // Destination:
        //      aWorkLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9011U)) & S_BLOCK1], 3U) ^ RotL64(aWindLaneC[((aIndex + 6293U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aScrapLaneB[((aIndex + 7555U)) & S_BLOCK1], 40U);

            //
            aCross = RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 5891U)) & S_BLOCK1], 29U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 6319U)) & S_BLOCK1], 50U);

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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 15976U)) & S_BLOCK1], 57U) ^ RotL64(aWindLaneA[((aIndex + 13586U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aKeyRowReadA[((aIndex + 12009U)) & W_KEY1], 14U);

            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14719U)) & S_BLOCK1], 11U) ^ RotL64(aWindLaneC[((aIndex + 14346U)) & S_BLOCK1], 60U);

            aSnowLaneA[aIndex] = aIngress;
        }

        //
        // twist_loop_b loop 4
        //
        // Ingress:
        //      aSnowLaneA (-->), aWindLaneD (-->), aSource (<-?->)
        //
        // Cross:
        //      aWorkLaneB (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aSnowLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 20566U)) & S_BLOCK1], 51U) ^ RotL64(aWindLaneD[((aIndex + 16984U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aSource[((aIndex + 20582U)) & S_BLOCK1], 4U);

            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17263U)) & S_BLOCK1], 51U) ^ RotL64(aWindLaneA[((aIndex + 17799U)) & S_BLOCK1], 36U);

            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // twist_loop_b loop 5
        //
        // Ingress:
        //      aSnowLaneB (-->), aWorkLaneB (-->), aKeyRowReadB (<-?->)
        //
        // Cross:
        //      aSnowLaneA (<--), aWorkLaneA (<-?->)
        //
        // Destination:
        //      aSnowLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 23806U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 22290U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aKeyRowReadB[(((2047U - aIndex) + 26837U)) & W_KEY1], 48U);

            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 24066U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 24441U)) & S_BLOCK1], 4U);

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
            aIngress = RotL64(aSnowLaneC[((aIndex + 28503U)) & S_BLOCK1], 10U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 30087U)) & S_BLOCK1], 39U);

            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 32440U)) & S_BLOCK1], 19U) ^ RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 28800U)) & S_BLOCK1], 60U);

            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_B twist_loop_b (end)

}

void TwistExpander_Regulus_Arx::Twist_C() {
    // [twist arx]
    // GTwistRunTwist_C twist_loop_c (start)
    {
        //
        // twist_loop_c loop 1
        //
        // Ingress:
        //      aSnowLaneA (-->), aSnowLaneB (-->), aWorkLaneB (<-?->)
        //
        // Cross:
        //      aSnowLaneC (<--), aSnowLaneD (<--), aWindLaneD (<-?->)
        //
        // Destination:
        //      aInvestLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 3917U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneB[((aIndex + 2562U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 3971U)) & S_BLOCK1], 5U);

            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 1390U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 4337U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 1237U)) & S_BLOCK1], 3U);

            aInvestLaneA[aIndex] = aIngress;
        }

        //
        // twist_loop_c loop 2
        //
        // Ingress:
        //      aInvestLaneA (-->), aSnowLaneC (-->), aWorkLaneA (<-?->)
        //
        // Cross:
        //      aSnowLaneA (<--), aSnowLaneD (<--), aSource (<-?->)
        //
        // Destination:
        //      aInvestLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 6669U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneC[((aIndex + 6941U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 8970U)) & S_BLOCK1], 54U);

            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 8181U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 9654U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aSource[((S_BLOCK1 - aIndex + 9759U)) & S_BLOCK1], 5U);

            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // twist_loop_c loop 3
        //
        // Ingress:
        //      aInvestLaneB (-->), aSnowLaneA (-->), aScrapLaneB (<-?->)
        //
        // Cross:
        //      aInvestLaneA (<--), aSnowLaneC (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aOperationLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 14928U)) & S_BLOCK1], 40U) ^ RotL64(aSnowLaneA[((aIndex + 12902U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 13591U)) & S_BLOCK1], 5U);

            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 11438U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 15865U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 11073U)) & S_BLOCK1], 30U);

            aOperationLaneA[aIndex] = aIngress;
        }

        //
        // twist_loop_c loop 4
        //
        // Ingress:
        //      aOperationLaneA (-->), aSnowLaneD (-->), aScrapLaneA (<-?->)
        //
        // Cross:
        //      aInvestLaneB (<--), aSnowLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16823U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneD[((aIndex + 20228U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 17385U)) & S_BLOCK1], 56U);

            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 21599U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 17395U)) & S_BLOCK1], 26U);

            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // twist_loop_c loop 5
        //
        // Ingress:
        //      aOperationLaneB (-->), aInvestLaneB (-->), aWindLaneA (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aInvestLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26418U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneB[((aIndex + 25074U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aWindLaneA[((aIndex + 26120U)) & S_BLOCK1], 11U);

            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24681U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24038U)) & S_BLOCK1], 6U);

            aOperationLaneC[aIndex] = aIngress;
        }

        //
        // twist_loop_c loop 6
        //
        // Ingress:
        //      aOperationLaneC (-->), aOperationLaneA (-->), aWindLaneB (<-?->)
        //
        // Cross:
        //      aOperationLaneB (<--), aSnowLaneB (<--)
        //
        // Destination:
        //      aOperationLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28700U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 28537U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 28300U)) & S_BLOCK1], 56U);

            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29463U)) & S_BLOCK1], 6U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 30104U)) & S_BLOCK1], 29U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_C twist_loop_c (end)

}

void TwistExpander_Regulus_Arx::Twist_D() {
    // [twist arx]
    // GTwistRunTwist_D twist_loop_d (start)
    {
        //
        // twist_loop_d loop 1
        //
        // Ingress:
        //      aOperationLaneA (-->), aOperationLaneB (-->), aWindLaneD (<-?->)
        //
        // Cross:
        //      aOperationLaneC (<--), aOperationLaneD (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aScrapLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4519U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 553U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWindLaneD[((aIndex + 1399U)) & S_BLOCK1], 6U);

            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4390U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1391U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 2504U)) & S_BLOCK1], 56U);

            aScrapLaneC[aIndex] = aIngress;
        }

        //
        // twist_loop_d loop 2
        //
        // Ingress:
        //      aScrapLaneC (-->), aOperationLaneC (-->), aSnowLaneB (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aOperationLaneD (<--), aInvestLaneB (<-?->)
        //
        // Destination:
        //      aScrapLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneC[((aIndex + 8347U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 10116U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 7013U)) & S_BLOCK1], 27U);

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9798U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8779U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 5918U)) & S_BLOCK1], 36U);

            aScrapLaneD[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // twist_loop_d loop 3
        //
        // Ingress:
        //      aScrapLaneD (-->), aOperationLaneA (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aScrapLaneC (<--), aOperationLaneC (<--), aSnowLaneA (<-?->)
        //
        // Destination:
        //      aWaterLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneD[((aIndex + 13334U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 16072U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aKeyRowReadA[((aIndex + 15141U)) & W_KEY1], 21U);

            //
            aCross = (RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 15393U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14918U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11870U)) & S_BLOCK1], 53U);

            aWaterLaneA[aIndex] = aIngress;
        }

        //
        // twist_loop_d loop 4
        //
        // Ingress:
        //      aWaterLaneA (-->), aOperationLaneD (-->), aInvestLaneA (<-?->)
        //
        // Cross:
        //      aScrapLaneD (<--), aOperationLaneA (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aWaterLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneA[((aIndex + 19080U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((aIndex + 19823U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 16441U)) & S_BLOCK1], 10U);

            //
            aCross = (RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 18680U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17610U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWindLaneC[((aIndex + 16475U)) & S_BLOCK1], 20U);

            aWaterLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // twist_loop_d loop 5
        //
        // Ingress:
        //      aWaterLaneB (-->), aScrapLaneD (-->), aWindLaneB (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aScrapLaneC (<--), aSnowLaneC (<-?->)
        //
        // Destination:
        //      aWaterLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneB[((aIndex + 24251U)) & S_BLOCK1], 13U) ^ RotL64(aScrapLaneD[((aIndex + 22068U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 25206U)) & S_BLOCK1], 58U);

            //
            aCross = (RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 26214U)) & S_BLOCK1], 21U) ^ RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 24783U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aSnowLaneC[((aIndex + 22969U)) & S_BLOCK1], 56U);

            aWaterLaneC[aIndex] = aIngress;
        }

        //
        // twist_loop_d loop 6
        //
        // Ingress:
        //      aWaterLaneC (-->), aWaterLaneA (-->), aSnowLaneD (<-?->)
        //
        // Cross:
        //      aWaterLaneB (<--), aOperationLaneB (<--)
        //
        // Destination:
        //      aWaterLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneC[((aIndex + 31702U)) & S_BLOCK1], 35U) ^ RotL64(aWaterLaneA[((aIndex + 32483U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 32528U)) & S_BLOCK1], 24U);

            //
            aCross = RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 28867U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30703U)) & S_BLOCK1], 34U);

            aWaterLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_D twist_loop_d (end)

}

void TwistExpander_Regulus_Arx::Twist_E() {
    // [twist arx]
    // GTwistRunTwist_E twist_loop_e (start)
    {
        //
        // twist_loop_e loop 1
        //
        // Ingress:
        //      aWaterLaneA (-->), aWaterLaneB (-->), aOperationLaneA (<-?->)
        //
        // Cross:
        //      aWaterLaneC (<--), aWaterLaneD (<--), aSnowLaneD (<-?->)
        //
        // Destination:
        //      aInvestLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneA[((aIndex + 1965U)) & S_BLOCK1], 46U) ^ RotL64(aWaterLaneB[((aIndex + 4765U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 2384U)) & S_BLOCK1], 27U);

            //
            aCross = (RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 545U)) & S_BLOCK1], 46U) ^ RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 1561U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aSnowLaneD[((aIndex + 1787U)) & S_BLOCK1], 57U);

            aInvestLaneC[aIndex] = aIngress;
        }

        //
        // twist_loop_e loop 2
        //
        // Ingress:
        //      aInvestLaneC (-->), aWaterLaneC (-->), aSnowLaneC (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWaterLaneD (<--), aOperationLaneC (<-?->)
        //
        // Destination:
        //      aInvestLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 7146U)) & S_BLOCK1], 41U) ^ RotL64(aWaterLaneC[((aIndex + 6935U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 8861U)) & S_BLOCK1], 28U);

            //
            aCross = (RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 8958U)) & S_BLOCK1], 13U) ^ RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 7706U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 7556U)) & S_BLOCK1], 24U);

            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // twist_loop_e loop 3
        //
        // Ingress:
        //      aInvestLaneD (-->), aWaterLaneA (-->), aInvestLaneA (<-?->)
        //
        // Cross:
        //      aInvestLaneC (<--), aWaterLaneC (<--), aOperationLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 12741U)) & S_BLOCK1], 46U) ^ RotL64(aWaterLaneA[((aIndex + 15404U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 14050U)) & S_BLOCK1], 29U);

            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11494U)) & S_BLOCK1], 47U) ^ RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 12563U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16314U)) & S_BLOCK1], 39U);

            aFuseLaneA[aIndex] = aIngress;
        }

        //
        // twist_loop_e loop 4
        //
        // Ingress:
        //      aFuseLaneA (-->), aWaterLaneD (-->), aScrapLaneD (<-?->)
        //
        // Cross:
        //      aInvestLaneD (<--), aWaterLaneA (<--), aSnowLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneA[((aIndex + 21258U)) & S_BLOCK1], 39U) ^ RotL64(aWaterLaneD[((aIndex + 16750U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aScrapLaneD[((aIndex + 17905U)) & S_BLOCK1], 29U);

            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 21085U)) & S_BLOCK1], 29U) ^ RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 20975U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aSnowLaneB[((aIndex + 17347U)) & S_BLOCK1], 3U);

            aFuseLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // twist_loop_e loop 5
        //
        // Ingress:
        //      aFuseLaneB (-->), aInvestLaneD (-->), aSnowLaneA (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aInvestLaneC (<--), aKeyRowReadB (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneB[((aIndex + 26309U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneD[((aIndex + 22667U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 23472U)) & S_BLOCK1], 52U);

            //
            aCross = (RotL64(aFuseLaneA[((S_BLOCK1 - aIndex + 23294U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 25740U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aKeyRowReadB[((aIndex + 25492U)) & W_KEY1], 35U);

            aFuseLaneC[aIndex] = aIngress;
        }

        //
        // twist_loop_e loop 6
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aOperationLaneB (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aWaterLaneB (<--), aScrapLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 29660U)) & S_BLOCK1], 53U) ^ RotL64(aFuseLaneA[((aIndex + 31232U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 32221U)) & S_BLOCK1], 6U);

            //
            aCross = (RotL64(aFuseLaneB[((S_BLOCK1 - aIndex + 32035U)) & S_BLOCK1], 11U) ^ RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 29646U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aScrapLaneC[((aIndex + 32169U)) & S_BLOCK1], 53U);

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_E twist_loop_e (end)

}

void TwistExpander_Regulus_Arx::Twist_F() {
    // [twist arx]
    // GTwistRunTwist_F twist_loop_f (start)
    {
        //
        // twist_loop_f loop 1
        //
        // Ingress:
        //      aFireLaneA (-->), aFireLaneB (-->), aScrapLaneB (-->), aScrapLaneD (<-?->)
        //
        // Cross:
        //      aFireLaneC (<--), aFireLaneD (<--), aScrapLaneA (<-?->)
        //
        // Destination:
        //      aInvestLaneE
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFireLaneA[((aIndex + 1242U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((aIndex + 4078U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aScrapLaneB[((aIndex + 4781U)) & S_BLOCK1], 37U) ^ RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 4423U)) & S_BLOCK1], 14U));

            //
            aCross = (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 233U)) & S_BLOCK1], 46U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 4319U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 4921U)) & S_BLOCK1], 19U);

            aInvestLaneE[aIndex] = aIngress;
        }

        //
        // twist_loop_f loop 2
        //
        // Ingress:
        //      aInvestLaneE (-->), aFireLaneC (-->), aWaterLaneC (-->), aSource (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), aSnowLaneB (<-?->)
        //
        // Destination:
        //      aInvestLaneF
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneE[((aIndex + 9245U)) & S_BLOCK1], 4U) ^ RotL64(aFireLaneC[((aIndex + 9845U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aWaterLaneC[((aIndex + 6153U)) & S_BLOCK1], 13U) ^ RotL64(aSource[((S_BLOCK1 - aIndex + 6410U)) & S_BLOCK1], 35U));

            //
            aCross = (RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 8779U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 5547U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aSnowLaneB[((aIndex + 6783U)) & S_BLOCK1], 27U);

            aInvestLaneF[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // twist_loop_f loop 3
        //
        // Ingress:
        //      aInvestLaneF (-->), aFireLaneA (-->), aScrapLaneC (-->), aInvestLaneC (<-?->)
        //
        // Cross:
        //      aInvestLaneE (<--), aFireLaneC (<--), aOperationLaneD (<-?->)
        //
        // Destination:
        //      aEarthLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneF[((aIndex + 12373U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneA[((aIndex + 12754U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aScrapLaneC[((aIndex + 15119U)) & S_BLOCK1], 14U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 15347U)) & S_BLOCK1], 5U));

            //
            aCross = (RotL64(aInvestLaneE[((S_BLOCK1 - aIndex + 14121U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15044U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 14366U)) & S_BLOCK1], 3U);

            aEarthLaneA[aIndex] = aIngress;
        }

        //
        // twist_loop_f loop 4
        //
        // Ingress:
        //      aEarthLaneA (-->), aFireLaneD (-->), aOperationLaneC (-->), aWaterLaneB (<-?->)
        //
        // Cross:
        //      aInvestLaneF (<--), aFireLaneA (<--), aWaterLaneD (<-?->)
        //
        // Destination:
        //      aEarthLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneA[((aIndex + 17658U)) & S_BLOCK1], 10U) ^ RotL64(aFireLaneD[((aIndex + 21080U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aOperationLaneC[((aIndex + 19526U)) & S_BLOCK1], 41U) ^ RotL64(aWaterLaneB[((aIndex + 21132U)) & S_BLOCK1], 23U));

            //
            aCross = (RotL64(aInvestLaneF[((S_BLOCK1 - aIndex + 19194U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17415U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 19293U)) & S_BLOCK1], 56U);

            aEarthLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // twist_loop_f loop 5
        //
        // Ingress:
        //      aEarthLaneB (-->), aInvestLaneF (-->), aWaterLaneA (-->), aOperationLaneB (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aInvestLaneE (<--), aSnowLaneA (<-?->)
        //
        // Destination:
        //      aEarthLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneB[((aIndex + 25017U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneF[((aIndex + 26036U)) & S_BLOCK1], 6U));
            aIngress ^= (RotL64(aWaterLaneA[((aIndex + 24407U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24661U)) & S_BLOCK1], 23U));

            //
            aCross = (RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 22855U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneE[((S_BLOCK1 - aIndex + 25518U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aSnowLaneA[((aIndex + 24015U)) & S_BLOCK1], 11U);

            aEarthLaneC[aIndex] = aIngress;
        }

        //
        // twist_loop_f loop 6
        //
        // Ingress:
        //      aEarthLaneC (-->), aEarthLaneA (-->), aInvestLaneB (-->), aInvestLaneD (<-?->)
        //
        // Cross:
        //      aEarthLaneB (<--), aFireLaneB (<--), aOperationLaneA (<-?->)
        //
        // Destination:
        //      aEarthLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneC[((aIndex + 29220U)) & S_BLOCK1], 19U) ^ RotL64(aEarthLaneA[((aIndex + 30934U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aInvestLaneB[((aIndex + 31995U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 32006U)) & S_BLOCK1], 6U));

            //
            aCross = (RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 31881U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 30855U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 28663U)) & S_BLOCK1], 46U);

            aEarthLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_F twist_loop_f (end)

}

void TwistExpander_Regulus_Arx::Twist_G() {
    // [twist arx]
    // GTwistRunTwist_G twist_loop_g (start)
    {
        //
        // twist_loop_g loop 1
        //
        // Ingress:
        //      aEarthLaneA (-->), aEarthLaneB (-->), aInvestLaneF (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aEarthLaneC (<--), aEarthLaneD (<--), aSnowLaneD (<-?->)
        //
        // Destination:
        //      aInvestLaneG
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneA[((aIndex + 2367U)) & S_BLOCK1], 58U) ^ RotL64(aEarthLaneB[((aIndex + 3320U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aInvestLaneF[((aIndex + 1470U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 3662U)) & W_KEY1], 21U));

            //
            aCross = (RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 5296U)) & S_BLOCK1], 3U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 4403U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 176U)) & S_BLOCK1], 35U);

            aInvestLaneG[aIndex] = aIngress;
        }

        //
        // twist_loop_g loop 2
        //
        // Ingress:
        //      aInvestLaneG (-->), aEarthLaneC (-->), aFireLaneD (-->), aWaterLaneD (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aEarthLaneD (<--), aInvestLaneC (<-?->)
        //
        // Destination:
        //      aInvestLaneH
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneG[((aIndex + 5470U)) & S_BLOCK1], 34U) ^ RotL64(aEarthLaneC[((aIndex + 10863U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 6799U)) & S_BLOCK1], 5U) ^ RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 7805U)) & S_BLOCK1], 51U));

            //
            aCross = (RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 7902U)) & S_BLOCK1], 23U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 10314U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aInvestLaneC[((aIndex + 5852U)) & S_BLOCK1], 5U);

            aInvestLaneH[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // twist_loop_g loop 3
        //
        // Ingress:
        //      aInvestLaneH (-->), aEarthLaneA (-->), aInvestLaneA (-->), aKeyRowReadB (<-?->)
        //
        // Cross:
        //      aInvestLaneG (<--), aEarthLaneC (<--), aWaterLaneA (<-?->)
        //
        // Destination:
        //      aWorkLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneH[((aIndex + 15288U)) & S_BLOCK1], 43U) ^ RotL64(aEarthLaneA[((aIndex + 16364U)) & S_BLOCK1], 30U));
            aIngress ^= (RotL64(aInvestLaneA[((aIndex + 16254U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14341U)) & W_KEY1], 3U));

            //
            aCross = (RotL64(aInvestLaneG[((S_BLOCK1 - aIndex + 16000U)) & S_BLOCK1], 40U) ^ RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 12739U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWaterLaneA[((aIndex + 11609U)) & S_BLOCK1], 51U);

            aWorkLaneA[aIndex] = aIngress;
        }

        //
        // twist_loop_g loop 4
        //
        // Ingress:
        //      aWorkLaneA (-->), aEarthLaneD (-->), aWaterLaneB (-->), aFireLaneC (<-?->)
        //
        // Cross:
        //      aInvestLaneH (<--), aEarthLaneA (<--), aInvestLaneE (<-?->)
        //
        // Destination:
        //      aWorkLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 19783U)) & S_BLOCK1], 57U) ^ RotL64(aEarthLaneD[((aIndex + 18715U)) & S_BLOCK1], 46U));
            aIngress ^= (RotL64(aWaterLaneB[((aIndex + 18657U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 19493U)) & S_BLOCK1], 35U));

            //
            aCross = (RotL64(aInvestLaneH[((S_BLOCK1 - aIndex + 16621U)) & S_BLOCK1], 47U) ^ RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 17383U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aInvestLaneE[((aIndex + 17864U)) & S_BLOCK1], 18U);

            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // twist_loop_g loop 5
        //
        // Ingress:
        //      aWorkLaneB (-->), aInvestLaneH (-->), aInvestLaneB (-->), aFireLaneB (<-?->)
        //
        // Cross:
        //      aWorkLaneA (<--), aInvestLaneG (<--), aWaterLaneC (<-?->)
        //
        // Destination:
        //      aWorkLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 25894U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneH[((aIndex + 22977U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aInvestLaneB[((aIndex + 26547U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((aIndex + 25981U)) & S_BLOCK1], 58U));

            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24678U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneG[((S_BLOCK1 - aIndex + 26413U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aWaterLaneC[((aIndex + 22982U)) & S_BLOCK1], 21U);

            aWorkLaneC[aIndex] = aIngress;
        }

        //
        // twist_loop_g loop 6
        //
        // Ingress:
        //      aWorkLaneC (-->), aWorkLaneA (-->), aSnowLaneC (-->), aFireLaneA (<-?->)
        //
        // Cross:
        //      aWorkLaneB (<--), aEarthLaneB (<--), aInvestLaneD (<-?->)
        //
        // Destination:
        //      aWorkLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28891U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 30434U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aSnowLaneC[((aIndex + 32388U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 28927U)) & S_BLOCK1], 28U));

            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28667U)) & S_BLOCK1], 56U) ^ RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 32432U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 29628U)) & S_BLOCK1], 19U);

            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_G twist_loop_g (end)

}

void TwistExpander_Regulus_Arx::GROW_A() {
    // [grow arx]
    // GROW_A grow_key_a (start)
    {
        //
        // grow_key_a loop 1
        //
        // Ingress:
        //      aWorkLaneA (-->), aWorkLaneB (-->), aWaterLaneC (-->), aInvestLaneE (<-?->)
        //
        // Cross:
        //      aWorkLaneC (<--), aWorkLaneD (<--), aOperationLaneC (<-?->)
        //
        // Destination:
        //      aOperationLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 3464U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 1914U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aWaterLaneC[((aIndex + 1281U)) & S_BLOCK1], 42U) ^ RotL64(aInvestLaneE[((S_BLOCK1 - aIndex + 3212U)) & S_BLOCK1], 3U));

            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5262U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2503U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3349U)) & S_BLOCK1], 41U);

            aOperationLaneB[aIndex] = aIngress;
        }

        //
        // grow_key_a loop 2
        //
        // Ingress:
        //      aOperationLaneB (-->), aWorkLaneC (-->), aInvestLaneB (-->), aFireLaneD (<-?->)
        //
        // Cross:
        //      aWorkLaneA (<--), aWorkLaneD (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aOperationLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 7331U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 10760U)) & S_BLOCK1], 18U));
            aIngress ^= (RotL64(aInvestLaneB[((aIndex + 8818U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneD[((aIndex + 6282U)) & S_BLOCK1], 47U));

            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7536U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9095U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aEarthLaneB[((aIndex + 8205U)) & S_BLOCK1], 47U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // grow_key_a loop 3
        //
        // Ingress:
        //      aOperationLaneD (-->), aWorkLaneA (-->), aFireLaneB (-->), aScrapLaneB (<-?->)
        //
        // Cross:
        //      aOperationLaneB (<--), aWorkLaneC (<--), aInvestLaneF (<-?->)
        //
        // Destination:
        //      aExpandLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneD[((aIndex + 14740U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((aIndex + 11118U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aFireLaneB[((aIndex + 16055U)) & S_BLOCK1], 13U) ^ RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 12245U)) & S_BLOCK1], 41U));

            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15415U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14749U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneF[((aIndex + 14571U)) & S_BLOCK1], 47U);

            aExpandLaneA[aIndex] = aIngress;
        }

        //
        // grow_key_a loop 4
        //
        // Ingress:
        //      aExpandLaneA (-->), aWorkLaneD (-->), aWaterLaneA (-->), aScrapLaneD (<-?->)
        //
        // Cross:
        //      aOperationLaneD (<--), aWorkLaneA (<--), aScrapLaneA (<-?->)
        //
        // Destination:
        //      aExpandLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17514U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneD[((aIndex + 19027U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aWaterLaneA[((aIndex + 16790U)) & S_BLOCK1], 29U) ^ RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 18181U)) & S_BLOCK1], 21U));

            //
            aCross = (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21000U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20511U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 18271U)) & S_BLOCK1], 5U);

            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // grow_key_a loop 5
        //
        // Ingress:
        //      aExpandLaneB (-->), aOperationLaneD (-->), aInvestLaneA (-->), aScrapLaneC (<-?->)
        //
        // Cross:
        //      aExpandLaneA (<--), aOperationLaneB (<--), aOperationLaneA (<-?->)
        //
        // Destination:
        //      aExpandLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23236U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneD[((aIndex + 23240U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aInvestLaneA[((aIndex + 22921U)) & S_BLOCK1], 3U) ^ RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 21954U)) & S_BLOCK1], 39U));

            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26340U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26036U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25879U)) & S_BLOCK1], 27U);

            aExpandLaneC[aIndex] = aIngress;
        }

        //
        // grow_key_a loop 6
        //
        // Ingress:
        //      aExpandLaneC (-->), aExpandLaneA (-->), aSnowLaneD (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aExpandLaneB (<--), aWorkLaneB (<--), aSnowLaneB (<-?->)
        //
        // Destination:
        //      aExpandLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28900U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 31098U)) & S_BLOCK1], 46U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 30340U)) & S_BLOCK1], 21U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 29635U)) & S_BLOCK1], 5U));

            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29238U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32475U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 31390U)) & S_BLOCK1], 60U);

            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GROW_A grow_key_a (end)

}

void TwistExpander_Regulus_Arx::GROW_B() {
    // [grow arx]
    // GROW_B grow_key_b (start)
    {
        //
        // grow_key_b loop 1
        //
        // Ingress:
        //      aExpandLaneA (-->), aExpandLaneB (-->), aInvestLaneC (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aExpandLaneC (<--), aExpandLaneD (<--), aSnowLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 238U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 2482U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aInvestLaneC[((aIndex + 1537U)) & S_BLOCK1], 11U) ^ RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 1171U)) & S_BLOCK1], 54U));

            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4239U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4722U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 2791U)) & S_BLOCK1], 39U);

            aFuseLaneC[aIndex] = aIngress;
        }

        //
        // grow_key_b loop 2
        //
        // Ingress:
        //      aFuseLaneC (-->), aExpandLaneC (-->), aInvestLaneG (-->), aOperationLaneD (<-?->)
        //
        // Cross:
        //      aExpandLaneA (<--), aExpandLaneD (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 6297U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 6741U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aInvestLaneG[((aIndex + 9261U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 5828U)) & S_BLOCK1], 58U));

            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8891U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5658U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 5944U)) & S_BLOCK1], 41U);

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // grow_key_b loop 3
        //
        // Ingress:
        //      aFuseLaneD (-->), aExpandLaneA (-->), aWaterLaneB (-->), aWaterLaneD (<-?->)
        //
        // Cross:
        //      aFuseLaneC (<--), aExpandLaneC (<--), aInvestLaneH (<-?->)
        //
        // Destination:
        //      aWorkLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneD[((aIndex + 14906U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 11476U)) & S_BLOCK1], 20U));
            aIngress ^= (RotL64(aWaterLaneB[((aIndex + 12771U)) & S_BLOCK1], 3U) ^ RotL64(aWaterLaneD[((aIndex + 13234U)) & S_BLOCK1], 37U));

            //
            aCross = (RotL64(aFuseLaneC[((S_BLOCK1 - aIndex + 14840U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14806U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aInvestLaneH[((aIndex + 11983U)) & S_BLOCK1], 10U);

            aWorkLaneA[aIndex] = aIngress;
        }

        //
        // grow_key_b loop 4
        //
        // Ingress:
        //      aWorkLaneA (-->), aExpandLaneD (-->), aWindLaneC (-->), aWindLaneB (<-?->)
        //
        // Cross:
        //      aFuseLaneD (<--), aExpandLaneA (<--), aInvestLaneD (<-?->)
        //
        // Destination:
        //      aWorkLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 18858U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 18361U)) & S_BLOCK1], 48U));
            aIngress ^= (RotL64(aWindLaneC[((aIndex + 19488U)) & S_BLOCK1], 3U) ^ RotL64(aWindLaneB[((aIndex + 18168U)) & S_BLOCK1], 19U));

            //
            aCross = (RotL64(aFuseLaneD[((S_BLOCK1 - aIndex + 17494U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19851U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 21593U)) & S_BLOCK1], 47U);

            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }

        //
        // grow_key_b loop 5
        //
        // Ingress:
        //      aWorkLaneB (-->), aFuseLaneD (-->), aWindLaneD (-->), aWindLaneA (<-?->)
        //
        // Cross:
        //      aWorkLaneA (<--), aFuseLaneC (<--), aSnowLaneA (<-?->)
        //
        // Destination:
        //      aWorkLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23850U)) & S_BLOCK1], 19U) ^ RotL64(aFuseLaneD[((aIndex + 26353U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aWindLaneD[((aIndex + 22020U)) & S_BLOCK1], 6U) ^ RotL64(aWindLaneA[((aIndex + 25604U)) & S_BLOCK1], 53U));

            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22758U)) & S_BLOCK1], 28U) ^ RotL64(aFuseLaneC[((S_BLOCK1 - aIndex + 24111U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 26899U)) & S_BLOCK1], 11U);

            aWorkLaneC[aIndex] = aIngress;
        }

        //
        // grow_key_b loop 6
        //
        // Ingress:
        //      aWorkLaneC (-->), aWorkLaneA (-->), aFireLaneA (-->), aFireLaneC (<-?->)
        //
        // Cross:
        //      aWorkLaneB (<--), aExpandLaneB (<--), aOperationLaneB (<-?->)
        //
        // Destination:
        //      aWorkLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28095U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 32183U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 31469U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 29299U)) & S_BLOCK1], 54U));

            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28168U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31249U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 29306U)) & S_BLOCK1], 52U);

            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GROW_B grow_key_b (end)

}
