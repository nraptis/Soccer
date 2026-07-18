#include "TwistExpander_Achernar_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Achernar_Arx::KDF_A_A() {
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
            aIngress = RotL64(aSource[((aIndex + 573U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((aIndex + 3072U)) & S_BLOCK1], 20U);

            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 831U)) & S_BLOCK1], 35U) ^ RotL64(aSource[((S_BLOCK1 - aIndex + 5358U)) & S_BLOCK1], 5U);

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
            aIngress = RotL64(aScrapLaneA[((aIndex + 8226U)) & S_BLOCK1], 54U) ^ RotL64(aSource[((aIndex + 8017U)) & S_BLOCK1], 21U);

            //
            aCross = RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 5679U)) & S_BLOCK1], 60U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 9996U)) & S_BLOCK1], 51U);

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
            aIngress = RotL64(aScrapLaneB[((aIndex + 10938U)) & S_BLOCK1], 5U) ^ RotL64(aSource[((aIndex + 11186U)) & S_BLOCK1], 40U);

            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 16161U)) & S_BLOCK1], 47U) ^ RotL64(aScrapLaneA[((aIndex + 12162U)) & S_BLOCK1], 29U);

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
            aIngress = RotL64(aEarthLaneA[((aIndex + 19327U)) & S_BLOCK1], 3U) ^ RotL64(aScrapLaneB[((aIndex + 18261U)) & S_BLOCK1], 21U);

            //
            aCross = RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 20434U)) & S_BLOCK1], 29U) ^ RotL64(aSource[((aIndex + 19218U)) & S_BLOCK1], 19U);

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
            aIngress = RotL64(aEarthLaneB[((aIndex + 26677U)) & S_BLOCK1], 26U) ^ RotL64(aScrapLaneB[((aIndex + 24632U)) & S_BLOCK1], 13U);

            //
            aCross = RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 23847U)) & S_BLOCK1], 12U) ^ RotL64(pSnow[((aIndex + 23357U)) & S_BLOCK1], 57U);

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
            aIngress = RotL64(aEarthLaneC[((aIndex + 31067U)) & S_BLOCK1], 21U) ^ RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 31961U)) & S_BLOCK1], 10U);

            //
            aCross = RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 29309U)) & S_BLOCK1], 21U) ^ RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 29063U)) & S_BLOCK1], 37U);

            aEarthLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_A kdf_a_loop_a (end)
    
}

void TwistExpander_Achernar_Arx::KDF_A_B() {
    // [kdf-a arx]
    // GSeedRunKDF_A_B kdf_a_loop_b (start)
    {
        //
        // kdf_a_loop_b loop 1
        //
        // Ingress:
        //      aEarthLaneA (-->), aEarthLaneB (-->), aScrapLaneA (<-?->)
        //
        // Cross:
        //      aEarthLaneC (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aFireLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneA[((aIndex + 5977U)) & S_BLOCK1], 39U) ^ RotL64(aEarthLaneB[((aIndex + 2352U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aScrapLaneA[((aIndex + 5507U)) & S_BLOCK1], 54U);

            //
            aCross = RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 3219U)) & S_BLOCK1], 12U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 5886U)) & S_BLOCK1], 23U);

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
            aIngress = (RotL64(aFireLaneA[((aIndex + 9022U)) & S_BLOCK1], 58U) ^ RotL64(aEarthLaneC[((aIndex + 10422U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(pSnow[((S_BLOCK1 - aIndex + 10177U)) & S_BLOCK1], 35U);

            //
            aCross = RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 10689U)) & S_BLOCK1], 10U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 9856U)) & S_BLOCK1], 19U);

            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_b loop 3
        //
        // Ingress:
        //      aFireLaneB (-->), aEarthLaneD (-->), aSource (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aEarthLaneB (<--)
        //
        // Destination:
        //      aFireLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFireLaneB[((aIndex + 20159U)) & S_BLOCK1], 38U) ^ RotL64(aEarthLaneD[((aIndex + 19905U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aSource[((aIndex + 22849U)) & S_BLOCK1], 3U);

            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23191U)) & S_BLOCK1], 29U) ^ RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 18009U)) & S_BLOCK1], 19U);

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
            aIngress = (RotL64(aFireLaneC[((aIndex + 25804U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneA[((aIndex + 25159U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 28160U)) & S_BLOCK1], 57U);

            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 25963U)) & S_BLOCK1], 13U) ^ RotL64(aEarthLaneC[((aIndex + 26764U)) & S_BLOCK1], 30U);

            aFireLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_B kdf_a_loop_b (end)
    
}

void TwistExpander_Achernar_Arx::KDF_A_C() {
    // [kdf-a arx]
    // GSeedRunKDF_A_C kdf_a_loop_c (start)
    {
        //
        // kdf_a_loop_c loop 1
        //
        // Ingress:
        //      aFireLaneA (-->), aFireLaneB (-->), aEarthLaneC (<-?->)
        //
        // Cross:
        //      aFireLaneC (<--), aFireLaneD (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFireLaneA[((aIndex + 4433U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((aIndex + 8061U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aEarthLaneC[((aIndex + 7910U)) & S_BLOCK1], 37U);

            //
            aCross = (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 2579U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 3555U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 7939U)) & S_BLOCK1], 11U);

            aOperationLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_c loop 2
        //
        // Ingress:
        //      aOperationLaneA (-->), aFireLaneC (-->), aEarthLaneB (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), aScrapLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8281U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneC[((aIndex + 13868U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 12070U)) & S_BLOCK1], 43U);

            //
            aCross = (RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11300U)) & S_BLOCK1], 46U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12121U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aScrapLaneA[((aIndex + 13846U)) & S_BLOCK1], 57U);

            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_c loop 3
        //
        // Ingress:
        //      aOperationLaneB (-->), aFireLaneD (-->), aSource (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aFireLaneB (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aOperationLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 18737U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneD[((aIndex + 18102U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aSource[((aIndex + 22255U)) & S_BLOCK1], 29U);

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22153U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16490U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aEarthLaneD[((aIndex + 20296U)) & S_BLOCK1], 57U);

            aOperationLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_c loop 4
        //
        // Ingress:
        //      aOperationLaneC (-->), aOperationLaneA (-->), pSnow (<-?->)
        //
        // Cross:
        //      aOperationLaneB (<--), aFireLaneC (<--), aScrapLaneB (<-?->)
        //
        // Destination:
        //      aOperationLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31969U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 27007U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(pSnow[((aIndex + 30411U)) & S_BLOCK1], 10U);

            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31055U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 32060U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 32734U)) & S_BLOCK1], 3U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_C kdf_a_loop_c (end)
    
}

void TwistExpander_Achernar_Arx::KDF_A_D() {
    // [kdf-a arx]
    // GSeedRunKDF_A_D kdf_a_loop_d (start)
    {
        //
        // kdf_a_loop_d loop 1
        //
        // Ingress:
        //      aOperationLaneA (-->), aOperationLaneB (-->), aFireLaneA (-->), aScrapLaneB (<-?->)
        //
        // Cross:
        //      aOperationLaneC (<--), aOperationLaneD (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2144U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 2394U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 2574U)) & S_BLOCK1], 41U) ^ RotL64(aScrapLaneB[((aIndex + 2411U)) & S_BLOCK1], 14U));

            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 680U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5781U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 4845U)) & S_BLOCK1], 11U);

            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_d loop 2
        //
        // Ingress:
        //      aFuseLaneA (-->), aOperationLaneC (-->), aScrapLaneA (-->), aFireLaneC (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aOperationLaneD (<--), aSource (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneA[((aIndex + 9431U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 10183U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aScrapLaneA[((aIndex + 15458U)) & S_BLOCK1], 44U) ^ RotL64(aFireLaneC[((aIndex + 10212U)) & S_BLOCK1], 21U));

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11604U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13251U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aSource[((S_BLOCK1 - aIndex + 12374U)) & S_BLOCK1], 37U);

            aFuseLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_d loop 3
        //
        // Ingress:
        //      aFuseLaneB (-->), aOperationLaneD (-->), aFireLaneB (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aOperationLaneB (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneB[((aIndex + 20859U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((aIndex + 20931U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aFireLaneB[((aIndex + 16559U)) & S_BLOCK1], 3U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 17711U)) & S_BLOCK1], 44U));

            //
            aCross = (RotL64(aFuseLaneA[((S_BLOCK1 - aIndex + 24529U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20817U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 22062U)) & S_BLOCK1], 5U);

            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_d loop 4
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aFireLaneD (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aOperationLaneC (<--), pSnow (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 28996U)) & S_BLOCK1], 19U) ^ RotL64(aFuseLaneA[((aIndex + 28016U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25614U)) & S_BLOCK1], 37U) ^ RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 29605U)) & S_BLOCK1], 3U));

            //
            aCross = (RotL64(aFuseLaneB[((S_BLOCK1 - aIndex + 27895U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 31589U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(pSnow[((aIndex + 26075U)) & S_BLOCK1], 13U);

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_D kdf_a_loop_d (end)
    
}

void TwistExpander_Achernar_Arx::KDF_A_E() {
    // [kdf-a arx]
    // GSeedRunKDF_A_E kdf_a_loop_e (start)
    {
        //
        // kdf_a_loop_e loop 1
        //
        // Ingress:
        //      aWindLaneA (-->), aWindLaneB (-->), aEarthLaneC (-->), aFireLaneA (<-?->)
        //
        // Cross:
        //      aWindLaneC (<--), aWindLaneD (<--), aEarthLaneB (<--), aOperationLaneD (<-?->)
        //
        // Destination:
        //      aWaterLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWindLaneA[((aIndex + 2171U)) & S_BLOCK1], 21U) ^ RotL64(aWindLaneB[((aIndex + 4793U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aEarthLaneC[((aIndex + 5198U)) & S_BLOCK1], 10U) ^ RotL64(aFireLaneA[((aIndex + 3501U)) & S_BLOCK1], 29U));

            //
            aCross = (RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 787U)) & S_BLOCK1], 19U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 5585U)) & S_BLOCK1], 53U));
            aCross ^= (RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 1606U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4146U)) & S_BLOCK1], 4U));

            aWaterLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_e loop 2
        //
        // Ingress:
        //      aWaterLaneA (-->), aWindLaneC (-->), aSource (-->), aOperationLaneA (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aWindLaneD (<--), aFireLaneB (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aWaterLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneA[((aIndex + 10110U)) & S_BLOCK1], 38U) ^ RotL64(aWindLaneC[((aIndex + 15100U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aSource[((aIndex + 10925U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 16323U)) & S_BLOCK1], 57U));

            //
            aCross = (RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 11629U)) & S_BLOCK1], 21U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 15128U)) & S_BLOCK1], 12U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 13285U)) & S_BLOCK1], 3U) ^ RotL64(aEarthLaneD[((aIndex + 11668U)) & S_BLOCK1], 29U));

            aWaterLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_e loop 3
        //
        // Ingress:
        //      aWaterLaneB (-->), aWindLaneD (-->), aFireLaneD (-->), aFireLaneC (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWindLaneB (<--), pSnow (<-?->)
        //
        // Destination:
        //      aWaterLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneB[((aIndex + 19520U)) & S_BLOCK1], 43U) ^ RotL64(aWindLaneD[((aIndex + 24556U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 22873U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 20990U)) & S_BLOCK1], 13U));

            //
            aCross = (RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 18075U)) & S_BLOCK1], 11U) ^ RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 17110U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(pSnow[((S_BLOCK1 - aIndex + 23867U)) & S_BLOCK1], 29U);

            aWaterLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_a_loop_e loop 4
        //
        // Ingress:
        //      aWaterLaneC (-->), aWaterLaneA (-->), aOperationLaneC (-->), aOperationLaneB (<-?->)
        //
        // Cross:
        //      aWaterLaneB (<--), aWindLaneC (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aWaterLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneC[((aIndex + 25906U)) & S_BLOCK1], 47U) ^ RotL64(aWaterLaneA[((aIndex + 30064U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aOperationLaneC[((aIndex + 26251U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26467U)) & S_BLOCK1], 13U));

            //
            aCross = (RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 26119U)) & S_BLOCK1], 22U) ^ RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 29622U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 31731U)) & S_BLOCK1], 3U);

            aWaterLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_A_E kdf_a_loop_e (end)
    
}

