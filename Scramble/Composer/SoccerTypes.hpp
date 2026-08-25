//
//  CipherType.h
//  MeanMachine
//
//  Created by Icarus Black on 8/4/26.
//

#ifndef CipherType_h
#define CipherType_h

#include <cstddef>
#include <cstdint>

#ifndef SOCCER_ENCRYPTION_STRENGTH_DEFINED
#define SOCCER_ENCRYPTION_STRENGTH_DEFINED
enum class EncryptionStrength : std::uint8_t {
    kTest = 3,
    kWeak = 0,
    kNormal = 1,
    kStrong = 2,
};
#endif

/*

EncryptionStrength.kLow (Lane Budget = 3.25 through 4)
L3: [kKeyConsumeSimple,    kMoverPrimary, kMoverAny]
L2: [kKeyConsumeAny,       kMoverPrimary, kMoverAny]
L1: [kKeyConsumeAny,       kMoverPrimary, kMoverAny]
F3: [kKeyConsumeSimple,    kMoverPrimary, kMoverAny]
 
 EncryptionStrength.kMedium (Lane Budget = 7.25 through 8)
 Extra stipulation: We can only use one of each of these: 3-lane, 4-lane
 L3: [kKeyConsumeComplex, kMoverPrimary, kMoverAny, kMoverAny, kMoverAny]
 L2: [kKeyConsumeSimple, kMoverPrimary, kMoverAny, kKeyConsumeSimple, kMoverAny, kMoverAny]
 L1: [kKeyConsumeAny, kMoverPrimary, kMoverAny, kKeyConsumeAny, kMoverPrimary, kMoverAny, kMoverAny]
 F3: [kKeyConsumeSimple,    kMoverPrimary, kMoverAny, kKeyConsumeAny, kMoverPrimary, kMoverAny, kMoverAny]
 
 EncryptionStrength.kHigh (Lane Budget = 15.25 through 16)
 Exactly one key consumes 3 lanes, and exactly one key consumes 4 lanes.
 L3: [kKeyConsumeSimple, kMoverPrimary, kMoverAny, kMoverAny, kKeyConsumeAny, kMoverPrimary, kMoverAny, kMoverAny, kKeyConsumeAny, kMoverPrimary, kMoverAny, kMoverAny, kKeyConsumeComplex, kMoverPrimary, kMoverAny, kMoverAny]
 L2: [kKeyConsumeSimple, kMoverPrimary, kMoverAny, kMoverAny, kKeyConsumeComplex, kMoverPrimary, kMoverAny, kMoverAny, kKeyConsumeSimple, kMoverPrimary, kMoverAny, kMoverAny]
 L1: [kKeyConsumeSimple, kMoverPrimary, kMoverAny, kMoverAny, kKeyConsumeComplex, kMoverPrimary, kMoverAny, kMoverAny, kKeyConsumeAny, kMoverPrimary, kMoverAny, kMoverAny]
 F3: [kKeyConsumeSimple, kMoverPrimary, kMoverAny, kMoverAny, kKeyConsumeAny, kMoverPrimary, kMoverAny, kMoverAny, kKeyConsumeAny, kMoverPrimary, kMoverAny, kMoverAny, kKeyConsumeComplex, kMoverPrimary, kMoverAny, kMoverAny]
 
*/

#define CIPHER_MASK_CIPHER_ID             0x0000001FU

// Lane counts 0-4 are one-hot in bits 5-9.
#define CIPHER_MASK_LANE_COUNT_0          0x00000020U
#define CIPHER_MASK_LANE_COUNT_1          0x00000040U
#define CIPHER_MASK_LANE_COUNT_2          0x00000080U
#define CIPHER_MASK_LANE_COUNT_3          0x00000100U
#define CIPHER_MASK_LANE_COUNT_4          0x00000200U

#define CIPHER_FLAG_MUTATE_SIMPLE         0x00000400U
#define CIPHER_FLAG_MUTATE_COMPLEX        0x00000800U
#define CIPHER_FLAG_MUTATE_ANY            0x00001000U

// Rotation is separate from the mover hierarchy. These two flags are
// mutually exclusive: plain rotation (R) or masked rotation (RM).
#define CIPHER_FLAG_ROTATION              0x00002000U
#define CIPHER_FLAG_ROTATION_MASKED       0x00004000U

