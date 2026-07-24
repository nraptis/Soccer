//
//  TwistExpander.cpp
//  MeanMachine
//

#include "TwistExpander.hpp"
#include "TwistFarmSalt.hpp"
#include "TwistMix32.hpp"

#include <cstdio>
#include <cstring>

TwistExpander::TwistExpander() {
    std::memset(&mDomainBundleInbuilt, 0, sizeof(mDomainBundleInbuilt));
    std::memset(&mDomainBundleEphemeral, 0, sizeof(mDomainBundleEphemeral));
    std::memset(mIndexList256A, 0, sizeof(mIndexList256A));
    std::memset(mIndexList256B, 0, sizeof(mIndexList256B));
    std::memset(mIndexList256C, 0, sizeof(mIndexList256C));
    std::memset(mIndexList256D, 0, sizeof(mIndexList256D));
}

TwistExpander::~TwistExpander() {
    
}

void TwistExpander::KDF(std::uint64_t pNonce,
                        TwistDomainConstants *pDomainConstants,
                        TwistDomainSaltSet *pDomainSaltSet) {
    (void)pNonce;
    (void)pDomainConstants;
    (void)pDomainSaltSet;
}

void TwistExpander::KDF_A(TwistWorkSpace *pWorkSpace,
                          std::uint64_t pNonce,
                          TwistDomainConstants *pDomainConstants,
                          TwistDomainSaltSet *pDomainSaltSet,
                          std::uint8_t *pSnow,
                          int pIndexKDF) {
    (void)pWorkSpace;
    (void)pSnow;
    (void)pIndexKDF;
    TwistExpander::KDF(pNonce,
                       pDomainConstants,
                       pDomainSaltSet);
}

void TwistExpander::KDF_B(TwistWorkSpace *pWorkSpace,
                          std::uint64_t pNonce,
                          TwistDomainConstants *pDomainConstants,
                          TwistDomainSaltSet *pDomainSaltSet,
                          int pIndexKDF) {
    (void)pWorkSpace;
    (void)pIndexKDF;
    TwistExpander::KDF(pNonce,
                       pDomainConstants,
                       pDomainSaltSet);
}

void TwistExpander::Seed(TwistWorkSpace *pWorkSpace,
                         TwistFarmSalt *pFarmSalt,
                         std::uint64_t pNonce,
                         std::uint8_t *pPassword,
                         std::size_t pPasswordByteLength,
                         std::uint8_t *pSnowLaneA,
                         std::uint8_t *pSnowLaneB,
                         std::uint8_t *pSnowLaneC,
                         std::uint8_t *pSnowLaneD,
                         std::uint8_t *pDestination) {
    (void)pNonce;
    if (pWorkSpace == nullptr) {
        std::printf("fatal: TwistExpander::Seed requires workspace\n");
        return;
    }
    if (pDestination == nullptr) {
        std::printf("fatal: TwistExpander::Seed requires destination buffer\n");
        return;
    }
    if (pFarmSalt == nullptr) {
        std::printf("fatal: TwistExpander::Seed requires farm salt PoisonLane\n");
        return;
    }
    if ((pSnowLaneA == nullptr) ||
        (pSnowLaneB == nullptr) ||
        (pSnowLaneC == nullptr) ||
        (pSnowLaneD == nullptr)) {
        std::printf("fatal: TwistExpander::Seed requires four snow lanes\n");
        return;
    }

    UnrollPasswordToSource(pWorkSpace->mSource, pPassword, pPasswordByteLength);
    mDomainBundleEphemeral.Zero();
    pWorkSpace->mDomainBundle.Zero();
}

void TwistExpander::TwistBlock(TwistWorkSpace *pWorkSpace,
                               std::uint8_t *pSource,
                               std::uint8_t *pDestination) {
    if ((pWorkSpace == nullptr) || (pSource == nullptr) || (pDestination == nullptr)) {
        return;
    }

}

