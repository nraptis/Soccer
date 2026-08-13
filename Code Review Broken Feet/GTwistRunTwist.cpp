//
//  GTwistRunTwist.cpp
//  MeanMachine
//

#include "GTwistRunTwist.hpp"
#include "ArrangementFour.hpp"
#include "GPassFactoryMidstage.hpp"
#include "GPassFactoryStarter.hpp"
#include "GPassFactoryTrunk.hpp"
#include "GQuick.hpp"
#include "Random.hpp"
#include "ResidualBucket.hpp"
#include "GSeedRunStageConfigValidator.hpp"
#include <array>
#include <cstdio>
#include <cstdlib>
#include <vector>

namespace {

const std::array<TwistVariable, 13> kInitialRandomVariables = {
    TwistVariable::kIngress,
    TwistVariable::kCarry,
    TwistVariable::kWandererA,
    TwistVariable::kWandererB,
    TwistVariable::kWandererC,
    TwistVariable::kWandererD,
    TwistVariable::kWandererE,
    TwistVariable::kWandererF,
    TwistVariable::kWandererG,
    TwistVariable::kWandererH,
    TwistVariable::kWandererI,
    TwistVariable::kWandererJ,
    TwistVariable::kWandererK,
};

int PhaseIndex(const TwistDomain pDomain) {
    switch (pDomain) {
        case TwistDomain::kKeySpawnA: return 1;
        case TwistDomain::kSeed: return 2;
        case TwistDomain::kTwist: return 3;
        case TwistDomain::kKeyRotateB: return 4;
        case TwistDomain::kKeySpawnB: return 5;
        case TwistDomain::kKeyRotateA:
        default:
            return 0;
    }
}

std::vector<TwistWorkSpaceSlot> PhaseSalts(const TwistDomain pDomain,
                                           const TwistWorkSpaceSlot pBaseSlot,
                                           const int pLaneCount) {
    const int aBase = static_cast<int>(pBaseSlot);
    const int aOffset = PhaseIndex(pDomain) * 24;

    std::vector<TwistWorkSpaceSlot> aResult;
    aResult.reserve(static_cast<std::size_t>(pLaneCount));
    for (int i = 0; i < pLaneCount; ++i) {
        aResult.push_back(static_cast<TwistWorkSpaceSlot>(aBase + aOffset + i));
    }
    return aResult;
}

GSeedRunStageConfig BaseConfig(const std::string &pStageName,
                               const std::string &pLoopName,
                               const GAXSFormat pFormat) {
    using Slot = TwistWorkSpaceSlot;
    constexpr TwistDomain kDomain = TwistDomain::kTwist;

    GSeedRunStageConfig aConfig;
    aConfig.mStageName = pStageName;
    aConfig.mBatchName = pLoopName;
    aConfig.mStartLine = "// " + pStageName + " " + pLoopName + " (start)";
    aConfig.mEndLine = "// " + pStageName + " " + pLoopName + " (end)";
    aConfig.mFormat = pFormat;
    aConfig.mIgnoreNonces = true;
    aConfig.mDomain = kDomain;
    aConfig.mIsNonKDF = true;
    aConfig.mSaltsOrbiterAssign = PhaseSalts(kDomain, Slot::kKeyRotateASaltOrbiterAssignA, 8);
    aConfig.mSaltsOrbiterUpdate = PhaseSalts(kDomain, Slot::kKeyRotateASaltOrbiterUpdateA, 8);
    aConfig.mSaltsWandererUpdate = PhaseSalts(kDomain, Slot::kKeyRotateASaltWandererUpdateA, 8);
    return aConfig;
}

void AddTwistPrologue(TwistProgramBranch &pBranch) {
    GBatch aInitBatch;
    aInitBatch.mName = "init varz";
    aInitBatch.mExportsAsBlock = false;

    std::vector<GStatement> aInitStatements;
    for (TwistVariable aVariable : kInitialRandomVariables) {
        aInitStatements.push_back(
            GQuick::MakeAssignVariableStatement(
                GSymbol::Var(aVariable),
                GExpr::Const64Hex(Random::Get64High())));
    }
    aInitBatch.CommitStatements(&aInitStatements);
    pBranch.AddBatch(aInitBatch);
    pBranch.AddLine("");
}

} // namespace

