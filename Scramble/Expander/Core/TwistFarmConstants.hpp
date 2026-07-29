//
//  TwistRipConstants.hpp
//  MeanMachine
//
//  Created by nicholas on 5/23/26.
//

#ifndef TwistFarmConstants_hpp
#define TwistFarmConstants_hpp

#include <cstdint>
#include "TwistWorkSpace.hpp"

class TwistFarmConstants {
public:
    TwistFarmConstants();
    
    static void                 Derive(const std::uint8_t *pSource,
                                       std::uint8_t *pFoldLaneA,
                                       std::uint8_t *pFoldLaneB,
                                       std::uint8_t *pFoldLaneC,
                                       TwistDomainConstants *pConstants);
};

#endif /* TwistFarmConstants_hpp */
