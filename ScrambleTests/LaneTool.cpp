//
//  LaneTool.cpp
//  ScrambleTests
//
//  Created by nicholas raptis on 7/17/26.
//

#include "LaneTool.hpp"

void LaneTool::PrintMismatch(std::string pName, std::uint8_t *pLaneA, std::uint8_t *pLaneB, std::size_t pIndex, std::size_t pSize) {
    
    printf("Mismatch found at %zu of %zu\n", pIndex, pSize);
    
    
    
    std::size_t aStartIndex = 0;
    if (pIndex > 16) {
        aStartIndex = pIndex - 16;
    }
    
    std::size_t aEnd = pIndex + 16;
    if (aEnd > pSize) {
        aEnd = pSize;
    }
    
    std::size_t aIndex = aStartIndex;
    
    printf("%s A: ", pName.c_str());
        while (aIndex < pIndex) {
            printf("%02X", pLaneA[aIndex]);
            aIndex++;
        }
    printf(" { %02X } ", pLaneA[aIndex]);
    aIndex++;
    while (aIndex < aEnd) {
        printf("%02X", pLaneA[aIndex]);
        aIndex++;
    }
    printf("\n%s B: ", pName.c_str());
    aIndex = aStartIndex;
    
    
        while (aIndex < pIndex) {
            printf("%02X", pLaneB[aIndex]);
            aIndex++;
        }
    printf(" { %02X } ", pLaneB[aIndex]);
    aIndex++;
    while (aIndex < aEnd) {
        printf("%02X", pLaneB[aIndex]);
        aIndex++;
    }
    printf("\n");
    
}
