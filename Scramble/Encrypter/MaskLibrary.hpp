#ifndef SOCCER_ENCRYPTION_MASK_LIBRARY_HPP_
#define SOCCER_ENCRYPTION_MASK_LIBRARY_HPP_

#include <cstddef>
#include <cstdint>
#include <vector>

class MaskLibrary {
public:
    static std::uint8_t GetMask(std::size_t pIndex);
    static bool HasMask(std::size_t pIndex);
    static std::vector<std::uint8_t> GetMasks();
    static constexpr std::size_t kMaskCount = 32u;
};

#endif  // SOCCER_ENCRYPTION_MASK_LIBRARY_HPP_
