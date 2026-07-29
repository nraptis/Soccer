//
//  TwistCryptoScoring.cpp
//  Gorgon
//
//  Created by Sonic The Hedge Whore on 4/10/26.
//

#include "TwistCryptoScoring.hpp"
#include "TwistWorkSpace.hpp"
#include <algorithm>
#include <bit>
#include <cstring>



TwistCryptoScoring::TwistCryptoScoring() {
    
}

TwistCryptoScoring::~TwistCryptoScoring() {
    
}

std::int32_t TwistCryptoScoring::ComputeSaltHammingDistance_Salt(const std::uint64_t *pDataA,
                                                                 const std::uint64_t *pDataB) {
    
    std::int32_t aDistance = 0;
    for (int aIndex = 0; aIndex < S_SALT; ++aIndex) {
        aDistance += static_cast<std::int32_t>(
            __builtin_popcountll(pDataA[aIndex] ^ pDataB[aIndex])
        );
    }
    return aDistance;
}

int TwistCryptoScoring::ComputeBitBalance_Salt(const std::uint64_t *pData) {
    
    std::memset(mHistogram, 0, sizeof(mHistogram));
    
    for (int i = 0; i < S_SALT; i++) {
        std::uint64_t v = pData[i];
        
        for (int b = 0; b < 64; b++) {
            if (v & (1ULL << b)) {
                mHistogram[b]++;
            }
        }
    }
    
    int aScore = 0;
    const int aIdeal = S_SALT / 2;
    
    for (int b = 0; b < 64; b++) {
        const int aDiff = std::abs(static_cast<int>(mHistogram[b]) - aIdeal);
        aScore += (aIdeal - aDiff);
    }
    
    return aScore;
}

int TwistCryptoScoring::ComputeByteSpread_Salt(const std::uint64_t *pData) {

    std::memset(mHistogram, 0, sizeof(mHistogram));

    const std::uint8_t *aBytes = reinterpret_cast<const std::uint8_t *>(pData);

    for (int i = 0; i < S_SALT * static_cast<int>(sizeof(std::uint64_t)); i++) {
        const std::uint8_t v = aBytes[i];
        mHistogram[v]++;
    }

    const int aExpectedPerByte =
        (S_SALT * static_cast<int>(sizeof(std::uint64_t))) / 256;

    int aScore = 0;
    for (int i = 0; i < 256; i++) {
        aScore += std::min<int>(
            static_cast<int>(mHistogram[i]),
            aExpectedPerByte);
    }

    return aScore;
}

int TwistCryptoScoring::ComputeAdjacencyPenalty_Salt(const std::uint64_t *pData) {

    int aPenalty = 0;

    for (int i = 1; i < S_SALT; i++) {
        const std::uint64_t aValueA = pData[i];
        const std::uint64_t aValueB = pData[i - 1];
        const int aDistance = static_cast<int>(__builtin_popcountll(aValueA ^ aValueB));

        if (aValueA == aValueB) {
            aPenalty += 64;
        } else if (aDistance < 8) {
            aPenalty += 16;
        } else if (aDistance < 16) {
            aPenalty += 4;
        }
    }

    return aPenalty;
}


int TwistCryptoScoring::ScorePercentileWeighted(int pValue,
                                                int p01,
                                                int p10,
                                                int p20,
                                                int p40,
                                                int p60,
                                                int p80,
                                                int p90,
                                                int p99,
                                                int pWeight,
                                                int *pRedFlagPoints) {
    
    if (pRedFlagPoints == nullptr) {
        return 0;
    }
    
    double aPercent = 0.0;
    
    // Outside p01..p99 is the actual red-flag zone.
    if (pValue < p01) {
        *pRedFlagPoints += 1;
        return 5;
    } else if (pValue > p99) {
        *pRedFlagPoints += 1;
        return 5;
    } else if (pValue < p10) {
        const double t = static_cast<double>(pValue - p01) / static_cast<double>(p10 - p01);
        aPercent = 5.0 + t * 15.0;
        return static_cast<int>(((static_cast<double>(pWeight) * aPercent) / 100.0) + 0.5);
    } else if (pValue < p20) {
        const double t = static_cast<double>(pValue - p10) / static_cast<double>(p20 - p10);
        aPercent = 20.0 + t * 40.0;
        return static_cast<int>(((static_cast<double>(pWeight) * aPercent) / 100.0) + 0.5);
    } else if (pValue < p40) {
        const double t = static_cast<double>(pValue - p20) / static_cast<double>(p40 - p20);
        aPercent = 60.0 + t * 40.0;
        return static_cast<int>(((static_cast<double>(pWeight) * aPercent) / 100.0) + 0.5);
    } else if (pValue <= p60) {
        return pWeight;
    } else if (pValue <= p80) {
        const double t = static_cast<double>(pValue - p60) / static_cast<double>(p80 - p60);
        aPercent = 100.0 - t * 40.0;
        return static_cast<int>(((static_cast<double>(pWeight) * aPercent) / 100.0) + 0.5);
    } else if (pValue <= p90) {
        const double t = static_cast<double>(pValue - p80) / static_cast<double>(p90 - p80);
        aPercent = 60.0 - t * 40.0;
        return static_cast<int>(((static_cast<double>(pWeight) * aPercent) / 100.0) + 0.5);
    } else {
        const double t = static_cast<double>(pValue - p90) / static_cast<double>(p99 - p90);
        aPercent = 20.0 - t * 15.0;
        return static_cast<int>(((static_cast<double>(pWeight) * aPercent) / 100.0) + 0.5);
    }
}