void TwistExpander_Achernar_Arx::KDF_B_A() {
    // [kdf-a arx]
    // GSeedRunKDF_B_A kdf_b_loop_a (start)
    {
        //
        // kdf_b_loop_a loop 1
        //
        // Ingress:
        //      aWaterLaneA (-->), aWaterLaneB (-->), aFireLaneC (-->), aWindLaneA (<-?->)
        //
        // Cross:
        //      aWaterLaneC (<--), aWaterLaneD (<--), aOperationLaneC (<-?->)
        //
        // Destination:
        //      aScrapLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneA[((aIndex + 7849U)) & S_BLOCK1], 27U) ^ RotL64(aWaterLaneB[((aIndex + 5723U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aFireLaneC[((aIndex + 5406U)) & S_BLOCK1], 5U) ^ RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 1423U)) & S_BLOCK1], 47U));

            //
            aCross = (RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 6630U)) & S_BLOCK1], 28U) ^ RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 2767U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4085U)) & S_BLOCK1], 3U);

            aScrapLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_a loop 2
        //
        // Ingress:
        //      aScrapLaneA (-->), aWaterLaneC (-->), aSource (-->), aFireLaneB (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWaterLaneD (<--), aOperationLaneD (<-?->)
        //
        // Destination:
        //      aScrapLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneA[((aIndex + 9969U)) & S_BLOCK1], 26U) ^ RotL64(aWaterLaneC[((aIndex + 15665U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aSource[((aIndex + 15893U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 10081U)) & S_BLOCK1], 35U));

            //
            aCross = (RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 9409U)) & S_BLOCK1], 52U) ^ RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 8742U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 16261U)) & S_BLOCK1], 19U);

            aScrapLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_a loop 3
        //
        // Ingress:
        //      aScrapLaneB (-->), aWaterLaneD (-->), aOperationLaneA (-->), aFireLaneD (<-?->)
        //
        // Cross:
        //      aScrapLaneA (<--), aWaterLaneB (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aScrapLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneB[((aIndex + 23379U)) & S_BLOCK1], 5U) ^ RotL64(aWaterLaneD[((aIndex + 21862U)) & S_BLOCK1], 36U));
            aIngress ^= (RotL64(aOperationLaneA[((aIndex + 17254U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneD[((aIndex + 23184U)) & S_BLOCK1], 13U));

            //
            aCross = (RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 17441U)) & S_BLOCK1], 47U) ^ RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 18533U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aWindLaneC[((aIndex + 20331U)) & S_BLOCK1], 29U);

            aScrapLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_a loop 4
        //
        // Ingress:
        //      aScrapLaneC (-->), aScrapLaneA (-->), aWindLaneD (-->), aOperationLaneB (<-?->)
        //
        // Cross:
        //      aScrapLaneB (<--), aWaterLaneC (<--), aWindLaneB (<-?->)
        //
        // Destination:
        //      aScrapLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneC[((aIndex + 29783U)) & S_BLOCK1], 53U) ^ RotL64(aScrapLaneA[((aIndex + 28431U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aWindLaneD[((aIndex + 25693U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31412U)) & S_BLOCK1], 14U));

            //
            aCross = (RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 30011U)) & S_BLOCK1], 23U) ^ RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 25670U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 28943U)) & S_BLOCK1], 5U);

            aScrapLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_A kdf_b_loop_a (end)
    
}

void TwistExpander_Achernar_Arx::KDF_B_B() {
    // [kdf-a arx]
    // GSeedRunKDF_B_B kdf_b_loop_b (start)
    {
        //
        // kdf_b_loop_b loop 1
        //
        // Ingress:
        //      aScrapLaneA (-->), aScrapLaneB (-->), aWaterLaneD (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aScrapLaneC (<--), aScrapLaneD (<--), aWaterLaneB (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aOperationLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneA[((aIndex + 2701U)) & S_BLOCK1], 19U) ^ RotL64(aScrapLaneB[((aIndex + 1073U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aWaterLaneD[((aIndex + 5768U)) & S_BLOCK1], 56U) ^ RotL64(aEarthLaneD[((aIndex + 7207U)) & S_BLOCK1], 27U));

            //
            aCross = (RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 2418U)) & S_BLOCK1], 35U) ^ RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 3056U)) & S_BLOCK1], 11U));
            aCross ^= (RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 5335U)) & S_BLOCK1], 19U) ^ RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 4159U)) & S_BLOCK1], 44U));

            aOperationLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_b loop 2
        //
        // Ingress:
        //      aOperationLaneA (-->), aScrapLaneC (-->), aWindLaneD (-->), aWaterLaneA (<-?->)
        //
        // Cross:
        //      aScrapLaneA (<--), aScrapLaneD (<--), aWindLaneB (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aOperationLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16226U)) & S_BLOCK1], 21U) ^ RotL64(aScrapLaneC[((aIndex + 10454U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aWindLaneD[((aIndex + 9233U)) & S_BLOCK1], 35U) ^ RotL64(aWaterLaneA[((aIndex + 14979U)) & S_BLOCK1], 5U));

            //
            aCross = (RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 12211U)) & S_BLOCK1], 5U) ^ RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 9929U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 15278U)) & S_BLOCK1], 35U) ^ RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 8557U)) & S_BLOCK1], 53U));

            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_b loop 3
        //
        // Ingress:
        //      aOperationLaneB (-->), aScrapLaneD (-->), aWindLaneA (-->), aFireLaneA (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aScrapLaneB (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 18199U)) & S_BLOCK1], 11U) ^ RotL64(aScrapLaneD[((aIndex + 19956U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aWindLaneA[((aIndex + 16387U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 19727U)) & S_BLOCK1], 43U));

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20415U)) & S_BLOCK1], 19U) ^ RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 22218U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 17715U)) & S_BLOCK1], 38U);

            aOperationLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_b loop 4
        //
        // Ingress:
        //      aOperationLaneC (-->), aOperationLaneA (-->), aSource (-->), aWaterLaneC (<-?->)
        //
        // Cross:
        //      aOperationLaneB (<--), aScrapLaneC (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aOperationLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 25173U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((aIndex + 25473U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aSource[((aIndex + 26876U)) & S_BLOCK1], 43U) ^ RotL64(aWaterLaneC[((aIndex + 31533U)) & S_BLOCK1], 51U));

            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26917U)) & S_BLOCK1], 13U) ^ RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 32491U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 27270U)) & S_BLOCK1], 43U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_B kdf_b_loop_b (end)
    
}

void TwistExpander_Achernar_Arx::KDF_B_C() {
    // [kdf-a arx]
    // GSeedRunKDF_B_C kdf_b_loop_c (start)
    {
        //
        // kdf_b_loop_c loop 1
        //
        // Ingress:
        //      aOperationLaneA (-->), aOperationLaneB (-->), aFireLaneD (-->), aFireLaneC (<-?->)
        //
        // Cross:
        //      aOperationLaneC (<--), aOperationLaneD (<--), aFireLaneA (<--), aScrapLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 984U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 2250U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 4858U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneC[((aIndex + 78U)) & S_BLOCK1], 12U));

            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6599U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5502U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7267U)) & S_BLOCK1], 23U) ^ RotL64(aScrapLaneD[((aIndex + 2898U)) & S_BLOCK1], 5U));

            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_c loop 2
        //
        // Ingress:
        //      aFuseLaneA (-->), aOperationLaneC (-->), aWaterLaneD (-->), aScrapLaneA (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aOperationLaneD (<--), aFireLaneB (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneA[((aIndex + 13293U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 12138U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aWaterLaneD[((aIndex + 16342U)) & S_BLOCK1], 11U) ^ RotL64(aScrapLaneA[((aIndex + 12861U)) & S_BLOCK1], 46U));

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10164U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14475U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 9076U)) & S_BLOCK1], 5U) ^ RotL64(aWindLaneA[((aIndex + 14355U)) & S_BLOCK1], 58U));

            aFuseLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_c loop 3
        //
        // Ingress:
        //      aFuseLaneB (-->), aOperationLaneD (-->), aWindLaneB (-->), aWaterLaneB (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aOperationLaneB (<--), aScrapLaneC (<--), aScrapLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneB[((aIndex + 22094U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((aIndex + 23057U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aWindLaneB[((aIndex + 24552U)) & S_BLOCK1], 5U) ^ RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 16472U)) & S_BLOCK1], 43U));

            //
            aCross = (RotL64(aFuseLaneA[((S_BLOCK1 - aIndex + 18448U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18975U)) & S_BLOCK1], 12U));
            aCross ^= (RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 20581U)) & S_BLOCK1], 37U) ^ RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 17182U)) & S_BLOCK1], 3U));

            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_c loop 4
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aWaterLaneA (-->), aWindLaneD (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aOperationLaneC (<--), aWindLaneC (<--), aWaterLaneC (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 30501U)) & S_BLOCK1], 47U) ^ RotL64(aFuseLaneA[((aIndex + 24597U)) & S_BLOCK1], 28U));
            aIngress ^= (RotL64(aWaterLaneA[((aIndex + 31475U)) & S_BLOCK1], 11U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 27869U)) & S_BLOCK1], 19U));

            //
            aCross = (RotL64(aFuseLaneB[((S_BLOCK1 - aIndex + 30275U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 32029U)) & S_BLOCK1], 11U));
            aCross ^= (RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 26664U)) & S_BLOCK1], 19U) ^ RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 25980U)) & S_BLOCK1], 60U));

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_C kdf_b_loop_c (end)
    
}

