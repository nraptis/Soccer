//
//  TwistFarmSalt.hpp
//  MeanMachine
//
//  Created by Xenegos of the Revel on 5/6/26.
//

#ifndef TwistFarmSalt_hpp
#define TwistFarmSalt_hpp

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <limits>
#include "TwistCryptoScoring.hpp"
#include "TwistWorkSpace.hpp"

// A source lane is partitioned into disjoint S_SALT-word candidates.
#define SALT_CANDIDATE_COUNT ((S_BLOCK >> 3) >> S_SALT_DIVIDE_BITSHIFT)

static_assert(SALT_CANDIDATE_COUNT >= 6,
              "TwistFarmSalt requires at least six salt candidates.");

struct TwistFarmSaltStats {
    std::uint64_t mCandidatesTested;
    std::uint64_t mAccepted;
    std::uint64_t mFallbackAccepted;

    std::uint64_t mRejectBitBalance;
    std::uint64_t mRejectByteSpread;
    std::uint64_t mRejectXorDrift;
    std::uint64_t mRejectAdjacencyPenalty;
    std::uint64_t mRejectMinDistance;

    int mBestBitBalance;
    int mBestByteSpread;
    int mBestXorDrift;
    int mBestAdjacencyPenalty;
    int mBestMinDistance;
    std::uint64_t mBestScore;
};

class TwistFarmSalt {
public:
    TwistFarmSalt();
    
    void                    Derive(const std::uint8_t *pSource,
                                   std::uint64_t *pSaltA,
                                   std::uint64_t *pSaltB,
                                   std::uint64_t *pSaltC,
                                   std::uint64_t *pSaltD,
                                   std::uint64_t *pSaltE,
                                   std::uint64_t *pSaltF);
    void                    Derive(const std::uint8_t *pSource,
                                   TwistDomainSeedRoundMaterial *pRoundMaterial);
    void                    DeriveThree(const std::uint8_t *pSourceLaneA,
                                        const std::uint8_t *pSourceLaneB,
                                        const std::uint8_t *pSourceLaneC,
                                        TwistDomainSaltSet *pSaltSet);
    
    void                    Zero();
    
    
    std::uint64_t           *mCandidateSalt[SALT_CANDIDATE_COUNT];
    std::uint64_t           mCandidateSaltFlat[SALT_CANDIDATE_COUNT * S_SALT];
    std::int32_t            mCandidateScore[SALT_CANDIDATE_COUNT];
    std::int32_t            mCandidateClaimed[SALT_CANDIDATE_COUNT];
    
    std::uint64_t           *mFillSalt[SALT_CANDIDATE_COUNT];
    
    
private:
    
    TwistCryptoScoring                  mAnalyzer;
    
};

#endif /* TwistFarmSalt_hpp */