namespace GTwistRunTwistConfig {

TwistStageConfigs MakeTwistConfig(ResidualBucket &pResidualBucket,
                                  const std::size_t pCandidateIndex) {
    using Slot = TwistWorkSpaceSlot;

    TwistStageConfigs aConfigs;
    std::vector<Slot> aResidualsPool;

    // Lane Plan

    //
    // Twist — Stage A
    // Source and key rows become Earth A-D.
    //
    const GPassFactoryMidstage::SlotArray3 aPrimarySourcesA = {
        Slot::kSourceLane, Slot::kKeyRowReadA, Slot::kKeyRowReadB,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsA = {
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aResidualsA = {
        Slot::kParamCrossA, Slot::kParamCrossB,
        Slot::kParamCrossC, Slot::kParamCrossD,
    };

    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aPrimarySourcesA));
    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aDestinationsA));

    //
    pResidualBucket.AddResiduals("Twist — Stage A inputs", {
        Slot::kSourceLane,
        Slot::kKeyRowReadA, Slot::kKeyRowReadB,
    });
    pResidualBucket.AddResiduals("Twist — Stage A cross lanes", {
        Slot::kParamCrossA, Slot::kParamCrossB,
        Slot::kParamCrossC, Slot::kParamCrossD,
    }, 1U);

    //
    // Twist — Stage B
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesB = {
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsB = {
        Slot::kFireLaneA, Slot::kFireLaneB,
        Slot::kFireLaneC, Slot::kFireLaneD,
    };

    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aPrimarySourcesB));
    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aDestinationsB));

    aResidualsPool =
        pResidualBucket.Withdraw("Twist — Stage B", 7);
    const GPassFactoryMidstage::SlotArray7 aResidualsB = {
        aResidualsPool[0], aResidualsPool[1],
        aResidualsPool[2], aResidualsPool[3],
        aResidualsPool[4], aResidualsPool[5],
        aResidualsPool[6],
    };

    //
    // Matrix diffusion: Fire A-D -> Wind A-D.
    // Entropy: Earth A-D.
    //

    pResidualBucket.AddResiduals("Twist — After diffusion", {
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
        Slot::kFireLaneA, Slot::kFireLaneB,
        Slot::kFireLaneC, Slot::kFireLaneD,
    });

    //
    // Twist — Stage C
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesC = {
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsC = {
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
    };

    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aPrimarySourcesC));
    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aDestinationsC));

    aResidualsPool =
        pResidualBucket.Withdraw("Twist — Stage C", 15);
    const GPassFactoryMidstage::SlotArray15 aResidualsC = {
        aResidualsPool[0], aResidualsPool[1],
        aResidualsPool[2], aResidualsPool[3],
        aResidualsPool[4], aResidualsPool[5],
        aResidualsPool[6], aResidualsPool[7],
        aResidualsPool[8], aResidualsPool[9],
        aResidualsPool[10], aResidualsPool[11],
        aResidualsPool[12], aResidualsPool[13],
        aResidualsPool[14],
    };

    pResidualBucket.AddResiduals("Twist — Stage C", {
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
    });
    pResidualBucket.Print("Twist — Final");

    // Stage Construction

    GSeedRunStageConfig aConfigA = BaseConfig("GTwistRunTwist_A",
                                              "twist_loop_a",
                                              GAXSFormat::kN11);
    aConfigA.mMaxContextSourceCount = 4;
    aConfigA.mMaxBoundSourceCount = 8;
    aConfigA.mBindDuplicateSourceSlots = false;
    aConfigA.mSlices =
        GPassFactoryStarter::FourPassStarterFourResidualSlices(
            aPrimarySourcesA,
            aResidualsA,
            aDestinationsA);
    aConfigA.mExpectedSkeletonCount = 4;
    aConfigA.mHotPackCount = 4;

    std::string aErrorMessageA;
    if (!GSeedRunStageConfigValidator::ValidateStarterWithResiduals(
            aConfigA,
            GPassFactoryMidstage::ToVector(aPrimarySourcesA),
            GPassFactoryMidstage::ToVector(aResidualsA),
            GPassFactoryMidstage::ToVector(aDestinationsA),
            &aErrorMessageA)) {
        printf("MakeTwistConfig stage A was not valid with ValidateStarterWithResiduals");
        printf("%s\n", aErrorMessageA.c_str());
        exit(0);
    }
    aConfigs[0] = aConfigA;

    // --------------------------

    GSeedRunStageConfig aConfigB = BaseConfig("GTwistRunTwist_B",
                                              "twist_loop_b",
                                              GAXSFormat::kN11);
    aConfigB.mSlices =
        GPassFactoryMidstage::FourPassSevenResidualSlices(
            aPrimarySourcesB,
            aResidualsB,
            aDestinationsB);
    aConfigB.mExpectedSkeletonCount = 4;
    aConfigB.mHotPackCount = 4;

    std::string aErrorMessageB;
    if (!GSeedRunStageConfigValidator::ValidateMidstage(
            aConfigB,
            GPassFactoryMidstage::ToVector(aPrimarySourcesB),
            GPassFactoryMidstage::ToVector(aResidualsB),
            GPassFactoryMidstage::ToVector(aDestinationsB),
            &aErrorMessageB)) {
        printf("MakeTwistConfig stage B was not valid with ValidateMidstage");
        printf("%s\n", aErrorMessageB.c_str());
        exit(0);
    }
    aConfigs[1] = aConfigB;

    // --------------------------

    const ArrangementFour::SlotArray4 aArrangedPrimarySourcesC =
        ArrangementFour::Arrange(aPrimarySourcesC,
                                 static_cast<int>(pCandidateIndex),
                                 11);

    GSeedRunStageConfig aConfigC = BaseConfig("GTwistRunTwist_C",
                                              "twist_loop_c",
                                              GAXSFormat::kN11);
    aConfigC.mSlices =
        GPassFactoryTrunk::FourPassTrunkSlices(
            aArrangedPrimarySourcesC,
            aResidualsC,
            aDestinationsC);
    aConfigC.mExpectedSkeletonCount = 4;
    aConfigC.mHotPackCount = 4;

    std::string aErrorMessageC;
    if (!GSeedRunStageConfigValidator::ValidateTrunk(
            aConfigC,
            GPassFactoryMidstage::ToVector(aArrangedPrimarySourcesC),
            GPassFactoryMidstage::ToVector(aResidualsC),
            GPassFactoryMidstage::ToVector(aDestinationsC),
            &aErrorMessageC)) {
        printf("MakeTwistConfig stage C was not valid with ValidateTrunk");
        printf("%s\n", aErrorMessageC.c_str());
        exit(0);
    }
    aConfigs[2] = aConfigC;

    return aConfigs;
}

} // namespace GTwistRunTwistConfig

GTwistRunTwist::GTwistRunTwist(const GSeedRunStageConfig &pConfig,
                               const bool pEmitPrologue)
: mStage(pConfig),
  mEmitPrologue(pEmitPrologue) {
}

bool GTwistRunTwist::Plan(std::string *pErrorMessage) {
    mStage.Reset();
    return mStage.Plan(pErrorMessage);
}

bool GTwistRunTwist::Build(TwistProgramBranch &pBranch,
                           std::string *pErrorMessage) {
    if (mEmitPrologue) {
        AddTwistPrologue(pBranch);
    }
    return mStage.Build(pBranch, pErrorMessage);
}