void TwistExpander_Achernar_Arx::KDF_B_D() {
    // [kdf-a arx]
    // GSeedRunKDF_B_D kdf_b_loop_d (start)
    {
        //
        // kdf_b_loop_d loop 1
        //
        // Ingress:
        //      aWorkLaneA (-->), aWorkLaneB (-->), aOperationLaneD (-->), aWindLaneB (<-?->)
        //
        // Cross:
        //      aWorkLaneC (<--), aWorkLaneD (<--), aWindLaneC (<--), aOperationLaneA (<-?->)
        //
        // Destination:
        //      aExpandLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 3946U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 5188U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 4964U)) & S_BLOCK1], 3U) ^ RotL64(aWindLaneB[((aIndex + 5093U)) & S_BLOCK1], 11U));

            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4216U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2870U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 4055U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 1170U)) & S_BLOCK1], 27U));

            aExpandLaneA[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_d loop 2
        //
        // Ingress:
        //      aExpandLaneA (-->), aWorkLaneC (-->), aWaterLaneB (-->), aOperationLaneC (<-?->)
        //
        // Cross:
        //      aWorkLaneA (<--), aWorkLaneD (<--), aScrapLaneC (<--), aWaterLaneC (<-?->)
        //
        // Destination:
        //      aExpandLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15007U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((aIndex + 13016U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aWaterLaneB[((aIndex + 12999U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneC[((aIndex + 14009U)) & S_BLOCK1], 5U));

            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14722U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13552U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 14814U)) & S_BLOCK1], 57U) ^ RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 16019U)) & S_BLOCK1], 47U));

            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_d loop 3
        //
        // Ingress:
        //      aExpandLaneB (-->), aWorkLaneD (-->), aWaterLaneD (-->), aSource (<-?->)
        //
        // Cross:
        //      aExpandLaneA (<--), aWorkLaneB (<--), aScrapLaneD (<--), aScrapLaneA (<-?->)
        //
        // Destination:
        //      aExpandLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22241U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 17514U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aWaterLaneD[((aIndex + 19337U)) & S_BLOCK1], 47U) ^ RotL64(aSource[((S_BLOCK1 - aIndex + 22814U)) & S_BLOCK1], 21U));

            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18694U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24286U)) & S_BLOCK1], 34U));
            aCross ^= (RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 19780U)) & S_BLOCK1], 43U) ^ RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 18959U)) & S_BLOCK1], 5U));

            aExpandLaneC[aIndex] = aIngress;
        }
    
        //
        // kdf_b_loop_d loop 4
        //
        // Ingress:
        //      aExpandLaneC (-->), aExpandLaneA (-->), aScrapLaneB (-->), aWindLaneD (<-?->)
        //
        // Cross:
        //      aExpandLaneB (<--), aWorkLaneC (<--), aOperationLaneB (<--), aWaterLaneA (<-?->)
        //
        // Destination:
        //      aExpandLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30518U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 32255U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aScrapLaneB[((aIndex + 27996U)) & S_BLOCK1], 60U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 29795U)) & S_BLOCK1], 51U));

            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32054U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 24817U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31521U)) & S_BLOCK1], 11U) ^ RotL64(aWaterLaneA[((aIndex + 30432U)) & S_BLOCK1], 50U));

            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunKDF_B_D kdf_b_loop_d (end)
    
}

void TwistExpander_Achernar_Arx::Seed_A() {
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
            aIngress = RotL64(aSource[((aIndex + 1379U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 1997U)) & W_KEY1], 19U);

            //
            aCross = RotL64(aSource[((S_BLOCK1 - aIndex + 3437U)) & S_BLOCK1], 34U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 1167U)) & W_KEY1], 21U);

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
            aIngress = RotL64(aWorkLaneA[((aIndex + 5899U)) & S_BLOCK1], 14U) ^ RotL64(aKeyRowReadB[((aIndex + 6296U)) & W_KEY1], 5U);

            //
            aCross = RotL64(aSource[((S_BLOCK1 - aIndex + 6610U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 6098U)) & W_KEY1], 35U);

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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 12938U)) & S_BLOCK1], 5U) ^ RotL64(aSource[((aIndex + 15309U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aKeyRowReadB[((aIndex + 11040U)) & W_KEY1], 54U);

            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 12326U)) & W_KEY1], 42U) ^ RotL64(aWorkLaneA[((aIndex + 14771U)) & S_BLOCK1], 3U);

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
            aIngress = RotL64(aExpandLaneA[((aIndex + 19743U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16912U)) & S_BLOCK1], 40U);

            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21759U)) & S_BLOCK1], 48U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21619U)) & W_KEY1], 19U);

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
            aIngress = RotL64(aExpandLaneB[((aIndex + 25789U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((aIndex + 23933U)) & S_BLOCK1], 21U);

            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23997U)) & S_BLOCK1], 6U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 23612U)) & W_KEY1], 41U);

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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30749U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27437U)) & S_BLOCK1], 38U);

            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28479U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((aIndex + 27318U)) & S_BLOCK1], 5U);

            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_A seed_loop_a (end)
    
}

void TwistExpander_Achernar_Arx::Seed_B() {
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
        //      aExpandLaneA (-->), aExpandLaneB (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aExpandLaneC (<--), aExpandLaneD (<-?->)
        //
        // Destination:
        //      aWorkLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3746U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 3512U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aKeyRowReadA[((aIndex + 3562U)) & W_KEY1], 11U);

            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 717U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4390U)) & S_BLOCK1], 24U);

            aWorkLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 2
        //
        // Ingress:
        //      aWorkLaneC (-->), aExpandLaneC (-->), aKeyRowReadB (<-?->)
        //
        // Cross:
        //      aExpandLaneA (<--), aExpandLaneD (<--)
        //
        // Destination:
        //      aWorkLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 6391U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 9078U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aKeyRowReadB[((aIndex + 6888U)) & W_KEY1], 37U);

            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6506U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8117U)) & S_BLOCK1], 20U);

            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 3
        //
        // Ingress:
        //      aWorkLaneD (-->), aExpandLaneA (-->), aWorkLaneA (<-?->)
        //
        // Cross:
        //      aWorkLaneC (<--), aExpandLaneC (<-?->)
        //
        // Destination:
        //      aEarthLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneD[((aIndex + 15296U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 15541U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15370U)) & S_BLOCK1], 37U);

            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15851U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 15301U)) & S_BLOCK1], 13U);

            aEarthLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 4
        //
        // Ingress:
        //      aEarthLaneA (-->), aExpandLaneD (-->), aSource (<-?->)
        //
        // Cross:
        //      aWorkLaneD (<--), aExpandLaneA (<-?->)
        //
        // Destination:
        //      aEarthLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneA[((aIndex + 17294U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 20752U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aSource[((aIndex + 19906U)) & S_BLOCK1], 13U);

            //
            aCross = RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17118U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((aIndex + 20250U)) & S_BLOCK1], 27U);

            aEarthLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 5
        //
        // Ingress:
        //      aEarthLaneB (-->), aWorkLaneD (-->), aWorkLaneB (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aWorkLaneC (<-?->)
        //
        // Destination:
        //      aEarthLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneB[((aIndex + 25200U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 23883U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22300U)) & S_BLOCK1], 43U);

            //
            aCross = RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 25887U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26033U)) & S_BLOCK1], 56U);

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
            aIngress = RotL64(aEarthLaneC[((aIndex + 32228U)) & S_BLOCK1], 43U) ^ RotL64(aEarthLaneA[((aIndex + 30791U)) & S_BLOCK1], 14U);

            //
            aCross = RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 28761U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29086U)) & S_BLOCK1], 14U);

            aEarthLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_B seed_loop_e (end)
    
}

void TwistExpander_Achernar_Arx::Seed_C() {
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
        //      aEarthLaneA (-->), aEarthLaneB (-->), aWorkLaneB (<-?->)
        //
        // Cross:
        //      aEarthLaneC (<--), aEarthLaneD (<--), aWorkLaneC (<-?->)
        //
        // Destination:
        //      aScrapLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneA[((aIndex + 2165U)) & S_BLOCK1], 5U) ^ RotL64(aEarthLaneB[((aIndex + 1419U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 2957U)) & S_BLOCK1], 27U);

            //
            aCross = (RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 4798U)) & S_BLOCK1], 51U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 4477U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2779U)) & S_BLOCK1], 24U);

            aScrapLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 2
        //
        // Ingress:
        //      aScrapLaneA (-->), aEarthLaneC (-->), aSource (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aEarthLaneD (<--), aExpandLaneC (<-?->)
        //
        // Destination:
        //      aScrapLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneA[((aIndex + 6239U)) & S_BLOCK1], 44U) ^ RotL64(aEarthLaneC[((aIndex + 9326U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aSource[((S_BLOCK1 - aIndex + 8858U)) & S_BLOCK1], 35U);

            //
            aCross = (RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 5961U)) & S_BLOCK1], 35U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 9063U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5782U)) & S_BLOCK1], 43U);

            aScrapLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 3
        //
        // Ingress:
        //      aScrapLaneB (-->), aEarthLaneA (-->), aExpandLaneA (<-?->)
        //
        // Cross:
        //      aScrapLaneA (<--), aEarthLaneC (<--), aWorkLaneD (<-?->)
        //
        // Destination:
        //      aOperationLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneB[((aIndex + 14133U)) & S_BLOCK1], 48U) ^ RotL64(aEarthLaneA[((aIndex + 11139U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 14547U)) & S_BLOCK1], 23U);

            //
            aCross = (RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 13732U)) & S_BLOCK1], 19U) ^ RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 14380U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 12283U)) & S_BLOCK1], 3U);

            aOperationLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 4
        //
        // Ingress:
        //      aOperationLaneA (-->), aEarthLaneD (-->), aExpandLaneB (<-?->)
        //
        // Cross:
        //      aScrapLaneB (<--), aEarthLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16412U)) & S_BLOCK1], 44U) ^ RotL64(aEarthLaneD[((aIndex + 18991U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21475U)) & S_BLOCK1], 3U);

            //
            aCross = RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 20890U)) & S_BLOCK1], 21U) ^ RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 19896U)) & S_BLOCK1], 11U);

            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 5
        //
        // Ingress:
        //      aOperationLaneB (-->), aScrapLaneB (-->), aWorkLaneA (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aScrapLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26860U)) & S_BLOCK1], 23U) ^ RotL64(aScrapLaneB[((aIndex + 24832U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22070U)) & S_BLOCK1], 43U);

            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22482U)) & S_BLOCK1], 51U) ^ RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 25924U)) & S_BLOCK1], 35U);

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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27681U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((aIndex + 31260U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 32506U)) & S_BLOCK1], 39U);

            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28797U)) & S_BLOCK1], 50U) ^ RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 29585U)) & S_BLOCK1], 23U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_C seed_loop_d (end)
    
}