// Movers are either primary, wide diffusion or secondary garnish.
#define CIPHER_FLAG_PRIMARY_MOVER         0x00008000U
#define CIPHER_FLAG_SECONDARY_MOVER       0x00010000U
#define CIPHER_FLAG_MOVER_ANY             0x00040000U

#define IS_MUTATE_SIMPLE(pType) \
    ((static_cast<std::uint32_t>(pType) & CIPHER_FLAG_MUTATE_SIMPLE) != 0U)
#define IS_MUTATE_COMPLEX(pType) \
    ((static_cast<std::uint32_t>(pType) & CIPHER_FLAG_MUTATE_COMPLEX) != 0U)
#define IS_MUTATE_ANY(pType) \
    ((static_cast<std::uint32_t>(pType) & CIPHER_FLAG_MUTATE_ANY) != 0U)

#define IS_ROTATION(pType) \
    ((static_cast<std::uint32_t>(pType) & CIPHER_FLAG_ROTATION) != 0U)
#define IS_ROTATION_MASKED(pType) \
    ((static_cast<std::uint32_t>(pType) & CIPHER_FLAG_ROTATION_MASKED) != 0U)
#define IS_ROTATION_ANY(pType) \
    ((static_cast<std::uint32_t>(pType) & \
      (CIPHER_FLAG_ROTATION | CIPHER_FLAG_ROTATION_MASKED)) != 0U)

#define IS_PRIMARY_MOVER(pType) \
    ((static_cast<std::uint32_t>(pType) & CIPHER_FLAG_PRIMARY_MOVER) != 0U)
#define IS_SECONDARY_MOVER(pType) \
    ((static_cast<std::uint32_t>(pType) & CIPHER_FLAG_SECONDARY_MOVER) != 0U)
#define IS_MOVER_ANY(pType) \
    ((static_cast<std::uint32_t>(pType) & CIPHER_FLAG_MOVER_ANY) != 0U)

#define IS_MASKED(pType) \
    ((static_cast<std::uint32_t>(pType) & \
      (CIPHER_FLAG_ROTATION_MASKED | CIPHER_FLAG_MOVER_ANY)) != 0U)


/*
kPasswordXORCipher
kPasswordAddCipher
kPasswordSubtractCipher

kPasswordJumpXORCipher
kPasswordJumpAddCipher
kPasswordJumpSubtractCipher

kPepperNoiseXORCipher
kPepperJumpNoiseXORCipher
kPepperDualJumpNoiseXORCipher

kCascadeCipher
kCascadeJumpCipher

kReverseMaskCipher
kRippleMaskBlockCipher32
kRippleMaskBlockCipher64

kSplintMaskBlockCipher32
kSplintMaskBlockCipher64

kReverseMaskByteBlockCipher32
kReverseMaskByteBlockCipher64

kInvertMaskCipher
kRotateMaskCipher
kRotateCipher
*/

enum class CipherType : std::uint32_t {
    kNone = 0U,
    
    kPasswordXORCipher = 0x01U | CIPHER_MASK_LANE_COUNT_1 | CIPHER_FLAG_MUTATE_SIMPLE | CIPHER_FLAG_MUTATE_ANY,
    kPasswordAddCipher = 0x02U | CIPHER_MASK_LANE_COUNT_1 | CIPHER_FLAG_MUTATE_SIMPLE | CIPHER_FLAG_MUTATE_ANY,
    kPasswordSubtractCipher = 0x03U | CIPHER_MASK_LANE_COUNT_1 | CIPHER_FLAG_MUTATE_SIMPLE | CIPHER_FLAG_MUTATE_ANY,

    kPasswordJumpXORCipher = 0x04U | CIPHER_MASK_LANE_COUNT_2 | CIPHER_FLAG_MUTATE_SIMPLE | CIPHER_FLAG_MUTATE_COMPLEX | CIPHER_FLAG_MUTATE_ANY,
    kPasswordJumpAddCipher = 0x05U | CIPHER_MASK_LANE_COUNT_2 | CIPHER_FLAG_MUTATE_SIMPLE | CIPHER_FLAG_MUTATE_COMPLEX | CIPHER_FLAG_MUTATE_ANY,
    kPasswordJumpSubtractCipher = 0x06U | CIPHER_MASK_LANE_COUNT_2 | CIPHER_FLAG_MUTATE_SIMPLE | CIPHER_FLAG_MUTATE_COMPLEX | CIPHER_FLAG_MUTATE_ANY,

