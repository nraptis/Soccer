//
//  Builder_GrowA.cpp
//  MeanMachine
//
//  Created by icarus black on 7/13/26.
//

#include "Builder_GrowA.hpp"
#include "GRunMatrixDiffusion.hpp"
#include "GTwistExpander.hpp"
#include "GTwistRunGrowKeyA.hpp"
#include "ResidualBucket.hpp"

#include <string>
#include <vector>

namespace {

void AddGrowAMatrixDomainWordLines(TwistProgramBranch &pBranch) {
    const std::string aConstants =
        "pWorkSpace->mDomainBundle.mKeyRotateAConstants";
    pBranch.AddLine("std::uint64_t aDomainWordMatrixSelectA = " + aConstants + ".mMatrixSelectA;");
    pBranch.AddLine("std::uint64_t aDomainWordMatrixSelectB = " + aConstants + ".mMatrixSelectB;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixUnrollA = " + aConstants + ".mMatrixUnrollA;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixUnrollB = " + aConstants + ".mMatrixUnrollB;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgA = " + aConstants + ".mMatrixArgA;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgB = " + aConstants + ".mMatrixArgB;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgC = " + aConstants + ".mMatrixArgC;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgD = " + aConstants + ".mMatrixArgD;");
}

} // namespace

bool Builder_GrowA::Build(GTwistExpander *pExpander,
                          ResidualBucket &pResidualBucket,
                          std::string *pErrorMessage) {
    if (pExpander == nullptr) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = "Builder_GrowA::Build received null expander";
        }
        return false;
    }

    const GTwistRunGrowKeyAConfig::GrowStageConfigs aBuiltStageConfigs =
        GTwistRunGrowKeyAConfig::MakeGrowAConfig(
            pResidualBucket,
            pExpander->mControlCandidateIndex);
    const std::vector<GSeedRunStageConfig> aStageConfigs(
        aBuiltStageConfigs.begin(),
        aBuiltStageConfigs.end());
    pExpander->mGrowAStageConfigs = aStageConfigs;
    pExpander->mGrowAMatrixDomain = TwistDomain::kKeyRotateA;

    GTwistRunGrowKeyA aStageA(aStageConfigs[0], pResidualBucket);
    if (!aStageA.Plan(pErrorMessage) ||
        !aStageA.Build(pExpander->mGrowKeyA, pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage =
                "Builder_GrowA::Build failed on grow A stage 0:\n" +
                *pErrorMessage;
        }
        return false;
    }

    AddGrowAMatrixDomainWordLines(pExpander->mGrowKeyA);

    GRunMatrixDiffusionConfig aDiffusion;
    aDiffusion.mInputA =
        GSymbol::Buf(TwistWorkSpaceSlot::kLightningLaneA);
    aDiffusion.mInputB =
        GSymbol::Buf(TwistWorkSpaceSlot::kLightningLaneB);
    aDiffusion.mInputC =
        GSymbol::Buf(TwistWorkSpaceSlot::kLightningLaneC);
    aDiffusion.mInputD =
        GSymbol::Buf(TwistWorkSpaceSlot::kLightningLaneD);
    aDiffusion.mOutputA =
        GSymbol::Buf(TwistWorkSpaceSlot::kWindLaneA);
    aDiffusion.mOutputB =
        GSymbol::Buf(TwistWorkSpaceSlot::kWindLaneB);
    aDiffusion.mOutputC =
        GSymbol::Buf(TwistWorkSpaceSlot::kWindLaneC);
    aDiffusion.mOutputD =
        GSymbol::Buf(TwistWorkSpaceSlot::kWindLaneD);
    aDiffusion.mEntropyA =
        GSymbol::Buf(TwistWorkSpaceSlot::kIceLaneA);
    aDiffusion.mEntropyB =
        GSymbol::Buf(TwistWorkSpaceSlot::kIceLaneB);
    aDiffusion.mEntropyC =
        GSymbol::Buf(TwistWorkSpaceSlot::kIceLaneC);
    aDiffusion.mEntropyD =
        GSymbol::Buf(TwistWorkSpaceSlot::kIceLaneD);

    GBatch aDiffusionBatch;
    aDiffusionBatch.mExportsAsBlock = false;
    if (!GRunMatrixDiffusion::Bake(aDiffusion,
                                   &aDiffusionBatch,
                                   pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage =
                "Builder_GrowA::Build failed on grow A matrix diffusion:\n" +
                *pErrorMessage;
        }
        return false;
    }
    pExpander->mGrowKeyA.AddBatch(aDiffusionBatch);

    GTwistRunGrowKeyA aStageB(aStageConfigs[1], pResidualBucket);
    if (!aStageB.Plan(pErrorMessage) ||
        !aStageB.Build(pExpander->mGrowKeyA, pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage =
                "Builder_GrowA::Build failed on grow A stage 1:\n" +
                *pErrorMessage;
        }
        return false;
    }

    return true;
}