void TwistExpander_Achernar_Arx::Seed_D() {
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
        //      aOperationLaneA (-->), aOperationLaneB (-->), aExpandLaneA (<-?->)
        //
        // Cross:
        //      aOperationLaneC (<--), aOperationLaneD (<--), aExpandLaneD (<-?->)
        //
        // Destination:
        //      aScrapLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4464U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 4070U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 5070U)) & S_BLOCK1], 57U);

            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2298U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4783U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 872U)) & S_BLOCK1], 57U);

            aScrapLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 2
        //
        // Ingress:
        //      aScrapLaneC (-->), aOperationLaneC (-->), aExpandLaneB (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aOperationLaneD (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aScrapLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneC[((aIndex + 9823U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 10523U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 10515U)) & S_BLOCK1], 48U);

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5492U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8661U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 10506U)) & S_BLOCK1], 11U);

            aScrapLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 3
        //
        // Ingress:
        //      aScrapLaneD (-->), aOperationLaneA (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aScrapLaneC (<--), aOperationLaneC (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneD[((aIndex + 13220U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 12845U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 11464U)) & S_BLOCK1], 11U);

            //
            aCross = (RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 14231U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14564U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 12402U)) & S_BLOCK1], 12U);

            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 4
        //
        // Ingress:
        //      aFuseLaneA (-->), aOperationLaneD (-->), aEarthLaneC (<-?->)
        //
        // Cross:
        //      aScrapLaneD (<--), aOperationLaneA (<--), aScrapLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneA[((aIndex + 19991U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((aIndex + 20925U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 17703U)) & S_BLOCK1], 23U);

            //
            aCross = (RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 21266U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17137U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 19865U)) & S_BLOCK1], 21U);

            aFuseLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 5
        //
        // Ingress:
        //      aFuseLaneB (-->), aScrapLaneD (-->), aWorkLaneD (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aScrapLaneC (<--), aKeyRowReadA (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneB[((aIndex + 22249U)) & S_BLOCK1], 6U) ^ RotL64(aScrapLaneD[((aIndex + 24627U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21863U)) & S_BLOCK1], 29U);

            //
            aCross = (RotL64(aFuseLaneA[((S_BLOCK1 - aIndex + 23941U)) & S_BLOCK1], 35U) ^ RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 26214U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aKeyRowReadA[((aIndex + 24125U)) & W_KEY1], 27U);

            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 6
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aExpandLaneC (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aOperationLaneB (<--), aScrapLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 32623U)) & S_BLOCK1], 19U) ^ RotL64(aFuseLaneA[((aIndex + 29956U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 28035U)) & S_BLOCK1], 11U);

            //
            aCross = (RotL64(aFuseLaneB[((S_BLOCK1 - aIndex + 29454U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32268U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aScrapLaneA[((S_BLOCK1 - aIndex + 31785U)) & S_BLOCK1], 29U);

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_D seed_loop_c (end)
    
}

void TwistExpander_Achernar_Arx::Seed_E() {
    const std::uint64_t &aPhaseADomainWordIngress = pWorkSpace->mDomainBundle.mPhaseAConstants.mIngress;
    const std::uint64_t &aPhaseADomainWordScatter = pWorkSpace->mDomainBundle.mPhaseAConstants.mScatter;
    const std::uint64_t &aPhaseADomainWordCross = pWorkSpace->mDomainBundle.mPhaseAConstants.mCross;
    const std::uint64_t &aPhaseCDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseCConstants.mIngress;
    const std::uint64_t &aPhaseCDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseCConstants.mScatter;
    const std::uint64_t &aPhaseCDomainWordCross = pWorkSpace->mDomainBundle.mPhaseCConstants.mCross;
    const std::uint64_t &aPhaseEDomainWordIngress = pWorkSpace->mDomainBundle.mPhaseEConstants.mIngress;
    const std::uint64_t &aPhaseEDomainWordScatter = pWorkSpace->mDomainBundle.mPhaseEConstants.mScatter;
    const std::uint64_t &aPhaseEDomainWordCross = pWorkSpace->mDomainBundle.mPhaseEConstants.mCross;
    // [seed arx]
    // GSeedRunSeed_E seed_loop_b (start)
    {
        //
        // seed_loop_b loop 1
        //
        // Ingress:
        //      aFireLaneA (-->), aFireLaneB (-->), aWorkLaneC (-->), aKeyRowReadB (<-?->)
        //
        // Cross:
        //      aFireLaneC (<--), aFireLaneD (<--), aScrapLaneA (<-?->)
        //
        // Destination:
        //      aWaterLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFireLaneA[((aIndex + 4265U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((aIndex + 3116U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aWorkLaneC[((aIndex + 3796U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadB[((aIndex + 2534U)) & W_KEY1], 46U));

            //
            aCross = (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 4535U)) & S_BLOCK1], 52U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 2301U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aScrapLaneA[((aIndex + 729U)) & S_BLOCK1], 11U);

            aWaterLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_b loop 2
        //
        // Ingress:
        //      aWaterLaneC (-->), aFireLaneC (-->), aEarthLaneB (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aWaterLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneC[((aIndex + 6698U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneC[((aIndex + 7307U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aEarthLaneB[((aIndex + 6844U)) & S_BLOCK1], 19U) ^ RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 9541U)) & S_BLOCK1], 37U));

            //
            aCross = (RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6445U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 9425U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 8720U)) & S_BLOCK1], 43U);

            aWaterLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_b loop 3
        //
        // Ingress:
        //      aWaterLaneD (-->), aFireLaneA (-->), aOperationLaneB (<-?->)
        //
        // Cross:
        //      aWaterLaneC (<--), aFireLaneC (<--), aOperationLaneD (<-?->)
        //
        // Destination:
        //      aInvestLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneD[((aIndex + 13441U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneA[((aIndex + 13392U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 10951U)) & S_BLOCK1], 56U);

            //
            aCross = (RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 15353U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15641U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 14105U)) & S_BLOCK1], 56U);

            aInvestLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_b loop 4
        //
        // Ingress:
        //      aInvestLaneA (-->), aFireLaneD (-->), aOperationLaneC (<-?->)
        //
        // Cross:
        //      aWaterLaneD (<--), aFireLaneA (<--), aScrapLaneC (<-?->)
        //
        // Destination:
        //      aInvestLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 18827U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((aIndex + 16982U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19528U)) & S_BLOCK1], 39U);

            //
            aCross = (RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 21307U)) & S_BLOCK1], 40U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 20260U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 17916U)) & S_BLOCK1], 23U);

            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_b loop 5
        //
        // Ingress:
        //      aInvestLaneB (-->), aWaterLaneD (-->), aOperationLaneA (<-?->)
        //
        // Cross:
        //      aInvestLaneA (<--), aWaterLaneC (<--), aScrapLaneD (<-?->)
        //
        // Destination:
        //      aInvestLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 22447U)) & S_BLOCK1], 47U) ^ RotL64(aWaterLaneD[((aIndex + 22994U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24279U)) & S_BLOCK1], 4U);

            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 27016U)) & S_BLOCK1], 19U) ^ RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 23155U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aScrapLaneD[((aIndex + 22261U)) & S_BLOCK1], 29U);

            aInvestLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_b loop 6
        //
        // Ingress:
        //      aInvestLaneC (-->), aInvestLaneA (-->), aScrapLaneB (<-?->)
        //
        // Cross:
        //      aInvestLaneB (<--), aFireLaneB (<--), aEarthLaneC (<-?->)
        //
        // Destination:
        //      aInvestLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 31886U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneA[((aIndex + 28125U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aScrapLaneB[((aIndex + 29329U)) & S_BLOCK1], 47U);

            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29336U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 30891U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aEarthLaneC[((aIndex + 32231U)) & S_BLOCK1], 51U);

            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_E seed_loop_b (end)
    
}

void TwistExpander_Achernar_Arx::Seed_F() {
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
    // [seed arx]
    // GSeedRunSeed_F seed_loop_c (start)
    {
        //
        // seed_loop_c loop 1
        //
        // Ingress:
        //      aInvestLaneA (-->), aInvestLaneB (-->), aFireLaneB (-->), aWaterLaneD (<-?->)
        //
        // Cross:
        //      aInvestLaneC (<--), aInvestLaneD (<--), aOperationLaneB (<-?->)
        //
        // Destination:
        //      aSnowLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 3695U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneB[((aIndex + 1186U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aFireLaneB[((aIndex + 4809U)) & S_BLOCK1], 11U) ^ RotL64(aWaterLaneD[((aIndex + 1121U)) & S_BLOCK1], 57U));

            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 2019U)) & S_BLOCK1], 38U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 2812U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3319U)) & S_BLOCK1], 19U);

            aSnowLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 2
        //
        // Ingress:
        //      aSnowLaneC (-->), aInvestLaneC (-->), aOperationLaneA (-->), aScrapLaneD (<-?->)
        //
        // Cross:
        //      aInvestLaneA (<--), aInvestLaneD (<--), aScrapLaneA (<-?->)
        //
        // Destination:
        //      aSnowLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 6935U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneC[((aIndex + 7747U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneA[((aIndex + 6604U)) & S_BLOCK1], 11U) ^ RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 8307U)) & S_BLOCK1], 56U));

            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 9836U)) & S_BLOCK1], 56U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 8073U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aScrapLaneA[((aIndex + 6683U)) & S_BLOCK1], 43U);

            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 3
        //
        // Ingress:
        //      aSnowLaneD (-->), aInvestLaneA (-->), aSource (-->), aOperationLaneC (<-?->)
        //
        // Cross:
        //      aSnowLaneC (<--), aInvestLaneC (<--), aFireLaneC (<-?->)
        //
        // Destination:
        //      aWindLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 14819U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneA[((aIndex + 11902U)) & S_BLOCK1], 14U));
            aIngress ^= (RotL64(aSource[((aIndex + 14181U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 14681U)) & S_BLOCK1], 29U));

            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 13887U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12650U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14585U)) & S_BLOCK1], 20U);

            aWindLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 4
        //
        // Ingress:
        //      aWindLaneA (-->), aInvestLaneD (-->), aScrapLaneC (-->), aScrapLaneB (<-?->)
        //
        // Cross:
        //      aSnowLaneD (<--), aInvestLaneA (<--), aFireLaneD (<-?->)
        //
        // Destination:
        //      aWindLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWindLaneA[((aIndex + 19745U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneD[((aIndex + 19271U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aScrapLaneC[((aIndex + 18085U)) & S_BLOCK1], 29U) ^ RotL64(aScrapLaneB[((aIndex + 19063U)) & S_BLOCK1], 47U));

            //
            aCross = (RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 16736U)) & S_BLOCK1], 38U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 20192U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 21425U)) & S_BLOCK1], 27U);

            aWindLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 5
        //
        // Ingress:
        //      aWindLaneB (-->), aSnowLaneD (-->), aOperationLaneD (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aSnowLaneC (<--), aFireLaneA (<-?->)
        //
        // Destination:
        //      aWindLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWindLaneB[((aIndex + 26085U)) & S_BLOCK1], 42U) ^ RotL64(aSnowLaneD[((aIndex + 22420U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 23544U)) & S_BLOCK1], 57U);

            //
            aCross = (RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 23222U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 25676U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 21949U)) & S_BLOCK1], 26U);

            aWindLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_c loop 6
        //
        // Ingress:
        //      aWindLaneC (-->), aWindLaneA (-->), aWaterLaneC (<-?->)
        //
        // Cross:
        //      aWindLaneB (<--), aInvestLaneB (<--), aEarthLaneD (<-?->)
        //
        // Destination:
        //      aWindLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWindLaneC[((aIndex + 30642U)) & S_BLOCK1], 27U) ^ RotL64(aWindLaneA[((aIndex + 29195U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 27536U)) & S_BLOCK1], 39U);

            //
            aCross = (RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 29430U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 27488U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aEarthLaneD[((aIndex + 27844U)) & S_BLOCK1], 35U);

            aWindLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_F seed_loop_c (end)
    
}

