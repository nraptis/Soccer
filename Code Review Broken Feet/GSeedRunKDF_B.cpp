//
//  GSeedRunKDF_B.cpp
//  MeanMachine
//

#include "GSeedRunKDF_B.hpp"
#include "ArrangementFour.hpp"
#include "GPassFactoryMidstage.hpp"
#include "GPassFactoryTrunk.hpp"
#include "GSeedRunStageConfigValidator.hpp"
#include "ResidualBucket.hpp"

namespace {

std::vector<TwistWorkSpaceSlot> ParamOrbiterAssignSalts() {
    using Slot = TwistWorkSpaceSlot;
    return {
        Slot::kParamDomainSaltOrbiterAssignA,
        Slot::kParamDomainSaltOrbiterAssignB,
        Slot::kParamDomainSaltOrbiterAssignC,
        Slot::kParamDomainSaltOrbiterAssignD,
        Slot::kParamDomainSaltOrbiterAssignE,
        Slot::kParamDomainSaltOrbiterAssignF,
        Slot::kParamDomainSaltOrbiterAssignG,
        Slot::kParamDomainSaltOrbiterAssignH,
    };
}

std::vector<TwistWorkSpaceSlot> ParamOrbiterUpdateSalts() {
    using Slot = TwistWorkSpaceSlot;
    return {
        Slot::kParamDomainSaltOrbiterUpdateA,
        Slot::kParamDomainSaltOrbiterUpdateB,
        Slot::kParamDomainSaltOrbiterUpdateC,
        Slot::kParamDomainSaltOrbiterUpdateD,
        Slot::kParamDomainSaltOrbiterUpdateE,
        Slot::kParamDomainSaltOrbiterUpdateF,
        Slot::kParamDomainSaltOrbiterUpdateG,
        Slot::kParamDomainSaltOrbiterUpdateH,
    };
}

std::vector<TwistWorkSpaceSlot> ParamWandererUpdateSalts() {
    using Slot = TwistWorkSpaceSlot;
    return {
        Slot::kParamDomainSaltWandererUpdateA,
        Slot::kParamDomainSaltWandererUpdateB,
        Slot::kParamDomainSaltWandererUpdateC,
        Slot::kParamDomainSaltWandererUpdateD,
        Slot::kParamDomainSaltWandererUpdateE,
        Slot::kParamDomainSaltWandererUpdateF,
        Slot::kParamDomainSaltWandererUpdateG,
        Slot::kParamDomainSaltWandererUpdateH,
    };
}

GSeedRunStageConfig BaseConfig(const std::string &pStageName,
                               const std::string &pBatchName,
                               GAXSFormat pFormat) {
    GSeedRunStageConfig aConfig;
    aConfig.mStageName = pStageName;
    aConfig.mBatchName = pBatchName;
    aConfig.mStartLine = "// " + pStageName + " " + pBatchName + " (start)";
    aConfig.mEndLine = "// " + pStageName + " " + pBatchName + " (end)";
    aConfig.mFormat = pFormat;
    aConfig.mIgnoreNonces = false;
    aConfig.mDomain = TwistDomain::kInvalid;
    aConfig.mIsNonKDF = false;
    aConfig.mExpectedSkeletonCount = 6;
    aConfig.mLoopCeiling = S_BLOCK;
    aConfig.mLoopEndText = "S_BLOCK";
    aConfig.mHotPackCount = 12;
    aConfig.mSaltsOrbiterAssign = ParamOrbiterAssignSalts();
    aConfig.mSaltsOrbiterUpdate = ParamOrbiterUpdateSalts();
    aConfig.mSaltsWandererUpdate = ParamWandererUpdateSalts();
    return aConfig;
}

void AddKDF_BPrologue(TwistProgramBranch &pBranch) {
    pBranch.AddLine("std::uint64_t aDomainWordIngress = pConstants->mIngress;");
    pBranch.AddLine("std::uint64_t aDomainWordScatter = pConstants->mScatter;");
    pBranch.AddLine("std::uint64_t aDomainWordCross = pConstants->mCross;");
    pBranch.AddLine("std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;");
    pBranch.AddLine("std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;");
    pBranch.AddLine("");
}

} // namespace

