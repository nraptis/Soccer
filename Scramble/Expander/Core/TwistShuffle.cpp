//
//  TwistShuffle.cpp
//  MeanMachine
//
//  Created by Dragon on 5/11/26.
//

#include "TwistShuffle.hpp"
#include "TwistWorkSpace.hpp"

void TwistShuffle::Execute(
    std::size_t *pIndexList256,
                           const std::uint8_t *pBlockSizedEntropySource) {
    if ((pIndexList256 == nullptr) ||
        (pBlockSizedEntropySource == nullptr)) {
        return;
    }
    
    std::size_t *aDestination = pIndexList256;
    std::size_t *const aDestinationEnd = pIndexList256 + 256U;
    std::size_t aValue = 0U;
    
    while (aDestination < aDestinationEnd) {
        *aDestination = aValue;
        ++aDestination;
        ++aValue;
    }
    
    ShuffleList256(pIndexList256,
                   pBlockSizedEntropySource,
                   0U,
                   S_EIGHTH,
                   1U);
    ShuffleList256(pIndexList256,
                   pBlockSizedEntropySource,
                   S_EIGHTH,
                   2U * S_EIGHTH,
                   1U);
    ShuffleList256(pIndexList256,
                   pBlockSizedEntropySource,
                   2U * S_EIGHTH,
                   3U * S_EIGHTH,
                   1U);
    ShuffleList256(pIndexList256,
                   pBlockSizedEntropySource,
                   3U * S_EIGHTH,
                   4U * S_EIGHTH,
                   1U);
    ShuffleList256(pIndexList256,
                   pBlockSizedEntropySource,
                   4U * S_EIGHTH,
                   5U * S_EIGHTH,
                   1U);
    ShuffleList256(pIndexList256,
                   pBlockSizedEntropySource,
                   5U * S_EIGHTH,
                   6U * S_EIGHTH,
                   1U);
    ShuffleList256(pIndexList256,
                   pBlockSizedEntropySource,
                   6U * S_EIGHTH,
                   7U * S_EIGHTH,
                   1U);
    ShuffleList256(pIndexList256,
                   pBlockSizedEntropySource,
                   7U * S_EIGHTH,
                   S_BLOCK,
                   1U);
}