void TwistExpander_Achernar_Arx::Seed_G() {
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
        //      aWindLaneA (-->), aWindLaneB (-->), aEarthLaneA (-->), aInvestLaneA (<-?->)
        //
        // Cross:
        //      aWindLaneC (<--), aWindLaneD (<--), aWaterLaneD (<-?->)
        //
        // Destination:
        //      aWaterLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWindLaneA[((aIndex + 2908U)) & S_BLOCK1], 6U) ^ RotL64(aWindLaneB[((aIndex + 4181U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aEarthLaneA[((aIndex + 726U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneA[((aIndex + 29U)) & S_BLOCK1], 23U));

            //
            aCross = (RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 1705U)) & S_BLOCK1], 14U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 1475U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 1896U)) & S_BLOCK1], 27U);

            aWaterLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 2
        //
        // Ingress:
        //      aWaterLaneA (-->), aWindLaneC (-->), aScrapLaneD (-->), aSnowLaneC (<-?->)
        //
        // Cross:
        //      aWindLaneA (<--), aWindLaneD (<--), aInvestLaneD (<-?->)
        //
        // Destination:
        //      aWaterLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneA[((aIndex + 7710U)) & S_BLOCK1], 37U) ^ RotL64(aWindLaneC[((aIndex + 5490U)) & S_BLOCK1], 50U));
            aIngress ^= (RotL64(aScrapLaneD[((aIndex + 7875U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 7623U)) & S_BLOCK1], 19U));

            //
            aCross = (RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 10640U)) & S_BLOCK1], 4U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 9545U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 10828U)) & S_BLOCK1], 43U);

            aWaterLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 3
        //
        // Ingress:
        //      aWaterLaneB (-->), aWindLaneA (-->), aWaterLaneC (-->), aEarthLaneC (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWindLaneC (<--), aScrapLaneC (<-?->)
        //
        // Destination:
        //      aOperationLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneB[((aIndex + 12896U)) & S_BLOCK1], 29U) ^ RotL64(aWindLaneA[((aIndex + 13802U)) & S_BLOCK1], 60U));
            aIngress ^= (RotL64(aWaterLaneC[((aIndex + 15894U)) & S_BLOCK1], 39U) ^ RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 11453U)) & S_BLOCK1], 51U));

            //
            aCross = (RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 14248U)) & S_BLOCK1], 40U) ^ RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 12395U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 14632U)) & S_BLOCK1], 53U);

            aOperationLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 4
        //
        // Ingress:
        //      aOperationLaneA (-->), aWindLaneD (-->), aKeyRowReadA (-->), aFireLaneB (<-?->)
        //
        // Cross:
        //      aWaterLaneB (<--), aWindLaneA (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aOperationLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18134U)) & S_BLOCK1], 41U) ^ RotL64(aWindLaneD[((aIndex + 19400U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aKeyRowReadA[((aIndex + 20395U)) & W_KEY1], 3U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19213U)) & S_BLOCK1], 13U));

            //
            aCross = (RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 19495U)) & S_BLOCK1], 54U) ^ RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 18326U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aEarthLaneB[((aIndex + 21725U)) & S_BLOCK1], 29U);

            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 5
        //
        // Ingress:
        //      aOperationLaneB (-->), aWaterLaneB (-->), aInvestLaneC (-->), aInvestLaneB (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aWaterLaneA (<--), aFireLaneD (<-?->)
        //
        // Destination:
        //      aOperationLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25591U)) & S_BLOCK1], 5U) ^ RotL64(aWaterLaneB[((aIndex + 24529U)) & S_BLOCK1], 50U));
            aIngress ^= (RotL64(aInvestLaneC[((aIndex + 27049U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneB[((aIndex + 23767U)) & S_BLOCK1], 19U));

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25114U)) & S_BLOCK1], 11U) ^ RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 25073U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 26101U)) & S_BLOCK1], 27U);

            aOperationLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_d loop 6
        //
        // Ingress:
        //      aOperationLaneC (-->), aOperationLaneA (-->), aSnowLaneD (-->), aFireLaneC (<-?->)
        //
        // Cross:
        //      aOperationLaneB (<--), aWindLaneB (<--), aFireLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28293U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneA[((aIndex + 29381U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 30680U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 30911U)) & S_BLOCK1], 3U));

            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28020U)) & S_BLOCK1], 35U) ^ RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 30241U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 30674U)) & S_BLOCK1], 13U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_G seed_loop_d (end)
    
}

void TwistExpander_Achernar_Arx::Seed_H() {
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
    // GSeedRunSeed_H seed_loop_e (start)
    {
        //
        // seed_loop_e loop 1
        //
        // Ingress:
        //      aOperationLaneA (-->), aOperationLaneB (-->), aWaterLaneA (-->), aSnowLaneD (<-?->)
        //
        // Cross:
        //      aOperationLaneC (<--), aOperationLaneD (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aSnowLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1808U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 5210U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aWaterLaneA[((aIndex + 408U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneD[((aIndex + 1060U)) & S_BLOCK1], 60U));

            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4170U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4430U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 1947U)) & S_BLOCK1], 11U);

            aSnowLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 2
        //
        // Ingress:
        //      aSnowLaneA (-->), aOperationLaneC (-->), aInvestLaneD (-->), aFireLaneA (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aOperationLaneD (<--), aWaterLaneB (<-?->)
        //
        // Destination:
        //      aSnowLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8459U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneC[((aIndex + 6433U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 8621U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7238U)) & S_BLOCK1], 39U));

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5875U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10163U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 5572U)) & S_BLOCK1], 13U);

            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 3
        //
        // Ingress:
        //      aSnowLaneB (-->), aOperationLaneA (-->), aSnowLaneC (-->), aInvestLaneC (<-?->)
        //
        // Cross:
        //      aSnowLaneA (<--), aOperationLaneC (<--), aExpandLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 13405U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 13813U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aSnowLaneC[((aIndex + 10999U)) & S_BLOCK1], 48U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 14252U)) & S_BLOCK1], 27U));

            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 16111U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15461U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12033U)) & S_BLOCK1], 37U);

            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 4
        //
        // Ingress:
        //      aFuseLaneA (-->), aOperationLaneD (-->), aFireLaneB (-->), aWindLaneD (<-?->)
        //
        // Cross:
        //      aSnowLaneB (<--), aOperationLaneA (<--), aInvestLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneA[((aIndex + 20678U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((aIndex + 18015U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aFireLaneB[((aIndex + 20634U)) & S_BLOCK1], 53U) ^ RotL64(aWindLaneD[((aIndex + 21748U)) & S_BLOCK1], 24U));

            //
            aCross = (RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 16803U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16436U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 16853U)) & S_BLOCK1], 19U);

            aFuseLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 5
        //
        // Ingress:
        //      aFuseLaneB (-->), aSnowLaneB (-->), aInvestLaneA (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aSnowLaneA (<--), aKeyRowReadB (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneB[((aIndex + 23442U)) & S_BLOCK1], 54U) ^ RotL64(aSnowLaneB[((aIndex + 26346U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 22413U)) & S_BLOCK1], 3U);

            //
            aCross = (RotL64(aFuseLaneA[((S_BLOCK1 - aIndex + 22118U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 27195U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aKeyRowReadB[(((2047U - aIndex) + 21849U)) & W_KEY1], 13U);

            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_e loop 6
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aWindLaneB (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aOperationLaneB (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 31830U)) & S_BLOCK1], 11U) ^ RotL64(aFuseLaneA[((aIndex + 32450U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 30488U)) & S_BLOCK1], 3U);

            //
            aCross = (RotL64(aFuseLaneB[((S_BLOCK1 - aIndex + 32697U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31133U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 29251U)) & S_BLOCK1], 27U);

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_H seed_loop_e (end)
    
}

void TwistExpander_Achernar_Arx::Seed_I() {
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
        //      aInvestLaneE (-->), aInvestLaneF (-->), aWindLaneC (-->), aSnowLaneB (<-?->)
        //
        // Cross:
        //      aInvestLaneG (<--), aInvestLaneH (<--), aWaterLaneA (<-?->)
        //
        // Destination:
        //      aSnowLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneE[((aIndex + 3186U)) & S_BLOCK1], 60U) ^ RotL64(aInvestLaneF[((aIndex + 119U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aWindLaneC[((aIndex + 4586U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 2818U)) & S_BLOCK1], 37U));

            //
            aCross = (RotL64(aInvestLaneG[((S_BLOCK1 - aIndex + 1030U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneH[((S_BLOCK1 - aIndex + 3261U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aWaterLaneA[((aIndex + 4512U)) & S_BLOCK1], 39U);

            aSnowLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 2
        //
        // Ingress:
        //      aSnowLaneC (-->), aInvestLaneG (-->), aWindLaneB (-->), aFireLaneD (<-?->)
        //
        // Cross:
        //      aInvestLaneE (<--), aInvestLaneH (<--), aOperationLaneB (<-?->)
        //
        // Destination:
        //      aSnowLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 6872U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneG[((aIndex + 9982U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aWindLaneB[((aIndex + 8166U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneD[((aIndex + 9881U)) & S_BLOCK1], 22U));

            //
            aCross = (RotL64(aInvestLaneE[((S_BLOCK1 - aIndex + 6321U)) & S_BLOCK1], 28U) ^ RotL64(aInvestLaneH[((S_BLOCK1 - aIndex + 10563U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 9214U)) & S_BLOCK1], 37U);

            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 3
        //
        // Ingress:
        //      aSnowLaneD (-->), aInvestLaneE (-->), aOperationLaneC (-->), aWaterLaneB (<-?->)
        //
        // Cross:
        //      aSnowLaneC (<--), aInvestLaneG (<--), aSnowLaneA (<-?->)
        //
        // Destination:
        //      aWorkLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 13503U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneE[((aIndex + 15350U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aOperationLaneC[((aIndex + 12966U)) & S_BLOCK1], 19U) ^ RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 16056U)) & S_BLOCK1], 3U));

            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 11649U)) & S_BLOCK1], 20U) ^ RotL64(aInvestLaneG[((S_BLOCK1 - aIndex + 12340U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aSnowLaneA[((aIndex + 12120U)) & S_BLOCK1], 43U);

            aWorkLaneA[aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 4
        //
        // Ingress:
        //      aWorkLaneA (-->), aInvestLaneH (-->), aOperationLaneD (-->), aWindLaneD (<-?->)
        //
        // Cross:
        //      aSnowLaneD (<--), aInvestLaneE (<--), aExpandLaneA (<-?->)
        //
        // Destination:
        //      aWorkLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 18278U)) & S_BLOCK1], 38U) ^ RotL64(aInvestLaneH[((aIndex + 20542U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 20955U)) & S_BLOCK1], 3U) ^ RotL64(aWindLaneD[((aIndex + 20665U)) & S_BLOCK1], 29U));

            //
            aCross = (RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 17339U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneE[((S_BLOCK1 - aIndex + 20750U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20247U)) & S_BLOCK1], 19U);

            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 5
        //
        // Ingress:
        //      aWorkLaneB (-->), aSnowLaneD (-->), aOperationLaneA (<-?->)
        //
        // Cross:
        //      aWorkLaneA (<--), aSnowLaneC (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aWorkLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22041U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneD[((aIndex + 25672U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 23238U)) & S_BLOCK1], 41U);

            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24451U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 24634U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 24823U)) & S_BLOCK1], 38U);

            aWorkLaneC[aIndex] = aIngress;
        }
    
        //
        // seed_loop_f loop 6
        //
        // Ingress:
        //      aWorkLaneC (-->), aWorkLaneA (-->), aFireLaneC (<-?->)
        //
        // Cross:
        //      aWorkLaneB (<--), aInvestLaneF (<--), aExpandLaneB (<-?->)
        //
        // Destination:
        //      aWorkLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29533U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 30239U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 29337U)) & S_BLOCK1], 23U);

            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31624U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneF[((S_BLOCK1 - aIndex + 28242U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 27952U)) & S_BLOCK1], 39U);

            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GSeedRunSeed_I seed_loop_f (end)
    
}

void TwistExpander_Achernar_Arx::Twist_A() {
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
            aIngress = RotL64(aSource[((aIndex + 3083U)) & S_BLOCK1], 22U) ^ RotL64(aKeyRowReadA[((aIndex + 2152U)) & W_KEY1], 41U);

            //
            aCross = RotL64(aSource[((S_BLOCK1 - aIndex + 179U)) & S_BLOCK1], 6U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 4114U)) & W_KEY1], 43U);

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
            aIngress = RotL64(aScrapLaneA[((aIndex + 7380U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadB[((aIndex + 6672U)) & W_KEY1], 22U);

            //
            aCross = RotL64(aSource[((S_BLOCK1 - aIndex + 6849U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 7712U)) & W_KEY1], 6U);

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
            aIngress = (RotL64(aScrapLaneB[((aIndex + 15710U)) & S_BLOCK1], 58U) ^ RotL64(aSource[((aIndex + 11859U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aKeyRowReadB[((aIndex + 15669U)) & W_KEY1], 19U);

            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 14146U)) & W_KEY1], 11U) ^ RotL64(aScrapLaneA[((aIndex + 13168U)) & S_BLOCK1], 34U);

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
            aIngress = RotL64(aWindLaneA[((aIndex + 16511U)) & S_BLOCK1], 30U) ^ RotL64(aScrapLaneA[((aIndex + 17503U)) & S_BLOCK1], 43U);

            //
            aCross = RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 20014U)) & S_BLOCK1], 20U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 18701U)) & W_KEY1], 51U);

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
            aIngress = RotL64(aWindLaneB[((aIndex + 26459U)) & S_BLOCK1], 3U) ^ RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 26849U)) & S_BLOCK1], 36U);

            //
            aCross = RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 24693U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 24333U)) & W_KEY1], 36U);

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
            aIngress = RotL64(aWindLaneC[((aIndex + 30158U)) & S_BLOCK1], 39U) ^ RotL64(aWindLaneA[((aIndex + 29828U)) & S_BLOCK1], 58U);

            //
            aCross = RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 28920U)) & S_BLOCK1], 48U) ^ RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 27758U)) & S_BLOCK1], 5U);

            aWindLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_A twist_loop_a (end)
    
}