namespace GSeedRunKDF_BConfig {

KDFStageConfigs MakeKDF_BConfig(ResidualBucket &pResidualBucket,
                                const std::size_t pCandidateIndex) {
    using Slot = TwistWorkSpaceSlot;

    KDFStageConfigs aConfigs;
    std::vector<Slot> aResidualsPool;

    // Lane Plan

    //
    // KDF B — Stage A
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesA = {
        Slot::kIceLaneA, Slot::kIceLaneB,
        Slot::kIceLaneC, Slot::kIceLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsA = {
        Slot::kCrystalLaneA, Slot::kCrystalLaneB,
        Slot::kCrystalLaneC, Slot::kCrystalLaneD,
    };

    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aPrimarySourcesA));
    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aDestinationsA));

    printf("at KDF B — Stage A, there were %zu residuals available\n",
           pResidualBucket.CountValidResiduals());

    aResidualsPool = pResidualBucket.Withdraw("KDF B — Stage A", 12);

    const GPassFactoryMidstage::SlotArray13 aResidualsA = {
        Slot::kSourceLane,
        aResidualsPool[0], aResidualsPool[1],
        aResidualsPool[2], aResidualsPool[3],
        aResidualsPool[4], aResidualsPool[5],
        aResidualsPool[6], aResidualsPool[7],
        aResidualsPool[8], aResidualsPool[9],
        aResidualsPool[10], aResidualsPool[11],
    };

    pResidualBucket.AddResiduals("KDF B — Stage A", {
        Slot::kIceLaneA, Slot::kIceLaneB,
        Slot::kIceLaneC, Slot::kIceLaneD,
    });

    //
    // KDF B — Stage B
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesB = {
        Slot::kCrystalLaneA, Slot::kCrystalLaneB,
        Slot::kCrystalLaneC, Slot::kCrystalLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsB = {
        Slot::kLightningLaneA,
        Slot::kLightningLaneB,
        Slot::kLightningLaneC,
        Slot::kLightningLaneD,
    };

    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aPrimarySourcesB));
    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aDestinationsB));

    printf("at KDF B — Stage B, there were %zu residuals available\n",
           pResidualBucket.CountValidResiduals());

    aResidualsPool = pResidualBucket.Withdraw("KDF B — Stage B", 15);

    const GPassFactoryMidstage::SlotArray16 aResidualsB = {
        Slot::kSourceLane,
        aResidualsPool[0], aResidualsPool[1],
        aResidualsPool[2], aResidualsPool[3],
        aResidualsPool[4], aResidualsPool[5],
        aResidualsPool[6], aResidualsPool[7],
        aResidualsPool[8], aResidualsPool[9],
        aResidualsPool[10], aResidualsPool[11],
        aResidualsPool[12], aResidualsPool[13],
        aResidualsPool[14],
    };

    pResidualBucket.AddResiduals("KDF B — Stage B", {
        Slot::kCrystalLaneA, Slot::kCrystalLaneB,
        Slot::kCrystalLaneC, Slot::kCrystalLaneD,
    });

    //
    // Matrix diffusion: Lightning lanes -> Wind lanes.
    // Entropy: Crystal lanes.
    //
    pResidualBucket.AddResiduals("KDF B — After diffusion", {
        Slot::kLightningLaneA, Slot::kLightningLaneB,
        Slot::kLightningLaneC, Slot::kLightningLaneD,
    });

    //
    // KDF B — Stage C
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesC = {
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsC = {
        Slot::kVaporLaneA, Slot::kVaporLaneB,
        Slot::kVaporLaneC, Slot::kVaporLaneD,
    };

    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aPrimarySourcesC));
    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aDestinationsC));

    printf("at KDF B — Stage C, there were %zu residuals available\n",
           pResidualBucket.CountValidResiduals());

    aResidualsPool = pResidualBucket.Withdraw("KDF B — Stage C", 15);

    const GPassFactoryMidstage::SlotArray16 aResidualsC = {
        Slot::kSourceLane,
        aResidualsPool[0], aResidualsPool[1],
        aResidualsPool[2], aResidualsPool[3],
        aResidualsPool[4], aResidualsPool[5],
        aResidualsPool[6], aResidualsPool[7],
        aResidualsPool[8], aResidualsPool[9],
        aResidualsPool[10], aResidualsPool[11],
        aResidualsPool[12], aResidualsPool[13],
        aResidualsPool[14],
    };

    pResidualBucket.AddResiduals("KDF B — Stage C", {
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
    });

    // Stage Construction

    //
    // Build and validate KDF B — Stage A
    //
    GSeedRunStageConfig aConfigA = BaseConfig("GSeedRunKDF_B_A",
                                              "kdf_b_loop_a",
                                              GAXSFormat::kN11);
    aConfigA.mSlices =
        GPassFactoryMidstage::FourPassThirteenResidualSlices(aPrimarySourcesA,
                                                             aResidualsA,
                                                             aDestinationsA);
    aConfigA.mExpectedSkeletonCount =
        static_cast<int>(aDestinationsA.size());
    aConfigA.mHotPackCount =
        static_cast<int>(aDestinationsA.size());

    std::string aErrorMessageA;
    if (!GSeedRunStageConfigValidator::ValidateMidstage(
            aConfigA,
            GPassFactoryMidstage::ToVector(aPrimarySourcesA),
            GPassFactoryMidstage::ToVector(aResidualsA),
            GPassFactoryMidstage::ToVector(aDestinationsA),
            &aErrorMessageA)) {
        printf("MakeKDF_BConfig stage A was not valid with ValidateMidstage");
        printf("%s\n", aErrorMessageA.c_str());
        exit(0);
    }
    aConfigs[0] = aConfigA;

    //
    // Build and validate KDF B — Stage B
    //
    GSeedRunStageConfig aConfigB = BaseConfig("GSeedRunKDF_B_B",
                                              "kdf_b_loop_b",
                                              GAXSFormat::kN11);
    aConfigB.mSlices =
        GPassFactoryMidstage::FourPassSixteenResidualSlices(aPrimarySourcesB,
                                                    aResidualsB,
                                                    aDestinationsB);
    aConfigB.mExpectedSkeletonCount =
        static_cast<int>(aDestinationsB.size());
    aConfigB.mHotPackCount =
        static_cast<int>(aDestinationsB.size());

    std::string aErrorMessageB;
    if (!GSeedRunStageConfigValidator::ValidateMidstage(
            aConfigB,
            GPassFactoryMidstage::ToVector(aPrimarySourcesB),
            GPassFactoryMidstage::ToVector(aResidualsB),
            GPassFactoryMidstage::ToVector(aDestinationsB),
            &aErrorMessageB)) {
        printf("MakeKDF_BConfig stage B was not valid with ValidateMidstage");
        printf("%s\n", aErrorMessageB.c_str());
        exit(0);
    }
    aConfigs[1] = aConfigB;

    //
    // Build and validate KDF B — Stage C
    //
    const ArrangementFour::SlotArray4 aArrangedPrimarySourcesC =
        ArrangementFour::Arrange(aPrimarySourcesC,
                                 static_cast<int>(pCandidateIndex),
                                 1);

    GSeedRunStageConfig aConfigC = BaseConfig("GSeedRunKDF_B_C",
                                              "kdf_b_loop_c",
                                              GAXSFormat::kN11);
    aConfigC.mSlices =
        GPassFactoryTrunk::FourPassTrunkSlices(aArrangedPrimarySourcesC,
                                               aResidualsC,
                                               aDestinationsC);
    aConfigC.mExpectedSkeletonCount =
        static_cast<int>(aDestinationsC.size());
    aConfigC.mHotPackCount =
        static_cast<int>(aDestinationsC.size());

    std::string aErrorMessageC;
    if (!GSeedRunStageConfigValidator::ValidateTrunk(
            aConfigC,
            GPassFactoryMidstage::ToVector(aArrangedPrimarySourcesC),
            GPassFactoryMidstage::ToVector(aResidualsC),
            GPassFactoryMidstage::ToVector(aDestinationsC),
            &aErrorMessageC)) {
        printf("MakeKDF_BConfig stage C was not valid with ValidateTrunk");
        printf("%s\n", aErrorMessageC.c_str());
        exit(0);
    }
    aConfigs[2] = aConfigC;

    return aConfigs;
}

} // namespace GSeedRunKDF_BConfig

GSeedRunKDF_B::GSeedRunKDF_B(
    const GSeedRunStageConfig &pConfig,
    const bool pEmitPrologue)
: mStage(pConfig),
  mEmitPrologue(pEmitPrologue) {
}

bool GSeedRunKDF_B::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunKDF_B::Build(TwistProgramBranch &pBranch,
                          std::string *pErrorMessage) {
    if (mEmitPrologue) {
        AddKDF_BPrologue(pBranch);
    }
    return mStage.Build(pBranch, pErrorMessage);
}
