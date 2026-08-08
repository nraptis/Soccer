//
//  SoccerRotationBank.hpp
//  Scramble
//
//  Created by nick on 8/7/26.
//

#ifndef SoccerRotationBank_hpp
#define SoccerRotationBank_hpp

#include <cstddef>
#include <cstdint>

#define SOCCER_ROTATION_LEEWAY 256
#define SOCCER_ROTATION_CACHE_COUNT_S3 4
#define SOCCER_ROTATION_CACHE_COUNT_S2 4
#define SOCCER_ROTATION_CACHE_COUNT_S1 4
#define SOCCER_ROTATION_CACHE_COUNT_TOTAL (SOCCER_ROTATION_CACHE_COUNT_S3 + SOCCER_ROTATION_CACHE_COUNT_S2 + SOCCER_ROTATION_CACHE_COUNT_S1)


enum class SoccerRotationCount : std::uint8_t {
    kNone = 0,
    kOne = 1,
    kTwo = 2,
    kThree = 3,
    kFour = 4,
};

struct SoccerRotationBankRequest {
    SoccerRotationCount mL3A = SoccerRotationCount::kNone;
    SoccerRotationCount mL2A = SoccerRotationCount::kNone;
    SoccerRotationCount mL1A = SoccerRotationCount::kNone;
    SoccerRotationCount mL3B = SoccerRotationCount::kNone;
    SoccerRotationCount mL2B = SoccerRotationCount::kNone;
    SoccerRotationCount mL1B = SoccerRotationCount::kNone;
    SoccerRotationCount mL3C = SoccerRotationCount::kNone;
};

struct SoccerRotationBankResponse {
    std::int32_t mAmountL3A[4] = {};
    std::int32_t mAmountL2A[4] = {};
    std::int32_t mAmountL1A[4] = {};

    std::int32_t mAmountL3B[4] = {};
    std::int32_t mAmountL2B[4] = {};
    std::int32_t mAmountL1B[4] = {};

    std::int32_t mAmountL3C[4] = {};
};

class SoccerRotationBank {

public:
    static SoccerRotationBankResponse               Withdraw(SoccerRotationBankRequest pRequest);

    enum class RotationSize : std::uint8_t {
        kS3,
        kS2,
        kS1,
    };

    // [524288...1048576) padded by (SOCCER_ROTATION_LEEWAY)
    static std::int32_t                             MakeRandomRotationS3(std::uint64_t pSeed);

    // [262144...524288) padded by (SOCCER_ROTATION_LEEWAY)
    static std::int32_t                             MakeRandomRotationS2(std::uint64_t pSeed);

    // [0...262144) padded by (SOCCER_ROTATION_LEEWAY)
    static std::int32_t                             MakeRandomRotationS1(std::uint64_t pSeed);


    static void                                     CacheRotation(RotationSize pSize, std::int32_t pAmount);

    static bool                                     RotationsContend(std::int32_t pRotationA, std::int32_t pRotationB);
    static bool                                     BoundariesContend(std::int32_t pRotation);
    static bool                                     RotationsContend(std::int32_t pRotation);

    static bool                                     ContendWithAnything(std::int32_t pRotation);

    static std::int32_t                             mCacheDataS3[SOCCER_ROTATION_CACHE_COUNT_S3];
    static std::size_t                              mCacheCountS3;

    static std::int32_t                             mCacheDataS2[SOCCER_ROTATION_CACHE_COUNT_S2];
    static std::size_t                              mCacheCountS2;

    static std::int32_t                             mCacheDataS1[SOCCER_ROTATION_CACHE_COUNT_S1];
    static std::size_t                              mCacheCountS1;

    static std::int32_t                             mRotationList[SOCCER_ROTATION_CACHE_COUNT_TOTAL];
    static bool                                     mRotationConsidered[SOCCER_ROTATION_CACHE_COUNT_TOTAL];
    static std::size_t                              mRotationListCount;

    static SoccerRotationBankResponse               mResponse;

    static bool                                     Withdraw_PassA(std::size_t pCountS3, std::size_t pCountS2, std::size_t pCountS1);
    static bool                                     Withdraw_PassB(std::size_t pCountS3, std::size_t pCountS2, std::size_t pCountS1);
    static bool                                     Withdraw_PassC(std::size_t pCountS3, std::size_t pCountS2, std::size_t pCountS1);
    static bool                                     Withdraw_PassD(std::size_t pCountS3, std::size_t pCountS2, std::size_t pCountS1);
    static void                                     Withdraw_PassE(std::size_t pCountS3, std::size_t pCountS2, std::size_t pCountS1);

    static std::size_t                              mCursorS3;
    static std::size_t                              mCursorS2;
    static std::size_t                              mCursorS1;
    
    static std::size_t                              mLoopCount;

};

#endif /* SoccerRotationBank_hpp */