void TwistExpander_Achernar_Arx::Twist_B() {
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
            aIngress = (RotL64(aWindLaneA[((aIndex + 1119U)) & S_BLOCK1], 50U) ^ RotL64(aWindLaneB[((aIndex + 5148U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aKeyRowReadB[((aIndex + 4889U)) & W_KEY1], 3U);

            //
            aCross = RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 99U)) & S_BLOCK1], 14U) ^ RotL64(aWindLaneD[((aIndex + 277U)) & S_BLOCK1], 47U);

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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9238U)) & S_BLOCK1], 35U) ^ RotL64(aWindLaneC[((aIndex + 9216U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aScrapLaneA[((aIndex + 7378U)) & S_BLOCK1], 13U);

            //
            aCross = RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 9476U)) & S_BLOCK1], 21U) ^ RotL64(aWindLaneD[((S_BLOCK1 - aIndex + 5690U)) & S_BLOCK1], 44U);

            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // twist_loop_b loop 3
        //
        // Ingress:
        //      aWorkLaneB (-->), aWindLaneA (-->), aSource (<-?->)
        //
        // Cross:
        //      aWorkLaneA (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aSnowLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 12348U)) & S_BLOCK1], 47U) ^ RotL64(aWindLaneA[((aIndex + 11476U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aSource[((aIndex + 15614U)) & S_BLOCK1], 3U);

            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13210U)) & S_BLOCK1], 53U) ^ RotL64(aWindLaneC[((aIndex + 13414U)) & S_BLOCK1], 14U);

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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 21061U)) & S_BLOCK1], 53U) ^ RotL64(aWindLaneD[((aIndex + 17708U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 16866U)) & S_BLOCK1], 18U);

            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18912U)) & S_BLOCK1], 19U) ^ RotL64(aWindLaneA[((aIndex + 18670U)) & S_BLOCK1], 38U);

            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // twist_loop_b loop 5
        //
        // Ingress:
        //      aSnowLaneB (-->), aWorkLaneB (-->), aKeyRowReadA (<-?->)
        //
        // Cross:
        //      aSnowLaneA (<--), aWorkLaneA (<-?->)
        //
        // Destination:
        //      aSnowLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 26211U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 24940U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aKeyRowReadA[(((2047U - aIndex) + 26392U)) & W_KEY1], 12U);

            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 25245U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 24521U)) & S_BLOCK1], 14U);

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
            aIngress = RotL64(aSnowLaneC[((aIndex + 28617U)) & S_BLOCK1], 30U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 27501U)) & S_BLOCK1], 39U);

            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 31721U)) & S_BLOCK1], 51U) ^ RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 30231U)) & S_BLOCK1], 18U);

            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_B twist_loop_b (end)
    
}

void TwistExpander_Achernar_Arx::Twist_C() {
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
        //      aSnowLaneC (<--), aSnowLaneD (<--), aWorkLaneA (<-?->)
        //
        // Destination:
        //      aInvestLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 2970U)) & S_BLOCK1], 48U) ^ RotL64(aSnowLaneB[((aIndex + 3797U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWindLaneB[((S_BLOCK1 - aIndex + 3629U)) & S_BLOCK1], 23U);

            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 1101U)) & S_BLOCK1], 50U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 2309U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 212U)) & S_BLOCK1], 19U);

            aInvestLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_c loop 2
        //
        // Ingress:
        //      aInvestLaneA (-->), aSnowLaneC (-->), aWindLaneA (<-?->)
        //
        // Cross:
        //      aSnowLaneA (<--), aSnowLaneD (<--), aScrapLaneB (<-?->)
        //
        // Destination:
        //      aInvestLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8900U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneC[((aIndex + 7703U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aWindLaneA[((S_BLOCK1 - aIndex + 9074U)) & S_BLOCK1], 57U);

            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 6087U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 8262U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 9651U)) & S_BLOCK1], 41U);

            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // twist_loop_c loop 3
        //
        // Ingress:
        //      aInvestLaneB (-->), aSnowLaneA (-->), aWorkLaneB (<-?->)
        //
        // Cross:
        //      aInvestLaneA (<--), aSnowLaneC (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aOperationLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 11096U)) & S_BLOCK1], 60U) ^ RotL64(aSnowLaneA[((aIndex + 12210U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15514U)) & S_BLOCK1], 47U);

            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 11720U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 14304U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWindLaneC[((S_BLOCK1 - aIndex + 15283U)) & S_BLOCK1], 54U);

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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20700U)) & S_BLOCK1], 18U) ^ RotL64(aSnowLaneD[((aIndex + 20823U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aScrapLaneA[((aIndex + 18092U)) & S_BLOCK1], 39U);

            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 20485U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneA[((aIndex + 19394U)) & S_BLOCK1], 40U);

            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // twist_loop_c loop 5
        //
        // Ingress:
        //      aOperationLaneB (-->), aInvestLaneB (-->), aWindLaneD (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aInvestLaneA (<-?->)
        //
        // Destination:
        //      aOperationLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26670U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneB[((aIndex + 25010U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aWindLaneD[((aIndex + 25001U)) & S_BLOCK1], 3U);

            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25896U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneA[((aIndex + 23869U)) & S_BLOCK1], 56U);

            aOperationLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_c loop 6
        //
        // Ingress:
        //      aOperationLaneC (-->), aOperationLaneA (-->), aSource (<-?->)
        //
        // Cross:
        //      aOperationLaneB (<--), aSnowLaneB (<--)
        //
        // Destination:
        //      aOperationLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27329U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 30293U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aSource[((aIndex + 31381U)) & S_BLOCK1], 52U);

            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31114U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 27985U)) & S_BLOCK1], 12U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_C twist_loop_c (end)
    
}

void TwistExpander_Achernar_Arx::Twist_D() {
    // [twist arx]
    // GTwistRunTwist_D twist_loop_d (start)
    {
        //
        // twist_loop_d loop 1
        //
        // Ingress:
        //      aOperationLaneA (-->), aOperationLaneB (-->), aSnowLaneA (<-?->)
        //
        // Cross:
        //      aOperationLaneC (<--), aOperationLaneD (<--), aSnowLaneD (<-?->)
        //
        // Destination:
        //      aScrapLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3895U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((aIndex + 5132U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aSnowLaneA[((aIndex + 89U)) & S_BLOCK1], 3U);

            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3221U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1120U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 626U)) & S_BLOCK1], 13U);

            aScrapLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 2
        //
        // Ingress:
        //      aScrapLaneC (-->), aOperationLaneC (-->), aWindLaneB (<-?->)
        //
        // Cross:
        //      aOperationLaneA (<--), aOperationLaneD (<--), aKeyRowReadA (<-?->)
        //
        // Destination:
        //      aScrapLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneC[((aIndex + 10518U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 7799U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aWindLaneB[((aIndex + 6617U)) & S_BLOCK1], 37U);

            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8519U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6368U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aKeyRowReadA[(((2047U - aIndex) + 8013U)) & W_KEY1], 14U);

            aScrapLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 3
        //
        // Ingress:
        //      aScrapLaneD (-->), aOperationLaneA (-->), aInvestLaneB (<-?->)
        //
        // Cross:
        //      aScrapLaneC (<--), aOperationLaneC (<--), aSnowLaneB (<-?->)
        //
        // Destination:
        //      aWaterLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aScrapLaneD[((aIndex + 14767U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 15811U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 15443U)) & S_BLOCK1], 18U);

            //
            aCross = (RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 12028U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13996U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 11018U)) & S_BLOCK1], 27U);

            aWaterLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 4
        //
        // Ingress:
        //      aWaterLaneA (-->), aOperationLaneD (-->), aWindLaneA (<-?->)
        //
        // Cross:
        //      aScrapLaneD (<--), aOperationLaneA (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aWaterLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneA[((aIndex + 16472U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneD[((aIndex + 20837U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWindLaneA[((aIndex + 20409U)) & S_BLOCK1], 47U);

            //
            aCross = (RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 18165U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19814U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWindLaneC[((aIndex + 17754U)) & S_BLOCK1], 30U);

            aWaterLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 5
        //
        // Ingress:
        //      aWaterLaneB (-->), aScrapLaneD (-->), aWindLaneD (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aScrapLaneC (<--), aSnowLaneC (<-?->)
        //
        // Destination:
        //      aWaterLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneB[((aIndex + 25112U)) & S_BLOCK1], 53U) ^ RotL64(aScrapLaneD[((aIndex + 26820U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aWindLaneD[((aIndex + 22647U)) & S_BLOCK1], 41U);

            //
            aCross = (RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 23288U)) & S_BLOCK1], 3U) ^ RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 27051U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 26377U)) & S_BLOCK1], 44U);

            aWaterLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_d loop 6
        //
        // Ingress:
        //      aWaterLaneC (-->), aWaterLaneA (-->), aInvestLaneA (<-?->)
        //
        // Cross:
        //      aWaterLaneB (<--), aOperationLaneB (<--)
        //
        // Destination:
        //      aWaterLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneC[((aIndex + 27580U)) & S_BLOCK1], 5U) ^ RotL64(aWaterLaneA[((aIndex + 30173U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 30473U)) & S_BLOCK1], 43U);

            //
            aCross = RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 27832U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30275U)) & S_BLOCK1], 43U);

            aWaterLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_D twist_loop_d (end)
    
}

