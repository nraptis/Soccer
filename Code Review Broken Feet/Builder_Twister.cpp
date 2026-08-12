//
//  Builder_Twister.cpp
//  MeanMachine
//
//  Created by nicholas on 5/23/26.
//

#include "Builder_Twister.hpp"
#include "GTwistExpander.hpp"
#include "GTwistRunTwist.hpp"
#include "GRunMatrixDiffusion.hpp"
#include "ResidualBucket.hpp"

#include <vector>

namespace {

const char *PhaseConstantsMemberName(const TwistDomain pDomain) {
    switch (pDomain) {
        case TwistDomain::kKeyRotateA: return "mKeyRotateAConstants";
        case TwistDomain::kKeyRotateB: return "mKeyRotateBConstants";
        case TwistDomain::kKeySpawnA: return "mKeySpawnAConstants";
        case TwistDomain::kKeySpawnB: return "mKeySpawnBConstants";
        case TwistDomain::kSeed: return "mSeedConstants";
        case TwistDomain::kTwist: return "mTwistConstants";
        default:
            return "";
    }
}

void AddTwistMatrixDomainWordLines(TwistProgramBranch &pBranch,
                                   const TwistDomain pDomain) {
    const std::string aConstants =
        std::string("pWorkSpace->mDomainBundle.") +
        PhaseConstantsMemberName(pDomain);

    pBranch.AddLine("std::uint64_t aDomainWordMatrixSelectA = " + aConstants + ".mMatrixSelectA;");
    pBranch.AddLine("std::uint64_t aDomainWordMatrixSelectB = " + aConstants + ".mMatrixSelectB;");
    pBranch.AddLine("");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixUnrollA = " + aConstants + ".mMatrixUnrollA;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixUnrollB = " + aConstants + ".mMatrixUnrollB;");
    pBranch.AddLine("");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgA = " + aConstants + ".mMatrixArgA;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgB = " + aConstants + ".mMatrixArgB;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgC = " + aConstants + ".mMatrixArgC;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgD = " + aConstants + ".mMatrixArgD;");
}

bool BuildTwistStage(TwistProgramBranch &pBranch,
                     const GSeedRunStageConfig &pConfig,
                     const bool pEmitPrologue,
                     const char *pStageName,
                     std::string *pErrorMessage) {
    GTwistRunTwist aRunner(pConfig, pEmitPrologue);
    if (!aRunner.Plan(pErrorMessage) ||
        !aRunner.Build(pBranch, pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage =
                std::string("Builder_Twister::Build failed on ") +
                pStageName + ":\n" + *pErrorMessage;
        }
        return false;
    }
    return true;
}

bool AddMatrixDiffusion(TwistProgramBranch &pBranch,
                        const std::vector<GSymbol> &pInputs,
                        const std::vector<GSymbol> &pOutputs,
                        const std::vector<GSymbol> &pEntropy,
                        const char *pDescription,
                        std::string *pErrorMessage) {
    GRunMatrixDiffusionConfig aConfig;
    aConfig.mInputA = pInputs[0];
    aConfig.mInputB = pInputs[1];
    aConfig.mInputC = pInputs[2];
    aConfig.mInputD = pInputs[3];
    aConfig.mOutputA = pOutputs[0];
    aConfig.mOutputB = pOutputs[1];
    aConfig.mOutputC = pOutputs[2];
    aConfig.mOutputD = pOutputs[3];
    aConfig.mEntropyA = pEntropy[0];
    aConfig.mEntropyB = pEntropy[1];
    aConfig.mEntropyC = pEntropy[2];
    aConfig.mEntropyD = pEntropy[3];

    GBatch aBatch;
    aBatch.mExportsAsBlock = false;
    if (!GRunMatrixDiffusion::Bake(aConfig,
                                   &aBatch,
                                   pErrorMessage)) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage =
                std::string("error on ") + pDescription +
                " matrix diffusion for twist: " + *pErrorMessage;
        }
        return false;
    }
    pBranch.AddBatch(aBatch);
    return true;
}

std::vector<GSymbol> Lanes(const TwistWorkSpaceSlot pFirst) {
    const int aFirst = static_cast<int>(pFirst);
    return {
        GSymbol::Buf(static_cast<TwistWorkSpaceSlot>(aFirst + 0)),
        GSymbol::Buf(static_cast<TwistWorkSpaceSlot>(aFirst + 1)),
        GSymbol::Buf(static_cast<TwistWorkSpaceSlot>(aFirst + 2)),
        GSymbol::Buf(static_cast<TwistWorkSpaceSlot>(aFirst + 3)),
    };
}

} // namespace

bool Builder_Twister::Build(GTwistExpander *pExpander,
                            ResidualBucket &pResidualBucket,
                            std::string *pErrorMessage) {
    if (pExpander == nullptr) {
        if (pErrorMessage != nullptr) {
            *pErrorMessage = "Builder_Twister::Build received null expander";
        }
        return false;
    }

    const GTwistRunTwistConfig::TwistStageConfigs aBuiltStageConfigs =
        GTwistRunTwistConfig::MakeTwistConfig(
            pResidualBucket,
            pExpander->mControlCandidateIndex);
    const std::vector<GSeedRunStageConfig> aStageConfigs(
        aBuiltStageConfigs.begin(),
        aBuiltStageConfigs.end());

    pExpander->mTwistStageConfigs = aStageConfigs;
    pExpander->mTwistMatrixDomains.assign(2U, TwistDomain::kTwist);

    const std::vector<GSymbol> aWaterLanes =
        Lanes(TwistWorkSpaceSlot::kWaterLaneA);
    const std::vector<GSymbol> aSpiritLanes =
        Lanes(TwistWorkSpaceSlot::kSpiritLaneA);
    const std::vector<GSymbol> aEarthLanes =
        Lanes(TwistWorkSpaceSlot::kEarthLaneA);
    const std::vector<GSymbol> aIceLanes =
        Lanes(TwistWorkSpaceSlot::kIceLaneA);
    const std::vector<GSymbol> aCrossLanes = {
        GSymbol::Buf(TwistWorkSpaceSlot::kParamCrossA),
        GSymbol::Buf(TwistWorkSpaceSlot::kParamCrossB),
        GSymbol::Buf(TwistWorkSpaceSlot::kParamCrossC),
        GSymbol::Buf(TwistWorkSpaceSlot::kParamCrossD),
    };

    if (!BuildTwistStage(pExpander->mTwister,
                         aStageConfigs[0],
                         true,
                         "GTwistRunTwist_A",
                         pErrorMessage)) {
        return false;
    }

    AddTwistMatrixDomainWordLines(pExpander->mTwister,
                                  TwistDomain::kTwist);

    if (!AddMatrixDiffusion(pExpander->mTwister,
                            aWaterLanes,
                            aSpiritLanes,
                            aCrossLanes,
                            "first",
                            pErrorMessage)) {
        return false;
    }

    if (!BuildTwistStage(pExpander->mTwister,
                         aStageConfigs[1],
                         false,
                         "GTwistRunTwist_B",
                         pErrorMessage)) {
        return false;
    }

    if (!AddMatrixDiffusion(pExpander->mTwister,
                            aEarthLanes,
                            aIceLanes,
                            aSpiritLanes,
                            "second",
                            pErrorMessage)) {
        return false;
    }

    if (!BuildTwistStage(pExpander->mTwister,
                         aStageConfigs[2],
                         false,
                         "GTwistRunTwist_C",
                         pErrorMessage)) {
        return false;
    }

    return true;
}
