//
//  TwistIndexShuffle.cpp
//  MeanMachine
//
//  Created by Dragon on 5/11/26.
//

#include "TwistIndexShuffle.hpp"
#include "TwistWorkSpace.hpp"

void TwistIndexShuffle::ExecuteA(std::size_t *pIndexList256,
                                 const std::uint8_t *pBlockSizedEntropySource) {
    if ((pIndexList256 == nullptr) || (pBlockSizedEntropySource == nullptr)) {
        return;
    }
    
    std::size_t *aWrite = pIndexList256;
    for (std::size_t aValue = 0; aValue < 256; ++aValue) {
        *aWrite = aValue;
        ++aWrite;
    }
    
    for (std::size_t aEntropyIndex=0U; aEntropyIndex<S_HALF; aEntropyIndex+=2U) {
        const std::size_t aIndexA = pBlockSizedEntropySource[aEntropyIndex];
        const std::size_t aIndexB = pBlockSizedEntropySource[aEntropyIndex + 1U];
        const std::size_t aHold = pIndexList256[aIndexA];
        pIndexList256[aIndexA] = pIndexList256[aIndexB];
        pIndexList256[aIndexB] = aHold;
    }
}

void TwistIndexShuffle::ExecuteB(std::size_t *pIndexList256,
                                 const std::uint8_t *pBlockSizedEntropySource) {
    if ((pIndexList256 == nullptr) || (pBlockSizedEntropySource == nullptr)) {
        return;
    }
    
    std::size_t *aWrite = pIndexList256;
    for (std::size_t aValue = 0; aValue < 256; ++aValue) {
        *aWrite = aValue;
        ++aWrite;
    }
    
    for (std::size_t aEntropyIndex=S_HALF; aEntropyIndex<S_BLOCK; aEntropyIndex+=2U) {
        const std::size_t aIndexA = pBlockSizedEntropySource[aEntropyIndex];
        const std::size_t aIndexB = pBlockSizedEntropySource[aEntropyIndex + 1U];
        const std::size_t aHold = pIndexList256[aIndexA];
        pIndexList256[aIndexA] = pIndexList256[aIndexB];
        pIndexList256[aIndexB] = aHold;
    }
}
