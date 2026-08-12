//
//  Builder_GrowB.cpp
//  MeanMachine
//
//  Created by icarus black on 7/13/26.
//

#include "Builder_GrowB.hpp"
#include "GRunMatrixDiffusion.hpp"
#include "GTwistExpander.hpp"
#include "GTwistRunGrowKeyB.hpp"
#include "ResidualBucket.hpp"

#include <string>
#include <vector>

namespace {

void AddGrowBMatrixDomainWordLines(TwistProgramBranch &pBranch) {
    const std::string aConstants =
        "pWorkSpace->mDomainBundle.mKeyRotateBConstants";
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

bool Builder_GrowB::Build(GTwistExpander *pExpander,
                          ResidualBucket &pResidualBucket,
                          std::string *pErrorMessage) {
    if (pExpander == nullptr) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = "Builder_GrowB::Build received null expander";
        }
        return false;
    }

    const GTwistRunGrowKeyBConfig::GrowStageConfigs aBuiltStageConfigs =
        GTwistRunGrowKeyBConfig::MakeGrowBConfig(
            pResidualBucket,
            pExpander->mControlCandidateIndex);
    const std::vector<GSeedRunStageConfig> aStageConfigs(
        aBuiltStageConfigs.begin(),
        aBuiltStageConfigs.end());
    pExpander->mGrowBStageConfigs = aStageConfigs;
    pExpander->mGrowBMatrixDomain = TwistDomain::kKeyRotateB;

    GTwistRunGrowKeyB aStageA(aStageConfigs[0], pResidualBucket);
    if (!aStageA.Plan(pErrorMessage) ||
        !aStageA.Build(pExpander->mGrowKeyB, pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage =
                "Builder_GrowB::Build failed on grow B stage 0:\n" +
                *pErrorMessage;
        }
        return false;
    }

    AddGrowBMatrixDomainWordLines(pExpander->mGrowKeyB);

    GRunMatrixDiffusionConfig aDiffusion;
    aDiffusion.mInputA =
        GSymbol::Buf(TwistWorkSpaceSlot::kPlasmaLaneA);
    aDiffusion.mInputB =
        GSymbol::Buf(TwistWorkSpaceSlot::kPlasmaLaneB);
    aDiffusion.mInputC =
        GSymbol::Buf(TwistWorkSpaceSlot::kPlasmaLaneC);
    aDiffusion.mInputD =
        GSymbol::Buf(TwistWorkSpaceSlot::kPlasmaLaneD);
    aDiffusion.mOutputA =
        GSymbol::Buf(TwistWorkSpaceSlot::kAetherLaneA);
    aDiffusion.mOutputB =
        GSymbol::Buf(TwistWorkSpaceSlot::kAetherLaneB);
    aDiffusion.mOutputC =
        GSymbol::Buf(TwistWorkSpaceSlot::kAetherLaneC);
    aDiffusion.mOutputD =
        GSymbol::Buf(TwistWorkSpaceSlot::kAetherLaneD);
    aDiffusion.mEntropyA =
        GSymbol::Buf(TwistWorkSpaceSlot::kFireLaneA);
    aDiffusion.mEntropyB =
        GSymbol::Buf(TwistWorkSpaceSlot::kFireLaneB);
    aDiffusion.mEntropyC =
        GSymbol::Buf(TwistWorkSpaceSlot::kFireLaneC);
    aDiffusion.mEntropyD =
        GSymbol::Buf(TwistWorkSpaceSlot::kFireLaneD);

    GBatch aDiffusionBatch;
    aDiffusionBatch.mExportsAsBlock = false;
    if (!GRunMatrixDiffusion::Bake(aDiffusion,
                                   &aDiffusionBatch,
                                   pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage =
                "Builder_GrowB::Build failed on grow B matrix diffusion:\n" +
                *pErrorMessage;
        }
        return false;
    }
    pExpander->mGrowKeyB.AddBatch(aDiffusionBatch);

    GTwistRunGrowKeyB aStageB(aStageConfigs[1], pResidualBucket);
    if (!aStageB.Plan(pErrorMessage) ||
        !aStageB.Build(pExpander->mGrowKeyB, pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage =
                "Builder_GrowB::Build failed on grow B stage 1:\n" +
                *pErrorMessage;
        }
        return false;
    }

    return true;
}
