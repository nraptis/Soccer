#pragma once

#include "TwistExpander.hpp"
#include "TwistExpander_Athebyne_Arx.hpp"

class TwistExpander_Athebyne : public TwistExpander {
public:
    TwistExpander_Athebyne();
    ~TwistExpander_Athebyne() override = default;

    void KDF_A(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               std::uint8_t *pSnow,
               int pIndexKDF) override;
    void KDF_B(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               int pIndexKDF) override;
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
                    std::uint8_t *pDestination) override;
    void SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) override;
    void GrowKeyA(TwistWorkSpace *pWorkSpace) override;
    void GrowKeyB(TwistWorkSpace *pWorkSpace) override;

private:
    static const TwistDomainSaltSet kPhaseASalts;
    static const TwistDomainConstants kPhaseAConstants;
    static const TwistDomainSaltSet kPhaseBSalts;
    static const TwistDomainConstants kPhaseBConstants;
    static const TwistDomainSaltSet kPhaseCSalts;
    static const TwistDomainConstants kPhaseCConstants;
    static const TwistDomainSaltSet kPhaseDSalts;
    static const TwistDomainConstants kPhaseDConstants;
};