void TwistExpander::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) {
        return;
    }

    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;
    std::uint8_t *aKeyBoxA = &(pWorkSpace->mKeyBoxA[0][0]);
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_KEY); aIndex += 1U) {
        std::uint32_t aKeyIngress =
            (static_cast<std::uint32_t>(aIceLaneA[aIndex]) << 0U) |
            (static_cast<std::uint32_t>(aIceLaneD[aIndex]) << 8U) |
            (static_cast<std::uint32_t>(aIceLaneC[aIndex]) << 16U) |
            (static_cast<std::uint32_t>(aIceLaneB[aIndex]) << 24U);
        aKeyBoxA[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aKeyIngress));
    }

    std::uint8_t *aKeyBoxB = &(pWorkSpace->mKeyBoxB[0][0]);
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_KEY); aIndex += 1U) {
        std::uint32_t aKeyIngress =
            (static_cast<std::uint32_t>(aIceLaneD[aIndex]) << 0U) |
            (static_cast<std::uint32_t>(aIceLaneA[aIndex]) << 8U) |
            (static_cast<std::uint32_t>(aIceLaneB[aIndex]) << 16U) |
            (static_cast<std::uint32_t>(aIceLaneC[aIndex]) << 24U);
        aKeyBoxB[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aKeyIngress));
    }
}

void TwistExpander::GrowKeyA(TwistWorkSpace *pWorkSpace) {
    (void)pWorkSpace;
}

void TwistExpander::GrowKeyB(TwistWorkSpace *pWorkSpace) {
    (void)pWorkSpace;
}

void TwistExpander::Twist(TwistWorkSpace *pWorkSpace,
                          std::uint8_t *pSource,
                          std::uint8_t *pDestination,
                          std::size_t pDestinationByteLength) {
    if ((pWorkSpace == nullptr) || (pSource == nullptr) || (pDestination == nullptr)) {
        std::printf("fatal: TwistExpander::Twist requires workspace/source/destination\n");
        return;
    }
    if ((pDestinationByteLength % S_BLOCK) != 0U) {
        std::printf("fatal: TwistExpander::Twist needs a multiple of S_BLOCK\n");
        return;
    }
    
    for (std::size_t aStartByte = 0U;
         aStartByte < pDestinationByteLength;
         aStartByte += static_cast<std::size_t>(S_BLOCK)) {
        TwistBlock(pWorkSpace,
                   pSource + aStartByte,
                   pDestination + aStartByte);
    }
    
}

void TwistExpander::AutoSeedThenTwist(TwistWorkSpace *pWorkSpace,
                                      TwistFarmSalt *pFarmSalt,
                                      std::uint64_t pNonce,
                                      std::uint8_t *pPassword,
                                      std::size_t pPasswordByteLength,
                                      std::uint8_t *pSnowLaneA,
                                      std::uint8_t *pSnowLaneB,
                                      std::uint8_t *pSnowLaneC,
                                      std::uint8_t *pSnowLaneD,
                                      std::uint8_t *pDestination,
                                      std::size_t pDestinationByteLength) {
    
    if ((pDestinationByteLength % S_BLOCK) != 0U) {
        std::printf("fatal: TwistExpander::AutoSeedThenTwist needs pDestinationByteLength as a multiple of S_BLOCK\n");
        return;
    }
    
    Seed(pWorkSpace,
         pFarmSalt,
         pNonce,
         pPassword, // password
         pPasswordByteLength, // password length
         pSnowLaneA,
         pSnowLaneB,
         pSnowLaneC,
         pSnowLaneD,
         pDestination);
    
    std::size_t aDestinationIndex = S_BLOCK;
    while (aDestinationIndex < pDestinationByteLength) {
        TwistBlock(pWorkSpace,
                   &pDestination[aDestinationIndex - S_BLOCK], // source
                   &pDestination[aDestinationIndex]); // dest
        aDestinationIndex += S_BLOCK;
    }
    
}