void TwistExpander_Achernar_Arx::Twist_E() {
    // [twist arx]
    // GTwistRunTwist_E twist_loop_e (start)
    {
        //
        // twist_loop_e loop 1
        //
        // Ingress:
        //      aWaterLaneA (-->), aWaterLaneB (-->), aSnowLaneC (<-?->)
        //
        // Cross:
        //      aWaterLaneC (<--), aWaterLaneD (<--), aOperationLaneA (<-?->)
        //
        // Destination:
        //      aInvestLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWaterLaneA[((aIndex + 824U)) & S_BLOCK1], 39U) ^ RotL64(aWaterLaneB[((aIndex + 3694U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aSnowLaneC[((aIndex + 4964U)) & S_BLOCK1], 30U);

            //
            aCross = (RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 1545U)) & S_BLOCK1], 39U) ^ RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 5346U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3025U)) & S_BLOCK1], 53U);

            aInvestLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 2
        //
        // Ingress:
        //      aInvestLaneC (-->), aWaterLaneC (-->), aInvestLaneA (<-?->)
        //
        // Cross:
        //      aWaterLaneA (<--), aWaterLaneD (<--), aKeyRowReadB (<-?->)
        //
        // Destination:
        //      aInvestLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 7986U)) & S_BLOCK1], 5U) ^ RotL64(aWaterLaneC[((aIndex + 5852U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 5804U)) & S_BLOCK1], 37U);

            //
            aCross = (RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 9453U)) & S_BLOCK1], 22U) ^ RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 5831U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aKeyRowReadB[(((2047U - aIndex) + 8600U)) & W_KEY1], 51U);

            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 3
        //
        // Ingress:
        //      aInvestLaneD (-->), aWaterLaneA (-->), aOperationLaneC (<-?->)
        //
        // Cross:
        //      aInvestLaneC (<--), aWaterLaneC (<--), aOperationLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 15969U)) & S_BLOCK1], 24U) ^ RotL64(aWaterLaneA[((aIndex + 14347U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 15612U)) & S_BLOCK1], 5U);

            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 15845U)) & S_BLOCK1], 41U) ^ RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 14149U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15259U)) & S_BLOCK1], 29U);

            aFuseLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 4
        //
        // Ingress:
        //      aFuseLaneA (-->), aWaterLaneD (-->), aSnowLaneB (<-?->)
        //
        // Cross:
        //      aInvestLaneD (<--), aWaterLaneA (<--), aScrapLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneA[((aIndex + 19667U)) & S_BLOCK1], 36U) ^ RotL64(aWaterLaneD[((aIndex + 21721U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aSnowLaneB[((aIndex + 16684U)) & S_BLOCK1], 57U);

            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 16902U)) & S_BLOCK1], 54U) ^ RotL64(aWaterLaneA[((S_BLOCK1 - aIndex + 17726U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aScrapLaneD[((S_BLOCK1 - aIndex + 16816U)) & S_BLOCK1], 29U);

            aFuseLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 5
        //
        // Ingress:
        //      aFuseLaneB (-->), aInvestLaneD (-->), aScrapLaneC (<-?->)
        //
        // Cross:
        //      aFuseLaneA (<--), aInvestLaneC (<--), aSnowLaneA (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneB[((aIndex + 25204U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneD[((aIndex + 23603U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aScrapLaneC[((aIndex + 24554U)) & S_BLOCK1], 19U);

            //
            aCross = (RotL64(aFuseLaneA[((S_BLOCK1 - aIndex + 22532U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 24527U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 22020U)) & S_BLOCK1], 39U);

            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_e loop 6
        //
        // Ingress:
        //      aFuseLaneC (-->), aFuseLaneA (-->), aOperationLaneB (<-?->)
        //
        // Cross:
        //      aFuseLaneB (<--), aWaterLaneB (<--), aSnowLaneD (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 27641U)) & S_BLOCK1], 3U) ^ RotL64(aFuseLaneA[((aIndex + 28545U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 29654U)) & S_BLOCK1], 41U);

            //
            aCross = (RotL64(aFuseLaneB[((S_BLOCK1 - aIndex + 30302U)) & S_BLOCK1], 57U) ^ RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 29457U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aSnowLaneD[((aIndex + 27484U)) & S_BLOCK1], 11U);

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_E twist_loop_e (end)
    
}

void TwistExpander_Achernar_Arx::Twist_F() {
    // [twist arx]
    // GTwistRunTwist_F twist_loop_f (start)
    {
        //
        // twist_loop_f loop 1
        //
        // Ingress:
        //      aFireLaneA (-->), aFireLaneB (-->), aInvestLaneD (-->), aWaterLaneD (<-?->)
        //
        // Cross:
        //      aFireLaneC (<--), aFireLaneD (<--), aOperationLaneB (<-?->)
        //
        // Destination:
        //      aInvestLaneE
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFireLaneA[((aIndex + 2498U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneB[((aIndex + 2442U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 2496U)) & S_BLOCK1], 6U) ^ RotL64(aWaterLaneD[((aIndex + 5052U)) & S_BLOCK1], 43U));

            //
            aCross = (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 535U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 1279U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2651U)) & S_BLOCK1], 19U);

            aInvestLaneE[aIndex] = aIngress;
        }
    
        //
        // twist_loop_f loop 2
        //
        // Ingress:
        //      aInvestLaneE (-->), aFireLaneC (-->), aScrapLaneD (-->), aWaterLaneA (<-?->)
        //
        // Cross:
        //      aFireLaneA (<--), aFireLaneD (<--), aSnowLaneA (<-?->)
        //
        // Destination:
        //      aInvestLaneF
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneE[((aIndex + 10341U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneC[((aIndex + 10571U)) & S_BLOCK1], 60U));
            aIngress ^= (RotL64(aScrapLaneD[((aIndex + 8864U)) & S_BLOCK1], 37U) ^ RotL64(aWaterLaneA[((aIndex + 7456U)) & S_BLOCK1], 5U));

            //
            aCross = (RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 8878U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6967U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aSnowLaneA[((aIndex + 10702U)) & S_BLOCK1], 14U);

            aInvestLaneF[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // twist_loop_f loop 3
        //
        // Ingress:
        //      aInvestLaneF (-->), aFireLaneA (-->), aOperationLaneC (-->), aInvestLaneB (<-?->)
        //
        // Cross:
        //      aInvestLaneE (<--), aFireLaneC (<--), aSource (<-?->)
        //
        // Destination:
        //      aEarthLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneF[((aIndex + 15773U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneA[((aIndex + 15764U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aOperationLaneC[((aIndex + 11034U)) & S_BLOCK1], 28U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 11674U)) & S_BLOCK1], 3U));

            //
            aCross = (RotL64(aInvestLaneE[((S_BLOCK1 - aIndex + 15039U)) & S_BLOCK1], 20U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12612U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aSource[((aIndex + 13161U)) & S_BLOCK1], 39U);

            aEarthLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_f loop 4
        //
        // Ingress:
        //      aEarthLaneA (-->), aFireLaneD (-->), aWaterLaneC (-->), aScrapLaneC (<-?->)
        //
        // Cross:
        //      aInvestLaneF (<--), aFireLaneA (<--), aOperationLaneA (<-?->)
        //
        // Destination:
        //      aEarthLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneA[((aIndex + 18506U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneD[((aIndex + 20769U)) & S_BLOCK1], 4U));
            aIngress ^= (RotL64(aWaterLaneC[((aIndex + 19508U)) & S_BLOCK1], 47U) ^ RotL64(aScrapLaneC[((aIndex + 20612U)) & S_BLOCK1], 57U));

            //
            aCross = (RotL64(aInvestLaneF[((S_BLOCK1 - aIndex + 19073U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 19776U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 18506U)) & S_BLOCK1], 28U);

            aEarthLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // twist_loop_f loop 5
        //
        // Ingress:
        //      aEarthLaneB (-->), aInvestLaneF (-->), aSnowLaneB (-->), aScrapLaneB (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aInvestLaneE (<--), aOperationLaneD (<-?->)
        //
        // Destination:
        //      aEarthLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneB[((aIndex + 22144U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneF[((aIndex + 26563U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aSnowLaneB[((aIndex + 22706U)) & S_BLOCK1], 37U) ^ RotL64(aScrapLaneB[((S_BLOCK1 - aIndex + 24071U)) & S_BLOCK1], 23U));

            //
            aCross = (RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 24981U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneE[((S_BLOCK1 - aIndex + 26752U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26713U)) & S_BLOCK1], 27U);

            aEarthLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_f loop 6
        //
        // Ingress:
        //      aEarthLaneC (-->), aEarthLaneA (-->), aScrapLaneA (-->), aInvestLaneC (<-?->)
        //
        // Cross:
        //      aEarthLaneB (<--), aFireLaneB (<--), aWaterLaneB (<-?->)
        //
        // Destination:
        //      aEarthLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneC[((aIndex + 30532U)) & S_BLOCK1], 3U) ^ RotL64(aEarthLaneA[((aIndex + 32357U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aScrapLaneA[((aIndex + 28346U)) & S_BLOCK1], 18U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 28683U)) & S_BLOCK1], 57U));

            //
            aCross = (RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 29307U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29548U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aWaterLaneB[((S_BLOCK1 - aIndex + 27795U)) & S_BLOCK1], 23U);

            aEarthLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_F twist_loop_f (end)
    
}

void TwistExpander_Achernar_Arx::Twist_G() {
    // [twist arx]
    // GTwistRunTwist_G twist_loop_g (start)
    {
        //
        // twist_loop_g loop 1
        //
        // Ingress:
        //      aEarthLaneA (-->), aEarthLaneB (-->), aKeyRowReadB (-->), aInvestLaneA (<-?->)
        //
        // Cross:
        //      aEarthLaneC (<--), aEarthLaneD (<--), aWaterLaneB (<-?->)
        //
        // Destination:
        //      aInvestLaneG
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aEarthLaneA[((aIndex + 138U)) & S_BLOCK1], 21U) ^ RotL64(aEarthLaneB[((aIndex + 867U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 5109U)) & W_KEY1], 5U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 1963U)) & S_BLOCK1], 48U));

            //
            aCross = (RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 3255U)) & S_BLOCK1], 23U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 3484U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWaterLaneB[((aIndex + 4451U)) & S_BLOCK1], 14U);

            aInvestLaneG[aIndex] = aIngress;
        }
    
        //
        // twist_loop_g loop 2
        //
        // Ingress:
        //      aInvestLaneG (-->), aEarthLaneC (-->), aSnowLaneD (-->), aInvestLaneE (<-?->)
        //
        // Cross:
        //      aEarthLaneA (<--), aEarthLaneD (<--), aWaterLaneC (<-?->)
        //
        // Destination:
        //      aInvestLaneH
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneG[((aIndex + 9421U)) & S_BLOCK1], 23U) ^ RotL64(aEarthLaneC[((aIndex + 7930U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 6625U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneE[((aIndex + 10382U)) & S_BLOCK1], 46U));

            //
            aCross = (RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 8154U)) & S_BLOCK1], 23U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 8177U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aWaterLaneC[((S_BLOCK1 - aIndex + 5562U)) & S_BLOCK1], 41U);

            aInvestLaneH[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // twist_loop_g loop 3
        //
        // Ingress:
        //      aInvestLaneH (-->), aEarthLaneA (-->), aKeyRowReadA (-->), aFireLaneA (<-?->)
        //
        // Cross:
        //      aInvestLaneG (<--), aEarthLaneC (<--), aSnowLaneC (<-?->)
        //
        // Destination:
        //      aWorkLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aInvestLaneH[((aIndex + 11032U)) & S_BLOCK1], 19U) ^ RotL64(aEarthLaneA[((aIndex + 12173U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aKeyRowReadA[((aIndex + 16113U)) & W_KEY1], 38U) ^ RotL64(aFireLaneA[((aIndex + 13863U)) & S_BLOCK1], 27U));

            //
            aCross = (RotL64(aInvestLaneG[((S_BLOCK1 - aIndex + 15555U)) & S_BLOCK1], 19U) ^ RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 11134U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aSnowLaneC[((aIndex + 14597U)) & S_BLOCK1], 5U);

            aWorkLaneA[aIndex] = aIngress;
        }
    
        //
        // twist_loop_g loop 4
        //
        // Ingress:
        //      aWorkLaneA (-->), aEarthLaneD (-->), aInvestLaneC (-->), aWaterLaneA (<-?->)
        //
        // Cross:
        //      aInvestLaneH (<--), aEarthLaneA (<--), aFireLaneD (<-?->)
        //
        // Destination:
        //      aWorkLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 19170U)) & S_BLOCK1], 37U) ^ RotL64(aEarthLaneD[((aIndex + 19922U)) & S_BLOCK1], 6U));
            aIngress ^= (RotL64(aInvestLaneC[((aIndex + 21205U)) & S_BLOCK1], 23U) ^ RotL64(aWaterLaneA[((aIndex + 21395U)) & S_BLOCK1], 47U));

            //
            aCross = (RotL64(aInvestLaneH[((S_BLOCK1 - aIndex + 19582U)) & S_BLOCK1], 13U) ^ RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 18329U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 21535U)) & S_BLOCK1], 42U);

            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // twist_loop_g loop 5
        //
        // Ingress:
        //      aWorkLaneB (-->), aInvestLaneH (-->), aInvestLaneD (-->), aInvestLaneF (<-?->)
        //
        // Cross:
        //      aWorkLaneA (<--), aInvestLaneG (<--), aWaterLaneD (<-?->)
        //
        // Destination:
        //      aWorkLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23478U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneH[((aIndex + 22477U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 22945U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneF[((aIndex + 22218U)) & S_BLOCK1], 30U));

            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27012U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneG[((S_BLOCK1 - aIndex + 23354U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aWaterLaneD[((S_BLOCK1 - aIndex + 24488U)) & S_BLOCK1], 57U);

            aWorkLaneC[aIndex] = aIngress;
        }
    
        //
        // twist_loop_g loop 6
        //
        // Ingress:
        //      aWorkLaneC (-->), aWorkLaneA (-->), aInvestLaneB (-->), aFireLaneC (<-?->)
        //
        // Cross:
        //      aWorkLaneB (<--), aEarthLaneB (<--), aFireLaneB (<-?->)
        //
        // Destination:
        //      aWorkLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27635U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 31823U)) & S_BLOCK1], 38U));
            aIngress ^= (RotL64(aInvestLaneB[((aIndex + 29049U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneC[((aIndex + 27989U)) & S_BLOCK1], 27U));

            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29975U)) & S_BLOCK1], 19U) ^ RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 30084U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 31713U)) & S_BLOCK1], 30U);

            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_G twist_loop_g (end)
    
}

