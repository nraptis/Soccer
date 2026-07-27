#pragma once

#include "TwistExpander.hpp"
#include "TwistExpander_Sirius_Arx.hpp"

class TwistExpander_Sirius : public TwistExpander {
public:
    TwistExpander_Sirius();
    ~TwistExpander_Sirius() override = default;

    void KDF_A(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               std::uint8_t *pSnow) override;
    void KDF_B(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               std::uint8_t *pSnow) override;
    void KDF_C(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               std::uint8_t *pSnow) override;
    void KDF_D(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               std::uint8_t *pSnow) override;
    void Seed(TwistWorkSpace *pWorkSpace,
              TwistFarmSalt *pFarmSalt,
              std::uint64_t pNonce,
              std::uint8_t *pPassword,
              std::size_t pPasswordByteLength,
              std::uint8_t *pSnowLaneA,
              std::uint8_t *pSnowLaneB,
              std::uint8_t *pSnowLaneC,
              std::uint8_t *pSnowLaneD,
              std::uint8_t *pDestination) override;
    void TwistBlock(TwistWorkSpace *pWorkSpace,
                    std::uint8_t *pSource,
                    std::uint8_t *pSnowLaneA,
                    std::uint8_t *pSnowLaneB,
                    std::uint8_t *pSnowLaneC,
                    std::uint8_t *pSnowLaneD,
                    std::uint8_t *pDestination) override;
    void FoldSeed(TwistWorkSpace *pWorkSpace,
                  std::uint8_t *pDestination) override;
    void FoldTwist(TwistWorkSpace *pWorkSpace,
                   std::uint8_t *pDestination) override;
    void GrowKeyA(TwistWorkSpace *pWorkSpace,
                  std::uint64_t *pPrevious,
                  std::uint64_t *pIngress,
                  std::uint64_t *pCarry,
                  std::uint64_t *pWandererA,
                  std::uint64_t *pWandererB,
                  std::uint64_t *pWandererC,
                  std::uint64_t *pWandererD,
                  std::uint64_t *pWandererE,
                  std::uint64_t *pWandererF,
                  std::uint64_t *pWandererG,
                  std::uint64_t *pWandererH,
                  std::uint64_t *pWandererI,
                  std::uint64_t *pWandererJ,
                  std::uint64_t *pWandererK) override;
    void GrowKeyB(TwistWorkSpace *pWorkSpace,
                  std::uint64_t *pPrevious,
                  std::uint64_t *pIngress,
                  std::uint64_t *pCarry,
                  std::uint64_t *pWandererA,
                  std::uint64_t *pWandererB,
                  std::uint64_t *pWandererC,
                  std::uint64_t *pWandererD,
                  std::uint64_t *pWandererE,
                  std::uint64_t *pWandererF,
                  std::uint64_t *pWandererG,
                  std::uint64_t *pWandererH,
                  std::uint64_t *pWandererI,
                  std::uint64_t *pWandererJ,
                  std::uint64_t *pWandererK) override;

private:
    void FoldKeyRows(TwistWorkSpace *pWorkSpace);
    static const TwistDomainSaltSet kKeyRotateSalts;
    static const TwistDomainConstants kKeyRotateConstants;
    static const TwistDomainSaltSet kKeySpawnSalts;
    static const TwistDomainConstants kKeySpawnConstants;
    static const TwistDomainSaltSet kSeedSalts;
    static const TwistDomainConstants kSeedConstants;
    static const TwistDomainSaltSet kTwistSalts;
    static const TwistDomainConstants kTwistConstants;
};
