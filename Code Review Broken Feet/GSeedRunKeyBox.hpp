//
//  GSeedRunKeyBox.hpp
//  MeanMachine
//

#ifndef GSeedRunKeyBox_hpp
#define GSeedRunKeyBox_hpp

#include "GSeedRunStage.hpp"

#include <array>
#include <cstddef>
#include <cstdint>
#include <string>

class ResidualBucket;

namespace GSeedRunKeyBoxConfig {

using KeyBoxStageConfigs = std::array<GSeedRunStageConfig, 80>;

// Each key flow has five independently generated four-loop ARX stages and two
// per-flow mini-diffusions. Phase A reads one Coven/Alchemy sixteenth. Phase E
// finishes by replacing that same logical flow's four Ice sixteenths, which
// are then folded directly into one key row.

bool MakeKeyBoxConfigs(std::size_t pCandidateIndex,
                       const ResidualBucket &pSeedResidualBucket,
                       KeyBoxStageConfigs *pConfigs,
                       std::string *pErrorMessage = nullptr);

}

class GSeedRunKEY {
public:
    explicit GSeedRunKEY(
        const GSeedRunStageConfig &pConfig);

    bool Plan(std::string *pErrorMessage);
    bool Build(TwistProgramBranch &pBranch,
               std::string *pErrorMessage);

private:
    GSeedRunStage mStage;
};

#endif /* GSeedRunKeyBox_hpp */