int TwistCryptoScoring::ScoreLowerIsBetterCurve(float pValue,
                                   float pBest,
                                   float pWorst,
                                                int pMaxPoints) {
    float aPercent = (pValue - pBest) / (pWorst - pBest);
    float aKeep = 1.0f - aPercent;
    float aPointsf = static_cast<float>(pMaxPoints) * aKeep * aKeep;
    int aPoints = static_cast<int>(aPointsf + 0.5f);
    if (aPoints > pMaxPoints) { aPoints = pMaxPoints; }
    if (aPoints < 0) { aPoints = 0; }
    return aPoints;
}

void TwistCryptoScoring::ComputeCombinedSaltGrade_Component_BitBalance(int pBitBalance,
                                                                       int *pScore,
                                                                       int *pRedFlagPoints) {
    
    if ((pScore == nullptr) || (pRedFlagPoints == nullptr)) {
        return;
    }
    
    *pScore += ScorePercentileWeighted(pBitBalance,
                                       7689,
                                       7734,
                                       7751,
                                       7775,
                                       7795,
                                       7817,
                                       7833,
                                       7871,
                                       30,
                                       pRedFlagPoints);
}

void TwistCryptoScoring::ComputeCombinedSaltGrade_Component_ByteSpread(int pByteSpread,
                                                                       int *pScore,
                                                                       int *pRedFlagPoints) {
    
    if ((pScore == nullptr) || (pRedFlagPoints == nullptr)) {
        return;
    }
    
    *pScore += ScorePercentileWeighted(pByteSpread,
                                       1731,
                                       1745,
                                       1751,
                                       1759,
                                       1766,
                                       1774,
                                       1780,
                                       1794,
                                       35,
                                       pRedFlagPoints);
}

void TwistCryptoScoring::ComputeCombinedSaltGrade_Component_XorDrift(int pXorDrift,
                                                                     int *pScore,
                                                                     int *pRedFlagPoints) {
    
    if ((pScore == nullptr) || (pRedFlagPoints == nullptr)) {
        return;
    }
    
    *pScore += ScorePercentileWeighted(pXorDrift,
                                       8044,
                                       8110,
                                       8138,
                                       8176,
                                       8208,
                                       8246,
                                       8274,
                                       8340,
                                       30,
                                       pRedFlagPoints);
}

void TwistCryptoScoring::ComputeCombinedSaltGrade_Component_AdjacencyPenalty(int pAdjacencyPenalty,
                                                                             int *pScore,
                                                                             int *pRedFlagPoints) {
    
    if ((pScore == nullptr) || (pRedFlagPoints == nullptr)) {
        *pScore += 5;
        return;
    }
    
    if (pAdjacencyPenalty == 0) {
        return;
    }
    
    if (pAdjacencyPenalty <= 8) {
        *pRedFlagPoints += 1;
    } else {
        *pRedFlagPoints += 2;
    }
}

int TwistCryptoScoring::ComputeCombinedSaltGrade(const std::uint64_t *pData) {
    
    const int aAdjacencyPenalty = ComputeAdjacencyPenalty_Salt(pData);
    const int aBitBalance = ComputeBitBalance_Salt(pData);
    const int aByteSpread = ComputeByteSpread_Salt(pData);
    const int aXorDrift = ComputeXorDrift_Salt(pData);
    
    int aHealthyScore = 0;
    int aRedFlagPoints = 0;
    
    ComputeCombinedSaltGrade_Component_BitBalance(aBitBalance, &aHealthyScore, &aRedFlagPoints);
    ComputeCombinedSaltGrade_Component_ByteSpread(aByteSpread, &aHealthyScore, &aRedFlagPoints);
    ComputeCombinedSaltGrade_Component_XorDrift(aXorDrift, &aHealthyScore, &aRedFlagPoints);
    ComputeCombinedSaltGrade_Component_AdjacencyPenalty(aAdjacencyPenalty, &aHealthyScore, &aRedFlagPoints);
    
    if (aRedFlagPoints > 0) {
        // max aRedFlagPoints is [2 + 1 + 1 + 1] = 5
        return (aHealthyScore / 4) // [0 - 25]
        - aRedFlagPoints * 5;
    } else {
        return aHealthyScore;
    }
}

int TwistCryptoScoring::ComputeXorDrift_Salt(const std::uint64_t *pData) {
    int aScore = 0;
    
    for (int i = 0, j = S_SALT - 1; i < S_SALT; j = i++) {
        aScore += static_cast<int>(__builtin_popcountll(pData[i] ^ pData[j]));
    }
    
    return aScore;
}
