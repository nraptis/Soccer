#include "MaskLibrary.hpp"

#include <array>

namespace {

constexpr std::array<std::uint8_t, MaskLibrary::kMaskCount> kMasks = {
    0xF0u, // 1 1 1 1 0 0 0 0
    0x0Fu, // 0 0 0 0 1 1 1 1

    0x33u, // 0 0 1 1 0 0 1 1
    0xCCu, // 1 1 0 0 1 1 0 0

    0x55u, // 0 1 0 1 0 1 0 1
    0xAAu, // 1 0 1 0 1 0 1 0

    0x69u, // 0 1 1 0 1 0 0 1
    0x96u, // 1 0 0 1 0 1 1 0

    0x19u, // 0 0 0 1 1 0 0 1
    0x98u, // 1 0 0 1 1 0 0 0

    0x1Au, // 0 0 0 1 1 0 1 0
    0x58u, // 0 1 0 1 1 0 0 0

    0x1Cu, // 0 0 0 1 1 1 0 0
    0x38u, // 0 0 1 1 1 0 0 0

    0x25u, // 0 0 1 0 0 1 0 1
    0xA4u, // 1 0 1 0 0 1 0 0

    0x26u, // 0 0 1 0 0 1 1 0
    0x64u, // 0 1 1 0 0 1 0 0

    0x2Cu, // 0 0 1 0 1 1 0 0
    0x34u, // 0 0 1 1 0 1 0 0

    0x43u, // 0 1 0 0 0 0 1 1
    0xC2u, // 1 1 0 0 0 0 1 0

    0x46u, // 0 1 0 0 0 1 1 0
    0x62u, // 0 1 1 0 0 0 1 0

    0x4Au, // 0 1 0 0 1 0 1 0
    0x52u, // 0 1 0 1 0 0 1 0

    0x83u, // 1 0 0 0 0 0 1 1
    0xC1u, // 1 1 0 0 0 0 0 1

    0x85u, // 1 0 0 0 0 1 0 1
    0xA1u, // 1 0 1 0 0 0 0 1

    0x89u, // 1 0 0 0 1 0 0 1
    0x91u, // 1 0 0 1 0 0 0 1
};

}  // namespace

std::vector<std::uint8_t> MaskLibrary::GetMasks() {
    std::vector<std::uint8_t> aResult(kMaskCount, 0);
    for (std::size_t aIndex=0; aIndex<kMaskCount; aIndex++) {
        aResult[aIndex] = kMasks[aIndex];
    }
    return aResult;
}

bool MaskLibrary::HasMask(std::size_t pIndex) {
    if (pIndex < kMaskCount) {
        return true;
    } else {
        return false;
    }
}

std::uint8_t MaskLibrary::GetMask(std::size_t pIndex) {
  return kMasks[pIndex];
}