void TwistExpander_Achernar_Arx::GROW_A() {
    // [grow arx]
    // GROW_A grow_key_a (start)
    {
        //
        // grow_key_a loop 1
        //
        // Ingress:
        //      aWorkLaneA (-->), aWorkLaneB (-->), aInvestLaneB (-->), aEarthLaneD (<-?->)
        //
        // Cross:
        //      aWorkLaneC (<--), aWorkLaneD (<--), aFireLaneB (<-?->)
        //
        // Destination:
        //      aOperationLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 712U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 5019U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aInvestLaneB[((aIndex + 1876U)) & S_BLOCK1], 39U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 1964U)) & S_BLOCK1], 23U));

            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1260U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 1785U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 1724U)) & S_BLOCK1], 42U);

            aOperationLaneB[aIndex] = aIngress;
        }
    
        //
        // grow_key_a loop 2
        //
        // Ingress:
        //      aOperationLaneB (-->), aWorkLaneC (-->), aScrapLaneB (-->), aSnowLaneD (<-?->)
        //
        // Cross:
        //      aWorkLaneA (<--), aWorkLaneD (<--), aOperationLaneC (<-?->)
        //
        // Destination:
        //      aOperationLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 8851U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneC[((aIndex + 7482U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aScrapLaneB[((aIndex + 7351U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 8541U)) & S_BLOCK1], 47U));

            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8254U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8994U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10181U)) & S_BLOCK1], 26U);

            aOperationLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // grow_key_a loop 3
        //
        // Ingress:
        //      aOperationLaneD (-->), aWorkLaneA (-->), aInvestLaneF (-->), aFireLaneD (<-?->)
        //
        // Cross:
        //      aOperationLaneB (<--), aWorkLaneC (<--), aEarthLaneB (<-?->)
        //
        // Destination:
        //      aExpandLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aOperationLaneD[((aIndex + 12528U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((aIndex + 15969U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aInvestLaneF[((aIndex + 14533U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 13448U)) & S_BLOCK1], 13U));

            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12192U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14055U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 13009U)) & S_BLOCK1], 23U);

            aExpandLaneA[aIndex] = aIngress;
        }
    
        //
        // grow_key_a loop 4
        //
        // Ingress:
        //      aExpandLaneA (-->), aWorkLaneD (-->), aSnowLaneB (-->), aWaterLaneA (<-?->)
        //
        // Cross:
        //      aOperationLaneD (<--), aWorkLaneA (<--), aInvestLaneE (<-?->)
        //
        // Destination:
        //      aExpandLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19885U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((aIndex + 21008U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aSnowLaneB[((aIndex + 20062U)) & S_BLOCK1], 3U) ^ RotL64(aWaterLaneA[((aIndex + 17958U)) & S_BLOCK1], 27U));

            //
            aCross = (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18296U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20623U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aInvestLaneE[((aIndex + 18284U)) & S_BLOCK1], 12U);

            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // grow_key_a loop 5
        //
        // Ingress:
        //      aExpandLaneB (-->), aOperationLaneD (-->), aWaterLaneC (-->), aScrapLaneC (<-?->)
        //
        // Cross:
        //      aExpandLaneA (<--), aOperationLaneB (<--), aOperationLaneA (<-?->)
        //
        // Destination:
        //      aExpandLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24482U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((aIndex + 26555U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aWaterLaneC[((aIndex + 22284U)) & S_BLOCK1], 40U) ^ RotL64(aScrapLaneC[((S_BLOCK1 - aIndex + 25298U)) & S_BLOCK1], 51U));

            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25658U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25979U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26424U)) & S_BLOCK1], 47U);

            aExpandLaneC[aIndex] = aIngress;
        }
    
        //
        // grow_key_a loop 6
        //
        // Ingress:
        //      aExpandLaneC (-->), aExpandLaneA (-->), aScrapLaneA (-->), aScrapLaneD (<-?->)
        //
        // Cross:
        //      aExpandLaneB (<--), aWorkLaneB (<--), aInvestLaneA (<-?->)
        //
        // Destination:
        //      aExpandLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30960U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 29106U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aScrapLaneA[((aIndex + 31316U)) & S_BLOCK1], 26U) ^ RotL64(aScrapLaneD[((aIndex + 29560U)) & S_BLOCK1], 11U));

            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30661U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32420U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 29909U)) & S_BLOCK1], 30U);

            aExpandLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GROW_A grow_key_a (end)
    
}

void TwistExpander_Achernar_Arx::GROW_B() {
    // [grow arx]
    // GROW_B grow_key_b (start)
    {
        //
        // grow_key_b loop 1
        //
        // Ingress:
        //      aExpandLaneA (-->), aExpandLaneB (-->), aOperationLaneD (-->), aInvestLaneH (<-?->)
        //
        // Cross:
        //      aExpandLaneC (<--), aExpandLaneD (<--), aOperationLaneB (<-?->)
        //
        // Destination:
        //      aFuseLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5434U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 1373U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 721U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneH[((S_BLOCK1 - aIndex + 3724U)) & S_BLOCK1], 60U));

            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 175U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4336U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 5248U)) & S_BLOCK1], 11U);

            aFuseLaneC[aIndex] = aIngress;
        }
    
        //
        // grow_key_b loop 2
        //
        // Ingress:
        //      aFuseLaneC (-->), aExpandLaneC (-->), aWindLaneD (-->), aFireLaneC (<-?->)
        //
        // Cross:
        //      aExpandLaneA (<--), aExpandLaneD (<--), aInvestLaneG (<-?->)
        //
        // Destination:
        //      aFuseLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneC[((aIndex + 6154U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 8859U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aWindLaneD[((aIndex + 8227U)) & S_BLOCK1], 50U) ^ RotL64(aFireLaneC[((aIndex + 8183U)) & S_BLOCK1], 11U));

            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10577U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9643U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aInvestLaneG[((aIndex + 7500U)) & S_BLOCK1], 51U);

            aFuseLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // grow_key_b loop 3
        //
        // Ingress:
        //      aFuseLaneD (-->), aExpandLaneA (-->), aInvestLaneD (-->), aEarthLaneC (<-?->)
        //
        // Cross:
        //      aFuseLaneC (<--), aExpandLaneC (<--), aWindLaneC (<-?->)
        //
        // Destination:
        //      aWorkLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aFuseLaneD[((aIndex + 14281U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 11811U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 10954U)) & S_BLOCK1], 29U) ^ RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 16383U)) & S_BLOCK1], 41U));

            //
            aCross = (RotL64(aFuseLaneC[((S_BLOCK1 - aIndex + 15877U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15095U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWindLaneC[((aIndex + 11154U)) & S_BLOCK1], 21U);

            aWorkLaneA[aIndex] = aIngress;
        }
    
        //
        // grow_key_b loop 4
        //
        // Ingress:
        //      aWorkLaneA (-->), aExpandLaneD (-->), aWaterLaneB (-->), aInvestLaneC (<-?->)
        //
        // Cross:
        //      aFuseLaneD (<--), aExpandLaneA (<--), aWindLaneB (<-?->)
        //
        // Destination:
        //      aWorkLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 18957U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 20774U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aWaterLaneB[((aIndex + 18441U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 20768U)) & S_BLOCK1], 10U));

            //
            aCross = (RotL64(aFuseLaneD[((S_BLOCK1 - aIndex + 17789U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18372U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWindLaneB[((aIndex + 17580U)) & S_BLOCK1], 35U);

            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // grow_key_b loop 5
        //
        // Ingress:
        //      aWorkLaneB (-->), aFuseLaneD (-->), aFireLaneA (-->), aSnowLaneA (<-?->)
        //
        // Cross:
        //      aWorkLaneA (<--), aFuseLaneC (<--), aWindLaneA (<-?->)
        //
        // Destination:
        //      aWorkLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 26256U)) & S_BLOCK1], 58U) ^ RotL64(aFuseLaneD[((aIndex + 25050U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 26009U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneA[((aIndex + 22513U)) & S_BLOCK1], 43U));

            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27072U)) & S_BLOCK1], 41U) ^ RotL64(aFuseLaneC[((S_BLOCK1 - aIndex + 26565U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWindLaneA[((aIndex + 26309U)) & S_BLOCK1], 26U);

            aWorkLaneC[aIndex] = aIngress;
        }
    
        //
        // grow_key_b loop 6
        //
        // Ingress:
        //      aWorkLaneC (-->), aWorkLaneA (-->), aSnowLaneC (-->), aEarthLaneA (<-?->)
        //
        // Cross:
        //      aWorkLaneB (<--), aExpandLaneB (<--), aWaterLaneD (<-?->)
        //
        // Destination:
        //      aWorkLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29636U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 27648U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aSnowLaneC[((aIndex + 27616U)) & S_BLOCK1], 29U) ^ RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 28376U)) & S_BLOCK1], 58U));

            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31657U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29382U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWaterLaneD[((aIndex + 31778U)) & S_BLOCK1], 21U);

            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GROW_B grow_key_b (end)
    
}