    kPepperNoiseXORCipher = 0x07U | CIPHER_MASK_LANE_COUNT_2 | CIPHER_FLAG_MUTATE_SIMPLE | CIPHER_FLAG_MUTATE_COMPLEX | CIPHER_FLAG_MUTATE_ANY,
    kPepperJumpNoiseXORCipher = 0x08U | CIPHER_MASK_LANE_COUNT_3 | CIPHER_FLAG_MUTATE_SIMPLE | CIPHER_FLAG_MUTATE_COMPLEX | CIPHER_FLAG_MUTATE_ANY,
    kPepperDualJumpNoiseXORCipher = 0x09U | CIPHER_MASK_LANE_COUNT_4 | CIPHER_FLAG_MUTATE_SIMPLE | CIPHER_FLAG_MUTATE_COMPLEX | CIPHER_FLAG_MUTATE_ANY,
    
    kCascadeCipher = 0x12U | CIPHER_MASK_LANE_COUNT_1 | CIPHER_FLAG_MUTATE_COMPLEX | CIPHER_FLAG_MUTATE_ANY,
    kCascadeJumpCipher = 0x13U | CIPHER_MASK_LANE_COUNT_2 | CIPHER_FLAG_MUTATE_COMPLEX | CIPHER_FLAG_MUTATE_ANY,
    
    kRotateMaskCipher = 0x0AU | CIPHER_MASK_LANE_COUNT_0 | CIPHER_FLAG_ROTATION_MASKED,
    kRotateCipher = 0x0FU | CIPHER_MASK_LANE_COUNT_0 | CIPHER_FLAG_ROTATION,
    
    kReverseMaskCipher = 0x0BU | CIPHER_MASK_LANE_COUNT_0 | CIPHER_FLAG_PRIMARY_MOVER | CIPHER_FLAG_MOVER_ANY,
    kSplintMaskBlockCipher32 = 0x10U | CIPHER_MASK_LANE_COUNT_0 | CIPHER_FLAG_PRIMARY_MOVER | CIPHER_FLAG_MOVER_ANY,
    kSplintMaskBlockCipher64 = 0x11U | CIPHER_MASK_LANE_COUNT_0 | CIPHER_FLAG_PRIMARY_MOVER | CIPHER_FLAG_MOVER_ANY,

    kRippleMaskBlockCipher32 = 0x17U | CIPHER_MASK_LANE_COUNT_0 | CIPHER_FLAG_SECONDARY_MOVER | CIPHER_FLAG_MOVER_ANY,
    kRippleMaskBlockCipher64 = 0x18U | CIPHER_MASK_LANE_COUNT_0 | CIPHER_FLAG_SECONDARY_MOVER | CIPHER_FLAG_MOVER_ANY,

    kInvertMaskCipher = 0x0CU | CIPHER_MASK_LANE_COUNT_0 | CIPHER_FLAG_SECONDARY_MOVER | CIPHER_FLAG_MOVER_ANY,
    kReverseMaskByteBlockCipher32 = 0x0DU | CIPHER_MASK_LANE_COUNT_0 | CIPHER_FLAG_SECONDARY_MOVER | CIPHER_FLAG_MOVER_ANY,
    kReverseMaskByteBlockCipher64 = 0x0EU | CIPHER_MASK_LANE_COUNT_0 | CIPHER_FLAG_SECONDARY_MOVER | CIPHER_FLAG_MOVER_ANY,
};

static_assert(sizeof(CipherType) == sizeof(std::uint32_t));

class CipherTool {
public:
    
    static constexpr std::size_t CountLanes(CipherType pType) {
        const std::uint32_t aType = static_cast<std::uint32_t>(pType);

        if ((aType & CIPHER_MASK_LANE_COUNT_0) != 0U) { return 0U; }
        if ((aType & CIPHER_MASK_LANE_COUNT_1) != 0U) { return 1U; }
        if ((aType & CIPHER_MASK_LANE_COUNT_2) != 0U) { return 2U; }
        if ((aType & CIPHER_MASK_LANE_COUNT_3) != 0U) { return 3U; }
        if ((aType & CIPHER_MASK_LANE_COUNT_4) != 0U) { return 4U; }

        return 0U;
    }
    
};

#endif /* CipherType_h */