// Assumes the work space is seeded...
void TwistExpander::AutoTwist(TwistWorkSpace *pWorkSpace,
                              std::uint8_t *pSource,
                              std::uint8_t *pDestination,
                              std::size_t pDestinationByteLength) {
    
    TwistBlock(pWorkSpace,
               pSource,
               pDestination); // dest
    
    std::size_t aDestinationIndex = S_BLOCK;
    while (aDestinationIndex < pDestinationByteLength) {
        TwistBlock(pWorkSpace,
                   &pDestination[aDestinationIndex - S_BLOCK], // source
                   &pDestination[aDestinationIndex]); // dest
        aDestinationIndex += S_BLOCK;
    }
    
}

void TwistExpander::UnrollPasswordToSource(std::uint8_t *pSource,
                            std::uint8_t *pPassword,
                            std::size_t pPasswordByteLength) {
    if (pSource == nullptr) {
        return;
    }

    std::memset(pSource, 0, static_cast<std::size_t>(S_BLOCK));
    if ((pPassword == nullptr) || (pPasswordByteLength == 0U)) {
        return;
    }

    std::size_t aInitialCopy = pPasswordByteLength;
    if (aInitialCopy > static_cast<std::size_t>(S_BLOCK)) {
        aInitialCopy = static_cast<std::size_t>(S_BLOCK);
    }

    std::memcpy(pSource, pPassword, static_cast<std::size_t>(aInitialCopy));
    if (aInitialCopy < static_cast<std::size_t>(S_BLOCK)) {
        pSource[aInitialCopy++] = 0;
    }
    if (aInitialCopy < static_cast<std::size_t>(S_BLOCK)) {
        pSource[aInitialCopy++] = 0;
    }

    std::size_t aFilled = aInitialCopy;
    while (aFilled < static_cast<std::size_t>(S_BLOCK)) {
        std::size_t aChunk = aFilled;
        if ((aFilled + aChunk) > static_cast<std::size_t>(S_BLOCK)) {
            aChunk = static_cast<std::size_t>(S_BLOCK) - aFilled;
        }
        std::memcpy(pSource + aFilled, pSource, static_cast<std::size_t>(aChunk));
        aFilled += aChunk;
    }
}

void TwistExpander::UnrollPasswordToSource(std::uint8_t *pSource,
                                           std::uint8_t *pPassword,
                                           std::size_t pPasswordByteLength,
                                           std::size_t pSourceByteLength) {
    if (pSource == nullptr) {
        return;
    }

    if (pSourceByteLength == 0U) {
        return;
    }

    std::memset(pSource, 0, static_cast<std::size_t>(pSourceByteLength));

    if ((pPassword == nullptr) || (pPasswordByteLength == 0U)) {
        return;
    }

    std::size_t aInitialCopy = pPasswordByteLength;
    if (aInitialCopy > pSourceByteLength) {
        aInitialCopy = pSourceByteLength;
    }

    std::memcpy(pSource, pPassword, static_cast<std::size_t>(aInitialCopy));

    if (aInitialCopy < pSourceByteLength) {
        pSource[aInitialCopy++] = 0;
    }

    if (aInitialCopy < pSourceByteLength) {
        pSource[aInitialCopy++] = 0;
    }

    std::size_t aFilled = aInitialCopy;

    while (aFilled < pSourceByteLength) {
        std::size_t aChunk = aFilled;

        if (aChunk == 0U) {
            break;
        }

        if ((aFilled + aChunk) > pSourceByteLength) {
            aChunk = pSourceByteLength - aFilled;
        }

        std::memcpy(pSource + aFilled,
                    pSource,
                    static_cast<std::size_t>(aChunk));

        aFilled += aChunk;
    }
}

void TwistExpander::Zero() {
    Zero_PostSeed();
    mDomainBundleInbuilt.Zero();
}

void TwistExpander::Zero_PostSeed() {
    memset(mIndexList256A, 0, sizeof(mIndexList256A));
    memset(mIndexList256B, 0, sizeof(mIndexList256B));
    memset(mIndexList256C, 0, sizeof(mIndexList256C));
    memset(mIndexList256D, 0, sizeof(mIndexList256D));
    mDomainBundleEphemeral.Zero();
}
