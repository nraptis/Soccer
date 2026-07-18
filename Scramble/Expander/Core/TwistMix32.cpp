//
//  TwistMix32.cpp
//  MeanMachine
//
//  Created by icarus black on 6/21/26.
//


#include "TwistMix32.hpp"

std::uint32_t TwistMix32::DiffuseA(std::uint32_t pValue) {
    pValue ^= pValue >> 16;
    pValue *= 0x85EBCA6B;
    pValue ^= pValue >> 13;
    pValue *= 0xC2B2AE35;
    pValue ^= pValue >> 16;
    return pValue;
}

std::uint32_t TwistMix32::DiffuseB(std::uint32_t pValue) {
    pValue ^= pValue >> 16;
    pValue *= 0x21F0AAAD;
    pValue ^= pValue >> 15;
    pValue *= 0x735A2D97;
    pValue ^= pValue >> 15;
    return pValue;
}

std::uint32_t TwistMix32::DiffuseC(std::uint32_t pValue) {
    pValue ^= pValue >> 16;
    pValue *= 0x7FEB352D;
    pValue ^= pValue >> 15;
    pValue *= 0x846CA68B;
    pValue ^= pValue >> 16;
    return pValue;
}
